/** @file PID.cpp
 * @brief PID controller source file
 * @author Driver- Amrish Baskaran; Navigator- Kapil Rawal
 * Copyright 2018 Amrish Baskaran
 */

#include "PID.h"

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
  return 5;
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




