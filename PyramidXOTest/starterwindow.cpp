// #include "starterwindow.h"
// #include "ui_starterwindow.h"
// #include "mainwindow.h"
// StarterWindow::StarterWindow(QWidget *parent)
//     : QDialog(parent)
//     , ui(new Ui::StarterWindow)
// {
//     ui->setupUi(this);
// }

// StarterWindow::~StarterWindow()
// {
//     delete ui;
// }

// void StarterWindow::on_pushButton_clicked()
// {
//     qDebug() << "Button clicked. Player1: " << player1 << " Player2: " << player2;
//     try {
//         mainWindow = new MainWindow(player1, player2, this);
//         qDebug() << "MainWindow created";
//         mainWindow->show();
//         qDebug() << "MainWindow shown";
//         this->close();
//     }
//     catch (const std::exception& e) {
//         qDebug() << "Exception in button click: " << e.what();
//     }
//     catch (...) {
//         qDebug() << "Unknown exception in button click";
//     }
// }
// // void StarterWindow::on_pushButton_clicked()
// // {
// //     mainWindow = new MainWindow(player1,player2,this);
// //     mainWindow->show();
// //     this->close();
// // }


// void StarterWindow::on_radioButton_clicked()
// {
//     this->player1 = 0;
// }


// void StarterWindow::on_radioButton_2_clicked()
// {
//     this->player1 = 1;

// }

// void StarterWindow::on_radioButton_3_clicked()
// {
//     this->player2 = 0;

// }


// void StarterWindow::on_radioButton_4_clicked()
// {
//     this->player2 = 1;

// }

