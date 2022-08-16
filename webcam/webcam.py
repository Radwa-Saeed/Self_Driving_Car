from multiprocessing.connection import wait
import urllib
import numpy as np
import cv2
from urllib.request import urlopen
import time

while True:
    videoURL = 'http://192.168.146.7:8080/shot.jpg?rnd=764928'
    # videoURL = 'http://192.168.172.235:8080/shot.jpg?rnd=100227'
    Respons = urllib.request.urlopen(videoURL)
    numpy_img = np.array(bytearray(Respons.read()),dtype=np.uint8)
    image = cv2.imdecode(numpy_img ,-1)
    cv2.imwrite(r'E:\SBME\Elec\git\self-driving-car\server\img\auto.png',image)
    # cv2.imwrite(r'E:\SBME\Elec\git\self-driving-car\server\img\lane.png',image)
    # cv2.imwrite('./auto.png',image)
    time.sleep(2)


 

