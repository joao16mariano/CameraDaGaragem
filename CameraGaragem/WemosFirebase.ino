#include "FirebaseESP8266.h"  
#include <WiFiManager.h> 
#include <neotimer.h>

#define FIREBASE_HOST "fir-4d8d1-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "vxatqUomcgsWtjG4fxooBvTXv6h7VErb7MF3qCqk"
int led0 = D0; //Quando conectado
int led5 = D5; // controle do rele do servo motor
int led8 = D8;//Progresso de conecção na REDE    

Neotimer piscaD0;   //Pisca quando conectado

FirebaseData ledData0;  
FirebaseData ledData5;
FirebaseJson json;


void setup() {

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
 pinMode(led0,OUTPUT);  
 digitalWrite(led0, LOW); 
  
  pinMode(led5,OUTPUT);
  digitalWrite(led5, HIGH);    
  
        
 pinMode(led8,OUTPUT);

  digitalWrite(led8, HIGH); //Progresso deconexão
  delay(2000);
  digitalWrite(led8, LOW);
  delay(2000);
  digitalWrite(led8, HIGH);  
  delay(2000);
  
  digitalWrite(led8, LOW);
  delay(2000); 
  digitalWrite(led8, HIGH);
  delay(2000);
  digitalWrite(led8, LOW);
  delay(2000);
  digitalWrite(led8, HIGH);
  delay(2000);
  digitalWrite(led8, LOW);
  delay(2000);
  digitalWrite(led8, HIGH);
  delay(2000);
  digitalWrite(led8, LOW);
  delay(2000);
  digitalWrite(led8, HIGH);
  delay(2000);
  digitalWrite(led8, LOW);
  delay(2000);
  digitalWrite(led8, HIGH);
  delay(4000);
  digitalWrite(led8, LOW);
  delay(4000);
  digitalWrite(led8, HIGH);
  delay(4000);
  digitalWrite(led8, LOW);
  delay(4000);
  digitalWrite(led8, HIGH);
  delay(4000);  
  digitalWrite(led8, LOW);
  delay(4000);
  digitalWrite(led8, HIGH);
  delay(4000);
  digitalWrite(led8, HIGH);
  delay(4000);
  digitalWrite(led8, LOW);
  delay(4000);
  digitalWrite(led8, HIGH);  
  delay(4000);
  digitalWrite(led8, LOW);
  delay(4000);
  digitalWrite(led8, HIGH);  
  delay(1000);
  digitalWrite(led8, LOW);  

  digitalWrite(led8, HIGH);  
  delay(100000);
  digitalWrite(led8, LOW);  
  
   
 Serial.begin(115200);           

 WiFiManager wifiManager;
 wifiManager.autoConnect("IOT Mariano");
 Serial.println("connected...yeey :)"); 
     
}


void loop() {

  if (Firebase.getString(ledData0, "led8")){   //Quando conectado nivel "0" no firebase   
    Serial.println(ledData0.stringData());
    if (ledData0.stringData() == "1") {
    digitalWrite(led0, HIGH);
    }
  else if (ledData0.stringData() == "0"){
   if (piscaD0.repeat()){                          
    digitalWrite(led0,!digitalRead(led0));   //Pisca quando conectado
    }
  }
  }

  if (Firebase.getString(ledData5, "camera")){   //Controle rele do servo motor
    Serial.println(ledData5.stringData());
    if (ledData5.stringData() == "1") {      
    digitalWrite(led5, HIGH);     
   }
   else if (ledData5.stringData() == "0"){
    digitalWrite(led5, LOW);   
    
    }
  }
 
  
}








