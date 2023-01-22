#include "MecanumDrive.h"

void MecanumDrive::wheelTest() {
  for (int i = 0; i < 4; i++) {
    _wheels[i].directionTest();
  }
}