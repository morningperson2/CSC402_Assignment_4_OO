//
// Created by paulh on 3/21/2022.
//


#include "IntWrapper.h"

IntWrapper::IntWrapper() {
  myInt = 0;
}

IntWrapper::IntWrapper(int value) {
  myInt = value;
}

IntWrapper::~IntWrapper() {
  myInt = 0;
}

IntWrapper::IntWrapper(const IntWrapper &rhs) {
  myInt = rhs.myInt;
}

IntWrapper &IntWrapper::operator=(const IntWrapper &rhs) {
  if(this != &rhs){
    myInt = rhs.myInt;
  }

  return *this;
}

bool IntWrapper::isLessThan(IComparable& rhs) {
  if(myInt < dynamic_cast<IntWrapper&>(rhs).myInt)
    return true;
  else
    return false;
}

void IntWrapper::setInt(int nInt) {
  myInt = nInt;
}


