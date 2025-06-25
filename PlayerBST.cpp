// Author: Ishrat Arshad
// Date: May 9, 2025
// File: PlayerBST.cpp
// Description: this file contains the implementation of the PlayerBST class

#include "PlayerBST.hpp"
#include <cmath> 

    /**
     * @brief Default constructor; constructs an empty BST
     * @post The `root_` is set to nullptr & `size_` to 0.
     */
// here this is the default constructor where the root is set to nullptr and size is set to 0
PlayerBST::PlayerBST() : root_(nullptr), size_(0) {}

/**
 * @brief Destructor to clean up all nodes.
 */
PlayerBST::~PlayerBST()
{
    destroyTree(root_);
}

void PlayerBST::destroyTree(Node<ChessPlayer>* node)
{
    if (!node) {
        return;
    }

    destroyTree(node->getLeftChild());
    destroyTree(node->getRightChild());
    delete node;
    node = nullptr;
}

Node<ChessPlayer>* PlayerBST::removeHelper(Node<ChessPlayer>* node, const std::string& name)
{
    if (!node) {
        return nullptr;
    }

    // Traverse the tree to find the node to delete
    if (name < node->getValue().name_) {
        node->setLeftChild(removeHelper(node->getLeftChild(), name));
        return node;
    } else if (name > node->getValue().name_) {
        node->setRightChild(removeHelper(node->getRightChild(), name));
        return node;
    }
    // Node found, handle deletion

    // Case 1: Node with no children (leaf node)
    if (!node->getLeftChild() && !node->getRightChild()) {
        delete node;
        size_--;
        return nullptr;
    }
    // Case 2: Node with only one child
    else if (!node->getLeftChild()) {
        Node<ChessPlayer>* temp = node->getRightChild();
        delete node;
        size_--;
        return temp;
    } else if (node->getRightChild() == nullptr) {
        Node<ChessPlayer>* temp = node->getLeftChild();
        delete node;
        size_--;
        return temp;
    }

    // Case 3: Node with two children
    // Find the inorder successor (smallest node in right subtree)
    Node<ChessPlayer>* successor = node->getRightChild();
    while (successor->getLeftChild() != nullptr) {
        successor = successor->getLeftChild();
    }

    // Copy the successor's value to this node
    node->setValue(successor->getValue());

    // Delete the now-duplicate successor
    node->setRightChild(removeHelper(node->getRightChild(), successor->getValue().name_));

    return node;
}

bool PlayerBST::remove(const std::string& name)
{
    int oldSize = size_;
    root_ = removeHelper(root_, name);
    // If size changed, removal was successful
    return oldSize > size_;
}

// ====== Your code below ======

/**
 * @brief Getter for the `root_` member
 * @returns The a pointer to the root of the PlayerBST, 
 * or nullptr if the tree is empty.
 */
Node<ChessPlayer>* PlayerBST::getRoot() const {
    return root_; // here we return the root
}


/**
 * @brief Getter for the `size_` member
 * @returns The number of Players (ie. nodes) 
 * in the PlayerBST as an integer
 */
int PlayerBST::size() const {
    return size_; // retrun the size
}

/**
 * @brief Inserts a Player into the PlayerBST
 * if a player with their name does NOT already exist.
 *
 * @param value A const. reference to the ChessPlayer to insert
 * @returns True if the player was sucessfully inserted. False otherwise.
 * @post Increments the BST's size if the value was succesfully inserted
 */

 bool PlayerBST::insert(const ChessPlayer& value) {
// check if the player already exists
    if (!root_) {
// if the tree is empty, insert the new value as the root
        root_ = new Node<ChessPlayer>(value);
        size_++; // increase the size
        return true;
    }
// insert the new value using the helper function
    int oSize = size_;
    root_ = insertHelper(root_, value); // recursive helper
    return size_ > oSize;
}

// this is the helper funtion for insert
Node<ChessPlayer>* PlayerBST::insertHelper(Node<ChessPlayer>* node, const ChessPlayer& value) {
// the base case is when the node is null, meaning we can insert the new value
    if (!node) {
        size_++;
        return new Node<ChessPlayer>(value);
    }
// if the value is less than the current node, go left
    if (value.name_ < node->getValue().name_) {
        node->setLeftChild(insertHelper(node->getLeftChild(), value));
// if the value is greater than the current node, go right
    } else if (value.name_ > node->getValue().name_) {
        node->setRightChild(insertHelper(node->getRightChild(), value));
    }
// if the value is equal to the current node, do nothing
    return node;
}
/**
 * @brief Searches for a Player in the PlayerBST
 * with the specified name.
 *
 * @param value A const reference to a STRING representing
 * the name of the Player to search for.
 * @returns True if the player exists in the BST. False otherwise.
 */
bool PlayerBST::contains(const std::string& name) const {
    return containsHelper(root_, name);
}

// this is the helper function for contains
bool PlayerBST::containsHelper(Node<ChessPlayer>* node, const std::string& name) const {
// the base case is when the node is null which means we can not find the value
    if (!node) { 
        return false;
    }
// if the name is equal to the current node, we found it
    if (name == node->getValue().name_) 
        return true;
// if the name is less than the current node, go left
    if (name < node->getValue().name_) 
        return containsHelper(node->getLeftChild(), name);
// if the name is greater than the current node, go right
    return containsHelper(node->getRightChild(), name);
}

/**
 * @brief Calculates the average number of wins
 * across all Players in the PlayerBST, rounded
 * to at most the second decimal place.
 *
 * @returns The average number of wins or 0.0
 * if the BST is empty, as a double
 */

double PlayerBST::averageWins()  {
// if the tree is empty, return 0.0
    if (size_ == 0) {
        return 0.0;
    }
// if not, calculate the average 
    int numWins = sWins(root_);
// average is the sum of wins divided by the size
    double average = (double)(numWins) / size_;

// round the average to 2 decimal places
    return round(average * 100) / 100.0;
}

// this is the helper function to get the sum of wins
int PlayerBST::sWins(Node<ChessPlayer>* node) const {
    if (!node) {
        return 0;
    }
// get the sum of wins from the left child
    int left = sWins(node->getLeftChild());
// get the sum of wins from the left child
    int right = sWins(node->getRightChild());
// get the current node's wins
    int current = node->getValue().wins_;

// return the sum of all from the left child, right child and current node
    return left + right + current;
}

int PlayerBST::countAboveWins(const int& min_wins) const {
// use helper function to count the number of players with wins >= min_wins
    return countAboveWinsHelper(root_, min_wins);
}

int PlayerBST::countAboveWinsHelper(Node<ChessPlayer>* node, const int& min_wins) const {
    if (!node) {
// base case is when the node is null
        return 0;
    }
    int count = 0;
// check if the current node's wins are greater than or equal to min_wins
    if (node->getValue().wins_ >= min_wins) {
        count = 1;
    }
// recursively count the number of players with wins >= min_wins
    return count + countAboveWinsHelper(node->getLeftChild(), min_wins) + countAboveWinsHelper(node->getRightChild(), min_wins);
}

std::vector<ChessPlayer> PlayerBST::toVector(const TraversalType& traversal) const {
// this function creates a vector of all ChessPlayers in the BST
    std::vector<ChessPlayer> result;
// check if the tree is empty
    traverseHelper(root_, result, traversal);
    return result;
}

// helper function to traverse the tree
void PlayerBST::traverseHelper(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec, TraversalType type) const {
// this function traverses the tree in the specified order  
    if (!node) 
        return; // if the node is null, return
// if the type is pre-orde add the current node's value to the vector
        if (type == PRE_ORDER) {
        vec.push_back(node->getValue());
    }
// use traverseHelper to go left
    traverseHelper(node->getLeftChild(), vec, type);

// if the type is in-order, add the current node's value to the vector
    if (type == IN_ORDER) {
// here we add the current node's value to the vector
        vec.push_back(node->getValue());
    }

// use traverseHelper to go right
    traverseHelper(node->getRightChild(), vec, type);

// if the type is post-order add the current node's value to the vector
    if (type == POST_ORDER) {
        vec.push_back(node->getValue());
    }
}
