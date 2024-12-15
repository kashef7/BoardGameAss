#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "Entering MainWindow constructor";

    ui->setupUi(this);
    qDebug() << "UI setup complete";

    // Set background image for the MainWindow
    this->setStyleSheet(
        "QMainWindow {"
        "   background-image: url(C:/Users/Elkashef/Documents/Sus/img/background.jpg);" // Use resource file
        "   background-repeat: no-repeat;"
        "   background-position: center;"
        "   background-size: cover;"
        "}"
        "QPushButton {"
        "   color: white;"
        "   border: 9px solid #808080;"
        "   font: bold 30px;"
        "}"
        "QPushButton:hover {"
        "   background-color: rgba(0, 0, 0, 0.5);"
        "}"
        "QPushButton:pressed {"
        "   background-color: rgba(0, 0, 0, 0.5);"
        "}"
        "QMessageBox QPushButton {"
        "   border: 1px solid #808080;"
        "   color: black;"
        "   font: normal 12px;"
        "}"
        );

    // Initialize the buttons array
    QPushButton* buttons[3][3];
    buttons[0][0] = ui->pushButton;
    buttons[0][1] = ui->pushButton_2;
    buttons[0][2] = ui->pushButton_3;
    buttons[1][0] = ui->pushButton_4;
    buttons[1][1] = ui->pushButton_5;
    buttons[1][2] = ui->pushButton_6;
    buttons[2][0] = ui->pushButton_7;
    buttons[2][1] = ui->pushButton_8;
    buttons[2][2] = ui->pushButton_9;

    if (ui->gridLayout) {
        ui->gridLayout->setSpacing(0);
        ui->gridLayout->setContentsMargins(0, 0, 0, 0);

        // Set fixed sizes for buttons
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (buttons[i][j]) {
                    buttons[i][j]->setFixedSize(100, 100);
                }
            }
        }

        qDebug() << "Button array setup complete";

        // Button connection
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (buttons[i][j]) {
                    buttons[i][j]->setProperty("row", i);
                    buttons[i][j]->setProperty("col", j);
                    connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::handleButtonClick);
                }
            }
        }

        qDebug() << "Button connections complete";

        hide();
        playerselector = new PlayerSelector(this);
        playerselector->exec();

        if (playerselector->player1Type == 1) {
            players[0] = new SUS_Player<char>(playerselector->player1Name.toStdString(), 'S');
        } else if (playerselector->player1Type == 0) {
            players[0] = new SUS_Random_Player<char>('S');
        }

        if (playerselector->player2Type == 1) {
            players[1] = new SUS_Player<char>(playerselector->player2Name.toStdString(), 'U');
        } else if (playerselector->player2Type == 0) {
            players[1] = new SUS_Random_Player<char>('U');
        }

        board = new SUS<char>();
        gameManager = new GameManager(board, players);
        currentPlayer = 0;

        qDebug() << "Game initialization complete";

        if (playerselector->player1Type == 0) {
            int x, y;
            players[0]->getmove(x, y);

            while (!board->update_board(x, y, 'S')) {
                players[0]->getmove(x, y);
            }

            buttons[x][y]->setText(QString('S'));
            buttons[x][y]->setEnabled(false);
            currentPlayer = 1;
        }
    } else {
        qDebug() << "UI elements are null";
    }
}

void MainWindow::handleButtonClick() {
    qDebug() << "hello1";
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    int row = clickedButton->property("row").toInt();
    int col = clickedButton->property("col").toInt();
    clickedButton->setStyleSheet("QPushButton { background-color: rgba(0, 0, 0, 0.5); }");
    if (board->update_board(row, col, players[currentPlayer]->getsymbol())) {
        qDebug() << "hello2";
        clickedButton->setText(QString(players[currentPlayer]->getsymbol()));
        clickedButton->setEnabled(false);

        if (board->is_win()) {
            QMessageBox::information(this, "Game Over",
                                     QString("%1 wins!").arg(players[currentPlayer]->getname().c_str()));
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
            QApplication::quit();
        } else if (board->is_draw()) {
            QMessageBox::information(this, "Game Over", "It's a draw!");
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
            QApplication::quit();
        }

        currentPlayer = 1 - currentPlayer;
    }

    if (dynamic_cast<SUS_Random_Player<char>*>(players[currentPlayer]) != nullptr && !board->is_win()) {
        qDebug() << currentPlayer;
        int x, y;
        players[currentPlayer]->getmove(x, y);
        while (!board->update_board(x, y, players[currentPlayer]->getsymbol())) {
            qDebug() << "hello4";
            players[currentPlayer]->getmove(x, y);
        }
        qDebug() << "hello5";
        buttons[x][y]->setText(QString(players[currentPlayer]->getsymbol()));
        buttons[x][y]->setEnabled(false);

        if (board->is_win()) {
            QMessageBox::information(this, "Game Over",
                                     QString("%1 wins!").arg(players[currentPlayer]->getname().c_str()));
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
        } else if (board->is_draw()) {
            QMessageBox::information(this, "Game Over", "It's a draw!");
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
        }
        currentPlayer = 1 - currentPlayer;
    }
}

MainWindow::~MainWindow() {
    delete ui;
    delete board;
    if (players[0]) delete players[0];
    if (players[1]) delete players[1];
    delete gameManager;
}
