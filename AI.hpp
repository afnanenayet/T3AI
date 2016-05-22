//
//  AI.hpp
//  T3AI
//
//  Created by Afnan Enayet on 12/10/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include <array>
#include "gamePieces.hpp"
#include "board.hpp"

class AI
{
private:
    struct node {
        pieceType * scenario;
        node
        * left = nullptr,
        * right = nullptr;
    };
    node * root = nullptr;
    pieceType p_type;
    //std::unique_ptr<board> searchBoard;
    const board * searchBoard;
    
public:
    AI(pieceType playingPiece, board * gameBoard);
    pieceType getType();
    std::array<int, 2> getMove();
};

#endif /* AI_hpp */
