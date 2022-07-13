/**************
* File: lab5.cpp
* Project: CMSC 202 Lab 5, Fall 2020
* Author: Sumaa Sayed
* Date: 9/29/20
* Section: 20/25
* E-mail: ssayed1@gl.umbc.edu 
* The user creates this file to demonstrate use of a course.
 *************/   
                                      
#include <iostream>
#include "Course.h"
using namespace std;

int main() {
  //**Student Requirement**
  //Part 1: Create 2 courses by instantiating them
  Course courseOne; // course 1
  Course courseTwo; // course 2

  //**Student Requirement**
  //Part 2: Set their values for course name, section number, and enrolled students.
  courseOne.setCourseName("CMSC 201");
  courseOne.setSectionNum(2);
  courseOne.setEnrolledStudents(0);

  courseTwo.setCourseName("PHIL 100");
  courseTwo.setSectionNum(1);
  courseTwo.setEnrolledStudents(72);
  
  //**Student Requirement**
  //Part 3: Output their information:  Name, section, and enrolled students
  cout << "Data of course1:\n";
  cout << "\tCourse Name: " << courseOne.getCourseName() << endl;
  cout << "\tSection: " << courseOne.getSectionNum() << endl;
  cout << "\tEnrolled Students: " << courseOne.getEnrolledStudents() << endl;

  cout << "Data of course2:\n";
  cout << "\tCourse Name: " << courseTwo.getCourseName() << endl;
  cout << "\tSection: " << courseTwo.getSectionNum() << endl;
  cout << "\tEnrolled Students: " << courseTwo.getEnrolledStudents() << endl;
  
  //**Student Requirement**
  //Part 4: Call a custom function: Check if courses are large or not
  courseOne.checkLarge();
  courseTwo.checkLarge();

  //**Student Requirement**
  //Part 5: Update data members with custom function: Drop a student from each course
  //Display updated enrolled students
  courseOne.dropStudent();
  courseTwo.dropStudent();

  courseOne.getEnrolledStudents();
  courseTwo.getEnrolledStudents();
  
  cout << courseOne.getEnrolledStudents() << endl;
  cout << courseTwo.getEnrolledStudents() << endl;
  
  return 0;
}
