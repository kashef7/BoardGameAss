//
// Created by salma on 12/14/2024.
//

#ifndef BOARDGAMEASS_GAME3_H
#define BOARDGAMEASS_GAME3_H

using namespace std;

template <typename T>
class TicTacToeBoard : public Board<T>{
public:
    TicTacToeBoard();

    ~TicTacToeBoard();

    void display_board();

    bool update_board(int x,int y,T symbol);

    bool is_win();

    bool is_draw();

    bool game_is_over();


};

template <typename T>
TicTacToeBoard<T>::TicTacToeBoard() {
    this->rows = this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; ++j) {
            this->board[i][j] = ' ';
        }
    }
}

template <typename T>
TicTacToeBoard<T>::~TicTacToeBoard() {
    for (int i = 0; i < this->rows; ++i) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

template <typename T>
bool TicTacToeBoard<T>::update_board(int x, int y, T symbol){
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != ' ')
        return false;

    this->board[x][y] = symbol;
    this->n_moves++;
    return true;
}

template <typename T>
void TicTacToeBoard<T>::display_board() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            cout << this->board[i][j];
            if (j < this->columns - 1) cout << " ";
        }
        cout << endl;
        if (i < this->rows - 1) {
            cout << "-------------------" << endl;
        }
    }
    cout << endl;
}

template <typename T>
bool TicTacToeBoard<T>::is_win() {

    for (int i = 0; i < this->rows; ++i) {
        if (this->board[i][0] != ' ' &&
            this->board[i][0] == this->board[i][1] &&
                this->board[i][1] ==  this->board[i][2] &&
                this->board[i][2] ==  this->board[i][3] &&
                this->board[i][3] ==  this->board[i][4])
            return true;
    }

    // Check columns
    for (int j = 0; j <  this->columns; ++j) {
        if ( this->board[0][j] != ' ' &&
                this->board[0][j] ==  this->board[1][j] &&
                this->board[1][j] ==  this->board[2][j] &&
                this->board[2][j] ==  this->board[3][j] &&
                this->board[3][j] ==  this->board[4][j])
            return true;
    }

    // Check diagonals
    if ( this->board[0][0] != ' ' &&
            this->board[0][0] ==  this->board[1][1] &&
            this->board[1][1] ==  this->board[2][2] &&
            this->board[2][2] ==  this->board[3][3] &&
            this->board[3][3] ==  this->board[4][4])
        return true;

    if ( this->board[0][4] != ' ' &&
            this->board[0][4] ==  this->board[1][3] &&
            this->board[1][3] ==  this->board[2][2] &&
            this->board[2][2] ==  this->board[3][1] &&
            this->board[3][1] ==  this->board[4][0])
        return true;

    return false;
}
template <typename T>
bool TicTacToeBoard<T>::is_draw() {
    return this->n_moves == this->rows * this->columns && !is_win();
}

template <typename T>
bool TicTacToeBoard<T>::game_is_over() {
    return is_win() || is_draw();
}

/*template <typename T>
class TicTacToeBoard : public Board<char> {
public:
    TicTacToeBoard() {


    ~TicTacToeBoard() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    bool update_board(int x, int y, char symbol) override {
        if (x < 0 || x >= rows || y < 0 || y >= columns || board[x][y] != ' ')
            return false;

        board[x][y] = symbol;
        n_moves++;
        return true;
    }

    void display_board() override {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << board[i][j];
                if (j < columns - 1) cout << " ";
            }
            cout << endl;
            if (i < rows - 1) {
                cout << "-------------------" << endl;
            }
        }
        cout << endl;
    }

    bool is_win() override {
        // Check rows
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] != ' ' &&
                board[i][0] == board[i][1] &&
                board[i][1] == board[i][2] &&
                board[i][2] == board[i][3] &&
                board[i][3] == board[i][4])
                return true;
        }

        // Check columns
        for (int j = 0; j < columns; ++j) {
            if (board[0][j] != ' ' &&
                board[0][j] == board[1][j] &&
                board[1][j] == board[2][j] &&
                board[2][j] == board[3][j] &&
                board[3][j] == board[4][j])
                return true;
        }

        // Check diagonals
        if (board[0][0] != ' ' &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2] &&
            board[2][2] == board[3][3] &&
            board[3][3] == board[4][4])
            return true;

        if (board[0][4] != ' ' &&
            board[0][4] == board[1][3] &&
            board[1][3] == board[2][2] &&
            board[2][2] == board[3][1] &&
            board[3][1] == board[4][0])
            return true;

        return false;
    }

    bool is_draw() override {
        return n_moves == rows * columns && !is_win();
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }
};*/
template <typename T>
class TicTacToeHumanPlayer : public Player<char> {
public:
    TicTacToeHumanPlayer(std::string n, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
TicTacToeHumanPlayer<T>::TicTacToeHumanPlayer(string n, T symbol) :Player<T>(n,symbol) {};

template <typename T>
void TicTacToeHumanPlayer<T>::getmove(int &x, int &y) {
    while (true) {
        cout << this->name << ", enter your move (row and column, 0-4): ";
        if (cin >> x >> y) {
            if (x >= 0 && x < 5 && y >= 0 && y < 5) {
                return; // Valid move, exit the loop
            } else {
                cout << "Invalid move, try again." << endl;
            }
        } else {
            cout << "Invalid input, try again." << endl;
            cin >> x >> y;

        }
    }
}



#endif //BOARDGAMEASS_GAME3_H
