#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QImage myImage;
//        myImage.load("image/block.png");

//        QLabel myLabel;
//        myLabel.setPixmap(QPixmap::fromImage(myImage));

//        myLabel.show();


    return a.exec();
}
