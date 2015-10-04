//
//  player.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "player.hpp"

player::player(pieceType initializeType) {
    pieceType tType;
    tType = initializeType;
};

bool addPiece (pieceType (&gameBoard)[3][3], int (&addPosition)[2]){
    //this ensures that the player won't override anything already on the game board
    if (gameBoard[addPosition[0]][addPosition[1]]) {
        gameBoard[addPosition[0]][addPosition[1]] = tType;
        return true;
    }
    
    else {
        return false;
    }
    
}
