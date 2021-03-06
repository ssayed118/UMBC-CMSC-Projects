/************************                                                      
* File: Imp.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Imp file for Zombie/Entity class for project 4.     
**************************/
#include "Imp.h"
#include "Zombie.h"
#include "Entity.h"
#include "Game.h"
#include <iostream>
using namespace std;

//default contructor
//precondtions: none 
//postconditions: can create imp  
//Imp::Imp(){}

//overloaded constructor
//precondtions: none
//postconditions: can create imp  
Imp::Imp(string name, int health)
  :Zombie(name, health){
}

//SpecialAttack() - defines Imp special attack
//precondtions: none
//postconditions: returns damage from special attack  
int Imp::SpecialAttack(){
  cout << GetName() << " blasts you with their Impkata attack!" << endl;
  return 4;
}
