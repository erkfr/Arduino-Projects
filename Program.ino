const int dummy = 0;

#include <Servo.h>
#include "Move_Data.h"

#define RightHipFlexPin 10
#define RightHipAPin 11
#define RightKneePin 2
#define RightAnklePin 13
#define LeftHipFlexPin 6
#define LeftHipAPin 3
#define LeftKneePin 5
#define LeftAnklePin 4
#define SensorServoPin 12

int Offsets [9];

Servo ServoTable[9];

void setup()
{
  Serial.begin(115200);
  ServoTable[0].attach(RightHipFlexPin);
  ServoTable[1].attach(RightHipAPin);
  ServoTable[2].attach(RightKneePin);
  ServoTable[3].attach(RightAnklePin);
  ServoTable[4].attach(LeftHipFlexPin);
  ServoTable[5].attach(LeftHipAPin);
  ServoTable[6].attach(LeftKneePin);
  ServoTable[7].attach(LeftAnklePin);
  ServoTable[8].attach(SensorServoPin);
  pinMode(7, INPUT);  //Activate the onboard buttons for our use in the program
  pinMode(8, INPUT);  //
  pinMode(9, INPUT);  //
}

void loop()
{
 GroupMove(90,90,90,90,90,90,90,90,100);
 int i;
 for (i = 0; i < 8; i ++)
  {
    Serial.write(ServoTable[i]);
  }
 delay(1000);
}
