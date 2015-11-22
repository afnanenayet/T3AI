//
//  eventManager.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/30/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "eventManager.hpp"
#define NEWLINE std::cout<<"\n";

enum gamedef {tie, win, loss};

eventManager::eventManager(pieceType*** arg)
{
    board = *arg;
}

bool eventManager::onePlayer(player * humanPlayer)
{
    CLInterface printer;
    bool gameOver = false;
    
    while(!gameOver)
    {
        // Add a piece to the game board
        bool successfulMove;
        
        do
        {
            // Allocate space for array so memory isn't killed when getInput() moves out of scope
            // (otherwise the pointer could point to wrong data)
            int * inputVars;
            inputVars = printer.getInput();
            successfulMove = humanPlayer->addPiece(board, inputVars);
            printer.printBoard(board);
            
            if (successfulMove)
            {
                boardHistory.push(board);
            }
        }
        // TODO: check to see if game is over here, and then set gameOver variable
        while (!successfulMove);
    }
    
    return true; //debug
}

bool eventManager::twoPlayer(player * playerOne, player * playerTwo)
{
    bool gameOver = false;
    
    while(!gameOver)
    {
        // WIP/TODO: finish this
    }
    return true; //debug
}

int isGameOver()
{
    // TODO figure out diagonals
    return gamedef::tie;
}