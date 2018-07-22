#include "addgoodsdialog.h"
#include "ui_addgoodsdialog.h"

#include<QObject>
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>
#include<QRegExp>

//管理员添加商品界面

//界面构造函数
addGoodsDialog::addGoodsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addGoodsDialog)
{
    ui->setupUi(this);
    ui->inventorySpinBox->setRange(0,100000);               //设置商品库存量
    ui->rateSpinBox->setRange(0.00,1.00);                   //设置商品折扣率

    //设置原价输入，正则表达式，只能输入浮点数，并保留两位小数
    ui->originalPriceLineEdit->setValidator(new QDoubleValidator(0.0,1000000.0,2,this));

    //捕获确认添加按钮点击事件
    QObject::connect(ui->addConfirmButton,SIGNAL(clicked()),this,SLOT(addConfirmButton_clicked()));
    //捕获返回按钮点击事件
    QObject::connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(returnButton_clicked()));
}

addGoodsDialog::~addGoodsDialog()
{
    delete ui;
}

void addGoodsDialog::returnButton_clicked()
{
    close();
}

//确认添加按钮点击，将输入的商品信息添加到库中
void addGoodsDialog::addConfirmButton_clicked()
{
    //错误处理
    if(ui->nameLineEdit->text().isEmpty()||ui->originalPriceLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "AddGoodsError","请填写完整信息", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    //检查原价填写错误
    QString oriPrice = ui->originalPriceLineEdit->text();
    if(oriPrice.length()>10)
    {
        QMessageBox::warning(this, "AddGoodsError","原价非法输入", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }

    QString name = ui->nameLineEdit->text();
    QString type = ui->typeComboBox->currentText();

    int inventory = ui->inventorySpinBox->value();
    QString rate = ui->rateSpinBox->text();
    QString other = ui->otherLineEdit->text();
    QString description = ui->descriptionTextEdit->toPlainText();

    //插入新商品到数据库 商品信息表中
    QSqlQuery query;
    query.prepare("INSERT INTO productInfo ( name, type, originalPrice, inventory, rate, other, description )"
                  "VALUES ( ?, ?, ?, ?, ?, ?, ? )");
    query.bindValue(0,name);
    query.bindValue(1,type);
    query.bindValue(2,oriPrice);
    query.bindValue(3,inventory);
    query.bindValue(4,rate);
    query.bindValue(5,other);
    query.bindValue(6,description);
    query.exec();

    //情况界面输入框，以供下一个商品信息输入
    QMessageBox::information(this,"AddGoodsInfo","添加成功",QMessageBox::Yes | QMessageBox::Yes);
    ui->nameLineEdit->clear();
    ui->typeComboBox->setCurrentIndex(0);
    ui->inventorySpinBox->clear();
    ui->rateSpinBox->setValue(0.0);
    ui->otherLineEdit->clear();
    ui->originalPriceLineEdit->clear();
    ui->descriptionTextEdit->clear();

}
