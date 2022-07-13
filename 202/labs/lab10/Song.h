/**************                                                                
* File: Song.h                                                              
* Project: CMSC 202 Lab 10, Fall 2020                                          
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                             
* Section: 20/25                                                               
* E-mail: ssayed1@gl.umbc.edu                                                  
* Header file for polymorphsim lab.
 *************/

#ifndef SONG_H
#define SONG_H
#include <iostream>
using namespace std;

//song class
class Song{
public:
  //Name: Song() - default constructor
  //Description: creates a new song
  //Preconditions: none
  //Postconditons: sets strings
  Song();
  //Name: Song() - overloaded constructor                                      
  //Description: creates a new song                                            
  //Preconditions: none                                                        
  //Postconditons: sets strings as items/params from lab10.cpp file
  Song(string, string); //artist + name 
  //Name: Play()                                         
  //Description: tells user to play a song                                     
  //Preconditions: none (song exists?)                                        
  //Postconditons: "plays" song
  virtual void Play();
  //Name: Request()
  //Description: tells user to request a song
  //Preconditons: none (song exists?)
  //Postcodnitons: "requests" song
  virtual void Request();
  //Name: Like()              
  //Description: tells user to like a song                                  
  //Preconditons: none (song exists?)               
  //Postcodnitons: "likes" song
  virtual void Like(); 
  
 protected:
  string m_songName; //name of song
  string m_artistName; //name of artist
};

//hiphop class
class Hiphop : public Song{
public:
  //Name: Hiphop(string, string) - overloaded constructor    
  //Description: creates a new hiphop song                
  //Preconditions: none                                                        
  //Postconditons: sets strings as items/params from lab10.cpp file 
  Hiphop(string songName, string artistName);
  void Play(); //see above comments for functions
  void Request();
  void Like();
};

//pop class
class Pop : public Song{
public:
  //Name: Pop(string, string) - overloaded constructor      
  //Description: creates a new pop song                              
  //Preconditions: none                                                        
  //Postconditons: sets strings as items/params from lab10.cpp file 
  Pop(string songName, string artistName);  
  void Play(); //see above comments
  void Request();
  void Like();
};
  
#endif
