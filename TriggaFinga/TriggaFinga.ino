#include<CoDrone.h>

int step;

unsigned long LONG;

void setup() {
  // put your setup code here, to run once:
  CoDrone.begin(115200);
  byte droneAddress[6] = {0xFF, 0xBB, 0x60, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte leftSensor = digitalRead(11);
  byte middleSensor = digitalRead(14);
  byte rightSensor = digitalRead(18);
  if (leftSensor) {
    CoDrone.FlightEvent(Stop);
    step = 0;
  } else if (middleSensor) {
    CoDrone.FlightEvent(Landing);
  } else if (rightSensor) {
    step = step + 1;
    if(step >= 4){
      step = 0;
      }
    CoDrone.Buzz(step * 100, 7);
    delay(200);
  }

  if (step == 1) {
    THROTTLE = 504;
    PITCH = 100;
    CoDrone.Control();
  } else if (step == 2) {
    PITCH = 100;
    CoDrone.Control();
  }
  else if (step == 3) {
    ROLL = -100;
    CoDrone.Control();
  } else if (step == 4) {
    PITCH = 100;
    CoDrone.Control();
  } else {
    CoDrone.FlightEvent(Landing);
  }
}
