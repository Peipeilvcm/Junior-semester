#include "registerdialog.h"
#include "ui_registerdialog.h"

#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtSql>
#include<QDebug>
#include<QtGui>
#include"account.h"
#include"main.h"

#include<QRegExp>

//注册界面

extern account *accountPtr;                     //当前账户信息

//注册窗口构造函数
RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setMaximumSize(400,300);                    //固定界面大小
    setMinimumSize(400,300);

    //设置tab切换顺序
    setTabOrder(ui->acoountLineEdit,ui->banknameComboBox);
    setTabOrder(ui->banknameComboBox,ui->passwordLineEdit);
    setTabOrder(ui->passwordLineEdit,ui->passwordconfirmLineEdit);
    setTabOrder(ui->passwordconfirmLineEdit,ui->idcreditLineEdit);
    setTabOrder(ui->idcreditLineEdit,ui->phoneLineEdit);
    setTabOrder(ui->phoneLineEdit,ui->acoountLineEdit);

    //正则表达式，规范输入
    QRegExp regExpNum("[0-9]{19}");             //注册账户号，只能输入19位数字
    QRegExp regExpID("[0-9]{17}[0-9xX]");       //注册身份证号,只能输入18位，前17位为数字，最后一位可以是X
    QRegExp regExpPhoneNum("[0-9]{11}");        //注册电话号码,只能输入11位数字
    QRegExp regExpPW("[0-9]{6}");               //账户密码，只能输入6位数字
    ui->acoountLineEdit->setValidator(new QRegExpValidator(regExpNum,this));
    ui->idcreditLineEdit->setValidator(new QRegExpValidator(regExpID,this));
    ui->phoneLineEdit->setValidator(new QRegExpValidator(regExpPhoneNum,this));
    ui->passwordLineEdit->setValidator(new QRegExpValidator(regExpPW,this));
    ui->passwordconfirmLineEdit->setValidator(new QRegExpValidator(regExpPW,this));


    //获取数据库中所有银行名称信息，插入combobox插件中
    QSqlQuery query;
    query.exec("SELECT name FROM bankInfo");
    QString bankNameTemp;
    while(query.next())                     //把所有银行名列入combobox
    {
        bankNameTemp=query.value(0).toString();
        ui->banknameComboBox->addItem(bankNameTemp);
    }

    //捕获确认注册事件
    QObject::connect(ui->RegisterButton,SIGNAL(clicked()),this,SLOT(buttonRegister_clicked()));

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

//注册时会发生的异常处理
registerException::registerException(int kind)
{
    this->kind=kind;
}

QString registerException::what()//错误输出信息
{
    if(ACCOUNTERROR==kind)
    {
        return "卡号长度19位";
    }
    else if(PASSWORDERROR==kind)
    {
        return "密码长度错误为6位,两次密码输入要相同";
    }
    else if(IDCREDITERROR==kind)
    {
        return "身份证号码长度为18位";
    }
    else if(PHONENUMERROR==kind)
    {
        return "电话号码长度位11位";
    }
    else if(ACCOUNTCONFLICT==kind)
    {
        return "卡号已经被注册";
    }
    else
    {
        return "未知错误";
    }

}

//点击立即注册按钮，检查信息完整性与正确性
//正确则写入数据库，否则返回 登录界面
void RegisterDialog::check()
{
    //卡号检查
    if(ui->acoountLineEdit->text().isEmpty()||ui->acoountLineEdit->text().length()!=accountLength)
    {
        throw registerException(registerException::ACCOUNTERROR);
    }

    QString numTemp=ui->acoountLineEdit->text();
    QSqlQuery query;
    query.exec("SELECT * FROM accountInfo WHERE num = '"+numTemp+"'");
    if(query.next())
    {//该卡号已经注册，冲突
        throw registerException(registerException::ACCOUNTCONFLICT);
    }

    //密码检查
    if(ui->passwordLineEdit->text().isEmpty()||ui->passwordconfirmLineEdit->text().isEmpty()
     ||ui->passwordLineEdit->text().length()!=passwordLength||ui->passwordconfirmLineEdit->text().length()!=passwordLength)
    {
        throw registerException(registerException::PASSWORDERROR);
    }
    if(ui->passwordLineEdit->text()!=ui->passwordconfirmLineEdit->text())
    {
        throw registerException(registerException::PASSWORDERROR);
    }

    //身份证号码检查
    if(ui->idcreditLineEdit->text().isEmpty()||ui->idcreditLineEdit->text().length()!=idcreditLength)
    {
        throw registerException(registerException::IDCREDITERROR);
    }

    //电话号码
    if(ui->phoneLineEdit->text().isEmpty()||ui->phoneLineEdit->text().length()!=phonenumLength)
    {
        throw registerException(registerException::PHONENUMERROR);
    }

}

//确认注册按钮点击响应事件
void RegisterDialog::buttonRegister_clicked()
{
    try
    {
        check();//检查异常

        infoType num=ui->acoountLineEdit->text();
        infoType password=ui->passwordLineEdit->text();
        infoType bankname=ui->banknameComboBox->currentText();
        infoType idcredit=ui->idcreditLineEdit->text();
        infoType phonenum=ui->phoneLineEdit->text();
        infoType balance=QString::number(0);//初始余额为0
        //插入数据库
        QSqlQuery query;
        query.prepare("INSERT INTO accountInfo ( num, password, bankname, idcredit, phonenum, balance )"
                      "VALUES ( ?, ? , ?, ?, ?, ? )");
        query.bindValue(0,num);
        query.bindValue(1,password);
        query.bindValue(2,bankname);
        query.bindValue(3,idcredit);
        query.bindValue(4,phonenum);
        query.bindValue(5,balance);
        query.exec();

        QMessageBox::information(NULL,"RegisterInfo","注册成功,返回登录",QMessageBox::Yes | QMessageBox::Yes);

        close();
    }
    catch(registerException &E)         //输出异常种类信息
    {
        QMessageBox::warning(this,"RegisterError",E.what());
    }
}
