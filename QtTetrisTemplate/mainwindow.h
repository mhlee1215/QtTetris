#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QPushButton>
#include <QImage>
#include <QPainter>
#include <iostream>
#include <unistd.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent* e);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    int timerId;
    QTimer* m_gameTimer;
    void onTimer();
    Ui::MainWindow *ui;
    int x;
    int y;

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
