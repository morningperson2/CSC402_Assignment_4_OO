//
// Created by paulh on 3/23/2022.
//
#include "sort.h"

void sort(std::vector<IComparable>list, int start, int end) {
  if(start < end){
    int part = partition(list, start, end);

    sort(list, start, part-1);
    sort(list, part+1, end);
  }
}

int partition(std::vector<IComparable>list, int start, int end){
  int pivot = end;
  int j = start;

  for(int i = start; i < end; i++){
    if(list[i].isLessThan(list[pivot])){
      swap(list[i], list[j]);
      j++;
    }
  }
  swap(list[j], list[pivot]);
  return j;
}

void swap(IComparable &x, IComparable &y){
  IComparable *temp;
  temp = &x;
  x = std::move(y);
  y = std::move(*temp);
}

bool isSorted(std::vector<IComparable> list) {
  for(int i = 1; i < list.size(); i++){
    if(!list[i-1].isLessThan(list[i]))
      return false;
  }
  return true;
}

