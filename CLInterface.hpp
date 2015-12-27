//
//  CLInterface.hpp
//  T3AI
//
//  Created by Afnan Enayet on 11/20/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#ifndef CLInterface_hpp
#define CLInterface_hpp

#include "gamePieces.hpp"
#include <iostream>

class CLInterface
{
public:
    // Takes only a 3*3 gameboard as argument and pretty prints to CLI
    void printBoard(pieceType ** &board);
    
    // Uses CLI to get input from user for next move on gameboard (x, y)
    int * getInput();
};

#endif /* CLInterface_hpp */
