#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_papierBtn_clicked();

    void on_kamienBtn_clicked();

    void on_nozyceBtn_clicked();

    void on_resetBtn_clicked();

    void choicePressed();

private:
    Ui::MainWindow *ui;
    const int PAP = 0;
    const int ROK = 1;
    const int SCI = 2;
    const int PYT = 3;
    int wynikGracza;
    int wynikKomputera;
    int wyborGracza;
    int wyborKomp;
    int nrRundy;
    const QString zdjecia[4] = {":/images/papierkamien/papier.png",
                                ":/images/papierkamien/kamien.png",
                                ":/images/papierkamien/nozyce.png",
                                ":/images/papierkamien/pytajnik.png"};

signals:
    void choicePressedSignal();
};
#endif // MAINWINDOW_H
