int trigPin = 6;
int echoPin = 7;
int button = 11;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340*duration) / 1000) / 2 ;

  if (digitalRead(button) == LOW) {
  Serial.print("\nDistance:");
  Serial.print(distance);
  Serial.println("m\n");
  }
  
  else () {
  }
}
