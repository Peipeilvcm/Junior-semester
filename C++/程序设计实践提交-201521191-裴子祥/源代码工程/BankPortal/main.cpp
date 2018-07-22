#include "mainwindow.h"
#include <QApplication>

#include"account.h"
#include <QHostAddress>
#include <QTcpServer>
#include "bankserver.h"

//全局变量,保存当前登入账户信息
account *accountPtr = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;               //主界面，即登入窗口

    //建立QTcpServer
    BankServer server;

    QObject::connect(&server,SIGNAL(paySignal()),&w,SLOT(getPaySignal()));  //捕捉支付成功信号，以实时更新界面
    if(!server.listen(QHostAddress::Any,6665))
    {
        qDebug()<<"BankServer Error in mainwindow";                         //BankServer
    }
    w.show();

    return a.exec();
}
