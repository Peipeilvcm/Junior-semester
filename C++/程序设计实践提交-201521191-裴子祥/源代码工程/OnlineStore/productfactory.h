#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include"product.h"
#include"book.h"
#include"food.h"
#include"cloth.h"
#include"phone.h"

//商品构造工厂
class ProductFactory
{
public:
    ProductFactory();
public:
    static Product *CreateProduct(int type);
};

#endif // PRODUCTFACTORY_H
