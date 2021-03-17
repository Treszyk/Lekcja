#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QRandomGenerator>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wynikGracza = 0;
    wynikKomputera = 0;
    nrRundy = 1;

    connect(this, &MainWindow::choicePressedSignal, this, &MainWindow::choicePressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_papierBtn_clicked()
{
    ui->zdjgracz->setPixmap(QPixmap(zdjecia[PAP]));
    wyborGracza = PAP;
    emit choicePressed();
}

void MainWindow::on_kamienBtn_clicked()
{
    ui->zdjgracz->setPixmap(QPixmap(zdjecia[ROK]));
    wyborGracza = ROK;
    emit choicePressed();
}

void MainWindow::on_nozyceBtn_clicked()
{
    ui->zdjgracz->setPixmap(QPixmap(zdjecia[SCI]));
    wyborGracza = SCI;
    emit choicePressed();
}

void MainWindow::on_resetBtn_clicked()
{
    wynikGracza = 0;
    wynikKomputera = 0;
    nrRundy = 1;
    ui->zdjgracz->setPixmap(QPixmap(":/images/papierkamien/pytajnik.png"));
    ui->zdjkomp->setPixmap(QPixmap(":/images/papierkamien/pytajnik.png"));
    ui->wynik->setText("Runda: " + QString::number(nrRundy) + " Wynik: " + QString::number(wynikGracza) + " : " + QString::number(wynikKomputera));
}

void MainWindow::choicePressed()
{
    nrRundy++;
    wyborKomp = QRandomGenerator::global()->bounded(0, 3);
    ui->zdjkomp->setPixmap(QPixmap(zdjecia[wyborKomp]));
    qDebug() << wyborGracza << " " << wyborKomp;
    if(wyborGracza == wyborKomp)
    {
        ui->infoLabel->setText("REMIS!!!");
    }
    else if((wyborGracza == PAP && wyborKomp == ROK) || (wyborGracza == ROK && wyborKomp == SCI) || (wyborGracza == SCI && wyborKomp == PAP))
    {
        ui->infoLabel->setText("WYGRALES!!!");
        wynikGracza++;
    }
    else
    {
        ui->infoLabel->setText("PRZEGRALES!!!");
        wynikKomputera++;
    }
    ui->wynik->setText("Runda: " + QString::number(nrRundy) + " Wynik: " + QString::number(wynikGracza) + " : " + QString::number(wynikKomputera));
}
