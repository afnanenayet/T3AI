//
//  player.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "player.hpp"

player::player(pieceType initializeType) {
    // Initializes the player class and their type (X or O)
    player::tType = initializeType;
    losses = 0;
    wins = 0;
}

void player::setName(std::string name) {
    playerName = name;
}