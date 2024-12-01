//
// Created by User on 12/2/2024.
//
#include "BoardGame_Classes.h"
#include "Four_in_a_Row.h"

using namespace std;
#include <string>
int main() {
    Four_in_a_Row<char> *board = new Four_in_a_Row<char>();
    char i ='k';
    board->update_board( 0 , 0 , i );
    board->display_board();
}