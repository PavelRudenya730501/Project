#ifndef CALCULATIONSCREEN_H
#define CALCULATIONSCREEN_H

#include <QMainWindow>

namespace Ui {
class CalculationScreen;
}

class CalculationScreen : public QMainWindow
{
Q_OBJECT

public:
explicit CalculationScreen(QWidget *parent = nullptr);
~CalculationScreen();

private:
Ui::CalculationScreen *ui;
void on_actionExit_triggered();
void on_actionRenew_triggered();
void on_actionFull_screen_triggered();
void on_actionNormal_screen_triggered();
void on_actionClean_calculation_list_triggered();
void ReadFromFile();
};

#endif // CALCULATIONSCREEN_H
