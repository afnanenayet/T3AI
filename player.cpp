//
//  player.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "player.hpp"

player::player(pieceType initializeType)
{
    // Initializes the player class and their type (X or O)
    player::tType = initializeType;
}

bool player::addPiece (pieceType ** gameBoard, int addPosition[])
{
    // adds piece to specified point on the gameboard, checking to make sure
    // it does not override an existing piece. If the move is valid (within bounds
    // of the board and not overriding an existing game piece) the function returns true
    int arrayIndex[2] = {(addPosition[0] - 1), (addPosition[1] - 1)};
    int bound = arrayIndex[0] * arrayIndex[1];
    
    try
    {
    if (addPosition[0] > 0 && addPosition[1] > 0 && bound < 9 && bound > 0 && gameBoard[addPosition[1]][addPosition[0]] == gEmpty)
    {
        (gameBoard[arrayIndex[0]][arrayIndex[1]]) = tType;
        return true;
    }
    else
    {
        return false;
    }
    }
    
    catch (int n)
    {
        return false;
    }
    
}

void player::setName(std::string name)
{
    playerName = name;
}