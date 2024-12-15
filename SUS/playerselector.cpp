#include "playerselector.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "ui_playerselector.h"
PlayerSelector::PlayerSelector(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerSelector)
{
    ui->setupUi(this);
    this->setStyleSheet("PlayerSelector {"
                        //"   background-color: #8FB3E2;" // Lighter blue background
                        "   background-image: url(C:/Users/Elkashef/Documents/Sus/img/background.jpg);"
                        "} "
                        "QLabel#label {"
                        "   color: white;"        // Header label text color
                        "   font: bold 36px;"     // Bigger and bolder font for header
                        "   margin-bottom: 10px;" // Add spacing below the header
                        "} "
                        "QLabel {"
                        "   color: white;" // Standard labels
                        "   font: bold 16px;"
                        "} "
                        "QLineEdit {"
                        "   background-color: white;"
                        "   border: 1px solid black;"
                        "   color: black;"
                        "   font: 14px;"
                        "   margin-bottom: 10px;"
                        "   margin-top: 10px;"
                        "} "
                        "QPushButton {"
                        "   background-color: lightgray;"
                        "   border: 2px solid Black;"
                        "   font: bold 16px;"
                        "} "
                        "QPushButton:hover {"
                        "   background-color: rgba(0, 0, 0, 0.5);"
                        "} "
                        "QPushButton:pressed {"
                        "   background-color: rgba(0, 0, 0, 0.3);"
                        "}"
                        "QWidget#widget, QWidget#widget_2 {"
                        "   border: 2px solid white;"
                        "   border-radius: 5px;"
                        "   background-color: #8FB3E2;"
                        "} ");
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(10);
    shadowEffect->setColor(Qt::black);
    shadowEffect->setOffset(3, 3);
    ui->pushButton->setGraphicsEffect(shadowEffect);
}

PlayerSelector::~PlayerSelector()
{
    delete ui;
}

void PlayerSelector::on_radioButton_clicked()
{
    this->player1Type = 1;
    if (ui->lineEdit->text().isEmpty()) {
        this->player1Name = "Player1";
    } else {
        this->player1Name = ui->lineEdit->text();
    }
}

void PlayerSelector::on_radioButton_2_clicked()
{
    this->player1Type = 0;
}

void PlayerSelector::on_radioButton_3_clicked()
{
    this->player2Type = 1;
    if (ui->lineEdit_2->text().isEmpty()) {
        this->player2Name = "Player2";
    } else {
        this->player2Name = ui->lineEdit_2->text();
    }
}
void PlayerSelector::on_radioButton_4_clicked()
{
    this->player2Type = 0;
}

void PlayerSelector::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked()
        || ui->radioButton_2->isChecked() && ui->radioButton_3->isChecked()
        || ui->radioButton_4->isChecked()) {
        if (ui->lineEdit->text().isEmpty()) {
            this->player1Name = "Player1";
        } else {
            this->player1Name = ui->lineEdit->text();
        }
        if (ui->lineEdit_2->text().isEmpty()) {
            this->player2Name = "Player2";
        } else {
            this->player2Name = ui->lineEdit_2->text();
        }
        close();
    } else {
        QMessageBox::warning(this, "Error", "Please select type for all players");
    }
}
