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
#include <algorithm>
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
    int nextMove[2]; // this array holds the coordinates of where player wants to place a piece
    
    //entering menu input loop
    string userInput;
    
    eventManager game(&gameBoard);
    do
    {
        srand(time(nullptr));
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
            
            
            pieceType playerPiece;
            pieceType computerPiece;
            
            (rand() % 1 <= .5) ? (playerPiece = gO) : (playerPiece = gX);
            
            for (int i = 0; i < 100; i++)
            {
                NEWLINE
                float x = rand() + 1;
                cout << (x);
            }
            
            player human(playerPiece);
            player computer(computerPiece);
            
            string nameString;
            string pieceString;
            NEWLINE
            cout << "Enter Player 1's name: ";
            getline(cin, nameString);
            NEWLINE
            
            human.setName(nameString);
        
            (playerPiece == gO) ? (pieceString = "O") : (pieceString = "X");
            cout << human.playerName << " is playing with the " << pieceString << " piece";
            
            game.onePlayer(&human);
        }
        else if (userInput == "2")
        {
            pieceType typeOne;
            pieceType typeTwo;
            
            if (rand() % 1 <= .5)
            {
                typeOne = gX;
                typeTwo = gO;
            }
            
            else
            {
                typeOne = gO;
                typeTwo = gX;
            }
            
            player playerOne(typeOne);
            player playerTwo(typeTwo);
            
            game.twoPlayer(&playerOne, &playerTwo);
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
