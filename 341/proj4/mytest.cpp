using namespace std;
#include <iostream>
#include "hash.h"
#include <random>

// Using a fixed seed value generates always the same sequence                 
// of pseudorandom numbers, e.g. reproducing scientific experiments            
// here it helps us with testing since the same sequence repeats               
std::mt19937 generator(10);// 10 is the fixed seed value                       

// We distribute the pseudorandom numbers uniformaly within                    
// the range [1000,99999]                                                      
std::uniform_int_distribution<> distribution(1000, 99999);

// The hash function used by HashTable class                                   
unsigned int hashCode(const string str);

// the function to generate random serial numbers                              
unsigned int vaccineSerial() {return distribution(generator);}

// Implementation of hash function -- stolen from driver.cpp                   
unsigned int hashCode(const string str) {
  unsigned int val = 0;
  const unsigned int thirtyThree = 33;  // magic number from textbook          
  for(int i = 0 ; i < str.length(); i++){
    val = val * thirtyThree + str[i];
  }
  return val;
}

class Tester{
public:
  void insertTest(HashTable &table, int array[]);
  void removeTest(HashTable &hashTable, int array[]);
  void rehashTest(HashTable &hashTable);
  void probeTest(HashTable &table);
};

int main(){
  //tester object, hashTable and array to hold objects for later use
  Tester tester;
  HashTable table(18, hashCode);
  int serialNums[50] = {0};
  
//visual check for contructor to change the value for the table, should be 101
  cout << "capcity of table: " << table.tableSize() << endl;

  //all of these tests are visual checks!
  tester.insertTest(table, serialNums);

  tester.rehashTest(table);
  
  tester.removeTest(table, serialNums);

  tester.probeTest(table);
  
  // table.dump();
  return 0;
}

//test for insertion and linear probing
void Tester::insertTest(HashTable &table, int serialNums[]){
  int serial = 0; //variable to hold serial value

  //inserting into table
  cout << "Inserting 50 elements into the table" << endl;
  for(int i = 0; i < 50; i ++){
    serial = vaccineSerial();
    table.insert(Person("Name", serial));

    //this will save a few objects to test for remove
    if(i % 3 == 0){
      serialNums[i] = serial;
    }
  }
  cout << "Table should have 50 people inserted" << endl;
  table.dump();
}

//test for insetion, triggering a rehash, and quadratic probing
void Tester::rehashTest(HashTable &table){
  int serial = vaccineSerial(); //holds serial value

//inserting another person should imapct the load factor + rehash should occur
  table.insert(Person("Name", serial));

  cout << "this is the 51st insertion so a rehash should occur, with the policy changing, and the new table should have a capacity of 211" << endl;

  //printing out the prob policy to check that it changed and tables capacity
  cout << "probing policy: " << table.m_currentProb << endl;
  cout << "table capacity: " << table.tableSize() << endl;

  cout << "Table should have 51 people inserted" << endl;
  table.dump();
}

//test for remove, rehash, and probing change
void Tester::removeTest(HashTable &table, int array[]){
  //using array from before, and removing a few elements, rehash should occur 
  for(int i = 0; i < 14; i++){
    table.remove(Person("Name", array[i]));
  }
  
  cout << "14 people will be removed from the table and a rehash should occur, with the tables capacity changing" << endl;

  //printing out the prob policy to check that it changed and tables capacity
  cout << "probing policy: " << table.m_currentProb << endl;
  cout << "table capacity: " << table.tableSize() << endl;
  table.dump();
}

//test for changing the probing type
void Tester::probeTest(HashTable &table){
  //forcing the probing type to switch should trigger a rehash
  if(table.m_currentProb == LINEAR){
    cout << "current probing type is linear, changing it to quadratic" << endl;
    table.setProbingPolicy(QUADRATIC);
  }
  
  if(table.m_currentProb == QUADRATIC){
    cout << "current probing type is quadratic, changing it to linear" << endl;
    table.setProbingPolicy(LINEAR);
  }

  //dump to see the new table
  cout << "table after probing policy was changed" << endl;
  
  //printing out the prob policy to check that it changed and tables capacity 
  cout << "probing policy: " << table.m_currentProb << endl;
  cout << "table capacity: " << table.tableSize() << endl;
  table.dump();
}
 
