/*
 * Controller.h
 *
 *  Created on: Nov 30, 2018
 *      Author: amrish1222
 */

#ifndef INCLUDE_CONTROLLER_H_
#define INCLUDE_CONTROLLER_H_

#include "../include/PID.h"

class Controller {
 public:
  Controller(PID& pid);
  virtual ~Controller();

  PID _pid;

  int runController(double velocity);
};

#endif /* INCLUDE_CONTROLLER_H_ */
