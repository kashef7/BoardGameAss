// main.cpp
#include <string>
#include <limits>
#include "PyramidXO.h"
#include "WordXO.h"
#include "Four_in_a_Row.h"
#include "Numerical_TicTacToe.h"
#include "sus.h"
using namespace std;
static bool ComputerOrNotMain= false;
template<typename T>
Player<T>* getPlayer(const string& gameType, const char symbol) {
    char ch;
    while (true) {
        cout << "Choose player Type\nA)Human\nB)Computer\nC)AI\n";
        cin >> ch;
        if (toupper(ch) == 'A') {
            string playerName;
            cout << "Enter player name: ";
            cin >> playerName;
            if (gameType == "Pyramid") return new PyramidXO_Player<T>(playerName, symbol);
            else if (gameType == "Word") return new WordXO_Player<T>(playerName, symbol);
            else if (gameType == "Four") return new Four_in_a_Row_Player<T>(playerName, symbol);
            else if (gameType == "Numerical") return new Numerical_TicTacToe_Player<T>(playerName, symbol);
            else if (gameType == "SUS") return new SUS_Player<T>(playerName, symbol);
        } else if (toupper(ch) == 'B') {
            if (gameType == "Pyramid") return new PyramidXO_Random_Player<T>(symbol);
            else if (gameType == "Word") return new WordXO_Random_Player<T>(symbol);
            else if (gameType == "Four") return new Four_in_a_Row_Random_Player<T>(symbol);
            else if (gameType == "SUS") return new SUS_Random_Player<T>(symbol);
            else if (gameType == "Numerical"){
                ComputerOrNotMain= true;
                return new Numerical_TicTacToe_Random_Player<T>(symbol);
            }
        } else if(toupper(ch) == 'C'){
            if (gameType == "Four") return new Four_in_a_a_Row_MinMax_Player<T>(symbol);
        }
        else {
            cout << "Please enter a valid input.\n";
        }
    }
}
int main() {
    Player<char>* players[2];
    char ch;
    while (true) {
        cout << "Welcome to the Arcade\n";
        while (true) {
            cout << "choose which game you want to play\nA)Pyramid X_O\nB)Word X_O\nC)Four in a row\nD)Numerical tictactoe\nE)SUS\nQ)Quit\n";
            cin >> ch;
            if (toupper(ch) == 'A') {
                auto* Pyramid_Board = new PyramidXO_Board<char>();
                cout << "starting Pyramid X_O\n";
                cout << "PLAYER 1\n";
                players[0] = getPlayer<char>("Pyramid",'X');
                cout << "PLAYER 2\n";
                players[1] = getPlayer<char>("Pyramid",'O');
                GameManager<char> pyramidXO(Pyramid_Board,players);
                pyramidXO.run();
                players[0] = nullptr;
                players[1] = nullptr;
                delete Pyramid_Board;
            }
            else if (toupper(ch) == 'B') {
                auto* Word_Board = new WordXO_Board<char>();
                cout << "starting Word X_O\n";
                cout << "PLAYER 1\n";
                players[0] = getPlayer<char>("Word",'X');
                cout << "PLAYER 2\n";
                players[1] = getPlayer<char>("Word",'O');
                GameManager<char> wordXO(Word_Board,players);
                wordXO.run();
                players[0] = nullptr;
                players[1] = nullptr;
                delete Word_Board;
            }
            else if (toupper(ch) == 'C') {
                auto* Fourinrow_Board = new Four_in_a_Row<char>();
                cout << "Starting Four in a Row\n";

                cout << "PLAYER 1\n";
                players[0] = getPlayer<char>("Four", 'X');  // Create Player 1
                cout << "PLAYER 2\n";
                players[1] = getPlayer<char>("Four", 'O');  // Create Player 2

                // Set the board for AI players
                if (auto* aiPlayer = dynamic_cast<Four_in_a_a_Row_MinMax_Player<char>*>(players[0])) {
                    aiPlayer->setBoard(Fourinrow_Board);
                }
                if (auto* aiPlayer = dynamic_cast<Four_in_a_a_Row_MinMax_Player<char>*>(players[1])) {
                    aiPlayer->setBoard(Fourinrow_Board);
                }

                GameManager<char> fourinrow(Fourinrow_Board, players);
                fourinrow.run();

                players[0] = nullptr;
                players[1] = nullptr;
                delete Fourinrow_Board;
            }
            else if (toupper(ch) == 'D') {
                auto* NumericTicTacToe_Board = new Numerical_TicTacToe<char>();
                cout << "starting Numerical Tic Tac Toe\n";
                cout << "PLAYER 1\n";
                players[0] = getPlayer<char>("Numerical",'X');
                cout << "PLAYER 2\n";
                players[1] = getPlayer<char>("Numerical",'O');
                if (ComputerOrNotMain){
                    NumericTicTacToe_Board->ComputerOrNot= true;
                }
                GameManager<char> Numerical(NumericTicTacToe_Board,players);
                Numerical.run();
                players[0] = nullptr;
                players[1] = nullptr;
                delete NumericTicTacToe_Board;
            }
            else if (toupper(ch) == 'E') {
                auto* SUS_Board = new SUS<char>();
                cout << "starting SUS\n";
                cout << "PLAYER 1\n";
                players[0] = getPlayer<char>("SUS",'S');
                cout << "PLAYER 2\n";
                players[1] = getPlayer<char>("SUS",'U');
                GameManager<char> SUS(SUS_Board,players);
                SUS.run();
                players[0] = nullptr;
                players[1] = nullptr;
                delete SUS_Board;
            }
            else if (toupper(ch) == 'Q') {
                cout << "Thank you for using this program";
                break;
            }
            else {
                cout << "Please enter a valid input\n";
                continue;
            }
        }
        break;
    }
}