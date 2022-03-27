//
// Created by paulh on 3/21/2022.
//

#ifndef OO_ICOMPARABLE_H
#define OO_ICOMPARABLE_H


class IComparable {
public:
     virtual bool isLessThan(IComparable& rhs) = 0;

};


#endif //OO_ICOMPARABLE_H
