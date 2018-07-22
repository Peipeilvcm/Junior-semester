#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QObject>
#include "logindialog.h"
#include "registerdialog.h"
#include "managedialog.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include "modifyuserinfodialog.h"
#include "cart.h"
#include "addtocartdialog.h"
#include "modifyquantitydialog.h"
#include<QDebug>
#include<QAbstractItemModel>

#include"accountmanagedialog.h"
#include"paydialog.h"
#include "product.h"

#include "globalinfo.h"

//进入店铺首界面

//首页构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//数据库连接
    QFileInfo dbFileInfo("allInfo.db");
    bool isExist = dbFileInfo.exists();
    createConnect(isExist);

    ui->setupUi(this);

    //设置商品栏的展示形式
    ui->searchByNameLineEdit->setPlaceholderText("搜索 名称/描述/其它信息");
    ui->GoodsTableView->setEditTriggers( QAbstractItemView::NoEditTriggers);//设置列表不可被修改
    ui->GoodsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->GoodsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->CartTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->CartTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->CartTableView->setSelectionMode(QAbstractItemView::MultiSelection);

    //用户信息展示
    updateUserInfo();
    //所有商品信息展示
    goodsInfoShow();


    /* 连接信号与槽,响应有效点击操作*/
    //登入界面接口
    QObject::connect(ui->loginEntryButton,SIGNAL(clicked()),this,SLOT(loginEntryButton_clicked()));
    //注册界面接口
    QObject::connect(ui->registerEntryButton,SIGNAL(clicked()),this,SLOT(registerEntryButton_clicked()));
    //管理员用户接口
    QObject::connect(ui->manageEntryButton,SIGNAL(clicked()),this,SLOT(manageEntryButton_clicked()));

    //添加之购物车界面接口
    QObject::connect(ui->addToCartButton,SIGNAL(clicked()),this,SLOT(addToCartButton_clicked()));
    //修改购物车内商品数量接口按钮
    QObject::connect(ui->modifyQuantityButton,SIGNAL(clicked()),this,SLOT(modifyQuantityButton_clicked()));
    //删除购物车内商品接口按钮
    QObject::connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(deleteButton_clicked()));
    //提交订单，转向支付接口
    QObject::connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(submitButton_clicked()));
    //修改用户信息接口
    QObject::connect(ui->modifyUserInfoButton,SIGNAL(clicked()),this,SLOT(modifyUserInfoButton_clicked()));
    //用户银行账户绑定接口
    QObject::connect(ui->accountMagButton,SIGNAL(clicked()),this,SLOT(accountMagButton_clicked()));
    //用户银行账户解绑接口按钮
    QObject::connect(ui->disBindingButton,SIGNAL(clicked()),this,SLOT(disBindingButton_clicked()));

    //按品类分类combox选择
    QObject::connect(ui->typeShowComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(typeShowCombox_select()));
    //按价格排序combox选择
    QObject::connect(ui->sortComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(sortCombox_select()));
    //模糊查询按钮
    QObject::connect(ui->searchButton,SIGNAL(clicked(bool)),this,SLOT(searchButton_clicked()));

}


MainWindow::~MainWindow()
{
    delete ui;
}


//展示商品信息
void MainWindow::goodsInfoShow()
{
    //商城界面
    model = new QSqlTableModel;
    model->setTable("productInfo");
    model->setHeaderData(1,Qt::Horizontal,"商品名称");
    model->setHeaderData(2,Qt::Horizontal,"品类");
    model->setHeaderData(3,Qt::Horizontal,"原价");
    model->setHeaderData(4,Qt::Horizontal,"库存量");
    model->setHeaderData(5,Qt::Horizontal,"折扣力度");
    model->setHeaderData(6,Qt::Horizontal,"其它");
    model->setHeaderData(7,Qt::Horizontal,"简介");
    model->select();
    ui->GoodsTableView->setModel(model);
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

    QSqlQuery query;
    query.exec("SELECT * FROM onSaleInfo");
    if(query.next())
    {
        if(query.value(1).toString()=="YES")
        {
            GlobalInfo::instance()->setIsFRstart(true);
            GlobalInfo::instance()->setFull(query.value(2).toInt());
            GlobalInfo::instance()->setReduce(query.value(3).toInt());
        }
    }

    bool isFRstart = GlobalInfo::instance()->getIsFRstart();
    int Full = GlobalInfo::instance()->getFull();
    int Reduce = GlobalInfo::instance()->getReduce();
    if(isFRstart==true)
    {
        ui->fullThenReduceLabel->setText("满 "+QString::number(Full)+" 减 "+QString::number(Reduce)+" ");
    }


}


//按品类显示商品信息(分类效果)
void MainWindow::typeShowCombox_select()
{
    int type = ui->typeShowComboBox->currentIndex();
    switch(type)
    {
    case 0:
        model->setFilter("");
        model->select();
        break;
    case Product::BOOK:
        model->setFilter("type = 'BOOK'");
        model->select();
        break;
    case Product::CLOTH:
        model->setFilter("type = 'CLOTH'");
        model->select();
        break;
    case Product::FOOD:
        model->setFilter("type = 'FOOD'");
        model->select();
        break;
    case Product::PHONE:
        model->setFilter("type = 'PHONE'");
        model->select();
        break;
    default:
        break;
    }
}


//按价格(高或低或默认)排序显示商品信息
void MainWindow::sortCombox_select()
{
    int sortMethod = ui->sortComboBox->currentIndex();
    switch(sortMethod)
    {
    case 1:
        ui->GoodsTableView->sortByColumn(3,Qt::AscendingOrder);
        break;
    case 2:
        ui->GoodsTableView->sortByColumn(3,Qt::DescendingOrder);
        break;
    default://默认排序
        ui->GoodsTableView->sortByColumn(0,Qt::AscendingOrder);
        break;
    }
}


//实现文本信息的模糊搜索，名称、其它、描述
void MainWindow::searchButton_clicked()
{
    QString nameTemp = ui->searchByNameLineEdit->text();
    if(nameTemp.isEmpty())
    {
        model->setFilter("");
    }
    else
    {
        model->setFilter(QObject::tr("name LIKE '%%1%' OR other LIKE '%%1%' OR description LIKE '%%1%'").arg(nameTemp));
    }
    model->select();
}


//登入信息
void MainWindow::loginEntryButton_clicked()
{
    if(GlobalInfo::instance()->getIsLogin() == false)
    {
        //弹出登入对话框，进行信息输入
        LoginDialog *loginDialogPtr = new LoginDialog(this);
        loginDialogPtr->exec();

        if(GlobalInfo::instance()->getIsLogin() == true)
        {//登陆成功，购物车界面
            updateUserInfo();

            QString userPhoneNum = GlobalInfo::instance()->getUserNum();

            //我的购物车信息显示
            modelCart = new QSqlTableModel;

            modelCart->setTable("cartInfo");
            modelCart->setHeaderData(1,Qt::Horizontal,"商品名称");
            modelCart->setHeaderData(2,Qt::Horizontal,"品类");
            modelCart->setHeaderData(3,Qt::Horizontal,"原价");
            modelCart->setHeaderData(4,Qt::Horizontal,"现价");
            modelCart->setHeaderData(5,Qt::Horizontal,"数量");
            modelCart->setFilter("userPhoneNum = '"+userPhoneNum+"'");
            modelCart->select();
            ui->CartTableView->setModel(modelCart);
            ui->CartTableView->setColumnHidden(0,true);//隐藏商品id
            ui->CartTableView->setColumnHidden(6,true);//隐藏用户账号
            ui->CartTableView->setColumnWidth(1,130);
            ui->CartTableView->setColumnWidth(2,130);
            ui->CartTableView->setColumnWidth(3,130);
            ui->CartTableView->setColumnWidth(4,130);
            ui->CartTableView->setColumnWidth(5,130);
            QHeaderView *header = ui->CartTableView->horizontalHeader();
            header->setStretchLastSection(true);
            ui->CartTableView->show();

            //银行卡栏显示
            modelAccount = new QSqlTableModel;
            modelAccount->setTable("cardInfo");
            modelAccount->setHeaderData(0,Qt::Horizontal,"卡号");
            modelAccount->setFilter("userPhoneNum = '"+userPhoneNum+"'");       //找到当前用户的卡号信息
            modelAccount->select();
            ui->bankAccountTableView->setModel(modelAccount);
            ui->bankAccountTableView->setColumnHidden(1,true);                  //隐藏用户账号
            ui->bankAccountTableView->setColumnWidth(0,320);
            ui->bankAccountTableView->show();

            //计算购物车内所有商品的价格信息
            calPayLabelShow();
        }

    }
    else
    {//变为注销键处理事件
        QMessageBox message(QMessageBox::Question,"YESorNO","是否注销当前用户",QMessageBox::Yes|QMessageBox::No,this);

        if (message.exec()==QMessageBox::Yes)
        {
            GlobalInfo::instance()->setIsLogin(false);

            updateUserInfo();
            updateCartInfo();
            updateAccountInfo();
        }
        else
        {
            return;
        }
    }
}


//进入注册界面
void MainWindow::registerEntryButton_clicked()
{
    RegisterDialog *registerDialogPtr = new RegisterDialog(this);
    registerDialogPtr->exec();
}


//进入管理员用户界面
void MainWindow::manageEntryButton_clicked()
{
    ManageDialog *manageDialogPtr = new ManageDialog(this);
    manageDialogPtr->exec();

    //更新商品信息显示与购物车信息显示
    updateGoodsInfo();
    updateCartInfo();

    bool isFRstart = GlobalInfo::instance()->getIsFRstart();
    if(isFRstart==true) //满减活动开始了
    {
        int Full = GlobalInfo::instance()->getFull();
        int Reduce  = GlobalInfo::instance()->getReduce();
        ui->fullThenReduceLabel->setText("满 "+QString::number(Full)+" 减 "+QString::number(Reduce)+" ");
    }
    else                //满减活动未开始
    {
        ui->fullThenReduceLabel->setText("XXXXXXXXX");  //屏蔽显示
    }
}


//建立数据库连接
void MainWindow::createConnect(bool isExist)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("allInfo.db");

    if(!db.open())
    {//数据库打开失败
        QMessageBox::critical(this,QObject::tr("数据库错误"),db.lastError().text());
        return;
    }

    QSqlQuery query(db);

    if(!isExist)//数据库不存在，则新建数据库，下面是各个表结构
    {
        query.exec("CREATE TABLE userInfo ("
                   "phoneNum VARCHAR PRIMARY KEY,"
                   "name VARCHAR,"
                   "password VARCHAR )");
        query.exec("CREATE TABLE productInfo ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "name VARCHAR,"
                   "type VARCHAR,"
                   "originalPrice VARVHAR,"
                   "inventory INT,"
                   "rate REAL,"
                   "other VARCHAR,"
                   "description TEXT )");
        query.exec("CREATE TABLE cartInfo ("
                   "id INT,"
                   "name VARCHAR,"
                   "type VARCHAR,"
                   "oriPrice REAL,"
                   "price REAL,"
                   "quantity INT,"
                   "userPhoneNum VARCHAR)");
        query.exec("CREATE TABLE cardInfo ("
                   "accountNum VARCHAR,"
                   "userPhoneNum VARCHAR)");
        query.exec("CREATE TABLE onSaleInfo ("
                   "label VARCHAR,"
                   "isStart VARCHAR,"
                   "full INT,"
                   "reduce INT)");
        query.prepare("INSERT INTO onSaleInfo ( label, isStart, full, reduce)"
                      "VALUES ( ?, ?, ? ,?)");
        query.bindValue(0,"FullThenReduce");
        query.bindValue(1,"FALSE");
        query.bindValue(2,QString::number(0));
        query.bindValue(3,QString::number(0));
        query.exec();

    }
}


//更新主界面用户信息
void MainWindow::updateUserInfo()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    QString userPhoneNum = GlobalInfo::instance()->getUserNum();

    if(isLogin == true)
    {
        ui->loginEntryButton->setText("注销");
        QSqlQuery query;
        query.exec("SELECT * FROM userInfo WHERE phoneNum = '"+userPhoneNum+"'");
        if(query.next())//显示用户信息
        {
            ui->nameLabel->setText(query.value(1).toString());
            ui->phoneLabel->setText(userPhoneNum);
        }
        else
        {
            return;
        }

        query.clear();
    }
    else
    {
        ui->loginEntryButton->setText("登录");
        ui->nameLabel->setText("未登录");
        ui->phoneLabel->setText("未登录");
        //ui->CartTableView->clearSpans();
    }
}


//计算购物车内总体价格信息
void MainWindow::calPayLabelShow()
{
    QString userPhoneNum = GlobalInfo::instance()->getUserNum();
    bool isFRstart = GlobalInfo::instance()->getIsFRstart();

    double oriPriceSum = 0.0;
    double priceSum = 0.0;
    double paySum = 0.0;

    QSqlQuery query;
    query.exec("SELECT * FROM cartInfo WHERE userPhoneNum = "+userPhoneNum);
    while (query.next())
    {
        oriPriceSum += query.value(3).toFloat()*query.value(5).toInt();
        priceSum += query.value(4).toFloat()*query.value(5).toInt();
    }
    //qDebug()<<priceSum;
    ui->oriPriceSumLabel->setText(QString::number(oriPriceSum));
    ui->priceSumLabel->setText(QString::number(priceSum));

    if(isFRstart==true)
    {
        int Full = GlobalInfo::instance()->getFull();
        int Reduce = GlobalInfo::instance()->getReduce();

        paySum = priceSum - (int)(priceSum/Full)*Reduce;
        ui->paySumLabel->setText(QString::number(paySum));
    }
    else
    {
        paySum = priceSum;
        ui->paySumLabel->setText(QString::number(paySum));
    }
}


void MainWindow::updateCartInfo()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();

    //购物车界面
    if(isLogin==true)
    {
        modelCart->setFilter("userPhoneNum = '"+GlobalInfo::instance()->getUserNum()+"'");
        modelCart->select();
        calPayLabelShow();
    }
    else
    {
        //清空购物车界面
        ui->CartTableView->setModel(NULL);
        ui->CartTableView->clearSpans();
        ui->oriPriceSumLabel->setText("XXXXXXXXX");
        ui->paySumLabel->setText("XXXXXXXXX");
        ui->priceSumLabel->setText("XXXXXXXXX");
    }
}

void MainWindow::updateAccountInfo()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin==true)
    {
        modelAccount->select();
    }
    else
    {//清空银行卡窗口信息
        ui->bankAccountTableView->setModel(NULL);
        ui->bankAccountTableView->clearSpans();
    }
}


void MainWindow::updateGoodsInfo()
{
    model->select();
}


//首页添加购物车按钮事件
void MainWindow::addToCartButton_clicked()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin == true)
    {
        int row = ui->GoodsTableView->currentIndex().row();
        int idTemp = model->data(model->index(row,0)).toInt();
        //QString nameTemp = model->data(model->index(row,1)).toString();
        //qDebug()<<nameTemp;
        addToCartDialog *addToCartDialogPtr = new addToCartDialog(this,idTemp);
        addToCartDialogPtr->exec();
        updateCartInfo();
    }
    else
    {
        QMessageBox::warning(this, "Error","请先登录!!", QMessageBox::Yes | QMessageBox::Yes);
    }
}


//修改购物车内商品数量按钮事件
void MainWindow::modifyQuantityButton_clicked()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin==true)
    {
        int row = ui->CartTableView->currentIndex().row();

        if(row == -1)
        {
            QMessageBox::warning(this, "Error","请选择物品以修改数量", QMessageBox::Yes | QMessageBox::Yes);
            return;
        }

        int idTemp = modelCart->data(modelCart->index(row,0)).toInt();
        //qDebug()<<idTemp;
        int quantityTemp = modelCart->data(modelCart->index(row,5)).toInt();
        modifyQuantityDialog *modifyQuantityPtr = new modifyQuantityDialog(this,idTemp,quantityTemp);
        modifyQuantityPtr->exec();
        updateCartInfo();
    }
    else
    {
        QMessageBox::warning(this, "Error","请先登录!!", QMessageBox::Yes | QMessageBox::Yes);
    }
}


//删除购物车内选中物品
void MainWindow::deleteButton_clicked()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin==true)
    {
        int row = ui->CartTableView->currentIndex().row();

        if(row == -1)
        {
            QMessageBox::warning(this, "Error","请选择物品删除", QMessageBox::Yes | QMessageBox::Yes);
            return;
        }

        QMessageBox message(QMessageBox::Question,"YESorNO","确认删除此物品?",QMessageBox::Yes|QMessageBox::No,this);

        if (message.exec()==QMessageBox::Yes)
        {

            modelCart->removeRow(row);//删除该行
            modelCart->submitAll();//提交数据库，同步
            modelCart->select();
            calPayLabelShow();
        }
        else
        {
            return;
        }
    }
    else
    {
        QMessageBox::warning(this, "Error","请先登录!!", QMessageBox::Yes | QMessageBox::Yes);
    }
}


//选择购物车内商品(可多选)，提交订单
void MainWindow::submitButton_clicked()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin==true)
    {
        QItemSelectionModel *selections = ui->CartTableView->selectionModel();
        QModelIndexList selected = selections->selectedIndexes();

        if(selected.isEmpty())
        {
            QMessageBox::warning(this, "Error","请在购物车界面内选中要支付的物品", QMessageBox::Yes | QMessageBox::Yes);
            return;
        }

        QSqlQuery query;

        QVector<Product *> productItems;//存产品类指针
        QVector<int> rowList;//存在购物车中的位置
        QVector<int> idList;//存物品id
        QVector<int> quantities;//存物品数量
        foreach (QModelIndex index, selected)
        {
            if(index.column()==0)
            {
                int row = index.row();
                rowList.push_back(row);
                int id = modelCart->data(modelCart->index(row,0)).toInt();
                idList.push_back(id);
                int quantity = modelCart->data(modelCart->index(row,5)).toInt();
                quantities.push_back(quantity);

                query.exec("SELECT * FROM productInfo where id = "+QString::number(id));

                if(query.next())
                {
                    QString name = query.value(1).toString();
                    QString typeStr = query.value(2).toString();
                    float oriPrice = query.value(3).toFloat();
                    int inventory = query.value(4).toInt();
                    float rate = query.value(5).toFloat();
                    QString other = query.value(6).toString();
                    QString description = query.value(7).toString();

                    if(inventory<quantity)
                    {
                        QMessageBox::warning(this, "SubmitError",name+"库存不足", QMessageBox::Yes | QMessageBox::Yes);
                        return;
                    }

                    if(typeStr=="BOOK")
                    {
                        productItems.push_back(new Book(name,description,oriPrice,inventory,rate,other));

                    }
                    else if(typeStr=="CLOTH")
                    {
                        productItems.append(new Cloth(name,description,oriPrice,inventory,rate,other));
                    }
                    else if(typeStr=="FOOD")
                    {
                        productItems.append(new Food(name,description,oriPrice,inventory,rate,other));
                    }
                    else
                    {
                        productItems.append(new Phone(name,description,oriPrice,inventory,rate,other));
                    }


                }
            }


        }

        PayDialog *payDialogPtr = new PayDialog(this,productItems,quantities);
        payDialogPtr->exec();

        bool isPayed = GlobalInfo::instance()->getIsPayed();    //是否支付成功
        if(isPayed == true)
        {//支付成功,将购物车内相应商品移除
            int n = rowList.size();
            for(int i=0;i<n;++i)
            {
                modelCart->removeRow(rowList[i]);

                //更新库存
                int inventoryTemp = productItems[i]->getInventory() - quantities[i];
                query.exec("UPDATE productInfo SET inventory = "+QString::number(inventoryTemp)+" WHERE id = "+QString::number(idList[i]));

            }
            model->select();
            modelCart->select();

            calPayLabelShow();

            GlobalInfo::instance()->setIsPayed(false);
        }

        productItems.clear();
        rowList.clear();
        idList.clear();
        quantities.clear();

    }
    else
    {
        QMessageBox::warning(this, "Error","请先登录!!", QMessageBox::Yes | QMessageBox::Yes);
    }
}


//修改用户基本信息
void MainWindow::modifyUserInfoButton_clicked()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin==true)
    {
        modifyUserInfoDialog *mUserInfoPtr = new modifyUserInfoDialog(this);
        mUserInfoPtr->exec();
        updateUserInfo();
    }
    else
    {
        QMessageBox::warning(this, "Error","请先登录!!", QMessageBox::Yes | QMessageBox::Yes);
    }
}


void MainWindow::accountMagButton_clicked()//银行卡管理,第三题
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin==true)
    {
        accountManageDialog *accountMagPtr = new accountManageDialog(this);
        accountMagPtr->exec();

        //更新银行卡界面
        modelAccount->select();
    }
    else
    {
        QMessageBox::warning(this, "Error","请先登录!!", QMessageBox::Yes | QMessageBox::Yes);
    }
}

void MainWindow::disBindingButton_clicked()
{
    bool isLogin = GlobalInfo::instance()->getIsLogin();
    if(isLogin==true)
    {
        int row = ui->bankAccountTableView->currentIndex().row();

        if(row == -1)
        {
            QMessageBox::warning(this, "Error","请选择解绑银行卡", QMessageBox::Yes | QMessageBox::Yes);
            return;
        }

        QMessageBox message(QMessageBox::Question,"YESorNO","确认解绑此卡?",QMessageBox::Yes|QMessageBox::No,this);

        if (message.exec()==QMessageBox::Yes)
        {

            modelAccount->removeRow(row);//删除该行
            modelAccount->submitAll();//提交数据库，同步

            //更新页面
            modelAccount->select();
        }
        else
        {
            return;
        }
    }
    else
    {
        QMessageBox::warning(this, "Error","请先登录!!", QMessageBox::Yes | QMessageBox::Yes);
    }
}

