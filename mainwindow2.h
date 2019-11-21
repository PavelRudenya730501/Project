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

private:
Ui::MainWindow2 *ui;
double sumSoFar, sumInMemory, factorSoFar, num_f;

QString pendingAdditiveOperator, pendingMultiplicativeOperator;

bool waitingForOperand;
void abortOperation();
bool calculate(double rightOperand, const QString & pendingOperator);
void WriteToFile(QString info);

private slots:
    void on_actionExit_triggered();
    void on_actionShow_additive_bars_triggered();
    void on_actionHide_additive_bars_triggered();
    void digits_numbers();
    void fsin();
    void fcos();
    void ftan();
    void fctg();
    void fAsin();
    void fAcos();
    void fAtan();
    void degre();
    void degre2();
    void math_op();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();
    void on_clear_clicked();
    void on_clear_all_clicked();
    void on_dot_clicked();
    void on_mul_clicked();
    void on_div_clicked();
    void on_equal_clicked();
    void on_back_clicked();
    void on_actionStage_1_standart_triggered();
    void on_actionStage_4_money_converter_triggered();
    void on_actionFull_screen_triggered();
    void on_actionStandart_screen_triggered();
    void on_actionMode_3_converter_triggered();
    void on_actionCalculation_list_triggered();
};

#endif // MAINWINDOW2_H
