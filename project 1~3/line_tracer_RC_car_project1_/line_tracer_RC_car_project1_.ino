// 라인트레이서 rc카
int IR1=8;      //오른쪽 센서
int IR2=10;    //왼쪽 센서
int IR3=9;     //가운데 센서
// 오른쪽 모터
int enA = 5;    
int MotorAip1=2;
int MotorAip2=3;
// 왼쪽 모터
int enB = 6;    
int MotorBip1=4;
int MotorBip2=7;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
  }
void loop(){
   if(digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH){
    // 양쪽 모터 모두 정지
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
    }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==LOW){
    // 양쪽 모터 모두 작동
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    if(digitalRead(IR3)==LOW){
      analogWrite (enA, 1023);
      analogWrite (enB, 1023);
      }
    else{
      analogWrite (enA, 200);
      analogWrite (enB, 200);
      }
    }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH)
  {
    // 왼쪽 모터를 멈추고 오른쪽 모터를 작동시켜 rc카가 좌회전하도록 함.
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 150);
    delay(50);
  }

  else if(digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW)
  {
    // 오른쪽 모터를 멈추고 왼쪽 모터를 작동시켜 rc카가 우회전하도록 함.
    digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 150);
    analogWrite (enB, 200);
    delay(50);
  } 

  else
  {
    // 양쪽 모터 모두 정지
   digitalWrite(MotorAip1,LOW);
   digitalWrite(MotorAip2,LOW);
   digitalWrite(MotorBip1,LOW);
   digitalWrite(MotorBip2,LOW);
   analogWrite (enA, 0);
   analogWrite (enB, 0);
  }
}
