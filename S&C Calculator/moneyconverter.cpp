#include "moneyconverter.h"
#include "ui_moneyconverter.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "mainwindow.h"
#include "mainwindow2.h"
#include "calculationscreen.h"
#include "converter.h"

MoneyConverter::MoneyConverter(QWidget * parent): QMainWindow(parent), ui(new Ui::MoneyConverter){

    ui->setupUi(this);

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
}
MoneyConverter::~MoneyConverter() {

    delete ui;
}

void MoneyConverter::WriteToFile(QString info) {

    QFile file("C:\\Users\\Winston\\Documents\\SimpleAndConvinientCalculator\\allOperations.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)){
        QMessageBox::warning(this, "WARNING!", "You are not perform any calculations");
        return;
    }
    QTextStream stream(&file);
    stream << info;

    file.flush();
    file.close();
}

void MoneyConverter::on_clear_clicked() {

    if (waitingForOperand)
        return;

    ui->label->setText("0");
    waitingForOperand = true;
}
void MoneyConverter::on_clear_all_clicked() {

    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
}

void MoneyConverter::on_actionStage_1_standart_2_triggered() {

    MainWindow *window = new MainWindow();
    window->show();
    this->close();
}
void MoneyConverter::on_actionStage_2_trigonometry_triggered() {

    MainWindow2 *sWindow = new MainWindow2();
    sWindow->show();
    this->close();
}
void MoneyConverter::on_actionStage_3_converter_triggered() {
    Converter *conv = new Converter();
    conv->show();
    this->close();
}
void MoneyConverter::on_actionExit_triggered() {

    QApplication::quit();
}

void MoneyConverter::on_dot_clicked() {

    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text()+".");
}
void MoneyConverter::on_actionFull_screen_triggered() {

    showFullScreen();
}
void MoneyConverter::on_actionStandart_screen_triggered() {
    showNormal();
}
void MoneyConverter::on_backspace_clicked() {

    QString text = ui->label->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->label->setText(text);
}
void MoneyConverter::digits_numbers() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    double all_numbers;
    QString new_lable, info = button->text();

    if(ui->label->text().contains("." ) && button->text() == "0"){
        new_lable = ui->label->text() + button->text();
    } else{
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_lable = QString::number(all_numbers, 'g', 20);
    }

    ui->label->setText(new_lable);

    WriteToFile(info);
}
void MoneyConverter::on_actionOperation_list_triggered() {

    CalculationScreen *calc = new CalculationScreen();
    calc->show();
}

void MoneyConverter::on_bsb_bar_clicked() {
    pbsbb = true;
    ui->bsb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(231, 190, 22); border-radius: 10px;");
    pbapbb = false;
    priorBb = false;
    mtbb = false;
    pblrbb = false;
    prrbbb = false;

    ui->mtb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bapb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->blrb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->rrbb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->priorB_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
}
void MoneyConverter::on_bapb_bar_clicked(){
    pbsbb = false;
    pbapbb = true;
    ui->bapb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(231, 190, 22); border-radius: 10px;");
    priorBb = false;
    mtbb = false;
    pblrbb = false;
    prrbbb = false;

    ui->bsb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->mtb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->blrb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->rrbb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->priorB_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
}
void MoneyConverter::on_priorB_bar_clicked(){
    pbsbb = false;
    pbapbb = false;
    priorBb = true;
    ui->priorB_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(231, 190, 22); border-radius: 10px;");
    mtbb = false;
    pblrbb = false;
    prrbbb = false;

    ui->bsb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->mtb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bapb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->blrb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->rrbb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
}
void MoneyConverter::on_mtb_bar_clicked(){
    pbsbb = false;
    pbapbb = false;
    priorBb = false;
    mtbb = true;
    ui->mtb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(231, 190, 22); border-radius: 10px;");
    pblrbb = false;
    prrbbb = false;

    ui->bsb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->priorB_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bapb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->blrb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->rrbb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
}
void MoneyConverter::on_blrb_bar_clicked(){
    pbsbb = false;
    pbapbb = false;
    priorBb = false;
    mtbb = false;
    pblrbb = true;
    ui->blrb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(231, 190, 22); border-radius: 10px;");
    prrbbb = false;

    ui->mtb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bsb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->priorB_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bapb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->rrbb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
}
void MoneyConverter::on_rrbb_bar_clicked(){
    pbsbb = false;
    pbapbb = false;
    priorBb = false;
    mtbb = false;
    pblrbb = false;
    prrbbb = true;
    ui->rrbb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(231, 190, 22); border-radius: 10px;");

    ui->mtb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bsb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->priorB_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bapb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->blrb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
}

void MoneyConverter::on_dolla_bar_clicked()
{
    peurob = false;
    pdollarb = true;
    ui->dolla_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = false;

    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_euro_bar_clicked()
{
    peurob = true;
    ui->euro_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_grn_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    ui->grn_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    pgrnb = true;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_byn_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = true;
    ui->byn_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_rub_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = true;
    ui->rub_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    pkronab = false;
    pfuntb = false;
    pplzlb = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_krona_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = true;
    ui->krona_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    pfuntb = false;
    pplzlb = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_funts_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = true;
    ui->funts_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    pplzlb = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_pzlt_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = true;
    ui->pzlt_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    pptb = false;
    paub = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_pt_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = false;
    pptb = true;
    ui->pt_bar->setStyleSheet("color: red; background-color: white; border: 2px solid black;");
    paub = false;

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
void MoneyConverter::on_au_bar_clicked()
{
    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = false;
    pptb = false;
    paub = true;
    ui->au_bar->setStyleSheet("color: red; background-color: rgb(170, 255, 127); border: 2px solid black;");

    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}

void MoneyConverter::on_reset_button_clicked()
{
    pbsbb = false;
    pbapbb = false;
    priorBb = false;
    mtbb = false;
    pblrbb = false;
    prrbbb = false;
    ui->bsb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->mtb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->bapb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->blrb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->rrbb_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");
    ui->priorB_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 255); border-radius: 10px;");

    peurob = false;
    pdollarb = false;
    pgrnb = false;
    pbynb = false;
    prubb = false;
    pkronab = false;
    pfuntb = false;
    pplzlb = false;
    ui->dolla_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->euro_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->grn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pzlt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->krona_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->byn_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->rub_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->funts_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->pt_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
    ui->au_bar->setStyleSheet("color: rgb(255, 0, 0); border: 2px solid black; background-color: rgb(170, 255, 127); border-radius: 10px;");
}
