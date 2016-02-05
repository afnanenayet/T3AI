//
//  eventManager.hpp
//  T3AI
//
//  Created by Afnan Enayet on 10/30/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#ifndef eventManager_hpp
#define eventManager_hpp

#include <stack>
#include <random>
#include "string.h"
#include "player.hpp"
#include "CLInterface.hpp"
#include "board.hpp"

class eventManager
{
    board *instanceBoard;

public:
    eventManager(board &arg);
    
    // A game where a human player plays against the AI, returns 0 if the AI won
    // returns 1 if the player won
    bool onePlayer(player &humanPlayer);
    
    // A game where two human players play against each other. Returns the player that won
    // (1 for player one, 2 for player two)
    bool twoPlayer(player &playerOne, player &playerTwo);
};

#endif /* eventManager_hpp */
