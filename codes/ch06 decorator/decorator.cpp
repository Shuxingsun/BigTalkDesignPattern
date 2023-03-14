//
// Created by sunchanghui on 2023/3/13.
//С�˵ڶ������
//

#include "decorator.h"
#include "iostream"

using namespace std;

class Person:public Human
{
public:
    explicit Person(string name)
    {
        m_name = name;
    }
    void show() override
    {
        cout << "װ���" << m_name << endl;
    }
};

void Finery::decorate(Human *component)
{
    m_component = component;
}
void Finery::show()
{
    m_component->show();
}

class Tshirts:public Finery
{
public:
    void show() override
    {
        cout << "��Tѥ" <<endl;
        Finery::show();
    }
};
class BigTrousher:public Finery
{
public:
    void show() override
    {
        cout << "��� ";
        Finery::show();
    }
};
class Sneakers: public Finery
{
public:
    void show() override
    {
        cout << "����Ь ";
        Finery::show();
    }
};

class LeatherShoes: public Finery
{
public:
    void show() override
    {
        cout << "ƤЬ ";
        Finery::show();
    }
};

class Tie: public Finery
{
public:
    void show() override
    {
        cout << "��� ";
        Finery::show();
    }
};

class Suit: public Finery
{
public:
    void show() override
    {
        cout << "��װ ";
        Finery::show();
    }
};
int main()
{
    try {
        Person *xc = new Person("С��");

        cout << "��һ��װ�磺" << endl;
        Sneakers *pqx = new Sneakers();
        BigTrousher *kk = new BigTrousher();
        Tshirts *dtx = new Tshirts();
        pqx->decorate(xc);
        kk->decorate(pqx);
        dtx->decorate(kk);
        dtx->show();

        cout << "�ڶ���װ�磺" << endl;
        LeatherShoes *px = new LeatherShoes();
        Tie *ld = new Tie();
        Suit *xz = new Suit();
        px->decorate(xc);
        ld->decorate(px);
        xz->decorate(ld);
        xz->show();

        cout << "������װ�磺" << endl;
        Sneakers *pqx2 = new Sneakers();
        LeatherShoes *px2 = new LeatherShoes();
        BigTrousher *kk2 = new BigTrousher();
        Tie *ld2 = new Tie();
        pqx2->decorate(xc);
        px2->decorate(pqx);
        kk2->decorate(px2);
        ld2->decorate(kk2);
        ld2->show();
    }
    catch(char *msg)
    {
        cerr << msg << endl;
    }


}