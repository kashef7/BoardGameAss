//
// Created by User on 12/2/2024.
//
#ifndef BOARDGAMEASS_FOUR_IN_A_ROW_H
#define BOARDGAMEASS_FOUR_IN_A_ROW_H
#include "BoardGame_Classes.h"





using namespace std;

template <typename T>
class Four_in_a_Row : public Board<T>{
public:
    Four_in_a_Row();

    ~Four_in_a_Row();

    void display_board();

    bool update_board(int x,int y,T symbol);
};


template <typename T>
Four_in_a_Row <T>::Four_in_a_Row() {
    this->rows = 5;
    this->columns = 7;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;
}
template <typename T>
void Four_in_a_Row<T>::display_board(){
    cout << "Current Board:" << endl;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            cout <<"(" <<i<<"," << j<<")"  <<"[" << this->board[i][j] << "]" << "      "; // Display each cell in brackets
        }
        cout << endl;
    }
}
template <typename T>
bool Four_in_a_Row<T> ::update_board(int x, int y, T symbol) {
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns) {
        cout << "Invalid move: Coordinates out of bounds." << endl;
        return false;
    }

    // Check if the cell is empty
    if (this->board[x][y] != ' ') {
        cout << "Invalid move: Cell is already occupied." << endl;
        return false;
    }

    // Update the board with the symbol
    this->board[x][y] = symbol;
    return true;
}


#endif //BOARDGAMEASS_FOUR_IN_A_ROW_H