#include "modifyquantitydialog.h"
#include "ui_modifyquantitydialog.h"

#include<QSqlQuery>
#include <QMessageBox>

#include "globalinfo.h"

//extern QString userPhoneNum;

modifyQuantityDialog::modifyQuantityDialog(QWidget *parent, int id, int quantity) :
    QDialog(parent),
    ui(new Ui::modifyQuantityDialog)
{
    this->id = id;

    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT * FROM productInfo where id = "+QString::number(id));
    if(query.next())
    {
        //显示商品信息
        ui->nameLabel->setText(query.value(1).toString());
        ui->typeLabel->setText(query.value(2).toString());
        ui->oriPriceLabel->setText(query.value(3).toString());
        ui->inventoryLabel->setText(query.value(4).toString());
        ui->rateLabel->setText(query.value(5).toString());
        ui->quantitySpinBox->setValue(quantity);
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

    QObject::connect(ui->modifyConfirmButton,SIGNAL(clicked(bool)),this,SLOT(modifyConfirmButton_clicked()));
    QObject::connect(ui->returnButton,SIGNAL(clicked(bool)),this,SLOT(returnButton_clicked()));
}

modifyQuantityDialog::~modifyQuantityDialog()
{
    delete ui;
}

void modifyQuantityDialog::modifyConfirmButton_clicked()
{
    QString userPhoneNum = GlobalInfo::instance()->getUserNum();

    int quantitytemp = ui->quantitySpinBox->text().toInt();
    if(quantitytemp<0)
    {
        QMessageBox::warning(this, "AddError","亲，负数是什么意思，我要送给你吗？", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(quantitytemp==0)//删除
    {
        QMessageBox message(QMessageBox::Question,"YESorNO","确认删除此物品?",QMessageBox::Yes|QMessageBox::No,this);

        if (message.exec()==QMessageBox::Yes)
        {
            QSqlQuery query;
            query.exec("DELETE FROM cartInfo where id = "+QString::number(getId())+" AND userPhoneNum = '"+userPhoneNum+"'");

            QMessageBox::information(this, "DeleteFromCart","删除成功", QMessageBox::Yes | QMessageBox::Yes);
            close();
        }
        else
        {
            return;
        }
    }
    else
    {
        QSqlQuery query;
        query.exec("UPDATE cartInfo SET quantity = "+QString::number(quantitytemp)+" WHERE id = "+QString::number(getId())+" AND userPhoneNum = '"+userPhoneNum+"'");
        QMessageBox::information(this, "ModifyQuantity","修改数量成功", QMessageBox::Yes | QMessageBox::Yes);
        close();
    }

}

void modifyQuantityDialog::returnButton_clicked()
{
    close();
}

