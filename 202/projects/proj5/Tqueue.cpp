/******************************************                                    
** File: Tqueue.cpp                                                           
** Project: CMSC202 Project 5, Fall 2020                                       
** Author: Sumaa Sayed                                                         
** Date: 11/23/2020                                                            
** Section 20/25                                                               
** Email: ssayed1@gl.umbc.edu                                                  
** Description: Tqueue file for project 5. 
*********************************************/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T, int N> //T is the data type and N is the container's capacity
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: Enqueue
  //Desc: Adds item to the back of queue (checks for capacity)
  //Precondition: Existing Tqueue
  //Postcondition: Size is incremented if successful and m_back increases
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //      **Automatically moves all data to start at index 0 (using loop**
  //Precondition: Existing Tqueue
  //Postcondition: Size is decremented if successful.
  //               Data in m_front is removed and remaining data is move to the front.
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue (any algorithm you like)
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (low to high)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (difference between m_back and m_front)
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: At
  //Precondition: Existing Tqueue with index starting at 0
  //Postcondition: Returns object from Tqueue using At() 
  T& At(int x);//Returns data from queue at location
  //Name: DisplayAll()
  //Precondition: Existing Tqueue (not used in MediaPlayer)
  //Postcondition: Outputs all items in Tqueue (must be cout compatible -
  //               may require overloaded << in object)
  void DisplayAll();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue (for this project should always remain at 0)
  int m_back; //Back of the queue (will increase as the size increases)
};

//**** Add class definition below ****
template <class T, int N>
Tqueue<T,N>::Tqueue(){
  m_data = new T[N]; 
  m_front = 0;
  m_back = 0;
}

//copy constructor
template <class T, int N>
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ){
  m_front = x.m_front;
  m_back = x.m_back;
  m_data = new T[N];
  for(int i = 0; i < N; i ++){
    m_data[i] = x.m_data[i];
  }
}

template <class T, int N>
Tqueue<T,N>::~Tqueue(){
  //deallocating m_data 
  delete[] m_data;
  m_data = nullptr;
}

template <class T, int N>
void Tqueue<T,N>::Enqueue(T data){
  if(IsFull() == 1){ //checking to see if the queue is full
    cout << "The queue is full." << endl;

    //if not, then adding in data at the back of m_data
  }else{
    m_data[m_back] = data;
    m_back++;
  }
}

template <class T, int N>
void Tqueue<T,N>::Dequeue(){
  if(IsEmpty() == 1){ //making sure the queue is empty
    cout << "The queue is empty." << endl;
    
    //if not, pulling data upwards (by one spot)
  }else{
    for(int i = 0; i < m_back; i ++){
      m_data[i] = m_data[i + 1];
    }
    m_back --; //subtracting from size
  }
}

template <class T, int N>
void Tqueue<T,N>::Sort(){
  T temp; //T for running proj, for tests its int

  //bubble sort to sort playlist/data
  for(int i = 0; i < Size(); i++){
    for(int j = 0; j < Size() - 1; j++){
      if(m_data[j] > m_data[j + 1]){
	temp = m_data[j];
	m_data[j] = m_data[j + 1];
	m_data[j + 1] = temp;
      }
    }
  }
}

template <class T, int N>
int Tqueue<T,N>::IsEmpty(){
  if(m_back == 0){ //if m_back is 0, then it's empty
    return 1;
  }else{
    return 0;
  }
}

template <class T, int N>
int Tqueue<T,N>::IsFull(){
  if(m_back == N){ //if m_back == N (max capcity), then it's full
    return 1;
  }else{
    return 0;
  }
}

template <class T, int N>
int Tqueue<T,N>::Size(){
  int size = m_back - m_front;
  //m_back will carry the size, and m_front should be 0 

  return size;
}

template <class T, int N>
Tqueue<T,N>&Tqueue<T,N>::operator=( Tqueue<T,N> y){
  if(this != &y){ //overwrite in if condtion,, when y is not the object
    delete[] m_data;

    //setting the variables to y object
    m_front = y.m_front;
    m_back = y.m_back;
    
    m_data = new T[N];
    for(int i = 0; i < Size(); i ++){
      m_data[i] = y.m_data[i];
    }
  }
  return *this;
}

template <class T, int N>
T&Tqueue<T,N>::At(int x){
  return m_data[x]; //looking at m_data at x
}

template <class T, int N>
void Tqueue<T,N>::DisplayAll(){
  //for loop to display items in m_data
  for(int i = m_front; i < m_back; i ++){
    cout << m_data[i] << endl; 
  }
}

#endif
