#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TheGame.h"
#include "BoardGame_Classes.h"
#include "QPushButton"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void handleButtonClick();

private:
    Ui::MainWindow *ui;
    PyramidXO_Board<char>* board;
    Player<char>* players[2];
    GameManager<char>* gameManager;
    QPushButton* buttons[3][5];
    int currentPlayer;
};
#endif // MAINWINDOW_H
