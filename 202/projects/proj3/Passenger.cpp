/******************************************                                    
** File: Passenger.cpp                                                         
** Project: CMSC202 Project 3, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 10/18/2020                                                            
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: This is the file to get the variables needed for the Passenger
** class.     
***********************************************/
#include "Passenger.h"
#include <iostream>
using namespace std;

Passenger::Passenger(string name, int age, string start, string finalDes){
  m_fullName = name;
  m_age = age;
  m_startLocation = start;
  m_finalDestination = finalDes;
}

//getter for passenegr name
string Passenger::GetName(){
  return m_fullName;
}

//getter for passenegrs start location
string Passenger::GetStartLocation(){
  return m_startLocation;
}

//getter for passenegrs final destination
string Passenger::GetFinalDestination(){
  return m_finalDestination;
}
