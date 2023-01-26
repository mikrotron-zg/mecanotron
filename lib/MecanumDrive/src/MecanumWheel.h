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

#ifndef MECANUM_WHEEL_H
  #define MECANUM_WHEEL_H
  #define MAX_PWM 255

  /**
   * @brief Drives a single wheel.
   * 
   * Implements basic wheel movements: forward, reverse and stop.
   * Also includes a simple test to determine if the motor is 
   * correctly wired.
   * 
   */
  class MecanumWheel {
    public:
      /**
       * @brief No args constructor.
       * 
       */
      MecanumWheel(){};
      
      /**
       * @brief Construct a new Mecanum Wheel object.
       * 
       * @param pinA Digital output pin controlling the
       *        motor A pin on a driver. 
       * @param pinB Digital output pin controlling the
       *        motor B pin on a driver.
       */
      MecanumWheel(int pinA, int pinB);

      /**
       * @brief Moves the wheel forward.
       * 
       */
      void forward();

      /**
       * @brief Moves the wheel backward.
       * 
       */
      void reverse();

      /**
       * @brief Puts the motor in idle.
       * 
       */
      void idle();

      /**
       * @brief Locks the wheel.
       * 
       */
      void stop();

      /**
       * @brief Runs simple wheel direction test.
       * 
       * Make sure wheels are lifted from the ground before
       * running this test. The wheel should rotate forward
       * first, then backward. If it does the opposite, switch
       * the motor wires connected to the motor driver and re-test.
       */
      void directionTest();
      
    private:
      int _pinA;
      int _pinB;
  };
#endif