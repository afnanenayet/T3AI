//
//  board.hpp
//  T3AI
//
//  Created by Afnan Enayet on 1/8/16.
//  Copyright © 2016 Afnan Enayet. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include "gamePieces.hpp"
#include "string.h"


class board {
private:
    pieceType ** gameBoard; // keep private to prevent unintentional copying
    
    // Keep track of these to find out whether piece won or not
    unsigned char lastMove[2];
    
public:
    // Creates a board of length and width
    board();
    ~board();
    // Copy assignment
    // TODO: fix end of non-void function error
    /*board& operator=(const board& rhs)
    {
        for (auto i = 0; i < 3; i++)
        {
            gameBoard[i] = new pieceType[3];
            for (auto j = 0; j < 3; j++)
            {
                (gameBoard[i][j]) = rhs.gameBoard[i][j];
            }
        }
    }*/
    // Copy constructor
    board(const board& rhs);
    
    // Checks to see if the piece passed as argument has "won" the game
    bool didPieceWin(pieceType checkPiece); // checks to see if the piece
    
    // pass game board and array[2] that contains the player's moves
    // adds piece to specified point on the gameboard, checking to make sure
    // it does not override an existing piece. If the move is valid (within bounds
    // of the board and not overriding an existing game piece) the function returns true
    bool addPiece(unsigned char x, unsigned char y, pieceType addType);
    
};

#endif /* board_hpp */
