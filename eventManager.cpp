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
            
            if (humanPlayer->addPiece(board, inputVars)){
                boardHistory.push(board);
                
                printer.printBoard(board);
                
                if (humanPlayer->won())
                {
                    NEWLINE
                    std::cout<< "You won!";
                    gameOver = true;
                }
                
                else
                {
                    NEWLINE
                    std::cout<<"You have not won.";
                }
            }
            else
            {
                NEWLINE
                std::cout << "Invalid move.";
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

int eventManager::isGameOver()
{

    int ohCounter = 0;
    int xhCounter = 0;
    int ovCounter = 0;
    int xvCounter = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == gX)
        {
            xhCounter++;
        }
        
        else if (board[i][0] == gO)
        {
            ohCounter++;
        }
        
        if (board[0][i] == gX)
        {
            xvCounter++;
        }
        
        else if (board[0][i] == gO)
        {
            ovCounter++;
        }
    }
    
    if (xhCounter > 2 || ohCounter > 2)
    {
        return 1;
    }
    return gamedef::tie;
}