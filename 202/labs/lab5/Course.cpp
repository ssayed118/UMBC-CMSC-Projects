/*****************************************                                     
** File:    Course.cpp                                                         
** Project: CMSC 202 Lab 5, Fall 2020                                      
** Author:  Sumaa Sayed                                                        
** Date:    9/29/20                                                            
** Section: 20/25                                                              
** E-mail:  ssayed1@gl.umbc.edu                                                
**                                                                             
** This file implements the getter and setter functions for lab5.cpp.
***********************************************/
#include <iostream>
#include "Course.h"
using namespace std;

//Constructor -- Already Implemented
Course::Course() {
  cout << "Creating a course..." << endl;
  m_courseName = "CMSC 202";
  m_sectionNum = 1;
  m_enrolledStudents = 50;
}

//Here is an example for a getter and a setter
int Course::getEnrolledStudents() {
  return m_enrolledStudents;
}

void Course::setEnrolledStudents(int numStudents) {
  //If number of students is negative, set to 0.
  if (numStudents < 0){
    m_enrolledStudents = 0;
  } else {
    m_enrolledStudents = numStudents;
  }
}

//**Student Requirement**
//Implement getters and setters for courseName and sectionNum here
string Course::getCourseName(){
  return m_courseName;
}

void Course::setCourseName(string courseName){
  m_courseName = courseName;
}

int Course::getSectionNum(){
  return m_sectionNum;
}

void Course::setSectionNum(int sectionNum){
  m_sectionNum = sectionNum;
}

//**Student Requirement**
//Custom Functions -- Implement checkLarge and dropStudent
void Course::checkLarge(){
  //if enrolledStudents is more than 40
 if(m_enrolledStudents > 40){
   cout << m_courseName << " section " << m_sectionNum << " is a large course!" << endl;
 }

 //if enrolled students is 40 or less
 else if(m_enrolledStudents <= 40){
   cout << m_courseName << " section " << m_sectionNum << " is a small course!" << endl;
 } 
}

bool Course::dropStudent(){
  //if enrolledStudents is greater than or equal to 1
 if(m_enrolledStudents >= 1){
   m_enrolledStudents --;
   cout << "Student successfully dropped the course!" << endl;
   return true;
 }

 //if enrolledStudents is less than one
 //else if(m_enrolledStudents < 1)
   else{
   cout << "The course is already empty!" << endl;
   return false;
 }
}
