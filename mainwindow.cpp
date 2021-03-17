#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_papier_clicked()
{

}

void MainWindow::on_kamien_clicked()
{

}

void MainWindow::on_nozyce_clicked()
{

}
