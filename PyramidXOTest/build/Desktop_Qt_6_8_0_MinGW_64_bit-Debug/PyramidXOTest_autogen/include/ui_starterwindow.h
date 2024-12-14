/********************************************************************************
** Form generated from reading UI file 'starterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTERWINDOW_H
#define UI_STARTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StarterWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;

    void setupUi(QDialog *StarterWindow)
    {
        if (StarterWindow->objectName().isEmpty())
            StarterWindow->setObjectName("StarterWindow");
        StarterWindow->resize(877, 563);
        label = new QLabel(StarterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 110, 181, 101));
        label_2 = new QLabel(StarterWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 140, 151, 41));
        widget = new QWidget(StarterWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(160, 210, 134, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName("radioButton");

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout->addWidget(radioButton_2);

        widget_2 = new QWidget(StarterWindow);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(450, 210, 134, 81));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioButton_3 = new QRadioButton(widget_2);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(widget_2);
        radioButton_4->setObjectName("radioButton_4");

        verticalLayout_2->addWidget(radioButton_4);

        pushButton = new QPushButton(StarterWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 350, 221, 31));

        retranslateUi(StarterWindow);

        QMetaObject::connectSlotsByName(StarterWindow);
    } // setupUi

    void retranslateUi(QDialog *StarterWindow)
    {
        StarterWindow->setWindowTitle(QCoreApplication::translate("StarterWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("StarterWindow", "Player 1", nullptr));
        label_2->setText(QCoreApplication::translate("StarterWindow", "Player 2", nullptr));
        radioButton->setText(QCoreApplication::translate("StarterWindow", "Human", nullptr));
        radioButton_2->setText(QCoreApplication::translate("StarterWindow", "Computer", nullptr));
        radioButton_3->setText(QCoreApplication::translate("StarterWindow", "Human", nullptr));
        radioButton_4->setText(QCoreApplication::translate("StarterWindow", "Computer", nullptr));
        pushButton->setText(QCoreApplication::translate("StarterWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StarterWindow: public Ui_StarterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTERWINDOW_H
