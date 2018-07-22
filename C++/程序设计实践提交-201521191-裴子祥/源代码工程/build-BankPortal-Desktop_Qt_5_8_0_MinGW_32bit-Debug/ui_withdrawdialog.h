/********************************************************************************
** Form generated from reading UI file 'withdrawdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWDIALOG_H
#define UI_WITHDRAWDIALOG_H

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

class Ui_WithdrawDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *withdrawLineEdit;
    QPushButton *withdrawButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *WithdrawDialog)
    {
        if (WithdrawDialog->objectName().isEmpty())
            WithdrawDialog->setObjectName(QStringLiteral("WithdrawDialog"));
        WithdrawDialog->resize(280, 100);
        layoutWidget = new QWidget(WithdrawDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 261, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        withdrawLineEdit = new QLineEdit(layoutWidget);
        withdrawLineEdit->setObjectName(QStringLiteral("withdrawLineEdit"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        withdrawLineEdit->setFont(font);
        withdrawLineEdit->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(withdrawLineEdit);

        withdrawButton = new QPushButton(layoutWidget);
        withdrawButton->setObjectName(QStringLiteral("withdrawButton"));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(12);
        withdrawButton->setFont(font1);
        withdrawButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));

        horizontalLayout->addWidget(withdrawButton);


        verticalLayout->addLayout(horizontalLayout);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));

        verticalLayout->addWidget(cancelButton);


        retranslateUi(WithdrawDialog);

        QMetaObject::connectSlotsByName(WithdrawDialog);
    } // setupUi

    void retranslateUi(QDialog *WithdrawDialog)
    {
        WithdrawDialog->setWindowTitle(QApplication::translate("WithdrawDialog", "Dialog", Q_NULLPTR));
        withdrawButton->setText(QApplication::translate("WithdrawDialog", "\345\217\226\346\254\276", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("WithdrawDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WithdrawDialog: public Ui_WithdrawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWDIALOG_H
