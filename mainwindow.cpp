#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Command dir = Command("go", "north");
        string room = zork->goRoom(dir);
        QString str = QString::fromUtf8(room.c_str());
        ui->label->setText(str);
}

void MainWindow::on_pushButton_4_clicked()
{
    Command dir = Command("go", "south");
        string room = zork->goRoom(dir);
        QString str = QString::fromUtf8(room.c_str());
        ui->label->setText(str);
}

void MainWindow::on_pushButton_2_clicked()
{
    Command dir = Command("go", "east");
        string room = zork->goRoom(dir);
        QString str = QString::fromUtf8(room.c_str());
        ui->label->setText(str);;
}

void MainWindow::on_pushButton_3_clicked()
{
    Command dir = Command("go", "west");
        string room = zork->goRoom(dir);
        QString str = QString::fromUtf8(room.c_str());
        ui->label->setText(str);;
}




