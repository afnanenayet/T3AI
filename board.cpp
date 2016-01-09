//
//  board.cpp
//  T3AI
//
//  Created by Afnan Enayet on 1/8/16.
//  Copyright © 2016 Afnan Enayet. All rights reserved.
//

#include "board.hpp"

// Determines if move integers are within bounds of the gameboard array
#define VALID(x) x[0] < 3 && x[0] >= 0 && x[1] < 3 && x[1] >= 0

board::board()
{
    gameBoard = new pieceType * [3];
    
    for (auto i = 0; i < 3; i++)
    {
        gameBoard[i] = new pieceType[3];
        for (auto j = 0; j < 3; j++)
        {
            gameBoard[i][j] = gEmpty;
        }
    }
}

board::~board()
{
    for (int i = 0; i < 3; i++)
    {
        delete gameBoard[i];
    }
    
    // Not sure if necessary since we are using an
    // array of pointers to pointers
    delete gameBoard;
}

board::board(const board& rhs)
{
    for (auto i = 0; i < 3; i++)
    {
        gameBoard[i] = new pieceType[3];
        for (auto j = 0; j < 3; j++)
        {
            (gameBoard[i][j]) = rhs.gameBoard[i][j];
        }
    }
}


bool board::didPieceWin(pieceType checkPiece)
{
    int verticalCounter = 0,
    horizontalCounter = 0,
    diagonalCounter = 0,
    rdiagonalCounter = 0;
    
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][lastMove[0]] == checkPiece)
        {
            horizontalCounter++;
        }
        
        if (gameBoard[lastMove[1]][i] == checkPiece)
        {
            verticalCounter++;
        }
        
        if (gameBoard[i][i] == checkPiece)
        {
            diagonalCounter++;
        }
        
        if (gameBoard[2 - i][i] == checkPiece)
        {
            rdiagonalCounter++;
        }
    }
    
    return (verticalCounter == 3 || horizontalCounter  == 3 ||
            rdiagonalCounter == 3 || diagonalCounter == 3);
}

bool board::addPiece(unsigned char x, unsigned char y, pieceType addType)
{
    unsigned char arrayIndex[2] = {static_cast<unsigned char>(x - 1), static_cast<unsigned char>(y - 1)};
    
    try
    {
        if (VALID(arrayIndex))
        {
            (gameBoard[arrayIndex[1]][arrayIndex[0]]) = addType;
            memcpy(arrayIndex, lastMove, sizeof(lastMove));
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
