#include<CoDrone.h>

void setup() {
  // put your setup code here, to run once:

  CoDrone.begin(115200);
  byte droneAddress[6] = {0xFF, 0xBB, 0x60, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect( AddressInputDrone, droneAddress);
  CoDrone.LedColor(ArmDimming, 102, 0, 225, 7);
  CoDrone.BattleBegin(TEAM_GREEN);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte leftSensor = digitalRead(11);
  byte middleSensor = digitalRead(14);
  byte rightSensor = digitalRead(18);
  if (leftSensor) {
    CoDrone.FlightEvent(Stop);
  } else if (middleSensor) {
    
  } else if (rightSensor) {
    CoDrone.Buzz(100, 7);
    CoDrone.BattleShooting();
    CoDrone.ButtonPreesHoldWait(18);
  }
  THROTTLE = CoDrone.AnalogScaleChange(analogRead(A4));
  PITCH = CoDrone.AnalogScaleChange(analogRead(A6));
  ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5));
  YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3));
  CoDrone.Control();
}
