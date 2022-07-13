/************************                                                      
* File: Plant.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Plant file for Entity class for project 4.     
**************************/

#include "Plant.h"
#include "Entity.h"
#include <iostream>
using namespace std;

//constructor                                                       
//preconditons: none                                                           
//postcondtions: can create a plant      
Plant::Plant(string name, int health)
  :Entity(name, health){
}

//deconstructor
//preconditons: none                                                           
//postcondtions: things are deallocated      
Plant::~Plant(){  
}

//Attack() - describes attack for plant
//precondtions: none
//postconditons: none
int Plant::Attack(){
  int random; //holds value for damage
  random = (rand() % 6) + 1; //gets random value for damage
  cout << GetName() << " attacks dealing " << random << " damage" << endl;
  return random;
}

//SpecialAttack() - special attack for plant
//preconditons: none
//postconditons: used for child class function call
int Plant::SpecialAttack(){
  cout << "Plant does not have a special attack." << endl;
  return 0;
}
