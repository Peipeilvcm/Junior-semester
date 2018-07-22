/********************************************************************************
** Form generated from reading UI file 'depositdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITDIALOG_H
#define UI_DEPOSITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *depositLineEdit;
    QPushButton *depositButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *DepositDialog)
    {
        if (DepositDialog->objectName().isEmpty())
            DepositDialog->setObjectName(QStringLiteral("DepositDialog"));
        DepositDialog->resize(280, 100);
        layoutWidget = new QWidget(DepositDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 261, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        depositLineEdit = new QLineEdit(layoutWidget);
        depositLineEdit->setObjectName(QStringLiteral("depositLineEdit"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        depositLineEdit->setFont(font);
        depositLineEdit->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(depositLineEdit);

        depositButton = new QPushButton(layoutWidget);
        depositButton->setObjectName(QStringLiteral("depositButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(depositButton->sizePolicy().hasHeightForWidth());
        depositButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(12);
        depositButton->setFont(font1);
        depositButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        horizontalLayout->addWidget(depositButton);


        verticalLayout->addLayout(horizontalLayout);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;\n"
""));

        verticalLayout->addWidget(cancelButton);


        retranslateUi(DepositDialog);

        QMetaObject::connectSlotsByName(DepositDialog);
    } // setupUi

    void retranslateUi(QDialog *DepositDialog)
    {
        DepositDialog->setWindowTitle(QApplication::translate("DepositDialog", "Dialog", Q_NULLPTR));
        depositLineEdit->setText(QString());
        depositButton->setText(QApplication::translate("DepositDialog", "\345\255\230\346\254\276", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("DepositDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DepositDialog: public Ui_DepositDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITDIALOG_H
