/******************************************                                    
** File: Route.cpp                                                         
** Project: CMSC202 Project 3, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 10/18/2020                                                            
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: This is the file for the Route struct for project 3.
***********************************************/
#include "Route.h"
#include "Stop.cpp"
#include "Train.h"
#include <iostream>
using namespace std;

//PRE + POST conditons are in the header files
Route::Route(){ //constructor
  m_head = nullptr;
  m_tail = nullptr;
  m_currentStop = nullptr;
  m_totalStops = 0;
}

Route::~Route(){ //destrcutor
  Stop* currentStop = m_head;
  while(currentStop != nullptr){
    m_head = currentStop;
    currentStop = currentStop-> GetNextStop();
    delete m_head;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_currentStop = nullptr;
  m_totalStops = 0;
}


void Route::LoadRoute(string routeFile){
  int count = 0; //varibales to grab certain items for route
  string stopName;
  string stopNum;
  int stop;
  
  fstream myFile;
  myFile.open(routeFile);

  if(myFile.is_open()){
    while(getline(myFile, stopName, ',')){
      getline(myFile, stopNum, '\n');

      stop = stoi(stopNum); //converting to int
      AddStop(stopName, stop);
      count++;
    }
  }
  myFile.close();
  cout << "Route loaded with " << count << " stops" << endl;
}

//adding stop to route
void Route::AddStop(string name, int stopNum){
  Stop* stopName = new Stop(name, stopNum);
  
  if(m_head == nullptr) {
    //    m_head = stopName;
    m_tail = stopName;
  }
  else {
    //Stop* currentStop = m_head;
    //use getnextstop!!
    //    while(currentStop->GetNextStop() != nullptr) {
    //currentStop = currentStop->GetNextStop();
    //}
    m_tail->SetNextStop(stopName);
    m_tail = stopName;
  }
  m_totalStops ++;
}
//printing route details
void Route::PrintRouteDetails(){  
  cout << "Current stop: " << GetCurrentStop() << endl;
  cout << "Next stop is: " << m_currentStop->GetNextStop() << endl;
}

//getting the current stop of the train
Stop* Route::GetCurrentStop(){ 
   if(m_currentStop != nullptr){  
     return m_currentStop;
   }else{
     m_currentStop = nullptr;
   }
   return m_currentStop;
 }

//setting the curretn stop of the train
void Route::SetCurrentStop(Stop* currStop){
   m_currentStop = currStop;
 }

//this fucntion def does NOT work but reversing the linked list of the route
void Route::ReverseRoute(){
  if(GetCurrentStop() != nullptr){
    cout << "You can only reverse the route when at the end of the route" << endl;
  }else{
    string name;
    int number;
    Stop *current = m_head;
    Stop *prev = nullptr;
    Stop* newNode = new Stop(name, number); 

    //insert at beggining
    while(current != nullptr){
      //      next = current->next;
      //current->next = prev;
      prev = current;
      current = current->GetNextStop();
    }
      //current = next;
      //      current = current-> newStop;
      
    //      Stop *current = next;
      if(current == nullptr){
	current = newNode;
	//prev->GetNextStop();
	//	current = newNode;
      }

      if(prev == nullptr){
	newNode->GetNextStop();
	current = newNode;
      }
      else{
	prev->GetNextStop();
	current = newNode->GetNextStop();
      }
  
  //grab curr + update it
      //create a new node w/ curr
      //set it to nextstop^
      //if m_head == nullptr, set m_tail = newstop
      //set m_head to the one you "created"
      //this allhappens in while loop^^ then done?
  //m_head = prev;
      while(prev != nullptr){
	delete prev;
      }
  }

  //  m_head-> SetNextStop(Stop *current);
  m_tail-> GetNextStop();
  cout << m_totalStops << "have been reversed." << endl;
}

