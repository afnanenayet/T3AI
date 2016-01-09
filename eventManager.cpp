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

eventManager::eventManager(board *arg)
{
    instanceBoard = arg;
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
        int * inputVars;
        inputVars = printer.getInput();
        
        // Setting an array here because the space for inputVars won't be held after anything changes
        int tempArray [2] = {inputVars[0] - 1, inputVars[1] - 1};
        memcpy(inputVars, tempArray, sizeof(tempArray));
        
        pieceType lastPlayed;
        
        if (instanceBoard->addPiece(tempArray[0], tempArray[1], humanPlayer.tType))
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
    }
    while (!gameOver);
    
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
            int * inputVars;
            inputVars = printer.getInput();
            
            int tempArray [2] = {(inputVars[0] - 1), (inputVars[1] - 1)};
            
            NEWLINE
            cout << currentPlayer->playerName;
            
            if (instanceBoard->addPiece(tempArray[0], tempArray[1], currentPlayer->tType))
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