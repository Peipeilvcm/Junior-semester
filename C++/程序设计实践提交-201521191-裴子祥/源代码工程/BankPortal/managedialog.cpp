#include "managedialog.h"
#include "ui_managedialog.h"

#include<QObject>
#include<QMessageBox>
#include"main.h"

//管理员界面,可以看所有卡信息

//管理员对话框构造函数
ManageDialog::ManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDialog)
{
    ui->setupUi(this);

    //展示所有账户信息
    accountInfoShow();

    //捕获返回按钮点击事件
    QObject::connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(returnButton_clicked()));
    //捕获删除按钮点击事件
    QObject::connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(deleteButton_clicked()));

}

ManageDialog::~ManageDialog()
{
    delete ui;
}

void ManageDialog::accountInfoShow()
{
    //将数据库中accountInfo与表格绑定
    model = new QSqlTableModel;
    model->setTable("accountInfo");
    model->setHeaderData(0,Qt::Horizontal,"卡号");
    model->setHeaderData(1,Qt::Horizontal,"密码");
    model->setHeaderData(2,Qt::Horizontal,"所属银行");
    model->setHeaderData(3,Qt::Horizontal,"身份证号");
    model->setHeaderData(4,Qt::Horizontal,"联系方式");
    model->setHeaderData(5,Qt::Horizontal,"账户余额");

    //设置表格格式
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,160);
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(2,160);
    ui->tableView->setColumnWidth(3,160);
    ui->tableView->setColumnWidth(4,100);
    ui->tableView->setColumnWidth(5,90);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->show();
}

void ManageDialog::returnButton_clicked()
{
    close();
}

//删除按钮点击，删除选中按钮
void ManageDialog::deleteButton_clicked()
{
    //获取当前选中账户信息，提示是否删除
    int row = ui->tableView->currentIndex().row();
    infoType num = model->data(model->index(row,0)).toString();
    QMessageBox message(QMessageBox::Question,"YESorNO","确认删除卡号 "+num+" 所有信息?",QMessageBox::Yes|QMessageBox::No,this);

    if (message.exec()==QMessageBox::Yes)
    {

        model->removeRow(row);          //删除该行账户
        model->submitAll();             //提交数据库，同步

        //更新页面
        model->select();

    }
    else
    {
        return;
    }


}
