/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLineEdit *passwordLineEdit;
    QLineEdit *phoneNumLineEdit;
    QPushButton *returnButton;
    QPushButton *loginButton;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 300);
        LoginDialog->setStyleSheet(QLatin1String("#LoginDialog{\n"
"border-image:url(:/icon/icon/timg.jpg);\n"
"}\n"
"#LoginDialog *{\n"
"border-image:url();\n"
"}"));
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 160, 51, 30));
        label->setStyleSheet(QStringLiteral("color: white;"));
        passwordLineEdit = new QLineEdit(LoginDialog);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(100, 190, 190, 30));
        passwordLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        phoneNumLineEdit = new QLineEdit(LoginDialog);
        phoneNumLineEdit->setObjectName(QStringLiteral("phoneNumLineEdit"));
        phoneNumLineEdit->setGeometry(QRect(100, 160, 190, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        phoneNumLineEdit->setFont(font);
        phoneNumLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        returnButton = new QPushButton(LoginDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(300, 230, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(100, 230, 190, 30));
        loginButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 190, 40, 30));
        label_2->setStyleSheet(QStringLiteral("color:white;"));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 60, 341, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: white;"));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        returnButton->setText(QApplication::translate("LoginDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
        loginButton->setText(QApplication::translate("LoginDialog", "\347\241\256\350\256\244\347\231\273\345\275\225", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginDialog", "Welcome to Login", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
