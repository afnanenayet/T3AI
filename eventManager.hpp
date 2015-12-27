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
#include "player.hpp"
#include "CLInterface.hpp"

class eventManager
{
    pieceType ** board;
    std::stack<pieceType**> boardHistory;
    
    // This allows the user to undo moves
    std::stack<int*> moveHistory; // thinking about switching to this from boardhistory
    
    
    // Determines whether the player won
    bool whoWon(const int lastMove[], const pieceType & lastType);

public:
    eventManager(pieceType ** &arg);
    
    // A game where a human player plays against the AI, returns 0 if the AI won
    // returns 1 if the player won
    bool onePlayer(player &humanPlayer);
    
    // A game where two human players play against each other. Returns the player that won
    // (1 for player one, 2 for player two)
    bool twoPlayer(player &playerOne, player &playerTwo);
};

#endif /* eventManager_hpp */
