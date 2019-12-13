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
bool pbsbb, pbapbb, priorBb, mtbb, pblrbb, prrbbb;
bool peurob, pdollarb, pgrnb, pbynb, prubb, pkronab, pfuntb, pplzlb, pptb, paub;

private slots:

    void on_clear_clicked();
    void on_clear_all_clicked();
    void on_actionStage_1_standart_2_triggered();
    void on_actionStage_2_trigonometry_triggered();
    void on_actionStage_3_converter_triggered();
    void on_actionExit_triggered();
    void on_actionFull_screen_triggered();
    void on_actionStandart_screen_triggered();
    void on_actionOperation_list_triggered();

    void on_dot_clicked();
    void on_bsb_bar_clicked();
    void on_backspace_clicked();
    void digits_numbers();
    void on_bapb_bar_clicked();
    void on_priorB_bar_clicked();
    void on_mtb_bar_clicked();
    void on_blrb_bar_clicked();
    void on_rrbb_bar_clicked();
    void on_dolla_bar_clicked();
    void on_euro_bar_clicked();
    void on_grn_bar_clicked();
    void on_byn_bar_clicked();
    void on_rub_bar_clicked();
    void on_krona_bar_clicked();
    void on_funts_bar_clicked();
    void on_pzlt_bar_clicked();
    void on_pt_bar_clicked();
    void on_au_bar_clicked();
    void on_reset_button_clicked();
};

#endif // MONEYCONVERTER_H
