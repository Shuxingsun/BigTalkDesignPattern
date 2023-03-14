//
// Created by sunchanghui on 2023/3/14.
//

#ifndef BIGTALKDESIGNPATTERN_LEIFENG_H
#define BIGTALKDESIGNPATTERN_LEIFENG_H

#include "iostream"
using namespace std;

class Leifeng
{
public:
    Leifeng(){};
    void swap();
    void swash();
    void buyRice();
};

class iLeifeng
{
public:
    iLeifeng(){};
    virtual Leifeng * createLeifeng() const = 0;
};

#endif //BIGTALKDESIGNPATTERN_LEIFENG_H
