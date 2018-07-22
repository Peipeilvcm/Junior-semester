#include "paydialog.h"
#include "ui_paydialog.h"


//支付界面

#include<QObject>
#include<QDebug>
#include<QSqlQuery>
#include<QRegExp>
#include<QMessageBox>
#include <QtNetwork>

#include "globalinfo.h"
/*
extern bool isLogin;
extern QString userPhoneNum;
extern int Full;
extern int Reduce;
extern bool isFRstart;
extern bool isPayed;*/

PayDialog::PayDialog(QWidget *parent, QVector<Product *> productItems, QVector<int> quant) :
    QDialog(parent),
    ui(new Ui::PayDialog)
{
    productList.clear();
    productList.swap(productItems);
    quantities.clear();
    quantities.swap(quant);

    ui->setupUi(this);


    QRegExp regExpPW("[0-9]{6}");
    ui->passwLineEdit->setValidator(new QRegExpValidator(regExpPW,this));

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->resizeRowsToContents();

    QStringList header;
    header<<"名称"<<"品类"<<"原价"<<"库存"<<"现价"<<"数量"<<"其它"<<"描述";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    productItemShow();

    QString userPhoneNum = GlobalInfo::instance()->getUserNum();

    QSqlQuery query;
    query.exec("SELECT * FROM cardInfo WHERE userPhoneNum = '"+userPhoneNum+"'");
    if(query.next())
    {
        ui->accountNumComboBox->addItem(query.value(0).toString());
        while(query.next())
        {
            ui->accountNumComboBox->addItem(query.value(0).toString());
        }
    }
    else
    {
        ui->cardLabel->setText("您未绑定银行卡");
        ui->payConfirmButton->setDisabled(true);
        ui->passwLineEdit->setDisabled(true);
        ui->accountNumComboBox->setDisabled(true);
    }


    QObject::connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(returnButton_clicked()));
    QObject::connect(ui->payConfirmButton,SIGNAL(clicked()),this,SLOT(payConfirmButton_clicked()));
}

PayDialog::~PayDialog()
{
    delete ui;
}

void PayDialog::payConfirmButton_clicked()
{//付款
    QString accountNumTemp = ui->accountNumComboBox->currentText();
    QString passwprdTemp = ui->passwLineEdit->text();
    QString paySumTemp = ui->paySumLabel_2->text();
    if(passwprdTemp.isEmpty())
    {
        QMessageBox::warning(this, "AddError","请填写密码！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    QString sendStr = "pay:"+paySumTemp+";accountNum:"+accountNumTemp+";password:"+passwprdTemp;
    qDebug()<<sendStr;
    int receiveSignal = askBank(sendStr);
    qDebug()<<receiveSignal;
    if(receiveSignal==SUCCESS)
    {//支付成功
        QMessageBox::information(NULL, "PayInfo","支付成功,等待收货吧", QMessageBox::Yes | QMessageBox::Yes);
        GlobalInfo::instance()->setIsPayed(true);
        close();
    }
    else if(receiveSignal==NOSEVER)
    {
        QMessageBox::warning(this, "PayError","未连接到服务器,请稍后再试", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(receiveSignal==DISCONNECT)
    {
        QMessageBox::warning(this, "PayError","与服务区失去连接,请稍后再试", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(receiveSignal==LACKMONEY)
    {
        QMessageBox::warning(this, "PayError","您的账户余额不足,支付失败", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else
    {
        QMessageBox::warning(this, "PayError","密码错误,支付失败", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

}

int PayDialog::askBank(QString sendStr)
{//建立与银行服务器的Tcp连接
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(QHostAddress::LocalHost,6665);
    if(socket->waitForConnected(1000))
    {
        socket->write(sendStr.toUtf8());
        if(socket->waitForReadyRead(2000))
        {
            QString res = socket->readAll();
            if(res=="SUCCESS")
            {
                socket->disconnectFromHost();
                return SUCCESS;
            }
            else if(res == "WRONGNUM")
            {
                socket->disconnectFromHost();
                return WRONGNUM;
            }
            else if(res == "WRONGPW")
            {
                socket->disconnectFromHost();
                return WRONGPW;
            }
            else if(res == "LACKMONEY")
            {
                socket->disconnectFromHost();
                return LACKMONEY;
            }
            else
            {
                socket->disconnectFromHost();
                QMessageBox::warning(NULL, "ERROR","出现未知错误", QMessageBox::Yes | QMessageBox::Yes);
                return DISCONNECT;
            }
        }
        else
        {
            socket->disconnectFromHost();
            return DISCONNECT;
        }
    }
    else
    {
        socket->disconnectFromHost();
        return NOSEVER;
    }
}


void PayDialog::returnButton_clicked()
{
    close();
}

void PayDialog::productItemShow()
{
    int row = productList.size();
    ui->tableWidget->setRowCount(row);
    //qDebug()<<row;
    double oriPriceSum = 0.0;
    double priceSum = 0.0;
    double paySum = 0.0;

    for(int i = 0;i<row;++i)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem(productList[i]->getName());
        ui->tableWidget->setItem(i,0,item1);
        QTableWidgetItem *item2 = new QTableWidgetItem(productList[i]->getType());
        ui->tableWidget->setItem(i,1,item2);
        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(productList[i]->getOriginalPrice()));
        ui->tableWidget->setItem(i,2,item3);
        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(productList[i]->getInventory()));
        ui->tableWidget->setItem(i,3,item4);
        QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(productList[i]->getPrice()));
        ui->tableWidget->setItem(i,4,item5);
        QTableWidgetItem *item8 = new QTableWidgetItem(QString::number(quantities[i]));
        ui->tableWidget->setItem(i,5,item8);
        QTableWidgetItem *item6 = new QTableWidgetItem(productList[i]->toString());
        ui->tableWidget->setItem(i,6,item6);
        QTableWidgetItem *item7 = new QTableWidgetItem(productList[i]->getDescroption());
        ui->tableWidget->setItem(i,7,item7);

        oriPriceSum += productList[i]->getOriginalPrice()*quantities[i];
        priceSum += productList[i]->getPrice()*quantities[i];
    }

    bool isFRstart = GlobalInfo::instance()->getIsFRstart();

    if(isFRstart==true)
    {
        int Full = GlobalInfo::instance()->getFull();
        int Reduce = GlobalInfo::instance()->getReduce();
        ui->fullThenReduceLabel_2->setText("满 "+QString::number(Full)+" 减 "+QString::number(Reduce)+" ");
        paySum = priceSum - (int)(priceSum/Full)*Reduce;
    }
    else
    {
        paySum = priceSum;
    }

    ui->oriPriceSumLabel_2->setText(QString::number(oriPriceSum));
    ui->priceSumLabel_2->setText(QString::number(priceSum));
    ui->paySumLabel_2->setText(QString::number(paySum));

    ui->tableWidget->show();

}
