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
  double dt;
  double integral;
  double minRange;
  double maxRange;
  double setPoint;
  double feedBackVal;

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

  /**
   * @brief returns the private kp variable.
   * @param none
   * @return kp value.
   */
  double getKp();

  /**
   * @brief returns the private kd variable.
   * @param none
   * @return kd value.
   */
  double getKd();

  /**
   * @brief returns the private ki variable.
   * @param none
   * @return ki value.
   */
  double getKi();

  /**
   * @brief returns the private dt variable.
   * @param none
   * @return dt value.
   */
  double getDt();

  /**
   * @brief returns the private maxRange variable.
   * @param none
   * @return maxRange value.
   */
  double getMax();

  /**
   * @brief returns the private minRange variable.
   * @param none
   * @return minRange value.
   */
  double getMin();

  /**
   * @brief Initializes the required variables
   * @param Kp1:double, Ki1:double, Kd1:double, dt1:double, max1:double, min1:double
   * @return none.
   */
  void setValues(double Kp1, double Ki1, double Kd1, double dt1, double max1,
                 double min1);

  /**
   * @brief Initializes the required variables
   * @param setPoint1:double, feedBackVal1:double
   * @return none.
   */
  void setCurrentState(double setPoint, double feedBackVal1);
};



#endif /* INCLUDE_PID_H_ */
