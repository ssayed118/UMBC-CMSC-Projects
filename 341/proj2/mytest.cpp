#include "utree.h"
#include "dtree.h"

//dtree: balanced, bst property is preserved
//utree: balance, bst property is preserved 

#include <random>
#define NUMACCTS 20
#define RANDDISC (distAcct(rng))

std::mt19937 rng(10);
std::uniform_int_distribution<> distAcct(0, 9999);

class Tester {
public:
  bool testBasicDTreeInsert(DTree& dtree);
  bool DTreeAssignOperator(const DTree& rhs);
  bool testDTreeBalance(DTree& dtree, DNode* node);
  bool testDTreeRemove(DTree& dtree, DNode* node);
  
  bool testBasicUTreeInsert(UTree& utree);
  bool testUTreeBalance(UTree& utree, UNode* node);
  bool testUTreeRemove(UTree& utree, UNode* node, DNode* removed);
};

int main() {
  Tester tester;
  
  /* Basic dtree tests */
  DTree dtree;
  UTree utree;
  DNode* node;
  DNode* removed;
  UNode* node1;
  // int disc = node1->node->getDiscriminator();
  
  cout << "Testing DTree insertion...";
  if(tester.testBasicDTreeInsert(dtree)) {
    cout << "test passed" << endl;
  } else {
    cout << "test failed" << endl;
  }
  
  cout << "Resulting DTree:" << endl;
  dtree.dump();
  cout << endl;

  //dtree assignment operator test
  cout << "Testing DTree's assignment operator" << endl;
  //  if(tester.DTreeAssignOperator(dtree) == true){
  //cout << "test passed" << endl;
  // }else{
  // cout << "Test failed" << endl;
  // }

  //balance + bst property?
  cout << "testing balance for DTree" << endl;
  if(tester.testDTreeBalance(dtree, node) == true){
    cout << "test passed" << endl;
  } else {
    cout << "test failed" << endl;
  }
  
  //remove for DTree
  cout << "Testing DTree's remove" << endl;
  if(tester.testDTreeRemove(dtree, node) == true){
    cout << "test passed" << endl;
  } else {
    cout << "test failed" << endl;
  }
  
  /* Basic UTree tests */
 
  cout << "\n\nTesting UTree insertion...";
  if(tester.testBasicUTreeInsert(utree)) {
    cout << "test passed" << endl;
    } else {
    cout << "test failed" << endl;
  }
  
  cout << "Resulting UTree:" << endl;
  utree.dump();
  cout << endl;

  //testing balance
  cout << "testing balance for UTree" << endl;
  if(tester.testUTreeBalance(utree, node1) == true){
    cout << "test passed" << endl;
  }else {
    cout << "test failed" << endl;
  }
  
  //remove for UTree
  cout << "Testing UTree removal" << endl;
  //  utree.removeUser("Capstan", 9801, &node);
  if(tester.testUTreeRemove(utree, node1, removed) == true){
    cout << "test passed" << endl;
  } else {
    cout << "test failed" << endl;
  }
  
  cout << "Resulting UTree:" << endl;
  utree.dump();
  cout << endl;
  return 0;
}

bool Tester::testBasicDTreeInsert(DTree& dtree) {
  bool allInserted = true;
  for(int i = 0; i < NUMACCTS; i++) {
    int disc = RANDDISC;
    Account newAcct = Account("", disc, 0, "", "");
    if(!dtree.insert(newAcct)) {
      cout << "Insertion on node " << disc << " did not return true" << endl;
      allInserted = false;
    }
  }
  return allInserted;
}

bool Tester::DTreeAssignOperator(const DTree &rhs){
  DTree copy(rhs);
  copy = rhs;
  DNode *copyAdd = copy._root;
  copy = copy;
  
  //check for deep copy                                                        
  if(copyAdd != copy._root){
    return false;
  }

  //checking for self assign                                                   
  if(copy._root == rhs._root){
    return false;
  }
      //the case of empty object                                             
  //  if(copyAdd == nullptr && rhs == nullptr){
  //  return true;
  // }
  /*
  //the case that sizes are the same and the table pointers are not the same   
  else if(copyAdd._size == rhs._size && copy._root != rhs._root){
    if(true){
      return true;
    }else{
      return false;
    }
    }*/

  //everthing else                                                             
  else{
    return false;
  }
  return true;
}
bool Tester::testDTreeBalance(DTree& dtree, DNode* node){
  if(dtree.checkImbalance(node) == true){
    dtree.rebalance(node);
    if(dtree.checkImbalance(node) == false){
      return true;
    }
    return false;
  }
  else{
    return false;
  }
}

bool Tester::testDTreeRemove(DTree& dtree, DNode* node){
  if(dtree.remove(node->getDiscriminator(), node) == true){
    //if(retrieve(9801) == nullptr){
    return true;
  }
  else{
    return false;
  }
}

bool Tester::testBasicUTreeInsert(UTree& utree) {
  string dataFile = "accounts.csv";
  try {
    utree.loadData(dataFile);
  } catch(std::invalid_argument e) {
    std::cerr << e.what() << endl;
    return false;
  }
  return true;
}

bool Tester::testUTreeBalance(UTree& utree, UNode* node){
  if(utree.checkImbalance(node) == true){
    utree.rebalance(node);
    if(utree.checkImbalance(node) == false){
      return true;
    }
  }
  return false;
}

bool Tester::testUTreeRemove(UTree& utree, UNode* node, DNode* remove){
  if(utree.removeUser(node->getUsername(), remove->getDiscriminator(), remove) == true){
    return true;
  }
  //  else{
  return false;
    // }  
}

//i dont know whats wrong with my code but i had a crazy amount of memory leaking when i run it w driver, and my test had no leaks but a ton of error which was weird as heck. if you happen to find the source of the leakage pls let me know becasue i spent almost 2 hours with a TA and neither of us could figure it out! thanks!! //
