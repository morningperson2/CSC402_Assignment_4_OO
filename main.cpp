#include <iostream>
#include <vector>
#include <random>
#include "IntWrapper.h"
#include "IComparable.h"
#include "sort.h"

#define length 1000

int main() {
  std::random_device r;
  std::default_random_engine eng(r());
  std::uniform_int_distribution<int> dist(0, 1000);

  std::vector<IComparable> list;
  for(int i = 0; i<length; i++){
    IntWrapper temp;
    temp.setInt(dist(eng));
    list.push_back(temp);
  }

  sort(list, 0, length);

  std::cout<<"hi"<<std::endl;

  return 0;
}
