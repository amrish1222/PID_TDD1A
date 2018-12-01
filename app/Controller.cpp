/*
 * Controller.cpp
 *
 *  Created on: Nov 30, 2018
 *      Author: amrish1222
 */

#include <iostream>
#include "PID.h"
#include "Controller.h"

Controller::Controller(PID &_p1)
    : _pid(_p1) {


}

Controller::~Controller() {

}

int Controller::runController(double velocity) {
  // set the PID controller gains
  _pid.setValues(0.1, 0.1, 0.1, 0.5, 20, 0);
  int count = 0;
  // set the required final velocity
  double _setPoint = velocity;
  // return feedback value
  double _feedBack = 0;
  bool stop = false;
  while (!stop) {
    _pid.setCurrentState(_setPoint, _feedBack);
    double ucontrol = _pid.compute();
    // system can go to the controller input in the given time
    _feedBack += ucontrol;
    // printing the current acquired velocity
    std::cout << _feedBack << std::endl;
    count += 1;
    if (_setPoint - _feedBack > 0.01) {
      stop = false;
    } else {
      stop = true;
    }
    if (count > 150) {
      // return 1 if number of iterations are
      // beyond 150.
      return 1;
  }
    }
  // return 0 if success
  return 0;
  }

