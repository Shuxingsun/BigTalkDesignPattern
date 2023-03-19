//
// Created by sunchanghui on 2023/3/17.
//

#ifndef BIGTALKDESIGNPATTERN_FUND_H
#define BIGTALKDESIGNPATTERN_FUND_H
class Stock1
{
public:
    void sell();
    void buy();
};
class Stock2
        {
                public:
                void sell();
                void buy();
        };

class Stock3
{
public:
    void sell();
    void buy();
};

class NationalDebt1
{
public:
    void sell();
    void buy();
};

class Realty1
{
public:
    void sell();
    void buy();
};
/*
 *基金类 类似外观类
 * 它需要了解所有的股票或其他投资方式的方法或属性
 * */
class Fund
{
public:
    Fund()
    {
        m_gu1 = new Stock1();
        m_gu2 = new Stock2();
        m_gu3 = new Stock3();
        m_nd1 = new NationalDebt1();
        m_rt1 = new Realty1();
    }
    void buyFund();
    void sellFund();

private:
    Stock1 * m_gu1;
    Stock2 * m_gu2;
    Stock3 * m_gu3;
    NationalDebt1 * m_nd1;
    Realty1 * m_rt1;

};

#endif //BIGTALKDESIGNPATTERN_FUND_H
