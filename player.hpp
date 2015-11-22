//
//  player.hpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "gamePieces.hpp"
#include <string>

class player
{
    pieceType tType;
    
public:
    // Player statistics/info
    int wins = 0;
    int losses = 0;
    std::string playerName;
    
    // Constructor sets whether player is an X or an O
    player(pieceType);
    
    // pass game board and array[2] that contains the player's moves
    // adds piece to specified point on the gameboard, checking to make sure
    // it does not override an existing piece. If the move is valid (within bounds
    // of the board and not overriding an existing game piece) the function returns true
    bool addPiece(pieceType** gameBoard, int addPosition[]);
    
    // Sets player name
    void setName(std::string name);
};

#endif /* player_hpp */