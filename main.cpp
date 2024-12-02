//
// Created by User on 12/2/2024.
//
#include "BoardGame_Classes.h"
#include "Four_in_a_Row.h"

using namespace std;
#include <string>
int main() {
    Four_in_a_Row<char> *board = new Four_in_a_Row<char>();
    char i ='o';
    board->update_board(4, 0, 'O'); // Supporting piece
    board->update_board(3, 0, 'X');

    board->update_board(4, 1, 'O'); // Supporting piece
    board->update_board(3, 1, 'O'); // Supporting piece
    board->update_board(2, 1, 'X');

    board->update_board(4, 2, 'O'); // Supporting piece
    board->update_board(3, 2, 'O'); // Supporting piece
    board->update_board(2, 2, 'O'); // Supporting piece
    board->update_board(1, 2, 'X');

    board->update_board(4, 3, 'C'); // Supporting piece
    board->update_board(3, 3, 'O'); // Supporting piece
    board->update_board(2, 3, 'O'); // Supporting piece
    board->update_board(1, 3, 'C'); // Supporting piece
    board->update_board(0, 3, 'C');

    board->display_board();
    if (board->is_win()) {
        cout << "You win" << endl;
    }

}