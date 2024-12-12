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

    void display_board();

    bool update_board(int x,int y,T symbol);

    bool is_win();

    bool is_draw();

    bool game_is_over();

};
template <typename T>
class Four_in_a_Row_Player : public Player<T> {
public:
    Four_in_a_Row_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

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
        if (symbol == ' '){
            this->n_moves--;
            this->board[x][y] = ' ';
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(symbol);
        }
        return false;
    }
    // Check if the cell is empty
    if (this->board[x][y] != ' ') {
        return false;
    }
    for (int z=4; z>=0;z-- ){
        if (this->board[z][y]==' '){
            this->board[z][y] = symbol;
            this->n_moves+=1;
            return true;
        }
    }
    cout << "Invalid move: Column is full." << endl;
    return false;
}

template <typename T>
bool Four_in_a_Row<T> :: is_win() {
    for ( int i=4 ; i>=0 ; i--){
        for ( int j=0 ; j<=3 ; j++ ){
            if (this->board[i][j] == this->board[i][j+1] &&
                this->board[i][j+1] == this->board[i][j+2] &&
                this->board[i][j+2] == this->board[i][j+3] &&
                this->board[i][j] != ' '){
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
                return true;
            }
        }
    }
    return false;
}
template <typename T>
bool Four_in_a_Row<T>::is_draw() {
    return (this->n_moves == 42 && !is_win());
}

template <typename T>
bool Four_in_a_Row<T>::game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
Four_in_a_Row_Player<T>::Four_in_a_Row_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Four_in_a_Row_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move y (0 to 6) : \n";
    x=0;
    cin >> y;

}


/*
template <typename T>
class Four_in_a_a_Row_MinMax_Player : public Player<T> {
public:
    Four_in_a_a_Row_MinMax_Player(T symbol);

    void getmove(int& x, int& y) override;

private:
    int calculateMinMax(T s, bool isMaximizing);
    pair<int, int> getBestMove();
};




template <typename T>
Four_in_a_a_Row_MinMax_Player<T>::Four_in_a_a_Row_MinMax_Player(T symbol): Player<T>(symbol) {
    this->name = "AI Player";
}

template <typename T>
void Four_in_a_a_Row_MinMax_Player<T>::getmove(int& x, int& y) {
    if (!this->boardPtr) {
        cerr << "Error: AI player is not linked to a board!" << endl;
        return;
    }
    cout << "AI is thinking...\n";
    pair<int, int> bestMove = getBestMove();
    x = bestMove.first;
    y = bestMove.second;

    cout << "AI chose move: (" << x << ", " << y << ")\n";
}


template <typename T>
int Four_in_a_a_Row_MinMax_Player<T>::calculateMinMax(T s, bool isMaximizing) {
    if (this->boardPtr->is_win()) {
        return isMaximizing ? 1 : 3;
    } else if (this->boardPtr->is_draw()) {
        return 2;
    }

    int bestValue = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();
    T opponentSymbol = (s == 'X') ? 'O' : 'X';

    for (int i = 0; i < 5; ++i) {
        for (int j = 7; j >= 0; --j) {
            if (this->boardPtr->update_board(i, j, s)) {
                int value = calculateMinMax(opponentSymbol, !isMaximizing);
                this->boardPtr->update_board(i, j, ' ');

                if (isMaximizing) {
                    bestValue = max(bestValue, value);
                } else {
                    bestValue = min(bestValue, value);
                }
            }
        }
    }
    return bestValue;
}

template <typename T>
pair<int, int> Four_in_a_a_Row_MinMax_Player<T>::getBestMove() {
    int bestValue = numeric_limits<int>::min(); // Start with worst value
    pair<int, int> bestMove = {0, 0};        // Default invalid move
    T opponentSymbol = (this->symbol == 'X') ? 'O' : 'X';

    // First, check if we can win in the next move
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (this->boardPtr->update_board(i, j, this->symbol)) {
                if (this->boardPtr->is_win()) {
                    this->boardPtr->update_board(i, j, ' '); // Undo move
                    return {i, j}; // Winning move found
                }
                this->boardPtr->update_board(i, j, ' '); // Undo move
            }
        }
    }

    // Second, block opponent's winning move
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (this->boardPtr->update_board(i, j, opponentSymbol)) {
                if (this->boardPtr->is_win()) {
                    this->boardPtr->update_board(i, j, ' '); // Undo move
                    return {i, j}; // Block opponent's winning move
                }
                this->boardPtr->update_board(i, j, ' '); // Undo move
            }
        }
    }

    // Use MinMax to find the best move
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (this->boardPtr->update_board(i, j, this->symbol)) { // Try move
                int moveValue = calculateMinMax(this->symbol, false);
                this->boardPtr->update_board(i, j, ' '); // Undo move
                cout << "Move (" << i << ", " << j << ") has value: " << moveValue << "\n";

                if (moveValue > bestValue) {
                    bestMove = {i, j};
                    bestValue = moveValue;
                    cout << "Best move updated to (" << i << ", " << j << ") with value: " << bestValue << "\n";
                }
            }
        }
    }
    return bestMove;
}*/






#endif //BOARDGAMEASS_FOUR_IN_A_ROW_H