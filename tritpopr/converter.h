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

private slots:
    void on_dot_clicked();
    void digits_numbers();

    void on_actionExit_triggered();

    void on_actionStage_2_trigonometry_triggered();

    void on_actionStage_1_standart_triggered();

private:
    Ui::Converter *ui;
    void fmlmtrs();
    void fsmtrs();
    void fdmtrs();
    void fmtrs();
    void fkmtrs();
    void fyards();
    void fmiles();
    void fut();

    void mlgr();
    void gram();
    void kg();
    void cntnr();
    void tona();

    bool pressedmm;
};

#endif // CONVERTER_H
