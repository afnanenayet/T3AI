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

class player {
pieceType tType;
public:
    player(pieceType); //constructor sets whether player is an X or an O
    
    bool addPiece(pieceType(&)[3][3], int(&)[2]); //passes the game board by reference so we can add to it and tells if the move is possible
    
};

#endif /* player_hpp */
