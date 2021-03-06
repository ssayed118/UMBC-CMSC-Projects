/************************
* File: Buckethead.cpp
* Project: CMSC202, Project 4, Fall 2020
* Author: Sumaa Sayed
* Date: 11/2/2020
* Section: 20/25
* Email: ssayed1@umbc.edu
* Description: Buckethead file for Zombie/Entity class for project 4.
************************/

#include "Buckethead.h"
#include "Game.h"
#include "Zombie.h"
#include <iostream>
using namespace std;

//deafult constructor
//preconditions: none
//postconditions: can create a buckethead
//Buckethead::Buckethead(){}

//overloaded constructor
//preconditons: none
//postconditons: can create a buckethead
Buckethead::Buckethead(string name, int health)
:Zombie(name, health){
}

//SpecialAttack()
//precondtions: none
//postconditons: returns damage from special attack
int Buckethead::SpecialAttack(){
  cout << GetName() << " throws its bucket at you!" << endl;
  return 1;
}
