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
        pieceType lastPlayed;
        
        if (humanPlayer->addPiece(board, inputVars)){
            // boardHistory.push(board); // Removing (experimental)
            moveHistory.push(inputVars);
            
            printer.printBoard(board);
            
            if (whoWon(moveHistory.top(), lastPlayed) == humanPlayer->tType)
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

pieceType eventManager::whoWon(int lastMove[], const pieceType & lastType)
{
    int verticalCounter = 0;
    int horizontalCounter = 0;
    int diagonalCounter = 0;
    int rdiagonalCounter = 0;
    
    for (int i = 0; i < 2; i++) {
        
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