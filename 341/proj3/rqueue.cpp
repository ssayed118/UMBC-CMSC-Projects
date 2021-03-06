// CMSC 341 - Spring 2021 - Project 3
// RQueue: 

#include "rqueue.h"
using namespace std;
using std::cout;
using std::endl;
using std::domain_error;

RQueue::RQueue(prifn_t priFn){
  /************************
   * To be implemented
   * *********************/
  //setting values
  _heap = nullptr; //this is the root!  
  _size = 0; 
  priority = priFn;
}

RQueue::~RQueue(){
  /************************
   * To be implemented
   * *********************/
  clear();
  //  _heap = nullptr;
  // _size = 0;
}

RQueue::RQueue(const RQueue& rhs){
  /************************
   * To be implemented
   * *********************/
  //setting values
  _size = rhs._size;
  priority = rhs.priority;
  _heap = CCandAOHelper(rhs._heap);
}

//this function will recurse through the heap and assign nodes 
Node* RQueue::CCandAOHelper(Node* node){
  Node* temp = nullptr;
  if(node != nullptr){
    temp = new Node(node->getStudent());
    temp->_left = CCandAOHelper(temp->_left);
    temp->_right = CCandAOHelper(temp->_right);
  }
  return temp;
}

RQueue& RQueue::operator=(const RQueue& rhs){
  /************************
   * To be implemented
   * *********************/
  //checking for self-assign and setting values
  if(this != &rhs){
    clear();
    _size = rhs._size;
    priority = rhs.priority;
    _heap = CCandAOHelper(rhs._heap);
  }
  return *this;
}

void RQueue::insertStudent(const Student& input) {
  /************************
   * To be implemented
   * *********************/
  //inserting student via mergeHelp
  Node* temp = new Node(input);
  _heap = mergeHelper(temp, _heap);
  _size ++;
}

Student RQueue::getNextStudent() {
  /************************
   * To be implemented
   * *********************/
  Node* temp = _heap;

  //checking for empty heap
  if(_heap == nullptr){
    throw domain_error("getNextStudent - attempting to remove from a queue that is empty!");
  }

  //else, find node and return the student, and remove from queue
  _heap = mergeHelper(temp->_left, temp->_right);
  Student curr = temp->getStudent();
  delete temp;  
  _size --;
  return curr;
}


void RQueue::mergeWithQueue(RQueue& rhs) {
  /************************
   * To be implemented
   * *********************/
  //merge queue if priority functions are the same and heaps are different
  if(priority == rhs.priority && this != &rhs){
    _heap = mergeHelper(_heap, rhs._heap);
    _size += rhs._size; //updating size
    rhs._heap = nullptr;
  }

  //else throw error
  else{
    throw domain_error("mergeWithQueue - priority functions are different");
  }
}

Node* RQueue::mergeHelper(Node* newHeap, Node* oldHeap){
  //return heaps if one is empty
  if(newHeap == nullptr){
    return oldHeap;
  }
  if(oldHeap == nullptr){
    return newHeap;
  }

  //swap heaps if priority of one is higher
  if(priority(newHeap->getStudent()) > priority(oldHeap->getStudent())){
    swap(newHeap, oldHeap);
  }

  //else swap and recursive call
  swap(newHeap->_left, newHeap->_right);
  
  newHeap->_left = mergeHelper(oldHeap, newHeap->_left);
  //newHeap->_left = mergeHelper(newHeap->_left, oldHeap);
  
  return newHeap; //return heap to save it for _heap
}

void RQueue::clear() {
  /************************
   * To be implemented
   * *********************/
  Node* clearNode = _heap;
  clearHelper(clearNode);
}

void RQueue::clearHelper(Node* node){
  //recursing through heap and deleting nodes
  if(node == nullptr){
    return;
  }
  clearHelper(node->_left);
  clearHelper(node->_right);
  delete node;
  node = nullptr;
}

int RQueue::numStudents() const{
  /************************
   * To be implemented
   * *********************/
  return _size; //size of queue
}

void RQueue::printStudentQueue() const {
  /************************
   * To be implemented
   * *********************/
  Node* printNode = _heap;
  printHelper(printNode);
}

void RQueue::printHelper(Node* node) const{ //preorder
  //recursing through heap and printing nodes
  if(node != nullptr){
    Student student = node->getStudent();
    cout << "[" << priority(node->_student) << "]" << "Student: " << student.getName() << ", priority: " << student.getPriority() << ", year: " << student.getYear() << ", major: " << student.getMajorStr() << ", group: " << student.getGroupStr() << endl;
    printHelper(node->_left);
    printHelper(node->_right);
  }
}

prifn_t RQueue::getPriorityFn() const {
  /************************
   * To be implemented
   * *********************/
  return priority; //obtaining priority
}

void RQueue::setPriorityFn(prifn_t priFn) {
  /************************
   * To be implemented
   * *********************/
  
  //setting new priorty for heap and rebuilding a new heap
  priority = priFn; 
  RQueue queue(priFn);
  queue.setHelp(_heap);
  clear();
  _size = queue._size;
  _heap = queue._heap;
  queue._heap = nullptr;
}

//recurse through heap
void RQueue::setHelp(Node* node){
  //recursing through heap and inserting nodes into new queue
  if(node != nullptr){
    insertStudent(node->getStudent());
    setHelp(node->_left);
    setHelp(node->_right);
  }
}

// for debugging
void RQueue::dump() const{
  if (_size == 0) {
    cout << "Empty skew heap.\n" ;
  } else {
    dump(_heap);
    cout << endl;
  }
}

// for debugging
void RQueue::dump(Node *pos) const {
  if ( pos != nullptr ) {
    cout << "(";
    dump(pos->_left);
    cout << priority(pos->_student) << ":" << pos->_student.getName();
    dump(pos->_right);
    cout << ")";
  }
}

// overloaded insertion operator for Student class
ostream& operator<<(ostream& sout, const Student& student) {
  sout << "Student: " << student.getName() << ", priority: " << student.getPriority() << ", year: " << student.getYear() << ", major: " << student.getMajorStr() << ", group: " << student.getGroupStr();
  return sout;
}

// overloaded insertion operator for Node class
ostream& operator<<(ostream& sout, const Node& node) {
  sout << node.getStudent();
  return sout;
}
