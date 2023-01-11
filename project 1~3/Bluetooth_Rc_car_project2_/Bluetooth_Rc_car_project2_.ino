// 소프트웨어 시리얼 통신을 사용하기 위한 라이브러리를 포함한다.
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

String ms = "";

#define ENA 11 //오른쪽 모터의 속도제어
#define IN1 10 //오른쪽 모터의 방향제어1
#define IN2 9 //오른쪽 모터의 방향제어2
#define IN3 8 //왼쪽 모터의 방향제어1
#define IN4 7 //왼쪽 모터의 방향제어2
#define ENB 6 //왼쪽 모터의 속도제어

int sp = 100; // 모터의 속도값

int value; // 블루투스 통신을 통해 받아오는 값.
int num = 5; 

void setup() {
  mySerial.begin(9600);

  pinMode(ENB,OUTPUT); 
  pinMode(IN4,OUTPUT); 
  pinMode(IN3,OUTPUT); 
  pinMode(IN2,OUTPUT); 
  pinMode(IN1,OUTPUT); 
  pinMode(ENA,OUTPUT); 
}

void loop() {
  if(mySerial.available()){
    ms = mySerial.readStringUntil('c');
    value = ms.toInt(); // 블루투스 통신을 통해 받아오는 값을 value에 저장한다.
    
    if(value>9){
      sp=value; // 9보다 큰 value값이 입력되면 이를 속도값으로 인식.
    }else{
      num=value; // 1~9까지의 value 값이 입력되면 이에 따라 rc카가 각각 전진 좌회전 ~ 후진 우회전의 동작을 함.
    }

    int ratioSp = sp*1023/1024; 
    // 왼쪽 모터의 속도값은 오른쪽 모터의 속도값에 일정한 비율을 취하여, 두 모터의 속도를 같게 맞춤.

    if(num==1){
      analogWrite(ENB,sp); //a forward left turn
      digitalWrite(IN4,HIGH); 
      digitalWrite(IN3,HIGH);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN1,LOW);
      analogWrite(ENA,ratioSp);
    }else if(num==2){ //forward
      analogWrite(ENB,sp);
      digitalWrite(IN4,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN1,LOW);
      analogWrite(ENA,ratioSp);
    }else if(num==3){ //a forward right turn
      analogWrite(ENB,sp);
      digitalWrite(IN4,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN1,HIGH);
      analogWrite(ENA,ratioSp);
    }else if(num==4){ //a stop left turn
      analogWrite(ENB,sp);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN1,LOW);
      analogWrite(ENA,ratioSp);
    }else if(num==5){ //stop
      analogWrite(ENB,sp);
      digitalWrite(IN4,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN1,HIGH);
      analogWrite(ENA,ratioSp);
    }else if(num==6){ //a stop right turn
      analogWrite(ENB,sp);
      digitalWrite(IN4,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENA,ratioSp);
    }else if(num==7){ //a backward left turn 
      analogWrite(ENB,sp);
      digitalWrite(IN4,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENA,ratioSp);
    }else if(num==8){ //backward
      analogWrite(ENB,sp);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENA,ratioSp);
    }else if(num==9){ //a backward right turn 
      analogWrite(ENB,sp);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN1,HIGH);
      analogWrite(ENA,ratioSp);
    }
  }
}
