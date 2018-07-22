#ifndef CART_H
#define CART_H

#include "book.h"
#include "cloth.h"
#include "food.h"
#include "phone.h"
#include "product.h"
#include <QVector>

class Cart
{
private:
    QVector<Product> productList;
    int full;//满多少
    int reduce;//减多少
    bool isStart;//满减活动是否开始
public:
    Cart();
    Cart(int full, int reduce, bool isStart);
    ~Cart();

    int getFull();
    int getReduce();
    void setFull(int full);
    void setReduce(int reduce);

    void addToCart(Product *productPtr);
    void delFromCart(int i);
};

#endif // CART_H
