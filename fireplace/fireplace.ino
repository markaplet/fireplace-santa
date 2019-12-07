/*   

  ____  _             ____              _        
 / ___|| |__  _   _  / ___|  __ _ _ __ | |_ __ _ 
 \___ \| '_ \| | | | \___ \ / _` | '_ \| __/ _` |
  ___) | | | | |_| |  ___) | (_| | | | | || (_| |
 |____/|_| |_|\__, | |____/ \__,_|_| |_|\__\__,_|
              |___/                              

Arduino Uno version of the adafruit grinch fireplace https://bit.ly/2DUMCI4

Floor switch = GRD and Pin 2
Relay (lights) = Pin 8
Servo = Pin 9

*/
 
//#define DEBUG 1
#define SWITCH_PIN        2     // Floor switch pin
#define DELAY             200   // Delay per loop in ms
#define LIGHTS_PIN        8     // output pin to lights relay
#define SERVO_PIN         9     // servo pin


#include <Servo.h>
Servo SantaServo;     // create servo object to control a servo
int SERVO_START_POS = 0;          // variable to store the servo position


void setup() {
  SantaServo.attach(SERVO_PIN);       // attaches the servo on pin 9 to the servo object
  SantaServo.write(SERVO_START_POS);  // default to the starting position
  pinMode(SWITCH_PIN, INPUT);         // declare inPin as input
  pinMode(LIGHTS_PIN, OUTPUT);        // declare inPin as output
  digitalWrite(SWITCH_PIN, HIGH);     // internal pull-up for switch
  digitalWrite(LIGHTS_PIN, HIGH);     // turn on lights at startup
  
  #ifdef DEBUG
    Serial.begin(9600);       // open serial monitor for debug
  #endif
} 

void loop() {
  boolean button_pressed = handle_button();

  switch (button_pressed) {
    case 1:    // Floor sensor pressed
      hideSanta();
      break;
    case 0:    // Floor sensor NOT pressed
      showSanta() ;
      break;
  }
  delay(DELAY);
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

boolean handle_button(){
  int button_pressed = !digitalRead(SWITCH_PIN); // pin low -> pressed
  return button_pressed;
}
