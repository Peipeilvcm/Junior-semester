/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *LoginButton;
    QPushButton *ManageButton;
    QLabel *label_2;
    QLineEdit *accountLineEdit;
    QPushButton *RegisterButton;
    QLineEdit *passwordLineEdit;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QLabel *label_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background:white;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 170, 40, 30));
        label->setStyleSheet(QStringLiteral("color:rgb(22, 165, 228);"));
        LoginButton = new QPushButton(centralWidget);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setGeometry(QRect(100, 240, 190, 30));
        LoginButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        ManageButton = new QPushButton(centralWidget);
        ManageButton->setObjectName(QStringLiteral("ManageButton"));
        ManageButton->setGeometry(QRect(300, 240, 80, 30));
        ManageButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 200, 40, 30));
        label_2->setStyleSheet(QStringLiteral("color:rgb(22, 165, 228);"));
        accountLineEdit = new QLineEdit(centralWidget);
        accountLineEdit->setObjectName(QStringLiteral("accountLineEdit"));
        accountLineEdit->setGeometry(QRect(100, 170, 190, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        accountLineEdit->setFont(font);
        RegisterButton = new QPushButton(centralWidget);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        RegisterButton->setGeometry(QRect(300, 170, 80, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        RegisterButton->setFont(font1);
        RegisterButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        passwordLineEdit = new QLineEdit(centralWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(100, 200, 190, 30));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(30, 10, 331, 20));
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 20, 20, 271));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(350, 20, 20, 151));
        line_3->setStyleSheet(QStringLiteral(""));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(39, 269, 321, 31));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(360, 270, 3, 10));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(360, 200, 3, 40));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 90, 201, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);
        label_6->setStyleSheet(QLatin1String("color: rgb(22, 165, 228);\n"
"background:transparent;"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\215\241\345\217\267", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        ManageButton->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\345\205\245\345\217\243", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        RegisterButton->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214\351\223\266\350\241\214\345\215\241", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "BANK PORTAL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
