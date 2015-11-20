//
//  eventManager.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/30/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "eventManager.hpp"
#define NEWLINE std::cout<<"\n";

eventManager::eventManager(pieceType** arg)
{
    board = arg;
}

bool eventManager::onePlayer(player * humanPlayer)
{
    static pieceType** boardA = eventManager::board;
    bool gameOver = false;
    
    while(!gameOver)
    {
        // Add a piece to the game board
        bool successfulMove;
        
        do
        {
            successfulMove = humanPlayer->addPiece(boardA, getInput());
        }
        // TODO: check to see if game is over here, and then set gameOver variable
        while (!successfulMove);
    }
    
    return true; //debug
}

bool eventManager::twoPlayer(player * playerOne, player * playerTwo)
{
    bool gameOver = false;
    
    while(!gameOver)
    {
        
    }
    
    return true; //debug
}

// Input from CLI
using namespace std;
int * eventManager::getInput()
{
    int tempArray[2];
    NEWLINE
    cout << "Enter X: ";
    cin >> tempArray[0];
    NEWLINE
    cout << "Enter Y: ";
    cin >> tempArray[1];
    NEWLINE
    
    /**NOTE: this will return the address of the memory
    associated with the array (doesn't matter for this purpose
    since we are just reading
    **/
    return tempArray;
}