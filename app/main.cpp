/** @file main.cpp
 * @brief Executing PID controller
 * @author Driver- Amrish Baskaran; Navigator- Kapil Rawal
 * @author part2 - Saimouli Katragadda
 * Copyright 2018 Amrish Baskaran
 */
#include <iostream>
#include "../include/Controller.h"

int main() {
  PID pid;
  Controller _controller(pid);
  if (_controller.runController(10) == 0) {
    std::cout << "Target Velocity= 10 Reached!!" << std::endl;
  }

  return 0;
}
