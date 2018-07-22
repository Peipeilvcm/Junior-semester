#include "mainwindow.h"
#include "ui_mainwindow.h"

//登录界面
#include <QObject>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariantList>
#include <QString>
#include <QMessageBox>
#include "account.h"
#include "registerdialog.h"
#include "managedialog.h"
#include "mainwindow.h"
#include "accountdialog.h"
#include "main.h"
#include <QRegExp>
#include <QDebug>

extern account *accountPtr;                 //当前账户信息

//注册界面(主界面)，构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //数据库连接
    QFileInfo dbFileInfo("allInfo.db");
    bool isExist=dbFileInfo.exists();
    createConnect(isExist);                //数据库文件是否存在，不存在则新建
    
    ui->setupUi(this);

    setMaximumSize(400,300);               //固定窗口
    setMinimumSize(400,300);

    setTabOrder(ui->accountLineEdit,ui->passwordLineEdit);      //设置tab切换顺序
    setTabOrder(ui->passwordLineEdit,ui->accountLineEdit);

    QRegExp regExpNum("[0-9]{19}");        //账户输入栏，只能19位输入数字，正则表达式，其它错误输入不被允许
    QRegExp regExpPW("[0-9]{6}");          //密码输入栏，只能6位输入数字，正则表达式，其它错误输入不被允许

    ui->accountLineEdit->setValidator(new QRegExpValidator(regExpNum,this));
    ui->passwordLineEdit->setValidator(new QRegExpValidator(regExpPW,this));

    //捕获登入按钮点击事件
    QObject::connect(ui->LoginButton,SIGNAL(clicked()),this,SLOT(buttonLogin_clicked()));
    //捕获管理员入口按钮点击事件
    QObject::connect(ui->ManageButton,SIGNAL(clicked()),this,SLOT(buttonManage_clicked()));
    //捕获注册按钮点击事件
    QObject::connect(ui->RegisterButton,SIGNAL(clicked()),this,SLOT(buttonRegister_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


//异常处理
loginException::loginException(errorType kind)
{
    this->kind=kind;
}

QString loginException::what()//错误输出信息
{
    if(accountError==kind)
    {
        return "卡号输入错误";
    }
    else if(accountNotFound==kind)
    {
        return "卡号不存在";
    }
    else if(passwordError==kind)
    {
        return "密码与卡号不匹配";
    }
    else
    {
        return "";
    }
}

/**建立数据库连接
 * accountInfo保存所有银行卡信息
 * bankInfo保存所有银行名称及对应编号 */
void MainWindow::createConnect(bool isExist)            //若数据库文件不存在，则新建
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("allInfo.db");                   //与数据库建立连接

    if(!db.open())
    {//数据库打开失败
        QMessageBox::critical(this,QObject::tr("数据库错误"),db.lastError().text());
        return;
    }

    QSqlQuery query(db);

    if(!isExist)//数据库不存在,第一次创建，空表项
    {
        query.exec("CREATE TABLE accountInfo ( num VARCHAR, password VARCHAR, bankname VARCHAR, idcredit VARCHAR, phonenum VARCHAR, balance REAL )");
        query.exec("CREATE TABLE bankInfo ( name VARCHAR PRIMARY KEY)");

        //初始化银行信息
        query.prepare("INSERT INTO bankInfo ( name ) VALUES ( ? )");

        QVariantList groupBankName;
        groupBankName.append("中国银行");
        groupBankName.append("中国工商银行");
        groupBankName.append("中国建设银行");
        groupBankName.append("中国农业银行");
        groupBankName.append("中国邮政储蓄银行");
        groupBankName.append("中国民生银行");
        groupBankName.append("交通银行");
        groupBankName.append("招商银行");
        groupBankName.append("中信银行");
        groupBankName.append("平安银行");
        groupBankName.append("华夏银行");
        groupBankName.append("北京银行");
        groupBankName.append("广发银行");

        query.addBindValue(groupBankName);
        query.execBatch();
    }

}


void MainWindow::buttonLogin_clicked()
{
    try
    {
        //卡号检查
        QString accountTemp=ui->accountLineEdit->text();
        QString passwordTemp=ui->passwordLineEdit->text();
        if(accountTemp.isEmpty()||accountTemp.length()<RegisterDialog::accountLength)
        {

            throw loginException(loginException::accountError);
        }

        QSqlQuery query;
        query.exec("SELECT * FROM accountInfo WHERE num = '"+accountTemp+"'");
        if(query.next())
        {
            //登录成功
            if(query.value(1)==passwordTemp)
            {
                QMessageBox::information(this,"LoginInfo",tr("登录成功"));
                infoType num=query.value(0).toString();
                infoType password=query.value(1).toString();
                infoType bankname=query.value(2).toString();
                infoType idcredit=query.value(3).toString();
                infoType phonenum=query.value(4).toString();
                balanceType balance=query.value(5).toFloat();
                accountPtr=new account (num,password,bankname,idcredit,phonenum,balance);

                ui->accountLineEdit->clear();
                ui->passwordLineEdit->clear();

                AccountDialog *accountDialogPtr = new AccountDialog(this);
                QObject::connect(this,SIGNAL(paySignal()),accountDialogPtr,SLOT(getSignal()));
                accountDialogPtr->exec();

                //close();
            }
            else//密码匹配失败抛出异常
            {
                ui->passwordLineEdit->setText("");
                throw loginException(loginException::passwordError);
            }
        }
        else//未找到
        {
            qDebug()<<"2";
            throw loginException(loginException::accountError);
        }
    }
    catch(loginException &E)
    {
        QMessageBox::warning(this,"LoginError",E.what());
    }

}

void MainWindow::buttonRegister_clicked()//跳转注册界面
{
    ui->accountLineEdit->clear();
    ui->passwordLineEdit->clear();
    RegisterDialog *registerDialogPtr=new RegisterDialog(this);
    registerDialogPtr->exec();
}

void MainWindow::buttonManage_clicked()
{
    ui->accountLineEdit->clear();
    ui->passwordLineEdit->clear();
    ManageDialog *manageDialogPtr=new ManageDialog(this);
    manageDialogPtr->exec();
}

void MainWindow::getPaySignal()
{
    emit paySignal();
}
