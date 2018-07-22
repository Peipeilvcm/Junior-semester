#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlTableModel *modelCart;
    QSqlTableModel *modelAccount;
    void goodsInfoShow();
    void updateUserInfo();
    void updateGoodsInfo();
    void updateCartInfo();
    void updateAccountInfo();
    void calPayLabelShow();//计算购物车内的物品总值

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createConnect(bool isExist);

private:
    Ui::MainWindow *ui;

private slots:
    void loginEntryButton_clicked();
    void registerEntryButton_clicked();
    void manageEntryButton_clicked();

    void addToCartButton_clicked();
    void modifyQuantityButton_clicked();
    void deleteButton_clicked();
    void submitButton_clicked();
    void modifyUserInfoButton_clicked();
    void accountMagButton_clicked();
    void disBindingButton_clicked();

    void typeShowCombox_select();
    void sortCombox_select();

    void searchButton_clicked();

    //void paySignalGet(bool isPay);

};

#endif // MAINWINDOW_H
