
//importing the libraries

#include <Servo.h>

//associating the pins to variables

const int trigPin = 9; 
const int echoPin = 10;

//defining the servo and a variable to store it's target position

Servo myservo;
int pos = 0;

//those will help us later

float duration, distance;

//actions that happen once the board is powered

void setup() { 
 pinMode(trigPin, OUTPUT); //set this pin as output
 pinMode(echoPin, INPUT);  //set this pin as input
 Serial.begin(9600); //starting the serial communication
 myservo.attach(11); //attaching the servo on pin 11
} 

//starting the main loop

void loop() { 

//clearing the voltage on the trig pin
  
 digitalWrite(trigPin, LOW);  
 delayMicroseconds(2); 

//setting the trig pin on high for 10 micro seconds
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW); 

//reading the pin -- returns the duration
 duration = pulseIn(echoPin, HIGH); 

 //calculating the actual distance
 distance = (duration*.0343)/2;

 //outputing the distance in Serial Monitor 
 Serial.print("Distance: "); 
 Serial.println(distance); 

 /* The sensor has a 400cm range while the servo  
    only has a 180 degrees turn. In conclusion, each
    degree is equal to ~2.2cm (400/180), but the servo
    will only recive integer values and that's why we
    are converting it into an "int"
    */
 myservo.write((int)(distance*2.2));
 
 //now waiting before the next loop
 
 delay(100); 
} 
