// #include <QDebug>
// #include <QException>
// #include "starterwindow.h"
// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     try {
//         StarterWindow w;
//         w.show();
//         qDebug() << "StarterWindow created and shown";
//         return a.exec();
//     }
//     catch (const std::exception& e) {
//         qDebug() << "Standard exception: " << e.what();
//         return -1;
//     }
//     catch (...) {
//         qDebug() << "Unknown exception occurred";
//         return -1;
//     }
// }

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
