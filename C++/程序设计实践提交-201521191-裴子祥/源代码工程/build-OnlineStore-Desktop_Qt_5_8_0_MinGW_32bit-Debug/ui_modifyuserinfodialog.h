/********************************************************************************
** Form generated from reading UI file 'modifyuserinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYUSERINFODIALOG_H
#define UI_MODIFYUSERINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modifyUserInfoDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *oldPasswordLineEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *newPasswordLineEdit;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *newPassword2LineEdit;
    QPushButton *returnButton;
    QPushButton *modifyPasswordButton;
    QFrame *line;
    QPushButton *modifyNameButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;

    void setupUi(QDialog *modifyUserInfoDialog)
    {
        if (modifyUserInfoDialog->objectName().isEmpty())
            modifyUserInfoDialog->setObjectName(QStringLiteral("modifyUserInfoDialog"));
        modifyUserInfoDialog->resize(400, 300);
        modifyUserInfoDialog->setStyleSheet(QLatin1String("#modifyUserInfoDialog{\n"
"border-image:url(:/icon/icon/kobe2.jpg);\n"
"}\n"
"#modifyUserInfoDialog *{\n"
"border-image:url();\n"
"}"));
        layoutWidget = new QWidget(modifyUserInfoDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 100, 177, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_2->addWidget(label_2);

        oldPasswordLineEdit = new QLineEdit(layoutWidget);
        oldPasswordLineEdit->setObjectName(QStringLiteral("oldPasswordLineEdit"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        oldPasswordLineEdit->setFont(font);
        oldPasswordLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        oldPasswordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(oldPasswordLineEdit);

        layoutWidget_2 = new QWidget(modifyUserInfoDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(110, 130, 177, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_3->addWidget(label_3);

        newPasswordLineEdit = new QLineEdit(layoutWidget_2);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));
        newPasswordLineEdit->setFont(font);
        newPasswordLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_3->addWidget(newPasswordLineEdit);

        layoutWidget_3 = new QWidget(modifyUserInfoDialog);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(110, 160, 177, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_4->addWidget(label_4);

        newPassword2LineEdit = new QLineEdit(layoutWidget_3);
        newPassword2LineEdit->setObjectName(QStringLiteral("newPassword2LineEdit"));
        newPassword2LineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        newPassword2LineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(newPassword2LineEdit);

        returnButton = new QPushButton(modifyUserInfoDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(130, 250, 141, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        modifyPasswordButton = new QPushButton(modifyUserInfoDialog);
        modifyPasswordButton->setObjectName(QStringLiteral("modifyPasswordButton"));
        modifyPasswordButton->setGeometry(QRect(150, 190, 101, 30));
        modifyPasswordButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        line = new QFrame(modifyUserInfoDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(40, 230, 311, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        modifyNameButton = new QPushButton(modifyUserInfoDialog);
        modifyNameButton->setObjectName(QStringLiteral("modifyNameButton"));
        modifyNameButton->setGeometry(QRect(150, 50, 101, 30));
        modifyNameButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        layoutWidget1 = new QWidget(modifyUserInfoDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 20, 177, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(layoutWidget1);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setFont(font);
        nameLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout->addWidget(nameLineEdit);


        retranslateUi(modifyUserInfoDialog);

        QMetaObject::connectSlotsByName(modifyUserInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *modifyUserInfoDialog)
    {
        modifyUserInfoDialog->setWindowTitle(QApplication::translate("modifyUserInfoDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("modifyUserInfoDialog", "\345\216\237\345\257\206\347\240\201  ", Q_NULLPTR));
        label_3->setText(QApplication::translate("modifyUserInfoDialog", "\346\226\260\345\257\206\347\240\201  ", Q_NULLPTR));
        label_4->setText(QApplication::translate("modifyUserInfoDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        returnButton->setText(QApplication::translate("modifyUserInfoDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
        modifyPasswordButton->setText(QApplication::translate("modifyUserInfoDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\344\277\256\346\224\271", Q_NULLPTR));
        modifyNameButton->setText(QApplication::translate("modifyUserInfoDialog", "\347\241\256\350\256\244\346\230\265\347\247\260\344\277\256\346\224\271", Q_NULLPTR));
        label->setText(QApplication::translate("modifyUserInfoDialog", "\346\230\265\347\247\260    ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modifyUserInfoDialog: public Ui_modifyUserInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYUSERINFODIALOG_H
