// Project          : Sonar Software Test
// Language         : Arduino
// Version          : ALPHA v0.3
// Author           : Batuhan Gayretli
// Commencement Date: 09.05.2014
// Last Update      : 09.06.2014


#define ECHOPIN 7        
#define TRIGPIN 8
#include <Servo.h>

Servo myservo; // create servo object to control a servo
int pos = 0; // variable to store the servo position

void setup() {
  
  Serial.begin(9600); 
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT); 
}

void Print (int R , int T)
{
   Serial.print(R);Serial.print(", ");
   Serial.print(T);Serial.println(".");
   delay(100);
}

float Distance () {
  // Pulse Sending
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);
  
  // Distance Calculation
  float distance = pulseIn(ECHOPIN, HIGH); 
  distance= distance/58; 
  return(distance);
}

void loop() {
  
  myservo.write(45); // Tells the servo to go to position in variable 'pos'  
  delay(2000); // Turning Time
  
  for(pos = 45; pos <= 135; pos += 3) // 45 to 135
  {
    myservo.write(pos); // Tells the servo to go to position in variable 'pos'    
    Print(Distance() , pos); // For Serial
    delay(10); // Waits 10ms for the servo to reach the position
  }
  delay(1000);     
    
  for(pos = 135; pos>=45; pos-=3) // 45 to 135
  {
    myservo.write(pos); // Tells the servo to go to position in variable 'pos'
    Print(Distance() , pos);    
    delay(10); // Waits 10ms for the servo to reach the position
  }  
  

  
}
