/********************************************************************************
** Form generated from reading UI file 'accountdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTDIALOG_H
#define UI_ACCOUNTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountDialog
{
public:
    QPushButton *witdrawEntryButton;
    QPushButton *depositEntryButton;
    QPushButton *setButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *accountNumLabel;
    QLabel *bankNameLabel;
    QLabel *idcreditLabel;
    QLabel *phoneNumLabel;
    QLabel *balanceLabel;
    QPushButton *logoutButton;

    void setupUi(QDialog *AccountDialog)
    {
        if (AccountDialog->objectName().isEmpty())
            AccountDialog->setObjectName(QStringLiteral("AccountDialog"));
        AccountDialog->resize(400, 300);
        AccountDialog->setStyleSheet(QStringLiteral("background:white;"));
        witdrawEntryButton = new QPushButton(AccountDialog);
        witdrawEntryButton->setObjectName(QStringLiteral("witdrawEntryButton"));
        witdrawEntryButton->setGeometry(QRect(30, 262, 75, 31));
        witdrawEntryButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));
        depositEntryButton = new QPushButton(AccountDialog);
        depositEntryButton->setObjectName(QStringLiteral("depositEntryButton"));
        depositEntryButton->setGeometry(QRect(120, 262, 75, 31));
        depositEntryButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));
        setButton = new QPushButton(AccountDialog);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(210, 262, 75, 31));
        setButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));
        layoutWidget = new QWidget(AccountDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 361, 221));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        accountNumLabel = new QLabel(layoutWidget);
        accountNumLabel->setObjectName(QStringLiteral("accountNumLabel"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        accountNumLabel->setFont(font1);
        accountNumLabel->setStyleSheet(QLatin1String("color: rgb(22, 165, 228);\n"
"background-color: white;\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        verticalLayout_2->addWidget(accountNumLabel);

        bankNameLabel = new QLabel(layoutWidget);
        bankNameLabel->setObjectName(QStringLiteral("bankNameLabel"));
        bankNameLabel->setFont(font1);
        bankNameLabel->setStyleSheet(QLatin1String("color: rgb(22, 165, 228);\n"
"background-color: white;\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        verticalLayout_2->addWidget(bankNameLabel);

        idcreditLabel = new QLabel(layoutWidget);
        idcreditLabel->setObjectName(QStringLiteral("idcreditLabel"));
        idcreditLabel->setFont(font1);
        idcreditLabel->setStyleSheet(QLatin1String("color: rgb(22, 165, 228);\n"
"background-color: white;\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        verticalLayout_2->addWidget(idcreditLabel);

        phoneNumLabel = new QLabel(layoutWidget);
        phoneNumLabel->setObjectName(QStringLiteral("phoneNumLabel"));
        phoneNumLabel->setFont(font1);
        phoneNumLabel->setStyleSheet(QLatin1String("color: rgb(22, 165, 228);\n"
"background-color: white;\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        verticalLayout_2->addWidget(phoneNumLabel);

        balanceLabel = new QLabel(layoutWidget);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        balanceLabel->setFont(font1);
        balanceLabel->setStyleSheet(QLatin1String("color: rgb(22, 165, 228);\n"
"background-color: white;\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        verticalLayout_2->addWidget(balanceLabel);


        horizontalLayout->addLayout(verticalLayout_2);

        logoutButton = new QPushButton(AccountDialog);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setGeometry(QRect(300, 262, 75, 31));
        logoutButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        retranslateUi(AccountDialog);

        QMetaObject::connectSlotsByName(AccountDialog);
    } // setupUi

    void retranslateUi(QDialog *AccountDialog)
    {
        AccountDialog->setWindowTitle(QApplication::translate("AccountDialog", "Dialog", Q_NULLPTR));
        witdrawEntryButton->setText(QApplication::translate("AccountDialog", "\345\217\226\346\254\276", Q_NULLPTR));
        depositEntryButton->setText(QApplication::translate("AccountDialog", "\345\255\230\346\254\276", Q_NULLPTR));
        setButton->setText(QApplication::translate("AccountDialog", "\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("AccountDialog", "\345\215\241\345\217\267:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AccountDialog", "\346\211\200\345\261\236\351\223\266\350\241\214:", Q_NULLPTR));
        label_3->setText(QApplication::translate("AccountDialog", "\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201:", Q_NULLPTR));
        label_4->setText(QApplication::translate("AccountDialog", "\350\201\224\347\263\273\347\224\265\350\257\235", Q_NULLPTR));
        label_5->setText(QApplication::translate("AccountDialog", "\345\215\241\345\206\205\344\275\231\351\242\235", Q_NULLPTR));
        accountNumLabel->setText(QApplication::translate("AccountDialog", "TextLabel", Q_NULLPTR));
        bankNameLabel->setText(QApplication::translate("AccountDialog", "TextLabel", Q_NULLPTR));
        idcreditLabel->setText(QApplication::translate("AccountDialog", "TextLabel", Q_NULLPTR));
        phoneNumLabel->setText(QApplication::translate("AccountDialog", "TextLabel", Q_NULLPTR));
        balanceLabel->setText(QApplication::translate("AccountDialog", "TextLabel", Q_NULLPTR));
        logoutButton->setText(QApplication::translate("AccountDialog", "\346\263\250\351\224\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AccountDialog: public Ui_AccountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTDIALOG_H
