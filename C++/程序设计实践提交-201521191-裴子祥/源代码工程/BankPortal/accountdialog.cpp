#include "accountdialog.h"
#include "ui_accountdialog.h"

//登入成功，信息界面
#include<QObject>
#include<QString>
#include "account.h"
#include "withdrawdialog.h"
#include "depositdialog.h"
#include "modifydialog.h"

extern account *accountPtr;                     //当前账户信息

//账号主界面构造函数
AccountDialog::AccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountDialog)
{
    ui->setupUi(this);

    //在对话框中显示当前账户基本信息
    accountInfoShow();

    //捕获取款按钮点击事件
    QObject::connect(ui->witdrawEntryButton,SIGNAL(clicked()),this,SLOT(withdrawEntryButton_clicked()));
    //捕获存款按钮点击事件
    QObject::connect(ui->depositEntryButton,SIGNAL(clicked()),this,SLOT(depositEntryButton_clicked()));
    //捕获设置按钮点击事件
    QObject::connect(ui->setButton,SIGNAL(clicked()),this,SLOT(setButton_clicked()));
    //捕获注销按钮点击事件
    QObject::connect(ui->logoutButton,SIGNAL(clicked()),this,SLOT(logoutButton_clicked()));

}

AccountDialog::~AccountDialog()
{
    delete ui;
}

//贴出银行卡账户信息
void AccountDialog::accountInfoShow()
{
    ui->accountNumLabel->setText(accountPtr->getNum());                         //贴出账户号码
    ui->balanceLabel->setText(QString::number(accountPtr->getBalance()));       //贴出余额
    ui->bankNameLabel->setText(accountPtr->getBankName());                      //贴出银行名称
    ui->phoneNumLabel->setText(accountPtr->getPhoneNum());                      //贴出手机号
    ui->idcreditLabel->setText(accountPtr->getIDcredit());                      //贴出身份证号
}

//更新余额显示
void AccountDialog::updateInfo()
{
    ui->balanceLabel->setText(QString::number(accountPtr->getBalance()));
}

//取钱按钮点击，弹出取钱对话框
void AccountDialog::withdrawEntryButton_clicked()
{
    WithdrawDialog *withdrawDialogPtr = new WithdrawDialog(this);
    withdrawDialogPtr->exec();
    updateInfo();
}

//存钱按钮点击，弹出存钱对话框
void AccountDialog::depositEntryButton_clicked()
{
    DepositDialog *depositDialogPtr = new DepositDialog(this);
    depositDialogPtr->exec();
    updateInfo();
}

//设置按钮点击，弹出设置对话框
void AccountDialog::setButton_clicked()
{
    ModifyDialog *modifyDialogPtr = new ModifyDialog(this);
    modifyDialogPtr->exec();
}

//注销按钮点击，退出登录
void AccountDialog::logoutButton_clicked()
{
    //释放accountPtr内存
    delete accountPtr;
    accountPtr = NULL;
    close();
}

//捕获到支付成功信号，更改余额显示
void AccountDialog::getSignal()
{
    ui->balanceLabel->setText(QString::number(accountPtr->getBalance()));
}
