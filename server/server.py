from flask import Flask , request,Response,jsonify
from flask_cors import CORS, cross_origin
import sys
sys.path.append('../webcam')

from angle import HandCodedLaneFollower, test_photo

app=Flask(__name__)
CORS(app)
cors = CORS(app, resource={
    r"/*":{"origins":"*"}
})


@app.route("/")
def main():
    return 'main'

# 1-Get Mode From Mobile: 0 = Manual , 1 = Auto
@app.route('/post', methods=['POST'])
def post():
    if request.method == 'POST':
        try:
            data = request.get_json()
            print(data["value"])
            return str(data)
        except Exception as e:
            return(str(e))

# 2-Get Manual Direction From Mobile
mode = '0'
@app.route("/get/",methods=['GET'])
def move():
    global dir,mode
    value=request.args.get('val')
    mode=str(value)
    dir=value
    print(value)
    return str(dir)

# Send Manual Direction value to Arduino    
@app.route("/send",methods=['GET'])
def send():
    global mode
    if(mode == '0' or mode == '2' or mode == '3' or mode == '4' or mode == '5' or mode == '6' ):
        return str(dir)
    elif(mode == '1'):
        mode='m'
        return str(dir) 
    elif (mode == 'm'):
        # test_photo("../webcam/auto.png")
        # DirectionSendToServer.append(test_photo(sys.path[0]+"/img/auto.png"))
        # print(DirectionSendToServer[-1])
        try:
            result,f_angle=test_photo(sys.path[0]+"/img/auto.png")
            print(result,'=======',f_angle)
            return jsonify(result)
        except Exception as e:
            print(str(e))
            return jsonify(2)
        # return(Response(DirectionSendToServer[-1]))
    else:
        return "Error"

@app.route('/image/', methods=['GET'])
def image():
    # time.sleep(0.5)
    img=request.args.get('img')
    # result=test_photo(sys.path[0]+"/img/"+img)
    result,f_angle=test_photo(sys.path[0]+"/img/lane/"+img+".jpg")
    if result == '4':
        return jsonify(result , 'Forword',f_angle)
    elif result == '5':
        return jsonify(result , 'Left',f_angle)
    elif result == '6':
        return jsonify(result , 'Right',f_angle)
    else:
        return (result,f_angle)

# To Prevent flask app's development server from unwanted reloads
# python -m venv env
# .\env\Scripts\activate

if __name__ == "__main__":
    # app.run(host='192.168.172.174', port= 8000, debug=True)
    # app.run(host='192.168.172.174', port= 8000, debug=True)
    app.run(host='192.168.146.174', port= 8000, debug=True)
    # app.run(port=8000,debug=True)