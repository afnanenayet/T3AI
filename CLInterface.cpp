//
//  CLInterface.cpp
//  T3AI
//
//  Created by Afnan Enayet on 11/20/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//
//  This one's quick and dirty :)

#include "CLInterface.hpp"
#define NEWLINE cout << "\n";

using namespace std;

/*void printBoard(const board& Board) // TODO setup friendship with board.hpp
{
    NEWLINE
    cout << "    1   2   3   <-- x";
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
            
            switch((Board.gameBoard[i][j]))
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
}*/

array<int, 2> CLInterface::getInput() {
    std::array<int, 2> tempArray;
    NEWLINE
    std::cout << "Enter X: ";
    std::cin >> tempArray[0];
    NEWLINE
    std::cout << "Enter Y: ";
    std::cin >> tempArray[1];
    NEWLINE
    return tempArray;
}