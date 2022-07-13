/************************                                                      
* File: Sunflower.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Sunflower file for Plant/Entity class for project 4.     
**************************/

#include "Sunflower.h"
#include "Plant.h"
#include "Entity.h"
#include <iostream>
using namespace std;
//cue Sunflower vol. 6 by Harry Styles or Sunflower by Post Malone

//default constructor                                                          
//preconditons: none                                                           
//postcondtions: can create a sunflower
//Sunflower::Sunflower(){}

//overloaded constructor                                             
//preconditons: none                                                           
//postcondtions: can create a sunflower     
Sunflower::Sunflower(string name, int health)
  :Plant(name, health){
}

//deconstructor                                                         
//preconditons: none                                                          
//postcondtions: things are deallocated   
Sunflower::~Sunflower(){
}

//SpecialAttack() - special attack for sunflower
//preconditons: none
//postcondtions: returns damage from special attack
int Sunflower::SpecialAttack(){
  int random; //holds value for damage
  random = (rand() % 8) + 1; //gets random value for damage
  cout << GetName() << " uses a high beam turret - **SUNBEAM**" << endl;
  return random;
}
