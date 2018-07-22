#ifndef BANKSERVER_H
#define BANKSERVER_H

#include <QtNetwork>

/* 定义了TCP的服务器线程bankServer*
 * 通过继承QTcpServer，在有客户端要建立连接时，
 * 建立TcpSocket线程与客户端建立TCP连接 */
class BankServer : public QTcpServer
{
    Q_OBJECT
private:
    QTcpSocket *clientConnection;
public:
    BankServer(QObject *parent=0);

signals:
    void paySignal();                   //支付成功信号，传给主函数，以更新首页余额信息

private slots:
    void acceptConnection();            //当有新客户端请求建立连接时（即newConnection()被唤醒时，建立连接
    void readClient();                  /* 建立连接后，如果有信息传入（即readyRead()信号被唤醒）
                                         * 开始读取信息并进行处理
                                         * 处理完信息后将处理结果再发回客户端 */
};

#endif // BANKSERVER_H
