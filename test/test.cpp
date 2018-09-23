/** @file test/main.cpp
 * @brief GoogleTest- unit tests
 * @author Driver- Amrish Baskaran; Navigator- Kapil Rawal
 * Copyright 2018 Amrish Baskaran
 */
#include <gtest/gtest.h>

#include<PID.h>




/**
 * @brief Test initialization of private variables
 */
TEST(PID_Test, InitValuesTest) {
  PID PID1;    // initializes an instance of the class

  EXPECT_EQ(0, PID1.getKp());
  EXPECT_EQ(0, PID1.getKd());
  EXPECT_EQ(0, PID1.getKi());
  EXPECT_EQ(0, PID1.getMin());
  EXPECT_EQ(0, PID1.getMax());
  EXPECT_EQ(0.0001, PID1.getDt());
}

/**
 * @brief Test function that sets
 * the required parameters- gains, time and restrictions
 */
TEST(PID_Test, SetParamsTest) {
  PID PID1;
  PID1.setValues(1, 0.5, 0.1, 1, 30, 2);  // Setting the required parameters.
  EXPECT_EQ(1, PID1.getKp());
  EXPECT_EQ(0.5, PID1.getKi());
  EXPECT_EQ(0.1, PID1.getKd());
  EXPECT_EQ(2, PID1.getMin());
  EXPECT_EQ(30, PID1.getMax());
  EXPECT_EQ(1, PID1.getDt());
}

/**
 * @brief Test compute method
 */
TEST(PID_Test, ComputeMethodTest) {
  PID PID1;
  PID1.setValues(1, 0.5, 0.1, 1, 30, 2);
  PID1.setCurrentState(10, 5);        // Setting the current state of the system
  double OutputVal = PID1.compute();     // Executing the PID compute method

  // for kp=1, ki=0.5, kd =0.1 and dt=1 second, setPoint velocity =10 m/s,
  // present velocity=5m/s with prevError=0 the output is 8 m/s.
  EXPECT_NEAR(8, OutputVal, 0.1);
}

