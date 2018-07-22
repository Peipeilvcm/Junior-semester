#include "managedialog.h"
#include "ui_managedialog.h"

#include <QObject>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QMessageBox>
#include<QRegExp>
#include "addgoodsdialog.h"
#include "globalinfo.h"

//管理员编辑界面

ManageDialog::ManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDialog)
{
    ui->setupUi(this);

    //正则表达式，预防修改折扣信息和满减信息出错
    ui->bookRateLineEdit->setValidator(new QDoubleValidator(0.0,1.0,2,this));
    ui->clothRateLineEdit->setValidator(new QDoubleValidator(0.0,1.0,2,this));
    ui->foodRateLineEdit->setValidator(new QDoubleValidator(0.0,1.0,2,this));
    ui->phoneRateLineEdit->setValidator(new QDoubleValidator(0.0,1.0,2,this));

    ui->fullLineEdit->setValidator(new QIntValidator(0,100000,this));
    ui->reduceLineEdit->setValidator(new QIntValidator(0,100000,this));

    goodsInfoShow();

    //当前满减信息
    bool isFRstart = GlobalInfo::instance()->getIsFRstart();
    int Full = GlobalInfo::instance()->getFull();
    int Reduce = GlobalInfo::instance()->getReduce();

    if(isFRstart==true)
    {
        ui->onSaleCheckBox->setChecked(true);
    }
    ui->fullLineEdit->setText(QString::number(Full));
    ui->reduceLineEdit->setText(QString::number(Reduce));

    QObject::connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(returnButton_clicked()));
    QObject::connect(ui->addGoodsButton,SIGNAL(clicked()),this,SLOT(addGoodsButton_clicked()));
    QObject::connect(ui->delGoodsButton,SIGNAL(clicked()),this,SLOT(delGoodsButton_clicked()));

    QObject::connect(ui->discountSetButton,SIGNAL(clicked()),this,SLOT(discountSetButton_clicked()));
    QObject::connect(ui->onSaleSetButton,SIGNAL(clicked()),this,SLOT(onSaleSetButton_clicked()));
}

ManageDialog::~ManageDialog()
{
    delete ui;
}

void ManageDialog::goodsInfoShow()
{
    //商品展示
    manageModel = new QSqlTableModel;
    manageModel->setTable("productInfo");
    manageModel->setHeaderData(1,Qt::Horizontal,"商品名称");
    manageModel->setHeaderData(2,Qt::Horizontal,"品类");
    manageModel->setHeaderData(3,Qt::Horizontal,"原价");
    manageModel->setHeaderData(4,Qt::Horizontal,"库存量");
    manageModel->setHeaderData(5,Qt::Horizontal,"折扣力度");
    manageModel->setHeaderData(6,Qt::Horizontal,"其它");
    manageModel->setHeaderData(7,Qt::Horizontal,"简介");

    manageModel->select();
    ui->GoodsTableView->setModel(manageModel);
    ui->GoodsTableView->setColumnWidth(1,100);
    ui->GoodsTableView->setColumnWidth(2,60);
    ui->GoodsTableView->setColumnWidth(3,50);
    ui->GoodsTableView->setColumnWidth(4,50);
    ui->GoodsTableView->setColumnWidth(5,70);
    ui->GoodsTableView->setColumnWidth(6,100);
    ui->GoodsTableView->setColumnHidden(0,true);

    QHeaderView *header = ui->GoodsTableView->horizontalHeader();
    header->setStretchLastSection(true);
    ui->GoodsTableView->show();
}

void ManageDialog::updateGoodsInfo()
{
    manageModel->select();
}

void ManageDialog::returnButton_clicked()
{
    close();
}

//弹出管理员添加商品对话框
void ManageDialog::addGoodsButton_clicked()
{
    addGoodsDialog *addPtr = new addGoodsDialog(this);
    addPtr->exec();
    updateGoodsInfo();//更新商品信息
}

//管理员删除商品
void ManageDialog::delGoodsButton_clicked()
{
    int row = ui->GoodsTableView->currentIndex().row();

    if(row == -1)
    {
        QMessageBox::warning(this, "Error","请选择物品删除", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }


    QMessageBox message(QMessageBox::Question,"YESorNO","确认删除此物品?",QMessageBox::Yes|QMessageBox::No,this);

    if (message.exec()==QMessageBox::Yes)
    {

        manageModel->removeRow(row);//删除该行
        manageModel->submitAll();//提交数据库，同步

        //更新页面
        manageModel->setFilter("");
        manageModel->select();
    }
    else
    {
        return;
    }
}

/*void ManageDialog::modifyGoodsButton_clicked()
{
    //已经实现，model,直接在显示表格中显示
}*/

void ManageDialog::discountSetButton_clicked()          //品类打折活动
{
    bool flag = false;
    QSqlQuery query;
    if(!ui->bookRateLineEdit->text().isEmpty())
    {
        //书籍的折扣类型
        float rateBook = ui->bookRateLineEdit->text().toFloat();
        if(rateBook<1.000001&&rateBook>0.0)
        {
            //更新书本折扣信息
            query.exec("UPDATE productInfo SET rate = "+QString::number(rateBook,'f',2)+" WHERE type = 'BOOK'");

            //修改购物车中信息
            QSqlQuery query2;
            query2.exec("SELECT * FROM cartInfo WHERE type = 'BOOK'");
            while (query2.next())
            {
                query.exec("UPDATE cartInfo SET price = "+QString::number(rateBook*query2.value(3).toFloat(),'f',2)+" WHERE id = "+query2.value(0).toString());

            }

            flag = true;
        }
        else
        {
            QMessageBox::warning(this,"discountError","图书折扣设置失败，请检查输入",QMessageBox::Yes|QMessageBox::Yes);
        }
    }
    if(!ui->clothRateLineEdit->text().isEmpty())
    {
        float rateCloth = ui->clothRateLineEdit->text().toFloat();
        if(rateCloth<1.000001&&rateCloth>0.0)
        {
            //更新服装折扣信息
            query.exec("UPDATE productInfo SET rate = "+QString::number(rateCloth,'f',2)+" WHERE type = 'CLOTH'");

            //修改购物车中信息
            QSqlQuery query2;
            query2.exec("SELECT * FROM cartInfo WHERE type = 'CLOTH'");
            while (query2.next())
            {
                query.exec("UPDATE cartInfo SET price = "+QString::number(rateCloth*query2.value(3).toFloat(),'f',2)+" WHERE id = "+query2.value(0).toString());

            }

            flag = true;
        }
        else
        {
            QMessageBox::warning(this,"discountError","服装折扣设置失败，请检查输入",QMessageBox::Yes|QMessageBox::Yes);
        }

    }
    if(!ui->foodRateLineEdit->text().isEmpty())
    {
        float rateFood = ui->foodRateLineEdit->text().toFloat();
        if(rateFood<1.000001&&rateFood>0.0)
        {

            //更新食品折扣信息
            query.exec("UPDATE productInfo SET rate = "+QString::number(rateFood,'f',2)+" WHERE type = 'FOOD'");

            //修改购物车中信息
            QSqlQuery query2;
            query2.exec("SELECT * FROM cartInfo WHERE type = 'FOOD'");
            while (query2.next())
            {
                query.exec("UPDATE cartInfo SET price = "+QString::number(rateFood*query2.value(3).toFloat(),'f',2)+" WHERE id = "+query2.value(0).toString());

            }

            flag = true;
        }
        else
        {
            QMessageBox::warning(this,"discountError","食品折扣设置失败，请检查输入",QMessageBox::Yes|QMessageBox::Yes);
        }

    }
    if(!ui->phoneRateLineEdit->text().isEmpty())
    {
        float ratePhone = ui->phoneRateLineEdit->text().toFloat();
        if(ratePhone<1.000001&&ratePhone>0.0)
        {
            //更新手机折扣信息
            query.exec("UPDATE productInfo SET rate = "+QString::number(ratePhone,'f',2)+" WHERE type = 'PHONE'");

            //修改购物车中信息
            QSqlQuery query2;
            query2.exec("SELECT * FROM cartInfo WHERE type = 'PHONE'");
            while (query2.next())
            {
                query.exec("UPDATE cartInfo SET price = "+QString::number(ratePhone*query2.value(3).toFloat(),'f',2)+" WHERE id = "+query2.value(0).toString());

            }

            flag = true;
        }
        else
        {
            QMessageBox::warning(this,"discountError","手机折扣设置失败，请检查输入",QMessageBox::Yes|QMessageBox::Yes);
        }

    }

    if(flag == true)
    {
        QMessageBox::information(this,"折扣信息","成功设置品类折扣",QMessageBox::Yes|QMessageBox::Yes);
        manageModel->select();//更新信息
    }
    else
    {
        QMessageBox::warning(this,"discountError","设置品类折扣失败，请填写正确信息",QMessageBox::Yes|QMessageBox::Yes);
    }

}


//满减信息与状态设置
void ManageDialog::onSaleSetButton_clicked()
{
    if(ui->onSaleCheckBox->isChecked())
    {
        QString fullTemp = ui->fullLineEdit->text();
        QString reduceTemp = ui->reduceLineEdit->text();
        for(int i=0;i<fullTemp.length();++i)
        {
            if(fullTemp.at(i)>'9'||fullTemp.at(i)<'0')
            {
                QMessageBox::warning(this,"满减错误","满减信息错误",QMessageBox::Yes|QMessageBox::Yes);
                return;
            }
        }
        for(int i=0;i<reduceTemp.length();++i)
        {
            if(reduceTemp.at(i)>'9'||reduceTemp.at(i)<'0')
            {
                QMessageBox::warning(this,"满减错误","满减信息错误",QMessageBox::Yes|QMessageBox::Yes);
                return;
            }
        }
        if(fullTemp.toInt()<=0)
        {
            QMessageBox::warning(this,"满减错误","至少满个正数再减吧,别亏本了",QMessageBox::Yes|QMessageBox::Yes);
            return;
        }
        else if(fullTemp.toInt()<reduceTemp.toInt())
        {
            QMessageBox::warning(this,"满减错误","至少满个正数再减吧,别亏本了",QMessageBox::Yes|QMessageBox::Yes);
            return;
        }

        //更新满减信息

        GlobalInfo::instance()->setIsFRstart(true);
        GlobalInfo::instance()->setFull(fullTemp.toInt());
        GlobalInfo::instance()->setReduce(reduceTemp.toInt());

        QSqlQuery query;
        query.exec("UPDATE onSaleInfo SET full = "+fullTemp);
        query.exec("UPDATE onSaleInfo SET reduce = "+reduceTemp);
        query.exec("UPDATE onSaleInfo SET isStart = 'YES'");

        QMessageBox::information(this,"满减信息","满减活动开始了",QMessageBox::Yes|QMessageBox::Yes);
    }
    else
    {
        GlobalInfo::instance()->setIsFRstart(false);
        QSqlQuery query;
        query.exec("UPDATE onSaleInfo SET isStart = 'NO'");
        QMessageBox::information(this,"满减信息","满减活动不开始",QMessageBox::Yes|QMessageBox::Yes);
    }
}
