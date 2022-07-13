/************************                                                      
* File: lab11b.cpp                                                             
* Project: CMSC202, Lab 11, Fall 2020                                          
* Author: Sumaa Sayed                                                          
* Date: 11/12/2020                                                             
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Lab11b file.                                      
**************************/
#include <iostream>
using namespace std;
// Use this file to implement the templated class UserList
// UserList is a class that stores an array of 5 elements of a templated type
// The constructor takes no parameters and sets all elements of the array to 0
// SetIndex function takes an index and value
//    and sets the element of the array at the given index to the given value
//    (assume 0<=index<=4)
// GetMax function should return the maximum of all elements in the list

// Implement the class UserList here:
template <class T>
class UserList{
private:
  int m_array[5] = {};
  
public:
  int SetIndex(int index, T const &value);
  float GetMax();
};

template <class T>
int UserList<T>::SetIndex(int index, T const &value){//set value at specified index
  m_array[index] = value;
  return 0;
}

template <class T>
float UserList<T>::GetMax(){//get biggest number
  int max = m_array[0];
  for(int i = 0; i < 5; ++i){
    if(max < m_array[i]){
      max = m_array[i];
    }
  }
  return max;
}

int main(){
  UserList<int> intList;            // list of 5 ints
  UserList<float> floatList;        // list of 5 floats
  UserList<unsigned int> uintList;  // list of 5 unsigned ints
  // test list of ints
  int intVals[] = {1,2,3,4,-5};
  for (int i=0; i<5; i++) {
    intList.SetIndex(i, intVals[i]);
  }
  cout << "intList max (4 expected): ";
  cout << intList.GetMax() << endl;
  
  // test list of floats
  // initial list should be all 0.0
  cout << endl << "floatList max (0 expected): ";
  cout << floatList.GetMax() << endl;
  float floatVals[] = {10,1.5,2.5,4,-4.5};
  for (int i=0; i<5; i++) {
    floatList.SetIndex(i, floatVals[i]);
  }
  cout << endl << "floatList max (10 expected): ";
  cout << floatList.GetMax() << endl;
  
  // test list of unsigned ints
  unsigned int uintVals[] = {56,1,78,2,3};
  for (int i=0; i<5; i++) {
    uintList.SetIndex(i, uintVals[i]);
  }
  cout << endl << "uintList max (78 expected): ";
  cout << uintList.GetMax() << endl << endl;

  return 0;
}

