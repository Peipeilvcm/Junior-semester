/********************************************************************************
** Form generated from reading UI file 'managedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEDIALOG_H
#define UI_MANAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ManageDialog
{
public:
    QTableView *tableView;
    QLabel *label;
    QPushButton *returnButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *ManageDialog)
    {
        if (ManageDialog->objectName().isEmpty())
            ManageDialog->setObjectName(QStringLiteral("ManageDialog"));
        ManageDialog->resize(780, 560);
        ManageDialog->setStyleSheet(QStringLiteral("background:white;"));
        tableView = new QTableView(ManageDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 70, 740, 420));
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        label = new QLabel(ManageDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(609, 10, 151, 48));
        QFont font;
        font.setFamily(QStringLiteral("SimSun-ExtB"));
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        returnButton = new QPushButton(ManageDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(670, 510, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        deleteButton = new QPushButton(ManageDialog);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(570, 510, 80, 30));
        deleteButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(22, 165, 228);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));

        retranslateUi(ManageDialog);

        QMetaObject::connectSlotsByName(ManageDialog);
    } // setupUi

    void retranslateUi(QDialog *ManageDialog)
    {
        ManageDialog->setWindowTitle(QApplication::translate("ManageDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ManageDialog", "\350\264\246\346\210\267\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        returnButton->setText(QApplication::translate("ManageDialog", "\350\277\224\345\233\236", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("ManageDialog", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManageDialog: public Ui_ManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEDIALOG_H
