/******************************************                                    
** File: Media.cpp                              
** Project: CMSC202 Project 5, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 11/20/2020                                                            
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: This is the Media class file for project 5.
*********************************************/
#include "Media.h"

//Default Constructor for Media                                          
//Precondition: None                                                         
//Postcondition: Creates a default media    
Media::Media(){ 
  m_title = " ";
  m_artist = " ";
  m_type = " ";
  m_year = 0;
  m_rank = 0;
}

//Overloaded Constructor for Media
//Precondition: Requires title, artist, type, year and rank                   
//Postcondition: Creates a media entry based on passed parameters      
Media::Media(string title, string artist, string type, int year, int rank){
  m_title = title; //title of media
  m_artist = artist; //artist of media
  m_type = type; //type of media
  m_year = year; //year of media
  m_rank = rank; //rank of media
}

//Name: Mutators and Accessors                                                
//Precondition: None                                                         
//Postcondition: Sets and Gets private member variables

//GetTitle, returns title of media
string Media::GetTitle()const{ 
  return m_title;
}

//GetArtist, returns name of artist
string Media::GetArtist()const{
  return m_artist;
}

//GetTpe, returns type of media
string Media::GetType()const{ 
  return m_type;
}

//GetYear, returns year of media
int Media::GetYear()const{ 
  return m_year;
}

//GetRank, returns rank of media
int Media::GetRank()const{
  return m_rank;
}

//SetTile, sets title of media
void Media::SetTitle(string title){
   m_title = title;
}

//SetARtist, sets artist of media
void Media::SetArtist(string artist){
  m_artist = artist;
}

//SetType, sets type of media
void Media::SetType(string type){
  m_type = type;
}

//SetYear, sets year of media
void Media::SetYear(int year){
  m_year = year;
}

//SetRank, sets rank of media
void Media::SetRank(int rank){
  m_rank = rank;
}

//Overloaded << operator                                                
//Precondition: media available                                              
//Postcondition: Returns output stream including title by artist from year   
ostream& operator<<(ostream& out, Media& m){
  //setting variables to get title, artist and year of media
  out << m.GetTitle() << endl;
  out << m.GetArtist() << endl;
  out << m.GetYear() << endl;
  return out;
}

//Overloaded Relational Operator (<) 
//Precondition: Two media objects required                                    
//Postcondition: if passed media's year is less than first, return true else false   
bool Media::operator<(const Media& m){
  if(m_year < m.m_year){ //checking that the year is less that first
    return true;
  }else{
    return false;
  }
}
