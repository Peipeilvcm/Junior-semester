#include "modifyuserinfodialog.h"
#include "ui_modifyuserinfodialog.h"

//修改用户信息，密码或昵称
#include <QObject>
#include <QMessageBox>
#include <QSqlQuery>

#include "globalinfo.h"

extern QString userPhoneNum;

modifyUserInfoDialog::modifyUserInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyUserInfoDialog)
{
    ui->setupUi(this);

    QObject::connect(ui->modifyPasswordButton,SIGNAL(clicked(bool)),this,SLOT(modifyPasswordButton_clicked()));
    QObject::connect(ui->returnButton,SIGNAL(clicked(bool)),this,SLOT(returnButton_clicked()));
    QObject::connect(ui->modifyNameButton,SIGNAL(clicked(bool)),this,SLOT(modifyNameButton_clicked()));
}

modifyUserInfoDialog::~modifyUserInfoDialog()
{
    delete ui;
}

//修改密码
void modifyUserInfoDialog::modifyPasswordButton_clicked()
{
    QString userPhoneNum = GlobalInfo::instance()->getUserNum();

    QString oldPassword = ui->oldPasswordLineEdit->text();

    QSqlQuery query;
    query.exec("SELECT * FROM userInfo WHERE phoneNum = '"+userPhoneNum+"'");
    if(query.next())
    {
        if(oldPassword != query.value(2).toString())
        {
            QMessageBox::warning(this,"ModifyError","原密码输入错误");
            return;
        }
    }

    QString newPassword = ui->newPasswordLineEdit->text();
    QString newPassword2 = ui->newPassword2LineEdit->text();

    if(newPassword.isEmpty())
    {
        QMessageBox::warning(this,"ModifyError","新密码不能为空");
        return;
    }
    if(newPassword != newPassword2)
    {
        QMessageBox::warning(this,"ModifyError","新密码两次输入不同");
        return;
    }
    //更新密码
    query.prepare("UPDATE userInfo SET password = ? WHERE phoneNum = '"+userPhoneNum+"'");
    query.bindValue(0,newPassword);
    query.exec();

    QMessageBox::information(this,"ModifyRight","修改成功,请记住新密码:"+newPassword+"");
    close();
}

//修改昵称
void modifyUserInfoDialog::modifyNameButton_clicked()
{
    QString userPhoneNum = GlobalInfo::instance()->getUserNum();

    QString newName = ui->nameLineEdit->text();

    if(newName.isEmpty())
    {
        QMessageBox::warning(this,"ModifyError","昵称不能为空");
        return;
    }

    QSqlQuery query;
    //更新数据库
    query.prepare("UPDATE userInfo SET name = ? WHERE phoneNum = '"+userPhoneNum+"'");
    query.bindValue(0,newName);
    query.exec();

    QMessageBox::information(this,"ModifyRight","修改成功,Hello "+newName);
    ui->nameLineEdit->setText("");
}

void modifyUserInfoDialog::returnButton_clicked()
{
    close();
}
