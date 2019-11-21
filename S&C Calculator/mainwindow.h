#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
explicit MainWindow(QWidget *parent = nullptr);
~MainWindow();

private:
    void on_actionexit_triggered();

    Ui::MainWindow * ui;

    double sumSoFar, sumInMemory, factorSoFar, num_f;
    QString pendingAdditiveOperator, pendingMultiplicativeOperator;

    bool waitingForOperand;
    void abortOperation();
    bool calculate(double rightOperand, const QString & pendingOperator);
    void WriteToFile(QString info);

private slots:    void digits_numbers();

    void math_op();
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
    void on_signproc_clicked();
    void on_clear_all_clicked();
    void on_minus_clicked();
    void on_div_clicked();
    void on_actionStage_2_trigonometry_triggered();
    void on_actionStage_3_converter_2_triggered();
    void on_actionStage_4_money_converter_triggered();
    void on_actionFull_screen_triggered();
    void on_actionStandart_screen_triggered();
    void on_backspace_clicked();
    void on_actionCalculation_list_triggered();
};

#endif // MAINWINDOW_H
