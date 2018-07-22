/********************************************************************************
** Form generated from reading UI file 'accountmanagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTMANAGEDIALOG_H
#define UI_ACCOUNTMANAGEDIALOG_H

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

class Ui_accountManageDialog
{
public:
    QLabel *label;
    QLineEdit *passwordLineEdit;
    QPushButton *bindConfirmButton;
    QLabel *label_2;
    QLineEdit *accountNumLineEdit;
    QPushButton *returnButton;
    QLabel *label_3;

    void setupUi(QDialog *accountManageDialog)
    {
        if (accountManageDialog->objectName().isEmpty())
            accountManageDialog->setObjectName(QStringLiteral("accountManageDialog"));
        accountManageDialog->resize(400, 300);
        accountManageDialog->setStyleSheet(QLatin1String("#accountManageDialog{\n"
"border-image:url(:/icon/icon/timg.jpg);\n"
"}\n"
"#accountManageDialog *{\n"
"border-image:url();\n"
"}"));
        label = new QLabel(accountManageDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 150, 51, 30));
        label->setStyleSheet(QStringLiteral("color: white;"));
        passwordLineEdit = new QLineEdit(accountManageDialog);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(100, 180, 190, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        passwordLineEdit->setFont(font);
        passwordLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        bindConfirmButton = new QPushButton(accountManageDialog);
        bindConfirmButton->setObjectName(QStringLiteral("bindConfirmButton"));
        bindConfirmButton->setGeometry(QRect(100, 220, 190, 30));
        bindConfirmButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_2 = new QLabel(accountManageDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 180, 40, 30));
        label_2->setStyleSheet(QStringLiteral("color: white;"));
        accountNumLineEdit = new QLineEdit(accountManageDialog);
        accountNumLineEdit->setObjectName(QStringLiteral("accountNumLineEdit"));
        accountNumLineEdit->setGeometry(QRect(100, 150, 190, 30));
        accountNumLineEdit->setFont(font);
        accountNumLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        returnButton = new QPushButton(accountManageDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(300, 220, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_3 = new QLabel(accountManageDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 60, 351, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: white;"));

        retranslateUi(accountManageDialog);

        QMetaObject::connectSlotsByName(accountManageDialog);
    } // setupUi

    void retranslateUi(QDialog *accountManageDialog)
    {
        accountManageDialog->setWindowTitle(QApplication::translate("accountManageDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("accountManageDialog", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        passwordLineEdit->setText(QString());
        bindConfirmButton->setText(QApplication::translate("accountManageDialog", "\347\241\256\350\256\244\347\273\221\345\256\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("accountManageDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        accountNumLineEdit->setText(QString());
        returnButton->setText(QApplication::translate("accountManageDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
        label_3->setText(QApplication::translate("accountManageDialog", "Bind With Account", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class accountManageDialog: public Ui_accountManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTMANAGEDIALOG_H
