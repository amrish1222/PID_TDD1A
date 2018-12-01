# PID Controller TDD1A
[![Build Status](https://travis-ci.org/amrish1222/PID_TDD1A.svg?branch=master)](https://travis-ci.org/amrish1222/PID_TDD1A)
[![Coverage Status](https://coveralls.io/repos/github/amrish1222/PID_TDD1A/badge.svg?branch=master)](https://coveralls.io/github/amrish1222/PID_TDD1A?branch=master)
---

## Overview
Implementation of gmock testing on the previously made repo for testing the toy PID controller.

- Dependencies
* cmake
* googletest
* gmock
* Travis CI
* Coveralls

## Google Mock testing
A new controller class is made to test Mock of the PID class using gmock.

controllerTest.cpp file contains the gmock implementation of the PID class used for testing the Controller class.

Using Google Mock involves three basic steps:

Use some simple macros to describe the interface you want to mock, and they will expand to the implementation of your mock class;
Create some mock objects and specify its expectations and behavior using an intuitive syntax;
Exercise code that uses the mock objects. Google Mock will catch any violation of the expectations as soon as it arises.

Instruction for using Gmock can be found [Here](https://github.com/abseil/googletest/blob/master/googlemock/docs/ForDummies.md)

## Standard install via command-line
```
git clone https://github.com/amrish1222/PID_TDD1A.git
cd <path to repository>
```
- Move to the required Branch
```
git checkout GMock_Extra_Credit
```
- Build the Project

```
mkdir build
cd build
cmake ..
make
```
- Run the program
```
./app/shell-app
```

- Run tests
```
./test/cpp-test
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)
