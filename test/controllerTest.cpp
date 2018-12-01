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
 * @file test/controllerTest.cpp
 * @brief GoogleTest- unit tests
 * @brief GoogleMock
 * @author Author- Amrish Baskaran
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

#include"../include/Controller.h"

#include"../include/PID.h"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

/**
 * @brief Mocking the PID class
 */
class MockPID : public PID {
 public:
  MOCK_METHOD0(compute, double());
  MOCK_METHOD0(getKp, double());
  MOCK_METHOD0(getKd, double());
  MOCK_METHOD0(getKi, double());
  MOCK_METHOD0(getDt, double());
  MOCK_METHOD0(getMax, double());
  MOCK_METHOD0(getMin, double());
  MOCK_METHOD6(setValues, void(double Kp1, double Ki1,
          double Kd1, double dt1, double max1, double min1));
  MOCK_METHOD2(setCurrentState, void(double setPoint, double feedBackVal1));
};

/**
 * @brief Testing the controller class using the mocked class
 */
TEST(ControllerTest, RunControllerTest) {
  // creating mock object
  MockPID pid;
  // Expectations for Mock class
  EXPECT_CALL(pid, getKp()).Times(AtLeast(1)).WillRepeatedly(Return(1));
  EXPECT_CALL(pid, getKd()).Times(AtLeast(1)).WillRepeatedly(Return(2));
  EXPECT_CALL(pid, getKi()).Times(AtLeast(1)).WillRepeatedly(Return(3));
  EXPECT_CALL(pid, compute()).Times(AtLeast(1)).WillRepeatedly(Return(10));
  EXPECT_CALL(pid, setCurrentState(_, _)).Times(AtLeast(1));
  EXPECT_CALL(pid, setValues(_, _, _, _, _, _)).Times(AtLeast(1));
  // using mock to check function outputs
  int _Kp = pid.getKp();
  int _Kd = pid.getKd();
  int _Ki = pid.getKi();
  // running controller to check mocked class
  Controller _controller(pid);
  // run controller to achieve velocity 10.
  int isDone = _controller.runController(10);
  // Testing using gtest
  EXPECT_EQ(0, isDone);
  EXPECT_EQ(1, _Kp);
  EXPECT_EQ(2, _Kd);
  EXPECT_EQ(3, _Ki);
}
