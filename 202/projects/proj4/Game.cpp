/************************                                                     
* File: Game.cpp                                                              
* Project: CMSC202, Project 4, Fall 2020                                      
* Author: Sumaa Sayed                                                         
* Date: 11/2/2020                                                             
* Section: 20/25                                                              
* Email: ssayed1@umbc.edu                                                     
* Description: Game file for project 4.                                       
**************************/
#include "Game.h"

//default constructor
//preconditons: none
//postconditions: loads map
Game::Game(){
  string filename;
}

//overloaded constructor
//preconditons: none
//postcondiotions: loadsmap, sets rests + special, starts game
Game::Game(string filename){
  LoadMap(filename);
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  StartGame();
}

//destrcutor
//preconditons: none
//postconditons: deallocates plant, zombie and map
Game::~Game(){
    if(m_myPlant != nullptr){
    delete m_myPlant;
  }
  
  if(m_curZombie != nullptr){
    delete m_curZombie;
  }
 
  for(unsigned int i = 0; i < m_myMap.size(); i++){
    delete m_myMap[i];
  } 
}

//LoadMap - creates rooms to insert in m_myMap
//preocnditions: map file has info
//postcondtions: m_myMap has room objects
void Game::LoadMap(string filename){
 fstream myFile;
 myFile.open(filename); //opening file
 string ID, name, desc, north, east, south, west;//variables for items in file
 int id, n, e, s, w; //int variables to convert things to int

 //opening file and grabbing room items accordingly
  if(myFile.is_open()){
    while(getline(myFile, ID, '|') && getline(myFile, name, '|') &&
      getline(myFile, desc, '|') && getline(myFile, north, '|')&&
      getline(myFile, east, '|')&& getline(myFile, south, '|')&&
      getline(myFile, west, '|')){

      //converting to int
      id = stoi(ID);
      n = stoi(north);
      e = stoi(east);
      s = stoi(south);
      w = stoi(west);

      //dynamically allocating room and adding to map vector
      Room *room = new Room(id, name, desc, n, e, s, w);
      m_myMap.push_back(room); 
    }
  }
  //closing file
  myFile.close();
}

//PlantCreation() - user builds their plant here
//preconditions: none
//postcodnitons: m_myPlant is populated
void Game::PlantCreation(){
  string plantName; //stores name
  int classNum; //for user to pick type of plant
  
  cout << "Plant name: "; //getting name
  cin >> plantName;
  cout << "Select a class" << endl;
  cout << "1. Peashooter" << endl;
  cout << "2. Chomper" << endl;
  cout << "3. Sunflower" << endl;
  cout << "4. No class" << endl;
  cin >> classNum;

  //validating that classNum doesn't go past 1 or 4
  while(classNum < 1 && classNum > 4){
    cout << "Select a class (1-4)" << endl;
    cin >> classNum;
  }

  //building plant based off user input
  if(classNum == 1){
    m_myPlant = new Peashooter(plantName, PEASHOOTER_HEALTH);
  }
  if(classNum == 2){
    m_myPlant = new Chomper(plantName, CHOMPER_HEALTH);
  }
  if(classNum == 3){
    m_myPlant = new Sunflower(plantName, SUNFLOWER_HEALTH);
  }
  if(classNum == 4){
    m_myPlant = new Plant(plantName, PLANT_HEALTH);
  }
}

//StartGame() - starts game
//preconditions: m_myMap and m_myPlant is populated
//postcondtions: rest + special + curRoom is set, Action is called
void Game::StartGame(){
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  cout << "Welcome to UMBC Adventure!" << endl;
  PlantCreation();
  m_curZombie = 0;
  m_curRoom = START_ROOM;
  m_myMap.at(m_curRoom)->PrintRoom();
  Action();
}

//Action() - menu for game (backbone of this whole thing)
//preconditons: StartGame has finished running
//postconditions: Game runs until player quits or dies
void Game::Action(){
  int choice; //stores user choice
  do{
    //menu for game
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Zombie" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Check Stats"<< endl;
    cout << "6. Quit" << endl;
    cin >> choice;

    //validating choice
    while(choice < 1 && choice > 6){
      cout << "What would you like to do? (1-6)" << endl;
      cin >> choice;
    }

    //look
    if(choice == 1){
      m_myMap.at(m_curRoom)->PrintRoom();
    }
    //move
    if(choice == 2){
      m_curZombie = RandomZombie();
      Move();
    }
    //attack (this doens't seem to be working :(  )
    if(choice == 3){
      m_curZombie = RandomZombie();
      Attack();
    }
    //rest
    if(choice == 4){
      m_curZombie = RandomZombie();
      Rest();
    }
    //check stats
    if(choice == 5){
      Stats();
    }
  }
  //while user is still playing the game/ health is above 0
  while(m_myPlant->GetHealth() > 0 && choice != 6);
  cout << "Goodbye!" << endl;
}

//RandomZombie - creates a zombie randomly
// Preconditions: Has an entity pointer to hold zombie child                  
// Postconditions: Returns object of type Buckethead, Imp, or Engineer  
Entity* Game::RandomZombie(){ 
  int random; //stores random number
  random = (rand() % 4) + 1; //obtains random number

  //creates zombie based off number
  if(random == 1){
    Entity* enemy = new Buckethead("BUCKETHEAD", BUCKETHEAD_HEALTH);
    cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
    return enemy;
  }
  if(random == 2){
    Entity* enemy = new Imp("IMP", IMP_HEALTH);
    cout << "A dirty imp licks his lips and glares at you." << endl;
    return enemy;
  }
  
  if(random == 3){
    Entity* enemy = new Engineer("ENGINEER", ENGINEER_HEALTH);
    cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER." << endl;
    return enemy;
    
  }else{
    cout << "It is peaceful here" << endl;
    return nullptr; //empty m_curZombie
  }
}

//Rest - lets player rest if no zombie is in room
//precondtions: valid room w no zombies
//Postconditions: Reduces available rests by one and increases hp by 10 
void Game::Rest(){
  int heal = m_myPlant->GetHealth(); //stores current health
  if(m_curZombie == nullptr && m_numRests >= 1){
    m_numRests --; //decreases rest
    m_myPlant->SetHealth(REST_HEAL + heal);
    cout << "You rest and wake up refreshed." << endl;
  }else{
    cout << "You can't rest at the moment." << endl;
  }
}

// Name: Move - Moves a player from one room to another (updates m_curRoom) 
  // Preconditions: Must be valid move (room must exist)                      
  // Postconditions: Displays room information, checks for new zombie (deletes old)           
void Game::Move(){
  int direction; //stores location
  char myDirection; //stores user input

  //validates user direction
  cout << "Which direction? (N E S W)" << endl;
  cin >> myDirection;
  myDirection = tolower(myDirection);
  while(myDirection != 'n' && myDirection != 'e' && myDirection != 's' && myDirection != 'w'){
    cout << "Invalid direction. Try again please." << endl;
    cin >> myDirection;
    myDirection = tolower(myDirection);
  }
  
  //checks if direction is valid
  direction = m_myMap[m_curRoom]->CheckDirection(myDirection);

  //if direction is not -1, then valid
  if(direction != -1){ 
    if(m_myMap[m_curRoom] != nullptr){
      m_curRoom = direction;
    }
    m_myMap[m_curRoom]->PrintRoom(); //changed from .at()
  }
  if(direction == -1){
    //while(direction == -1){
    cout << "Which direction? (N E S W)" << endl;
    cin >> myDirection;
    myDirection = tolower(myDirection);
    while(myDirection != 'n' && myDirection != 'e' && myDirection != 's' && myDirection != 'w'){
      cout << "Invalid direction. Try again please." << endl;
      cin >> myDirection;
    }
  }  
}

// Name: Attack (it doesnt work)                   
  // Description: Allows player to attack an enemy entity.                      
  // Preconditions: Must have enemy zombie in room                             
// Postconditions: Indicates who wins and updates health(hp) as battle continues.         
void Game::Attack(){
  int option;
  int random;
  random = (rand() % 4) + 1; //if its 1, then special attack else normal
  // cout << "hi" << m_curZombie->GetName() << endl;
  
  if(m_curZombie == nullptr){
    cout << "There is no zombie in the room." << endl;
  }
  if(m_curZombie != nullptr){
    while(m_myPlant->GetHealth() <= 0 && m_curZombie->GetHealth() <= 0){
      cout << "1. Normal Attack\n 2. Special Attack" << endl;
      cin >> option;
      if(option != 1 && option != 2){
	cout << "1. Normal Attack\n 2. Special Attack" << endl;
	cin >> option;
      }
      
    //users normal attack
      if(option == 1){
	m_curZombie->SetHealth(m_curZombie->GetHealth() - m_myPlant->Attack());
	cout << m_myPlant->GetName() << "'s health: " << m_myPlant->GetHealth() << endl;
	//cout << m_curZombie->GetName() << "'s health: " << m_curZombie->GetHealth() << endl;
      }
    
    //users special attack (can only do a few special attacks)
      if(option == 2 && m_numSpecial > 0){
	m_numSpecial --;
	m_curZombie->SetHealth(m_curZombie->GetHealth() - m_myPlant->SpecialAttack());
	cout << m_myPlant->GetName() << "'s health: " << m_myPlant->GetHealth() << endl;
	
      //zombie can choose normal/special (25% chance of picking)
      if(random == 1){
	m_curZombie->SetHealth(m_curZombie->GetHealth() - m_myPlant->SpecialAttack());
	cout << m_curZombie->GetName() << "'s health: " << m_curZombie->GetHealth() << endl;
      }else{
	m_myPlant->SetHealth(m_myPlant->GetHealth() - m_curZombie->Attack());
	cout << m_curZombie->GetName() << "'s health: " << m_curZombie->GetHealth() << endl;
      }
      
      cout << *m_myPlant << endl;
      // cout << m_myPlant->GetName() << "'s health: " << m_myPlant->GetHealth() << endl;
      cout << *m_curZombie << endl;
      // cout << m_curZombie->GetName() << "'s health: " << m_curZombie->GetHealth() << endl;
      }
    }
    //after exiting while loop
    if(m_curZombie->GetHealth() <= 0){
      cout << "You have defeated the " << m_curZombie->GetName() << endl;
    }
    if(m_myPlant->GetHealth() <= 0){
      cout << "You have been defeated by the " << m_curZombie->GetName() << endl;     
    }
  }
}

// Name: Stats()                                                              
// Description: Displays the information about the player (name, hp, rests, specials)                                                                      
// Preconditions: None                                                      
// Postconditions: None 
void Game::Stats(){
  cout << "Name: " << m_myPlant->GetName() << endl;
  cout << "HP: " << m_myPlant->GetHealth() << endl;
  cout << "Rests: " << m_numRests << endl; 
  cout << "Specials: " << m_numSpecial << endl;
}

