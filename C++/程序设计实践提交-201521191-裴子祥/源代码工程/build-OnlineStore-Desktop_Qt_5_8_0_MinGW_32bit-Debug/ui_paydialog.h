/********************************************************************************
** Form generated from reading UI file 'paydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYDIALOG_H
#define UI_PAYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PayDialog
{
public:
    QLabel *cardLabel;
    QComboBox *accountNumComboBox;
    QLabel *label_2;
    QLineEdit *passwLineEdit;
    QPushButton *payConfirmButton;
    QPushButton *returnButton;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *oriPriceSumLabel_2;
    QLabel *label_8;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QLabel *priceSumLabel_2;
    QLabel *label_14;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_16;
    QLabel *fullThenReduceLabel_2;
    QLabel *label_17;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_18;
    QLabel *paySumLabel_2;
    QLabel *label_19;

    void setupUi(QDialog *PayDialog)
    {
        if (PayDialog->objectName().isEmpty())
            PayDialog->setObjectName(QStringLiteral("PayDialog"));
        PayDialog->resize(640, 474);
        PayDialog->setStyleSheet(QLatin1String("#PayDialog{\n"
"border-image:url(:/icon/icon/kobe2.jpg);\n"
"}\n"
"#PayDialog *{\n"
"border-image:url();\n"
"}"));
        cardLabel = new QLabel(PayDialog);
        cardLabel->setObjectName(QStringLiteral("cardLabel"));
        cardLabel->setGeometry(QRect(270, 370, 71, 16));
        cardLabel->setStyleSheet(QStringLiteral("color:white;"));
        accountNumComboBox = new QComboBox(PayDialog);
        accountNumComboBox->setObjectName(QStringLiteral("accountNumComboBox"));
        accountNumComboBox->setGeometry(QRect(350, 370, 180, 22));
        accountNumComboBox->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_2 = new QLabel(PayDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 400, 71, 16));
        label_2->setStyleSheet(QStringLiteral("color: white;"));
        passwLineEdit = new QLineEdit(PayDialog);
        passwLineEdit->setObjectName(QStringLiteral("passwLineEdit"));
        passwLineEdit->setGeometry(QRect(350, 400, 180, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        passwLineEdit->setFont(font);
        passwLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        passwLineEdit->setEchoMode(QLineEdit::Password);
        payConfirmButton = new QPushButton(PayDialog);
        payConfirmButton->setObjectName(QStringLiteral("payConfirmButton"));
        payConfirmButton->setGeometry(QRect(350, 430, 180, 30));
        payConfirmButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        returnButton = new QPushButton(PayDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(540, 430, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        tableWidget = new QTableWidget(PayDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 601, 321));
        layoutWidget = new QWidget(PayDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 360, 151, 14));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_7->addWidget(label_5);

        oriPriceSumLabel_2 = new QLabel(layoutWidget);
        oriPriceSumLabel_2->setObjectName(QStringLiteral("oriPriceSumLabel_2"));
        oriPriceSumLabel_2->setFont(font);
        oriPriceSumLabel_2->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_7->addWidget(oriPriceSumLabel_2);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_7->addWidget(label_8);

        layoutWidget_2 = new QWidget(PayDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 390, 140, 14));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_8->addWidget(label_11);

        priceSumLabel_2 = new QLabel(layoutWidget_2);
        priceSumLabel_2->setObjectName(QStringLiteral("priceSumLabel_2"));
        priceSumLabel_2->setFont(font);
        priceSumLabel_2->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_8->addWidget(priceSumLabel_2);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_8->addWidget(label_14);

        layoutWidget_3 = new QWidget(PayDialog);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(50, 420, 140, 14));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_9->addWidget(label_16);

        fullThenReduceLabel_2 = new QLabel(layoutWidget_3);
        fullThenReduceLabel_2->setObjectName(QStringLiteral("fullThenReduceLabel_2"));
        fullThenReduceLabel_2->setFont(font);
        fullThenReduceLabel_2->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_9->addWidget(fullThenReduceLabel_2);

        label_17 = new QLabel(layoutWidget_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_9->addWidget(label_17);

        layoutWidget_4 = new QWidget(PayDialog);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(50, 450, 152, 14));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_10->addWidget(label_18);

        paySumLabel_2 = new QLabel(layoutWidget_4);
        paySumLabel_2->setObjectName(QStringLiteral("paySumLabel_2"));
        paySumLabel_2->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_10->addWidget(paySumLabel_2);

        label_19 = new QLabel(layoutWidget_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_10->addWidget(label_19);


        retranslateUi(PayDialog);

        QMetaObject::connectSlotsByName(PayDialog);
    } // setupUi

    void retranslateUi(QDialog *PayDialog)
    {
        PayDialog->setWindowTitle(QApplication::translate("PayDialog", "Dialog", Q_NULLPTR));
        cardLabel->setText(QApplication::translate("PayDialog", "\351\200\211\346\213\251\351\223\266\350\241\214\345\215\241\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("PayDialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        payConfirmButton->setText(QApplication::translate("PayDialog", "\347\241\256\350\256\244\346\224\257\344\273\230", Q_NULLPTR));
        returnButton->setText(QApplication::translate("PayDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
        label_5->setText(QApplication::translate("PayDialog", "\346\200\273\345\216\237\344\273\267\357\274\232", Q_NULLPTR));
        oriPriceSumLabel_2->setText(QApplication::translate("PayDialog", "XXXXXXXXXXX", Q_NULLPTR));
        label_8->setText(QApplication::translate("PayDialog", "\345\205\203", Q_NULLPTR));
        label_11->setText(QApplication::translate("PayDialog", "\346\212\230\345\220\216\357\274\232", Q_NULLPTR));
        priceSumLabel_2->setText(QApplication::translate("PayDialog", "XXXXXXXXXXX", Q_NULLPTR));
        label_14->setText(QApplication::translate("PayDialog", "\345\205\203", Q_NULLPTR));
        label_16->setText(QApplication::translate("PayDialog", "\346\273\241\345\207\217\357\274\232", Q_NULLPTR));
        fullThenReduceLabel_2->setText(QApplication::translate("PayDialog", "XXXXXXXXXXX", Q_NULLPTR));
        label_17->setText(QApplication::translate("PayDialog", "\345\205\203", Q_NULLPTR));
        label_18->setText(QApplication::translate("PayDialog", "\345\256\236\351\231\205\345\272\224\344\273\230\357\274\232", Q_NULLPTR));
        paySumLabel_2->setText(QApplication::translate("PayDialog", "XXXXXXXXXXX", Q_NULLPTR));
        label_19->setText(QApplication::translate("PayDialog", "\345\205\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PayDialog: public Ui_PayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYDIALOG_H
