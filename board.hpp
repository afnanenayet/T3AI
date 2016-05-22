//
//  board.hpp
//  T3AI
//
//  Created by Afnan Enayet on 1/8/16.
//  Copyright © 2016 Afnan Enayet. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include "CLInterface.hpp"
#include "gamePieces.hpp"
#include "string.h"
#include <array>


class board {
private:
    pieceType ** gameBoard; // keep private to prevent unintentional copying
    
    // Keep track of these to find out whether piece won or not
    std::array<unsigned short, 2> lastMove = {0, 0};
    
public:
    // Creates a board of length and width
    board();
    ~board();
    
    // Copy constructor
    board(const board & other);
    
    // Copy assignment
    board & operator=(const board& other) {
        pieceType ** tempBoard = other.gameBoard;
        
        // Delete the current board
        for (auto i = 0; i < 3; i++) {
            delete[] gameBoard[i];
        }
        delete[] gameBoard;
        
        this->gameBoard = tempBoard;
        
        return * this;
    };
    
    
    // Checks to see if the piece passed as argument has "won" the game
    bool didPieceWin(pieceType checkPiece); // checks to see if the piece
    
    // pass game board and array[2] that contains the player's moves
    // adds piece to specified point on the gameboard, checking to make sure
    // it does not override an existing piece. If the move is valid (within bounds
    // of the board and not overriding an existing game piece) the function returns true
    bool addPiece(unsigned short x, unsigned short y, pieceType addType);
    
    // Prints the board to command line
    void print();
    
    //friend void printBoard(const board& Board);
    
    // Retrieve the contents of a particular position on the board
    pieceType identify(unsigned short x, unsigned short y) const;
};

#endif /* board_hpp */
