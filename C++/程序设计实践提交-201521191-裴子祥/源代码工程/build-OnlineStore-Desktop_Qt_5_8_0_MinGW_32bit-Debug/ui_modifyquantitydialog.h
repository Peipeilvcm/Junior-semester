/********************************************************************************
** Form generated from reading UI file 'modifyquantitydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYQUANTITYDIALOG_H
#define UI_MODIFYQUANTITYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modifyQuantityDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QSpinBox *quantitySpinBox;
    QLabel *label_14;
    QPushButton *modifyConfirmButton;
    QPushButton *returnButton;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *typeLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *oriPriceLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLabel *inventoryLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLabel *rateLabel;
    QHBoxLayout *horizontalLayout_8;
    QLabel *otherLabel;
    QLabel *otherValueLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLabel *descriptionLabel;

    void setupUi(QDialog *modifyQuantityDialog)
    {
        if (modifyQuantityDialog->objectName().isEmpty())
            modifyQuantityDialog->setObjectName(QStringLiteral("modifyQuantityDialog"));
        modifyQuantityDialog->resize(400, 300);
        modifyQuantityDialog->setStyleSheet(QLatin1String("#modifyQuantityDialog{\n"
"border-image:url(:/icon/icon/timg.jpg);\n"
"}\n"
"#modifyQuantityDialog *{\n"
"border-image:url();\n"
"}"));
        layoutWidget = new QWidget(modifyQuantityDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 200, 251, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_7->addWidget(label_13);

        quantitySpinBox = new QSpinBox(layoutWidget);
        quantitySpinBox->setObjectName(QStringLiteral("quantitySpinBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        quantitySpinBox->setFont(font);
        quantitySpinBox->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        quantitySpinBox->setMaximum(10000);

        horizontalLayout_7->addWidget(quantitySpinBox);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_7->addWidget(label_14);

        modifyConfirmButton = new QPushButton(modifyQuantityDialog);
        modifyConfirmButton->setObjectName(QStringLiteral("modifyConfirmButton"));
        modifyConfirmButton->setGeometry(QRect(130, 240, 80, 30));
        modifyConfirmButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        returnButton = new QPushButton(modifyQuantityDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(260, 240, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        layoutWidget_2 = new QWidget(modifyQuantityDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(71, 21, 241, 171));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout->addWidget(label);

        nameLabel = new QLabel(layoutWidget_2);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout->addWidget(nameLabel);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_2->addWidget(label_3);

        typeLabel = new QLabel(layoutWidget_2);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));
        typeLabel->setFont(font);
        typeLabel->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_2->addWidget(typeLabel);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_3->addWidget(label_5);

        oriPriceLabel = new QLabel(layoutWidget_2);
        oriPriceLabel->setObjectName(QStringLiteral("oriPriceLabel"));
        oriPriceLabel->setFont(font);
        oriPriceLabel->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_3->addWidget(oriPriceLabel);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_4->addWidget(label_7);

        inventoryLabel = new QLabel(layoutWidget_2);
        inventoryLabel->setObjectName(QStringLiteral("inventoryLabel"));
        inventoryLabel->setFont(font);
        inventoryLabel->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_4->addWidget(inventoryLabel);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_5->addWidget(label_9);

        rateLabel = new QLabel(layoutWidget_2);
        rateLabel->setObjectName(QStringLiteral("rateLabel"));
        rateLabel->setFont(font);
        rateLabel->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_5->addWidget(rateLabel);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        otherLabel = new QLabel(layoutWidget_2);
        otherLabel->setObjectName(QStringLiteral("otherLabel"));
        otherLabel->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_8->addWidget(otherLabel);

        otherValueLabel = new QLabel(layoutWidget_2);
        otherValueLabel->setObjectName(QStringLiteral("otherValueLabel"));
        otherValueLabel->setFont(font);
        otherValueLabel->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_8->addWidget(otherValueLabel);


        gridLayout->addLayout(horizontalLayout_8, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_6->addWidget(label_11);

        descriptionLabel = new QLabel(layoutWidget_2);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setFont(font);
        descriptionLabel->setStyleSheet(QLatin1String("color: rgb(255, 135, 0);\n"
"background:white;"));

        horizontalLayout_6->addWidget(descriptionLabel);


        gridLayout->addLayout(horizontalLayout_6, 6, 0, 1, 1);


        retranslateUi(modifyQuantityDialog);

        QMetaObject::connectSlotsByName(modifyQuantityDialog);
    } // setupUi

    void retranslateUi(QDialog *modifyQuantityDialog)
    {
        modifyQuantityDialog->setWindowTitle(QApplication::translate("modifyQuantityDialog", "Dialog", Q_NULLPTR));
        label_13->setText(QApplication::translate("modifyQuantityDialog", "\344\277\256\346\224\271\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("modifyQuantityDialog", "\344\273\266", Q_NULLPTR));
        modifyConfirmButton->setText(QApplication::translate("modifyQuantityDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        returnButton->setText(QApplication::translate("modifyQuantityDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("modifyQuantityDialog", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("modifyQuantityDialog", "\345\223\201\347\261\273\357\274\232", Q_NULLPTR));
        typeLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("modifyQuantityDialog", "\345\216\237\344\273\267\357\274\232", Q_NULLPTR));
        oriPriceLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("modifyQuantityDialog", "\345\272\223\345\255\230\351\207\217\357\274\232", Q_NULLPTR));
        inventoryLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
        label_9->setText(QApplication::translate("modifyQuantityDialog", "\346\212\230\346\211\243\347\216\207\357\274\232", Q_NULLPTR));
        rateLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
        otherLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
        otherValueLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
        label_11->setText(QApplication::translate("modifyQuantityDialog", "\347\256\200\344\273\213\357\274\232", Q_NULLPTR));
        descriptionLabel->setText(QApplication::translate("modifyQuantityDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modifyQuantityDialog: public Ui_modifyQuantityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYQUANTITYDIALOG_H
