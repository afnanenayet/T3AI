//
//  AI.hpp
//  T3AI
//
//  Created by Afnan Enayet on 12/10/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include "gamePieces.hpp"

class AI
{
private:
    struct node
    {
        pieceType ** scenario;
        node
        * left = nullptr,
        * right = nullptr;
    };
    node * root = nullptr;
    
public:
    AI(pieceType playingPiece);
    pieceType type;
};

#endif /* AI_hpp */
