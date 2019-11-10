#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "QtCore/qmath.h"
#include "iostream"
#include "converter.h"
#include "mainwindow.h"
#include "moneyconverter.h"

using namespace std;

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    ui->Asin->hide();
    ui->Actg->hide();
    ui->back->hide();
    ui->degrees_2->hide();

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

    connect(ui->pi, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->sin, SIGNAL(clicked()), this, SLOT(fsin()));
    connect(ui->cos, SIGNAL(clicked()), this, SLOT(fcos()));
    connect(ui->tg, SIGNAL(clicked()), this, SLOT(ftan()));
    connect(ui->ctg, SIGNAL(clicked()), this, SLOT(fctg()));
    connect(ui->Asin, SIGNAL(clicked()), this, SLOT(fAsin()));
    connect(ui->Acos, SIGNAL(clicked()), this, SLOT(fAcos()));
    connect(ui->Atan, SIGNAL(clicked()), this, SLOT(fAtan()));

    connect(ui->degrees, SIGNAL(clicked()), this, SLOT(degre()));
    connect(ui->degrees_2, SIGNAL(clicked()), this, SLOT(degre2()));
    connect(ui->back, SIGNAL(clicked()), this, SLOT(on_back_clicked()));

    ui->statusBar->showMessage("S&C calculator: mode 2 (trigonometry)");

    //connect(ui->Actg, SIGNAL(clicked()), this, SLOT(fActg()));
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_actionStage_1_standart_triggered()
{
    MainWindow *window = new MainWindow();
    window->show();
    this->close();
}
void MainWindow2::on_actionMode_3_converter_triggered()
{
    Converter *conv = new Converter();
    conv->show();
    this->close();
}
void MainWindow2::on_actionStage_4_money_converter_triggered()
{
    MoneyConverter *monc = new MoneyConverter();
    monc->show();
    this->close();
}
void MainWindow2::on_actionShow_additive_bars_triggered()
{
    ui->Asin->show();
    ui->Actg->show();
    ui->back->show();
    ui->degrees_2->show();
}
void MainWindow2::on_actionHide_additive_bars_triggered()
{
    ui->Asin->hide();
    ui->Actg->hide();
    ui->back->hide();
    ui->degrees_2->hide();
}

void MainWindow2::digits_numbers()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    double all_numbers;
    QString new_lable;
    if(ui->label->text().contains("." ) && button->text() == "0"){
        new_lable = ui->label->text() + button->text();
    } else{
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_lable = QString::number(all_numbers, 'g', 15);
    }

    ui->label->setText(new_lable);
}

void MainWindow2::math_op()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    num_f = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}

void MainWindow2::fsin()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qSin(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::fcos()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qCos(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::ftan()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qTan(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::fctg()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = 1/qTan(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::fAsin()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qSin(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::fAcos(){
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qCos(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::fAtan()
{
    double number;
    QString new_label;
    number = (ui->label->text()).toDouble();
    number = qTan(number);
    new_label = QString::number(number, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::degre()
{
    double numb, pi = 3.14159265359;
    QString new_label;
    numb = (ui->label->text()).toDouble();
    numb = (180/pi)*numb;
    new_label = QString::number(numb, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::degre2()
{
    double numb, pi = 3.14159265359;
    QString new_label;
    numb = (ui->label->text()).toDouble();
    numb = (pi*numb)/180;
    new_label = QString::number(numb, 'g', 15);
    ui->label->setText(new_label);
}
void MainWindow2::on_mul_clicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;

    ui->mul->setChecked(true);
}
void MainWindow2::on_div_clicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;
}

void MainWindow2::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow2::on_clear_clicked()
{
    ui->div->setChecked(false);
    ui->mul->setChecked(false);

    ui->label->setText("0");
    waitingForOperand = true;
}

void MainWindow2::on_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
    ui->label->setText(ui->label->text()+".");
}

void MainWindow2::on_equal_clicked()
{
    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    ui->label->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void MainWindow2::on_clear_all_clicked()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
}

void MainWindow2::clearMemory()
{
    sumInMemory = 0.0;
}
void MainWindow2::readMemory()
{
    ui->label->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}
void MainWindow2::setMemory()
{
    on_equal_clicked();
    sumInMemory = ui->label->text().toDouble();
}
void MainWindow2::addToMemory()
{
    on_equal_clicked();
    sumInMemory += ui->label->text().toDouble();
}

void MainWindow2::abortOperation()
{
    on_clear_all_clicked();
    ui->label->setText(tr("####"));
}

bool MainWindow2::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("\303\227")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("/")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}

void MainWindow2::on_back_clicked()
{
    if (waitingForOperand)
        return;

    QString text = ui->label->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->label->setText(text);
}

void MainWindow2::on_actionFull_screen_triggered()
{
    showFullScreen();
}

void MainWindow2::on_actionStandart_screen_triggered()
{
    showNormal();
}
