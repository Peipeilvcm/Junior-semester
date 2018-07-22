#include "withdrawdialog.h"
#include "ui_withdrawdialog.h"

#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtSql>
#include<QObject>
#include"main.h"
#include"account.h"
#include<QRegExp>

//取款小界面

extern account * accountPtr;                   //当前账户信息

//账户取钱窗口构造函数
WithdrawDialog::WithdrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawDialog)
{
    ui->setupUi(this);
    setMaximumSize(280,100);                   //固定窗口大小
    setMinimumSize(280,100);

    //设置取钱输入框，正则表达式，只能输入浮点数，其它错误输入不被允许
    ui->withdrawLineEdit->setValidator(new QDoubleValidator(0.0,5000.0,2,this));

    //捕获确认取款按钮点击事件
    QObject::connect(ui->withdrawButton,SIGNAL(clicked()),this,SLOT(withdrawButton_clicked()));
    //捕获取消按钮点击事件
    QObject::connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancelButton_clicked()));
}

WithdrawDialog::~WithdrawDialog()
{
    delete ui;
}

//取钱按钮点击，执行取钱操作
void WithdrawDialog::withdrawButton_clicked()
{
    //输入错误处理
    if(ui->withdrawLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "WithdrawError","请填写金额。", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    if(ui->withdrawLineEdit->text().length()>10)
    {
        QMessageBox::warning(this, "WithdrawError","非法输入", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    balanceType money = ui->withdrawLineEdit->text().toFloat();
    ui->withdrawLineEdit->clear();
    if(accountPtr->withdraw(money))//取款成功
    {
        QMessageBox::information(this, "WithDraw","取款成功。", QMessageBox::Yes | QMessageBox::Yes);
        //更新数据库
        QSqlQuery query;
        query.exec("UPDATE accountInfo SET balance = "+QString ::number(accountPtr->getBalance(),'f',2)+" WHERE num = '"+accountPtr->getNum()+"'");
        close();
    }
    else
    {
        QMessageBox::warning(this, "WithdrawError","您的余额不足", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

}

void WithdrawDialog::cancelButton_clicked()
{
    close();
}
