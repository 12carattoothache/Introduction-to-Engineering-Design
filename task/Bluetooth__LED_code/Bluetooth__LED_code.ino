#include <SoftwareSerial.h>

int TxPin = 7;
int RxPin = 8;
int ledPin = 4;
int state = 0;
SoftwareSerial BTSerial(TxPin, RxPin); 

void setup()  
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) {
    state = Serial.read();
    BTSerial.write(Serial.read());
  }
  
   if(state == '1') {
      digitalWrite(ledPin,HIGH);
      state = 0;
      } 
    else if(state == '0') {
      digitalWrite(ledPin,LOW);
      state = 0;
    }
  }
