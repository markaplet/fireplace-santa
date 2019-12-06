#define DEBUG 1;

#include <Servo.h>
Servo SantaServo;     // create servo object to control a servo
int pos = 0;          // variable to store the servo position
int inPin = 7;        // input pin for the floor switch
int lightsPin = 8;    // output pin to lights relay

void setup() {
  SantaServo.attach(9);           // attaches the servo on pin 9 to the servo object
  pinMode(inPin, INPUT);          // declare inPin as input
  pinMode(lightsPin, OUTPUT);     // declare inPin as output
  digitalWrite(lightsPin, HIGH);  // turn on lights at startup
  
  #ifdef DEBUG
    Serial.begin(9600);       // open serial monitor for debug
  #endif
} 

void loop() {
  int SwitchState = digitalRead(inPin);

  switch (SwitchState) {
    case 1:    // Floor sensor pressed
      hideSanta();
      break;
    case 0:    // Floor sensor NOT pressed
      showSanta() ;
      break;
  }
}


// FUNCTIONS
void showSanta() {
  #ifdef DEBUG
    Serial.println("Show Santa");
  #endif
  SantaServo.write(90);
}

void hideSanta() {
  #ifdef DEBUG
    Serial.println("Hide Santa");
  #endif
  SantaServo.write(0);
}
