//
// Created by paulh on 3/21/2022.
//

#include "StringWrapper.h"

#include <utility>

StringWrapper::~StringWrapper() {
  myString = " ";
}

StringWrapper::StringWrapper(const StringWrapper &rhs) {
  myString = rhs.myString;
}

StringWrapper &StringWrapper::operator=(const StringWrapper &rhs) {
  if(this != &rhs){
    myString = rhs.myString;
  }

  return *this;
}

bool StringWrapper::isLessThan(IComparable& rhs) {
  StringWrapper temp = dynamic_cast<StringWrapper&>(rhs);
  if(myString < temp.myString)
    return true;
  else
    return false;
}
