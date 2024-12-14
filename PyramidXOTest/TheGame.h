#ifndef THEGAME_H
#define THEGAME_H

#include "BoardGame_Classes.h"
#include <iomanip>
#include <cstdlib>
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
    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter y:" << endl;
    cin >> y;
}



template <typename T>
PyramidXO_Random_Player<T>::PyramidXO_Random_Player(T symbol):RandomPlayer<T>(symbol){}

template <typename T>
void PyramidXO_Random_Player<T>::getmove(int &x, int &y) {
    x = rand()%3;
    y = rand()%5;
}








#endif // THEGAME_H
