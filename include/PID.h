/** @file PID.h
 * @brief PID controller header file.
 * @author Driver- Amrish Baskaran; Navigator- Kapil Rawal
 * Copyright 2018 Amrish Baskaran
 */


#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_


class PID {
 private:
  // Declaration of class members
  double kp;
  double kd;
  double ki;
  double prevError;

 public:

  /**
   * @brief Constructor that sets all the required variables to zero.
   * @param none
   * @return none
   */

  PID();            // Constructor
  virtual ~PID();   // Destructor

  /**
   * @brief executes the PID controller flow.
   * @param none
   * @return new control value.
   */

  double compute();  // Compute method
};



#endif /* INCLUDE_PID_H_ */
