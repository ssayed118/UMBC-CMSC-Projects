/*****************************************
** File:    proj1.cpp
** Project: CMSC 202 Project 1, Fall 2020
** Author:  Sumaa Sayed
** Date:    9/11/20
** Section: 20/25
** E-mail:  ssayed1@gl.umbc.edu 
**
** This project will decide if a file contains a valid "escalator" answer, or 
** not.
***********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_LINE = 3; //how many lines in the file
const int MAX_SIZE = 6; // how long the longest word in the file can be
const int ABC = 26; // number of letters in alphabet

// FUNCTION PROTOTYPES
int loadFile(string[MAX_LINE]);
void printWords(string[MAX_LINE]);
int countLetter(string[MAX_LINE]);
void clearList(string[MAX_LINE]);
int checkSize(string[MAX_LINE]);

int main(){
  string myArray[MAX_LINE];
  cout << "Welcome to Escalators" << endl;
  loadFile(myArray);

  if ((loadFile(myArray) == 1)){
  //do{
    printWords(myArray);
    checkSize(myArray);
    countLetter(myArray);
    clearList(myArray);
  }
  //while((loadFile(myArray) == 0));
	
  return 0;
}

//Name: loadFile
//Purpose: to open a file that the user inputs
int loadFile(string myArray[MAX_LINE]){
  string fileName;
  string fileLine;
  string answer;
  
  cout << "What is the file name of the list of words? ";
  cin >> fileName;

  ifstream myFile;
  myFile.open(fileName);

 int index = 0;
 if(myFile.is_open()){
   while(myFile >> fileLine){
     myArray[index] = fileLine;
     index ++;
   }
   printWords(myArray);
   checkSize(myArray);
   countLetter(myArray);
   clearList(myArray);
 }
   
 else{
   cout << "No file found" << endl;
   cout << "Check another list? (y/n)" << endl;
   cin >> answer;

   if(answer == "n" or answer == "N"){
     cout << "Thank you for using Escalators!" << endl;
     return 0;
   }
      
   else if(answer == "y" or answer == "Y"){
       return 1;
   }
 }  
 myFile.close();
 return 0;
}

//Name: printWords
//Prupoe: to print the words from the file, saved in myArray
void printWords(string myArray[MAX_LINE]){
  for(int index = 0; index < MAX_LINE; ++index){
    string word = myArray[index];
    cout << myArray[index] << " (" << word.length() << " letters)" << endl;
  }}

//Name: countLetter
//Purpose: to count how many of each letter shows up in a word, and compare    with the other words in the array to validate if the escalator is valid, or not
int countLetter(string myArray[MAX_LINE]){
  int newArray[MAX_LINE][ABC] = {0}; // setting array to 0
  int counterOne = 0; //counters for each word, to tally up the letters
  int counterTwo = 0;
  int counterThree = 0;
  int countFirst = 0; // counters for comparing 
  int countSecond = 0;
  char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  string wordOne = myArray[0]; //puttng the words into variables
  string wordTwo = myArray[1];
  string wordThree = myArray[2];
  string answer;
  
  //looping through each individual word and tallying how many of each letter
  for(int i = 0; i < MAX_SIZE; i++){
    for (int j = 0; j < ABC; j++){
      if(wordOne[i] == alphabet[j]){
	newArray[0][j] ++;
	counterOne ++;
      }}}

  //loop for second word
  for(int i = 0; i < (MAX_SIZE - 1); i++){
    for (int j = 0; j < ABC; j++){
      if(wordTwo[i] == alphabet[j]){
	newArray[1][j] ++;
	counterTwo ++;
      }}}

  //loop for third word
  for(int i = 0; i < (MAX_SIZE - 2); i++){
    for (int j = 0; j < ABC; j++){
	if(wordThree[i] == alphabet[j]){
	  newArray[2][j] ++;
          counterThree ++;
	}}}

  //loop for comparing that word1 and word0 have atleast 5 of the same letters
  for(int j = 0; j < ABC; j++){
    if((newArray[1][j] && newArray[0][j] != '0')){
  	countFirst = countFirst + newArray[1][j];
    }}

  //loop for comparing that word2 and word1 have 4 of the same letters
  if(countFirst == 5){
    for(int j = 0; j < ABC; j++){
      if(newArray[2][j] && newArray[1][j] != '0'){
	countSecond = countSecond + newArray[2][j];
      }}}

  if(countFirst == 5 && countSecond == 4){
    cout << "This list is valid" << endl;}

  else{
    cout << "This list is not valid" << endl;
    cout << "Check another list? (y/n)" << endl;
    cin >> answer;

    if(answer == "n" or answer == "N"){
      cout << "Thank you for using Escalators!" << endl;
      return 0;
    }

    else if(answer == "y" or answer == "Y"){
      loadFile(myArray);
  }
  }
  return 0;
}
//Name: clearList
//Purpose: to clear out the array for a new file
void clearList(string myArray[MAX_LINE]){
  for(int index = 0; index < MAX_LINE; index++){
    myArray[index] = " ";
  }}

//Name: checkSize
//Purpose: to make sure that each word is the correct lenght
int checkSize(string myArray[MAX_LINE]){
  //making sure that word0 is 6 letters, word1 is 5 and word2 is 4
  int wordLength1 = int(myArray[0].length());
  int wordLength2 = int(myArray[1].length());
  int wordLength3 = int(myArray[2].length());

  if(wordLength1 == MAX_SIZE && wordLength2 == (MAX_SIZE -1) && wordLength3 == (MAX_SIZE - 2)){
      return 1;
  }

  else{
    cout << "This list is not valid!" << endl;
    loadFile(myArray);
  }
  return 0;
}
