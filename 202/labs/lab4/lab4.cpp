/*****************************************                                     
** File:    lab4.cpp                                                          
** Project: CMSC 202 Lab 4, Fall 2020                                      
** Author:  Sumaa Sayed                                                        
** Date:    9/20/20                                                            
** Section: 20/25                                                              
** E-mail:  ssayed1@gl.umbc.edu                                                
**                                                                             
** This lab is to practice passing variables by value and reference.         
***********************************************/

#include <iostream>
using namespace std;

// Constants go here
const int START_GOLD = 500;
const int BAIT = 5;
const int SELL_PRICE = 10;

//function prototypes
void goFishing(int&, int&);
void sellFish(int*, int*);

int main(){
  int fish = 0;
  int gold = START_GOLD;

  cout << "You wake up at 6 am." << endl;
  cout << "You have " << fish << " fish" << endl;
  cout << "You have " << gold << " gold coins" << endl;
  cout << endl;

  // Call goFishing by reference
  goFishing(fish, gold);

  cout << endl;
  cout << "You now have " << fish << " fish" << endl;
  cout << "You now have " << gold << " gold coins" << endl;
  cout << endl;

  // Call sellFish by pointer
  sellFish(&fish, &gold);

  cout << endl;
  cout << "It is 10 pm and you decide to go to bed" << endl;
  cout << "You end the day with " << fish << " fish" << endl;
  cout << "You end the day with " << gold << " gold coins" << endl;

  return 0;
}

// Implement goFishing and sellFish below
void goFishing(int &fish, int &gold){
  
  //variable to hold value for fish
  int numFish = 0;
  cout << "How much bait would you like to buy? (5 gold per bait)" << endl;
  cin >> numFish;
  
  //validation for gold
  while(numFish > 100){
    cout << "Cannot buy that much bait" << endl;
    numFish = 0;
    cout << "How much bait would you like to buy? (5 gold per bait)" << endl;
    cin >> numFish;
  }
  
  gold = (numFish * BAIT);
  gold = (START_GOLD - gold);
 
  cout << "You bought " << numFish << " bait and went fishing" << endl;
  fish = (fish + numFish);
}

void sellFish(int *fish, int *gold){
  
  //variable to hold gold value
  int numGold = 0;
  numGold = (*fish * SELL_PRICE);
  
  cout << "You sold " << *fish << " and earned " << numGold << " gold coins." << endl;

  *fish -= *fish;
  *gold += numGold;
}
