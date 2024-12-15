//
// Created by Elkashef on 12/14/2024.
//

#ifndef BOARDGAMEASS_ULTIMATETICTACTOE_H
#define BOARDGAMEASS_ULTIMATETICTACTOE_H

#include "BoardGame_Classes.h"
#include <cstdlib>

template<typename T>
class Ultimate_Board: public Board<T>{
private:
    char arr[9];
    char small_boards[9][3][3];
    int checkWin;
    int checkDraw;
public:
    Ultimate_Board();
    void display_board();
    bool update_board(int x, int y, T symbol);
    bool is_win();
    bool is_draw();
    bool game_is_over();
    bool is_small_win();
    bool is_small_draw();
};

template<typename T>
class Ultimate_Player: public Player<char>{
public:
    Ultimate_Player(string name,T symbol);
    void getmove(int& x,int& y);
};

template<typename T>
class Ultimate_Random_Player: public RandomPlayer<char>{
public:
    Ultimate_Random_Player(T symbol);
    void getmove(int& x,int& y);
};











template<typename T>
Ultimate_Player<T>::Ultimate_Player(string name, T symbol):Player<T>(name,symbol) {
}

template <typename T>
void Ultimate_Player<T>::getmove(int &x, int &y) {
    cout << this->name << "'s Turn " << endl;

    while (true) {
        cout << "Enter x: ";
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter an int" << endl;
            continue;
        } else {
            break;
        }
    }
    while (true) {
        cout << "Enter y: ";
        cin >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter an int" << endl;
            continue;
        } else {
            break;
        }
    }
}

template<typename T>
Ultimate_Random_Player<T>::Ultimate_Random_Player(T symbol):RandomPlayer<char>(symbol) {}

template<typename T>
void Ultimate_Random_Player<T>::getmove(int &x, int &y) {
    x = rand()%9;
    y = rand()%9;
}


template <typename T>
Ultimate_Board<T>::Ultimate_Board() {
    this->rows = 9;
    this->columns = 9;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;

    for (int board = 0; board < 9; board++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                small_boards[board][i][j] = ' ';
            }
        }
        arr[board] = ' ';
    }
}

template <typename T>
bool Ultimate_Board<T>::update_board(int x, int y, T symbol) {
    int small_board_row = x / 3;
    int small_board_col = y / 3;
    int small_board_index = small_board_row * 3 + small_board_col;

    if (arr[small_board_index] != ' ') {
        return false;
    }

    if ((x < 0 || y < 0 || x >= this->rows || y >= this->columns) ||
        (this->board[x][y] != ' ')){
        return false;
    }

    int local_x = x % 3;
    int local_y = y % 3;

    if (small_boards[small_board_index][local_x][local_y] == ' '){
        this->board[x][y] = toupper(symbol);
        small_boards[small_board_index][local_x][local_y] = toupper(symbol);
        this->n_moves++;

        if(is_small_win()){
            arr[checkWin] = toupper(symbol);
        }
        if(is_small_draw()){
            arr[checkDraw] = 'D';
        }
        return true;
    }

    return false;
}

template<typename T>
bool Ultimate_Board<T>::is_small_win() {
    for (int board_index = 0; board_index < 9; board_index++) {
        char (&current_board)[3][3] = small_boards[board_index];

        if (arr[board_index] != ' ') {
            continue;
        }


        for (int i = 0; i < 3; i++) {
            if (current_board[i][0] == current_board[i][1] &&
                current_board[i][0] == current_board[i][2] &&
                current_board[i][0] != ' ') {
                checkWin = board_index;
                return true;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (current_board[0][j] == current_board[1][j] &&
                current_board[0][j] == current_board[2][j] &&
                current_board[0][j] != ' ') {
                checkWin = board_index;
                return true;
            }
        }

        if ((current_board[0][0] == current_board[1][1] &&
             current_board[0][0] == current_board[2][2] &&
             current_board[0][0] != ' ') ||
            (current_board[0][2] == current_board[1][1] &&
             current_board[0][2] == current_board[2][0] &&
             current_board[0][2] != ' ')) {
            checkWin = board_index;
            return true;
        }
    }

    return false;
}

template<typename T>
bool Ultimate_Board<T>::is_small_draw() {
    bool any_draw = false;
    for (int board_index = 0; board_index < 9; board_index++) {
        if (arr[board_index] != ' ') {
            continue;
        }
        char (&current_board)[3][3] = small_boards[board_index];
        bool is_full = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (current_board[i][j] == ' ') {
                    is_full = false;
                    break;
                }
            }
            if (!is_full) break;
        }
        if (is_full) {
            arr[board_index] = 'D';
            checkDraw = board_index;
            any_draw = true;
        }
    }
    return any_draw;
}



template <typename T>
void Ultimate_Board<T>::display_board() {
    int i = 0;
    int j;
    for(int board_row = 0; board_row < 9; board_row += 3) {
        for(int row_in_board = 0; row_in_board < 3; row_in_board++) {
            j = 0;
            for(int board_col = 0; board_col < 9; board_col += 3) {
                for(int col_in_board = 0; col_in_board < 3; col_in_board++) {
                    int board_index = (board_row / 3) * 3 + (board_col / 3);
                    cout << "(" << i << "," << j << ")"<< small_boards[board_index][row_in_board][col_in_board] << " ";
                    j++;
                }
                cout << "| ";
            }
            cout << endl;
            if((i + 1) % 3 == 0) {
                for(int k = 0; k < 68;k++) {
                    cout << "-";
                }
                cout << endl;
            }
            i++;
        }

    }
    cout << "\nBoard Status: " << endl;
    for(int i = 0; i < 9; i++) {
        cout <<"["<< arr[i] << "]";
        if((i+1)%3 ==0){
            cout << endl;
        }
    }
    cout << endl;
}




template <typename T>
bool Ultimate_Board<T>::is_win() {
    if((arr[0] == arr[1] && arr[0] == arr[2] && arr[0] != ' ') ||
       (arr[3] == arr[4] && arr[3] == arr[5] && arr[3] != ' ') ||
       (arr[6] == arr[7] && arr[6] == arr[8] && arr[6] != ' ') ||
       (arr[0] == arr[3] && arr[0] == arr[6] && arr[0] != ' ') ||
       (arr[1] == arr[4] && arr[1] == arr[7] && arr[1] != ' ') ||
       (arr[2] == arr[5] && arr[2] == arr[8] && arr[2] != ' ') ||
       (arr[0] == arr[4] && arr[0] == arr[8] && arr[0] != ' ') ||
       (arr[2] == arr[4] && arr[2] == arr[6] && arr[2] != ' ')){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
bool Ultimate_Board<T>::is_draw() {
    for(int i = 0;i <=8 ; i++){
        if(arr[i] == ' '){
            return false;
        }
    }
    if (!is_win()){
        return true;
    }
}

template <typename T>
bool Ultimate_Board<T>::game_is_over() {
    if(is_win() || is_draw()){
        return true;
    }
    return false;
}

#endif //BOARDGAMEASS_ULTIMATETICTACTOE_H
