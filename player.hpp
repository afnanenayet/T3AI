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
#include <vector>

class player
{
    
public:
    // Player statistics/info
    int wins;
    int losses;
    std::string playerName;
    pieceType tType;
    
    // Constructor sets whether player is an X or an O
    player(pieceType);
    // Sets player name
    void setName(std::string name);
};

#endif /* player_hpp */