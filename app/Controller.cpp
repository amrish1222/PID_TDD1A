/** MIT License
 *
 * Copyright (c) 2018 Amrish Baskaran
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file Controller.cpp
 * @brief Controller source file to run a virtual machine
 * @author Author- Amrish Baskaran
 * Copyright 2018 Amrish Baskaran
 */


#include <iostream>
#include "PID.h"
#include "Controller.h"

/**
 * @brief Constructor for Controller Class
 * @param PID class object sent by reference
 * @return none.
 */
Controller::Controller(PID &_p1)
    : _pid(_p1) {
}

/**
 * @brief Destructor for Controller Class
 * @return none.
 */
Controller::~Controller() {
}

/**
 * @brief runs the PID method on a virtual machine
 * @brief uses the PID method in loop to achieve the
 * the required reference velocity
 * @param reference velocity to be achieved
 * @return none.
 */
int Controller::runController(double velocity) {
  // set the PID controller gains
  _pid.setValues(0.1, 0.1, 0.1, 0.5, 20, 0);
  int count = 0;
  // set the required final velocity
  double _setPoint = velocity;
  // return feedback value
  double _feedBack = 0;
  bool stop = false;
  // Loop for checking running of virtual machine
  while (!stop) {
    _pid.setCurrentState(_setPoint, _feedBack);
    double ucontrol = _pid.compute();
    // Condition for virtual machine
    // system can go to the controller input in the given time
    _feedBack += ucontrol;
    // printing the current acquired velocity
    std::cout << _feedBack << std::endl;
    count += 1;
    // checking if set point is reached
    if (_setPoint - _feedBack > 0.01) {
      stop = false;
    } else {
      // if set point is reached exiting loop
      stop = true;
    }
    if (count > 150) {
      // return 1 if number of iterations are beyond 150.
      return 1;
  }
    }
  // return 0 if success
  return 0;
  }

