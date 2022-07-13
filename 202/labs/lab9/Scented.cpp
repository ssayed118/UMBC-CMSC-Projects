/**************                                                                
* File: Scented.cpp                                                            
* Project: CMSC 202 Lab 9, Fall 2020                                           
* Author: Sumaa Sayed                                                          
* Date: 10/2720                                                                
* Section: 20/25                                                               
* E-mail: ssayed1@gl.umbc.edu                                                  
* Header file for inheritance lab, this lab will allow practice with inheriance
* classes, objects, and overloaded operators.                                  
 *************/

#include "Scented.h"
#include <iostream>                                                          
using namespace std;          

//constructor for scented
Scented::Scented(string name, double burnRate, string flavor)
  : Candle(name, burnRate){
  m_flavor = flavor;
}

//pre condition: candle exists
//post condition: set the flavor for candle
void Scented::SetFlavor(string flavor){
  m_flavor = flavor;
}

//pre condition: candle with flavor exists
//post conditon: obtaining flavor of candle
string Scented::GetFlavor(){
  return m_flavor;
}

//pre condition: candle exists
//post conditon: to set whether its lit or not
string Scented::SetLit(bool isLit){
  cout << "The delicious smell of " << m_flavor << " wafts from the scented candle." << endl;
  return "Yes";

  return "No";
}

//pre condition: candle exists with isLit variable
//post conditon: obtaining status of candle being lit or not
string Scented::GetLit(){
  if(m_isLit == true){
    return "No";
  }
  return "Yes";
}
