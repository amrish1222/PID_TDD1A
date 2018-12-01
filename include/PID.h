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
  /**
   * @brief kp proportional gain
   */
  double kp;

  /**
   * @brief kd derivative gain
   */
  double kd;

  /**
   * @brief ki integral gain
   */
  double ki;

  /**
   * @brief storing the previous error value
   */
  double prevError;

  /**
   * @brief dT time constant
   */
  double dt;

  /**
   * @brief minimum value of output of compute()
   */
  double minRange;

  /**
   * @brief maximum value of output of compute()
   */
  double maxRange;

  /**
   * @brief setpoint- desired value
   */
  double setPoint;

  /**
   * @brief Process variable -value returned by the sensor/ feedback
   */
  double feedBackVal;

  /**
   * @brief error collection for the integral part
   */
  double Integral;

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
   * @return new controller value.
   */
  virtual double compute();  // Compute method

  /**
   * @brief returns the private kp variable.
   * @param none
   * @return kp value.
   */
  virtual double getKp();

  /**
   * @brief returns the private kd variable.
   * @param none
   * @return kd value.
   */
  virtual double getKd();

  /**
   * @brief returns the private ki variable.
   * @param none
   * @return ki value.
   */
  virtual double getKi();

  /**
   * @brief returns the private dt variable.
   * @param none
   * @return dt value.
   */
  virtual double getDt();

  /**
   * @brief returns the private maxRange variable.
   * @param none
   * @return maxRange value.
   */
  virtual double getMax();

  /**
   * @brief returns the private minRange variable.
   * @param none
   * @return minRange value.
   */
  virtual double getMin();

  /**
   * @brief Initializes the required variables
   * @param Kp1:double, Ki1:double, Kd1:double, dt1:double, max1:double, min1:double
   * @return none.
   */
  virtual void setValues(double Kp1, double Ki1, double Kd1, double dt1,
                         double max1,
                 double min1);

  /**
   * @brief Initializes the required variables
   * @param setPoint1:double, feedBackVal1:double
   * @return none.
   */
  virtual void setCurrentState(double setPoint, double feedBackVal1);
};



#endif /* INCLUDE_PID_H_ */
