#include <Arduino.h>
#include <analogWrite.h>
#include "MecanumWheel.h"

MecanumWheel::MecanumWheel(int pinA, int pinB) : _pinA(pinA), _pinB(pinB) {
  pinMode(_pinA, OUTPUT);
  pinMode(_pinB, OUTPUT);
}

void MecanumWheel::forward() {
  analogWrite(_pinA, MAX_PWM);
  analogWrite(_pinB, 0);
}

void MecanumWheel::reverse() {
  analogWrite(_pinA, 0);
  analogWrite(_pinB, MAX_PWM);
}

void MecanumWheel::idle() {
  analogWrite(_pinA, 0);
  analogWrite(_pinB, 0);
}

void MecanumWheel::stop() {
  analogWrite(_pinA, 0);
  analogWrite(_pinB, 0);
}

void MecanumWheel::directionTest() {
  forward();
  delay(3000);
  reverse();
  delay(3000);
  idle();
}