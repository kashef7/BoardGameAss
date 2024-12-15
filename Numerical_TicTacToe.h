#ifndef BOARDGAMEASS_NUMERICAL_TICTACTOE_H
#define BOARDGAMEASS_NUMERICAL_TICTACTOE_H
#include "BoardGame_Classes.h"
#include <algorithm>
using namespace std;

template <typename T>
class Numerical_TicTacToe :public Board<T> {

public:
    vector<int> used_numbers = {1,2,3,4,5,6,7,8,9};
    int current_player = 1;
    Numerical_TicTacToe();


    void display_board();
    bool update_board(int x,int y,T symbol);
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Numerical_TicTacToe_Player : public Player<T> {
public:
    Numerical_TicTacToe_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
Numerical_TicTacToe<T>::Numerical_TicTacToe() {
    this->rows = 3;
    this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '0';
        }
    }
    this->n_moves = 0;
}

template <typename T>
void Numerical_TicTacToe<T>::display_board() {
    cout << "Current Board:" << endl;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")" << "[" << (this->board[i][j] == '0' ? ' ' : this->board[i][j]) << "]" << "  ";
        }
        cout << endl;
    }
    cout << "Available numbers: ";
    for (int num : used_numbers) {
        cout << num << " ";
    }
    cout << endl;
}

template <typename T>
bool Numerical_TicTacToe<T>::update_board(int x, int y, T symbol) {

    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns) {
        return false;
    }

    if (this->board[x][y] != '0') {
        return false;
    }

    int num;
    num = symbol - '0';
    auto it = find(used_numbers.begin(), used_numbers.end(), num);
    if (it == used_numbers.end()) {
        return false;
    }

    if ((current_player % 2 == 1 && num % 2 == 0) ||
        (current_player % 2 == 0 && num % 2 == 1)) {
        return false;
    }

    this->board[x][y] = symbol;
    used_numbers.erase(it);
    this->n_moves++;
    current_player++;

    return true;
}

template <typename T>
bool Numerical_TicTacToe<T>::is_win() {

    for (int i = 0; i < this->rows; i++) {
        int row_sum = (this->board[i][0] - '0') +(this->board[i][1] - '0') +(this->board[i][2] - '0');
        if (row_sum == 15 && this->board[i][0]!='0' && this->board[i][1]!=0 && this->board[i][2] !='0') {
            return true;
        }
    }
    for (int i = 0; i < this->columns; i++) {
        int col_sum = (this->board[0][i] - '0')+(this->board[1][i] - '0')+(this->board[2][i] - '0');
        if (col_sum == 15 && this->board[0][i]!='0' && this->board[1][i]!='0' && this->board[2][i]!='0') {
            return true;
        }
    }

    int diagonal1_sum = (this->board[0][0] - '0') +(this->board[1][1] - '0') +(this->board[2][2] - '0');
    int diagonal2_sum = (this->board[0][2] - '0') +(this->board[1][1] - '0') +(this->board[2][0] - '0');
    if (diagonal1_sum == 15 && this->board[0][0]!='0' && this->board[1][1]!=0 && this->board[2][2]!='0'){
        return true;
    }
    else if (diagonal2_sum == 15 && this->board[0][2]!='0' && this->board[1][1]!=0 && this->board[2][0]!='0'){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
bool Numerical_TicTacToe<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Numerical_TicTacToe<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
Numerical_TicTacToe_Player<T>::Numerical_TicTacToe_Player(string name, T symbol): Player<T>(name, symbol) {}

template <typename T>
void Numerical_TicTacToe_Player<T>::getmove(int& x, int& y) {
    int number;
    cout << this->name << ", enter your number and position (e.g., '6 1 1'): ";
    cin >> number >> x >> y;
    this->symbol = number + '0';
}


template <typename T>
class Numerical_TicTacToe_Random_Player : public RandomPlayer<T>{
public:
    Numerical_TicTacToe_Random_Player(T symbol);
    void getmove(int &x, int &y) ;
};


template <typename T>
Numerical_TicTacToe_Random_Player<T>::Numerical_TicTacToe_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}



template <typename T>
void Numerical_TicTacToe_Random_Player<T>::getmove(int& x, int& y){
    x = rand() % this->dimension;
    y = rand() % this->dimension;
    this->symbol = (rand() % 9+1) + '0';
}


#endif //BOARDGAMEASS_NUMERICAL_TICTACTOE_H