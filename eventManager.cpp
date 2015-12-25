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
        
        // Setting an array here because the space for inputVars won't be held after anything changes
        int tempArray [2] = {inputVars[0] - 1, inputVars[1] - 1};
        
        pieceType lastPlayed;
        
        if (humanPlayer->addPiece(board, inputVars)){
            // boardHistory.push(board); // Removing (experimentally)
            
            moveHistory.push(inputVars);
            lastPlayed = humanPlayer->tType;
            
            printer.printBoard(board);
            
            if (whoWon(tempArray, lastPlayed))
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
        cout << "Player 1";
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

// Keep arguments const because they should not be manipulated
bool eventManager::whoWon(int lastMove[], const pieceType & lastType)
{
    int verticalCounter = 0,
    horizontalCounter = 0,
    diagonalCounter = 0,
    rdiagonalCounter = 0;
    
    if (lastType == gX)
    {
        cout << "\ngX";
    }
    
    else if (lastType == gO)
    {
        cout << "\ngX";
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[i][lastMove[0]] == lastType)
        {
            horizontalCounter++;
        }
        
        if (board[lastMove[1]][i] == lastType)
        {
            verticalCounter++;
        }
        
        if (board[i][i] == lastType)
        {
            diagonalCounter++;
        }
        
        if (board[2 - i][i] == lastType)
        {
            rdiagonalCounter++;
        }
    }
    
    return (verticalCounter == 3 || horizontalCounter  == 3 || rdiagonalCounter == 3 || diagonalCounter == 3);
}