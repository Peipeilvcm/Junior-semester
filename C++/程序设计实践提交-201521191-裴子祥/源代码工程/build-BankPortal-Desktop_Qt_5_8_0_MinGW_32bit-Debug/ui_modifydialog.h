/********************************************************************************
** Form generated from reading UI file 'modifydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYDIALOG_H
#define UI_MODIFYDIALOG_H

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

class Ui_ModifyDialog
{
public:
    QLineEdit *newPasswordLineEdit;
    QLabel *label_2;
    QLineEdit *newPassword2LineEdit;
    QLineEdit *oldpasswordLineEdit;
    QLabel *label;
    QLabel *label_3;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label_4;

    void setupUi(QDialog *ModifyDialog)
    {
        if (ModifyDialog->objectName().isEmpty())
            ModifyDialog->setObjectName(QStringLiteral("ModifyDialog"));
        ModifyDialog->resize(400, 300);
        ModifyDialog->setStyleSheet(QStringLiteral("background-color: white;"));
        newPasswordLineEdit = new QLineEdit(ModifyDialog);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));
        newPasswordLineEdit->setGeometry(QRect(180, 140, 171, 20));
        newPasswordLineEdit->setStyleSheet(QStringLiteral("background-color:white;color: rgb(36, 118, 217);"));
        newPasswordLineEdit->setEchoMode(QLineEdit::Normal);
        newPasswordLineEdit->setClearButtonEnabled(true);
        label_2 = new QLabel(ModifyDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 140, 71, 21));
        label_2->setStyleSheet(QStringLiteral("color:rgb(22, 165, 228);"));
        newPassword2LineEdit = new QLineEdit(ModifyDialog);
        newPassword2LineEdit->setObjectName(QStringLiteral("newPassword2LineEdit"));
        newPassword2LineEdit->setGeometry(QRect(180, 170, 171, 20));
        newPassword2LineEdit->setStyleSheet(QStringLiteral("background-color:white;color: rgb(36, 118, 217);"));
        newPassword2LineEdit->setEchoMode(QLineEdit::Password);
        newPassword2LineEdit->setClearButtonEnabled(true);
        oldpasswordLineEdit = new QLineEdit(ModifyDialog);
        oldpasswordLineEdit->setObjectName(QStringLiteral("oldpasswordLineEdit"));
        oldpasswordLineEdit->setGeometry(QRect(180, 110, 171, 20));
        oldpasswordLineEdit->setStyleSheet(QStringLiteral("background-color:white;color: rgb(36, 118, 217);"));
        oldpasswordLineEdit->setEchoMode(QLineEdit::Password);
        oldpasswordLineEdit->setClearButtonEnabled(true);
        label = new QLabel(ModifyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 110, 71, 21));
        label->setStyleSheet(QStringLiteral("color:rgb(22, 165, 228);"));
        label_3 = new QLabel(ModifyDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 170, 101, 21));
        label_3->setStyleSheet(QStringLiteral("color:rgb(22, 165, 228);"));
        confirmButton = new QPushButton(ModifyDialog);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(110, 230, 80, 30));
        confirmButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        cancelButton = new QPushButton(ModifyDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(220, 230, 80, 30));
        cancelButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_4 = new QLabel(ModifyDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 30, 171, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(22, 165, 228);"));

        retranslateUi(ModifyDialog);

        QMetaObject::connectSlotsByName(ModifyDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifyDialog)
    {
        ModifyDialog->setWindowTitle(QApplication::translate("ModifyDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModifyDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ModifyDialog", "\345\216\237\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ModifyDialog", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ModifyDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ModifyDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("ModifyDialog", "Modify Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModifyDialog: public Ui_ModifyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYDIALOG_H
