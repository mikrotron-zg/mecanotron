/*
 * This file is part of Mecanum Drive library.
 *
 * Developed for Mecanotron project (https://github.com/mikrotron-zg/mecanotron)
 * by Mikrotron d.o.o. (http://mikrotron.hr)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. See the LICENSE file at the 
 * top-level directory of this distribution for details 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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