//
// Created by sunchanghui on 2023/3/13.
//

#ifndef BIGTALKDESIGNPATTERN_CASH_H
#define BIGTALKDESIGNPATTERN_CASH_H

#include "iostream"
class Cash
{
public:
    virtual double acceptCash(double money) const = 0;
};

#endif //BIGTALKDESIGNPATTERN_CASH_H
