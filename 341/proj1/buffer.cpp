/* File: buffer.cpp                                                            
 * Project: proj1                                                             
 * Author:  Sumaa Sayed                                                       
 * Date: 2/13/2021                                                             
 * Section: 01                                                                 
 * Email: ssayed1@gl.umbc.edu                                                  
 * This is the buffer class for proj1.                                         
 */
#include "buffer.h"

Buffer::Buffer(int capacity){
    // **************************************
    // Implement the alternative constructor
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // **************************************
  
  //setting the appropriate values for a buffer
  if(capacity < 1){
    m_capacity = 0;
    m_buffer = nullptr;
  }else{
    m_capacity = capacity;
    m_buffer = new int[m_capacity];
  }
  m_count = 0;
  m_start = 0;
  m_end = 0;
}

void Buffer::clear(){
    // ***********************************
    // Implement clear() function
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // **********************************

  //re-setting all the buffer variabeles to 0/empty
  m_capacity = 0; 
  m_count = 0;
  m_start = 0;
  m_end = 0;
  delete[] m_buffer;
  m_buffer = nullptr;
}

Buffer::~Buffer(){
    clear();
}

int Buffer::count(){return m_count;}

int Buffer::capacity(){return m_capacity;}

bool Buffer::full(){
    // **************************
    // Implement full() function
    // **************************

  //checking is the queue is full by comparing count and capacity
  if(m_count == m_capacity){ 
    return true;
  }else{
    return false;
  }
}

bool Buffer::empty(){
    // **************************
    // Implement empty() function
    // **************************

  //checking if the queue is empty by comparing count to 0
  if(m_count == 0){
    return true;
  }else{
    return false;
  }
}

void Buffer::enqueue(int data){
    // ********************************
    // Implement enqueue(...) function
    // ********************************

  //if the queue is full then throw an error 
  if(full() == true){
    throw overflow_error("Buffer::enqueue(int data) - The array is already full.");
    //else; add the data to the queue
  }else{
    m_buffer[m_end] = data;
    m_count++;
    m_end = ((m_end + 1) % m_capacity);
  }
}

int Buffer::dequeue(){
    // *****************************
    // Implement dequeue() function
    // *****************************

  //if the queue is empty then throw an error
  int start = m_start;
  if(empty() == true){
    throw underflow_error("Buffer::dequeue() - The array is empty");

    //else remove the first item in the queue
  }else{
    start = m_buffer[m_start];
    m_start = ((m_start + 1) % m_capacity);
    m_count --;
  }
  return start;
}

Buffer::Buffer(const Buffer & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************

  //copying the buffer variables 
    m_capacity = rhs.m_capacity;
    m_count = rhs.m_count;
    m_start = rhs.m_start;
    m_end = rhs.m_end;

    if(m_capacity > 0){
      m_buffer = new int[m_capacity];
      for(int i = 0; i < m_count; i++){
	m_buffer[i] = rhs.m_buffer[i];
      }
    }else{
      m_buffer = nullptr;
    }
}

const Buffer & Buffer::operator=(const Buffer & rhs){
  // ******************************
    // Implement assignment operator
    // ******************************

  //asigning the buffer variables 
  if(this != &rhs){
    delete[] m_buffer;
    
    m_capacity = rhs.m_capacity;
    m_count = rhs.m_count;
    m_start = rhs.m_start;
    m_end = rhs.m_end;

    if(m_capacity > 0){
      m_buffer = new int[m_capacity];
      for(int i = 0; i < m_count; i++){
	m_buffer[i] = rhs.m_buffer[i];
      }
    }else{
      m_buffer = nullptr;
    }
  }
  return *this;
}

void Buffer::dump(){
  int start = m_start;
  int end = m_end;
  int counter = 0;
  cout << "Buffer size: " << m_capacity << " : ";
  if (!empty()){
    while(counter < m_count){
      cout << m_buffer[start] << "[" << start << "]" << " ";
      start = (start + 1) % m_capacity;
      counter++;
    }
    cout << endl;
  }
  else cout << "Buffer is empty!" << endl;
}
