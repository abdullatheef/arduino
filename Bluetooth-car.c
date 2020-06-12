#include <Servo.h>

char t;
int pos=95;
int start=95;
int delta=25;
Servo myservo;  // create servo object to control a servo


void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);   //Led
Serial.begin(9600);
myservo.attach(8);
myservo.write(pos);
 
}
void front() {
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}

void back() {
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
 } 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  if (pos > start) {pos -= 1;}
  if (pos < start) {pos += 1;}
  delay(15);
  myservo.write(pos);
  front();  
}
else if (t == 'I') {
  front();
  if (pos < start + delta) { pos += 1; }
  myservo.write(pos);
  delay(15);
}
else if (t == 'G') {
  front();
  if (pos > start - delta) { pos -= 1; }
  myservo.write(pos);
  delay(15);
}
else if (t == 'J') {
  back();
  if (pos < start + delta) { pos += 1; }
  myservo.write(pos);
  delay(15);
} 
else if (t == 'H') {
  back();
  if (pos > start - delta) { pos -= 1; }
  myservo.write(pos);
  delay(15);
}   
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
    if (pos > start) {pos -= 1;}
  if (pos < start) {pos += 1;}
  delay(15);
  back();
  myservo.write(pos);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(13,HIGH);
  if (pos > start - delta) { pos -= 1; }
  myservo.write(pos);
  delay(15);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(11,HIGH);
  if (pos < start + delta) { pos += 1; }
  myservo.write(pos);
  delay(15);
}
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  myservo.write(pos);
}
//delay(100);
}
