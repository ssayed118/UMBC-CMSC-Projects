/*                                                                             
 * File:    lab3.cpp                                                           
 * Project: CMSC 202 Lab 3, Fall 2020                                          
 * Author:  Sumaa Sayed                                                        
 * Date:    9/14/2020         
 * Section: 20/25                                                              
 * Email:   ssayed1@gl.umbc.edu                                                
 * This program tests skills regarding input/output, arrays and functions.  
 */

#include <iostream>
using namespace std;

// FUNCTION PROTOTYPES
int smallestNum(int[], int);
int largestNum(int[], int);
int avgNum(int[], int);

int main(){
  //variables
  const int MAXSIZE = 100;      //Constant maximum size of the array
  int myArray[MAXSIZE] = {0};   //Initializes the values of the array to 0's 
  int currSize = 0;      //Keeps track of current size of the array
  int inputValue;     //Used to get the input in order to store it in the array

//Code up the user's input, print out the array and then call the functions and return the expected output
  cout << "Enter a number (0 when done): ";
  cin >> inputValue;

  while(inputValue != 0 && currSize < MAXSIZE){
    myArray[currSize] = inputValue;
    currSize ++;

    cout << "Enter a number (0 when done): ";
    cin >> inputValue;                       
  }
  
  //printing out the array
  cout << "Original Array: ";
  for (int i = 0; i < currSize; ++i){
    cout << myArray[i] << "  ";
  }

  //calling the functions and returning the appropriate values
  cout << "\nSmallest number in the array: " << smallestNum(myArray, currSize) << endl;
  
  cout << "Largest number in the array: " << largestNum(myArray, currSize) << endl;
  
  cout << "Average of the array: " << avgNum(myArray, currSize) << endl;
  
  return 0;
}

//Name: smallestNum
//Purpose: This function will return the smallest number within the array   
int smallestNum(int myArray[], int currSize){
  int i = 0; //Keeps track of the number that the loop is checking            
  int lastNum = myArray[0]; //Keeps track of the smallest number
  
  for(i = 1; i < currSize; ++i){
    if(lastNum > myArray[i])
      lastNum = myArray[i];
  }

  return lastNum;
}

//Name: largestNum
//Purpose: This function will return the largest number within the array 
int largestNum(int myArray[], int currSize){
  int i = 0; //Keeps track of the number that the loop is checking 
  int firstNum = myArray[0]; //Keeps track of the largest number
  
  for(i = 1; i < currSize; ++i){
    if(firstNum < myArray[i])
      firstNum = myArray[i];
  }
 
  return firstNum;
}

//Name: avgNum
//Purpose: This function will return the average (or the mean) of the array
int avgNum(int myArray[], int currSize){
  int i = 0; //Keeps track of the number that the loop is checking
  int sum = 0; //Sum of all the numbers in myArray
  double average = 0.0; //Average/mean of the numbers in myArray

  for(i = 0 ; i < currSize; ++i){
    sum += myArray[i];
  }

  if (currSize == 0){
    return 0;
  }
  
  average = (sum) / currSize;

  return average;
}
