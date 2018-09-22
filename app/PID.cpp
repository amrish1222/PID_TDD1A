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
}

PID::~PID() {
}


double PID::PID::compute() {
return 5.0;
}
