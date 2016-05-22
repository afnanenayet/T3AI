//
//  AI.cpp
//  T3AI
//
//  Created by Afnan Enayet on 12/10/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "AI.hpp"

using namespace std;

AI::AI(pieceType playingPiece, board * gameBoard) {
    searchBoard = gameBoard;
    p_type = playingPiece;
}

pieceType AI::getType() {
    return p_type;
}

array<int, 2> AI::getMove() {
    // Evaluating game board
    int verticalCounter = 0,
        horizontalCounter = 0,
        diagonalCounter = 0,
        rdiagonalCounter = 0,
        oppVerticalCounter = 0,
        oppHorizontalCounter = 0,
        oppDiagonalCounter = 0,
        oppRdiagonalCounter = 0;
    pieceType opponent_type = (p_type == gX) ? gO : gX;
    array<int, 2> tempArray;
    
    for (int i = 0; i < 3; i++) {
        // Evaluating diagonals
        if (searchBoard->identify(i, i) == p_type) {
            diagonalCounter++;
        }
        
        else if (searchBoard->identify(i, i) == opponent_type) {
            oppDiagonalCounter++;
        }
        
        if (searchBoard->identify(2 - i, i) == p_type) {
            rdiagonalCounter++;
        }
        
        else if (searchBoard->identify(2 - i, i) == opponent_type) {
            oppRdiagonalCounter++;
        }
        
        // Evaluating columns and rows
        for (int j = 0; j < 3; j++) {
            if (searchBoard->identify(i, j) == p_type) {
                horizontalCounter++;
            }
            
            else if (searchBoard->identify(i, j) == opponent_type) {
                oppHorizontalCounter++;
            }
            
            if (searchBoard->identify(j, i) == p_type) {
                verticalCounter++;
            }
            
            if (searchBoard->identify(j, i) == opponent_type) {
                oppVerticalCounter++;
            }
        }
    }
    
    // Determining what to do based on data
    
    if (diagonalCounter == 2) {
        if (searchBoard->identify(3, 3) == gEmpty) {
            tempArray = {3, 3};
        } else {
            tempArray = {1, 1};
        }
    }
    
    else if (rdiagonalCounter == 2) {
        if (searchBoard->identify(1, 3) == gEmpty) {
            tempArray = {1, 3};
        } else {
            tempArray = {3, 1};
        }
    }
 
    else {
        tempArray = {2, 2};
    }
    
    return tempArray;
}