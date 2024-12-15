#ifndef PLAYERSELECTOR_H
#define PLAYERSELECTOR_H

#include <QDialog>
#include <QString>

namespace Ui {
class PlayerSelector;
}

class PlayerSelector : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSelector(QWidget *parent = nullptr);
    int player1Type , player2Type;
    QString player1Name , player2Name;
    ~PlayerSelector();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::PlayerSelector *ui;
};

#endif // PLAYERSELECTOR_H
