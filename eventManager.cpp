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

eventManager::eventManager(pieceType*** arg)
{
    board = *arg;
}

using namespace std;
bool eventManager::onePlayer(player * humanPlayer)
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
        
        if (humanPlayer->addPiece(board, inputVars)){
            // boardHistory.push(board); // Removing (experimental)
            moveHistory.push(inputVars);
            
            printer.printBoard(board);
            
            if (whoWon() == humanPlayer->tType)
            {
                NEWLINE
                cout << "You won!";
                humanPlayer->wins++;
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

bool eventManager::twoPlayer(player * playerOne, player * playerTwo)
{
    bool gameOver = false;
    
    while(!gameOver)
    {
        CLInterface printer;
        int * inputVars = printer.getInput();
        
        NEWLINE
        cout << playerOne->playerName;
        if (playerOne->addPiece(board, inputVars))
        {
            boardHistory.push(board);
        }
        
        else
        {
            NEWLINE
            cout << "Invalid move.";
        }
    }
    return true; //debug
}

pieceType eventManager::whoWon()
{
    uint8_t ohCounter = 0, // O horizontal
    xhCounter = 0, // X horizontal
    ovCounter = 0, // O vertical
    xvCounter = 0, // X vertical
    odCounterA = 0, // O diagonal (top left to bottom right)
    xdCounterA = 0, // X diagonal (top left to bottom right)
    odCounterB = 0, // O diagonal (top right to bottom left)
    xdCounterB = 0; // X diagonal (top right to bottom left)
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == gX)
            {
                xhCounter++;
            }
            
            else if (board[i][j] == gO)
            {
                ohCounter++;
            }
            
            if (board[j][i] == gX)
            {
                xvCounter++;
            }
            else if (board[j][i] == gO)
            {
                ovCounter++;
            }
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] == gX)
        {
            xdCounterA++;
        }
        else if (board[i][i] == gO)
        {
            odCounterA++;
        }
        
        if (board[2 - i][i] == gO)
        {
            odCounterB++;
        }
        else if (board[2 - i][i] == gX)
        {
            xdCounterB++;
        }
    }
    
    if (xhCounter > 2 || xvCounter > 2 || xdCounterA > 2 || xdCounterB > 2)
    {
        return gX;
    }
    else if (ohCounter > 2 || ovCounter > 2 || odCounterA > 2 || odCounterB > 2)
    {
        return gO;
    }
    else {
        return gEmpty;
    }
}