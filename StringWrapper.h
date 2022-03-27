//
// Created by paulh on 3/21/2022.
//

#ifndef OO_STRINGWRAPPER_H
#define OO_STRINGWRAPPER_H
#include <string>
#include "IComparable.h"

class StringWrapper: public IComparable{
public:
    ~StringWrapper();

    StringWrapper(const StringWrapper& rhs);

    StringWrapper& operator=(const StringWrapper& rhs);

    bool isLessThan(IComparable& rhs);

private:
    std::string myString;

};


#endif //OO_STRINGWRAPPER_H
