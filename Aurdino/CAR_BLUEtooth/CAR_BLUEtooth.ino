#include <SoftwareSerial.h>

char Dir;
char readStringEsp();

int enA = 6;
int in1 = 8;
int in2 = 9;
int enB = 5;
int in3 =10;
int in4 = 11;

char espData;
char Data1;
char Data2;
char WhichServer=' ';
const int trigPinL = 2;
const int echoPinL = 3;
const int trigPinR = 12;
const int echoPinR = 13;
long durationL = 0;
int distanceL=0;
long durationR=0;
int distanceR=0;
int sumRight=0;
int sumLeft=0;

float DistanceLeft(){
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  durationL = pulseIn(echoPinL, HIGH);
  distanceL= durationL*0.034/2;
  return distanceL;
  }
float DistanceRight(){
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  durationR = pulseIn(echoPinR, HIGH);
  distanceR= durationR*0.034/2;
  return distanceR;
  } 
  
void setup(){
Serial.begin(9600); 
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
//esp
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(trigPinL, OUTPUT); 
pinMode(echoPinL, INPUT);
pinMode(trigPinR, OUTPUT); 
pinMode(echoPinR, INPUT);


}

void Backword(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4,HIGH); 
  analogWrite(enA, 100);
  analogWrite(enB, 100);

  }
  
void Forword(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);  
  digitalWrite(in4, LOW)  ; 
  analogWrite(enA, 100);
  analogWrite(enB, 100);

}
void Right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  analogWrite(enA, 0);
  analogWrite(enB, 110);

  }
void Left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  analogWrite(enA, 110);
  analogWrite(enB, 0);

  }  
void Stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);  
  digitalWrite(in4, LOW); 
  analogWrite(enA, 0);
  analogWrite(enB, 0); 
  }



void loop() {
   //put your man code here, to run repeatedly:
Data1 = digitalRead(2);
Data2 = digitalRead(3);
Serial.println(Data1,Data2);
Serial.println(espData);

if (espData == '1' || espData == '0'){
  WhichServer = espData;
  }
else{
  Dir = espData;
  }  

while(WhichServer == '0'){
  espData = readStringEsp();
  Serial.println(espData);

  if (espData == '1' || espData == '0'){
    WhichServer = espData;
  }
  else{
    Dir = espData;
  }  
  Serial.println("Manual");
  if(Dir == '2'){
   Serial.println("Stop");
   Stop();
   }
  else if(Dir == '3'){
    Serial.println("back");
    Backword();
    }
  else if(Dir == '4'){
    Serial.println("Forword");
    Forword();
    }
  else if(Dir == '5'){
    Serial.println("Left");
    Left();
    }  
  else if(Dir == '6'){
    Serial.println("Right");
    Right();
    } 
  }  
  
while(WhichServer == '1'){
  espData = readStringEsp();
  Serial.println(espData);
  
  if (espData == '1' || espData == '0'){
    WhichServer = espData;
  }
  else{
    Dir = espData;
  } 
  Serial.println("Automatic");
    if(Dir == '2'){
      Serial.println("Stop");
      Stop();
      }
    else if(Dir == '4'){
      Serial.println("Forword");
      Forword();
      delay(200);
      Stop();
      //delay(100 );
      }
     else if(Dir == '5'){
      Serial.println("Left");
      Left();
      delay(200);
      Stop(); 
      //delay(100);
      }
     else if(Dir == '6'){
      Serial.println("Right");
      Right();
      delay(200);
      Stop();
      //delay(100); 
      }
  distanceR = DistanceRight();
  distanceL = DistanceLeft();
  if((distanceR <20)&&(distanceL > 20) && (distanceR != 0)&&(distanceL != 0)){
    Serial.println("Right Object");
    Left();
    delay(300);
    Forword();
    delay(400);
    Stop();
    
    }
  else if((distanceR >20)&&(distanceL < 20) && (distanceR != 0)&&(distanceL != 0)){
    Serial.println("Left Object");
    Right();
    delay(300);
    Forword();
    delay(400);
    Stop();
    }  

 
} 
//delay(1000);
}
char readStringEsp() {
  char dataRecieved ;
  char chBuffer;
  while (Serial.available() > 0) {
    chBuffer =  (char) Serial.read();
    dataRecieved = chBuffer;
    Serial.println(dataRecieved);
    return dataRecieved;
   }  
   }
