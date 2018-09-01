#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include "myclass.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread *t = new QThread;
    MyClass *my = new MyClass("abb");

    my->moveToThread(t);
    connect(my, SIGNAL(send(int)), this, SLOT(update()));
    connect(t, SIGNAL(started()), my, SLOT(doWork()));

    t->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(int i)
{
    ui->textEdit->insertPlainText(QString::number(i));
    qDebug() << i;
}
