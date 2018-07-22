#include "registerdialog.h"
#include "ui_registerdialog.h"

//注册界面
#include<QObject>
#include <QMessageBox>
#include <QSqlQuery>
#include<QRegExp>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);

    QRegExp regExpNum("[0-9]{11}");
    ui->phoneNumLineEdit->setValidator(new QRegExpValidator(regExpNum,this));

    QObject::connect(ui->registerButton,SIGNAL(clicked()),this,SLOT(registerButton_clicked()));
    QObject::connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(returnButton_clicked()));

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}


//注册键
void RegisterDialog::registerButton_clicked()
{
    QString phoneNumTemp = ui->phoneNumLineEdit->text();
    QString passwordTemp = ui->passwordLineEdit->text();
    QString passwordConfirmTemp = ui->passwordconfirmLineEdit->text();
    QString nameTemp = ui->nameLineEdit->text();

    if(phoneNumTemp.isEmpty()||passwordTemp.isEmpty()
     ||passwordConfirmTemp.isEmpty()||nameTemp.isEmpty())
    {
        QMessageBox::warning(this, "RegisterError","信息填写不完整", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    if(phoneNumTemp.length()!=phoneNumLen)
    {
        QMessageBox::warning(this, "RegisterError","电话应为11位长", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    for(int i = 0;i<phoneNumLen;++i)
    {
        if(phoneNumTemp.at(i)>'9'||phoneNumTemp.at(i)<'0')
        {
            QMessageBox::warning(this, "RegisterError","电话填写无效", QMessageBox::Yes | QMessageBox::Yes);
            return;
        }
    }
    //检查该手机号是否已经注册
    QSqlQuery query;
    query.exec("SELECT * From userInfo WHERE phoneNum = '"+phoneNumTemp+"'");
    if(query.next())
    {
        QMessageBox::warning(this, "RegisterError","电话已经被注册", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    if(passwordTemp!=passwordConfirmTemp)
    {
        QMessageBox::warning(this, "RegisterError","两次密码输入不匹配", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    query.prepare("INSERT INTO userInfo ( phoneNum, name, password)"
                  "VALUES ( ?, ?, ? )");
    query.bindValue(0,phoneNumTemp);
    query.bindValue(1,nameTemp);
    query.bindValue(2,passwordTemp);
    query.exec();

    QMessageBox::information(NULL,"RegisterInfo","注册成功,可以登录",QMessageBox::Yes | QMessageBox::Yes);

    /*
    query.exec("CREATE TABLE cart"+phoneNumTemp+" ("
               "id INT PRIMARY KEY,"
               "name VARCHAR,"
               "type VARCHAR,"
               "oriPrice REAL,"
               "price REAL,"
               "quantity INT)");*/
    /*
    query.exec("CREATE TABLE card"+phoneNumTemp+" ("
               "accountNum VARCHAR PRIMARY KEY )");
               */

    close();
}

void RegisterDialog::returnButton_clicked()
{
    close();
}
