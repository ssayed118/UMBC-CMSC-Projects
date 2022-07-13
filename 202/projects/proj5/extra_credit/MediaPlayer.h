/******************************************                                    
** File: MediaPlayer.h                                                       
** Project: CMSC202 Project 5, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 11/20/2020                                                            
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: This is the MediaPlayer headrer file for project 5.
** (I only modified a few things at the bottom for the extra credit)       
*********************************************/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Media.h"
#include "Tqueue.cpp"

using namespace std;
#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

const int MIN_YEAR = 1958;
const int MAX_YEAR = 2020;
const int MAX_LISTS = 10;

class MediaPlayer{
 public:
  //Name: MediaPlayer - Default Constructor
  //Precondition: None
  //Postcondition: Creates a new MediaPlayer
  MediaPlayer();
  //Name: MediaPlayer - Overloaded Constructor
  //Precondition: None
  //Postcondition: Creates a new MediaPlayer and passes the media filename
  MediaPlayer(string filename);
  //Name: ~MediaPlayer - Destructor
  //Precondition: None
  //Postcondition: Creates a new MediaPlayer
  ~MediaPlayer();
  //Name: LoadCatalog(string filename)
  //Precondition: Requires filename
  //Postcondition: Loads the file into the m_mediaCatalog (as media)
  void LoadCatalog(string filename);
  //Name: MainMenu
  //Precondition: None
  //Postcondition: Manages the application and the menu
  void MainMenu();
  //Name: DisplayMedia
  //Precondition: User enters year (1958-2020)
  //              (shows all years even if no media of that type exists for a particular year)
  //Postcondition: Lists all media (numbered) for that year and returns int
  //               of number found with that criteria
  int DisplayMedia();
  //Name: AddMedia
  //Precondition: m_mediaCatalog is populated
  //Postcondition: Displays the current list and adds media
  //               to the m_playList
  void AddMedia();
  //Name: DisplayPlaylist
  //Precondition: None (will indicate if list is empty)
  //Postcondition: Displays the playlist
  void DisplayPlaylist();
  //Name: SortPlaylist
  //Precondition: None (will indicate if list is empty)
  //Postcondition: Sorts the playlist by year
  void SortPlaylist();
  //Name: Import
  //Preconditon: File for playlist must exist
  //Postcondition: Saves the playlist in m_playLists
  void Import();
  //Name: Export();
  //Preconditon: Playlist must exits
  //Postcondtion: Saves playlist as text file
  void Export();
private:
  vector<Media*> m_mediaCatalog; //Holds all media in file
  Tqueue<Tqueue<Media*, 3000>, MAX_LISTS> m_playlists; //2d vector for playlists
};


#endif
