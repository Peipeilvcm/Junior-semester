/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QPushButton *registerButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *phoneNumLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label;
    QLineEdit *passwordconfirmLineEdit;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *nameLineEdit;
    QPushButton *returnButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(400, 300);
        RegisterDialog->setStyleSheet(QLatin1String("#RegisterDialog{\n"
"border-image:url(:/icon/icon/kobe3.jpg);\n"
"}\n"
"#RegisterDialog *{\n"
"border-image:url();\n"
"}"));
        registerButton = new QPushButton(RegisterDialog);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(110, 240, 190, 30));
        registerButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        layoutWidget = new QWidget(RegisterDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 301, 182));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:white;"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        phoneNumLineEdit = new QLineEdit(layoutWidget);
        phoneNumLineEdit->setObjectName(QStringLiteral("phoneNumLineEdit"));
        phoneNumLineEdit->setFont(font);
        phoneNumLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        gridLayout->addWidget(phoneNumLineEdit, 0, 2, 1, 1);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        gridLayout->addWidget(passwordLineEdit, 1, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:white;"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        passwordconfirmLineEdit = new QLineEdit(layoutWidget);
        passwordconfirmLineEdit->setObjectName(QStringLiteral("passwordconfirmLineEdit"));
        passwordconfirmLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        passwordconfirmLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordconfirmLineEdit, 2, 2, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color:white;"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color:white;"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setFont(font);
        nameLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        gridLayout->addWidget(nameLineEdit, 3, 2, 1, 1);

        returnButton = new QPushButton(RegisterDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(310, 240, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", Q_NULLPTR));
        registerButton->setText(QApplication::translate("RegisterDialog", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("RegisterDialog", "\346\211\213\346\234\272\345\217\267\346\263\250\345\206\214\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegisterDialog", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterDialog", "\346\230\265\347\247\260\357\274\232", Q_NULLPTR));
        returnButton->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
