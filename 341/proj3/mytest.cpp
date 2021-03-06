/* File: mytest.cpp                                                            
 * Project: proj3    
 * Author:  Sumaa Sayed                                                        
 * Date: 4/09/2021                                                             
 * Section: 01                                                                 
 * Email: ssayed1@gl.umbc.edu                                                  
 * This is the tester class for proj3.                                         
 */

#include "rqueue.h"
using namespace std;

class Tester{
public:
  bool RQueueCopyConstructor(const RQueue &queue);
  bool RQueueAssignOperator(const RQueue &rhs);
  void RQueuePerformance(int numTrials, int N, RQueue &queue); 
  bool RQueuePriority(RQueue &queue1, RQueue &queue2);
  bool RQueueDequeue(RQueue &queue); 
  void RQueueSetPriority(RQueue &queue);
};
//priority function prototypes
int priorityFn1(const Student&student);
int priorityFn2(const Student&student);

int priorityFn1(const Student&student) {
//priority value is determined based on some criteria, value is between 0-6    
  //the smaller value means the higher priority                                
  int priority = student.getYear() + student.getMajor() + student.getGroup();
  return priority;
}

int priorityFn2(const Student&student) {
//priority is determined by officer in registrar office, value is between 0-6
//the smaller value means the higher priority                                
  return student.getPriority();
}

int main(){
  Tester tester;
  
  //slightly bigger but also small-ish queue
  RQueue queue1(priorityFn1); //takes in a priority function
  Student student1("Violet", 1, 0, 2, 0);
  Student student2("Liz",5,1,2,0);
  Student student3("Nick",2,0,0,0);
  Student student4("Eva",4,3,2,1);
  Student student5("John",6,3,2,1);
  
  queue1.insertStudent(student1);
  queue1.insertStudent(student2);
  queue1.insertStudent(student3);
  queue1.insertStudent(student4);
  queue1.insertStudent(student5);
  cout << "queue1:" << endl;
  queue1.printStudentQueue();
  
  //small queue
  RQueue queue2(priorityFn2);
  Student student6("Mia",3,0,0,0);
  queue2.insertStudent(student6);
  cout << "queue2:" << endl;
  queue2.printStudentQueue();
  
  //empty queue
  RQueue queue3(priorityFn2);
  cout << "queue3:" << endl;
  queue3.printStudentQueue();
  
  cout << "\nTesting RQueue Copy Constructor" << endl;
  if(tester.RQueueCopyConstructor(queue1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueueCopyConstructor(queue2) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueueCopyConstructor(queue3) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  
  
  cout << "\nTesting RQueue Assignment Operator" << endl;
  if(tester.RQueueAssignOperator(queue1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueueAssignOperator(queue2) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueueAssignOperator(queue3) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  
  cout << "\nTesting RQueue inseriton efficiency" << endl;
  int M = 5;
  int N = 1000;
  tester.RQueuePerformance(M, N, queue1);

  cout << "\nTesting RQueue Priority" << endl;
  if(tester.RQueuePriority(queue1, queue2) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  if(tester.RQueuePriority(queue2, queue1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueuePriority(queue1, queue3) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueuePriority(queue3, queue1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  cout << "\nTesting setPriority" << endl;
  tester.RQueueSetPriority(queue1);
  cout << "Queue1 (5 students) after changing priorities" << endl;
  queue1.printStudentQueue();

  tester.RQueueSetPriority(queue2);
  cout << "Queue2 (1 student) after changing priorities" << endl;
  queue2.printStudentQueue();

  tester.RQueueSetPriority(queue3);
  cout << "Queue3 (0 students) after changing priorities" << endl;
  queue3.printStudentQueue();
  
  cout << "\nTesting RQueue empty queue" << endl;
  if(tester.RQueueDequeue(queue1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueueDequeue(queue2) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.RQueueDequeue(queue3) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

}

//testing correctness of copy contructor
bool Tester::RQueueCopyConstructor(const RQueue &queue){
  RQueue copy(queue);
  
  //if copied queue is the same size
  if(queue.numStudents() == copy.numStudents()){
    return true;
  }
  
  //sizes are same, heaps are different...?
  else if(queue.numStudents() == copy.numStudents() && queue._heap != copy._heap){
    if(true){
      return true;
    }else{
      return false;
    }
  }
  
  //anything else
  return false;
}

//testing correctness of assignment operator
bool Tester::RQueueAssignOperator(const RQueue &rhs){
  RQueue assign(rhs.getPriorityFn()); //???
  assign = rhs;
  Node* node = assign._heap;
  assign = assign;

  //deep copy check
  if(node != assign._heap){
    return false;
  }

  //empty object
  if(assign.numStudents() == 0 && rhs.numStudents() == 0){
    return true;
  }

  //self-assign test                                                           
  if(assign._heap == rhs._heap){
    return false;
  }
  
  //the case that sizes are the same and the pointers are not the same   
  else if(assign._size == rhs._size && assign._heap != rhs._heap){
    if(true){
      return true;
    }else{
      return false;
    }
  }
  
  //everthing else
  return false;
}

void Tester::RQueuePerformance(int numTrials, int N, RQueue &queue1){
//Measuring the efficiency of insertion algorithm with system clock ticks   
//Clock ticks are units of time of a constant but system-specific length, as 
// those returned by function clock().                                       
//Dividing a count of clock ticks by CLOCKS_PER_SEC =  the number of seconds.  
  const int a = 2;//scaling factor for input size                              
  double T = 0.0;//to store running times                                      
  clock_t start, stop;//stores the clock ticks while running the program
  int ranPrio = (rand() % MAXPRIO) + MINPRIO; //value from 0-6 for priority
  for (int i = 0; i < numTrials; i++){
    RQueue queue1(priorityFn1);//the algorithm to be analyzed for efficiency 
    start = clock();
    for(int j = 0; j < N; j++){
      Student student("", ranPrio, 1, 1, 1);
      queue1.insertStudent(student);
    }
      stop = clock();
    T = stop - start;//number of clock ticks the algorithm took                
    cout << "Inserting " << N * N << " members took " << T << " clock ticks (" << T/CLOCKS_PER_SEC << " seconds)!" << endl;
    N = N * a;//increase the input size by the scaling factor                  
  }
}

//testing for queues that have different priorities,and trying to merge them 
bool Tester::RQueuePriority(RQueue &queue1, RQueue &queue2){
  
  //queues have different priority values! 
  try{
    queue1.mergeWithQueue(queue2);
  }
  
  catch(domain_error &e){
    //the exception that we expect                                             
    return true;
  }
  catch(...){
    //any other exception, this case is not acceptable                         
    return false;
  }
  //no exception thrown, this case is not acceptable                           
  return false;
}

//trying to deqeue an empty queue
bool Tester::RQueueDequeue(RQueue &queue){
  int size = queue.numStudents();
  
  for(int i = 0; i < size; i++){
    queue.getNextStudent();
  }
  
  try{
    queue.getNextStudent();
  }
  
  catch(domain_error &e){
    //the exception that we expect                                             
    return true;
  }
  catch(...){
    //any other exception, this case is not acceptable                         
    return false;
  }
  //no exception thrown, this case is not acceptable                           
  return false;
}

//testing setPriority function
void Tester::RQueueSetPriority(RQueue &queue){
  cout << "Queue before changing priorities" << endl;
  queue.printStudentQueue();
  
  if(queue.getPriorityFn() == priorityFn1){
    queue.setPriorityFn(priorityFn2);
  }
  else{
    queue.setPriorityFn(priorityFn1);
  }
}
