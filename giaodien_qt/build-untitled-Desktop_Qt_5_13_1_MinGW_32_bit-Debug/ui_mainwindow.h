/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *calculator;
    QWidget *float_2;
    QPushButton *switchtoint;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *binScreen_f;
    QTextEdit *decScreen_f;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *binToDec_f;
    QPushButton *decToBin_f;
    QPushButton *not_i_3;
    QWidget *int_2;
    QPushButton *switchtofloat;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *binScreen_i;
    QTextEdit *decScreen_i;
    QTextEdit *hexScreen_i;
    QPushButton *equalBin_i;
    QPushButton *equalDec_i;
    QPushButton *equalHex_i;
    QPushButton *dichTrai;
    QPushButton *dichPhai;
    QPushButton *xoayTrai;
    QPushButton *xoayPhai;
    QPushButton *binToDec_i;
    QPushButton *binToHex_i;
    QPushButton *decToBin_i;
    QPushButton *decToHex_i;
    QPushButton *hexToBin_i;
    QPushButton *hexToDec_i;
    QLabel *label_5;
    QPushButton *not_i;
    QPushButton *not_i_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(921, 751);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        calculator = new QStackedWidget(centralwidget);
        calculator->setObjectName(QString::fromUtf8("calculator"));
        calculator->setGeometry(QRect(0, 0, 921, 751));
        calculator->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 16, 16);"));
        float_2 = new QWidget();
        float_2->setObjectName(QString::fromUtf8("float_2"));
        switchtoint = new QPushButton(float_2);
        switchtoint->setObjectName(QString::fromUtf8("switchtoint"));
        switchtoint->setGeometry(QRect(740, 670, 181, 81));
        QFont font;
        font.setPointSize(17);
        switchtoint->setFont(font);
        switchtoint->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 85, 0);"));
        label_6 = new QLabel(float_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 921, 41));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"background-color: rgb(45, 45, 45);"));
        label_7 = new QLabel(float_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 40, 41, 711));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 45);"));
        binScreen_f = new QTextEdit(float_2);
        binScreen_f->setObjectName(QString::fromUtf8("binScreen_f"));
        binScreen_f->setGeometry(QRect(50, 190, 861, 51));
        binScreen_f->setFont(font);
        binScreen_f->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        decScreen_f = new QTextEdit(float_2);
        decScreen_f->setObjectName(QString::fromUtf8("decScreen_f"));
        decScreen_f->setGeometry(QRect(50, 360, 861, 51));
        decScreen_f->setFont(font);
        decScreen_f->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(float_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 150, 81, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        label_9 = new QLabel(float_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 320, 101, 31));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        binToDec_f = new QPushButton(float_2);
        binToDec_f->setObjectName(QString::fromUtf8("binToDec_f"));
        binToDec_f->setGeometry(QRect(400, 240, 181, 61));
        QFont font1;
        font1.setPointSize(13);
        binToDec_f->setFont(font1);
        binToDec_f->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        decToBin_f = new QPushButton(float_2);
        decToBin_f->setObjectName(QString::fromUtf8("decToBin_f"));
        decToBin_f->setGeometry(QRect(400, 410, 181, 61));
        decToBin_f->setFont(font1);
        decToBin_f->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        not_i_3 = new QPushButton(float_2);
        not_i_3->setObjectName(QString::fromUtf8("not_i_3"));
        not_i_3->setGeometry(QRect(660, 670, 81, 81));
        QFont font2;
        font2.setPointSize(15);
        not_i_3->setFont(font2);
        not_i_3->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 85, 0);"));
        calculator->addWidget(float_2);
        switchtoint->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        binToDec_f->raise();
        decToBin_f->raise();
        binScreen_f->raise();
        decScreen_f->raise();
        not_i_3->raise();
        int_2 = new QWidget();
        int_2->setObjectName(QString::fromUtf8("int_2"));
        switchtofloat = new QPushButton(int_2);
        switchtofloat->setObjectName(QString::fromUtf8("switchtofloat"));
        switchtofloat->setGeometry(QRect(660, 670, 261, 81));
        switchtofloat->setFont(font);
        switchtofloat->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 85, 0);"));
        label = new QLabel(int_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 81, 31));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        label_2 = new QLabel(int_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 240, 101, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        label_3 = new QLabel(int_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 410, 101, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        label_4 = new QLabel(int_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 921, 41));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"background-color: rgb(45, 45, 45);"));
        binScreen_i = new QTextEdit(int_2);
        binScreen_i->setObjectName(QString::fromUtf8("binScreen_i"));
        binScreen_i->setGeometry(QRect(50, 110, 821, 51));
        binScreen_i->setFont(font);
        binScreen_i->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        decScreen_i = new QTextEdit(int_2);
        decScreen_i->setObjectName(QString::fromUtf8("decScreen_i"));
        decScreen_i->setGeometry(QRect(50, 280, 821, 51));
        decScreen_i->setFont(font);
        decScreen_i->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        hexScreen_i = new QTextEdit(int_2);
        hexScreen_i->setObjectName(QString::fromUtf8("hexScreen_i"));
        hexScreen_i->setGeometry(QRect(50, 450, 821, 51));
        hexScreen_i->setFont(font);
        hexScreen_i->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        equalBin_i = new QPushButton(int_2);
        equalBin_i->setObjectName(QString::fromUtf8("equalBin_i"));
        equalBin_i->setGeometry(QRect(870, 110, 51, 51));
        equalBin_i->setFont(font2);
        equalBin_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        equalDec_i = new QPushButton(int_2);
        equalDec_i->setObjectName(QString::fromUtf8("equalDec_i"));
        equalDec_i->setGeometry(QRect(870, 280, 51, 51));
        equalDec_i->setFont(font2);
        equalDec_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        equalHex_i = new QPushButton(int_2);
        equalHex_i->setObjectName(QString::fromUtf8("equalHex_i"));
        equalHex_i->setGeometry(QRect(870, 450, 51, 51));
        equalHex_i->setFont(font2);
        equalHex_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        dichTrai = new QPushButton(int_2);
        dichTrai->setObjectName(QString::fromUtf8("dichTrai"));
        dichTrai->setGeometry(QRect(420, 670, 81, 81));
        dichTrai->setFont(font2);
        dichTrai->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        dichPhai = new QPushButton(int_2);
        dichPhai->setObjectName(QString::fromUtf8("dichPhai"));
        dichPhai->setGeometry(QRect(340, 670, 81, 81));
        dichPhai->setFont(font2);
        dichPhai->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        xoayTrai = new QPushButton(int_2);
        xoayTrai->setObjectName(QString::fromUtf8("xoayTrai"));
        xoayTrai->setGeometry(QRect(500, 670, 81, 81));
        xoayTrai->setFont(font2);
        xoayTrai->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        xoayPhai = new QPushButton(int_2);
        xoayPhai->setObjectName(QString::fromUtf8("xoayPhai"));
        xoayPhai->setGeometry(QRect(580, 670, 81, 81));
        xoayPhai->setFont(font2);
        xoayPhai->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        binToDec_i = new QPushButton(int_2);
        binToDec_i->setObjectName(QString::fromUtf8("binToDec_i"));
        binToDec_i->setGeometry(QRect(260, 160, 181, 61));
        binToDec_i->setFont(font1);
        binToDec_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        binToHex_i = new QPushButton(int_2);
        binToHex_i->setObjectName(QString::fromUtf8("binToHex_i"));
        binToHex_i->setGeometry(QRect(500, 160, 181, 61));
        binToHex_i->setFont(font1);
        binToHex_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        decToBin_i = new QPushButton(int_2);
        decToBin_i->setObjectName(QString::fromUtf8("decToBin_i"));
        decToBin_i->setGeometry(QRect(260, 330, 181, 61));
        decToBin_i->setFont(font1);
        decToBin_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        decToHex_i = new QPushButton(int_2);
        decToHex_i->setObjectName(QString::fromUtf8("decToHex_i"));
        decToHex_i->setGeometry(QRect(500, 330, 181, 61));
        decToHex_i->setFont(font1);
        decToHex_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        hexToBin_i = new QPushButton(int_2);
        hexToBin_i->setObjectName(QString::fromUtf8("hexToBin_i"));
        hexToBin_i->setGeometry(QRect(260, 500, 181, 61));
        hexToBin_i->setFont(font1);
        hexToBin_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        hexToDec_i = new QPushButton(int_2);
        hexToDec_i->setObjectName(QString::fromUtf8("hexToDec_i"));
        hexToDec_i->setGeometry(QRect(500, 500, 181, 61));
        hexToDec_i->setFont(font1);
        hexToDec_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        label_5 = new QLabel(int_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 40, 41, 711));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 45);"));
        not_i = new QPushButton(int_2);
        not_i->setObjectName(QString::fromUtf8("not_i"));
        not_i->setGeometry(QRect(260, 670, 81, 81));
        not_i->setFont(font2);
        not_i->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 255, 255);"));
        not_i_2 = new QPushButton(int_2);
        not_i_2->setObjectName(QString::fromUtf8("not_i_2"));
        not_i_2->setGeometry(QRect(180, 670, 81, 81));
        not_i_2->setFont(font2);
        not_i_2->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);\n"
"color: rgb(255, 85, 0);"));
        calculator->addWidget(int_2);
        switchtofloat->raise();
        xoayPhai->raise();
        xoayTrai->raise();
        dichTrai->raise();
        label_5->raise();
        equalHex_i->raise();
        equalDec_i->raise();
        equalBin_i->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        dichPhai->raise();
        binToDec_i->raise();
        binToHex_i->raise();
        decToBin_i->raise();
        decToHex_i->raise();
        hexToBin_i->raise();
        hexToDec_i->raise();
        binScreen_i->raise();
        decScreen_i->raise();
        hexScreen_i->raise();
        not_i->raise();
        not_i_2->raise();
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        calculator->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        switchtoint->setText(QCoreApplication::translate("MainWindow", "Switch To\n"
"Integer Mode", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "                                         Floating Mode", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Binary", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Decimal", nullptr));
        binToDec_f->setText(QCoreApplication::translate("MainWindow", "Convert To Dec", nullptr));
        decToBin_f->setText(QCoreApplication::translate("MainWindow", "Convert To Bin", nullptr));
        not_i_3->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        switchtofloat->setText(QCoreApplication::translate("MainWindow", "Switch To\n"
"Floating Point Mode", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Binary", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Decimal", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Heximal", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "                                         Integer Mode", nullptr));
        equalBin_i->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        equalDec_i->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        equalHex_i->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        dichTrai->setText(QCoreApplication::translate("MainWindow", "SHL", nullptr));
        dichPhai->setText(QCoreApplication::translate("MainWindow", "SHR", nullptr));
        xoayTrai->setText(QCoreApplication::translate("MainWindow", "ROL", nullptr));
        xoayPhai->setText(QCoreApplication::translate("MainWindow", "ROR", nullptr));
        binToDec_i->setText(QCoreApplication::translate("MainWindow", "Convert To Dec", nullptr));
        binToHex_i->setText(QCoreApplication::translate("MainWindow", "Convert To Hex", nullptr));
        decToBin_i->setText(QCoreApplication::translate("MainWindow", "Convert To Bin", nullptr));
        decToHex_i->setText(QCoreApplication::translate("MainWindow", "Convert To Hex", nullptr));
        hexToBin_i->setText(QCoreApplication::translate("MainWindow", "Convert To Bin", nullptr));
        hexToDec_i->setText(QCoreApplication::translate("MainWindow", "Convert To Dec", nullptr));
        label_5->setText(QString());
        not_i->setText(QCoreApplication::translate("MainWindow", "NOT", nullptr));
        not_i_2->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
