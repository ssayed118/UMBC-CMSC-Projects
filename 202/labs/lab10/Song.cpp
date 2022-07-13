/**************                                                                
* File: Song.cpp                                                              
* Project: CMSC 202 Lab 10, Fall 2020  
* Author: Sumaa Sayed                                                          
* Date: 11/2/2020                                                           
* Section: 20/25                                                               
* E-mail: ssayed1@gl.umbc.edu                                                  
* Main file for the Song class for polymorphism lab.
 *************/

#include <iostream>
#include "Song.h"
using namespace std;

//pre and post condtions are all in song.h file!!
//song constructor
Song::Song(string songName, string artistName){
  m_artistName = artistName; //initializing varables
  m_songName = songName;
}

//play, like, and request functions for song
void Song::Play(){
  cout << "Listen I got just what you need, brand new " << m_artistName << " , this is " << m_songName << endl;
}
void Song::Like(){
  cout << "I knew you'd like that, we're adding " << m_songName << " by " << m_artistName << " to your liked songs list." << endl;
}

void Song::Request(){
  cout << "We got a request from someone to play " << m_songName << " by " << m_artistName << endl;
}

//hiphop constructor
Hiphop::Hiphop(string songName, string artistName)
  : Song(songName, artistName){ //getting variables from song
}

//play, like, and request functions for hiphop
void Hiphop::Request(){
  cout << "We got a caller on line one asking for some more hip-hop." << endl;
}
void Hiphop::Play(){
  cout << "We love rap music, here's another one from " << m_artistName << " , " << m_songName << endl;
}
 void Hiphop::Like(){
   cout << "I knew you'd like that, we're adding " << m_songName << " by " << m_artistName << " to your liked songs list." << endl;
}

//pop constructor
Pop::Pop(string songName, string artistName)
  : Song(songName, artistName){ //getting variables from song
}

//play, like, and request functions for pop
void Pop::Request(){
  cout << "We got a caller in the building requesting some pop music this time." << endl;
}
void Pop::Play(){
  cout << "We love pop music too, coming up we got " << m_songName << " by " << m_artistName << " . " << endl;
}
void Pop::Like(){
   cout << "I knew you'd like that, we're adding " << m_songName << " by " << m_artistName << " to your liked songs list." << endl;
}
