/************************                                                      
* File: lab11a.cpp                                                             
* Project: CMSC202, Lab 11, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/11/2020                                                             
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Lab11a file 
**************************/

#include <iostream>
using namespace std;

// Use this file to implement two functions.
// Function 1: A templated function to display information about two variables
//             and the results of a function all to a templated IsLessThan function
//             Should display "10 < 5: (the result of IsLessThan)"
// Function 2: A templated IsLessThan function
//             IsLessThan function returns a bool:
//             true if a is less than b
//             false if a is greater than or equal to b
// Both functions take two args:
//   a: object of type T (where T is the templated class type)
//   b: object of type T (where T is the templated class type)
//


// Implement the templated IsLessThan function here:
template <class T>
int IsLessThan(const T &a, const T &b){
  if(a < b){
    return 1; 
  }else{
    return 0;
  }
}  
// Implement the templated DisplayInfo function here:
template <class T>
void DisplayInfo(const T &a, const T &b){
  cout << a << " < " << b << ": " << IsLessThan(a, b) << endl;
}

int main(){
  DisplayInfo(10,5);
  DisplayInfo(20,20);
  DisplayInfo(5,10);
  DisplayInfo('a','b');
  DisplayInfo(true,true);
  return 0;
}

