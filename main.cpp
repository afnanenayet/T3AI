//
//  main.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include <iostream>
#include <stack>
#include <random>
#include <string>
#include "player.hpp"
#include "gamePieces.hpp"
#include "eventManager.hpp"
#include "CLInterface.hpp"
#include "board.hpp"

#define NEWLINE cout << '\n'; //print a newline

using namespace std;

// Returns a random coin flip between the X and O piece
pieceType randPiece() {
    std::random_device rDevice;
    std::default_random_engine randEngine;
    std::uniform_real_distribution<double> numberDistribution(0, 1);
    
    if (numberDistribution(randEngine) > .5) {
        return gX;
    }
    
    else {
        return gO;
    }
}

int main() {
    //entering menu input loop
    string userInput;
    
    do {
        NEWLINE
        cout << "Welcome to tic-tac-toe";
        NEWLINE
        cout << "Enter a choice:";
        NEWLINE
        cout << "q: quit";
        NEWLINE
        cout << "1: 1 player (one computer)";
        NEWLINE
        cout << "2: 2 players";
        NEWLINE
        getline(cin, userInput);
        
        if (userInput == "1") {
            board gameBoard;
            eventManager game(gameBoard);
            // Introducing these here to keep them in scope
            // for game initialization
            pieceType playerPiece = randPiece();
            pieceType computerPiece = (playerPiece == gX) ? gO : gX;
            
            // Declaring players for game
            player computer(computerPiece);
            player human(playerPiece);
            
            game.onePlayer(human);
        }
        else if (userInput == "2") {
            //game.twoPlayer();
        }
        else if (userInput == "q") {
            return 0;
        }
        
        else {
            NEWLINE
            cout << "You did not enter a valid option. Please enter a valid option:";
        }
    } while (userInput != "q");
    return 0;
}
