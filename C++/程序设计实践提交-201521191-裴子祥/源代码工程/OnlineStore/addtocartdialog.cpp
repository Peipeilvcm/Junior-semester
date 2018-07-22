#include "addtocartdialog.h"
#include "ui_addtocartdialog.h"

#include <QObject>
#include <QSqlQuery>
#include <QMessageBox>
#include "globalinfo.h"


//用户添加商品至购物车界面

//界面构造函数
addToCartDialog::addToCartDialog(QWidget *parent,int id) :  //传入商品的内部id
    QDialog(parent),
    ui(new Ui::addToCartDialog)
{
    this->id = id;
    ui->setupUi(this);

    //找到商品库中该商品信息
    QSqlQuery query;
    query.exec("SELECT * FROM productInfo where id = "+QString::number(id));

    //将此商品在对话框中展示
    if(query.next())
    {
        ui->nameLabel->setText(query.value(1).toString());
        ui->typeLabel->setText(query.value(2).toString());
        ui->oriPriceLabel->setText(query.value(3).toString());
        ui->inventoryLabel->setText(query.value(4).toString());
        ui->rateLabel->setText(query.value(5).toString());
        if(query.value(2).toString()=="BOOK")
        {
            ui->otherLabel->setText("作者:");
        }
        else if(query.value(2).toString()=="CLOTH")
        {
            ui->otherLabel->setText("种类:");
        }
        else if(query.value(2).toString()=="FOOD")
        {
            ui->otherLabel->setText("类别:");
        }
        else
        {
            ui->otherLabel->setText("品牌:");
        }
        ui->otherValueLabel->setText(query.value(6).toString());
        ui->descriptionLabel->setText(query.value(7).toString());
    }

    //捕获确认添加按钮点击事件
    QObject::connect(ui->addConfirmButton,SIGNAL(clicked(bool)),this,SLOT(addConfirmButton_clicked()));
    //捕获返回按钮点击事件
    QObject::connect(ui->returnButton,SIGNAL(clicked(bool)),this,SLOT(returnButton_clicked()));
}

addToCartDialog::~addToCartDialog()
{
    delete ui;
}


//确认添加按钮点击事件，将一定数量的选中商品加入到自己的购物车中
void addToCartDialog::addConfirmButton_clicked()
{
    QString userPhoneNum = GlobalInfo::instance()->getUserNum();

    int quantitytemp = ui->quantitySpinBox->text().toInt();
    if(quantitytemp<=0)
    {
        QMessageBox::warning(this, "AddError","亲，至少添加一件商品", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    QSqlQuery query;
    query.exec("SELECT * FROM cartInfo WHERE id = "+QString::number(getId())+" AND userPhoneNum = '"+userPhoneNum+"'");
    if(query.next())         //此商品已经存在与用户购物车中，则只更改数量
    {
        quantitytemp += query.value(5).toInt();
        query.exec("UPDATE cartInfo SET quantity = "+QString::number(quantitytemp)+" WHERE id = "+QString::number(getId())+" AND userPhoneNum = '"+userPhoneNum+"'");
        QMessageBox::information(this, "AddToCart","添加成功", QMessageBox::Yes | QMessageBox::Yes);
        close();
    }
    else        //把商品信息插入到购物车信息表中，加入用户的账号以索引
    {
        query.prepare("INSERT INTO cartInfo (id, name, type, oriPrice , price, quantity, userPhoneNum) VALUES( ?,?,?,?,?,?,? )");
        query.bindValue(0,QString::number(getId()));
        query.bindValue(1,ui->nameLabel->text());
        query.bindValue(2,ui->typeLabel->text());
        query.bindValue(3,ui->oriPriceLabel->text());
        query.bindValue(4,QString::number(ui->oriPriceLabel->text().toFloat()*ui->rateLabel->text().toFloat()));
        query.bindValue(5,QString::number(quantitytemp));
        query.bindValue(6,userPhoneNum);
        query.exec();

        QMessageBox::information(this, "AddToCart","添加成功", QMessageBox::Yes | QMessageBox::Yes);
        close();
    }



}

void addToCartDialog::returnButton_clicked()
{
    close();
}
