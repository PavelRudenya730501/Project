#ifndef MONEYCONVERTER_H
#define MONEYCONVERTER_H

#include <QMainWindow>

namespace Ui {
class MoneyConverter;
}

class MoneyConverter : public QMainWindow
{
Q_OBJECT

public:
explicit MoneyConverter(QWidget *parent = nullptr);
~MoneyConverter();

private:
Ui::MoneyConverter *ui;
double sumSoFar, sumInMemory, factorSoFar;
QString pendingAdditiveOperator, pendingMultiplicativeOperator;
bool waitingForOperand, dollar, euro, byn, rub, krona, zloty;
void WriteToFile(QString info);

private slots:

    void on_clear_clicked();
    void on_clear_all_clicked();
    void on_actionStage_1_standart_2_triggered();
    void on_actionStage_2_trigonometry_triggered();
    void on_actionStage_3_converter_triggered();
    void on_actionExit_triggered();
    void on_actionShow_additive_bars_triggered();
    void on_actionHide_additive_bars_triggered();
    void on_dot_clicked();
    void on_actionFull_screen_triggered();
    void on_actionStandart_screen_triggered();
    void on_bsb_bar_clicked();
    void on_backspace_clicked();
    void digits_numbers();
    void on_actionOperation_list_triggered();
};

#endif // MONEYCONVERTER_H
