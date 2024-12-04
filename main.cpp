//
// Created by User on 12/2/2024.
//
#include "BoardGame_Classes.h"
#include "PyramidXO.h"
#include "Four_in_a_Row.h"
#include "WordXO.h"
#include "Numerical_TicTacToe.h"

using namespace std;
#include <string>
int main() {
    //do not touch theeeeeese!!!!!!!!!!!!!!!!!!
    /*Player<char>* players[2];
    Four_in_a_Row<char> *board = new Four_in_a_Row<char>();
    players[0] = new Four_in_a_Row_Player<char>("yousef", 'X');
    players[1] = new Four_in_a_Row_Player<char>("Kashef", 'O');
    GameManager<char>Four_in_Row_Game(board, players);
    Four_in_Row_Game.run();

    // Clean up
    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }*/

        // Create board
        Numerical_TicTacToe<char> *board = new Numerical_TicTacToe<char>();

        // Create players
        Player<char>* players[2];
        players[0] = new Numerical_TicTacToe_Player<char>("Player 1", '5');  // First player starts with 5
        players[1] = new Numerical_TicTacToe_Player<char>("Player 2", '2');  // Second player uses 2

        // Run game
        GameManager<char> Numerical_TicTacToe_Game(board, players);
        Numerical_TicTacToe_Game.run();

        // Clean up memory
        delete board;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

        return 0;
    cout << "zabat el menu ^_^";
}