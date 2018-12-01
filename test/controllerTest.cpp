/** @file test/controllerTest.cpp
 * @brief GoogleTest- unit tests
 * @brief Google mock
 * @author Driver- Amrish Baskaran; Navigator- Kapil Rawal
 * Copyright 2018 Amrish Baskaran
 */
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include"../include/PID.h"
#include"../include/Controller.h"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

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
  // creating mock object
  MockPID pid;
  EXPECT_CALL(pid, getKp()).Times(AtLeast(1)).WillRepeatedly(Return(1));
  EXPECT_CALL(pid, getKd()).Times(AtLeast(1)).WillRepeatedly(Return(2));
  EXPECT_CALL(pid, getKi()).Times(AtLeast(1)).WillRepeatedly(Return(3));
  EXPECT_CALL(pid, compute()).Times(AtLeast(1)).WillRepeatedly(Return(10));
  EXPECT_CALL(pid, setCurrentState(_,_)).Times(AtLeast(1));
  EXPECT_CALL(pid, setValues(_,_,_,_,_,_)).Times(AtLeast(1));


  int _Kp = pid.getKp();
  int _Kd = pid.getKd();
  int _Ki = pid.getKi();

  //pid.compute();

  Controller _controller(pid);
  int isDone = _controller.runController(10);
  std::cout << isDone << std::endl;

  EXPECT_EQ(0, isDone);
  EXPECT_EQ(1, _Kp);
  EXPECT_EQ(2, _Kd);
  EXPECT_EQ(3, _Ki);

}
