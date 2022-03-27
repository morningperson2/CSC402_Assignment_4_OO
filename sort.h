//
// Created by paulh on 3/23/2022.
//
#include <vector>
#include "IComparable.h"

#ifndef OO_SORT_H
#define OO_SORT_H

void sort(std::vector<IComparable> list, int start, int end);

int partition(std::vector<IComparable> list, int start, int end);

void swap(IComparable &x, IComparable &y);

bool isSorted(std::vector<IComparable> list);

#endif //OO_SORT_H
