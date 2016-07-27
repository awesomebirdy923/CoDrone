// 3. Include the CoDrone library in your code
#include<CoDrone.h>
// 1. Add the method that runs once, before anything else
void setup() {
  CoDrone.begin(115200);
  byte droneAddress[6] = {0xFF, 0xBB, 0x60, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
}
//   4. Set up the thread - HINT: 115200
//   5. Create a byte array that holds your specific drone address
//   6. Connect to your drone using the address - HINT: It functions as an AddressInputDrone

// 2. Add the method that runs repeatedly once the program starts
//    7. Create a variable to hold each sensor value
//    HINT: You can name them left, middle, and right (despite being digital sensors 11, 14, and 18)

void loop() {
  byte leftSensor = digitalRead(11);
  byte middileSensor = digitalRead(14);
  byte rightSensor = digitalRead(18);
  if (leftSensor) {
    CoDrone.FlightEvent(Stop);
  }
  else if (middileSensor) {
    CoDrone.FlightEvent(TakeOff);
    PITCH = 80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(1000);
    ROLL = 80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(1000);
    PITCH = -80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(1000);
    ROLL = -80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(1000);
    CoDrone.FlightEvent(Landing);
  }
  else if (rightSensor) {
    CoDrone.FlightEvent(Landing);
  }
}

//    8. Check to see if the left sensor is triggered
//        10. Kill the drone - HINT: Stop the drone with a FlightEvent

//    9. If not, check to see if the right sensor is triggered
//        11. TakeOff

//        12. Go up with a speed of 100
//        Send the command - HINT: Use .Control()
//        Wait for one second - HINT: Use delay(____);

//        13. Go forward (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        14. Go right (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        15. Go back (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        16. Go left (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        17. Land

