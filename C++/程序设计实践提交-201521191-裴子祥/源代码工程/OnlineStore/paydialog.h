#ifndef PAYDIALOG_H
#define PAYDIALOG_H

#include <QDialog>

#include "book.h"
#include "cloth.h"
#include "food.h"
#include "phone.h"
#include "product.h"

namespace Ui {
class PayDialog;
}
//支付窗口类
class PayDialog : public QDialog
{
    Q_OBJECT
private:
    QVector<Product *> productList;         //待付款商品指针容器，能够存储所有品类商品指针
    QVector<int> quantities;                //待付款商品数量容器，记录商品购买数量

public:
    explicit PayDialog(QWidget *parent = 0,QVector<Product *> productItems = QVector<Product *>(),QVector<int> quant = QVector<int>());
    ~PayDialog();

    static const int SUCCESS = 1;           //支付成功
    static const int NOSEVER = 2;           //为找到服务器
    static const int DISCONNECT = 3;        //失去连接
    static const int WRONGNUM = 4;          //卡号错误
    static const int WRONGPW = 5;           //密码错误
    static const int LACKMONEY = 6;         //余额不足

private:
    Ui::PayDialog *ui;

    void productItemShow();                 //待支付物品全部信息展示
    static int askBank(QString sendStr);    //向银行发送连接请求，并传递支付信息

private slots:
    void payConfirmButton_clicked();        //确认支付按钮被按下
    void returnButton_clicked();            //取消支付
};

#endif // PAYDIALOG_H
