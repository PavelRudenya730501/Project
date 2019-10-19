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
    double sumSoFar;
    double sumInMemory;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;
    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);

private slots:

    void on_actionExit_triggered();
    void on_actionStage1_triggered();
    void on_actionShow_additive_bars_triggered();
    void on_actionHide_additive_bars_triggered();
    void on_actionStage_3_converter_triggered();

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
};

#endif // MAINWINDOW2_H
