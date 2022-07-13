/**********
** File: Course.h
** Project: CMSC 202 Lab 5, Fall 2020                                          
** Author:  Sumaa Sayed                                                        
** Date:    9/29/20                                                            
** Section: 20/25                                                              
** E-mail:  ssayed1@gl.umbc.edu                                                
** This file defines the getter and setter functions for lab5.cpp.  
** Intended for Lab 5: Classes
**********/

#ifndef COURSE_H //Header or Include Guards
#define COURSE_H //Header or Include Guards

#include <iostream>
#include <string>
using namespace std;

class Course {
public:
  //Default constructor, already implemented.
  Course();
  
  //**Student Requirement**
  //Do the prototype for each of the functions described in the lab document
  
  //Returns name of the course
  string getCourseName();
  
  //Sets name of the course
  void setCourseName(string courseName);
  
  //Returns the course's section number
  int getSectionNum();
  
  //Sets the course's section number
  void setSectionNum(int sectionNum);

  //Returns course's enrolled students
  int getEnrolledStudents();

  //Sets course's enrolled students
  void setEnrolledStudents(int enrolledStudents);
  
  //Outputs whether the course is large or not
  void checkLarge();
  
  //Removes one student from the course
  bool dropStudent();
  
private:
  //**Student Requirement**
  //Create the member variables below as described in the lab document
  string m_courseName;  //name of course
  int m_sectionNum; //section number
  int m_enrolledStudents;  //enrolled students
};

#endif //End of Header Guard
