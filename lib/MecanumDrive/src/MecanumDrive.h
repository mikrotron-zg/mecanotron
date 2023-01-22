#ifndef MECANUM_DRIVE_H
  #define MECANUM_DRIVE_H
  #include "MecanumWheel.h"
  class MecanumDrive {
    public:
      MecanumDrive(){};
      MecanumDrive(MecanumWheel wheels[]) : _wheels(wheels){};
      void wheelTest();
    private:
      MecanumWheel *_wheels;
  };
#endif