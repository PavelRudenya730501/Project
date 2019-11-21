#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMainWindow>

namespace Ui {
class Converter;
}

class Converter : public QMainWindow
{
Q_OBJECT

public:
explicit Converter(QWidget *parent = nullptr);
~Converter();

private:
Ui::Converter *ui;
double sumSoFar, sumInMemory, factorSoFar;
QString pendingAdditiveOperator, pendingMultiplicativeOperator;
bool waitingForOperand, pressedmmb, pressedsmb, pressedmtrb, pressedkmtrb, pressedyrdb, pressedftsb, pressedmlsb;
bool pressedmgrb, pressedgrb, pressedkgrb, pressedtnb, pressedfuntb;
void fmmtrs();
void fsmtrs();
void fmtrs();
void fkmtrs();

void fyards();
void fmiles();
void futs();

void mlgr();
void gram();
void kg();
void tona();

void WriteToFile(QString info);
private slots:
    void on_dot_clicked();
    void digits_numbers();
    void on_actionExit_triggered();
    void on_actionStage_1_standart_2_triggered();
    void on_actionStage_2_trigonometry_2_triggered();
    void on_actionStage_4_money_converter_triggered();
    void on_clear_bar_clicked();
    void on_clear_all_bar_clicked();
    void on_mm_bar_clicked();
    void on_sm_bar_clicked();
    void on_met_bar_clicked();
    void on_km_bar_clicked();
    void on_milimeters_clicked();
    void on_smeters_clicked();
    void on_kilometers_clicked();
    void on_meters_clicked();
    void on_yard_bar_clicked();
    void on_mile_bar_clicked();
    void on_fut_bar_clicked();
    void on_yards_clicked();
    void on_miles_clicked();
    void on_futs_clicked();
    void on_mgr_bar_clicked();
    void on_gr_bar_clicked();
    void on_kg_bar_clicked();
    void on_cnt_bar_clicked();
    void on_ton_bar_clicked();
    void on_funts_bar_clicked();
    void on_miligram_clicked();
    void on_gram_clicked();
    void on_kilogram_clicked();
    void on_tona_clicked();
    void on_funts_clicked();
    void on_backspace_clicked();
    void on_actionCalculation_list_triggered();
};

#endif // CONVERTER_H
