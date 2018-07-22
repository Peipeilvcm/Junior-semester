/********************************************************************************
** Form generated from reading UI file 'addgoodsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGOODSDIALOG_H
#define UI_ADDGOODSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addGoodsDialog
{
public:
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *typeComboBox;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *originalPriceLineEdit;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *inventorySpinBox;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *otherLineEdit;
    QPushButton *returnButton;
    QPushButton *addConfirmButton;
    QTextEdit *descriptionTextEdit;
    QLabel *label_7;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *rateSpinBox;

    void setupUi(QDialog *addGoodsDialog)
    {
        if (addGoodsDialog->objectName().isEmpty())
            addGoodsDialog->setObjectName(QStringLiteral("addGoodsDialog"));
        addGoodsDialog->resize(400, 398);
        addGoodsDialog->setStyleSheet(QLatin1String("#addGoodsDialog{\n"
"border-image:url(:/icon/icon/kobe3.jpg);\n"
"}\n"
"#addGoodsDialog *{\n"
"border-image:url();\n"
"}"));
        layoutWidget1 = new QWidget(addGoodsDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(31, 49, 113, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: white;"));

        horizontalLayout_2->addWidget(label_2);

        typeComboBox = new QComboBox(layoutWidget1);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));
        typeComboBox->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));

        horizontalLayout_2->addWidget(typeComboBox);

        layoutWidget_2 = new QWidget(addGoodsDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 90, 177, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: white;"));

        horizontalLayout_3->addWidget(label_3);

        originalPriceLineEdit = new QLineEdit(layoutWidget_2);
        originalPriceLineEdit->setObjectName(QStringLiteral("originalPriceLineEdit"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        originalPriceLineEdit->setFont(font);
        originalPriceLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_3->addWidget(originalPriceLineEdit);

        layoutWidget_3 = new QWidget(addGoodsDialog);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 120, 102, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: white;"));

        horizontalLayout_4->addWidget(label_4);

        inventorySpinBox = new QSpinBox(layoutWidget_3);
        inventorySpinBox->setObjectName(QStringLiteral("inventorySpinBox"));
        inventorySpinBox->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        inventorySpinBox->setMaximum(10000);

        horizontalLayout_4->addWidget(inventorySpinBox);

        layoutWidget_5 = new QWidget(addGoodsDialog);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(30, 180, 201, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("color: white;"));

        horizontalLayout_6->addWidget(label_6);

        otherLineEdit = new QLineEdit(layoutWidget_5);
        otherLineEdit->setObjectName(QStringLiteral("otherLineEdit"));
        otherLineEdit->setFont(font);
        otherLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_6->addWidget(otherLineEdit);

        returnButton = new QPushButton(addGoodsDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(300, 290, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        addConfirmButton = new QPushButton(addGoodsDialog);
        addConfirmButton->setObjectName(QStringLiteral("addConfirmButton"));
        addConfirmButton->setGeometry(QRect(210, 290, 80, 30));
        addConfirmButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        descriptionTextEdit = new QTextEdit(addGoodsDialog);
        descriptionTextEdit->setObjectName(QStringLiteral("descriptionTextEdit"));
        descriptionTextEdit->setGeometry(QRect(90, 210, 281, 71));
        descriptionTextEdit->setFont(font);
        descriptionTextEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        label_7 = new QLabel(addGoodsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 210, 60, 16));
        label_7->setStyleSheet(QStringLiteral("color: white;"));
        layoutWidget2 = new QWidget(addGoodsDialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(31, 21, 177, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: white;"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(layoutWidget2);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setFont(font);
        nameLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout->addWidget(nameLineEdit);

        layoutWidget3 = new QWidget(addGoodsDialog);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 150, 114, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color: white;"));

        horizontalLayout_5->addWidget(label_5);

        rateSpinBox = new QDoubleSpinBox(layoutWidget3);
        rateSpinBox->setObjectName(QStringLiteral("rateSpinBox"));
        rateSpinBox->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        rateSpinBox->setMaximum(1);
        rateSpinBox->setSingleStep(0.01);

        horizontalLayout_5->addWidget(rateSpinBox);

        label_7->raise();
        layoutWidget1->raise();
        layoutWidget2->raise();
        layoutWidget3->raise();
        layoutWidget_2->raise();
        layoutWidget_3->raise();
        layoutWidget_5->raise();
        returnButton->raise();
        addConfirmButton->raise();
        descriptionTextEdit->raise();

        retranslateUi(addGoodsDialog);

        QMetaObject::connectSlotsByName(addGoodsDialog);
    } // setupUi

    void retranslateUi(QDialog *addGoodsDialog)
    {
        addGoodsDialog->setWindowTitle(QApplication::translate("addGoodsDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("addGoodsDialog", "\345\223\201\347\261\273\357\274\232", Q_NULLPTR));
        typeComboBox->clear();
        typeComboBox->insertItems(0, QStringList()
         << QApplication::translate("addGoodsDialog", "BOOK", Q_NULLPTR)
         << QApplication::translate("addGoodsDialog", "CLOTH", Q_NULLPTR)
         << QApplication::translate("addGoodsDialog", "FOOD", Q_NULLPTR)
         << QApplication::translate("addGoodsDialog", "PHONE", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("addGoodsDialog", "\345\216\237\344\273\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("addGoodsDialog", "\345\272\223\345\255\230\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("addGoodsDialog", "\345\205\266\345\256\203\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        returnButton->setText(QApplication::translate("addGoodsDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
        addConfirmButton->setText(QApplication::translate("addGoodsDialog", "\347\241\256\350\256\244\346\267\273\345\212\240", Q_NULLPTR));
        label_7->setText(QApplication::translate("addGoodsDialog", "\344\272\247\345\223\201\346\217\217\350\277\260\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("addGoodsDialog", "\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("addGoodsDialog", "\346\212\230\346\211\243\347\216\207\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addGoodsDialog: public Ui_addGoodsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGOODSDIALOG_H
