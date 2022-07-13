// CMSC 341 - Spring 2021 - Project 4
// hash.cpp
// The implementation of the class HashTable
#include "hash.h"
#include "math.h"

HashTable::HashTable(unsigned size, hash_fn hash){
//check that the size is a prime number or that it's inbetween the range given
  if(isPrime(size) == true && (size > MINPRIME || size < MAXPRIME)){
    m_capacity = size; //0?
  }
  
  //otherwise set the capacity to the appropriate value
  else if(size < MINPRIME){
    m_capacity = MINPRIME;
  }
  else if(size > MAXPRIME){
    m_capacity = MAXPRIME;
  }
  else if(isPrime(size) != true){
    m_capacity = findNextPrime(size);
  }

  //setting other HashTable class variables
  m_hash = hash;
  m_table = new Person[m_capacity];
  m_size = 0;
  m_numDeleted = 0;
  m_currentProb = LINEAR;
}

HashTable::~HashTable(){
  //deleting m_table
  delete[] m_table;
  m_table = nullptr;
}

bool HashTable::insert(Person person){
  bool var; //variable to hold what the insert helper functions return

  //calling the helper function based on current probing policy
  if(m_currentProb == LINEAR){
    var = insertLinear(person);
  }
  
  else if(m_currentProb == QUADRATIC){
    var = insertQuad(person);
  }

  //checking rehash conditons
  if(lambda() > 0.5 && m_currentProb == LINEAR){
    setProbingPolicy(QUADRATIC);
  }
  if(lambda() > 0.5 && m_currentProb == QUADRATIC){
    setProbingPolicy(LINEAR);
  }
  
  return var; //returns a bool depending on helper functions
}

bool HashTable::insertLinear(Person p){
//these variables holds the value for the index that the loop will look at  
  int index = m_hash(p.key()) % m_capacity;
  int offset = 0;
  int currIndex = (index + offset) % m_capacity;
  
  //loop runs as long as the index isn't empry 
  while(not(m_table[currIndex] == EMPTY)){
    
    if(m_table[currIndex] == p){
      //returns false if the person is already in the table
      return false;
    }
    
    offset++;
    //reset index if there's a collision
    currIndex = (index + offset) % m_capacity;
  }

  //inserting person, incrementing size, and returns true
  m_table[currIndex] = p;
  m_size++;
  return true;
}

bool HashTable::insertQuad(Person p){ //same comments as above^
  int offset = 0;
  int index = (m_hash(p.key()) % m_capacity) % m_capacity;
  int currIndex = index + (offset * offset);
  
  //loop until an empty spot is found
  while(not(m_table[currIndex] == EMPTY)){
    if(m_table[currIndex] == p){
      return false;
    }
    
    //to prevent collisions
    offset ++;
    currIndex = ((index + (offset * offset)) % m_capacity) % m_capacity;
  }
  
  //insertion
  m_table[currIndex] = p;
  m_size++;
  return true; 
}

bool HashTable::remove(Person person){
  bool var; //holds whatever helper functions return

  //same comments as regular insert function^^^
  if(m_currentProb == LINEAR){
    var = removeLinear(person);
  }
  
  if(m_currentProb == QUADRATIC){
    var = removeQuad(person);
  }

  if(m_numDeleted > (0.25 * m_size) && m_currentProb == LINEAR){
    setProbingPolicy(QUADRATIC);                                              
  }
  
  if(m_numDeleted > (0.25 * m_size) && m_currentProb == QUADRATIC){
    setProbingPolicy(LINEAR);                                                 
  }
  
  return var;
}

bool HashTable::removeLinear(Person person){
 //these variables holds the value for the index that the loop will look at   
  int offset = 0;
  int index = m_hash(person.key()) % m_capacity;
  int currIndex = (index + offset) % m_capacity;

  //checking that the person is not at the index 
  while(not(m_table[currIndex] == person)){
    if(m_table[currIndex] == EMPTY){
      return false;
    }//if the spot is empty then return false
    
    offset++;
    currIndex = (index + offset) % m_capacity;
    //upddating index to loop through again
  }

  //marks the person as deleted & increments numDeleted
  m_table[currIndex] = DELETED;
  m_numDeleted++;
  return true;
}

bool HashTable::removeQuad(Person person){//same comments as above^
  int index = m_hash(person.key()) % m_capacity;
  int offset = 0;
  int currIndex = index + (offset * offset);
  
  while(not(m_table[currIndex] == person)){
    if(m_table[currIndex] == EMPTY){
      return false;
    }
    offset++;
    currIndex = ((index + (offset * offset)) % m_capacity) % m_capacity;
  }
  
  m_table[currIndex] = DELETED;
  m_numDeleted++;
  return true;
}

void HashTable::setProbingPolicy(probing prob){
  m_currentProb = prob; //setting probing policy
  // int sizeVar = m_size - m_numDeleted; //

  //variables to calculate the new capacity for the new table
  int num = (m_size - m_numDeleted) * 4;
  int newCapacity = findNextPrime(num);
 
  int newSize = m_capacity;  //size that probing helper will run on

  //setting capacity and creating a new Person array 
  m_capacity = newCapacity; 
  Person* newTable = new Person[m_capacity];

  //setting size and numDeleted so rehash doesn't get stuck in a loop 
  m_size = 0;
  m_numDeleted = 0;
  
  probingHelper(newSize, newTable);

  //deallocating and setting m_table to the new array
  delete[] m_table;
  m_table = nullptr;
  m_table = newTable;     
}

void HashTable::probingHelper(int size, Person *&newTable){
  //if policy is linear then pass the person to that function
  if(m_currentProb == LINEAR){ //linear
    for(int i = 0; i < size; i++){
      if(!(m_table[i] == DELETED) && !(m_table[i] == EMPTY)){
	rehashInsertLinear(newTable, m_table[i]);
      }
    }
  }

  //insertion for quadratic policy
  if(m_currentProb == QUADRATIC){ //quad
    for(int i = 0; i < size; i++){
      if(!(m_table[i] == DELETED) && !(m_table[i] == EMPTY)){ 
	rehashInsertQuad(newTable, m_table[i]);
      }
    }
  }
}

bool HashTable::rehashInsertLinear(Person *&newTable, Person p){
  //this variable holds the value for the index that the loop will look at
  int index = m_hash(p.key()) % m_capacity;
  int offset = 0;
  int currIndex = index + (offset * offset);
  
  //loop runs as long as the index isn't empry                                 
  while(not(newTable[currIndex] == EMPTY)){
    if(newTable[currIndex] == p){
      //returns false if the person is already in the table
      return false;
    }
    offset++;
    //reset index if there's a collision                                       
    currIndex = (index + offset) % m_capacity;
  }
  
  //inserting person, incrementing size. and returns true                      
  newTable[currIndex] = p; 
  m_size++;
  return true;
}

bool HashTable::rehashInsertQuad(Person *&newTable, Person p){
  int offset = 0;
  int index = (m_hash(p.key()) % m_capacity) % m_capacity;
  int currIndex = index + (offset * offset);

  //loop until an empty spot is foun
  while(not(newTable[currIndex] == EMPTY)){
    if(newTable[currIndex] == p){
      return false;
    }

    offset++;
    //to prevent collisions -- updating index
    currIndex = ((index + (offset * offset)) % m_capacity) % m_capacity;
  }

  //insertion                                                                  
  newTable[currIndex] = p;
  m_size++;
  return true;
}

float HashTable::lambda() const { //load factor
  return (float)m_size/(float)m_capacity;  
}

float HashTable::deletedRatio() const { //ratio of deleted elements
  return (float)m_numDeleted/(float)m_size;
}

void HashTable::dump() const {
  for (int i = 0; i < m_capacity; i++) {
    cout << "[" << i << "] : " << m_table[i] << endl;
  }
}

bool HashTable::isPrime(int number){
  // If number is prime this function returns true
  // otherwise it returns false
  bool result = true;
  for (int i = 2; i <= number / 2; ++i) {
    if (number % i == 0) {
      result = false;
      break;
    }
  }
  return result;
}

int HashTable::findNextPrime(int current){
  //we won't go beyond MAXPRIME
  //the smallest prime would be next after MINPRIME
  if (current < MINPRIME) current = MINPRIME;
  for (int i=current; i<MAXPRIME; i++) { 
    for (int j=2; j*j<=i; j++) {
      if (i % j == 0) 
	break;
      else if (j+1 > sqrt(i) && i != current) {
	return i;
      }
    }
  }
  //if a user tries to go over MAXPRIME
  return MAXPRIME;
}
