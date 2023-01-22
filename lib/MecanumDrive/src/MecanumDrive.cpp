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

void MecanumDrive::wheelTest() {
  for (int i = 0; i < 4; i++) {
    _wheels[i].directionTest();
  }
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
  for (int i = 0; i < 4; i++) {
    _wheels[i].forward();
  }
}

void MecanumDrive::reverse() {
  for (int i = 0; i < 4; i++) {
    _wheels[i].reverse();
  }
}

void MecanumDrive::rotate(bool clockwise /* = true */) {
  for (int i = 0; i < 4; i++) {
    leftWheels(clockwise);
    rightWheels(!clockwise);
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