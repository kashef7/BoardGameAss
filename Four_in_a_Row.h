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

    bool is_win();
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
    for (int z=4; z>=0;z-- ){
        if (this->board[z][y]==' '){
            this->board[z][y] = symbol;
            return true;
        }
    }

}
template <typename T>
bool Four_in_a_Row<T> :: is_win() {
    for ( int i=4 ; i>=0 ; i--){
        for ( int j=0 ; j<=3 ; j++ ){
            if (this->board[i][j] == this->board[i][j+1] &&
                this->board[i][j+1] == this->board[i][j+2] &&
                this->board[i][j+2] == this->board[i][j+3] &&
                this->board[i][j] != ' '){
                cout << "the row win";
                return true;
            }
        }
    }
    for ( int i=4 ; i>=3 ; i--){
        for ( int j=0 ; j<=3 ; j++ ){
            if (this->board[i][j] == this->board[i-1][j] &&
                this->board[i-1][j] == this->board[i-2][j] &&
                this->board[i-2][j] == this->board[i-3][j] &&
                this->board[i][j] != ' ') {
                cout << "the column win";
                return true;
            }
        }
    }
    for ( int i=4 ; i>2 ; i--){
        for ( int j=0 ; j<=3 ; j++ ){
            if (this->board[i][j] == this->board[i-1][j+1] &&
                this->board[i-1][j+1] == this->board[i-2][j+2] &&
                this->board[i-2][j+2] == this->board[i-3][j+3] &&
                this->board[i][j] != ' '){
                cout << "the diagonal win";
                return true;
            }
        }
    }
    for ( int i=1 ; i>=0 ; i--){
        for ( int j=0 ; j<=3 ; j++ ){
            if (this->board[i][j] == this->board[i+1][j+1] &&
                this->board[i+1][j+1] == this->board[i+2][j+2] &&
                this->board[i+2][j+2] == this->board[i+3][j+3] &&
                this->board[i][j] != ' '){
                cout << "the diagonal winSSS";
                return true;
            }
        }
    }
    return false;
}


#endif //BOARDGAMEASS_FOUR_IN_A_ROW_H