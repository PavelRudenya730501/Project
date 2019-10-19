#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionexit_triggered();

private:
    Ui::MainWindow *ui;
    double sumSoFar;
    double sumInMemory;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;
    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);

private slots:
    void on_action2_stage_triggered();
    void on_actionStage_3_converter_triggered();

    void digits_numbers();
    void on_dot_clicked();
    void power();

    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();

    void koren();
    void equalClicked();
    void on_mul_clicked();
    void on_plus_clicked();
    void on_clear_clicked();
    void on_back_clicked();
    void on_signproc_clicked();
    void on_clear_all_clicked();
    void on_minus_clicked();
    void on_div_clicked();
    void on_Show_additive_bars_triggered();
    void on_Hide_additive_bars_2_triggered();
};

#endif // MAINWINDOW_H
