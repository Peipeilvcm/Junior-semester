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
#include <QtWidgets/QComboBox>
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
    QPushButton *RegisterButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *acoountLineEdit;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *idcreditLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label_5;
    QComboBox *banknameComboBox;
    QLineEdit *phoneLineEdit;
    QLineEdit *passwordconfirmLineEdit;
    QLabel *label_6;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(400, 300);
        RegisterDialog->setStyleSheet(QStringLiteral("background:white;"));
        RegisterButton = new QPushButton(RegisterDialog);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        RegisterButton->setGeometry(QRect(110, 250, 190, 30));
        RegisterButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        layoutWidget = new QWidget(RegisterDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 10, 301, 220));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(22, 165, 228);"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(22, 165, 228);"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        acoountLineEdit = new QLineEdit(layoutWidget);
        acoountLineEdit->setObjectName(QStringLiteral("acoountLineEdit"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        acoountLineEdit->setFont(font);
        acoountLineEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(acoountLineEdit, 0, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(22, 165, 228);"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(22, 165, 228);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idcreditLineEdit = new QLineEdit(layoutWidget);
        idcreditLineEdit->setObjectName(QStringLiteral("idcreditLineEdit"));
        idcreditLineEdit->setFont(font);
        idcreditLineEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(idcreditLineEdit, 4, 2, 1, 1);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setStyleSheet(QStringLiteral(""));
        passwordLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(passwordLineEdit, 2, 2, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color: rgb(22, 165, 228);"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        banknameComboBox = new QComboBox(layoutWidget);
        banknameComboBox->setObjectName(QStringLiteral("banknameComboBox"));
        banknameComboBox->setFont(font);
        banknameComboBox->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));

        gridLayout->addWidget(banknameComboBox, 1, 2, 1, 1);

        phoneLineEdit = new QLineEdit(layoutWidget);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));
        phoneLineEdit->setFont(font);
        phoneLineEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(phoneLineEdit, 5, 2, 1, 1);

        passwordconfirmLineEdit = new QLineEdit(layoutWidget);
        passwordconfirmLineEdit->setObjectName(QStringLiteral("passwordconfirmLineEdit"));
        passwordconfirmLineEdit->setFont(font);
        passwordconfirmLineEdit->setStyleSheet(QStringLiteral(""));
        passwordconfirmLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordconfirmLineEdit, 3, 2, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("color: rgb(22, 165, 228);"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", Q_NULLPTR));
        RegisterButton->setText(QApplication::translate("RegisterDialog", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterDialog", "\350\272\253\344\273\275\350\257\201\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegisterDialog", "\346\211\200\345\261\236\351\223\266\350\241\214\345\220\215\347\247\260", Q_NULLPTR));
        label->setText(QApplication::translate("RegisterDialog", "\345\215\241\345\217\267", Q_NULLPTR));
        label_5->setText(QApplication::translate("RegisterDialog", "\350\201\224\347\263\273\346\226\271\345\274\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegisterDialog", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
