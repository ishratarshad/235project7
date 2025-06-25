// Author: Ishrat Arshad
// Date: May 9, 2025
// File: PlayerBST.hpp
// Description: this file contains the header file for the PlayerBST class
#include "ChessPlayer.hpp"
#include "Node.hpp"

#include <string>
#include <vector>

enum TraversalType {
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};

/**
 * @brief The interface for a PlayerBST,
 * describing a BST ordered by the names
 * of ChessPlayer objects
 */
class PlayerBST {
protected:
    Node<ChessPlayer>* root_;
    int size_;

private:
    /**
     * @brief Helper function to delete node recursively.
     *
     * @param node Current subroot
     * @param value The name of the Player to delete
     * @return Updated node pointer
     */
    Node<ChessPlayer>* removeHelper(Node<ChessPlayer>* node, const std::string& name);

    /**
     * Deletes all nodes in the tree recursively.
     * @param node Current node to delete
     */
    void destroyTree(Node<ChessPlayer>* node);
    

// these are helper functions; 


// this is the helper function for insert
    Node<ChessPlayer>* insertHelper(Node<ChessPlayer>* node, const ChessPlayer& value);
 
// this is the helper function for contains
    bool containsHelper(Node<ChessPlayer>* node, const std::string& name) const;
    
// this is the helper funct to get avg win
    int sWins(Node<ChessPlayer>* node) const;
    
// this is the helper function to get the count of players with wins >= min_wins
    int countAboveWinsHelper(Node<ChessPlayer>* node, const int& min_wins) const;
    
// this is the helper function to traverse the tree
    void traverseHelper(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec, TraversalType type) const;

    

    public:
    /**
     * @brief Default constructor; constructs an empty BST
     * @post The `root_` is set to nullptr & `size_` to 0.
     */
    PlayerBST();

    /**
     * @brief Destructor to clean up all nodes.
     */
    ~PlayerBST();

    /**
     * @brief Removes a Player from the PlayerBST
     * if a player with their name exists.
     *
     * @param value A const reference a string representing
     * the name of the Player to be removed.
     * @returns True if the player was successfully removed. False otherwise.
     * @post Decrements `size_` if the player was removed.
     */
    bool remove(const std::string& name);

    // Define your function signatures below ========
    /**
     * @brief Getter for the `root_` member
     * @returns The a pointer to the root of the PlayerBST, 
     * or nullptr if the tree is empty.
     */
    Node<ChessPlayer>* getRoot() const; 

/**
 * @brief Getter for the `size_` member
 * @returns The number of Players (ie. nodes) 
 * in the PlayerBST as an integer
 */
    int size() const;                   

/**
 * @brief Searches for a Player in the PlayerBST
 * with the specified name.
 *
 * @param value A const reference to a STRING representing
 * the name of the Player to search for.
 * @returns True if the player exists in the BST. False otherwise.
 */

bool contains(const std::string& name) const;


/**
 * @brief Inserts a Player into the PlayerBST
 * if a player with their name does NOT already exist.
 *
 * @param value A const. reference to the ChessPlayer to insert
 * @returns True if the player was sucessfully inserted. False otherwise.
 * @post Increments the BST's size if the value was succesfully inserted
 */

bool insert(const ChessPlayer& value);

/**
 * @brief Calculates the average number of wins
 * across all Players in the PlayerBST, rounded
 * to at most the second decimal place.
 *
 * @returns The average number of wins or 0.0
 * if the BST is empty, as a double
 */

double averageWins();

/**
* @brief Counts the number of Players in the BST with
* greater than or equal to the specified minimum number of wins.
*
* @param min_wins A const reference to an integer
* denoting the minimum number of wins to check against
* @returns The count of players with wins >= min_wins
* as an integer
*/
int countAboveWins(const int& min_wins) const;

/**
 * @brief Creates a vector of all ChessPlayers in the BST
 * using the specified traversal order.
 *
 * @param traversal A const reference to the traversal type
 * (ie. IN_ORDER, PRE_ORDER, POST_ORDER)
 * @returns A vector containing all ChessPlayers in the PlayerBST 
 * read in the specified traversal order.
 */
std::vector<ChessPlayer> toVector(const TraversalType& traversal) const;



};
