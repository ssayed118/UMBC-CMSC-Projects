/************************                                                      
** File: Valorant.cpp                                                          
** Project: CMSC202 Lab 6, Fall 2020                                           
** Author: Sumaa Sayed                                                         
** Date: 10/7/20                                                               
** Section: 20/25                                                              
** Email: ssayed1@gl.umbc.edu

This file contains the setters, getters, and constructors for lab6.cpp.        
***********************/

#include <iostream>
#include <string>
#include "Valorant.h" 

using namespace std;

Valorant::Valorant(){
  m_name = " ";
  m_HP = 0;
  m_isDefender = true;
}

Valorant::Valorant(string setName, int setHP, bool setSide){
  SetName(setName);
  SetHP(setHP);
  SetSide(setSide);
}

//setter for name
void Valorant::SetName(string toSet){
  m_name = toSet;
}

//setter for HP
void Valorant::SetHP(int hp){
  m_HP = hp;
}

//setter for side
void Valorant::SetSide(bool toSet){
  m_isDefender = toSet;
}

//getter for name
string Valorant::GetName(){
  return m_name;
}

//getter for HP
int Valorant::GetHP(){
  return m_HP;
}

//getter for side
bool Valorant::GetSide(){
  return m_isDefender;
}
