#ifndef MECANUM_WHEEL_H
  #define MECANUM_WHEEL_H
  #define MAX_PWM 255
  class MecanumWheel {
    public:
      MecanumWheel(){};
      MecanumWheel(int pinA, int pinB);
      void forward();
      void reverse();
      void idle();
      void stop();
      void directionTest();
    private:
      int _pinA;
      int _pinB;
  };
#endif