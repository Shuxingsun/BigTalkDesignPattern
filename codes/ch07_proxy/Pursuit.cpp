//
// Created by sunchanghui on 2023/3/14.
//

#include "Pursuit.h"
#include "iostream"
using namespace std;

class SchoolGirl
{
public:
    SchoolGirl(){};
    void setName(string name)
    {
        m_name = name;
    }
    string getName()
    {
        return m_name;
    }
private:
    string m_name;
};
//唯一变化就是让追求者去实现送礼物接口
class Pursuit:public IGiveGift
{
public:
    Pursuit(SchoolGirl * mm)
    {
        m_mm = mm;
    }
    void giveChoclocate() const override
     {
        cout << m_mm->getName() << "送你巧克力" << endl;
     }
     void giveFlowers() const override
    {
        cout << m_mm->getName() << "送你花" << endl;
    };
    void giveDolls() const override
    {
        cout << m_mm->getName() << "送你洋娃娃" << endl;
    }
private:
    SchoolGirl * m_mm;
};
//代理类去实现送礼物接口
class Proxy: public IGiveGift
{
public:
    Proxy(SchoolGirl * mm)
    {
        m_gg = new Pursuit(mm);
    }

    void giveDolls() const override
    {
        m_gg->giveDolls();  //在实现方法中去调用“追求者”类的相关方法
    }

    void giveFlowers() const override
    {
        m_gg->giveFlowers();
    }

    void giveChoclocate() const override
    {
        m_gg->giveChoclocate();
    }

private:
    Pursuit * m_gg;  //关键在这一步
};

int main()
{
    try
    {
        SchoolGirl * jiaojiao = new SchoolGirl();
        jiaojiao->setName("李娇娇");

        Proxy * dali = new Proxy(jiaojiao);
        dali->giveDolls();
        dali->giveFlowers();
        dali->giveChoclocate();
    }
    catch(char * msg)
    {
        cerr << msg << endl;
    }
    return 0;
}