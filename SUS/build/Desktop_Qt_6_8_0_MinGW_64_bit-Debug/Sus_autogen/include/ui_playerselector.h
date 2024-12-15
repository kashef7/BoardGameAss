/********************************************************************************
** Form generated from reading UI file 'playerselector.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSELECTOR_H
#define UI_PLAYERSELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerSelector
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QRadioButton *radioButton_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;

    void setupUi(QDialog *PlayerSelector)
    {
        if (PlayerSelector->objectName().isEmpty())
            PlayerSelector->setObjectName("PlayerSelector");
        PlayerSelector->resize(760, 508);
        label = new QLabel(PlayerSelector);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 30, 531, 71));
        QFont font;
        font.setPointSize(23);
        label->setFont(font);
        layoutWidget = new QWidget(PlayerSelector);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 140, 641, 221));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(layoutWidget);
        widget->setObjectName("widget");
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        radioButton = new QRadioButton(widget);
        radioButton->setObjectName("radioButton");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        radioButton->setIcon(icon);

        verticalLayout_3->addWidget(radioButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_3->addWidget(lineEdit);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName("radioButton_2");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::Computer));
        radioButton_2->setIcon(icon1);

        verticalLayout_3->addWidget(radioButton_2);


        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(268, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName("widget_2");
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout_4->addWidget(label_3);

        radioButton_3 = new QRadioButton(widget_2);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setIcon(icon);

        verticalLayout_4->addWidget(radioButton_3);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_4->addWidget(lineEdit_2);

        radioButton_4 = new QRadioButton(widget_2);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setIcon(icon1);

        verticalLayout_4->addWidget(radioButton_4);


        verticalLayout_2->addWidget(widget_2);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButton = new QPushButton(PlayerSelector);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 420, 181, 61));
        pushButton->setFont(font1);

        retranslateUi(PlayerSelector);

        QMetaObject::connectSlotsByName(PlayerSelector);
    } // setupUi

    void retranslateUi(QDialog *PlayerSelector)
    {
        PlayerSelector->setWindowTitle(QCoreApplication::translate("PlayerSelector", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PlayerSelector", "           Welcome to SUS", nullptr));
        label_2->setText(QCoreApplication::translate("PlayerSelector", "Player 1", nullptr));
        radioButton->setText(QCoreApplication::translate("PlayerSelector", "Human", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("PlayerSelector", "Player Name", nullptr));
        radioButton_2->setText(QCoreApplication::translate("PlayerSelector", "Computer", nullptr));
        label_3->setText(QCoreApplication::translate("PlayerSelector", "Player 2", nullptr));
        radioButton_3->setText(QCoreApplication::translate("PlayerSelector", "Human", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("PlayerSelector", "Player Name", nullptr));
        radioButton_4->setText(QCoreApplication::translate("PlayerSelector", "Computer", nullptr));
        pushButton->setText(QCoreApplication::translate("PlayerSelector", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerSelector: public Ui_PlayerSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSELECTOR_H
