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
 * @file PID.h
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
