#include <SoftwareSerial.h>

#define BT_RXD 8
#define BT_TXD 7
#define ledPin 4

SoftwareSerial bluetooth(BT_RXD,BT_TXD);
char state = 0;

 
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);


}

void loop() {
  
  
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());

   if (Serial.available() > 0) {
    state = Serial.read();
   }
    
  }

  if (state == '0') {
    digitalWrite(ledPin,LOW);
    Serial.println("LED : OFF");

  }

  else if (state == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED : ON");

  }
  
}
