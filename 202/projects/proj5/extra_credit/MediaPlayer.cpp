/******************************************                                   
** File: MediaPlayer.cpp  
** Project: CMSC202 Project 5, Fall 2020                                      
** Author: Sumaa Sayed                                                        
** Date: 11/20/2020                                                           
** Section 20/25                                                              
** Email: ssayed1@gl.umbc.edu                                                 
** Description: This is the mediaPlayer file for proj 5, modifed for extra 
** credit.
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
  if(m_mediaCatalog.empty()){
    for(unsigned int i = 0; i < m_mediaCatalog.size(); i++){
      delete m_mediaCatalog[i];
    }
  }
}

//Name: LoadCatalog(string filename)                                          
//Precondition: Requires filename                                            
//Postcondition: Loads the file into the m_mediaCatalog (as media)    
void MediaPlayer::LoadCatalog(string filename){
  fstream myFile; 
  string title, artist, type, year, rank;
  int year1, rank1;
  int counter = 0;
  Media *media;
  
  myFile.open(filename);
  if(myFile.is_open()){
    while(getline(myFile, title, ';')){
	getline(myFile, artist, ';');
	getline(myFile, type, ';');
	getline(myFile, year, ';');
	getline(myFile, rank, '\n');

	year1 = stoi(year);
	rank1 = stoi(rank);
	
	media = new Media(title, artist, type, year1, rank1); 
	counter ++;
	m_mediaCatalog.push_back(media);
    }
  }
  cout << counter << " media files loaded." << endl;
  myFile.close();
}

//Name: MainMenu                                                              
//Precondition: None                                                         
//Postcondition: Manages the application and the menu     
void MediaPlayer::MainMenu(){
  int option = 0; //holds user input for menu
  while(option != 7){
    cout << "What would you like to do?" << endl;
    cout << "1. Display Media by Type and Year" << endl;
    cout << "2. Create New Playlist" << endl;
    cout << "3. Display Existing Playlist" << endl;
    cout << "4. Import Playlist" << endl;
    cout << "5. Export Playlist" << endl;
    cout << "6. Sort Playlist by Year" << endl;
    cout << "7. Quit" << endl;
    cin >> option;
    
    while(option < 1 && option > 7){
      cout << "What would you like to do?" << endl;
      cin >> option;
    }
    
    if(option == 1){
      DisplayMedia();
    }
    
    if(option == 2){
      AddMedia();
    }
    
    if(option == 3){
      DisplayPlaylist(); 
    }
    
    if(option == 4){
      Import();
    }
    
    if(option == 5){
      Export();
    }

    if(option == 6){
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
  int year = 0;
  int count = 0;
  string media;
  cout << "Which media type do you want to display? (podcast or music)" << endl;
  cin >> media;
  while((media != "music") && (media != "podcast")){
    cout << "Which media type do you want to display?" << endl;
    cin >> media;
  }
  
  cout << "Which year would you like to display? (1958-2020)" << endl;
  cin >> year;
    
  while(year < MIN_YEAR or year > MAX_YEAR){
    cout << "Which year would you like to display? (1958-2020)" << endl;
    cin >> year;
  }
    
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
//Postcondition: Creates a new playlist for the usert    
void MediaPlayer::AddMedia(){ 
  string media;
  int year, num;
  int count = 0;
  int name;
  
  cout << "What would you like to name your playlist (int only)" << endl;
  cout << "Psst, if you've already created a playlist and want to add to it, just type in the same name!" << endl;
  cin >> name;
  
  while((name < 0) && (name > MAX_LISTS)){
    cout << "Which playlist would you like to add to?" << endl;
    cout << "Pick a number between 0 and 10" << endl;
    cin >> name;
  }
  cout << "Choose the media you would like to add to the playlist." << endl;

  //validation for type of media user chooses
  cout << "Which media type do you want to display? (podcast or music)" << endl;
  cin >> media;
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

  //printing out media that fits users criteria
  cout << "******" << year << "******" << endl;
  for(unsigned int i = 0; i < m_mediaCatalog.size(); i++){
    if(m_mediaCatalog[i]->GetYear() == year && m_mediaCatalog[i]->GetType() == media){
      cout << (i+1) << ". " << m_mediaCatalog[i]->GetTitle() << " by " << m_mediaCatalog[i]->GetArtist() << endl;
      count ++;
    }
  }  
  cout << count << " media found." << endl;

  //if no media is found then go back to menu
  if(count == 0){
    cout << "No media found with those criteria" << endl;
    
  }else{
    cout << "Enter the number of the media you would like to add" << endl;
    cin >> num;
    
    //validation for media to be in range of the catalog
    while(num < 1 && num > int(m_mediaCatalog.size())){
      cout << "This number doesn't exist in the selected range." << endl;
      cout << "Enter the number of the media you would like to add" << endl;
      cin >> num;
    }
    
    //adding to playlist
    cout << m_mediaCatalog[num - 1]->GetTitle() << " by " << m_mediaCatalog[num - 1]->GetArtist() << " added to the playlist" << endl;
    m_playlists.At(name).Enqueue(m_mediaCatalog[num - 1]);
  }  
}

//Name: DisplayPlaylist                                                       
//Precondition: None (will indicate if list is empty)                        
//Postcondition: Displays the playlist         
void MediaPlayer::DisplayPlaylist(){
  int name; //holds name of playlist
  cout << "Which playlist would you like to display?" << endl;
  cin >> name;

  while((name < 0) && (name > MAX_LISTS)){
    cout << "Which playlist would you like to display?" << endl;
    cout << "Pick a number between 0 and 10" << endl;
    cin >> name;
  }

  //prints out playlist
  if(m_playlists.At(name).IsEmpty() == 1){
    cout << "The playlist is currently empty" << endl;
  }else{
    for(int i = 0; i < m_playlists.At(name).Size(); i ++){
      cout << (i + 1) << " " << m_playlists.At(name).At(i)->GetTitle() << " by " << m_playlists.At(name).At(i)->GetArtist() << " from " << m_playlists.At(name).At(i)->GetYear() << endl; 
    }
  }
}

//Name: SortPlaylist
//Precondition: None (will indicate if list is empty)                         
//Postcondition: Sorts the playlist by year            
void MediaPlayer::SortPlaylist(){
  int name; //holds name of playlist
  cout << "Which playlist would you like to sort?" << endl;
  cin >> name;
  
  while((name < 0) && (name > MAX_LISTS)){
    cout << "Which playlist would you like to sort?" << endl;
    cout << "Pick a number between 0 and 10" << endl;
    cin >> name;
  }

  //playlist gets sent to Sort function in Tqueue
  if(m_playlists.At(name).IsEmpty() == 1){
    cout << "The playlist is currently empty" << endl;
  }else{
    m_playlists.At(name).Sort();
    cout << "Done sorting by year." << endl;
    cout << m_playlists.At(name).Size() << " items sorted." << endl;
  } 
}

//Name: Import                                                                
//Preconditon: File for playlist must exist                                  
//Postcondition: Saves the playlist in m_playLists  
void MediaPlayer::Import(){
  fstream myFile; //file to be opened
  string title, artist, type, year, rank; //items needed for Media object
  string name; //name of file
  int year1, rank1; //to convert from stirng to int
  int nameList; //name of playlist
  int counter = 0; //counter to check that all items were loaded in 
  Media *media; //to create new Media objects
  
  cout << "What playlist file would you like to import?" << endl;
  cin >> name;

  cout << "Which playlist do you want to import?" << endl;
  cin >> nameList;
  
  while((nameList < 0) && (nameList > MAX_LISTS)){
    cout << "Which playlist would you like to save to?" << endl;
    cout << "Pick a number between 0 and 10" << endl;
    cin >> nameList;
  }

  //opening the file and grabbing the appropriate items from the file
  myFile.open(name);
  if(myFile.is_open()){
    while(getline(myFile, title, ';')){
      getline(myFile, artist, ';');
      getline(myFile, type, ';');
      getline(myFile, year, ';');
      getline(myFile, rank, '\n');
      
      year1 = stoi(year);
      rank1 = stoi(rank);

      //creating Media object
      media = new Media(title, artist, type, year1, rank1);
      counter ++;
      m_playlists.At(nameList).Enqueue(media);  
    }
  }
  cout << counter << " media items in playlist loaded." << endl;
  myFile.close();
}

//Name: Export();                                                             
//Preconditon: Playlist must exits                                           
 //Postcondtion: Saves playlist as text file 
void MediaPlayer::Export(){
  string filename; //name of file
  int listName; //name of playlist

  //obtaning filename and playlist name
  cout << "What do you want to call your file? (no spaces please!)" << endl;
  cin >> filename;

  cout << "Which playlist would you like to add to the file?" << endl;
  cin >> listName;

  while((listName < 0) && (listName > MAX_LISTS - 1)){
    cout << "Which playlist would you like to display?" << endl;
    cout << "Pick a number between 0 and 10" << endl;
    cin >> listName;
  }

  //writing the file
  ofstream outputfile(filename);
  for(int i = 0; i <  m_playlists.At(listName).Size(); i ++){
    outputfile <<  m_playlists.At(listName).At(i)->GetTitle() << ';' <<  m_playlists.At(listName).At(i)->GetArtist() << ';' <<  m_playlists.At(listName).At(i)->GetType() << ';' <<  m_playlists.At(listName).At(i)->GetYear() << ';' <<  m_playlists.At(listName).At(i)->GetRank() << '\n';
  }
}
