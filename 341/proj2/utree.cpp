/**
 * CMSC 341 - Spring 2021
 * Project 2 - Binary Trees
 * UserTree.h
 * Implementation for the UTree class.
 */

#include "utree.h"

/**
 * Destructor, deletes all dynamic memory.
 */
UTree::~UTree() {
  clear();
}

/**
 * Sources a .csv file to populate Account objects and insert them into the UTree.
 * @param infile path to .csv file containing database of accounts
 * @param append true to append to an existing tree structure or false to clear before importing
 */ 
void UTree::loadData(string infile, bool append) {
  std::ifstream instream(infile);
  string line;
  char delim = ',';
  const int numFields = 5;
  string fields[numFields];
  
  /* Check to make sure the file was opened */
  if(!instream.is_open()) {
    std::cerr << __FUNCTION__ << ": File " << infile << " could not be opened or located" << endl;
    exit(-1);
  }
  
  /* Should we append or clear? */
  if(!append) this->clear();
  
  /* Read in the data from the .csv file and insert into the UTree */
  while(std::getline(instream, line)) {
    std::stringstream buffer(line);
    
        /* Quick check to make sure each line is formatted correctly */
    int delimCount = 0;
    for(unsigned int c = 0; c < buffer.str().length(); c++) if(buffer.str()[c] == delim) delimCount++;
    if(delimCount != numFields - 1) {
      throw std::invalid_argument("Malformed input file detected - ensure each line contains 5 fields deliminated by a ','");
    }
    
    /* Populate the account attributes - 
         * Each line always has 5 sections of data */
    for(int i = 0; i < numFields; i++) {
      std::getline(buffer, line, delim);
      fields[i] = line;
    }
    Account newAcct = Account(fields[0], std::stoi(fields[1]), std::stoi(fields[2]), fields[3], fields[4]);
    this->insert(newAcct);
  }
}

/**
 * Dynamically allocates a new UNode in the tree and passes insertion into DTree. 
 * Should also update heights and detect imbalances in the traversal path after
 * an insertion.
 * @param newAcct Account object to be inserted into the corresponding DTree
 * @return true if the account was inserted, false otherwise
 */
bool UTree::insert(Account newAcct) {
  UNode* curr = _root; 
  bool temp = insertHelper(curr, newAcct.getUsername(), newAcct);
 
  return temp;
}

bool UTree::insertHelper(UNode*& node, string username, Account newAcct){
  //loops through to find the matching username of the given node
  bool temp;
  if(node == nullptr){
    node = new UNode();
    temp = node->_dtree->insert(newAcct);
    return true;
    // return node;
  }

  if(node->getUsername() < username){
    // updateHeight(node->_left);
    temp = insertHelper(node->_left, username, newAcct);
    updateHeight(node->_left);
    if(checkImbalance(node) != 0){
      rebalance(node);
    }
  }
  
  else if(node->getUsername() > username){
    // updateHeight(node->_right);
    temp = insertHelper(node->_right, username, newAcct);
    updateHeight(node->_right);
    if(checkImbalance(node) != 0){
      rebalance(node);
    }
  }
  else{
    temp = node->_dtree->insert(newAcct);
    return temp;
  }
  return temp;
}
/**
 * Removes a user with a matching username and discriminator.
 * @param username username to match
 * @param disc discriminator to match
 * @param removed DNode object to hold removed account
 * @return true if an account was removed, false otherwise
 */
bool UTree::removeUser(string username, int disc, DNode*& removed) {
  UNode* curr = _root;
  return removeHelper(curr, disc, username, removed);
  //
  bool temp = removeHelpTwo(curr, curr->_left);

}

bool UTree::removeHelper(UNode*& node, int disc, string user, DNode*& removed){
  //loops through to find the matching username of the given node
  bool temp2;
  if(node == nullptr){
    return false;
  }
  if(node->_dtree->getNumUsers() == 0){
    bool temp = removeHelpTwo(node, node->_left);
    if(temp == true){
      node = nullptr;
    }
  }
  
  if(node->getUsername() > user){
    updateHeight(node->_left);
    temp2 = removeHelper(node->_left, disc, user, removed);
  }

  else if(node->getUsername() < user){
    updateHeight(node->_right);
    temp2 = removeHelper(node->_right, disc, user, removed);
  }

  //updates height and rebalances if needed
  updateHeight(node);
  if(checkImbalance(node) != 0){
    rebalance(node);
  }
  return temp2;
}

bool UTree::removeHelpTwo(UNode* node, UNode* temp){
  //looping through to find the node to replace the deleted one with
  if(temp == nullptr){
    if(node->_right == nullptr){
      delete node;
      return true;
    }
    if(node->_left == nullptr && node->_right != nullptr){
      *node->_dtree = *node->_right->_dtree;
      delete node->_right;
      node->_right = nullptr;
    }
    return false;
  }
  else if(temp->_right != nullptr){
    if(removeHelpTwo(node, temp->_right) == true){
      temp->_right = nullptr;
      updateHeight(node);
      if(checkImbalance(node) != 0){
	rebalance(node);
      }
      return false;
    }
    return true;
  }
  else{
    *node->_dtree = *temp->_dtree;
    if(temp->_left != nullptr){
      *temp->_dtree = *temp->_left->_dtree;
      delete temp->_left;
      temp->_left = nullptr;
      return false;
    }
    else{
      delete temp;
      return true;
    }
  //else if(node->_left == nullptr && node->_right == nullptr){
  }
}
/**
   * Retrieves a set of users within a UNode.
 * @param username username to match
 * @return UNode with a matching username, nullptr otherwise
 */
UNode* UTree::retrieve(string username) {
  UNode* curr = _root;
  
  //finding node with the username given
  if(curr != nullptr){
    curr = this->_root;
    while(curr != nullptr){
      if(username == curr->getUsername()){ //curr == nullptr){
	return curr;
      }
      else if(username < curr->getUsername()){
	curr = curr->_left;
      }
      else{
	curr = curr->_right;
      }
    }
    return curr;
  }
  return nullptr;
} 

/**
 * Retrieves the specified Account within a DNode.
 * @param username username to match
 * @param disc discriminator to match
 * @return DNode with a matching username and discriminator, nullptr otherwise
 */
DNode* UTree::retrieveUser(string username, int disc) {
  UNode* temp = retrieve(username);
  DNode* curr = temp->_dtree->retrieve(disc);
  if(curr != nullptr && temp != nullptr){
    return curr; 
  }
  else{
    return nullptr;
  }
}
/**
 * Returns the number of users with a specific username.
 * @param username username to match
 * @return number of users with the specified username
 */
int UTree::numUsers(string username){
  int count = 0;
  UNode* temp = _root;
  for(int i = 0; i < temp->_dtree->getNumUsers(); i++){
    if(temp->getUsername() == username){
      count ++;
      temp = temp->_left;
    }
    temp = temp->_right;
  }
  return count;
}

/**
 * Helper for the destructor to clear dynamic memory.
 */
void UTree::clear() {
  UNode* curr = _root;
  clearHelper(curr);  
}
 
//clear helper - deletes nodes
void UTree::clearHelper(UNode* node){
  if(node == nullptr){
    return;
  }
  else{
    clearHelper(node->_left);
    clearHelper(node->_right);
  }
  delete node;
}
/**
 * Prints all accounts' details within every DTree.
 */
void UTree::printUsers() const {
  UNode* node = _root;
  printHelper(node);
}

//print helper that will print account details                              
void UTree::printHelper(UNode* node) const{
  if(node != nullptr){
    node->_dtree->printAccounts();
    printHelper(node->_left);
    printHelper(node->_right);
  }
}
/**
 * Dumps the UTree in the '()' notation.
 */
void UTree::dump(UNode* node) const {
    if(node == nullptr) return;
    cout << "(";
    dump(node->_left);
    cout << node->getUsername() << ":" << node->getHeight() << ":" << node->getDTree()->getNumUsers();
    dump(node->_right);
    cout << ")";
}

/**
 * Updates the height of the specified node.
 * @param node UNode object in which the height will be updated
 */
void UTree::updateHeight(UNode* node) {
  if(node != nullptr){
    if(node->_right->getHeight() > node->_left->getHeight()){
      node->_height = node->_right->getHeight() + 1;
    }
    else{
      node->_height = node->_left->getHeight() + 1;
    }
  }
}
/**
 * Checks for an imbalance, defined by AVL rules, at the specified node.
 * @param node UNode object to inspect for an imbalance
 * @return (can change) returns true if an imbalance occured, false otherwise
 */
int UTree::checkImbalance(UNode* node) {
  if(node!= nullptr){
    return node->_left->getHeight() - node->_right->getHeight();
  }
  return 0;
} 
  /*
  if(node->_right->getHeight() + 1 > node->_left->getHeight() + 1){ //check
    return 1;
    //return true;
  }
  else if(node->_right->getHeight() + 1 < node->_left->getHeight() + 1){
    return 1;
    //return true;
  }
  else{
    return 0;
    //return false;
    }*/

//----------------
/**
 * Begins and manages the rebalance procedure for an AVL tree (pass by reference).
 * @param node UNode object where an imbalance occurred
 */
void UTree::rebalance(UNode*& node) {  
  int balance = checkImbalance(node);
  //left left case
  if(checkImbalance(node->_left) >= 0 && balance > 1){
    node = rightRotation(node);
  }
  
  //right right case
  if(checkImbalance(node->_right) <= 0 && balance < -1){
    //node->_left = leftRotation(node->_left);
    node = leftRotation(node);
  }
  
  //left right case
  if(checkImbalance(node->_left) < 0  && balance > 1){ 
    node->_left = leftRotation(node->_left);
    node = rightRotation(node);
  }
  
  //right left
  if(checkImbalance(node->_right) > 0 && balance < -1){ 
    node->_right = rightRotation(node->_right);
    node = leftRotation(node);
  }
}

UNode* UTree::rightRotation(UNode* node){ //rotate right
  UNode* left = node->_left;
  UNode* right = node->_right;
  
  left->_right = node;
  node->_left = left->_right;

  updateHeight(node);
  updateHeight(left);

  return left;
}

UNode* UTree::leftRotation(UNode* node){ //rotate left
  UNode* right = node->_right;
  UNode* left = node->_left;

  right->_left = node;
  node->_right = right->_left;

  updateHeight(node);
  updateHeight(right);

  return right;
}

//--------fin
