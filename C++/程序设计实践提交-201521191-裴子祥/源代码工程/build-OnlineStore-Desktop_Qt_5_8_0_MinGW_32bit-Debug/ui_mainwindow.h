/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *storeTabWidget;
    QWidget *storePage;
    QTableView *GoodsTableView;
    QPushButton *addToCartButton;
    QComboBox *typeShowComboBox;
    QLineEdit *searchByNameLineEdit;
    QComboBox *sortComboBox;
    QPushButton *searchButton;
    QWidget *cartPage;
    QTableView *CartTableView;
    QPushButton *submitButton;
    QPushButton *deleteButton;
    QPushButton *modifyQuantityButton;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLabel *priceSumLabel;
    QLabel *label_9;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLabel *fullThenReduceLabel;
    QLabel *label_12;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QLabel *paySumLabel;
    QLabel *label_15;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *oriPriceSumLabel;
    QLabel *label_6;
    QWidget *userInfoPage;
    QLabel *label_3;
    QTableView *bankAccountTableView;
    QPushButton *accountMagButton;
    QPushButton *modifyUserInfoButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *phoneLabel;
    QPushButton *disBindingButton;
    QLabel *label_5;
    QPushButton *manageEntryButton;
    QPushButton *loginEntryButton;
    QPushButton *registerEntryButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(780, 560);
        MainWindow->setStyleSheet(QLatin1String("#MainWindow{\n"
"border-image:url(:/icon/icon/timg.jpg);\n"
"}\n"
"#MainWindow *{\n"
"border-image:url();\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background:transparent;"));
        storeTabWidget = new QTabWidget(centralWidget);
        storeTabWidget->setObjectName(QStringLiteral("storeTabWidget"));
        storeTabWidget->setGeometry(QRect(10, 20, 760, 491));
        storeTabWidget->setStyleSheet(QStringLiteral(""));
        storeTabWidget->setTabPosition(QTabWidget::North);
        storeTabWidget->setTabShape(QTabWidget::Rounded);
        storeTabWidget->setElideMode(Qt::ElideNone);
        storeTabWidget->setDocumentMode(false);
        storeTabWidget->setTabsClosable(false);
        storeTabWidget->setMovable(false);
        storeTabWidget->setTabBarAutoHide(false);
        storePage = new QWidget();
        storePage->setObjectName(QStringLiteral("storePage"));
        storePage->setStyleSheet(QStringLiteral(""));
        GoodsTableView = new QTableView(storePage);
        GoodsTableView->setObjectName(QStringLiteral("GoodsTableView"));
        GoodsTableView->setGeometry(QRect(10, 50, 740, 371));
        GoodsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        addToCartButton = new QPushButton(storePage);
        addToCartButton->setObjectName(QStringLiteral("addToCartButton"));
        addToCartButton->setGeometry(QRect(290, 430, 191, 30));
        addToCartButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        typeShowComboBox = new QComboBox(storePage);
        typeShowComboBox->setObjectName(QStringLiteral("typeShowComboBox"));
        typeShowComboBox->setGeometry(QRect(10, 10, 101, 31));
        typeShowComboBox->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        searchByNameLineEdit = new QLineEdit(storePage);
        searchByNameLineEdit->setObjectName(QStringLiteral("searchByNameLineEdit"));
        searchByNameLineEdit->setGeometry(QRect(280, 10, 181, 31));
        searchByNameLineEdit->setStyleSheet(QStringLiteral("color: rgb(255,135,0);"));
        sortComboBox = new QComboBox(storePage);
        sortComboBox->setObjectName(QStringLiteral("sortComboBox"));
        sortComboBox->setGeometry(QRect(130, 10, 101, 31));
        sortComboBox->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        searchButton = new QPushButton(storePage);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(470, 10, 75, 31));
        searchButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        storeTabWidget->addTab(storePage, QString());
        cartPage = new QWidget();
        cartPage->setObjectName(QStringLiteral("cartPage"));
        CartTableView = new QTableView(cartPage);
        CartTableView->setObjectName(QStringLiteral("CartTableView"));
        CartTableView->setGeometry(QRect(10, 10, 740, 351));
        CartTableView->setSelectionMode(QAbstractItemView::MultiSelection);
        CartTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        submitButton = new QPushButton(cartPage);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(660, 420, 80, 30));
        submitButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        deleteButton = new QPushButton(cartPage);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(550, 420, 80, 30));
        deleteButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        modifyQuantityButton = new QPushButton(cartPage);
        modifyQuantityButton->setObjectName(QStringLiteral("modifyQuantityButton"));
        modifyQuantityButton->setGeometry(QRect(440, 420, 80, 30));
        modifyQuantityButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        layoutWidget_2 = new QWidget(cartPage);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(190, 370, 140, 14));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        priceSumLabel = new QLabel(layoutWidget_2);
        priceSumLabel->setObjectName(QStringLiteral("priceSumLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        priceSumLabel->setFont(font);
        priceSumLabel->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_4->addWidget(priceSumLabel);

        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        layoutWidget_3 = new QWidget(cartPage);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(350, 370, 140, 14));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);

        fullThenReduceLabel = new QLabel(layoutWidget_3);
        fullThenReduceLabel->setObjectName(QStringLiteral("fullThenReduceLabel"));
        fullThenReduceLabel->setFont(font);
        fullThenReduceLabel->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_5->addWidget(fullThenReduceLabel);

        label_12 = new QLabel(layoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_5->addWidget(label_12);

        layoutWidget_4 = new QWidget(cartPage);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(510, 370, 163, 14));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        paySumLabel = new QLabel(layoutWidget_4);
        paySumLabel->setObjectName(QStringLiteral("paySumLabel"));
        paySumLabel->setFont(font);
        paySumLabel->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_6->addWidget(paySumLabel);

        label_15 = new QLabel(layoutWidget_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_6->addWidget(label_15);

        layoutWidget = new QWidget(cartPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 370, 151, 14));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        oriPriceSumLabel = new QLabel(layoutWidget);
        oriPriceSumLabel->setObjectName(QStringLiteral("oriPriceSumLabel"));
        oriPriceSumLabel->setFont(font);
        oriPriceSumLabel->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_3->addWidget(oriPriceSumLabel);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        storeTabWidget->addTab(cartPage, QString());
        userInfoPage = new QWidget();
        userInfoPage->setObjectName(QStringLiteral("userInfoPage"));
        userInfoPage->setStyleSheet(QStringLiteral("background:transparent;"));
        label_3 = new QLabel(userInfoPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 170, 71, 21));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));
        bankAccountTableView = new QTableView(userInfoPage);
        bankAccountTableView->setObjectName(QStringLiteral("bankAccountTableView"));
        bankAccountTableView->setGeometry(QRect(80, 200, 320, 180));
        accountMagButton = new QPushButton(userInfoPage);
        accountMagButton->setObjectName(QStringLiteral("accountMagButton"));
        accountMagButton->setGeometry(QRect(420, 200, 80, 30));
        accountMagButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        modifyUserInfoButton = new QPushButton(userInfoPage);
        modifyUserInfoButton->setObjectName(QStringLiteral("modifyUserInfoButton"));
        modifyUserInfoButton->setGeometry(QRect(250, 80, 80, 41));
        modifyUserInfoButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        layoutWidget1 = new QWidget(userInfoPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 80, 141, 81));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout->addWidget(label);

        nameLabel = new QLabel(layoutWidget1);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout->addWidget(nameLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_2->addWidget(label_2);

        phoneLabel = new QLabel(layoutWidget1);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        phoneLabel->setFont(font);
        phoneLabel->setStyleSheet(QStringLiteral("color: rgb(255, 135, 0);"));

        horizontalLayout_2->addWidget(phoneLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        disBindingButton = new QPushButton(userInfoPage);
        disBindingButton->setObjectName(QStringLiteral("disBindingButton"));
        disBindingButton->setGeometry(QRect(420, 240, 80, 30));
        disBindingButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        label_5 = new QLabel(userInfoPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(410, 20, 331, 421));
        label_5->setStyleSheet(QStringLiteral("border-image:url(:/icon/icon/kobe.jpg);"));
        storeTabWidget->addTab(userInfoPage, QString());
        label_5->raise();
        label_3->raise();
        bankAccountTableView->raise();
        accountMagButton->raise();
        modifyUserInfoButton->raise();
        layoutWidget1->raise();
        disBindingButton->raise();
        manageEntryButton = new QPushButton(centralWidget);
        manageEntryButton->setObjectName(QStringLiteral("manageEntryButton"));
        manageEntryButton->setGeometry(QRect(680, 10, 80, 30));
        manageEntryButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        loginEntryButton = new QPushButton(centralWidget);
        loginEntryButton->setObjectName(QStringLiteral("loginEntryButton"));
        loginEntryButton->setGeometry(QRect(500, 10, 80, 30));
        loginEntryButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        registerEntryButton = new QPushButton(centralWidget);
        registerEntryButton->setObjectName(QStringLiteral("registerEntryButton"));
        registerEntryButton->setGeometry(QRect(590, 10, 80, 30));
        registerEntryButton->setStyleSheet(QLatin1String("color: white;\n"
"background-color: rgb(255, 135, 0);\n"
"border-style: outset;\n"
"padding: 6px;\n"
"border-radius: 10px;"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        storeTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        addToCartButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\207\263\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
        typeShowComboBox->clear();
        typeShowComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\211\200\346\234\211\345\223\201\347\261\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "BOOK", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CLOTH", Q_NULLPTR)
         << QApplication::translate("MainWindow", "FOOD", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PHONE", Q_NULLPTR)
        );
        sortComboBox->clear();
        sortComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\273\230\350\256\244\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\273\267\346\240\274\344\273\216\344\275\216\350\207\263\351\253\230", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\273\267\346\240\274\344\273\216\351\253\230\350\207\263\344\275\216", Q_NULLPTR)
        );
        searchButton->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        storeTabWidget->setTabText(storeTabWidget->indexOf(storePage), QApplication::translate("MainWindow", "\345\225\206\345\237\216", Q_NULLPTR));
        submitButton->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244\350\256\242\345\215\225", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        modifyQuantityButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\346\225\260\351\207\217", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\212\230\345\220\216\357\274\232", Q_NULLPTR));
        priceSumLabel->setText(QApplication::translate("MainWindow", "XXXXXXXXXXX", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\345\205\203", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\346\273\241\345\207\217\357\274\232", Q_NULLPTR));
        fullThenReduceLabel->setText(QApplication::translate("MainWindow", "XXXXXXXXXXX", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\345\205\203", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\256\236\351\231\205\345\272\224\344\273\230\357\274\232", Q_NULLPTR));
        paySumLabel->setText(QApplication::translate("MainWindow", "XXXXXXXXXXX", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\345\205\203", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\200\273\345\216\237\344\273\267\357\274\232", Q_NULLPTR));
        oriPriceSumLabel->setText(QApplication::translate("MainWindow", "XXXXXXXXXXX", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\205\203", Q_NULLPTR));
        storeTabWidget->setTabText(storeTabWidget->indexOf(cartPage), QApplication::translate("MainWindow", "\346\210\221\347\232\204\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\351\223\266\350\241\214\345\215\241\357\274\232", Q_NULLPTR));
        accountMagButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\223\266\350\241\214\345\215\241", Q_NULLPTR));
        modifyUserInfoButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\230\265\347\247\260\357\274\232", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        phoneLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        disBindingButton->setText(QApplication::translate("MainWindow", "\350\247\243\347\273\221\351\223\266\350\241\214\345\215\241", Q_NULLPTR));
        label_5->setText(QString());
        storeTabWidget->setTabText(storeTabWidget->indexOf(userInfoPage), QApplication::translate("MainWindow", "\346\210\221\347\232\204\344\277\241\346\201\257", Q_NULLPTR));
        manageEntryButton->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\345\205\245\345\217\243", Q_NULLPTR));
        loginEntryButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        registerEntryButton->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
