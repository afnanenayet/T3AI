//
//  main.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include <iostream>
#include <stack>
#include "player.hpp"
#include "gamePieces.hpp"

#define NEWLINE cout << '\n'

using namespace std;

int main() {
    std::stack<pieceType[3][3]> boardHistory;
    pieceType gameBoard[3][3]; //initializing the game board
    //boardHistory.push(gameBoard);
    player computer(gX);
    int nextMove[2];
    
    cout << "Type in x: ";
    cin >> nextMove[0];
    cout << "\nType in y: ";
    cin >> nextMove[1];
    //bool moveIsValid;
    //moveIsValid = computer.addPiece(gameBoard, nextMove);
    //boardHistory.push(gameBoard);
    return 0;
}

void getInput() {
    //TODO: add code here
}
