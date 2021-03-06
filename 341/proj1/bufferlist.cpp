/* File: bufferlist.cpp                                                        
 * Project: proj1                                                              
 * Author:  Sumaa Sayed                                                        
 * Date: 2/13/2021                                                             
 * Section: 01                                                                 
 * Email: ssayed1@gl.umbc.edu                                                  
 * This is the bufferlist class for proj1.                                     
 */
#include "bufferlist.h"
BufferList::BufferList(int minBufCapacity){
    // **************************************
    // Implement the alternative constructor
    // **************************************
  //setting the appropraite values for the bufferlist member variables
  if(minBufCapacity < 1){
    m_minBufCapacity = DEFAULT_MIN_CAPACITY;
  }else{
    m_minBufCapacity = minBufCapacity;
  }
  m_listSize = 1;
  m_cursor = new Buffer(m_minBufCapacity);
  m_cursor->m_next = m_cursor;
}

BufferList::~BufferList(){
  clear(); 
}

void BufferList::clear(){ 
    // *****************************
    // Implement clear() function
    // *****************************
  //destructor to deallocate m_cursor
  Buffer* var = m_cursor;
  Buffer* temp = m_cursor->m_next;
  while(m_listSize > 0){
    m_listSize --;
    delete var;
    var = temp;
    
    if(m_listSize > 1){
      temp = temp->m_next;
    }
  }
  m_listSize = 0;
  m_cursor = nullptr;
  m_minBufCapacity = 0;
}

void BufferList::enqueue(const int& data) {
    // ************************************************************************
    // Implement enqueue(...) function
    // we always insert at the back, that would be the cursor
    // if the current cursor is full we create a new node as cursor then we        // insert
    // ************************************************************************

  //try-catch overlflow error
  try{m_cursor->enqueue(data);
  }
  catch(overflow_error &e){
    int size;
    int maxVal;
    maxVal = MAX_FACTOR * m_minBufCapacity;
    size = INCREASE_FACTOR * m_cursor->m_capacity;
    if(size > maxVal){
      
      //adding the data to the queue
      Buffer* bufferTwo =  new Buffer(m_minBufCapacity);
      bufferTwo->enqueue(data);
      Buffer* temp;
      temp = m_cursor->m_next;
      //   m_cursor = bufferTwo;
      m_cursor->m_next = bufferTwo;
      m_cursor = bufferTwo;
      m_cursor->m_next = temp;
    }
  }
}

int BufferList::dequeue() {
    // *****************************
    // Implement dequeue() function
    // *****************************
  
  //checking for underflow error
  if(m_listSize = 1 && m_cursor->empty()){
    throw(underflow_error("BufferList::dequeue() - The array is empty"));
  }
  int var;
  try{var = m_cursor->m_next->dequeue();
  }
  catch(underflow_error &e){
    //removing the node via dequeue
    Buffer* temp = m_cursor->m_next->m_next;
    delete m_cursor->m_next; 
    m_cursor->m_next = temp;
    var = m_cursor->m_next->dequeue();
  }
  return var; 
}

BufferList::BufferList(const BufferList & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************

  //copying over the current bufferlist values and objects
  int counter = 1;
  m_listSize = rhs.m_listSize;;
  m_minBufCapacity = rhs.m_minBufCapacity;

  m_cursor = new Buffer(*rhs.m_cursor);
  if(m_listSize == 1){
    m_cursor->m_next = m_cursor;
  }
    
  Buffer* temp1 = m_cursor->m_next;
  Buffer * var = rhs.m_cursor->m_next;
 
  while(counter < m_listSize){
 
    temp1 = new Buffer(*var);
    if(counter == (m_listSize - 1)){
      temp1->m_next = m_cursor;
    }
 
    temp1 = temp1->m_next;
    var = var->m_next;
    counter ++;
  }
}

const BufferList & BufferList::operator=(const BufferList & rhs){
    // ******************************
    // Implement assignment operator
    // ******************************

  //assigning the appropriate bufferlist objects 
  int counter = 1;
  if(this != &rhs){
    clear();
    
    m_listSize = rhs.m_listSize;
    m_minBufCapacity = rhs.m_minBufCapacity;

    m_cursor = new Buffer(*rhs.m_cursor);
    if(m_listSize == 1){
      m_cursor->m_next = m_cursor;
    }

    Buffer* temp = m_cursor->m_next;
    Buffer * var = rhs.m_cursor->m_next;
   
    while(counter < m_listSize){
      temp = new Buffer(*var);
      
      if(counter == (m_listSize - 1)){
	temp->m_next = m_cursor;
      }
      
      temp = temp->m_next;
      var = var->m_next;
      counter ++;
    }
  } 
  return *this;
}

void BufferList::dump(){
  Buffer* temp = m_cursor->m_next;
  for(int i=0;i<m_listSize;i++){
    temp->dump();
    temp = temp->m_next;
    cout << endl;
  }
  cout << endl;
}
