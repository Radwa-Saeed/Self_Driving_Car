#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h> 
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include<SoftwareSerial.h>
#include <SPI.h>
SoftwareSerial s(3,1);

const char* ssid = "Loozazzz";
const char* password = "251198radwa";
//const char* ssid = "STUDBME2";
//const char* password = "BME2Stud";
 
void setup () {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  s.begin(9600);
  Serial.begin(9600);
  SPI.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.println("Connecting..");
 
  }
  Serial.println("Connected to WiFi Network");
 
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
            HTTPClient http;  //Declare an object of class HTTPClient
            WiFiClient client;
     http.begin(client,"http://192.168.231.174:8000/send");  //Specify request destination
     int httpCode = http.GET(); //Send the request
     //Serial.println(httpCode);

     if (httpCode > 0) { //Check the returning code
      
       String payload = http.getString(); //Get the request response payload
       Serial.println(payload);
       s.write(payload[0]); //connection bet esp & arduino
       digitalWrite(D0,1);
       digitalWrite(D1,1);
//       char data='f';
       
//       //Serial.println(1);
        //Serial.println(payload);
        //Serial.println(1);
        //delay(100);
        //Serial.println(payload[0]); 
     }
     delay(100);
     http.end();
  
 
}
}
