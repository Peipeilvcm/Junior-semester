#include "productfactory.h"

ProductFactory::ProductFactory()
{

}

//根据类型不同，建造相应商品实例
Product* ProductFactory::CreateProduct(int type)
{
    Product *p;
    switch(type)
    {
    case Product::BOOK:
        p = new Book();
        break;
    case Product::CLOTH:
        p = new Cloth();
        break;
    case Product::FOOD:
        p = new Food();
        break;
    case Product::PHONE:
        p = new Phone();
        break;
    default:
        p = NULL;
        break;
    }
    return p;
}
