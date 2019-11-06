#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}
//-----------chuyen doi 2 che do--------------
void MainWindow::on_switchtoint_clicked()
{
    ui->calculator->setCurrentIndex(1);
}
void MainWindow::on_switchtofloat_clicked()
{
    ui->calculator->setCurrentIndex(0);
}
//--------------------------------------------
//--------------integer mode------------------
//**man hinh Binary -
void MainWindow::on_binScreen_i_textChanged()
{
    // get noi dung trong binary screen vao binScreen
    binScreen = ui->binScreen_i->toPlainText().toStdString();
}
//dau "=" o binary
void MainWindow::on_equalBin_i_clicked()
{
    string a, b, result;
    QInt x, y, r;
    if(getOp(binScreen,a,b) == "+"){ // cong
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        r = x + y;
        result = r.convertDecToBin();
    }
    if(getOp(binScreen,a,b) == "-"){ // tru
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        r = x - y;
        result = r.convertDecToBin();
    }
    if(getOp(binScreen,a,b) == "*"){ // nhan
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        r = x * y;
        result = r.convertDecToBin();
    }
    if(getOp(binScreen,a,b) == "/"){ // chia
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        r = x / y;
        result = r.convertDecToBin();
    }
    if(getOp(binScreen,a,b) == "<"){ // so sanh be hon
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        if(x.operator<(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(binScreen,a,b) == ">"){ // so sanh lon hon
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        if(x.operator>(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(binScreen,a,b) == "<="){ // so sanh be hon hoac bang
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        if(x.operator<=(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(binScreen,a,b) == ">="){ // so sanh lon hon hoac bang
        x = QInt::convertBinToQInt(a);
        y = QInt::convertBinToQInt(b);
        if(x.operator>=(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    ui->binScreen_i->setText(QString::fromStdString(result));
}
// bin2dec
void MainWindow::on_binToDec_i_clicked()
{
    string result;
    result = QInt::convertBinToDec(binScreen);
    ui->decScreen_i->setText(QString::fromStdString(result));
}
// bin2hex
void MainWindow::on_binToHex_i_clicked()
{
    string result;
    result = QInt::convertBinToHex(binScreen);
    ui->hexScreen_i->setText(QString::fromStdString(result));
}
//**man hinh decimal
void MainWindow::on_decScreen_i_textChanged()
{
    decScreen = ui->decScreen_i->toPlainText().toStdString();
}
// dau"=" o decimal
void MainWindow::on_equalDec_i_clicked()
{
    string a, b, result;
    QInt r;
    if(getOp(decScreen,a,b) == "+"){ // cong
        QInt x(a);
        QInt y(b);
        r = x + y;
        result = r.convertQIntToDec();
    }
    if(getOp(decScreen,a,b) == "-"){ // tru
        QInt x(a);
        QInt y(b);
        r = x - y;
        result = r.convertQIntToDec();
    }
    if(getOp(decScreen,a,b) == "*"){ // nhan
        QInt x(a);
        QInt y(b);
        r = x * y;
        result = r.convertQIntToDec();
    }
    if(getOp(decScreen,a,b) == "/"){ // chia
        QInt x(a);
        QInt y(b);
        r = x / y;
        result = r.convertQIntToDec();
    }
    if(getOp(decScreen,a,b) == "<"){ // so sanh be hon
        QInt x(a);
        QInt y(b);
        if(x.operator<(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(decScreen,a,b) == ">"){ // so sanh lon hon
        QInt x(a);
        QInt y(b);
        if(x.operator>(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(decScreen,a,b) == "<="){ // so sanh be hon hoac bang
        QInt x(a);
        QInt y(b);
        if(x.operator<=(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(decScreen,a,b) == ">="){ // so sanh lon hon hoac bang
        QInt x(a);
        QInt y(b);
        if(x.operator>=(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    ui->decScreen_i->setText(QString::fromStdString(result));
}

void MainWindow::on_decToBin_i_clicked()
{
    string result;
    result = QInt::convertDecToBin(decScreen);
    ui->binScreen_i->setText(QString::fromStdString(result));
}

void MainWindow::on_decToHex_i_clicked()
{
    string result;
    result = QInt::convertDecToHex(decScreen);
    ui->hexScreen_i->setText(QString::fromStdString(result));
}
//**man hinh heximal
void MainWindow::on_hexScreen_i_textChanged()
{
    hexScreen = ui->hexScreen_i->toPlainText().toStdString();
}

void MainWindow::on_equalHex_i_clicked()
{
    string a, b, result;
    QInt r;
    if(getOp(hexScreen,a,b) == "+"){ // cong
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        r = x + y;
        result = QInt::convertDecToHex(r.convertQIntToDec());
    }
    if(getOp(hexScreen,a,b) == "-"){ // tru
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        r = x - y;
        result = QInt::convertDecToHex(r.convertQIntToDec());
    }
    if(getOp(hexScreen,a,b) == "*"){ // nhan
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        r = x * y;
        result = QInt::convertDecToHex(r.convertQIntToDec());
    }
    if(getOp(hexScreen,a,b) == "/"){ // chia
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        r = x / y;
        result = QInt::convertDecToHex(r.convertQIntToDec());
    }
    if(getOp(hexScreen,a,b) == "<"){ // so sanh be hon
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        if(x.operator<(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(hexScreen,a,b) == ">"){ // so sanh lon hon
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        if(x.operator>(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(hexScreen,a,b) == "<="){ // so sanh be hon hoac bang
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        if(x.operator<=(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    if(getOp(hexScreen,a,b) == ">="){ // so sanh lon hon hoac bang
        QInt x(QInt::convertHexToDec(a));
        QInt y(QInt::convertHexToDec(b));
        if(x.operator>=(y))
            result = "TRUE";
        else
            result = "FALSE";
    }
    ui->hexScreen_i->setText(QString::fromStdString(result));
}
void MainWindow::on_hexToBin_i_clicked()
{
    string result;
    result = QInt::convertDecToBin(QInt::convertHexToDec(hexScreen));
    ui->binScreen_i->setText(QString::fromStdString(result));
}

void MainWindow::on_hexToDec_i_clicked()
{
    string result;
    result = QInt::convertHexToDec(hexScreen);
    ui->decScreen_i->setText(QString::fromStdString(result));
}
//-------------Dich phai-----------------
void MainWindow::on_dichPhai_clicked()
{
    string result;
    QInt a, r;
    if(binScreen!=""){
        a = QInt::convertBinToQInt(binScreen);
        r = a.operator>>(1);
        result = r.convertDecToBin();
        ui->binScreen_i->setText(QString::fromStdString(result));
    }
    if(decScreen!=""){
        a = QInt(decScreen);
        r = a.operator>>(1);
        result = r.convertQIntToDec();
        ui->decScreen_i->setText(QString::fromStdString(result));
    }
    if(hexScreen!=""){
        a = QInt(QInt::convertHexToDec(hexScreen));
        r = a.operator>>(1);
        result = QInt::convertDecToHex(r.convertQIntToDec());
        ui->hexScreen_i->setText(QString::fromStdString(result));
    }
}
//-------------Dich trai-----------------
void MainWindow::on_dichTrai_clicked()
{
    string result;
    QInt a, r;
    if(binScreen!=""){
        a = QInt::convertBinToQInt(binScreen);
        r = a.operator<<(1);
        result = r.convertDecToBin();
        ui->binScreen_i->setText(QString::fromStdString(result));
    }
    if(decScreen!=""){
        a = QInt(decScreen);
        r = a.operator<<(1);
        result = r.convertQIntToDec();
        ui->decScreen_i->setText(QString::fromStdString(result));
    }
    if(hexScreen!=""){
        a = QInt(QInt::convertHexToDec(hexScreen));
        r = a.operator<<(1);
        result = QInt::convertDecToHex(r.convertQIntToDec());
        ui->hexScreen_i->setText(QString::fromStdString(result));
    }
}
//-------------Xoay trai-----------------
void MainWindow::on_xoayTrai_clicked()
{
    string result;
    QInt a, r;
    if(binScreen!=""){
        a = QInt::convertBinToQInt(binScreen);
        r = a.ROL(1);
        result = r.convertDecToBin();
        ui->binScreen_i->setText(QString::fromStdString(result));
    }
    if(decScreen!=""){
        a = QInt(decScreen);
        r = a.ROL(1);
        result = r.convertQIntToDec();
        ui->decScreen_i->setText(QString::fromStdString(result));
    }
    if(hexScreen!=""){
        a = QInt(QInt::convertHexToDec(hexScreen));
        r = a.ROL(1);
        result = QInt::convertDecToHex(r.convertQIntToDec());
        ui->hexScreen_i->setText(QString::fromStdString(result));
    }
}
//-------------Xoay phai-----------------
void MainWindow::on_xoayPhai_clicked()
{
    string result;
    QInt a, r;
    if(binScreen!=""){
        a = QInt::convertBinToQInt(binScreen);
        r = a.ROR(1);
        result = r.convertDecToBin();
        ui->binScreen_i->setText(QString::fromStdString(result));
    }
    if(decScreen!=""){
        a = QInt(decScreen);
        r = a.ROR(1);
        result = r.convertQIntToDec();
        ui->decScreen_i->setText(QString::fromStdString(result));
    }
    if(hexScreen!=""){
        a = QInt(QInt::convertHexToDec(hexScreen));
        r = a.ROR(1);
        result = QInt::convertDecToHex(r.convertQIntToDec());
        ui->hexScreen_i->setText(QString::fromStdString(result));
    }
}
//---------------------------------------------
//--------------float mode---------------------
void MainWindow::on_binScreen_f_textChanged()
{
    binScreen_f = ui->binScreen_f->toPlainText().toStdString();
}

void MainWindow::on_binToDec_f_clicked()
{
    string result;
    result = QFloat::convertBinToDec(binScreen_f);
    ui->decScreen_f->setText(QString::fromStdString(result));
}

void MainWindow::on_decScreen_f_textChanged()
{
    decScreen_f = ui->decScreen_f->toPlainText().toStdString();
}

void MainWindow::on_decToBin_f_clicked()
{
    string result;
    result = QFloat::convertDecToBin(decScreen_f);
    ui->binScreen_f->setText(QString::fromStdString(result));
}
void MainWindow::on_not_i_clicked()
{
    string result;
    QInt a, r;
    if(binScreen!=""){
        a = QInt::convertBinToQInt(binScreen);
        r = a.operator~();
        result = r.convertDecToBin();
        ui->binScreen_i->setText(QString::fromStdString(result));
    }
    if(decScreen!=""){
        a = QInt(decScreen);
        r = a.operator~();
        result = r.convertQIntToDec();
        ui->decScreen_i->setText(QString::fromStdString(result));
    }
    if(hexScreen!=""){
        a = QInt(QInt::convertHexToDec(hexScreen));
        r = a.operator~();
        result = QInt::convertDecToHex(r.convertQIntToDec());
        ui->hexScreen_i->setText(QString::fromStdString(result));
    }
}
