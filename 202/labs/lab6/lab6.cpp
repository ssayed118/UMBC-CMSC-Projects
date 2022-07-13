/************************
** File: lab6.cpp
** Project: CMSC202 Lab 6, Fall 2020
** Author: Sumaa Sayed
** Date: 10/7/20
** Section: 20/25
** Email: ssayed1@gl.umbc.edu

** This file contains the main program for Lab 6. It asks for the amount of    ** charcaters wanted for a Valorant game, along with the HP and defender status**. Also, it allows practice with vectors.
*************************/

#include <iostream>
#include <string>
#include <vector>
#include "Valorant.h"
using namespace std;

//fillVector prototype here:
void fillVector(vector<Valorant> &list);
//Desc: Prompts the user with the number of characters they want to enter and adds each character to the vector
//Pre-condition: Accepts a vector
//Post-condition: Updates the vector passed to it

//printVector
void printVector(vector<Valorant> &list);
//Desc: Prints the contents of the vector (without using an iterator)
//Pre-condition: Accepts a vector (but don't make a copy of it)
//Post-condition: Displays information about the characters in the vector


int main(){
  //Vector that stores the user input
  vector<Valorant> list;

  //fills the vector
  fillVector(list);
  
  //prints the vector
  printVector(list);

  return 0;
}

//Insert fillVector here - we want to change the vector permanently!
void fillVector(vector<Valorant> &list){
  int numChar = 0; //number of characters
  int setHP = 0; //amount of HP
  string setName = " "; //name
  bool isDefender;  // defender status
  int counter = 1; //counter so i is always 1 more than the value (starts at 0)

  cout << "How many Valorant characters? " << endl;
  cin >> numChar;
  while(numChar > 10){
    cout << "How many Valorant characters? " << endl;
    cin >> numChar;
  }
  
  for(int i = 0; i < numChar; i ++){
    Valorant val; //this will clear each time, so the info gets stored in the next spot

    //asking for character, HP, and defender status
    cout << "Character " << (i + counter) << " name: " << endl;
    cin >> setName;
    val.SetName(setName);
    
    cout << "Character " << (i + counter) << " HP: " << endl;
    cin >> setHP;
    val.SetHP(setHP);
    
    cout << "Is character " << (i + counter)<< " a defender? (0 or 1)" << endl;
    cin >> isDefender;
    val.SetSide(isDefender);

    //adding to the vector
    list.push_back(val);
  }
}

//Insert printVector - we do not want to make a copy of the vector
void printVector(vector<Valorant> &list){
  cout << "Character list using unsigned int: " << endl;

  //printing out each part of the object
  for(unsigned int i = 0; i < list.size(); i ++){
    cout << list[i].GetName() << " is on team " << list[i].GetSide() << " and has " << list[i].GetHP() << " HP" << endl;
  }
}
