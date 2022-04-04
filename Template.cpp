/******************************************************************************/
/*!
\file   Template.cpp
\author Paul Huffman
\par    email: huffmanp4\@nku.edu
\par    Course: CSC402
\par    Section: 001
\par    Assignment: 4
\date   4/03/2022
\brief
  This file contains the implementation of the template sort assignment.
  Functions included:
    IntWrapper()
    ~IntWrapper()
    IntWrapper()
    operator=()
    operator<()
    StringWrapper()
    ~StringWrapper()
    operator=()
    operator<()
    sort()
    partition()
    isSorted()
    gen_random()
    main()

  Hours spent on this assignment: 2
  Specific portions that gave you the most trouble: I can not get it to run with
    1000000 elements in the vectors.
*/
/******************************************************************************/

#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <chrono>

//! This is the implementation of the IntWrapper class
class IntWrapper {
public:

/****************************************************************************/
/*!
  \brief
    This is a constructor for the IntWrapper class.

  \param value
    This is the value that will be stored in the IntWrapper class.
*/
/****************************************************************************/
     IntWrapper(int value){
      //myInt = new int;
      myInt = value;
    }

/****************************************************************************/
/*!
  \brief
    This is the destructor for the IntWrapper class.
*/
/****************************************************************************/
    ~IntWrapper(){
      //delete myInt;
      //myInt = nullptr;
    }

/****************************************************************************/
/*!
  \brief
    This is the copy constructor for the IntWrapper class.

  \param rhs
    This is the IntWrapper that will be copied.
*/
/****************************************************************************/
    IntWrapper(const IntWrapper &rhs){
      //myInt = new int;
      myInt = rhs.myInt;
    }

/****************************************************************************/
/*!
  \brief
    This is the assignment operator.

  \param rhs
    This is the IntWrapper that will be assigned to another.

  \return
    This function will return a reference to a IntWrapper.
*/
/****************************************************************************/
    IntWrapper& operator=(const IntWrapper &rhs){
      if(this != &rhs){
        myInt = rhs.myInt;
      }

      return *this;
    }

/****************************************************************************/
/*!
  \brief
    This is the less than operator.

  \param rhs
    This is the IntWrapper that will be compared to another.

  \return
    This function will return a bool whether the this IntWrapper is less than
    the rhs IntWrapper.
*/
/****************************************************************************/
    bool operator<(const IntWrapper &rhs) const{
      if(this->myInt > rhs.myInt)
        return false;
      else
        return true;
    }

private:

    int myInt; //!< This is the int that will store the data for this class.
};

//! This is the implementation of the StringWrapper class.
class StringWrapper {
public:

/****************************************************************************/
/*!
  \brief
    This is a constructor for the StringWrapper class.

  \param s
    This is the value that will be stored in the StringWrapper class.
*/
/****************************************************************************/
    explicit StringWrapper(std::string s){
      //myString = new std::string;
      myString = std::move(s);
    }

/****************************************************************************/
/*!
  \brief
    This is the destructor for the StringWrapper class.
*/
/****************************************************************************/
    ~StringWrapper(){
      //delete myString;
      myString = nullptr;
    }

/****************************************************************************/
/*!
  \brief
    This is the copy constructor for the StringWrapper class.

  \param rhs
    This is the StringWrapper that will be copied.
*/
/****************************************************************************/
    StringWrapper(const StringWrapper& rhs){
      //myString = new std::string;
      myString = rhs.myString;
    }

/****************************************************************************/
/*!
  \brief
    This is the assignment operator.

  \param rhs
    This is the StringWrapper that will be assigned to another.

  \return
    This function will return a reference to a StringWrapper.
*/
/****************************************************************************/
    StringWrapper& operator=(const StringWrapper& rhs){
      if(this != &rhs){
        myString = rhs.myString;
      }

      return *this;
    }

/****************************************************************************/
/*!
  \brief
    This is the less than operator.

  \param rhs
    This is the StringWrapper that will be compared to another.

  \return
    This function will return a bool whether the this StringWrapper is less
    than the rhs StringWrapper.
*/
/****************************************************************************/
    bool operator<(const StringWrapper& rhs){
      if(this->myString > rhs.myString)
        return false;
      else
        return true;
    }

private:
      //! This is the string that will hold the data for this class.
    std::string myString;
};

/****************************************************************************/
/*!
  \brief
    This function sorts a vector that is passed to it.

  \param list
    This is a vector of T that will be sorted.

  \param start
    This is an int that tells the function where in the vector to start
    sorting.

  \param end
    This is an int that tells the function where in the vector to stop
    sorting.
*/
/****************************************************************************/
  template <typename T>
  void sort(std::vector<T> &list,int start, int end){
    if(start < end){
      int part = partition(list, start, end);

      sort(list, start, part-1);
      sort(list, part+1, end);
    }
  }

/****************************************************************************/
/*!
  \brief
    This function finds the pivot for sorting the vector of type T that is
    passed to it.

  \param list
    This is a vector of T that will be sorted.

  \param start
    This is an int that tells the function where in the vector to start
    sorting.

  \param end
    This is an int that tells the function where in the vector to stop
    sorting.

  \return
    The function will return an int that will be used as the pivot for
    sorting.
*/
/****************************************************************************/
  template <typename T>
  int partition(std::vector<T> &list, int start, int end){
    int leftWall = start;
    for(int i = start+1; i <= end; i++){
      if(list[i] > list[start]){
        std::swap(list[i], list[leftWall+1]);
        leftWall += 1;
      }
    }
    std::swap(list[start], list[leftWall]);
    return leftWall;
  }

/****************************************************************************/
/*!
  \brief
    This function will walk the entire length of the vector to check if it
    is sorted properly.

  \param list
    This is a vector of T that will be checked.

  \return
    The function will return a bool to tell whether the vector is sorted
    properly.
*/
/****************************************************************************/
  template <typename T>
  bool isSorted(std::vector<T> &list) {
    for(int i = 1; i < (int)list.size(); i++){
      if(list[i - 1] < list[i])
        return false;
    }
    return true;
  }

/****************************************************************************/
/*!
  \brief
    This function generate a random string. It was stolen from
    https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
    I modified it slightly.


  \param len
    This is the length of the string that will be generated.

  \param dist
    This is used to generate the random number for making the random string.

  \param eng
    This is used to generate the random number for making the random string.

  \return
    The function will return a string that has been randomly generated.
*/
/****************************************************************************/
  std::string gen_random(const int len,
                         std::uniform_int_distribution<int> dist,
                         std::default_random_engine eng) {
    static const char alphanum[] =
          "0123456789"
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
          "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
      tmp_s += alphanum[dist(eng) % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
  }

/****************************************************************************/
/*!
  \brief
    This is the main function. It will generate a number of random numbers
    and strings and store them in vectors of IntWrapper* or StringWrapper*.
    The function will then call the sort function to sort the vectors. Then
    it will check if the vectors were properly sorted by calling isSorted().
    Finally it will print to screen how long it took to sort the vectors.

  \return
    This function will always return 0.
*/
/****************************************************************************/
int main() {
  std::random_device r;
  std::default_random_engine eng(r());
  std::uniform_int_distribution<int> dist(0, 1000);
  std::uniform_int_distribution<int> dist2(0, 4);

  std::vector<IntWrapper*> list;
  std::vector<StringWrapper*> list2;

  std::cout<<"Output for 100000 elements."<<std::endl;

  for(int i = 0; i < 3; i++) {

    for (int j = 0; j < 100000; j++) {
      IntWrapper *temp;
      temp = new IntWrapper(dist(eng));
      list.push_back(temp);
    }

    auto start = std::chrono::high_resolution_clock::now();

    sort(list, 0, 100000 - 1);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    if (!isSorted(list)) {
      std::cout << "The lists were not sorted properly." << std::endl;
      return 0;
    }

    std::cout << "Time taken to sort IntWrapper: "
              << duration.count() << " microseconds" << std::endl;

    for (int j = 0; j < 100000; j++) {

      StringWrapper *temp2;
      temp2 = new StringWrapper(gen_random(dist2(eng), dist, eng));
      list2.push_back(temp2);
    }

    auto start2 = std::chrono::high_resolution_clock::now();

    sort(list2, 0, 100000 - 1);

    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 =
            std::chrono::duration_cast<std::chrono::microseconds>
                    (stop2 - start2);

    if (!isSorted(list2)) {
      std::cout << "The lists were not sorted properly." << std::endl;
      return 0;
    }


    std::cout << "Time taken to sort StringWrapper: "
              << duration2.count() << " microseconds" << std::endl<<std::endl;

    list.clear();
    list2.clear();

  }

  return 0;
}