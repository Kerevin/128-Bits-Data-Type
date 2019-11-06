#pragma once
#include"checkSyntax.h"
#include"QInt.h"
#include"QFloat.h"
#include"xuLyChuoi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    string binScreen, decScreen, hexScreen; //3 chuoi cho 3 o nhap xuat
    string binScreen_f, decScreen_f;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //
    void on_switchtoint_clicked();
    void on_switchtofloat_clicked();
    //
    void on_binScreen_i_textChanged();
    void on_equalBin_i_clicked();

    void on_binToDec_i_clicked();

    void on_binToHex_i_clicked();

    void on_decScreen_i_textChanged();

    void on_equalDec_i_clicked();

    void on_decToBin_i_clicked();

    void on_decToHex_i_clicked();

    void on_hexScreen_i_textChanged();

    void on_equalHex_i_clicked();

    void on_hexToBin_i_clicked();

    void on_hexToDec_i_clicked();

    void on_dichPhai_clicked();

    void on_dichTrai_clicked();

    void on_xoayTrai_clicked();

    void on_xoayPhai_clicked();

    void on_binScreen_f_textChanged();

    void on_binToDec_f_clicked();

    void on_decScreen_f_textChanged();

    void on_decToBin_f_clicked();

    void on_not_i_clicked();

private:
    Ui::MainWindow *ui;
};
