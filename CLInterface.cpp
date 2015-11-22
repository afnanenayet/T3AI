//
//  CLInterface.cpp
//  T3AI
//
//  Created by Afnan Enayet on 11/20/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//
// This one's quick and dirty :)

#include "CLInterface.hpp"
#define NEWLINE cout << "\n";

using namespace std;

void CLInterface::printBoard(pieceType ** board)
{
    NEWLINE
    cout << "    1   2   3     <-- x";
    NEWLINE
    cout << "  _____________";
    for (int i = 0; i < 3; i++)
    {
        NEWLINE
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                cout << i + 1 << " ";
            }
            
            if (j == 0 || j == 1)
            {
                cout << "|";
            }
            
            switch((board[i][j]))
            {
                case gO:
                    cout << " O ";
                    break;
                case gX:
                    cout << " X ";
                    break;
                case gEmpty:
                    cout << "   ";
                    break;
                default:
                    cout << "   ";
                    break;
            }
            
            if (j == 1 || j == 2)
            {
                cout << "|";
            }
        }
        NEWLINE
        cout << "  -------------";
    }
    NEWLINE
    cout << "^";
    NEWLINE
    cout << "y";
    NEWLINE
}