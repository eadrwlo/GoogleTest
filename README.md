# GoogleTest - example 

Main concepts:
googletest (gtest) - Testing framework from Google
googlemock (gmock) - Mocking loibrary from Google - part of gtest

Links:
googletest - https://github.com/google/googletest


Project structure:

lib - contains googletest from github
Controller - example class for mocking demonstration

##How to set up a google test?
* branch **master** - environment is prepared to work with CLion and CMake.
  Clone repository and download googletest from link in Links chapter and place it in **lib**  directory.
 
* branch **no_cmake** - environment is prepared to be compile using **g++**, e.g
  g++ -Wall Controller.h Controller.cpp main.cpp -std=c++11 -lgtest -lgtest_main -lgmock -pthread

  But, before doing that you have to download googletest and googlemock on your OS to:
  -  /usr/src/googletest
  To do that install libgtest-dev packet:
  - sudo apt-get install libgtest-dev


 
