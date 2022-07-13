/******************************************
** File: Pirate.cpp
** Project: CMSC202 Project 2, Fall 2020
** Author: Sumaa Sayed
** Date: 10/4/2020
** Section 20/25
** Email: ssayed1@gl.umbc.edu
** Description: This is the file to set/get the variables and has some of the 
** more important functions for the Pirates project.
***********************************************/
#include "Ship.h"
#include "Pirate.h"
#include <iostream>
using namespace std;

//contructors
Pirate::Pirate(){
  m_pirateName = " "; 
  m_pirateRating = 0; 
  m_pirateOrigin = " ";
  m_pirateDesc = " ";
  m_pirateCargo = 0; 
  m_pirateDays = 0; 
}

Pirate::Pirate(string name, int rating, string origin, string desc){
  m_pirateName = name;
  m_pirateRating = rating;
  m_pirateOrigin = origin;
  m_pirateDesc = desc;
}

//getters and setters for name, rating, origin, description, amd ship
string Pirate::GetName(){
  return m_pirateName;
}

int Pirate::GetRating(){
  return m_pirateRating;
}

void Pirate::SetRating(int rating){
  m_pirateRating = rating;
}

string Pirate::GetOrigin(){
  return m_pirateOrigin;
}

string Pirate::GetDesc(){
  return m_pirateDesc;
}

void Pirate::SetCurShip(Ship curShip){
  m_curShip = curShip;
}

// Preconditions - Pirate exists and battle has concluded                     
// Postconditions - Updates total carg
void Pirate::CalcTreasure(Ship enemyShip){
  int num = 0;
  int treasure = 0;
  
  num = (enemyShip.m_cannon + enemyShip.m_toughness + enemyShip.m_speed);
  treasure = (num / 3);
  m_pirateCargo = m_pirateCargo + treasure; //is that right?
}

// Preconditions - Enemy pirate found                                         
// Postconditions - Either user pirate wins or enemy pirate wins
void Pirate::Battle(Pirate enemyPirate, Ship enemyShip){
  int hitCount = 0; //counter for hits
  int enemyHitCount = 0; //counter for enemy hits
  int random; //randomizer for regular pirate (to get if they hit or miss)
  int random1; //random for enemy pirate (to get if they hit or miss)

  //cannot start the battle until curToughness is greater than 0
  if(m_curShip.m_curToughness == 0){
    RepairShip();
  }

  //actual battle here:
  else{
    cout << "A naval battle of the ages commences between " << m_pirateName << " and " << enemyPirate.GetName() << endl;

  //as long as either of the tougness' are greater than 1, battle will continue
    while(m_curShip.m_curToughness > 1 && enemyShip.m_curToughness > 1){    
      cout << m_pirateName << " fires " << m_curShip.m_cannon << " cannons!" << endl;
      random = rand() % (100);
 //if rand() gives a number that satisfies the below condition then pirate hits
      if (random >= (100 - m_pirateRating)){
	hitCount ++;
	cout << hitCount << " shots hit! " << endl;
	enemyShip.m_curToughness -= hitCount;

     //otherwise it doesn't hit
      }else{
	cout << "0  shots hit! " << endl;
      }

      //same comments as above block of code (line after while statement)
      cout << enemyPirate.GetName() << " fires " << enemyShip.m_cannon << " back!" << endl;
      random1 = rand() % (100);
      if(random1 >= (100 - enemyPirate.GetRating())){
	  enemyHitCount ++;
	  cout << enemyHitCount << " shots hit! " << endl;
	  m_curShip.m_curToughness -= enemyHitCount;
	}else{
	  cout << "0  shots hit! " << endl;
	}
    }
    m_pirateDays ++;
  }
  //if enemypirate wins:
  if (m_curShip.m_curToughness < 1){
    m_pirateCargo /= 2;
    cout << "You lose!" << endl;
    if (m_curShip.m_curToughness < 0){
      m_curShip.m_curToughness = 0;
      cout << "Repairing ship." << endl;
      RepairShip();
    }
  }
  //if user pirate wins
  else if(enemyShip.m_curToughness < 1){
    cout << "You win!" << endl;
    CalcTreasure(enemyShip);
  }
}

// Preconditions - Ship damaged                                               
// Postconditions - Repairs ship and increases days (1 day per point of damage)
void Pirate::RepairShip(){
  int var = m_curShip.m_toughness - m_curShip.m_curToughness;
  //variable to hold the value for toughness - curToughness
  
  cout << "It takes " << var << " days to repair your ship" << endl;
  m_pirateDays += var;
  m_curShip.m_curToughness = m_curShip.m_toughness;
  //at the end, curToughness should be the same as max toughness
}

void Pirate::Flee(Pirate enemyPirate, Ship enemyShip){
  //if your speed is faster, then there is a successful flee
  if(m_curShip.m_speed > enemyShip.m_speed){
    cout << "You attempt to flee from" << enemyPirate.m_pirateName << " !"<< endl;
    cout << "You narrowly escape from" << enemyPirate.m_pirateName << endl;
    m_pirateDays ++;
  }

  //if speed is slower, then battle
  else{
    m_pirateDays ++;
    Battle(enemyPirate, enemyShip);
  }
}

// Preconditions - Pirate exists
// Postconditions - Displays name, rating, origin, desc, cargo, days,
//cargo/days, and info about m_curShip  
void Pirate::DisplayScore(){
  cout << "**************************" << endl;
  cout << "Name: " << m_pirateName << endl;
  cout << "Rating: " << m_pirateRating << endl;
  cout << "Country of Origin: " << m_pirateOrigin << endl;
  cout << "Description: " << m_pirateDesc << endl;
  cout << "Days Sailing: " << m_pirateDays << endl;
  cout << "Cargo Captured: " << m_pirateCargo << endl;

 //i was getting a floating point error for this so had to use an if-else block
  if (m_pirateCargo > 0){
    cout << "Cargo Per Day: " << double(m_pirateCargo/m_pirateDays) << endl;
  } else{
    cout << "Cargo Per Day: 0" << endl;
  }
  cout << "Ship Type: "<< m_curShip.m_type <<  endl;
  cout << "Ship Cannons: " << m_curShip.m_cannon << endl;
  cout << "Ship Current Toughness: " << m_curShip.m_curToughness << endl;
  cout << "Ship Max Toughness: " << m_curShip.m_toughness << endl;
  cout << "Ship Speed: " << m_curShip.m_speed << endl;
  cout << "**************************" << endl;
}
