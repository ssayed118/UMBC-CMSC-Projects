/************************                                                      
* File: Peashooter.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Peashooter file for Plant/Entity class for project 4.     
**************************/
#include "Peashooter.h"
#include "Plant.h"
#include "Entity.h"
#include <iostream>
using namespace std;

//default constructor                                                       
//preconditons: none                                                           
//postcondtions: can create a peashooter      
//Peashooter::Peashooter(){}

//overloaded constructor
//preconditons: none
//postcondtions: can create a peashooter 
Peashooter::Peashooter(string name, int health)
  :Plant(name, health){
}

//deconstructor
//preconditons: none
//postcondtions: things are deallocated
Peashooter::~Peashooter(){
}

//SpecialAttack() - defines special attack
//precondtions: none
//postconditons: returns damage
int Peashooter::SpecialAttack(){
  int random; // holds value for damage
  random = (rand() % 12) + 3; //gets random value for damage
  cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
  return random;
}
