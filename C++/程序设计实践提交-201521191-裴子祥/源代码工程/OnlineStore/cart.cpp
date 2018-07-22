#include "cart.h"


//购物车类实现

Cart::Cart()
{
    isStart = false;
}

Cart::Cart(int full, int reduce , bool isStart)
{
    this->full = full;
    this->reduce = reduce;
    this->isStart = isStart;
}

Cart::~Cart()
{
    productList.clear();
    isStart = false;
}

int Cart::getFull()
{
    return full;
}

int Cart::getReduce()
{
    return reduce;
}

void Cart::setFull(int full)
{
    this->full = full;
}

void Cart::setReduce(int reduce)
{
    this->reduce = reduce;
}

void Cart::addToCart(Product *productPtr)
{
    productList.append(*productPtr);
}

void Cart::delFromCart(int i)
{
    productList.remove(i);
}

