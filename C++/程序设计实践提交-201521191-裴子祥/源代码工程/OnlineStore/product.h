#ifndef PRODUCT_H
#define PRODUCT_H

/*
 * 产品基类product
 * 有名字name，描述description，原价originalPrice
 * 库存量inventory
 *
 * 定义getPrice虚函数
 */

#include<QString>


class Product
{
public:
    //商品种类
    static const int BOOK = 1;
    static const int CLOTH = 2;
    static const int FOOD = 3;
    static const int PHONE = 4;
private:
    QString name;           //产品名称
    QString description;    //产品描述
    float originalPrice;    //原价
    int inventory;          //库存量

public:
    //构造函数
    Product();
    Product(QString s1,QString s2,float f,int i);

    //get、set函数
    QString getName();
    void setName(QString name);

    QString getDescroption();
    void setDescription(QString description);

    float getOriginalPrice();
    void setOriginalPrice(float originalPrice);

    int getInventory();
    void setInventory(int inventory);


    virtual float getPrice();//虚函数，用于计算具体产品的价格
    virtual QString getType();//获得产品的品类信息
    virtual QString toString();//获得不同品类商品的其它信息
};

#endif // PRODUCT_H
