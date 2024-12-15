#ifndef THEGAME_H
#define THEGAME_H
#include "BoardGame_Classes.h"
#include <iomanip>
#include <cstdlib>
using namespace std;

inline int globalmoves = 0;

template <typename T>
class SUS:public Board<T> {
public:
    int countplayer1=0;
    int countplayer2=0;
    SUS();
    ~SUS();
    void display_board () ;
    bool update_board (int x , int y , T symbol);
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    bool** counted;

    bool player2iswin();

    int getPlayer1Count() const;
    int getPlayer2Count() const;
};
template <typename T>
class SUS_Player : public Player<T> {
public:
    SUS_Player(string name, T symbol);
    void getmove(int& x, int& y) ;
};

template <typename T>
SUS<T>::SUS() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    this->counted = new bool*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        this->counted[i] = new bool[this->columns];

        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
            this->counted[i][j] = false;
        }
    }
    this->n_moves = 0;
    globalmoves=0;
}

template <typename T>
int SUS<T>::getPlayer1Count() const {
    return countplayer1;
}

template <typename T>
int SUS<T>::getPlayer2Count() const {
    return countplayer2;
}



template <typename T>
void SUS<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T>
bool SUS<T>::player2iswin(){
    if(countplayer2>countplayer1 && this->n_moves>=9){
        return true;
    }
    else{
        return false;
    }
}


template <typename T>
bool SUS<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            globalmoves--;
            this->board[x][y] = 0;
        } else {
            this->n_moves++;
            globalmoves++;
            this->board[x][y] = toupper(mark);
        }

        for (int i = 0; i < this->rows; i++) {
            if (!counted[i][1] && this->board[i][0] == 'S' && this->board[i][1] == 'U' && this->board[i][2] == 'S') {
                counted[i][1] = true;
                if (mark == 'S') countplayer1++;
                else if (mark == 'U') countplayer2++;
            }
        }

        for (int i = 0; i < this->columns; i++) {
            if (!counted[1][i] && this->board[0][i] == 'S' && this->board[1][i] == 'U' && this->board[2][i] == 'S') {
                counted[1][i] = true;
                if (mark == 'S') countplayer1++;
                else if (mark == 'U') countplayer2++;
            }
        }

        if (true) {
            if (this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') {
                counted[1][1] = true;
                if (mark == 'S') countplayer1++;
                else if (mark == 'U') countplayer2++;
            }
            if (this->board[0][2] == 'S' && this->board[1][1] == 'U' && this->board[2][0] == 'S') {
                counted[1][1] = true;
                if (mark == 'S') countplayer1++;
                else if (mark == 'U') countplayer2++;
            }
        }

        return true;
    }else if (this->n_moves==10){
        return true;
    }
    return false;
}



template <typename T>
bool SUS<T>:: is_win() {
    if (this->n_moves == 9) {
        if (countplayer1 > countplayer2) {
            return true;
        }
        else if (countplayer1 < countplayer2) {
            this->n_moves++;
            globalmoves++;
            return false;
        }
        else {
            this->n_moves++;
            globalmoves++;
            return false;
        }
    }
    else if (this->n_moves == 10) {
        return true;
    }
    else{
        return false;
    }
}
template <typename T>
bool SUS<T>::is_draw(){
    if (countplayer1==countplayer2 && this->n_moves==10 && !this->player2iswin()) {
        return true;
    }
    else{
        return false;
    }
}
template <typename T>
bool SUS<T>::game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
SUS<T>::~SUS() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
        delete[] this->counted[i];
    }
    delete[] this->board;
    delete[] this->counted;
}

template <typename T>
SUS_Player<T>::SUS_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void SUS_Player<T>::getmove(int& x, int& y) {
    if (globalmoves%10==0 && globalmoves != 0 ){
        x=0;
        y=0;
    }
    else {
        cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
        cin >> x >> y;
    }
}




template <typename T>
class SUS_Random_Player : public RandomPlayer<T>{
public:
    SUS_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};


template <typename T>
SUS_Random_Player<T>::SUS_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void SUS_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}





#endif // THEGAME_H

