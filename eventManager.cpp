//
//  eventManager.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/30/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include "eventManager.hpp"
#define NEWLINE std::cout<<"\n";

using namespace std;

enum result {tie, xWin, oWin};

eventManager::eventManager(board &arg) : instanceBoard(&arg) {
}


bool eventManager::onePlayer(player &humanPlayer) {
    CLInterface printer;
    bool gameOver = false;
    AI computerPlayer((humanPlayer.tType == gX) ? gX : gO, instanceBoard);
    
    // Add a piece to the game board
    std::array<int, 2> inputVars;
    
    do {
        inputVars = printer.getInput();
        pieceType lastPlayed;
        
        // Loop until valid input from player
        bool validMove = false;
        
        do {
            validMove = instanceBoard->addPiece(inputVars[0], inputVars[1], humanPlayer.tType);
            
            if (!validMove) {
                NEWLINE
                cout << "Invalid move.";
            }
        } while(!validMove);
        
        lastPlayed = humanPlayer.tType;
        instanceBoard->print();
        
        //TODO add interface for AI
        
        // Checking to see if player won and updating stats if so
        if (instanceBoard->didPieceWin(lastPlayed)) {
            NEWLINE
            cout << "You won!";
            humanPlayer.wins++;
            gameOver = true;
        } else {
            NEWLINE
            cout << "You have not won.";
        }
        
        inputVars = computerPlayer.getMove();
        instanceBoard->addPiece(inputVars[0], inputVars[1], computerPlayer.getType());
        lastPlayed = computerPlayer.getType();
        instanceBoard->print();

        
        // Checking to see if the input was valid
        if (instanceBoard->addPiece(inputVars[0], inputVars[1], humanPlayer.tType)) {
            lastPlayed = humanPlayer.tType;
            instanceBoard->print();
            
            // Checking to see if player won and updating stats if so
            if (instanceBoard->didPieceWin(lastPlayed)) {
                NEWLINE
                cout << "You won!";
                humanPlayer.wins++;
                gameOver = true;
            } else {
                NEWLINE
                cout << "You have not won.";
            }
        } else {
            NEWLINE
            cout << "Invalid move.";
        }
    } while (!gameOver);
    return true; //debug
}

bool eventManager::twoPlayer(player &playerOne, player &playerTwo) {
    bool isGameOver = false;
    pieceType lastPlayed;
    CLInterface printer;
    player * currentPlayer = &playerOne;
    
    while(!isGameOver) {
        bool isValidMove = true;
        
        // Player input loop
        do {
            std:;array<int, 2> inputVars;;
            inputVars = printer.getInput();
            
            NEWLINE
            cout << currentPlayer->playerName;
            
            if (instanceBoard->addPiece(inputVars[0], inputVars[1], currentPlayer->tType)) {
                lastPlayed = currentPlayer->tType;
                isGameOver = instanceBoard->didPieceWin(lastPlayed);
            } else {
                NEWLINE
                cout << "Invalid move.";
            }
        } while(!isValidMove);
        
        // Toggling between players because they take turns
        (currentPlayer == &playerOne) ? currentPlayer = &playerTwo : &playerOne;
    }
    
    // TODO: figure out player output
    return true;
}