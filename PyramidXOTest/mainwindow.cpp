#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    try {
        qDebug() << "Entering MainWindow constructor";

        ui->setupUi(this);
        qDebug() << "UI setup complete";

        // Ensure these UI elements exist before accessing them
        if (ui->gridLayout && ui->pushButton) {
            ui->gridLayout->setSpacing(0);
            ui->gridLayout->setContentsMargins(0, 0, 0, 0);

            // Set fixed sizes for buttons
            QList<QPushButton*> buttonList = {
                ui->pushButton, ui->pushButton_2, ui->pushButton_3,
                ui->pushButton_4, ui->pushButton_5, ui->pushButton_6,
                ui->pushButton_7, ui->pushButton_8, ui->pushButton_9
            };

            for (auto* button : buttonList) {
                if (button) {
                    button->setFixedSize(100, 100);
                }
            }

            qDebug() << "Button setup complete";

            // Button array setup
            buttons[0][0] = ui->pushButton;
            buttons[1][0] = ui->pushButton_2;
            buttons[1][1] = ui->pushButton_3;
            buttons[1][2] = ui->pushButton_4;
            buttons[2][0] = ui->pushButton_5;
            buttons[2][1] = ui->pushButton_6;
            buttons[2][2] = ui->pushButton_7;
            buttons[2][3] = ui->pushButton_8;
            buttons[2][4] = ui->pushButton_9;

            qDebug() << "Button array setup complete";

            // Button connection
            int buttonLeft = 1;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < buttonLeft; ++j) {
                    if (buttons[i][j]) {
                        buttons[i][j]->setProperty("row", i);
                        buttons[i][j]->setProperty("col", j);
                        connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::handleButtonClick);
                    }
                }
                buttonLeft += 2;
            }

            qDebug() << "Button connections complete";

            // Game initialization
            board = new PyramidXO_Board<char>();
            players[0] = new PyramidXO_Player<char>("Player X",'X');
            players[1] = new PyramidXO_Player<char>("Player O",'O');
            gameManager = new GameManager(board,players);
            currentPlayer = 0;

            qDebug() << "Game initialization complete";
        }
        else {
            qDebug() << "UI elements are null";
        }
    }
    catch (const std::exception& e) {
        qDebug() << "Exception in MainWindow constructor: " << e.what();
    }
    catch (...) {
        qDebug() << "Unknown exception in MainWindow constructor";
    }
}



void MainWindow::handleButtonClick(){
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    // Get row and column
    int row = clickedButton->property("row").toInt();
    int col = clickedButton->property("col").toInt();

    // Try to update the board
    if (board->update_board(row, col, players[currentPlayer]->getsymbol())) {
        // Set button text
        clickedButton->setText(QString(players[currentPlayer]->getsymbol()));
        clickedButton->setEnabled(false);

        // Check for game over
        if (board->is_win()) {
            QMessageBox::information(this, "Game Over",
                                     QString("%1 wins!").arg(players[currentPlayer]->getname().c_str()));
            // Disable all buttons
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
        }
        else if (board->is_draw()) {
            QMessageBox::information(this, "Game Over", "It's a draw!");
            // Disable all buttons
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
        }

        // Switch players
        currentPlayer = 1 - currentPlayer;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete board;
    delete players[0];
    delete players[1];
    delete gameManager;
}
