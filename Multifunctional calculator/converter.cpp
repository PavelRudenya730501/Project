#include "converter.h"
#include "ui_converter.h"
#include "mainwindow2.h"
#include "mainwindow.h"

Converter::Converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Converter)
{
    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;

    ui->setupUi(this);
    ui->gr_bar->hide();
    ui->kg_bar->hide();
    ui->dm_bar->hide();
    ui->km_bar->hide();
    ui->mm_bar->hide();
    ui->sm_bar->hide();
    ui->cnt_bar->hide();
    ui->fut_bar->hide();
    ui->met_bar->hide();
    ui->mgr_bar->hide();
    ui->ton_bar->hide();
    ui->mile_bar->hide();
    ui->clear_bar->hide();
    ui->clear_all_bar->hide();
    ui->yard_bar->hide();

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->yards, SIGNAL(clicked()), this, SLOT(fyards()));
    connect(ui->miles, SIGNAL(clicked()), this, SLOT(fmiles()));
    connect(ui->futs, SIGNAL(clicked()), this, SLOT(futs()));

    connect(ui->miligram, SIGNAL(clicked()), this, SLOT(mlgr()));
    connect(ui->gram, SIGNAL(clicked()), this, SLOT(gram()));
    connect(ui->kilogram, SIGNAL(clicked()), this, SLOT(kg()));
    connect(ui->centner, SIGNAL(clicked()), this, SLOT(cntnr()));
    connect(ui->tona, SIGNAL(clicked()), this, SLOT(tona()));

}

Converter::~Converter()
{
    delete ui;
}

void Converter::on_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
    ui->label->setText(ui->label->text()+".");
}
void Converter::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
}

void Converter::on_actionExit_triggered()
{
    QApplication::quit();
}
void Converter::on_actionStage_2_trigonometry_triggered()
{
    MainWindow2 *sWindow = new MainWindow2();
    sWindow->show();
    this->close();
}
void Converter::on_actionStage_1_standart_triggered()
{
    MainWindow *window = new MainWindow();
    window->show();
    this->close();
}
void Converter::on_actionShow_choosing_bars_triggered()
{
    ui->gr_bar->show();
    ui->kg_bar->show();
    ui->dm_bar->show();
    ui->km_bar->show();
    ui->mm_bar->show();
    ui->sm_bar->show();
    ui->cnt_bar->show();
    ui->fut_bar->show();
    ui->met_bar->show();
    ui->mgr_bar->show();
    ui->ton_bar->show();
    ui->mile_bar->show();
    ui->clear_bar->show();
    ui->clear_all_bar->show();
    ui->yard_bar->show();
}
void Converter::on_actionHide_choosing_bars_triggered()
{
    ui->gr_bar->hide();
    ui->kg_bar->hide();
    ui->dm_bar->hide();
    ui->km_bar->hide();
    ui->mm_bar->hide();
    ui->sm_bar->hide();
    ui->cnt_bar->hide();
    ui->fut_bar->hide();
    ui->met_bar->hide();
    ui->mgr_bar->hide();
    ui->ton_bar->hide();
    ui->mile_bar->hide();
    ui->clear_bar->hide();
    ui->clear_all_bar->hide();
    ui->yard_bar->hide();
}

void Converter::on_mm_bar_clicked()
{
    pressedmmb = true;
}
void Converter::on_sm_bar_clicked()
{
    pressedsmb = true;
}
void Converter::on_dm_bar_clicked()
{
    presseddmb = true;
}
void Converter::on_met_bar_clicked()
{
    pressedmtrb = true;
}
void Converter::on_km_bar_clicked()
{
    pressedkmtrb = true;
}

void Converter::on_milimeters_clicked()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }else if (pressedsmb==true) {
        number = 10*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }
    else if (presseddmb==true) {
            number = 100*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedmtrb==true) {
            number = 1000*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedkmtrb==true) {
            number = 1000000*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else{
        ui->label->setText("Incorrect input!");
    }
}

void Converter::on_smeters_clicked()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        number = 0.1*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }else if (pressedsmb==true) {
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }
    else if (presseddmb==true) {
            number = 10*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedmtrb==true) {
            number = 100*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedkmtrb==true) {
            number = 100000*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else{
        ui->label->setText("Incorrect input!");
    }
}

void Converter::on_decimeters_clicked()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        number = 0.01*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }else if (pressedsmb==true) {
        number = 0.1*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }
    else if (presseddmb==true) {
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedmtrb==true) {
            number = 10*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedkmtrb==true) {
            number = 1000*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else{
        ui->label->setText("Incorrect input!");
    }
}

void Converter::on_kilometers_clicked()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        number = 0.000001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }else if (pressedsmb==true) {
        number = 0.00001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }
    else if (presseddmb==true) {
        number = 0.0001*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedmtrb==true) {
            number = 0.001*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedkmtrb==true) {
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else{
        ui->label->setText("Incorrect input!");
    }
}

void Converter::on_meters_clicked()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    if(pressedmmb==true){
        number = 0.001*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }else if (pressedsmb==true) {
        number = 0.01*number;
        new_label = QString::number(number, 'g', 15);
        ui->label->setText(new_label);
    }
    else if (presseddmb==true) {
        number = 0.1*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedmtrb==true) {
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else if (pressedkmtrb==true) {
            number = 1000*number;
            new_label = QString::number(number, 'g', 15);
            ui->label->setText(new_label);
        }
    else{
        ui->label->setText("Incorrect input!");
    }
}

void Converter::on_clear_bar_clicked()
{
    if (waitingForOperand)
        return;

    ui->label->setText("0");
    waitingForOperand = true;
}

void Converter::on_clear_all_bar_clicked()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
}
