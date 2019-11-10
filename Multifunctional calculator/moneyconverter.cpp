#include "moneyconverter.h"
#include "ui_moneyconverter.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "converter.h"

MoneyConverter::MoneyConverter(QWidget *parent): QMainWindow(parent), ui(new Ui::MoneyConverter){

    ui->setupUi(this);
    ui->bsb_bar->hide();
    ui->byn_bar->hide();
    ui->grn_bar->hide();
    ui->rrbb_bar->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->mtb_bar->hide();
    ui->rub_bar->hide();
    ui->priorB_bar->hide();
    ui->dolla_bar->hide();
    ui->krona_bar->hide();
    ui->euro_bar->hide();
    ui->blrb_bar->hide();
    ui->bapb_bar->hide();
    ui->funts_bar->hide();
    ui->au_bar->hide();
    ui->pt_bar->hide();
    ui->pzlt_bar->hide();

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

    ui->statusBar->showMessage("S&C calculator: mode 4 (money converter)");

}
MoneyConverter::~MoneyConverter()
{
    delete ui;
}

void MoneyConverter::digits_numbers()
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

void MoneyConverter::on_actionStage_1_standart_2_triggered()
{
    MainWindow *window = new MainWindow();
    window->show();
    this->close();
}
void MoneyConverter::on_actionStage_2_trigonometry_triggered()
{
    MainWindow2 *sWindow = new MainWindow2();
    sWindow->show();
    this->close();
}
void MoneyConverter::on_actionStage_3_converter_triggered()
{
    Converter *conv = new Converter();
    conv->show();
    this->close();
}
void MoneyConverter::on_actionShow_additive_bars_triggered()
{
    ui->bsb_bar->show();
    ui->byn_bar->show();
    ui->grn_bar->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->mtb_bar->show();
    ui->rub_bar->show();
    ui->priorB_bar->show();
    ui->dolla_bar->show();
    ui->krona_bar->show();
    ui->euro_bar->show();
    ui->blrb_bar->show();
    ui->bapb_bar->show();
    ui->rrbb_bar->show();
    ui->funts_bar->show();
    ui->au_bar->show();
    ui->pt_bar->show();
    ui->pzlt_bar->show();
}
void MoneyConverter::on_actionHide_additive_bars_triggered()
{
    ui->bsb_bar->hide();
    ui->byn_bar->hide();
    ui->grn_bar->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->mtb_bar->hide();
    ui->rub_bar->hide();
    ui->priorB_bar->hide();
    ui->dolla_bar->hide();
    ui->krona_bar->hide();
    ui->euro_bar->hide();
    ui->blrb_bar->hide();
    ui->bapb_bar->hide();
    ui->rrbb_bar->hide();
    ui->funts_bar->hide();
    ui->au_bar->hide();
    ui->pt_bar->hide();
    ui->pzlt_bar->hide();
}
void MoneyConverter::on_actionExit_triggered()
{
    QApplication::quit();
}

void MoneyConverter::on_clear_clicked()
{
    if (waitingForOperand)
        return;

    ui->label->setText("0");
    waitingForOperand = true;
}
void MoneyConverter::on_clear_all_clicked()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
}
void MoneyConverter::on_backspace_clicked()
{
    QString text = ui->label->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->label->setText(text);
}
void MoneyConverter::on_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
    ui->label->setText(ui->label->text()+".");
}

void MoneyConverter::on_actionFull_screen_triggered()
{
    showFullScreen();
}
void MoneyConverter::on_actionStandart_screen_triggered()
{
    showNormal();
}

void MoneyConverter::on_bsb_bar_clicked()
{

}
