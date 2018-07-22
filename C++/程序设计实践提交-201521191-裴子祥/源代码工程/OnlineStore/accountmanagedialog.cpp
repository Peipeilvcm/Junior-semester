#include "accountmanagedialog.h"
#include "ui_accountmanagedialog.h"

#include<QObject>
#include<QRegExp>
#include<QSqlQuery>
#include<QMessageBox>
#include <QtNetwork>

#include "globalinfo.h"

//绑定银行卡界面

accountManageDialog::accountManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountManageDialog)
{
    ui->setupUi(this);

    //正则表达式,预防错误产生
    QRegExp regExpNum("[0-9]{19}");                    //银行卡账户号码只能输入19位数字
    QRegExp regExpPassword("[0-9]{6}");                //银行卡密码只能输入6位数字
    ui->accountNumLineEdit->setValidator(new QRegExpValidator(regExpNum,this));
    ui->passwordLineEdit->setValidator(new QRegExpValidator(regExpPassword,this));

    //点击确认绑定按钮
    QObject::connect(ui->bindConfirmButton,SIGNAL(clicked()),this,SLOT(bindConfirmButton_clicked()));
    //点击取消按钮
    QObject::connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(returnButton_clicked()));

}

accountManageDialog::~accountManageDialog()
{
    delete ui;
}

//绑定确认按钮被按下，触发事件
void accountManageDialog::bindConfirmButton_clicked()
{
    //获得当前用户账号(即电话号码)
    QString userPhoneNum = GlobalInfo::instance()->getUserNum();

    QSqlQuery query;

    //从输入编辑栏读入卡号和密码
    QString accountNumTemp = ui->accountNumLineEdit->text();
    QString passwprdTemp = ui->passwordLineEdit->text();

    //错误处理
    if(accountNumTemp.isEmpty()||passwprdTemp.isEmpty())
    {
        QMessageBox::warning(this, "AddError","信息未填写完整！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    //判断卡号是否已经被绑定
    query.exec("SELECT * FROM cardInfo WHERE accountNum = '"+accountNumTemp+"'"+"AND userPhoneNum = '"+userPhoneNum+"'");

    if(query.next())
    {//此卡已经被绑定
        QMessageBox::warning(this, "AddError","您已经绑定此银行卡", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    //发送信息至银行服务器，以请求绑定银行卡
    QString sendStr = "accountNum:"+accountNumTemp+";password:"+passwprdTemp;
    int receiveSignal = askBank(sendStr);

    if(receiveSignal==SUCCESS)                  //绑定成功
    {
        query.prepare("INSERT INTO cardInfo (accountNum, userPhoneNum) VALUES (?,?)");
        query.bindValue(0,accountNumTemp);
        query.bindValue(1,userPhoneNum);
        query.exec();
        QMessageBox::information(NULL, "BindInfo","绑定成功", QMessageBox::Yes | QMessageBox::Yes);
        close();
    }
    else if(receiveSignal==NOSEVER)             //未连接到服务器
    {
        QMessageBox::warning(this, "AddError","未连接到服务器,请稍后再试", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(receiveSignal==DISCONNECT)          //与服务区失去连接
    {
        QMessageBox::warning(this, "AddError","与服务区失去连接,请稍后再试", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(receiveSignal==WRONGNUM)            //卡号输入错误
    {
        QMessageBox::warning(this, "AddError","卡号输入错误", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else                                        //密码错误
    {
        QMessageBox::warning(this, "AddError","密码错误,绑定失败", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
}


void accountManageDialog::returnButton_clicked()
{
    close();
}


//建立与银行服务器的Tcp连接,发送请求信息(卡号、密码)给银行服务器
int accountManageDialog::askBank(QString sendStr)
{
    //与银行服务器建立Tcp连接
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(QHostAddress::LocalHost,6665);

    if(socket->waitForConnected(1000))
    {
        socket->write(sendStr.toUtf8());
        if(socket->waitForReadyRead(1000))
        {
            //读取返回结果
            QString res = socket->readAll();

            if(res=="SUCCESS")              //绑定成功
            {
                socket->disconnectFromHost();
                return SUCCESS;
            }
            else if(res == "WRONGNUM")      //账号不存在
            {
                socket->disconnectFromHost();
                return WRONGNUM;
            }
            else if(res == "WRONGPW")       //密码错误
            {
                socket->disconnectFromHost();
                return WRONGPW;
            }
            else                            //未知错误，一般不会出现
            {
                QMessageBox::warning(NULL, "ERROR","出现未知错误", QMessageBox::Yes | QMessageBox::Yes);
                socket->disconnectFromHost();
                return DISCONNECT;
            }

        }
        else    //失去连接
        {
            socket->disconnectFromHost();
            return DISCONNECT;
        }
    }
    else        //服务器不存在
    {
        socket->disconnectFromHost();
        return NOSEVER;
    }
}
