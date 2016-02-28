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
#define NEWLINE std::cout << "\n";

board::board()
{
    std::cout << "\n board constructor called";
    gameBoard = new pieceType * [3];
    
    for (auto i = 0; i < 3; i++) {
        gameBoard[i] = new pieceType[3];
        for (auto j = 0; j < 3; j++) {
            gameBoard[i][j] = gEmpty;
        }
    }
}

board::~board() {
    for (auto i = 0; i < 3; i++) {
        delete[] gameBoard[i];
    }
    delete[] gameBoard;
}

bool board::didPieceWin(pieceType checkPiece) {
    int verticalCounter = 0,
    horizontalCounter = 0,
    diagonalCounter = 0,
    rdiagonalCounter = 0;
    
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][lastMove[1]] == checkPiece) {
            horizontalCounter++;
        }
        
        if (gameBoard[lastMove[0]][i] == checkPiece) {
            verticalCounter++;
        }
        
        if (gameBoard[i][i] == checkPiece) {
            diagonalCounter++;
        }
        
        if (gameBoard[2 - i][i] == checkPiece) {
            rdiagonalCounter++;
        }
    }
    
    return (verticalCounter == 3 || horizontalCounter  == 3 ||
            rdiagonalCounter == 3 || diagonalCounter == 3);
}

bool board::addPiece(unsigned short x, unsigned short y, pieceType addType) {
    std::array<unsigned short, 2> arrayIndex;
    arrayIndex[0] = x - 1;
    arrayIndex[1] = y - 1;
    try {
        if (VALID(arrayIndex)) {
            gameBoard[arrayIndex[0]][arrayIndex[1]] = addType;
            lastMove = arrayIndex;
            return true;
        } else {
            return false;
        }
    } catch (int n) {
        std::cout << "\nError: " << n << " occurred.";
        return false;
    }
}

void board::print() {
    NEWLINE
    std::cout << "    1   2   3   <-- x";
    NEWLINE
    std::cout << "  _____________";
    for (int i = 0; i < 3; i++) {
        NEWLINE
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                std::cout << i + 1 << " ";
            }
            
            if (j == 0 || j == 1) {
                std::cout << "|";
            }
            
            switch((gameBoard[i][j])) {
                case gO:
                    std::cout << " O ";
                    break;
                case gX:
                    std::cout << " X ";
                    break;
                case gEmpty:
                    std::cout << "   ";
                    break;
                default:
                    std::cout << "   ";
                    break;
            }
            
            if (j == 1 || j == 2) {
                std::cout << "|";
            }
        }
        NEWLINE
        std::cout << "  -------------";
    }
    NEWLINE
    std::cout << "^";
    NEWLINE
    std::cout << "y";
    NEWLINE
}

pieceType board::identify(unsigned short x, unsigned short y) {
    if (x < 3 && x >= 0 && y < 3 && y>=0) {
        return gameBoard[y][x];
    } else {
        throw 404; // Error 404: out of bounds error
    }
}
