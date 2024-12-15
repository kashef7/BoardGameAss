#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QSpacerItem>
#include <QVBoxLayout>
#include "ultimatetictactoegame.h"
#include <QMessageBox>
#include "playerselector.h"
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
    PlayerSelector *playerselector;
    Ultimate_Board<char>* board;
    Player<char>* players[2];
    GameManager<char>* gameManager;
    QPushButton* buttons[9][9];
    int currentPlayer;
};
#endif // MAINWINDOW_H
