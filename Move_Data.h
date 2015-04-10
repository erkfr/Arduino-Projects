#include "Arduino.h"

#define period 10 //time between each servo adjustment in Microseconds

extern Servo ServoTable[9];
extern int Offsets[9];

float RHFP = 90;
float RHAP = 90;
float RKP = 90;
float RAP = 90;
float LHFP = 90;
float LHAP = 90;
float LKP = 90;
float LAP = 90;

boolean stepN;

void GroupMove(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int Speed)
{
  float ticks = Speed / period;
  float RHFS = (p1 - RHFP) / ticks;
  float RHAS = (p2 - RHAP) / ticks;
  float RKS = (p3 - RKP) / ticks;
  float RAS = (p4 - RAP) / ticks;
  float LHFS = (p5 - LHFP) / ticks;
  float LHAS = (p6 - LHAP) /ticks;
  float LKS = (p7 - LKP) / ticks;
  float LAS = (p8 - LAP) / ticks;
  for(int x = 0; x < ticks; x++)
  {
    RHFP = RHFP + RHFS;
	RHAP = RHAP + RHAS;
    RKP = RKP + RKS;
    RAP = RAP + RAS;
    LHFP = LHFP + LHFS;
    LHAP = LHAP +LHAS;
	LKP = LKP + LKS;
    LAP = LAP + LAS;
    ServoTable[0].write(RHFP + Offsets[0]);
	ServoTable[1].write(RHAP + Offsets[1]);
    ServoTable[2].write(RKP + Offsets[2]);
    ServoTable[3].write(RAP + Offsets[3]);
    ServoTable[4].write(LHFP + Offsets[4]);
	ServoTable[5].write(LHAP + Offsets[5]);
    ServoTable[6].write(LKP + Offsets[6]);
    ServoTable[7].write(LAP + Offsets[7]);
    delay(period);
  }
}