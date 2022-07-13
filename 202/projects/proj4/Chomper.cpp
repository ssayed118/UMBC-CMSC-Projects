/************************                                                      
* File: Chomper.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Chomper file for Plant/Entity class for project 4.     
*************************/

#include "Chomper.h"
#include "Plant.h"
#include "Entity.h"
#include <iostream>
using namespace std;

//default constructor
//preconditons: none
//postconditons: can create a chomper
//Chomper::Chomper(){}

//overloaded constructor
//precodnitons: none
//postconditons: can create a chomper
Chomper::Chomper(string name, int health)
  :Plant(name, health){
}

//desctructor
//preconditons: none
//postconditons: everything dynamically allocated is deallocated
Chomper::~Chomper(){
}

//SpecialAttack()
//preconditons: defines chompers special attack
//postcondtions: returns damage from special attack
int Chomper::SpecialAttack(){
  int random; //holds value for damage
  random = (rand() % 12) + 2; //gets randome value for damage
  cout << GetName() << " performs a sneak attack! CHOMP" << endl;
  return random;
}
