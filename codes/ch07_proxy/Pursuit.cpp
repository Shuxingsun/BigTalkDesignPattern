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
//Ψһ�仯������׷����ȥʵ��������ӿ�
class Pursuit:public IGiveGift
{
public:
    Pursuit(SchoolGirl * mm)
    {
        m_mm = mm;
    }
    void giveChoclocate() const override
     {
        cout << m_mm->getName() << "�����ɿ���" << endl;
     }
     void giveFlowers() const override
    {
        cout << m_mm->getName() << "���㻨" << endl;
    };
    void giveDolls() const override
    {
        cout << m_mm->getName() << "����������" << endl;
    }
private:
    SchoolGirl * m_mm;
};
//������ȥʵ��������ӿ�
class Proxy: public IGiveGift
{
public:
    Proxy(SchoolGirl * mm)
    {
        m_gg = new Pursuit(mm);
    }

    void giveDolls() const override
    {
        m_gg->giveDolls();  //��ʵ�ַ�����ȥ���á�׷���ߡ������ط���
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
    Pursuit * m_gg;  //�ؼ�����һ��
};

int main()
{
    try
    {
        SchoolGirl * jiaojiao = new SchoolGirl();
        jiaojiao->setName("���");

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