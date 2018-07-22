#include "depositdialog.h"
#include "ui_depositdialog.h"

#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtSql>
#include"main.h"
#include"account.h"
#include<QRegExp>

//存款小界面
extern account * accountPtr;                   //当前账户信息

//账户存钱窗口构造函数
DepositDialog::DepositDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositDialog)
{
    ui->setupUi(this);
    setMaximumSize(280,100);                   //固定窗口大小
    setMinimumSize(280,100);

    //设置存钱输入框，正则表达式，只能输入浮点数，其它错误输入不被允许
    ui->depositLineEdit->setValidator(new QDoubleValidator(0.0,10000.0,2,this));

    //捕获确认存款按钮点击事件
    QObject::connect(ui->depositButton,SIGNAL(clicked(bool)),this,SLOT(depositButton_clicked()));
    //捕获取消按钮点击事件
    QObject::connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(cancelButton_clicked()));
}

DepositDialog::~DepositDialog()
{
    delete ui;
}

//存钱按钮点击，执行存钱操作
void DepositDialog::depositButton_clicked()
{
    //输入错误处理
    if(ui->depositLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "DepositError","请输入金额", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    if(ui->depositLineEdit->text().length()>10)         //长度大于10
    {
        QMessageBox::warning(this, "DepositError","非法输入", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    //存钱操作
    balanceType money = ui->depositLineEdit->text().toFloat();
    bool flag=accountPtr->deposit(money);
    ui->depositLineEdit->clear();
    if(flag)
    {//存款成功
        QMessageBox::information(this, "Deposit","存款成功", QMessageBox::Yes | QMessageBox::Yes);
        //更新数据库
        QSqlQuery query;
        query.exec("UPDATE accountInfo SET balance = "+QString ::number(accountPtr->getBalance(),'f',2)+" WHERE num = '"+accountPtr->getNum()+"'");
        close();
    }
    else    //超过最大金额，存款失败
    {
        QMessageBox::warning(this, "DepositError","超过最大金额", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

}

//取消按钮点击，存取对话框
void DepositDialog::cancelButton_clicked()
{
    close();
}

