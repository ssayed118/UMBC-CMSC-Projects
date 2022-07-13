/******************************************                                    
** File: Train.cpp                                                         
** Project: CMSC202 Project 3, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 10/18/2020                                                            
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: This is the file                                    
***********************************************/
#include "Train.h"
#include "Passenger.h"
#include "Route.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Train::Train(Route* route){ //constructor
  Car* m_head = new Car(CAR_CAPACITY, m_totalCars);
  Route* m_route = route;             
  int m_totalCars = 1;
}

Train::~Train(){ //destrcutor
  Car* var = m_head;
  while(m_head != nullptr){
    for(unsigned int i = 0; i < var->m_passengers.size(); ++i){
      delete var->m_passengers.at(i); 
    }
  }    
}

void Train::AddCar(){
  //adding a car to the train 
  if(m_head == nullptr){
    Car* car = new Car(CAR_CAPACITY, m_totalCars + 1); 
    m_head = car;
    
  }else{
	Car* car = new Car(CAR_CAPACITY, m_totalCars + 1);
	Car* temp = m_head;
	while(temp->m_next != nullptr){ 
	  temp = temp->m_next;    
	}
	temp->m_next = car;
	temp = car;
	m_totalCars ++;
  }
}

void Train::RemoveCar(Car*){ //this is extra credit
  //  Stop* currentStop = m_head;
  //Stop* previousStop = m_head;
  //int counter = 0;
  //int location;
  //  cout << "where do you wanna remove? " << endl;
  //  cin >> location;
  
  //while(currentStop != nullptr){
  //if(counter == location){
  //  previousStop->GetNextStop() = currentStop->GetNextStop();
  //  delete currentStop;
  //  return;
  // }
  // previousStop = currentStop;
  // currentStop = currentStop->GetNextStop();
  //counter++;
  // }
  //m_totalCars--;
  //if(m_totalCars == 0){
  // m_head = nullptr;
  // m_tail = nullptr;
  // }
}

void Train::TrainStatus(){
  //getting info for displayTRainStatus
  Car* curr = m_head;
  cout << "Number of cars: " << m_totalCars << endl;
  while(curr != nullptr){
    cout << "Car " << curr->m_carNumber << ": Number of Passengers " << curr->m_capacity << endl;
    curr = curr->m_next;
  }
  m_route->PrintRouteDetails();  
}

void Train::LoadPassengers(string passFile){
  fstream myFile;
  int count = 0; //variables to count, and grab infor for passengers
  string firstName;
  string lastName;
  string age;
  string start;
  string end;
  int ageNum;
  string fullName = firstName + " " + lastName;
  myFile.open(passFile);
    
  if(myFile.is_open()){
    //grabbing each item for passenger
    while(getline(myFile, firstName, ',')){
      getline(myFile, lastName, ',');
      getline(myFile, age, ',');
      getline(myFile, start, ',');
      getline(myFile, end, '\n');

      ageNum = stoi(age); //converting age to int
      if(start == m_route->GetCurrentStop()->GetName()){
	Passenger *newPassenger = new Passenger(fullName, ageNum, start, end);
	BoardPassenger(newPassenger);
      }
      count ++;   
    }
  }
  myFile.close();
  cout << count << " passengers loaded." << endl;
}

void Train::BoardPassenger(Passenger* passenger){
  //adding passenger to train
  Car* var = m_head;
  if(IsTrainFull() == true){ //if trian is full then add a car
    AddCar();
  }else{
    var->AddPassenger(passenger);
    cout << "Name: " << passenger->GetName() << " Destination: " << passenger->GetFinalDestination() << endl;
    }
}

void Train::DisembarkPassengers(){
  //use temp avr, loop thro passengers, check their stops and remove as needed
  Car* var = m_head; //remove from vecotr + car

  for(int j = 0; j < m_totalCars; j++){
    for(unsigned int i = 0; i < var->m_passengers.size(); i++){
      if(var->m_passengers[i]->GetFinalDestination() == m_route->GetCurrentStop()->GetName()){
	delete var->m_passengers[i]; /
	delete var->m_passengers[j];
      }
      j--;
    }
  }
}

void Train::TravelToNextStop(){
  //check to see if trian is at final stop, then move trains location
  if(m_route->GetCurrentStop()->GetNextStop() != nullptr){
    cout << "Arriving at " << m_route->GetCurrentStop()->GetNextStop() << endl;
  }else{
    cout << "You have arrived at the last stop in this Route." << endl;
  }
}

void Train::TurnTrainAround(){
  //call reverseroute to turn the traina round
  m_route->ReverseRoute();
}

bool Train::IsTrainFull(){
  Car* curr = m_head;
  //check to see if train is not full by using IsFull function
  while(curr != nullptr){
    if(curr->IsFull() == false){
      return false;
    }
    curr = curr->m_next;
  }
  return true;
}
