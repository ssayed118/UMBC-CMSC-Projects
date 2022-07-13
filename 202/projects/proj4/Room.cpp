/************************                                                     
* File: Room.cpp                                                             
* Project: CMSC202, Project 4, Fall 2020                                      
* Author: Sumaa Sayed                                                         
* Date: 11/2/2020                                                             
* Section: 20/25                                                              
* Email: ssayed1@umbc.edu                                      
* Description: Room file for project 4.  
**************************/
#include "Room.h"

//constructor
//precondtions: need valid input for each part of room
//postcondtions: creates a new room
Room::Room(int ID, string name, string desc, int north, int east, int south, int west){
  m_ID = ID; //room ID number
  m_name = name; //room name
  m_desc = desc; //room's description
  m_direction[0] = north; //directions to leave room
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west; 
}

//GetName() - gets name of room
//preconditons: must be a valid room
//postconditons: returns room name as string
string Room::GetName(){
  return m_name;
}

//GetID() - gets ID of room
//preconditons: must be a valid room                                          
//postconditons: returns room ID as int 
int Room::GetID(){
  return m_ID;
}

//GetDesc() - gets desc of room
//preconditons: must be a valid room                                          
//postconditons: returns room description as string 
string Room::GetDesc(){
  return m_desc;
}

//CheckDirection() - gets direction for room
//preconditons: must be a valid room
//postconditions: returns room id, if it exists
int Room::CheckDirection(char myDirection){
  if(myDirection == 'n'){
    return m_direction[0]; 
  }
  if(myDirection == 'e'){
    return m_direction[1];
  }
  if(myDirection == 's'){
    return m_direction[2];
  }
  if(myDirection == 'w'){
    return m_direction[3];
  }
  return 0;
}

//PrintRoom() - prints room details
//precondtions: room msut be complete
//postconditons:  outputs rooms name, desc, and possible exits
void Room::PrintRoom(){
  cout << m_name << endl;
  cout << m_desc << endl;
  cout << "Possible exits: " << endl;

  for(int i = 0; i < 4; i ++){
    if(m_direction[i] != -1){
      if(i == 0){
	cout << "N" << endl;
      }
      if(i == 1){
	cout << "E" << endl;
      }
      if(i == 2){
        cout << "S" << endl;
      }
      if(i == 3){
        cout << "W" << endl;
      }
    }
  }
}
