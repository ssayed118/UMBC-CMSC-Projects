/******************************
** File: LinkedList.cpp
** Lab: CMSC 202 Lab8
** Author: Sumaa Sayed
** Date: 09/14/2020
** Email: ssayed1@umbc.edu
** Section: 20/25
** Lab7 for cmsc 202
**
** Checks if a linked list is a palindrome.
******************************/

#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList(): m_head(nullptr) {};

LinkedList::~LinkedList() {
    Node* current = m_head;
    while (m_head) {
        m_head = m_head->next;
        delete current;
        current = m_head;
    }
}

// Inserts node at the end of the linked list
void LinkedList::insertAtEnd(char letter){
    if(m_head == nullptr) {
        m_head = new Node(letter);
    }
    else {
        Node *current = m_head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(letter);
    }
}

// Inserts node at the front of the linked list
void LinkedList::insertAtFront(char letter) {
    if(m_head == nullptr) {
        m_head = new Node(letter);
    }
    else {
        m_head = new Node(letter, m_head);
    }
}

// Displays/Prints the linked list
void LinkedList::display() {
    Node* current = m_head;
    while(current) {
        cout << current->letter;
        current = current->next;
    }
    cout << endl;
}

// *** TODO ***
// Implement reverse function - reverses the linked list
// Should return the reversed linked list
// Note: Keep this->m_head in position.
LinkedList* LinkedList::reverse() {
    // Write code here...
  LinkedList *revList = new LinkedList;

  //setting nodes to try and reverse the word..?
  Node *current = m_head;
  Node *previous = NULL;
  Node *next = NULL;

  while(current != NULL){
    next = current -> next;
    current -> next = previous;
    previous = current;
    current = next;
  }
  //setting the node and appending to the list..?
  m_head = previous;
  revList -> insertAtEnd(Node *m_head);

  return revList;
}

// *** TODO ***
// Implement isPalindrome function
// Utilize reverse function to implement this function
// Note: Keep this->m_head in position.
//I have no idea how to write this function at all like it's just a big ?? and lab ta confused me woo
bool LinkedList::isPalindrome() {
        // Write code here...

  //check if the lists match up?? and then if do, return true
  if (LinkedList -> reverse()){

 //this is what i wanted to do but like there are not enough hours in the day: 
 //iterate through and then every node should be equal, from both lists i think
  //save an array of node, call reverse, idk????
  
    return true;
  }
}
