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

    T getCell(int row, int col) const;

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
T Four_in_a_Row<T>::getCell(int row, int col) const {
    if (row >= 0 && row < this->rows && col >= 0 && col < this->columns) {
        return this->board[row][col];
    }
    return ' '; // Return empty space for out-of-bounds access
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
bool Four_in_a_Row<T>::update_board(int x, int y, T symbol) {
    // Bounds check
    if (y < 0 || y >= this->columns) {
        return false;
    }

    // If trying to place a blank (undo move)
    if (symbol == ' ') {
        // Start from the top of the column and find the first non-empty cell to remove
        for (int z = 0; z < this->rows; z++) {
            if (this->board[z][y] != ' ') {
                this->board[z][y] = ' ';
                this->n_moves--;
                return true;
            }
        }
        return false; // Column was already empty
    }

    // Regular move: find the lowest empty spot in the column
    for (int z = this->rows - 1; z >= 0; z--) {
        if (this->board[z][y] == ' ') {
            this->board[z][y] = toupper(symbol);
            this->n_moves++;
            return true;
        }
    }

    // Column is full
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
class Four_in_a_Row_Player : public Player<T> {
public:
    Four_in_a_Row_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
Four_in_a_Row_Player<T>::Four_in_a_Row_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Four_in_a_Row_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move y (0 to 6) : \n";
    x=0;
    cin >> y;

}


template <typename T>
class Four_in_a_a_Row_MinMax_Player : public Player<T> {
public:
    Four_in_a_a_Row_MinMax_Player(T symbol);

    void getmove(int& x, int& y) override;

private:
    int calculateMinMax(T s, bool isMaximizing,int depth);
    int getBestMove();
    int countConsecutive(int row, int col, T s);
    int evaluateBoard(T s);
};




template <typename T>
Four_in_a_a_Row_MinMax_Player<T>::Four_in_a_a_Row_MinMax_Player(T symbol): Player<T>(symbol) {
    this->name = "AI Player";
}

template <typename T>
void Four_in_a_a_Row_MinMax_Player<T>::getmove(int& x, int& y) {
    int bestMove = getBestMove();
    x = 0;
    y = bestMove;
}
template <typename T>
int Four_in_a_a_Row_MinMax_Player<T>::calculateMinMax(T s, bool isMaximizing, int depth) {
    if (depth == 0 || this->boardPtr->is_win() || this->boardPtr->is_draw()) {
        return evaluateBoard(s);
    }

    int bestValue = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();
    T opponentSymbol = (s == 'X') ? 'O' : 'X';

    for (int j = 0; j < 7; ++j) {
        if (this->boardPtr->update_board(0, j, isMaximizing ? s : opponentSymbol)) {
            int value = calculateMinMax(s, !isMaximizing, depth - 1);
            this->boardPtr->update_board(0, j, ' '); // Undo move

            if (isMaximizing) {
                bestValue = max(bestValue, value);
            } else {
                bestValue = min(bestValue, value);
            }
        }
    }

    return bestValue;
}

template <typename T>
int Four_in_a_a_Row_MinMax_Player<T>::evaluateBoard(T s) {
    int score = 0;

    T opponentSymbol = (s == 'X') ? 'O' : 'X';

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            auto* fourInARowBoard = dynamic_cast<Four_in_a_Row<T>*>(this->boardPtr);
            if (fourInARowBoard) {
                if (fourInARowBoard->getCell(i, j) == s) {
                    score += countConsecutive(i, j, s);
                } else if (fourInARowBoard->getCell(i, j) == opponentSymbol) {
                    score -= countConsecutive(i, j, opponentSymbol);
                }
            }

        }
    }

    return score;
}

template <typename T>
int Four_in_a_a_Row_MinMax_Player<T>::countConsecutive(int row, int col, T s) {
    int count = 0;

    const int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    auto* fourInARowBoard = dynamic_cast<Four_in_a_Row<T>*>(this->boardPtr);
    if (fourInARowBoard) {
        for (const auto& dir : directions) {
            int consecutive = 0;

            for (int k = 0; k < 4; ++k) {
                int r = row + k * dir[0];
                int c = col + k * dir[1];

                if (r >= 0 && r < 5 && c >= 0 && c < 7 &&
                    fourInARowBoard->getCell(r, c) == s) {
                    ++consecutive;
                } else {
                    break;
                }
            }

            // Assign scores based on consecutive matches
            switch (consecutive) {
                case 4: count += 1000; break; // Win
                case 3: count += 50; break;  // Close to winning
                case 2: count += 10; break;  // Small advantage
            }
        }
    }
    return count;
}

template <typename T>
int Four_in_a_a_Row_MinMax_Player<T>::getBestMove() {
    int bestMove = -1;
    int bestValue = std::numeric_limits<int>::min();

    for (int j = 0; j < 7; ++j) {
        if (this->boardPtr->update_board(0, j, this->symbol)) {
            int moveValue = calculateMinMax(this->symbol, false, 4); // Increase depth for better AI
            this->boardPtr->update_board(0, j, ' '); // Undo move

            if (moveValue >= bestValue) {
                bestMove = j;
                bestValue = moveValue;
            }
        }
    }

    return bestMove != -1 ? bestMove : 3; // Select middle if no move found
}


#endif //BOARDGAMEASS_FOUR_IN_A_ROW_H