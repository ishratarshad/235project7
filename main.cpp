// Author: Ishrat Arshad
// Date: May 9, 2025
// File: main.cpp
// Description: this file contains the main of PlayerBST, where it helps test the PlayerBST class
#include "PlayerBST.hpp"
#include <iostream>
#include <vector>

int main() {
    PlayerBST tree;

    // first test and insert players to match the desired tree
    ChessPlayer mia{"mia", 4};
    ChessPlayer grace{"grace", 3};
    ChessPlayer thomas{"thomas", 6};
    ChessPlayer andy{"andy", 2};
    ChessPlayer peter{"peter", 5};
    ChessPlayer zoe{"zoe", 1};
    // insert players into the tree
    tree.insert(mia);
    tree.insert(grace);
    tree.insert(thomas);
    tree.insert(andy);
    tree.insert(peter);
    tree.insert(zoe);
    // test the tree
    std::cout << "tree size: " << tree.size() << "\n";
    std::cout << "average wins: " << tree.averageWins() << "\n";
    std::cout << "wins more than or equal to 3: " << tree.countAboveWins(3) << "\n";
    std::vector<ChessPlayer> in_order = tree.toVector(IN_ORDER);
    std::vector<ChessPlayer> pre_order = tree.toVector(PRE_ORDER);
    std::vector<ChessPlayer> post_order = tree.toVector(POST_ORDER);
    std::cout << "in order: ";
    //  print the in order traversa
    for (int i = 0; i < in_order.size(); i++) {
        std::cout << in_order[i].name_ << "(" << in_order[i].wins_ << ") ";
    }
    std::cout << "\n";
    std::cout << "pre order: ";
    // print the pre order traversal
    for (int i = 0; i < pre_order.size(); i++) {
        std::cout << pre_order[i].name_ << "(" << pre_order[i].wins_ << ") ";
    }
        std::cout << "\n";
    // print the post order traversal
        std::cout << "post order:";
    for (int i = 0; i < post_order.size(); i++) {
        std::cout << post_order[i].name_ << "(" << post_order[i].wins_ << ") ";
    }
        std::cout << "\n";
    return 0;
}
