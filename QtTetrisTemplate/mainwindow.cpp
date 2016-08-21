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
//    QUuid x = QUuid::createUuid();



//    while(true){
//        sleep(1);
//        qDebug("hi");
//        y+=10;
//        this->repaint();
//    }

//    m_gameTimer = new QTimer(this);
//    connect(m_gameTimer, SIGNAL(timeout()), this, SLOT(onTimer()));
//    m_gameTimer->start(100);

//    QTimer *timer = new QTimer(this);
//       connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
//       timer->start(1000);

//       QTimer::singleShot(100, parent, SLOT(onTimer()));

    //QTimer::singleShot(5, this, SLOT(timeout()));
}

void MainWindow::onTimer()
{
    qDebug("hi");
//    y+=10;
//    this->repaint();
}

void MainWindow::timerEvent(QTimerEvent *)
{
   // qDebug("hi");
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
