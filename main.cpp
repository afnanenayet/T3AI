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
    
    //entering input loop
    
    string userInput;
    
    // entering menu
    while (userInput != "q") {
        NEWLINE
        cout << "q: quit";
        cout << "1: 1 player (one computer)";
        cout << "2: 2 players";
        getline(cin, userInput);
        
        if (userInput == "1") {
            // initiate AI
        }
        
        else if (userInput == "2") {
            // initiate 2 player game
        }
        
        else {
            cout << "You did not enter a valid option. Please enter a valid option:";
            NEWLINE
        }
    }
    
    bool moveIsValid;
    
    // input loop for adding part to game board
    while (!moveIsValid) {
    
        cout << "Type in x: ";
        cin >> nextMove[0];
        cout << "\nType in y: ";
        cin >> nextMove[1];
    
    
        moveIsValid = computer.addPiece(gameBoard, nextMove);
    
        if (moveIsValid) {
            boardHistory.push(gameBoard);
        }
    
        else {
            cout << "Move was not valid.";
        }
    
    }
    
    return 0;
}

void getInput() {
    
}
