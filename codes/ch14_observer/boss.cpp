//
// Created by sunchanghui on 2023/3/17.
//

#include "boss.h"
#include <iostream>
using namespace std;

void Boss::attach(Observer * obj)
{
    m_objs.push_back(obj);
}


void Boss::detach(Observer * obj)
{
    m_objs.remove(obj);
}

void Boss::notify()
{
    for (auto const& o: m_objs)
    {
        o->update();
    }
}

void StockObserver::update()
{
    cout << m_sub->getState() << m_name << " �رչ�Ʊ���飬����������" << endl;
}


void NBAObserver::update()
{
    cout << m_sub->getState() << m_name << " �ر�NBAֱ��������������" << endl;
}


int main()
{
    Boss * huhansan = new Boss();
    StockObserver * tongshi1 = new StockObserver("κ���", huhansan);
    NBAObserver * tongshi2 = new NBAObserver("�׹ܲ�", huhansan);

    huhansan->attach(tongshi1);
    huhansan->attach(tongshi2);

    huhansan->detach(tongshi1);

    huhansan->setState("�Һ����������ˣ�");
    huhansan->notify();

    return 0;
}

