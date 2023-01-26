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

#include "MecanumDrive.h"
#include "Arduino.h"

void MecanumDrive::wheelTest() {
  for (int i = 0; i < 4; i++) {
    _wheels[i].directionTest();
  }
}

void MecanumDrive::demo() {
  forward(); demoMoveDelay();
  reverse(); demoMoveDelay();
  sideways(); demoMoveDelay();
  sideways(false); demoMoveDelay();
  diagonal(); demoMoveDelay();
  diagonal(true, false); demoMoveDelay();
  diagonal(false); demoMoveDelay();
  diagonal(false, false); demoMoveDelay();
  rotate(); demoMoveDelay();
  rotate(false); demoMoveDelay();
  circle(); demoMoveDelay();
  circle(true, false); demoMoveDelay();
  circle(false); demoMoveDelay();
  circle(false); demoMoveDelay;
}

void MecanumDrive::demoMoveDelay() {
  delay(1000);
  stop();
  delay(250);
}

void MecanumDrive::stop(bool hard /* = false */) {
  for (int i = 0; i < 4; i++) {
    if (hard) {
      _wheels[i].stop();
    } else {
      _wheels[i].idle();
    }
  }
}

void MecanumDrive::forward() {
  leftWheels();
  rightWheels();
}

void MecanumDrive::reverse() {
  leftWheels(false);
  rightWheels(false);
}

void MecanumDrive::rotate(bool clockwise /* = true */) {
  leftWheels(clockwise);
  rightWheels(!clockwise);
}

void MecanumDrive::circle(bool rightwards /* = true */, bool forward /* = true */) {
  if (rightwards) {
    leftWheels(forward);
  } else {
    rightWheels(forward);
  }
}

void MecanumDrive::sideways(bool rightwards /* = true*/) {
  for (int i = 0; i < 4; i++) {
    if (i%2 == 0) {
      if (rightwards) _wheels[i].forward(); else _wheels[i].reverse();
    } else {
      if (rightwards) _wheels[i].reverse(); else _wheels[i].forward();
    }
  }
}

void MecanumDrive::diagonal(bool rightwards /* = true*/, bool forward /* = true*/) {
  if (rightwards) {
    if (forward) {
      _wheels[0].forward();
      _wheels[3].forward();
    } else {
      _wheels[0].reverse();
      _wheels[3].reverse();
    }
  } else {
    if (forward) {
      _wheels[1].forward();
      _wheels[2].forward();
    } else {
      _wheels[1].reverse();
      _wheels[2].reverse();
    }
  }
}

void MecanumDrive::leftWheels(bool forward /* = true*/) {
  if (forward) {
    _wheels[0].forward();
    _wheels[2].forward();
  } else {
    _wheels[0].reverse();
    _wheels[2].reverse();
  }
}

void MecanumDrive::rightWheels(bool forward /* = true*/) {
  if (forward) {
    _wheels[1].forward();
    _wheels[3].forward();
  } else {
    _wheels[1].reverse();
    _wheels[3].reverse();
  }
}