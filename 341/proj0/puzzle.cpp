/* File: puzzle.cpp                                                           
 * Project: proj0                                          
 * Author:  Sumaa Sayed                                                        
 * Date: 2/9/2021                                                           
 * Section: 01                                                              
 * Email: ssayed1@gl.umbc.edu                                                
 * This is the puzzle class for proj0.
 */

#include "puzzle.h"
Puzzle::Puzzle(int size){
    // *************************************
    // Implement the alternative constructor
    // *************************************

  //setting m_size to the appropriate value
  if(size < 0){
    m_size = 0;
  }else{
    m_size = size;
  }

  //calling these 2 functions to fill up the array, m_table
  makeMem();
  fill();
}

Puzzle::~Puzzle(){ //destructor
  clear();
}

void Puzzle::clear(){
    // ***************************
    // Implement clear() function
    // ***************************

  //empties out m_table and sets size to 0
  for(int i = 0; i < m_size; i ++){
    delete[] m_table[i]; 
  }
  
  delete[] m_table;
  m_table = nullptr;
  m_size = 0;
}

void Puzzle::makeMem(){
    // ****************************
    // Implement makeMem() function
    // ****************************

  //allocates memory for m_table
  m_table = new char*[m_size];
  for(int i = 0; i < m_size; i++){
    m_table[i] = new char[m_size];
  }
}

Puzzle::Puzzle(const Puzzle& rhs){
    // ***************************
    // Implement copy constructor
    // ***************************
  
  //setting the size and filling m_table
  m_size = rhs.m_size;
  makeMem();

  //setting m_table 
  for(int i = 0; i < m_size; i++){
    for(int j = 0; j < m_size; j++){
      m_table[i][j] = rhs.m_table[i][j]; 
    }
  }
}

const Puzzle& Puzzle::operator=(const Puzzle& rhs){
  // *****************************
    // Implement assignment operator
    // *****************************
  
  //clearing out m_table
  if(this != &rhs){
    clear();
  }

  //setting the size and filling m_table & setting m_table
  m_size = rhs.m_size;
  makeMem();
  
  for(int i = 0; i < m_size; i++){
    for(int j = 0; j < m_size; j++){
      m_table[i][j] = rhs.m_table[i][j];
    }
  }
  return *this;
}
 
void Puzzle::dump(){
    if (m_size > 0){
        int i=0;
        int j=0;
        while(i<m_size){
            while(j<m_size){
                cout << m_table[i][j] << " ";
                j++;
            }
            cout << endl;
            j=0;
            i++;
        }
        cout << endl;
    }
}

void Puzzle::fill(){
    srand(time(NULL));//create the seed value using the current time
    int i=0;
    int j=0;
    while(i<m_size){
        while(j<m_size){
            m_table[i][j] = ALPHA[rand() % MAX];//find a random char from the chars list
            j++;
        }
        j=0;
        i++;
    }
}
