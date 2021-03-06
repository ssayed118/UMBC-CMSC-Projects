/* File: mytest.cpp                                                            
 * Project: proj1                                                              
 * Author:  Sumaa Sayed                                                        
 * Date: 2/25/2021                                                             
 * Section: 01                                                                 
 * Email: ssayed1@gl.umbc.edu                                                  
 * This is the tester class for proj1.                                         
 */
#include "bufferlist.h"
class Tester{
    public:
    bool BufferEnqueueDequeue(Buffer &buffer, int dataCount);
    bool BufferEnqueueFull(int size);
    bool BufferCopyConstructor(const Buffer &buffer);
    void BufListEnqueuePerformance(int numTrials, int N);
    bool BufListCopyConstructor(const BufferList &buffer);
    bool BufListAssignOperator(const BufferList & rhs);
    bool BufListEnqueueDequeue(int size);
};

int main(){
  Tester tester;
  int bufferSize = 1000;
  Buffer buffer(bufferSize);
  
  //TESTING BUFFER: ENQUEUE + DEQUEUE
  cout << "\nTesting Buffer class: enqueue and dequeue:\n";

  if(tester.BufferEnqueueDequeue(buffer, -1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferEnqueueDequeue(buffer, 0) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferEnqueueDequeue(buffer, 1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferEnqueueDequeue(buffer, 10) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferEnqueueDequeue(buffer, 100) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferEnqueueDequeue(buffer, 1000) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  //TESTING BUFFER: ENQUEUE-FULL
  cout << "\nTest case: Buffer class: Throwing exception while inserting in full buffer:\n";
  if (tester.BufferEnqueueFull(0) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufferEnqueueFull(1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufferEnqueueFull(10) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufferEnqueueFull(100) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufferEnqueueFull(1000) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  //TESTING BUFFER: COPY CONSTRUCTOR
  cout << "Testing Buffer class: copy constructor:\n";
  if(tester.BufferCopyConstructor(0) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }  
  if(tester.BufferCopyConstructor(1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferCopyConstructor(10) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferCopyConstructor(100) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if(tester.BufferCopyConstructor(1000) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  
  //TESTING BUFFERLIST: ENQUEUE PERFORMANCE
  int M = 5;//number of trials                                            
  int N = 1000;//original input size                                      
  tester.BufListEnqueuePerformance(M, N);

  //TESTING BUFFERLIST: COPY CONSTRUCTOR
  cout << "Testing BufferList class: copy constructor:\n";
  
  BufferList numN(-1);
  for(int i = 0; i < 2; i++){
    numN.enqueue(i);
  }
  if(tester.BufListCopyConstructor(numN) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  BufferList num0(0);
  for(int i = 0; i < 10; i++){
    num0.enqueue(i);
  }
  if(tester.BufListCopyConstructor(num0) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  BufferList num2(1);
  for(int i = 0; i < 1; i++){
    num2.enqueue(i);
  }
  if(tester.BufListCopyConstructor(num2) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  BufferList num10(10);
  for(int i = 0; i < 10; i++){
    num10.enqueue(i);
  }
  if(tester.BufListCopyConstructor(num10) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  BufferList numTH(1000);
  for(int i = 0; i < 1001; i++){
    numTH.enqueue(i);
  }
  if(tester.BufListCopyConstructor(numTH) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  //TESTING BUFFERLIST: ASSIGNMENT OPERATOR
  cout << "Testing BufferList class: assignment operator:\n";
  //using same bufferlist objects from copy constructor tests
  
  for(int i = 0; i < 2; i++){
    numN.enqueue(i);
  }
  if(tester.BufListAssignOperator(numN) == true){
    cout << "\tTest passed!\n";                                                
  }else{
     cout << "\tTest failed!\n";                                               
  }
  
  for(int i = 0; i < 10; i++){
    num0.enqueue(i);
  }
   if(tester.BufListAssignOperator(num0) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  for(int i = 0; i < 1; i++){
    num2.enqueue(i);
  }
  if(tester.BufListAssignOperator(num2) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  for(int i = 0; i < 10; i++){
    num10.enqueue(i);
  }  
  if(tester.BufListAssignOperator(num10) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  for(int i = 0; i < 1001; i++){
    numTH.enqueue(i);
  }
  if(tester.BufListAssignOperator(numTH) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }

  //TESTING BUFFERLIST: ENQUEUE DEQUEUE
  cout << "Testing BufferList class: enqueue+dequeue:\n";
  
  if (tester.BufListEnqueueDequeue(0) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufListEnqueueDequeue(1) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufListEnqueueDequeue(10) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufListEnqueueDequeue(100) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  if (tester.BufListEnqueueDequeue(1000) == true){
    cout << "\tTest passed!\n";
  }else{
    cout << "\tTest failed!\n";
  }
  return 0;
}

bool Tester::BufferEnqueueDequeue(Buffer &buffer, int dataCount){
  Buffer aBuffer(dataCount);
  for (int i = 0; i < dataCount; i++){
    aBuffer.enqueue(i);
  }
  
  for (int i = 0; i < dataCount; i++){
    aBuffer.dequeue();
  }

  try{
    //calling the dequeu function
    aBuffer.dequeue();
  }
  
  catch(underflow_error &e){ //another exception that is expected
    return true;
  }
  catch(...){
    //any other exception, this case is not acceptable                         
    return false;
  }
  //no exception thrown, this case is not acceptable                           
  return false;
}

bool Tester::BufferEnqueueFull(int size){
  Buffer aBuffer(size);
  for (int i=0;i<size;i++)
    aBuffer.enqueue(i);
  try{
    //trying to insert in a full buffer                                     
    aBuffer.enqueue(size+1);
  }
  catch(overflow_error &e){
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

bool Tester::BufferCopyConstructor(const Buffer &buffer){
   Buffer copy(buffer);
    //the case of empty object                                        
   if (buffer.m_count == 0 && copy.m_count == 0){
     return true;
   }
    //the case that sizes are the same and the table pointers are not the same 
   else if(buffer.m_count == copy.m_count && buffer.m_buffer != copy.m_buffer){
     for (int i=0; i< buffer.m_count; i++){
       if ((buffer.m_buffer[i] != copy.m_buffer[i]) ||//check the value
	   (buffer.m_buffer[i] == copy.m_buffer[i])){ //check the ith pointer
	 return false;
       }
     }
     return true;
   }
   //everthing else                                                            
   else{
     return false;
   }
}

void Tester::BufListEnqueuePerformance(int numTrials, int N){
  //Measuring the efficiency of insertion algorithm with system clock ticks    
  //Clock ticks are units of time of a constant but system-specific length, as 
  // those returned by function clock().                                       
//Dividing a count of clock ticks by CLOCKS_PER_SEC yields the number of seconds.
  // Buffer buffer(); //buffer object                                          
  const int a = 2;//scaling factor for input size                              
  double T = 0.0;//to store running times                                      
  clock_t start, stop;//stores the clock ticks while running the program       
  for (int i = 0; i < numTrials; i++){
    Buffer b1(N);//the algorithm to be analyzed for efficiency                 
    start = clock();
    Buffer enqueue(b1); //timing enqueue
    stop = clock();
    T = stop - start;//number of clock ticks the algorithm took                
    cout << "Inserting " << N * N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
    N = N * a;//increase the input size by the scaling factor                  
  }
}

bool Tester::BufListCopyConstructor(const BufferList & buffer){
   BufferList copy(buffer);
    //the case of empty object                                                 
   if (buffer.m_listSize == 0 && copy.m_listSize == 0){
     return true;
   }

   if(copy.m_cursor == buffer.m_cursor){
    return false;
  }
    //the case that sizes are the same and the table pointers are not the same 
  else if(copy.m_listSize == buffer.m_listSize && copy.m_cursor != buffer.m_cursor){
    if(true){
      return true;
    }else{
      return false;
    }
  }
   
   //everthing else                                                            
  else{
    return false;
   }
   
   //the case that sizes are the same and the table pointers are not the same 
   /*  else if(buffer.m_listSize == copy.m_listSize && buffer.m_cursor != copy.m_cursor){
       for (int i=0;i< buffer.m_listSize;i++){
       if ((buffer.m_cursor[i] != copy.m_cursor[i]) ||//check the value        
       (buffer.m_cursor[i] == copy.m_cursor[i])){ //check the ith pointer  
       return false;
       }
       }
     return true;
     }*/ 
}

bool Tester::BufListAssignOperator(const BufferList & rhs){
  BufferList copy(0);
  copy = rhs;
  Buffer * copyAdd = copy.m_cursor;
  copy = copy;

  //check for deep copy
  if(copyAdd != copy.m_cursor){
    return false;
  }

  //checking for self assign
  if(copy.m_cursor == rhs.m_cursor){
    return false;
  }
  
    //the case of empty object                                                 
  if (copy.m_listSize == 0 && rhs.m_listSize == 0){
    return true;
  }
  
  //the case that sizes are the same and the table pointers are not the same 
  else if(copy.m_listSize == rhs.m_listSize && copy.m_cursor != rhs.m_cursor){ 
    if(true){
      return true;
    }else{
      return false;
    }
  }
  
  //everthing else                                                           
  else{
    return false;
  }
}

bool Tester::BufListEnqueueDequeue(int size){
  BufferList aBuffer(size);

  //enqueuing and dequeing the list
  for (int i=0; i< size; i++){
    aBuffer.enqueue(i);
  }
  
  for (int i=0; i< size; i++){
    aBuffer.dequeue();
  }
 
  try{
    //trying to remove in an empty buffer                         
    aBuffer.dequeue();
  }
  catch(underflow_error &e){
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

/*hi i just wanted to say that i had submitted my proj on tuesday, wednesday,  and today. i had a ton of memory leaks in yesterdays submission, but not
my first one so not sure if that makes any difference */
