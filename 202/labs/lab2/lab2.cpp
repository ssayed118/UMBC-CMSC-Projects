/*
 * File:    lab2.cpp
 * Project: CMSC 202 Lab 2, Fall 2020
 * Author:  Sumaa Sayed
 * Date:    9/7/2020
 * Section: 20/25
 * Email:   ssayed1@gl.umbc.edu
 * This program tests skills regarding input/output, loops, functions in C++.
 */

#include <iostream>
using namespace std;

/***************************************
 *   FUNCTION PROTOTYPES  
 ***************************************/

int multiplyByThree();
void divisibleByNine(int);

int main() {

  //calling functions
  divisibleByNine(multiplyByThree());
  return 0;
}

//Name: multiplyByThree
//Purpose: The function will request the user to enter 3 integers. Then the 
//	   3 integers will be added up and the sum will be multiplied by 3
//         and displays that result. Finally, the function returns the result.

int multiplyByThree(){
  
  // variables for the 3 integers
  int intOne = 0;
  int intTwo = 0;
  int intThree = 0;
  
  cout << "Enter an integer: ";
  cin >> intOne;
  cout << "Enter an integer: ";                                                
  cin >> intTwo;
  cout << "Enter an integer: ";                                                
  cin >> intThree; 

  //adding the 3 integers and multiplying by 3, printing out the total
  int sum = intOne + intTwo + intThree;
  int newVal = sum * 3;
  cout << "Total: " << newVal << endl;

  return newVal;
}

//Name: divisibleByNine()
//Purpose: Given an integer as a parameter, the function will say
//         if divisible by nine or not.

void divisibleByNine(int newVal){

  // if value is/is not divisible by 9, let the user know 
  if(newVal % 9 == 0){
     cout << "The final value is divisible by 9" << endl;
  }
  
  else{
     cout << "The final value is not divisible by 9" << endl;
  }
}
