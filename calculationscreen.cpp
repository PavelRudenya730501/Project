#include "calculationscreen.h"
#include "ui_calculationscreen.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "converter.h"
#include "moneyconverter.h"
#include <QFile>
#include <QMessageBox>

CalculationScreen::CalculationScreen(QWidget * parent) :
                                                        QMainWindow(parent),
                                                        ui(new Ui::CalculationScreen)
{

    ui->setupUi(this);
    ReadFromFile();
}

CalculationScreen::~CalculationScreen() {

    delete ui;
}

void CalculationScreen::on_actionExit_triggered() {

    hide();
}

void CalculationScreen::on_actionRenew_triggered() {

    hide();
    CalculationScreen *cs = new CalculationScreen();
    QFile file("C:\\Users\\Winston\\Documents\\S&C calculator\\mode 1.txt");
    file.close();
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    cs->show();
}

void CalculationScreen::on_actionFull_screen_triggered() {

    showFullScreen();
}

void CalculationScreen::on_actionNormal_screen_triggered() {

    showNormal();
}

void CalculationScreen::on_actionClean_calculation_list_triggered() {

    QFile file("C:\\Users\\Winston\\Documents\\S&C calculator\\mode 1.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        file.close();
}

void CalculationScreen::ReadFromFile() {


    QFile file("C:\\Users\\Winston\\Documents\\S&C calculator\\mode 1.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "WARNING!", "You are not perform any calculations");
        return;
    }
    //ui->label->setText(file.readAll());
    ui->textBrowser->setText(file.readAll());

    file.flush();
    file.close();
}


