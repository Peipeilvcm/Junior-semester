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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageDialog
{
public:
    QPushButton *returnButton;
    QTabWidget *manageTabWidget;
    QWidget *goodsManagePage;
    QTableView *GoodsTableView;
    QPushButton *addGoodsButton;
    QPushButton *delGoodsButton;
    QLabel *label_8;
    QWidget *onSaleSetPage;
    QPushButton *discountSetButton;
    QFrame *line;
    QCheckBox *onSaleCheckBox;
    QPushButton *onSaleSetButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *bookRateLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *clothRateLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *foodRateLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *phoneRateLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *fullLineEdit;
    QLabel *label_6;
    QLineEdit *reduceLineEdit;
    QLabel *label_7;

    void setupUi(QDialog *ManageDialog)
    {
        if (ManageDialog->objectName().isEmpty())
            ManageDialog->setObjectName(QStringLiteral("ManageDialog"));
        ManageDialog->resize(780, 560);
        ManageDialog->setStyleSheet(QLatin1String("#ManageDialog{\n"
"border-image:url(:/icon/icon/timg.jpg);\n"
"}\n"
"#ManageDialog *{\n"
"border-image:url();\n"
"}"));
        returnButton = new QPushButton(ManageDialog);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(680, 520, 80, 30));
        returnButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        manageTabWidget = new QTabWidget(ManageDialog);
        manageTabWidget->setObjectName(QStringLiteral("manageTabWidget"));
        manageTabWidget->setGeometry(QRect(10, 10, 760, 490));
        manageTabWidget->setStyleSheet(QStringLiteral("background:white;"));
        goodsManagePage = new QWidget();
        goodsManagePage->setObjectName(QStringLiteral("goodsManagePage"));
        GoodsTableView = new QTableView(goodsManagePage);
        GoodsTableView->setObjectName(QStringLiteral("GoodsTableView"));
        GoodsTableView->setGeometry(QRect(10, 10, 740, 411));
        GoodsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        addGoodsButton = new QPushButton(goodsManagePage);
        addGoodsButton->setObjectName(QStringLiteral("addGoodsButton"));
        addGoodsButton->setGeometry(QRect(30, 430, 111, 30));
        addGoodsButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        delGoodsButton = new QPushButton(goodsManagePage);
        delGoodsButton->setObjectName(QStringLiteral("delGoodsButton"));
        delGoodsButton->setGeometry(QRect(160, 430, 111, 30));
        delGoodsButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_8 = new QLabel(goodsManagePage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(540, 430, 211, 21));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color:rgb(255,135,0);"));
        manageTabWidget->addTab(goodsManagePage, QString());
        onSaleSetPage = new QWidget();
        onSaleSetPage->setObjectName(QStringLiteral("onSaleSetPage"));
        discountSetButton = new QPushButton(onSaleSetPage);
        discountSetButton->setObjectName(QStringLiteral("discountSetButton"));
        discountSetButton->setGeometry(QRect(109, 270, 91, 30));
        discountSetButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        line = new QFrame(onSaleSetPage);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(360, 10, 20, 451));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        onSaleCheckBox = new QCheckBox(onSaleSetPage);
        onSaleCheckBox->setObjectName(QStringLiteral("onSaleCheckBox"));
        onSaleCheckBox->setGeometry(QRect(420, 130, 101, 31));
        onSaleCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        onSaleSetButton = new QPushButton(onSaleSetPage);
        onSaleSetButton->setObjectName(QStringLiteral("onSaleSetButton"));
        onSaleSetButton->setGeometry(QRect(499, 270, 91, 30));
        onSaleSetButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        layoutWidget = new QWidget(onSaleSetPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 90, 141, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout->addWidget(label);

        bookRateLineEdit = new QLineEdit(layoutWidget);
        bookRateLineEdit->setObjectName(QStringLiteral("bookRateLineEdit"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        bookRateLineEdit->setFont(font1);
        bookRateLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout->addWidget(bookRateLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_2->addWidget(label_2);

        clothRateLineEdit = new QLineEdit(layoutWidget);
        clothRateLineEdit->setObjectName(QStringLiteral("clothRateLineEdit"));
        clothRateLineEdit->setFont(font1);
        clothRateLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_2->addWidget(clothRateLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_3->addWidget(label_3);

        foodRateLineEdit = new QLineEdit(layoutWidget);
        foodRateLineEdit->setObjectName(QStringLiteral("foodRateLineEdit"));
        foodRateLineEdit->setFont(font1);
        foodRateLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_3->addWidget(foodRateLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_4->addWidget(label_4);

        phoneRateLineEdit = new QLineEdit(layoutWidget);
        phoneRateLineEdit->setObjectName(QStringLiteral("phoneRateLineEdit"));
        phoneRateLineEdit->setFont(font1);
        phoneRateLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_4->addWidget(phoneRateLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(onSaleSetPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(420, 170, 281, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_5->addWidget(label_5);

        fullLineEdit = new QLineEdit(layoutWidget1);
        fullLineEdit->setObjectName(QStringLiteral("fullLineEdit"));
        fullLineEdit->setFont(font1);
        fullLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_5->addWidget(fullLineEdit);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_5->addWidget(label_6);

        reduceLineEdit = new QLineEdit(layoutWidget1);
        reduceLineEdit->setObjectName(QStringLiteral("reduceLineEdit"));
        reduceLineEdit->setFont(font1);
        reduceLineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_5->addWidget(reduceLineEdit);

        label_7 = new QLabel(onSaleSetPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 1, 761, 471));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/timg.jpg")));
        manageTabWidget->addTab(onSaleSetPage, QString());
        label_7->raise();
        discountSetButton->raise();
        line->raise();
        onSaleCheckBox->raise();
        onSaleSetButton->raise();
        layoutWidget->raise();
        layoutWidget1->raise();

        retranslateUi(ManageDialog);

        manageTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ManageDialog);
    } // setupUi

    void retranslateUi(QDialog *ManageDialog)
    {
        ManageDialog->setWindowTitle(QApplication::translate("ManageDialog", "Dialog", Q_NULLPTR));
        returnButton->setText(QApplication::translate("ManageDialog", "\345\217\226\346\266\210/\350\277\224\345\233\236", Q_NULLPTR));
        addGoodsButton->setText(QApplication::translate("ManageDialog", "\346\226\260\346\267\273\345\225\206\345\223\201", Q_NULLPTR));
        delGoodsButton->setText(QApplication::translate("ManageDialog", "\345\210\240\351\231\244", Q_NULLPTR));
        label_8->setText(QApplication::translate("ManageDialog", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257\357\274\214\345\234\250\350\241\250\346\240\274\344\270\255\347\202\271\345\207\273\347\274\226\350\276\221\345\215\263\345\217\257", Q_NULLPTR));
        manageTabWidget->setTabText(manageTabWidget->indexOf(goodsManagePage), QApplication::translate("ManageDialog", "\345\225\206\345\223\201\347\256\241\347\220\206", Q_NULLPTR));
        discountSetButton->setText(QApplication::translate("ManageDialog", "\346\212\230\346\211\243\347\212\266\346\200\201\344\277\256\346\224\271", Q_NULLPTR));
        onSaleCheckBox->setText(QApplication::translate("ManageDialog", "\346\273\241\345\207\217\346\264\273\345\212\250\345\274\200\345\247\213", Q_NULLPTR));
        onSaleSetButton->setText(QApplication::translate("ManageDialog", "\346\273\241\345\207\217\347\212\266\346\200\201\344\277\256\346\224\271", Q_NULLPTR));
        label->setText(QApplication::translate("ManageDialog", "\345\233\276\344\271\246\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ManageDialog", "\346\234\215\350\243\205\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ManageDialog", "\351\243\237\345\223\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ManageDialog", "\346\211\213\346\234\272\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ManageDialog", "\345\205\250\345\234\272\346\273\241", Q_NULLPTR));
        label_6->setText(QApplication::translate("ManageDialog", "\345\207\217", Q_NULLPTR));
        label_7->setText(QString());
        manageTabWidget->setTabText(manageTabWidget->indexOf(onSaleSetPage), QApplication::translate("ManageDialog", "\346\212\230\346\211\243\344\270\216\346\273\241\345\207\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManageDialog: public Ui_ManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEDIALOG_H
