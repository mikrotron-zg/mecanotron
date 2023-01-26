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

#ifndef MECANUM_DRIVE_H
  #define MECANUM_DRIVE_H
  #include "MecanumWheel.h"

  /**
   * @brief Drives a four wheel mecanum vehicle.
   * 
   * Implements all movement commands available for vehicle equiped
   * with mecanum (omnidirectional) wheels.
   * 
   */
  class MecanumDrive {

    public:
      /**
       * @brief No args constructor.
       * 
       */
      MecanumDrive(){};

      /**
       * @brief Construct a new Mecanum Drive object.
       * 
       * @param wheels An array containing all four Mecanum Wheel
       *               objects, @see MecanumWheel.h for details.
       */
      MecanumDrive(MecanumWheel wheels[]) : _wheels(wheels){};

      /**
       * @brief Wheel direction test.
       * 
       * Use this test for motor connection check, it runs all 
       * wheels one by one, forward first and then reverse. If 
       * some wheel fails the test, switch the motor wires.
       */
      void wheelTest();

      /**
       * @brief Mecanum drive demo.
       * 
       * This procedure demonstrates all available moves in the
       * library, be sure to have enough free space for your
       * vehicle to move around (1x1 meter should be enough).
       * 
       */
      void demo();

      /**
       * @brief Stops the vehicle.
       * 
       * @param hard If true, applies hard stop (locks all motors), 
       *             false by default.
       */
      void stop(bool hard = false);

      /**
       * @brief Moves the vehicle forward until stopped.
       * 
       */
      void forward();

      /**
       * @brief Moves the vehicle backward until stopped.
       * 
       */
      void reverse();

      /**
       * @brief Rotates the vehicle in place until stopped.
       * 
       * @param clockwise True by default, pass false to 
       *                  rotate counter cloclwise.
       */
      void rotate(bool clockwise = true);

      /**
       * @brief Moves the vehicle in circle.
       * 
       * Makes the vehicle circle to the right or to the left, 
       * going forward or reverse.
       * 
       * @param rightwards If true (default) makes the vehicle
       *        circle to the right, false makes it circle to 
       *        the left.
       * @param forward  If true (default) makes the vehicle 
       *        rotate in the forward direction (clockwise if
       *        it circles to the right, counter clockwise if
       *        it circles to the left). False makes it circle
       *        while going backward.
       */
      void circle(bool rightwards = true, bool forward = true );

      /**
       * @brief Moves the vehicle sideways.
       * 
       * @param rightwards If true (default), the vehicle moves
       *        to the right, false makes it move to the left.
       */
      void sideways(bool rightwards = true);

    private:
      MecanumWheel *_wheels;
      void demoMoveDelay();
      void leftWheels(bool forward = true);
      void rightWheels(bool forward = true);
  };
#endif