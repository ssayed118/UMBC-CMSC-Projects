/************************                                                      
* File: Engineer.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Engineer file for Zombie/Entity class for project 4.     
*************************/

#include "Engineer.h"
#include "Zombie.h"
#include "Entity.h"
#include <iostream>
using namespace std;

//default constructor
//precondtions: none
//postconditons: can create an engineer
//Engineer::Engineer(){}

//overloaded constructor
//precondtions: none
//postconditons: can create an engineer 
Engineer::Engineer(string name, int health)
  :Zombie(name, health){
}

//SpecialAttack()
//precondtions: none
//postcondtions: returns damage from special attack
int Engineer::SpecialAttack(){
  cout << GetName() << " blasts you with their steam blaster!" << endl;
  return 2;
}
