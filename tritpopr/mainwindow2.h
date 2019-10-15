#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:

    //void on_sin_clicked();

    void on_actionExit_triggered();
    void on_actionStage1_triggered();

    void digits_numbers();
    void fsin();
    void fcos();
    void ftan();
    void fctg();
    void fAsin();
    void fAcos();
    void fAtan();
    void degre();

    void on_pushButton_clear_clicked();

    void on_pushButton_22_clicked();

    void on_actionStage_3_converter_triggered();

private:
    Ui::MainWindow2 *ui;

};

#endif // MAINWINDOW2_H
