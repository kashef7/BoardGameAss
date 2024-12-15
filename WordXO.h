//
// Created by Elkashef on 12/2/2024.
//

#ifndef UNTITLED1_WORDXO_H
#define UNTITLED1_WORDXO_H
#include "BoardGame_Classes.h"
#include <fstream>
#include <cstdlib>

template <typename T>
class WordXO_Board: public Board<T> {
public:
    WordXO_Board();
    void display_board();
    bool update_board(int x, int y, T symbol);
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class WordXO_Player : public Player<T>{
public:
    WordXO_Player(string name,T symbol);
    void getmove(int& x,int& y);
};

template <typename T>
class WordXO_Random_Player : public RandomPlayer<T>{
public:
    WordXO_Random_Player(T symbol);
    void getmove(int& x, int& y);
};


template <typename T>
WordXO_Board<T>::WordXO_Board() {
    this->rows = 3;
    this->columns = 3;
    this->n_moves = 0;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '0';
        }
    }
}


template <typename T>
void WordXO_Board<T>::display_board() {
    for(int i = 0;i <= 2;i++){
        for(int j = 0;j <= 2;j++){
            cout << "( " << i << ", " << j <<") ";
            cout << "[" << this->board[i][j] << "]";
        }
        cout << endl;
    }
    cout << "\n" << "-----------------------------------------------------\n";
}


template <typename T>
bool WordXO_Board<T>::update_board(int x, int y, T symbol) {
    if ((x < 0 || y < 0 || x >= this->rows || y >= this->columns) ||
        (this->board[x][y] != '0')){
        return false;
    }
    else if(this->board[x][y] == '0'){
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    else{
        return false;
    }
}



template <typename T>
bool WordXO_Board<T>::is_win() {
    string word = "";
    string fileWord;
    ifstream file("dic.txt");
    for(int i = 0;i <= 2;i++){
        for(int j = 0;j <= 2;j++){
            word += this->board[i][j];
        }
        file.clear();
        file.seekg(0);
        while (file >> fileWord) {
            if ( fileWord == word) {
                cout << "winning word:" << word <<endl;
                return true;
            }
        }
        word = "";
    }
    for(int i = 0;i <= 2;i++){
        for(int j = 0;j <= 2;j++){
            word += this->board[j][i];
        }
        file.clear();
        file.seekg(0);
        while (file >> fileWord) {
            if ( fileWord == word) {
                cout << "winning word:" << word <<endl;
                return true;
            }
        }
        word = "";
    }
    for(int i = 0;i <= 2;i++){
        word += this->board[i][i];
    }
    file.clear();
    file.seekg(0);
    while (file >> fileWord) {
        if ( fileWord == word) {
            cout << "winning word:" << word <<endl;
            return true;
        }
    }
    word = "";
    word += this->board[0][2];
    word += this->board[1][1];
    word += this->board[2][0];
    file.clear();
    file.seekg(0);
    while (file >> fileWord) {
        if ( fileWord == word) {
            cout << "winning word:" << word <<endl;
            return true;
        }
    }
    return false;
}


template <typename T>
bool WordXO_Board<T>::is_draw() {
    if(!is_win()&&this->n_moves == 9){
        return true;
    }
    return false;
}

template <typename T>
bool WordXO_Board<T>::game_is_over() {
    if(is_win() || is_draw()){
        return true;
    }
    return false;
}


template <typename T>
WordXO_Player<T>::WordXO_Player(string name, T symbol):Player<T>(name,symbol) {}

template <typename T>
void WordXO_Player<T>::getmove(int &x, int &y) {
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
    cout << "Enter letter:" << endl;
    cin >> this->symbol;
}


template <typename T>
WordXO_Random_Player<T>::WordXO_Random_Player(T symbol) : RandomPlayer<T>(symbol){}

template <typename T>
void WordXO_Random_Player<T>::getmove(int &x, int &y) {
    this->symbol = char(('a' + rand() % 26));
    x = rand()%3;
    y = rand()%5;
}



#endif //UNTITLED1_WORDXO_H
