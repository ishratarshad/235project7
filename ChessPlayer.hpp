// Author: Ishrat Arshad
// Date: May 9, 2025
// File: ChessPlayer.cpp
// Description: this file contains the implementation of the ChessPlayer class

#pragma once

#include <string>
struct ChessPlayer {
    /**
     * @brief The name of the Chess player
     */
    std::string name_;

    /**
     * @brief The number of wins this player has
     * @pre Must be non-negative (ie. >= 0)
     */
    int wins_;
};