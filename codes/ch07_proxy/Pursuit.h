//
// Created by sunchanghui on 2023/3/14.
//

#ifndef BIGTALKDESIGNPATTERN_PURSUIT_H
#define BIGTALKDESIGNPATTERN_PURSUIT_H

#include "iostream"
using namespace std;

class IGiveGift
{
public:

    IGiveGift(){};  //默认构造函数
    virtual void giveDolls() const = 0;
    virtual void giveFlowers() const = 0;
    virtual  void giveChoclocate() const = 0;
};

#endif //BIGTALKDESIGNPATTERN_PURSUIT_H
