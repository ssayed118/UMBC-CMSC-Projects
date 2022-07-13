/************************                                                      
* File: Zombie.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Zombie file for Entity class for project 4.     
**************************/

#include "Zombie.h"
#include "Entity.h"
#include <iostream>
using namespace std;

//constructor
//precondtions: none
//postconditions: populate child class data
Zombie::Zombie(string name, int health)
 :Entity(name, health){
}

//Attack()
//precondtions: none
//postcondtions: returns damage
int Zombie::Attack(){
  cout << GetName() << " deals 1 point of damage" << endl;
  return 1;
}

//SpecialAttack()
//preconditons: none
//postcondions: used to call child class SpecialAttack
int Zombie::SpecialAttack(){
  cout << GetName() << " performs a special attack." << endl;
  return 0;
}
