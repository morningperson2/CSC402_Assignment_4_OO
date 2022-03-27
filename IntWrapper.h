//
// Created by paulh on 3/21/2022.
//

#ifndef OO_INTWRAPPER_H
#define OO_INTWRAPPER_H
#include "IComparable.h"

class IntWrapper: public IComparable{
public:
  IntWrapper();

  IntWrapper(int value);

  ~IntWrapper();

  IntWrapper(const IntWrapper &rhs);

  IntWrapper& operator=(const IntWrapper &rhs);

  IntWrapper& operator=(const IComparable &rhs);

  bool isLessThan(IComparable& rhs);

  void setInt(int nInt);

  int getInt();

private:
    bool operator()(IntWrapper &lhs, IntWrapper &rhs);

    int myInt;

};


#endif //OO_INTWRAPPER_H
