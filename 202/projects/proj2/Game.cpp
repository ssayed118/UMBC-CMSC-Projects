/******************************************                                    
** File: Game.cpp                                                            
** Project: CMSC202 Project 2, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 10/4/2020                                                             
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: This file is basically the main part of this game for the 
** Pirates project.                             
***********************************************/
#include <fstream>
#include <iostream>
#include "Ship.h"
#include "Pirate.h"
#include "Game.h"
using namespace std;

//contructor
Game::Game(){
  GameTitle();
  LoadShips();
  LoadPirates(); 
}

// Preconditions - Requires file with valid ship data                         
// Postconditions - m_ships is populated with ship structs  
void Game::LoadShips(){
  fstream myFile;
  myFile.open("proj2_ships.txt");
  int count = 0; //counter to make sure 15 ships are loaded
  string type; //variables to build the ship type
  string cannons; // number of cannons
  string toughness; //amount of toughness
  string speed; //lightning mcqueen
  string desc; //description of ship

  int cannonNum; //getline gets strings so casting ints for cannon
  int toughNum; //int for toughness
  int speedNum; //int for speed
    
  if (myFile.is_open()){ //checking that the file actually opens

    //looping through the file and grabbing each item
    while (getline(myFile, type, ',' )) {
      getline(myFile, cannons, ',');
      getline(myFile, toughness, ',');
      getline(myFile, speed, ',');
      getline(myFile, desc, '\n');

      //setting int variables to the stoi ones
      cannonNum = stoi(cannons);
      toughNum = stoi(toughness);
      speedNum = stoi(speed);
      
      // cannonNum = stoi(cannons) just in case you get issuesV
      //building the ship + setting to the proper index
      Ship newShip(type, cannonNum, toughNum, speedNum, desc);
      m_ships[count] = newShip;
      count++; 
    }
  }
  myFile.close();
  cout << count << " ships loaded." << endl;
}

// Preconditions - Requires file with valid pirate data                       
// Postconditions - m_allPirates is populated with pirate objects  
void Game::LoadPirates(){
  fstream myFile;
  myFile.open("proj2_pirates.txt");
  int count = 0; //counter to make sure we get 352 pirates
  string name; //name for pirate
  string rating; //pirate rating
  string origin; //origin of pirate
  string desc; //pirate description
  int ratingNum; //casting rating as int

  //same comments as previous function
  if (myFile.is_open()){
    while (getline(myFile, name, ',')) {
      getline(myFile, rating, ',');
      getline(myFile, origin, ',');
      getline(myFile, desc, '\n');

      ratingNum = stoi(rating);

      m_myPirate = Pirate(name, ratingNum, origin, desc);
      m_allPirates[count] = m_myPirate;
      count++;
    }
  }
  myFile.close();
  cout << count << " pirates loaded." << endl;
}

// Preconditions - Player (Pirate) is placed in game                          
// Postconditions - Continually checks to see if player has entered 4 (retires)
void Game::StartGame(){
  int userChoice = 0; //var to gret user input
  int random; //var to grab pirate
  int random1; //var to grab ship for pirate

  //using rand to get pirate + ship
  random = rand()  % (MAX_PIRATES);
  m_myPirate = m_allPirates[random];
  
  random1 = rand() & (MAX_SHIPS);
  Ship myShip = m_ships[random1];
  m_myPirate.SetCurShip(m_ships[random1]);
  
  cout << "Congratulations! "<< m_myPirate.GetName() << " is now available to plunder!" << endl;
  cout << m_myPirate.GetName() << " is aboard " << myShip.m_type << endl;

  //getting user input for menu until they enter 4
    userChoice = MainMenu();
    while(userChoice != 4){
      if (userChoice == 1){
	SearchTreasure();
	userChoice = MainMenu();
      }
      if (userChoice == 2){
	m_myPirate.RepairShip();
	userChoice = MainMenu();
      }
      if (userChoice == 3){
	m_myPirate.DisplayScore();
	userChoice = MainMenu();
      }
    }
    
    //if user enters 4
    m_myPirate.DisplayScore();
    cout << m_myPirate.GetName() << " sails off into retirement!" << endl;
    cout << "Thanks for playing Pirates!" << endl;
}

// Preconditions - Player has a Pirate                                        
// Postconditions - Returns number including exit
int Game::MainMenu(){
  int choice = 0; //var for getting user input
  cout << "What would you like to do?" << endl;
  cout << "1. Search for Treasure" << endl;
  cout << "2. Repair Ship" << endl;
  cout << "3. See Score" << endl;
  cout << "4. Retire" << endl;
  cin >> choice;

  //validating that the user enter a numbder between 1 and 4
  while(choice != 1 && choice != 2 && choice != 3 && choice != 4){
    cout << "Enter your choice (1-4): " << endl;
    cin >> choice;
  }
  return choice;
}

// Preconditions - Pirates loaded                                             
// Postconditions - Identifies enemy pirate to fight  
void Game::SearchTreasure(){
  int choice = 0; //var for getting user choice
  int random; //var to grab enemy pirate
  int random1; //var to grab enemy ship

  //using rand to set enemy pirate + ship
  random = rand()  % (MAX_PIRATES);
  Pirate m_enemyPirate = m_allPirates[random];

  random1 = rand() & (MAX_SHIPS);
  Ship enemyShip = m_ships[random1];

  cout << "You scan the horizon for prospective targets..." << endl;
  cout << "Off in the distance, you see " << m_enemyPirate.GetName() << " on a " << enemyShip.m_type << endl;
  cout << "What would you like to do?" << endl;
  cout << "1. Attack " << m_enemyPirate.GetName() << endl;
  cout << "2. Attempt to flee from " << m_enemyPirate.GetName() << endl;
  cin >> choice;

  //validating user choice 
  while(choice != 1 && choice != 2){
    cout << "Enter your choice (1 or 2): " << endl;;
    cin >> choice;
  }

  //calling the appropriate functions
  if(choice == 1){
    m_myPirate.Battle(m_enemyPirate, enemyShip);
  } 
  else if(choice == 2){
    m_myPirate.Flee(m_enemyPirate, enemyShip);
  }
}

// Preconditions - Pirate has ship for battle                                 
// Postconditions - Returns integer of chosen ship for battle 
void Game::RequestShip(int &choice){
  //no code goes in here
}

//no pre/post conditions
//void Game::GameTitle(){
  //no code goes in here
//}
