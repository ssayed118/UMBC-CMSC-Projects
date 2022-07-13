/**
 * CMSC 341 - Spring 2021
 * Project 2 - Binary Trees
 * DiscriminatorTree.cpp
 * Implementation for the DTree class.
 */

#include "dtree.h"

/**
 * Destructor, deletes all dynamic memory.
 */
DTree::~DTree() {
  clear();
 }

/**
 * Overloaded assignment operator, makes a deep copy of a DTree.
 * @param rhs Source DTree to copy
 * @return Deep copy of rhs
 */
DTree& DTree::operator=(const DTree& rhs) {
  if(this != &rhs){
    clear();
    _root = AssignmentOperatorHelper(rhs._root);
    _root->_left = AssignmentOperatorHelper(rhs._root->_left);
    _root->_right = AssignmentOperatorHelper(rhs._root->_right);
    // _root = AssignmentOperatorHelper(rhs._root);
  }
  return *this;
}

DNode* DTree::AssignmentOperatorHelper(DNode* node){
  DNode* temp = nullptr;;
  if(node != nullptr){
    temp = node;
    temp->_left = AssignmentOperatorHelper(temp->_left); //is this right?   
    temp->_right = AssignmentOperatorHelper(temp->_right);
  }
  return node;                                                                 
}

/**
 * Dynamically allocates a new DNode in the tree. 
 * Should also update heights and detect imbalances in the traversal path
 * an insertion.
 * @param newAcct Account object to be contained within the new DNode
 * @return true if the account was inserted, false otherwise
 */
bool DTree::insert(Account newAcct) {
  DNode* curr = _root;
  DNode* trailCurr = nullptr;
  DNode*temp = new DNode(newAcct); //hold info

  //insert temp into correct spot
  if(curr == nullptr){
    curr = temp;
    updateNumVacant(curr);
    updateSize(curr);
    if(checkImbalance(curr) == true){
      rebalance(curr);
    }
    _root = curr;
    return true;
  }
  
  else{
    curr = this->_root;
    while(curr != nullptr){
      trailCurr = curr;
      
      if(curr->getDiscriminator() == newAcct._disc){
	delete temp;
	return false; 
      }
      
      else if(curr->getDiscriminator() > newAcct._disc){
	curr = curr->_left;
      }
      else{
	curr = curr->_right;
      }
    }
    
    if(trailCurr->getDiscriminator() > newAcct._disc){
      trailCurr->_left = temp;
      updateNumVacant(temp);
      updateSize(temp);
      if(checkImbalance(temp) == true){
	rebalance(temp);
      }
      return true;
    }
    else{
      trailCurr->_right = temp;
      updateNumVacant(temp);
      updateSize(temp);
      if(checkImbalance(temp) == true){
        rebalance(temp);
      }
      return true;
    }
    return true;
  }
  return false;    
}

/**
 * Removes the specified DNode from the tree.
 * @param disc discriminator to match
 * @param removed DNode object to hold removed account
 * @return true if an account was removed, false otherwise
 */
bool DTree::remove(int disc, DNode*& removed) {
  DNode* curr = _root;
  curr = removeHelper(disc, removed, curr);

  if(curr != nullptr){
    if(curr->_vacant == true){
      removed = curr;
      removed->_vacant = true;
      removeHelper(disc, removed, curr);
      // updateNumVacant(removed);
      //updateSize(removed);
      return true;
    }
    return false;
  }
  return false;
}

DNode* DTree::removeHelper(int disc, DNode*& removed, DNode* node){
  //loops through to find the matching username of the given node              
  if(node == nullptr){
    return nullptr;
  }
    
  if(node->getDiscriminator() > disc){
    node->_left = removeHelper(disc, removed, node->_left);
    updateNumVacant(node->_left);
    updateSize(node->_left);
  }

  else if(node->getDiscriminator() > disc){
    node->_right = removeHelper(disc, removed, node->_right);
    updateNumVacant(node->_right);
    updateSize(node->_right);
  }
  return node;  
}

/**
 * Retrieves the specified Account within a DNode.
 * @param disc discriminator int to search for
 * @return DNode with a matching discriminator, nullptr otherwise
 */
DNode* DTree::retrieve(int disc) {
  DNode* curr = _root;
  if(curr != nullptr){
    curr = this->_root;
    while(curr != nullptr){
      
      if(disc == curr->getDiscriminator()){
	return curr;
      }
      else if(disc < curr->getDiscriminator()){
	curr = curr->_left;
      }
      else{
	curr = curr->_right;
      }
    }
  }
  return nullptr;
}
/**
 * Helper for the destructor to clear dynamic memory.
 */
void DTree::clear() {
  DNode* curr = _root;
  clearHelper(curr);
}

//clear helper - deletes nodes
void DTree::clearHelper(DNode*& node){
  if(node == nullptr){
    return;
  }
  clearHelper(node->_left);
  clearHelper(node->_right);
  delete node;
  node = nullptr;
}
/**
 * Prints all accounts' details within the DTree.
 */
void DTree::printAccounts() const {
  DNode* node = _root;
  printHelper(node);
}

//print helper - prints acocunts
void DTree::printHelper(DNode* curr) const{ 
  if(curr != nullptr){
    cout << curr->_account << endl;
    if(curr->_vacant != true){
      printHelper(curr->_left);
      printHelper(curr->_right);
    }
  }
}
/**
 * Dump the DTree in the '()' notation.
 */
void DTree::dump(DNode* node) const {
  if(node == nullptr) return;
  cout << "(";
  dump(node->_left);
  cout << node->getAccount().getDiscriminator() << ":" << node->getSize() << ":" << node->getNumVacant();
  dump(node->_right);
  cout << ")";
}

/**
 * Returns the number of valid users in the tree.
 * @return number of non-vacant nodes
 */
int DTree::getNumUsers() const {
  int count = _root->_size - _root->_numVacant;
  return count; 
} 

/**
 * Updates the size of a node based on the imedaite children's sizes
 * @param node DNode object in which the size will be updated
 */
void DTree::updateSize(DNode* node) {
  if(node != nullptr){
    updateSize(node->_left);
    updateSize(node->_right);
    
    if(node->_left != nullptr){
      node->_size += node->_left->_size;
    }
    if(node->_right != nullptr){
      node->_size += node->_right->_size;
    }
    if(node->_left == nullptr && node->_right == nullptr){
      node->_size++;
    }
    else{
      node->_size++;
    }
  }
}

 /**
 * Updates the number of vacant nodes in a node's subtree based on the immediate children
 * @param node DNode object in which the number of vacant nodes in the subtree will be updated
 */
void DTree::updateNumVacant(DNode* node) {
  if(node != nullptr){
    if(node->_vacant == true){
      node->_numVacant ++;
    }
    if(node->_left != nullptr){
      node->_left->isVacant() == true;
      node->_numVacant ++;
    }
    if(node->_right != nullptr){
      node->_right->isVacant() == true;
      node->_numVacant ++;
    }
    updateNumVacant(node->_left);
    updateNumVacant(node->_right);
  }  
}

/**
 * Checks for an imbalance, defined by 'Discord' rules, at the specified node.
 * @param checkImbalance DNode object to inspect for an imbalance
 * @return (can change) returns true if an imbalance occured, false otherwise
 */
bool DTree::checkImbalance(DNode* node) {
  //checking imabalcnes at nodes children
  if(node != nullptr && node->_right != nullptr && node->_left != nullptr){
    if(node->_right->_size < 4 && node->_left->_size < 4){
      return false;
    } 
    if(node->_right->_size >= (1.5 * node->_left->_size)){
      return true;
    }
    else if(node->_left->_size >= (1.5 * node->_right->_size)){ 
      return true;
    }
    if((node->_left->_size >= 4) || (node->_right->_size >= 4)){
      return true;
    }
  }
  return false;
}

//----------------
/**
 * Begins and manages the rebalancing process for a 'Discrd' tree (pass by reference).
 * @param node DNode root of the subtree to balance
 */
void DTree::rebalance(DNode*& node) {
  int count = node->_size - node->_numVacant;
  DNode* array[count];
 
  balanceHelper(node, array, count);
 
  //array to sub tree
  int beggining = array[0]->getDiscriminator();;
  int last = array[count]->getDiscriminator();;
  DNode* current = balanceHelpTwo(array, beggining, last);
   
  //make sure its balanced then delete
  // if(checkImbalance(node) == false){
  // delete[] array;
  // }
  //preorder traversal of tree to fill array
}

//1st balance helper --tree to array, do an inorder traversal and create array
void DTree::balanceHelper(DNode* node, DNode* array[], int &count){
  //pass in array + count    //DTree* array[getNumUsers()];   
  //in order traverse - recursion
   if(node != nullptr){
    balanceHelper(node->_left, array, count);
    if(node->_vacant == false){
      array[count] = node;
      count++;
    }
    // else{
    balanceHelper(node->_right, array, count);
    
    //delink
    node->_right = nullptr;
    node->_left = nullptr;
  }
  if(node->_vacant == true){
    delete node;
  }
}

//2nd balance helper -- array to subtree [take in array + count
DNode* DTree::balanceHelpTwo(DNode* array[], int start, int end){
  if(start > end){
    return nullptr;
  }
  int middle = (start + end)/2; //might have to add the counter and %
   DNode* temp = array[middle];

  temp->_left = balanceHelpTwo(array, start, middle - 1);
  temp->_right = balanceHelpTwo(array, middle + 1, end);

  return temp;
   //preorder traversal                                                     
    //divide array, alloacting node                                         
    //like regular array, left and right                                 
}

//----------------

/**
 * Overloaded << operator for an Account to print out the account details
 * @param sout ostream object
 * @param acct Account objec to print
 * @return ostream object containing stream of account details
 */
ostream& operator<<(ostream& sout, const Account& acct) {
  sout << "Account name: " << acct.getUsername() << 
    "\n\tDiscriminator: " << acct.getDiscriminator() <<
    "\n\tNitro: " << acct.hasNitro() << 
    "\n\tBadge: " << acct.getBadge() << 
    "\n\tStatus: " << acct.getStatus();
  return sout;
}

