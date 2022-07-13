/* File: mytest.cpp                                                            
 * Project: proj0                                                              
 * Author: Sumaa Sayed                                                       
 * Date: 2/9/2021                                                              
 * Section: 01                                                                 
 * Email: ssayed1@gl.umbc.edu                                                  
 * This is the tester class for proj0.                                         
 */

#include "puzzle.h"
class Tester{
  public:
  bool testCopyConstructor(const Puzzle& puzzle);
  void measureInsertionTime(int numTrials, int N); 
  bool testAssignmentOperator(const Puzzle& rhs); //AHHH
  bool testConstructor(int size);
};

int main(){
  Tester tester; //tester class object
  
  //TESTING COPY CONSTRUCTOR
  Puzzle p1000(1000);
  cout << "Test case, Copy Constructor: same members, same size, different pointers (deep copy):" << endl;
  if(tester.testCopyConstructor(p1000) == true){
    cout << "Copy constructor passed!" << endl;
  }else{
    cout << "Copy constructor failed!" << endl;
  }
  
  //tests the edge case, object with 1 member                              
  cout << "\nTest case, Copy Constructor: 1 member:" << endl;
  Puzzle p1(1);
  if (tester.testCopyConstructor(p1) == true){
    cout << "Copy constructor passed!" << endl;
  }else{
    cout << "Copy constructor failed!" << endl;
  }
  
  //tests the edge case, 0 members (empty object)                       
  cout << "\nTest case, Copy Constructor: zero members:" << endl;
  Puzzle p0(0);
  if (tester.testCopyConstructor(p0) == true){
    cout << "Copy constructor passed!" << endl;
  }else{
    cout << "Copy constructor failed!" << endl;
  }

  //test the user error case, creating object with table size less than 0 
  cout << "\nTest case, Copy Constructor: table size less than 0:" << endl;
  Puzzle p10(-10);
  if (tester.testCopyConstructor(p10) == true){
    cout << "Copy constructor passed!" << endl;
  }else{
    cout << "Copy constructor failed!" << endl;
  }
  
//TESTING TIME FOR COPY CONSTRUCTOR 
  //Measuring the efficiency of insertion functionality
  cout << "\nMeasuring the efficiency of insertion functionality:" << endl;
  int M = 5;//number of trials                                            
  int N = 1000;//original input size                                      
  tester.measureInsertionTime(M, N);

 //TESTING ASSIGNMENT OPERATOR
  Puzzle pThousand(1000);
  cout << "\nTest case, Assignment Operator: same members, same size, different pointers (deep copy):" << endl;
  if(tester.testAssignmentOperator(pThousand) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }

  //test the edge case, object with 1 member                                   
  cout << "\nTest case, Assignment Operator: 1 member:" << endl;
  Puzzle pOne(1);
  if(tester.testAssignmentOperator(pOne) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }
  
  //test the edge case, 0 member, i.e. empty object                            
  cout << "\nTest case, Assignment Operator: zero members:" << endl;
  Puzzle pZero(0);
  if(tester.testAssignmentOperator(pZero) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }

  //test the user error case, creating object with table zise less than 0   
  cout << "\nTest case, Assignment Operator: table size less than 0:" << endl;
  Puzzle pTen(-10);
  if(tester.testAssignmentOperator(pTen) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }
    
  //TESTING CONSTRUCTOR AHHHH
  int p5(-5);
  cout << "Testing the constructor with a size of -5" << endl;
  if(tester.testConstructor(p5) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }
  
  int pZero1(0);
  cout << "Testing the constructor with a size of 0" << endl;
  if(tester.testConstructor(pZero1) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }

  int pOne1(1);
  cout << "Testing the constructor with a size of 1" << endl;
  if(tester.testConstructor(pOne1) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }

  int pTen1(10);
  cout << "Testing the constructor with a size of 10" << endl;
  if(tester.testConstructor(pTen1) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }

  int pThou(1000);
  cout << "Testing the constructor with a size of 1000" << endl;
  if(tester.testConstructor(pThou) == true){
    cout << "Test passed!" << endl;
  }else{
    cout << "Test failed!" << endl;
  }
  return 0;
}

//testing for the copy constructor
bool Tester::testCopyConstructor(const Puzzle& puzzle){
  Puzzle copy(puzzle);
  //the case of empty object                                                  
  if (puzzle.m_size == 0 && copy.m_size == 0){
    return true;
  }
  
  //the case that sizes are the same and the table pointers are not the same  
  else if (puzzle.m_size == copy.m_size && puzzle.m_table != copy.m_table){
    for (int i=0;i<puzzle.m_size;i++){
      for (int j=0;j<puzzle.m_size;j++){
	if ((puzzle.m_table[i][j] != copy.m_table[i][j]) || //check the value
	      (puzzle.m_table[i] == copy.m_table[i])){//check the ith pointer  
	    return false;
	}
      }
    }
    return true;
  }
  //anything else                                                            
  else{
    return false;
  }
}

//testing the running time for the copy constructor (driver.cpp)
void Tester::measureInsertionTime(int numTrials, int N){
 //Measuring the efficiency of insertion algorithm with system clock ticks   
 //Clock ticks are units of time of a constant but system-specific length, as  those returned by function clock().                                           
//Dividing a count of clock ticks by CLOCKS_PER_SEC yields the number of seconds.                                                                          
  Puzzle puzzle; //puzzle object 
  const int a = 2;//scaling factor for input size                            
  double T = 0.0;//to store running times                                    
  clock_t start, stop;//stores the clock ticks while running the program
  
  for (int i = 0; i < numTrials - 1; i++){
    Puzzle p1(N);//the algorithm to be analyzed for efficiency
    start = clock();
    Puzzle copy(puzzle); //timing the copy constructor
    stop = clock();
    T = stop - start;//number of clock ticks the algorithm took             
    cout << "Inserting " << N * N << " members took " << T << " clock ticks\
 ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
    N = N * a;//increase the input size by the scaling factor               
  }
}

//testing the assignment operator
bool Tester::testAssignmentOperator(const Puzzle& rhs){
  Puzzle assign(rhs);
  //the case of empty object                                                   
  if (rhs.m_size == 0 && assign.m_size == 0){
    return true;
  }
  
  //the case that sizes are the same and the table pointers are not the same   
  else if (rhs.m_size == assign.m_size && rhs.m_table != assign.m_table){
    for (int i = 0; i < rhs.m_size; i++){
      for (int j = 0; j < rhs.m_size; j++){
        if ((rhs.m_table[i][j] != assign.m_table[i][j]) || //check the value  
	    (rhs.m_table[i] == assign.m_table[i])){//check the ith pointer
	  return false;
        }
      }
    }
    return true;
  }
  else{
    return false;
  }
}


bool Tester::testConstructor(int size){
  //testing to make sure if the size is less than 0, m_size is set to 0
  Puzzle puzzle;
  if(size < 0 && puzzle.m_size != 0){
      return false;
  }else{
    return true;
  }
}
