//
// Created by sunchanghui on 2023/3/14.
//

#include "Leifeng.h"
#include "iostream"
using namespace std;
void Leifeng::swap()
{
    cout<< "扫地" << endl;
}

void Leifeng::swash()
{
    cout << "洗衣服" << endl;
}
void Leifeng::buyRice()
{
    cout << "买米" << endl;
}

class Undergraduate:public Leifeng{};

class Volunteer:public Leifeng{};

//大学生工厂
class UndergraduateLeifeng:public iLeifeng
{
public:
    UndergraduateLeifeng(){};
    Leifeng* createLeifeng() const override
    {
        cout << "大学生" << endl;
        return new Undergraduate();
    }
};
//社区志愿者工厂
class VolunteerLeiFeng: public iLeifeng
{
public:
    VolunteerLeiFeng(){};
    Leifeng * createLeifeng() const override
    {
        cout << "社区志愿者" << endl;
        return new Volunteer();
    }
};
int main()
{
    try
    {
        iLeifeng * factory = new UndergraduateLeifeng(); //这里随意修改工厂类
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