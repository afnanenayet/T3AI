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
#include "board.hpp"

#define NEWLINE cout << '\n'; //print a newline

using namespace std;

pieceType ** createBoard() {
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
    return gameBoard;
}

int main()
{
    //std::stack<pieceType**> boardHistory; //contains board history so user can undo
    
    
    
    //boardHistory.push(gameBoard); //pushing first state
    
    //entering menu input loop
    string userInput;
    
    
    do
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
            board gameBoard;
            eventManager game(&gameBoard);
            
            srand(uint(time(nullptr)));
            
            cout << "\nrand: " << rand();
            
            if ((rand() % 1) < .5)
            {
                
                // Initializing players
                player human(gO);
                player computer(gX);
                NEWLINE
                cout << "You are playing with the O piece";
                game.onePlayer(human);
            }
            else
            {
                player human(gX);
                player computer(gO);
                NEWLINE
                cout << "You are playing with the X piece";
                game.onePlayer(human);
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
    } while (userInput != "q");
    
    return 0;
}
