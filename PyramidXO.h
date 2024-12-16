//
// Created by Elkashef on 12/2/2024.
//

#ifndef A2_T456_PYRAMIDXO_H
#define A2_T456_PYRAMIDXO_H
#include "BoardGame_Classes.h"
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <limits>
template <typename T>
class PyramidXO_Board : public Board<T>{
public:
    PyramidXO_Board();
    void display_board();
    bool update_board(int x, int y, T symbol);
    bool is_win();
    bool is_draw();
    bool game_is_over();
    void getcell(int x, int y){
        cout << this->board[x][y] << endl;
    }
};


template <typename T>
class PyramidXO_Player : public Player<T>{
public:
    PyramidXO_Player(string n,T symbol);
    void getmove(int& x, int& y);
};


template <typename T>
class PyramidXO_Random_Player : public RandomPlayer<T>{
public:
    PyramidXO_Random_Player(T symbol);
    void getmove(int& x,int& y);};


template <typename T>
class PyramidXO_Ai_Player : public Player<T>{
private:
    int calculateMinMax(T s, bool isMaximizing);
    std::pair<int, int> getBestMove();
public:
    PyramidXO_Ai_Player(T symbol);
    void getmove(int& x,int& y);
};



template <typename T>
PyramidXO_Board<T>::PyramidXO_Board() {
    this->rows = 3;
    this->columns = 5;
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
void PyramidXO_Board<T>::display_board() {
    int spaces = 20 ;
    int colmns_Left = 0;
    for(int i = 0;i <= this->rows-1;i++){
        for (int j = 0; j <= colmns_Left; j++) {
            for(int k = spaces;k > 0;k--){
                cout << " ";
            }
            cout << "(" + to_string(i) + "," + to_string(j) + "):";
            cout << setw(2) << "[" <<(this->board[i][j]) << "]"<<" ";
            spaces -= 10;
        }
        colmns_Left += 2;
        cout << endl;
    }
    cout << "------------------------------------------------------" << endl;
}

template <typename T>
bool PyramidXO_Board<T>::update_board(int x, int y, T symbol) {
    if(symbol == ' '){
        this->board[x][y] = ' ';
        this->n_moves--;
        return true;
    }
    if ((x < 0 || y < 0 || x >= this->rows || y >= this->columns) ||
        (this->board[x][y] != ' ' ||
         ((x == 0 && y >= 1 && y <= 4) || (x == 1 && y >= 3 && y <= 4)))) {
        return false;
    }
    else if(this->board[x][y] == ' '){
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
bool PyramidXO_Board<T>::is_win(){
    if ((this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0] && this->board[0][0] != ' ') ||
        (this->board[0][0] == this->board[1][2] && this->board[1][2] == this->board[2][4] && this->board[0][0] != ' ') ||
        (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != ' ')){
        return true;
    }
    for(int i = 0; i <= this->rows-1;i++){
        for(int j = 0; j <= this->columns-1;j++){
            if(this->board[i][j] !=' '){
                if (this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

template <typename T>
bool PyramidXO_Board<T>::is_draw() {
    if(!is_win()&&this->n_moves == 9){
        return true;
    }
    return false;
}


template <typename T>
bool PyramidXO_Board<T>::game_is_over() {
    if(is_win() || is_draw()){
        return true;
    }
    return false;
}



template <typename T>
PyramidXO_Player<T>::PyramidXO_Player(string n,T symbol):Player<T>(n,symbol){}


template <typename T>
void PyramidXO_Player<T>::getmove(int &x, int &y) {
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



template <typename T>
PyramidXO_Random_Player<T>::PyramidXO_Random_Player(T symbol):RandomPlayer<T>(symbol){}

template <typename T>
void PyramidXO_Random_Player<T>::getmove(int &x, int &y) {
    x = rand()%3;
    y = rand()%5;
}



template <typename T>
PyramidXO_Ai_Player<T>::PyramidXO_Ai_Player(T symbol) :Player<T>(symbol) {
    this->name = "Ai player";
}


template <typename T>
int PyramidXO_Ai_Player<T>::calculateMinMax(T s, bool isMaximizing) {
    if (this->boardPtr->is_win()) {
        return isMaximizing ? -1 : 1;
    } else if (this->boardPtr->is_draw()) {
        return 0;
    }
    int bestValue = isMaximizing ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    T opponentSymbol = (s == 'X') ? 'O' : 'X';
    int colmns_Left = 0;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j <= colmns_Left; j++) {
            if (this->boardPtr->update_board(i, j, s)) {
                int value = calculateMinMax(opponentSymbol, !isMaximizing);
                this->boardPtr->update_board(i, j, ' ');
                if (isMaximizing) {
                    bestValue = std::max(bestValue, value);
                } else {
                    bestValue = std::min(bestValue, value);
                }
            }
        }
        colmns_Left +=2;
    }
    return bestValue;
}
template <typename T>
std::pair<int, int> PyramidXO_Ai_Player<T>::getBestMove() {
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};
    T opponentSymbol = (this->symbol == 'X') ? 'O' : 'X';
    int colmns_Left = 0;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j <= colmns_Left; j++) {
            if (this->boardPtr->update_board(i, j, this->symbol)) {
                if (this->boardPtr->is_win()) {
                    this->boardPtr->update_board(i, j, ' ');
                    return {i, j};
                }
                this->boardPtr->update_board(i, j, ' ');
            }
        }
        colmns_Left+=2;
    }
    colmns_Left = 0;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j <= colmns_Left; j++) {
            if (this->boardPtr->update_board(i, j, opponentSymbol)) {
                if (this->boardPtr->is_win()) {
                    this->boardPtr->update_board(i, j, ' ');
                    return {i, j};
                }
                this->boardPtr->update_board(i, j, ' ');
            }
        }
        colmns_Left+=2;
    }
    colmns_Left = 0;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j <= colmns_Left; j++) {
            if (this->boardPtr->update_board(i, j, this->symbol)) {
                int moveValue = calculateMinMax(this->symbol, false);
                this->boardPtr->update_board(i, j, ' ');
                if (moveValue > bestValue) {
                    bestMove = {i, j};
                    bestValue = moveValue;
                }
            }
        }
        colmns_Left+=2;
    }
    return bestMove;
}


template <typename T>
void PyramidXO_Ai_Player<T>::getmove(int &x, int &y) {
    std::pair<int, int> bestMove = getBestMove();
    x = bestMove.first;
    y = bestMove.second;
}
#endif //A2_T456_PYRAMIDXO_H
