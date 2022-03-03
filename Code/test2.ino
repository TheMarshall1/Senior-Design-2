


#define led 13
#define motion_s 2


int distance;


void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(motion_s,INPUT);

digitalWrite(led,0);
}//setup

void loop() {
distance=analogRead(A0);
delay(50);

if (distance>100){
  Serial.println("object detected");
  digitalWrite(led,1);
  delay(2000);
  digitalWrite(led,0);
}

if (digitalRead(motion_s)==1){
  Serial.println("motion detected");
  digitalWrite(led,1);
  delay(2000);
  digitalWrite(led,0); 
}

}//lop
