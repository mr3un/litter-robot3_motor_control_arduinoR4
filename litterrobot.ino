#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Litterrobot3"
  https://create.arduino.cc/cloud/things/5d7800a7-ef8e-47b2-883d-47a9ebcadffc 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool go;
  bool left_Right;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "Arduino_LED_Matrix.h"
#include <Arduino_ConnectionHandler.h>
int pin1 = 2;
int pin2 = 3;
ArduinoLEDMatrix matrix; 

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  
  setDebugMessageLevel(2);
  matrix.loadSequence(LEDMATRIX_ANIMATION_STARTUP);
  matrix.begin();
  matrix.play(true);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
/*
  Since LeftRight is READ_WRITE variable, onLeftRightChange() is
  executed every time a new value is received from IoT Cloud.
*/
}

void handlePinStates() {
  if (left_Right) {
    if (go) {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
    } else {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
  } else { if (go) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);}
          else 
  {     digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);}
  }
}
void onLeftRightChange() {
  // Handle changes in LeftRight
  handlePinStates();
}

void onGoChange() {
  // Handle changes in Go  
  if (go) {
  matrix.loadSequence(LEDMATRIX_ANIMATION_ARROWS_COMPASS);
  ///matrix.begin();
  ///matrix.play(true);
  }
  else {
  matrix.loadSequence(LEDMATRIX_ANIMATION_STARTUP);
  ///matrix.begin();
  ///matrix.play(true);
    
  }
  handlePinStates();

}
  



