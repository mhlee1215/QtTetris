#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    x = 10;
    y = 10;

     timerId = startTimer(100);
}

void MainWindow::timerEvent(QTimerEvent *)
{
    y+=10;
    this->repaint();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::red);
    p.drawRect(x, y, 50, 50);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    qDebug("keyPressEvent(%x)", event->key());
    if(event->key() == Qt::Key_Left){
        qDebug("Go left");
        x -= 50;
    }else if(event->key() == Qt::Key_Up){
        qDebug("Go Up");
    }else if(event->key() == Qt::Key_Down){
        qDebug("Go Down");
        y += 50;
    }else if(event->key() == Qt::Key_Right){
        qDebug("Go Right");
        x += 50;
    }

    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}
