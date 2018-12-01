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
 *@file PID.cpp
 * @brief PID controller source file
 * @author Driver- Amrish Baskaran; Navigator- Kapil Rawal
 * @author Part 2 - Saimouli Katragadda
 * Copyright 2018 Amrish Baskaran
 */

#include "PID.h"
#include <iostream>
PID::PID() {
  kp = 0;
  kd = 0;
  ki = 0;
  prevError = 0;
  dt = 0.0001;  // cannot be zero
  minRange = 0;
  maxRange = 0;
  setPoint = 0;
  feedBackVal = 0;
  Integral = 0;
}

PID::~PID() {
}

/**
 * @brief executes the PID controller flow.
 * uses the error value (=setPoint- feedBack) with the respective gains to obtain
 * the correction value that will be sent to the controller to
 * correct its state to achieve the desired setPoint value.
 * @param none
 * @return new controller value.
 */
double PID::compute() {
  std::cout << "computing" << std::endl;
  float error = 0, Ucontrol = 0;
  error = setPoint - feedBackVal;
  float dTerm = 0;
  Integral += error * dt;  // calculating the i term

  dTerm = (error - prevError) / dt;  // calculating the derivative

  // control input calculation
  Ucontrol = kp * error + ki * Integral + kd * dTerm;

  prevError = error;  // setting the error for next iteration

  return Ucontrol;
}

/**
 * @brief Initializes the required variables
 * @param Kp1:double, Ki1:double, Kd1:double, dt1:double, max1:double, min1:double
 * @return none.
 */
void PID::setValues(double Kp1, double Ki1, double Kd1, double dt1, double max1,
                    double min1) {
  kp = Kp1;
  ki = Ki1;
  kd = Kd1;
  dt = dt1;
  maxRange = max1;
  minRange = min1;
}

/**
 * @brief Initializes the required variables
 * stores the variables that the compute method uses
 * to calculate the required correction value.
 * @param setPoint1:double, feedBackVal1:double
 * @return none.
 */
void PID::setCurrentState(double setPoint1, double feedBackVal1) {
  setPoint = setPoint1;
  feedBackVal = feedBackVal1;
}

double PID::getKp() {
  return kp;
}

double PID::getKd() {
  return kd;
}

double PID::getKi() {
  return ki;
}

double PID::getDt() {
  return dt;
}

double PID::getMax() {
  return maxRange;
}

double PID::getMin() {
  return minRange;
}
