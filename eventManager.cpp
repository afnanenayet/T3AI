//
//  eventManager.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/30/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "eventManager.hpp"
#define NEWLINE std::cout<<"\n";

enum result {tie, xWin, oWin};

eventManager::eventManager(board &arg)
{
    // Taking as reference because we want to modify the original board, not make a copy
    instanceBoard = &arg;
}

using namespace std;
bool eventManager::onePlayer(player &humanPlayer)
{
    CLInterface printer;
    bool gameOver = false;
    // Add a piece to the game board
    
    do
    {
        // Allocate space for array so memory isn't killed when getInput() moves out of scope
        // (otherwise the pointer could point to wrong data)
        std::array<int, 2> inputVars = printer.getInput();
        
        pieceType lastPlayed;
        
        if (instanceBoard->addPiece(inputVars[0], inputVars[1], humanPlayer.tType))
        {
            lastPlayed = humanPlayer.tType;
            instanceBoard->print();
            
            if (instanceBoard->didPieceWin(lastPlayed))
            {
                NEWLINE
                cout << "You won!";
                humanPlayer.wins++;
                gameOver = true;
            }
            else
            {
                NEWLINE
                cout << "You have not won.";
            }
        }
        else
        {
            NEWLINE
            cout << "Invalid move.";
        }
    } while (!gameOver);
    return true; //debug
}

bool eventManager::twoPlayer(player &playerOne, player &playerTwo)
{
    bool isGameOver = false;
    pieceType lastPlayed;
    CLInterface printer;
    player * currentPlayer = &playerOne;
    
    while(!isGameOver)
    {
        bool isValidMove = true;
        
        // Player input loop
        do
        {
            std:;array<int, 2> inputVars;;
            inputVars = printer.getInput();
            
            NEWLINE
            cout << currentPlayer->playerName;
            
            if (instanceBoard->addPiece(inputVars[0], inputVars[1], currentPlayer->tType))
            {
                lastPlayed = currentPlayer->tType;
                isGameOver = instanceBoard->didPieceWin(lastPlayed);
            }
            else
            {
                NEWLINE
                cout << "Invalid move.";
            }
        } while(!isValidMove);
        
        // Toggling between players because turns
        (currentPlayer == &playerOne) ? currentPlayer = &playerTwo : currentPlayer = &playerOne;
    }
    
    // TODO: figure out player output
    return true;
}