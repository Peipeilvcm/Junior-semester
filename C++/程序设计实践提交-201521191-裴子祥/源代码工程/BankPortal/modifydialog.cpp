#include "modifydialog.h"
#include "ui_modifydialog.h"

//修改密码界面
#include<QObject>
#include<QMessageBox>
#include<QSqlQuery>
#include"account.h"
#include"registerdialog.h"
#include<QRegExp>

extern account *accountPtr;                 //当前账户信息

//修改密码对话框构造函数
ModifyDialog::ModifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyDialog)
{
    ui->setupUi(this);
    setMaximumSize(400,300);                //固定界面大小
    setMinimumSize(400,300);

    //设置界面tab切换顺序
    setTabOrder(ui->oldpasswordLineEdit,ui->newPasswordLineEdit);
    setTabOrder(ui->newPasswordLineEdit,ui->newPassword2LineEdit);
    setTabOrder(ui->newPassword2LineEdit,ui->oldpasswordLineEdit);

    QRegExp regExpPW("[0-9]{6}");           //输入密码框正则表达式，只能输入6位数字，其它错误输入不被允许
    ui->oldpasswordLineEdit->setValidator(new QRegExpValidator(regExpPW,this));
    ui->newPasswordLineEdit->setValidator(new QRegExpValidator(regExpPW,this));
    ui->newPassword2LineEdit->setValidator(new QRegExpValidator(regExpPW,this));


    //捕获确认修改按钮点击事件
    QObject::connect(ui->confirmButton,SIGNAL(clicked(bool)),this,SLOT(confirmButton_clicked()));
    //捕获取消按钮点击事件
    QObject::connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(cancelButton_clicked()));
}

ModifyDialog::~ModifyDialog()
{
    delete ui;
}

//确认修改按钮点击，执行修改密码操作
void ModifyDialog::confirmButton_clicked()
{
    QString oldPassword = ui->oldpasswordLineEdit->text();      //获取输入的原密码
    if(oldPassword!=accountPtr->getPassword())
    {
        QMessageBox::warning(this,"ModifyError","原密码输入错误");
        return;
    }

    QString newPassword1 = ui->newPasswordLineEdit->text();     //获取输入的新密码
    QString newPassword2 = ui->newPassword2LineEdit->text();    //获取输入的新密码的确认

    //错误处理
    if(newPassword1.isEmpty())
    {
        QMessageBox::warning(this,"ModifyError","新密码不能为空");
        return;
    }
    if(newPassword1.length()<RegisterDialog::passwordLength)
    {
        QMessageBox::warning(this,"ModifyError","新密码应为6位");
        return;
    }
    if(newPassword1 != newPassword2)
    {
        QMessageBox::warning(this,"ModifyError","新密码两次输入不同");
        return;
    }

    accountPtr->setPassword(newPassword1);                      //修改密码设置
    //更新数据库
    QSqlQuery query;                                            //更新数据库
    query.exec("UPDATE accountInfo SET password = "+accountPtr->getPassword()+" WHERE num = '"+accountPtr->getNum()+"'");
    QMessageBox::information(this,"ModifyRight","修改成功,请记住新密码:"+accountPtr->getPassword()+"");
    close();

}

//退出此界面
void ModifyDialog::cancelButton_clicked()
{
    close();
}
