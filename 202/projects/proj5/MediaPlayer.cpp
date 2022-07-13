/******************************************                                    
** File: MediaPlayer.cpp  
** Project: CMSC202 Project 5, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 11/20/2020                                                            
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: This is the MediaPlayer file for project 5.              
*********************************************/
#include "MediaPlayer.h"

//Default Constructor for MediaPlayer
//Precondition: None                                                          
//Postcondition: Creates a new MediaPlayer        
MediaPlayer::MediaPlayer(){
  string filename; //setting filenamde for LoadCatalog
}

//Overloaded Constructor for MediaPlayer
//Precondition: None                                                          
//Postcondition: Creates a new MediaPlayer and passes the media filename 
MediaPlayer::MediaPlayer(string filename){
  LoadCatalog(filename); //calling load to start the MediaPlayer
}

//Name: ~MediaPlayer - Destructor                                             
//Precondition: None                                                         
//Postcondition: Deallocates mediaCatalog objects
MediaPlayer::~MediaPlayer(){
  for(unsigned int i = 0; i < m_mediaCatalog.size(); i++){
    delete m_mediaCatalog[i];
  }
}

//Name: LoadCatalog(string filename)                                          
//Precondition: Requires filename                                            
//Postcondition: Loads the file into the m_mediaCatalog (as media)    
void MediaPlayer::LoadCatalog(string filename){
  fstream myFile; 
  string title, artist, type, year, rank; //variables to hold each aspect of the media object
  int year1, rank1; //variables to conveert the strings to ints
  int counter = 0; //counter to make sure 6000 objects are made/loaded
  Media *media; //used to create new Media object
  
  myFile.open(filename); //opening file + grabbing each piece of the object
  if(myFile.is_open()){
    while(getline(myFile, title, ';')){
	getline(myFile, artist, ';');
	getline(myFile, type, ';');
	getline(myFile, year, ';');
	getline(myFile, rank, '\n');

	year1 = stoi(year); //converting to ints
	rank1 = stoi(rank);

	//creating new media object, adding to mediaCatalog and +1 for counter
	media = new Media(title, artist, type, year1, rank1); 
	counter ++;
	m_mediaCatalog.push_back(media);
    }
  }
  //closing file
  cout << counter << " media files loaded." << endl;
  myFile.close();
}

//Name: MainMenu                                                              
//Precondition: None                                                         
//Postcondition: Manages the application and the menu     
void MediaPlayer::MainMenu(){
  int option = 0; //holds user input
  while(option != 5){
    cout << "What would you like to do?" << endl;
    cout << "1. Display Media by Type and Year" << endl;
    cout << "2. Add Media to Playlist" << endl;
    cout << "3. Display Playlist" << endl;
    cout << "4. Sort Playlist by Year" << endl;
    cout << "5. Quit" << endl;
    cin >> option;

    //for each option, calling the corresponding function to run the program
    while(option < 1 && option > 5){
      cout << "What would you like to do?" << endl;
      cin >> option;
    }
    
    if(option == 1){
      DisplayMedia();
    }
    
    if(option == 2){
      DisplayPlaylist();
      AddMedia();
    }
    
    if(option == 3){
      DisplayPlaylist();
    }
    
    if(option == 4){
      SortPlaylist();
    }
  }
  cout << "Thank you for using the UMBC Media Player!" << endl;
}

//Name: DisplayMedia                                                          
//Precondition: User enters year (1958-2020)                                  
//(shows all years even if no media of that type exists for a particular year) 
//Postcondition: Lists all media (numbered) for that year and returns int of
//number found with that criteria        
int MediaPlayer::DisplayMedia(){
  int year = 0; //holds user input for what year of media they choose
  int count = 0; //counter for number of media
  string media; //holds user input for type of media
  
  cout << "Which media type do you want to display? (podcast or music)" << endl;
  cin >> media;

  //validating that the user puts in music or podcast
  while((media != "music") && (media != "podcast")){
    cout << "Which media type do you want to display?" << endl;
    cin >> media;
  }
  
  cout << "Which year would you like to display? (1958-2020)" << endl;
  cin >> year;

  //validation for year
  while(year < MIN_YEAR or year > MAX_YEAR){
    cout << "Which year would you like to display? (1958-2020)" << endl;
    cin >> year;
  }
  
  //printing out the media for year and type 
  cout << "******" << year << "******" << endl;
  for(unsigned int i = 0; i < m_mediaCatalog.size(); i++){
    if(m_mediaCatalog[i]->GetYear() == year && m_mediaCatalog[i]->GetType() == media){
      cout << (i + 1) << ". " << m_mediaCatalog[i]->GetTitle() << " by " << m_mediaCatalog[i]->GetArtist() << endl;
      count ++;
    }
  }
  cout << count << " media found." << endl;
  return count;
} 

//Name: AddMedia                                                              
//Precondition: m_mediaCatalog is populated                                  
//Postcondition: Displays the current list and adds media to the m_playList    
void MediaPlayer::AddMedia(){ //not done??? seg faults :)
  string media; //user input for type of media
  int year, num; //user input for year and item they want to add
  int count = 0; //counter for amount of media found
  
  cout << "Choose the media you would like to add to the playlist." << endl;
  cout << "Which media type do you want to display? (podcast or music)" << endl;
  cin >> media;

  //validation for media type
  while(media != "music" && media != "podcast"){
    cout << "Which media type do you want to display?" << endl;
    cin >> media;
  }

  //validation for year
  cout << "Which year would you like to display? (1958-2020)" << endl;
  cin >> year; 
  while(year < MIN_YEAR && year > MAX_YEAR){
    cout << "Which year would you like to display? (1958-2020)" << endl;
      cin >> year;
  }

  //printing out media for year + type 
  cout << "******" << year << "******" << endl;
  for(unsigned int i = 0; i < m_mediaCatalog.size(); i++){
    if(m_mediaCatalog[i]->GetYear() == year && m_mediaCatalog[i]->GetType() == media){
      cout << (i+1) << ". " << m_mediaCatalog[i]->GetTitle() << " by " << m_mediaCatalog[i]->GetArtist() << endl;
      count ++;
    }
  }
  cout << count << " media found." << endl;
  
  if(count == 0){
    cout << "No media found with those criteria" << endl;
    
  }else{  
    cout << "Enter the number of the media you would like to add" << endl;
    cin >> num;
    
    //validation for the user to enter a number that's within range of the catalog
    while(num < 1 && num > int(m_mediaCatalog.size())){
      cout << "This number doesn't exist in the selected range." << endl;
      cout << "Enter the number of the media you would like to add" << endl;
      cin >> num;
  }
    
    //printing out the media that the user chose and adding to playlist
    cout << m_mediaCatalog[num - 1]->GetTitle() << " by " << m_mediaCatalog[num - 1]->GetArtist() << " added to the playlist" << endl;
    m_playList.Enqueue(m_mediaCatalog[num - 1]); 
  }   
}

//Name: DisplayPlaylist                                                       
//Precondition: None (will indicate if list is empty)                        
//Postcondition: Displays the playlist         
void MediaPlayer::DisplayPlaylist(){
  if(m_playList.IsEmpty() == 1){
    cout << "The playlist is currently empty" << endl;
  }else{
    for(int i = 0; i < m_playList.Size(); i ++){
      cout << (i + 1) << " " << m_playList.At(i)->GetTitle() << " by " << m_playList.At(i)->GetArtist() << " from " << m_playList.At(i)->GetYear() << endl; 
    }
  }
}

//Name: SortPlaylist
//Precondition: None (will indicate if list is empty)                         
//Postcondition: Sorts the playlist by year            
void MediaPlayer::SortPlaylist(){
  //checking to make sure the playlist isn't empty, then sorting
  if(m_playList.IsEmpty() == 1){
    cout << "The playlist is currently empty" << endl;
    
  }else{
    m_playList.Sort(); //calling Sort from Tqueue
    cout << "Done sorting by year." << endl;
    cout << m_playList.Size() << " items sorted." << endl;
  } 
}
