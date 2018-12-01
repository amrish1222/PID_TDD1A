/** @file test/controllerTest.cpp
 * @brief GoogleTest- unit tests
 * @brief Google mock
 * @author Driver- Amrish Baskaran; Navigator- Kapil Rawal
 * Copyright 2018 Amrish Baskaran
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include"../include/PID.h"
#include"../include/Controller.h"

using ::testing::AtLeast;

class MockPID : public PID {
 public:
  MOCK_METHOD0(compute, double());
  MOCK_METHOD0(getKp, double());
  MOCK_METHOD0(getKd, double());
  MOCK_METHOD0(getKi, double());
  MOCK_METHOD0(getDt, double());
  MOCK_METHOD0(getMax, double());
  MOCK_METHOD0(getMin, double());
  MOCK_METHOD6(setValues,void(double Kp1, double Ki1, double Kd1, double dt1, double max1,double min1));
  MOCK_METHOD2(setCurrentState,void(double setPoint, double feedBackVal1));
};

TEST(ControllerTest,RunControllerTest) {
  MockPID pid;
  EXPECT_CALL(pid, compute()).Times(AtLeast(1));
  Controller _controller(pid);
  int isDone = _controller.runController(10);
  EXPECT_EQ(0, isDone);

}
