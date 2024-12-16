#include"Boardgames.h"
#include <iostream>
template <typename T>
class MisereTicTacToeBoard : public Board<T>{
public:
    MisereTicTacToeBoard();

    ~MisereTicTacToeBoard();

    void display_board();

    bool update_board(int x,int y,T symbol);

    bool is_win();

    bool is_draw();

    bool game_is_over();

};
template <typename T>
MisereTicTacToeBoard<T>::MisereTicTacToeBoard() {
    this->rows = this->columns = 3;;
    this->board = new char*[this->rows];
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; ++j) {
            this->board[i][j] = ' ';
        }
    }
}
template <typename T>
MisereTicTacToeBoard<T>::~MisereTicTacToeBoard() {
    for (int i = 0; i < this->rows; ++i) {
        delete[] this->board[i];
    }
    delete[] this->board;
}
template <typename T>
bool MisereTicTacToeBoard<T>::update_board(int x, int y, T symbol){
    if (x < 0 || x >= this->rows|| y < 0 || y >=this-> columns || this->board[x][y] != ' ') {
        return false;
    }

    this->board[x][y] = symbol;
    this->n_moves++;
    return true;
}

template <typename T>
void MisereTicTacToeBoard<T>::display_board() {
    cout << "-------------" << endl;
    for (int i = 0; i <  this->rows; i++) {
        cout << "| ";
        for (int j = 0; j <  this->columns; j++) {
            cout <<  this->board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}


template <typename T>
bool MisereTicTacToeBoard<T>::is_win() {

    for (int i = 0; i < this->rows; i++) {
        // Check rows
        if (this->board[i][0] ==this-> board[i][1] && this->board[i][1] ==this-> board[i][2] && this->board[i][0] != ' ') {
            return true;
        }
        // Check columns
        if (this->board[0][i] ==this-> board[1][i] && this->board[1][i] == this->board[2][i] && this-> board[0][i] != ' ') {
            return true;
        }
    }
    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != ' ') ||
        (this->board[0][2] == this->board[1][1] && this-> board[1][1] == this->board[2][0] && this->board[0][2] != ' ')) {
        return true;
    }
    return false;
}
template <typename T>
bool MisereTicTacToeBoard<T>::is_draw() {
    return this->n_moves == this->rows * this->columns && !is_win();
}

template <typename T>
bool MisereTicTacToeBoard<T>::game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
class MisereTicTacToeHumanPlayer : public Player<char> {
public:
    MisereTicTacToeHumanPlayer (std::string n, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
MisereTicTacToeHumanPlayer <T>::MisereTicTacToeHumanPlayer (string n, T symbol) :Player<T>(n,symbol) {};

template <typename T>
void MisereTicTacToeHumanPlayer <T>::getmove(int &x, int &y) {
    while (true) {
        cout << this->name << ", enter your move (row and column, 0-2): "; // 3x3 board range
        if (cin >> x >> y) {
            if (x >= 0 && x < 3 && y >= 0 && y < 3) { // Validate for 3x3
                return; // Valid move
            } else {
                cout << "Invalid move, try again." << endl;
            }
        } else {
            cout << "Invalid input, try again." << endl;
            cin >> x >> y;

        }
    }
}
int main() {

    // Create the players
    MisereTicTacToeHumanPlayer<char> human("Player 1", 'X');
    MisereTicTacToeHumanPlayer<char> computer("Computer", 'O');
    Player<char> *players[2] = {&human, &computer};

    MisereTicTacToeBoard<char> board;
    GameManager<char> game(&board, players);
    game.run();
    return 0;
}