//
//  player.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "player.hpp"

// Determines if move integers are within bounds of the gameboard array
#define VALID(x) x[0] < 3 && x[0] >= 0 && x[1] < 3 && x[1] >= 0

player::player(pieceType initializeType)
{
    // Initializes the player class and their type (X or O)
    player::tType = initializeType;
}

bool player::addPiece (pieceType ** gameBoard, int addPosition[])
{
    int arrayIndex[2] = {(addPosition[0] - 1), (addPosition[1] - 1)};
    
    try
    {
        if (VALID(arrayIndex))
        {
            (gameBoard[arrayIndex[1]][arrayIndex[0]]) = tType;
            moveHistory.push_back(arrayIndex);
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (long n)
    {
        return false;
    }
}

bool player::won()
{
    if (moveHistory.size() < 3)
    {
        return false;
    }
    else {
        auto diagCounter = 0;
        for (auto movePair : moveHistory)
        {
            if (movePair[0] == movePair[1])
            {
                diagCounter++;
            }
        }
        if (diagCounter == 3) {
            return true;
        }
        
        else {
            return false;
        }
    }
}

void player::setName(std::string name)
{
    playerName = name;
}