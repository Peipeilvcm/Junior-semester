#include "logindialog.h"
#include "ui_logindialog.h"

#include<QObject>
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>
#include "book.h"
#include "cloth.h"
#include "food.h"
#include "phone.h"
#include <QRegExp>

#include "globalinfo.h"

//登录界面

//登入界面构造函数
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    QRegExp regExpNum("[0-9]{11}");             //用户账号(电话号),只能输入11位数字，其余错误输入不被允许
    ui->phoneNumLineEdit->setValidator(new QRegExpValidator(regExpNum,this));

    //捕获注册按钮点击事件
    QObject::connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(loginButton_clicked()));
    //捕获返回按钮点击事件
    QObject::connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(returnButton_clicked()));

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::loginButton_clicked()
{
    //账号、密码检查
    QString phoneNum = ui->phoneNumLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    if(phoneNum.isEmpty()||password.isEmpty())
    {
        QMessageBox::warning(this, "LoginError","信息填写不能为空", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    QSqlQuery query;
    query.exec("SELECT * FROM userInfo WHERE phoneNum = '"+phoneNum+"'");
    if(query.next())
    {
        if(query.value(2)==password)                 //密码与账户匹配
        {//登录成功
            query.clear();

            GlobalInfo::instance()->setIsLogin(true);           //更改当前登入信息
            GlobalInfo::instance()->setUserNum(phoneNum);       //设置全局账号为当前账号

            //从数据库中读取全局满减信息
            query.exec("SELECT * FROM onSaleInfo WHERE label = FullThenReduce");
            if(query.next())
            {
                if(query.value(1)=="YES")                       //满减信息是否开始
                {
                    GlobalInfo::instance()->setIsFRstart(true); //
                }
                else
                {
                    GlobalInfo::instance()->setIsFRstart(false);
                }
                GlobalInfo::instance()->setFull(query.value(2).toInt());
                GlobalInfo::instance()->setReduce(query.value(3).toInt());
                query.clear();
            }

            QMessageBox::information(this, "LoginInfo","登陆成功", QMessageBox::Yes | QMessageBox::Yes);
            close();
        }
        else
        {
            QMessageBox::warning(this, "LoginError","密码错误", QMessageBox::Yes | QMessageBox::Yes);
            return;
        }

    }
    else
    {
        QMessageBox::warning(this, "LoginError","该手机号未注册", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }


}

void LoginDialog::returnButton_clicked()
{
    close();
}
