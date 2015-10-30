//
//  main.cpp
//  T3AI
//
//  Created by Afnan Enayet on 10/2/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include "player.hpp"
#include "gamePieces.hpp"

#define NEWLINE cout << '\n'; //print a newline

using namespace std;

int main() {
    std::stack<pieceType**> boardHistory; //contains board history so user can undo
    
    //initializing the game board
    pieceType ** gameBoard;
    gameBoard = new pieceType *[3];
    
    for (int i = 0; i < 3; i++) {
        gameBoard[i] = new pieceType[3];
    }
    
    boardHistory.push(gameBoard); //pushing first state
    player computer(gX); // initializing 'computer' player
    int nextMove[2]; // this array holds the coordinates of where player wants to place a piece
    
    //entering menu input loop
    string userInput;
    
    while (userInput != "q") {
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
            // initiate AI
        }
        else if (userInput == "2") {
            // initiate 2 player game
        }
        else if (userInput != "q") {
            NEWLINE
            cout << "You did not enter a valid option. Please enter a valid option:";
        }
    }
    
    bool moveIsValid;
    
    // input loop for adding part to game board
    while (!moveIsValid) {
        NEWLINE
        cout << "Type in x: ";
        NEWLINE
        cin >> nextMove[0];
        NEWLINE
        cout << "\nType in y: ";
        NEWLINE
        cin >> nextMove[1];
    
    
        moveIsValid = computer.addPiece(gameBoard, nextMove);
    
        if (moveIsValid) {
            boardHistory.push(gameBoard);
        }
        else {
            NEWLINE
            cout << "Move was not valid.";
        }
    }
    
    return 0;
}
