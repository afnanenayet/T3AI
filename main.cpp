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
#include "eventManager.hpp"
#include "CLInterface.hpp"

#define NEWLINE cout << '\n'; //print a newline

using namespace std;

int main()
{
    std::stack<pieceType**> boardHistory; //contains board history so user can undo
    
    //initializing the game board
    pieceType ** gameBoard;
    gameBoard = new pieceType *[3];
    
    for (int i = 0; i < 3; i++)
    {
        gameBoard[i] = new pieceType[3];
        for (int j = 0; j < 3; j++)
        {
            (gameBoard[i][j]) = gEmpty;
        }
    }
    
    boardHistory.push(gameBoard); //pushing first state
    player computer(gX); // initializing 'computer' player
    int nextMove[2]; // this array holds the coordinates of where player wants to place a piece
    
    //entering menu input loop
    string userInput;
    
    eventManager game(&gameBoard);
    while (userInput != "q")
    {
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
        
        if (userInput == "1")
        {
            srand(uint(time(nullptr)));
            
            if (rand() < .5)
            {
                // Initializing players
                player human(gO);
                player computer(gX);
                NEWLINE
                cout << "You are playing with the O piece";
                game.onePlayer(&human);
            }
            else
            {
                player human(gX);
                player computer(gO);
                NEWLINE
                cout << "You are playing with the X piece";
                game.onePlayer(&human);
            }
        }
        else if (userInput == "2")
        {
            //game.twoPlayer();
        }
        else if (userInput == "q")
        {
            return 0;
        }
        
        else
        {
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
    
        if (moveIsValid)
        {
            boardHistory.push(gameBoard);
        }
        else
        {
            NEWLINE
            cout << "Move was not valid.";
        }
    }
    
    return 0;
}
