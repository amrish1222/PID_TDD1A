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
 * @file Controller.h
 * @brief Controller header file
 * @author Author- Amrish Baskaran;
 * Copyright 2018 Amrish Baskaran
 */

#ifndef INCLUDE_CONTROLLER_H_
#define INCLUDE_CONTROLLER_H_

#include "../include/PID.h"

class Controller {
 public:
  /**
   * @brief holds the PID class object
   */
  PID &_pid;

  /**
   * @brief Controller Constructor
   * @params PID object by reference
   */
  explicit Controller(PID& pid);

  /**
   * @brief Controller Destructor
   */
  virtual ~Controller();

  /**
   * @brief runs the compute method on a virtual machine
   * @params reference velocity
   */
  int runController(double velocity);
};

#endif /* INCLUDE_CONTROLLER_H_ */
