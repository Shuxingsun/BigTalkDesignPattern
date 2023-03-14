//
// Created by sunchanghui on 2023/3/14.
//

#include "Leifeng.h"
#include "iostream"
using namespace std;
void Leifeng::swap()
{
    cout<< "ɨ��" << endl;
}

void Leifeng::swash()
{
    cout << "ϴ�·�" << endl;
}
void Leifeng::buyRice()
{
    cout << "����" << endl;
}

class Undergraduate:public Leifeng{};

class Volunteer:public Leifeng{};

//��ѧ������
class UndergraduateLeifeng:public iLeifeng
{
public:
    UndergraduateLeifeng(){};
    Leifeng* createLeifeng() const override
    {
        cout << "��ѧ��" << endl;
        return new Undergraduate();
    }
};
//����־Ը�߹���
class VolunteerLeiFeng: public iLeifeng
{
public:
    VolunteerLeiFeng(){};
    Leifeng * createLeifeng() const override
    {
        cout << "����־Ը��" << endl;
        return new Volunteer();
    }
};
int main()
{
    try
    {
        iLeifeng * factory = new UndergraduateLeifeng(); //���������޸Ĺ�����
        Leifeng * stu_or_vol = factory->createLeifeng();
        stu_or_vol->swap();
        stu_or_vol->swash();
        stu_or_vol->buyRice();
    }
    catch(char * msg)
    {
        cerr << msg << endl;
    }
    return 0;
}