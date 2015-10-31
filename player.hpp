//
//  player.hpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "gamePieces.hpp"
#include <string>

class player {
private:
    pieceType tType;
    
public:
    // allows us to keep statistics
    int wins = 0;
    int losses = 0;
    
    std::string playerName;
    
    //constructor sets whether player is an X or an O
    player(pieceType);
    
    //pass game board and array[2] that contains the player's moves
    bool addPiece(pieceType**, int[]);
    
    //allows player's name to be set
    void setName(std::string);
};

#endif /* player_hpp */
