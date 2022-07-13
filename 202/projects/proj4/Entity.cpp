/************************                                                      
* File: Entity.cpp                                                         
* Project: CMSC202, Project 4, Fall 2020                                       
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                              
* Section: 20/25                                                               
* Email: ssayed1@umbc.edu                                                      
* Description: Entity file for project 4.     
**************************/

#include "Entity.h"
#include <iostream>
using namespace std;

//default constructor
//preconditons: none
//postconditons: populates variables used in child classes
Entity::Entity(){
  m_name = " ";
  m_health = 0;
}

//overloaded constructor
//precondtions: none
//postconditions: populates variables in child classes
Entity::Entity(string name, int health){
  m_name = name;
  m_health = health;
}

//destructor
//precondtions: none
//postconditions: dynamically allocated things are deallocated  
Entity::~Entity(){
} 

//GetName() - returns name 
//precondtions: entity has a name  
//postconditions: none
string Entity::GetName(){
  return m_name;
}

//GetHealth() - returns health
//precondtions: entity has health
//postconditions: none
int Entity::GetHealth(){
  return m_health;
}

//SetName(string name) - sets entity's name
//precondtions: none
//postconditions: name is set  
void Entity::SetName(string name){
  m_name = name;
}

//SetHealth(int health) - sets entity's health
//precondtions: none
//postconditions: health is set
void Entity::SetHealth(int health){
  m_health = health;
}

//Attack() - attack for entity
//precondtions: none 
//postconditions: none     
int Entity::Attack(){
  cout << "Entity has an attack damage of 0" << endl;
  return 0;
}

//SpecialAttack() - special attack for entity
//precondtions: none
//postconditions: none  
int Entity::SpecialAttack(){
  cout << "Entity has an special attack damage of 0" << endl;
  return 0;
}

//Overloaded << - prints details of entity
//precondtions: all variables are valid
//postconditions: returns ostream w/ output of entity
ostream& operator<<(ostream& out, Entity& creature){
  out << creature.m_name << endl;
  out << creature.m_health << endl;
  return out;
}
