/**************                                                                
* File: Scented.h                                                              
* Project: CMSC 202 Lab 9, Fall 2020                                           
* Author: Sumaa Sayed                                                          
* Date: 10/2720                                                                
* Section: 20/25                                                               
* E-mail: ssayed1@gl.umbc.edu                                                  
* Header file for inheritance lab, this lab will allow practice with inheriance* classes, objects, and overloaded operators.                    
 *************/

#ifndef SCENTED_H
#define SCENTED_H
#include "Candle.h"

//declaring the Scented class as part of Candle
class Scented : public Candle{
 public:
  Scented(string name, double burnRate, string flavor);


 //function prototypes for functions for setters + getters used in Scented.cpp 
  string SetLit(bool isLit); //set the status for candle
  void SetFlavor(string flavor); //set flavor for candle
  string GetFlavor(); //get flavor for candle
  string GetLit(); //get status for candle
  
 protected:
  string m_flavor; //variable for flavor 
};

#endif


  
