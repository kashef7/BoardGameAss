#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->setSpacing(0);
    ui->gridLayout->setContentsMargins(0, 0, 0, 0);
    QSpacerItem* spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    this->setStyleSheet(
        "MainWindow {"
        "   background-image: url(C:/Users/Elkashef/Documents/UltimateTicTacToe/img/background.jpg);"
        "   background-color: #8FB3E2; /* Set a background color instead of an image */"
        "} "
        "QPushButton {"
        "   background-color: lightgray;"
        "   border: 2px solid Black;"
        "   font: bold 20px;"
        "} "
        "QPushButton:hover {"
        "   background-color: rgba(0, 0, 0, 0.5);"
        "} "
        "QPushButton:pressed {"
        "   background-color: rgba(0, 0, 0, 0.5);"
        "} "
        "QMessageBox QPushButton {"
        "   border: 1px solid #808080;"
        "   color: black;"  // Set text color to black (or default color)
        "   font: normal 12px;"  // Default font style
        "}"
        );

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            buttons[row][col] = new QPushButton(this);
            buttons[row][col]->setMinimumSize(50, 50);
            buttons[row][col]->setMaximumSize(50, 50);
            buttons[row][col]->setText("");
            ui->gridLayout->addWidget(buttons[row][col], row, col);
        }
    }
    ui->gridLayout->setColumnMinimumWidth(2, 75);
    ui->gridLayout->setColumnMinimumWidth(5, 75);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (buttons[i][j]) {
                buttons[i][j]->setProperty("row", i);
                buttons[i][j]->setProperty("col", j);
                connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::handleButtonClick);
            }
        }
    }
    hide();
    playerselector = new PlayerSelector(this);
    playerselector->exec();
    if(playerselector->player1Type == 1){
        players[0] = new Ultimate_Player<char>(playerselector->player1Name.toStdString(),'X');
    }
    else if(playerselector->player1Type == 0){
        players[0] = new Ultimate_Random_Player<char>('X');
    }
    if(playerselector->player2Type == 1){
        players[1] = new Ultimate_Player<char>(playerselector->player2Name.toStdString(),'O');
    }
    else if(playerselector->player2Type == 0){
        players[1] = new Ultimate_Random_Player<char>('O');
    }
    board = new Ultimate_Board<char>();
    gameManager = new GameManager(board,players);
    currentPlayer = 0;
    if(playerselector->player1Type == 0){
        int x, y;
        players[0]->getmove(x, y);

        while (!board->update_board(x, y,'X')) {
            players[0]->getmove(x, y);
        }

        buttons[x][y]->setText(QString('X'));
        buttons[x][y]->setStyleSheet(QString("background-color: %1; border: 1px solid black; font-size: 18px; font-weight: bold; color: black;").arg((currentPlayer == 0) ? "green" : "red"));
        buttons[x][y]->setEnabled(false);
        currentPlayer = 1;
    }
}

void MainWindow::handleButtonClick(){
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    int row = clickedButton->property("row").toInt();
    int col = clickedButton->property("col").toInt();
    QString color = (currentPlayer == 0) ? "green" : "red";
    if (board->update_board(row, col, players[currentPlayer]->getsymbol())) {
        clickedButton->setText(QString(players[currentPlayer]->getsymbol()));
        clickedButton->setStyleSheet(QString("background-color: %1; border: 1px solid black; font-size: 18px; font-weight: bold; color: black;").arg(color));
        clickedButton->setEnabled(false);

        if (board->is_win()) {
            QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(players[currentPlayer]->getname().c_str()));
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
            close();
        }
        else if (board->is_draw()) {
            QMessageBox::information(this, "Game Over", "It's a draw!");
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    buttons[i][j]->setEnabled(false);
                }
            }
        }

        currentPlayer = 1 - currentPlayer;
        if (dynamic_cast<Ultimate_Random_Player<char>*>(players[currentPlayer]) != nullptr && !board->is_win()) {
            int x, y;
            players[currentPlayer]->getmove(x, y);

            while (!board->update_board(x, y, players[currentPlayer]->getsymbol())) {
                players[currentPlayer]->getmove(x, y);
            }

            buttons[x][y]->setText(QString(players[currentPlayer]->getsymbol()));
            buttons[x][y]->setStyleSheet(QString("background-color: %1; border: 1px solid black; font-size: 18px; font-weight: bold; color: black;").arg((currentPlayer == 0) ? "green" : "red"));
            buttons[x][y]->setEnabled(false);
            if (board->is_win()) {
                QMessageBox::information(this, "Game Over",
                                         QString("%1 wins!").arg(players[currentPlayer]->getname().c_str()));
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 9; ++j) {
                        buttons[i][j]->setEnabled(false);
                    }
                }
            }
            else if (board->is_draw()) {
                QMessageBox::information(this, "Game Over", "It's a draw!");
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 9; ++j) {
                        buttons[i][j]->setEnabled(false);
                    }
                }
            }
            currentPlayer = 1 - currentPlayer;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
