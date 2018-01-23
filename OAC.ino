#include <Servo.h>  

Servo myservo;  
int pos = 0;
const int Motor1Pin2 = 8;
const int Motor1Pin1 = 9;
const int Motor2Pin2 = 10;
const int Motor2Pin1 = 11;
const int trigpin = 12;
const int echopin = 13;
void setup()
{
  myservo.attach(6);  
   Serial.begin(9600);
}
float trigger() //Returns distance between sensor and obstacle
{
  float duration;
  pinMode(trigpin, OUTPUT);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
   delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  pinMode(echopin, INPUT);
  duration = pulseIn(echopin, HIGH);
  float inches = duration / 74 /2;
  return(inches);
}
 
void loop()
{
  lbl:
  for(pos = 90; pos < 120; pos += 10)   
  {                                  
    myservo.write(pos);
    if(trigger()>5)
    {
      GoForward();
    }
    else
    {
      GoRight();
      delay(2000);
      goto lbl;
    }
    delay(15);
  }
  for(pos = 120; pos>=90; pos-=10)
  {                                
    myservo.write(pos);
    if(trigger()>5)
    {
      GoForward();
    }
    else
    {
      GoRight();
      delay(2000);
      goto lbl;
    }    
   delay(15);                    
  }
  delay(500);
  for(pos = 90; pos>=60; pos -= 10)
  {                                  
    myservo.write(pos);   
    if(trigger()>5)
    {
      GoForward();
    }
    else
    {
      GoLeft();
      delay(2000);
      goto lbl;
    }    
    delay(15);                       
  }
  for(pos = 60; pos<=90; pos+=10)
  {                                
    myservo.write(pos);        
   if(trigger()>5)
    {
      GoForward();
    }
    else
    {
      GoLeft();
      delay(2000);
      goto lbl;
    }
    delay(15);                  
  }
  delay(500);
}
void GoForward(){ //Function to go Forward
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
}
void GoLeft(){ //Function to turn Left
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
}
void GoRight(){    //Function to turn Right
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}
