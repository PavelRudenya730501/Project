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
    double sumSoFar;
    double sumInMemory;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;
    bool pressedmmb, pressedsmb, presseddmb, pressedmtrb, pressedkmtrb;
    bool pressedyrdb, pressedftsb, pressedmlsb;
    bool pressedmgrb, pressedgrb, pressedkgrb, pressedcntb, pressedtnb;
    bool pressedfuntb;
    void fmmtrs();
    void fsmtrs();
    void fdmtrs();
    void fmtrs();
    void fkmtrs();

    void fyards();
    void fmiles();
    void futs();

    void mlgr();
    void gram();
    void kg();
    void cntnr();
    void tona();

private slots:
    void on_dot_clicked();
    void digits_numbers();

    void on_actionExit_triggered();
    void on_actionShow_choosing_bars_triggered();
    void on_actionHide_choosing_bars_triggered();

    void on_clear_bar_clicked();
    void on_clear_all_bar_clicked();

    void on_mm_bar_clicked();
    void on_sm_bar_clicked();
    void on_dm_bar_clicked();
    void on_met_bar_clicked();
    void on_km_bar_clicked();

    void on_milimeters_clicked();
    void on_smeters_clicked();
    void on_decimeters_clicked();
    void on_kilometers_clicked();
    void on_meters_clicked();
    void on_actionStage_1_standart_2_triggered();
    void on_actionStage_2_trigonometry_2_triggered();
    void on_actionStage_4_money_converter_triggered();
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
    void on_centner_clicked();
    void on_tona_clicked();
    void on_funts_clicked();
    void on_backspace_clicked();
};

#endif // CONVERTER_H
