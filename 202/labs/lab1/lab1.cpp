/*****************************************                                    
** File:    lab1.cpp                                                           
** Project: CMSC 202 Lab 1, Fall 2020                                          
** Author:  Sumaa Sayed                                                        
** Date:    8/30/20                                                            
** Section: 20/25                                                              
** E-mail:  ssayed1@gl.umbc.edu                                                
**                                                                             
** This program will take in user input for a dog's name and age. Then, it will** allow the user to pick thign they want to do with their dog, and stop after ** 3 things.                                          
***********************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {

  //variables
  char name[80];
  int age;
  int options;
  int counter = 0;

  // setting the dog's name in the name variable
  cout << "What is your dog's name? ";
  cin >> name;

  //setting the dog's age in the age variable
  cout << "How old is your dog? ";
  cin >> age;

  //validating age so the number is between 0 and 22
  while(age < 0 or age > 22) {
    cout << "Please enter your dog's age, it should be an integer between 0 and 22 ";
    cin >> age;
  }
  
  cout << "Dog Name = " << name << endl;
  cout << "Dog's Age = " << age << endl;

  // making sure the loop goes up to the 3 in the counter
  while(counter < 3){
    cout << "What would you like to do? " << endl;
    cout << "1. Pet " << name << endl;
    cout << "2. Feed " << name << endl;
    cout << "3. Chase " << name << endl;
    cout << "Enter your choice: "; 
    cin >> options;                                   

    // validating that the user enters a number between 1 and 3
    while(options < 1 or options > 3) {
      cout << "Enter your choice (1-3): ";
      cin >> options;
    }

    // for each option, it prints out a sentence and adds 1 to the counter
      if (options == 1){
	cout << "You pet " << name << " and they are happy." << endl;
	counter +=1; 
      }

      else if (options == 2){
	cout << name << " growls gently as you feed them." << endl;
	counter += 1;
      }

      else if (options == 3){
	cout << "You chase after " << name << " and they wag their tail." << endl;
	counter += 1;
    }
  }

  // once the counter reaches 3, the program stops
  if (counter == 3){
    cout << "That is enough for today. Good-bye" << endl;}
    
   return 0;
}
