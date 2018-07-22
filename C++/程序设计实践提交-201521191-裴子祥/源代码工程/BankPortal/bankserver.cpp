#include "bankserver.h"

#include <QtNetwork>
#include <QSqlQuery>
#include <QRegExp>
#include "account.h"

extern account *accountPtr;               //当前账户信息

BankServer::BankServer(QObject *parent)
    :QTcpServer(parent)
{
    connect(this,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}

//当有新客户端请求建立连接时（即newConnection()被唤醒时，建立连接
void BankServer::acceptConnection()
{
    this->clientConnection = this->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

/* 建立连接后，如果有信息传入（即readyRead()信号被唤醒）
 * 开始读取信息并进行处理
 * 处理完信息后将处理结果再发回客户端 */
void BankServer::readClient()
{

    QString receiveStr = clientConnection->readAll();
    QString res;
    QSqlQuery query;

    QRegExp patternBindingCard("accountNum:(.*);password:(.*)");        //绑定信息结构：账户号码，密码
    QRegExp patternPayment("pay:(.*);accountNum:(.*);password:(.*)");   //支付信息结构：支付金额，账户号码，密码


    if(receiveStr.indexOf(patternBindingCard)==0)
    {                                                                   //绑定银行卡操作
        QStringList strList = patternBindingCard.capturedTexts();       //捕获客户端发来的绑定信息
        QString accountNum = strList.at(1);                             //从绑定信息中提取账户号码
        QString password = strList.at(2);                               //从绑定信息中提取账户密码

        //查询数据库，对比账号密码是否匹配

        query.exec("SELECT password FROM accountInfo WHERE num = '"+accountNum+"'");        //找到当前账户的密码，进行校对
        if(query.next())
        {
            if(password==query.value(0).toString())
            {
                res = "SUCCESS";
            }
            else
            {
                res = "WRONGPW";
            }
        }
        else
        {
            res = "WRONGNUM";
        }
    }
    else if(receiveStr.indexOf(patternPayment)==0)                      //支付操作
    {
        QStringList strList = patternPayment.capturedTexts();           //捕获客户端发来的绑定信息
        float paySum = strList.at(1).toFloat();                         //从绑定信息中提取支付金额
        QString accountNum = strList.at(2);                             //从绑定信息中提取账户号码
        QString password = strList.at(3);                               //从绑定信息中提取账户密码

        //查询数据库，找出此账户
        query.exec("SELECT * FROM accountInfo WHERE num = '"+accountNum+"'");

        if(query.next())
        {
            if(password == query.value(1).toString())
            {
                if(paySum<=query.value(5).toFloat())
                {   //支付成功
                    res = "SUCCESS";

                    //更新账户余额信息
                    float balance = query.value(5).toFloat() - paySum;
                    query.exec("UPDATE accountInfo SET balance = "+QString::number(balance)+" WHERE num = '"+accountNum+"'");
                    if(accountPtr)//若accountPtr不为空
                    {
                        accountPtr->withdraw(paySum);                  //取出支付金额，相当于购买
                        emit paySignal();                              //发送支付成功信号，以更新窗口
                    }

                }
                else
                {
                    res = "LACKMONEY";                                 //余额不足以支付
                }
            }
            else
            {
                res = "WRONGPW";                                       //密码错误
            }

        }
        else
        {
            res = "WRONGNUM";                                           //账户不存在
        }
    }
    else
    {
        res="ERROR";                                                    //字符串传入错误
    }

    clientConnection->write(res.toUtf8());                              //将结果返回客户端
}
