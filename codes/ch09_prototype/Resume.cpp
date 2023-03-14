//
// Created by sunchanghui on 2023/3/14.
//
//深复制

#include "Resume.h"
#include<iostream>
using namespace std;

//原型类--工作经历实现Icloneable
class WorkExperience:public ICloneable
{
public:
    void setWorkDate(string workDate)
    {
        m_workDate = workDate;
    }
    void setCompany(string company)
    {
        m_company = company;
    }
    string getWorkdate()
    {
        return m_workDate;
    }
    string getCompany()
    {
        return m_company;
    }
    //工作经历类实现克隆方法
    WorkExperience * clone() const override
    {
        return new WorkExperience(*this);
    }
private:
    string m_workDate;
    string m_company;
};
// 具体原型类，即ConcretePrototype类，本例中为简历Resume类，实现一个克隆自身的操作
class Resume:public ICloneable
{
public:
    Resume(string name)
    {
        m_name = name;
        m_work = new WorkExperience(); //简历实例化同时 实例化工作经历
    }
    //提供clone方法调用的私有构造函数，以便克隆工作经历的数据
    Resume(WorkExperience * work)
    {
        m_work = work->clone();
    }
    void setPersonalInfo(string sex,string age)
    {
        m_sex = sex;
        m_age = age;
    }
    void setWorkExperience(string workDate,string company)
    {
        m_work->setWorkDate(workDate);
        m_work->setCompany(company);
    }
    void display()
    {
        cout << m_name << " " << m_sex << " " << m_age << endl;
        cout << "工作经历：" << m_work->getWorkdate() << " " << m_work->getCompany() << endl;
    }
    /*
     * 调用私有的构造方法，让工作经理克隆完成，然后再给这个简历最终返回一个 深复制  的奖励对象
    */
    Resume * clone() const override
    {
        Resume* obj = new Resume(m_work);
        obj->m_name = m_name;
        obj->m_sex = m_sex;
        obj->m_age = m_age;
        return obj;

    }
private:
    string m_name;
    string m_sex;
    string m_age;
    WorkExperience * m_work;
};

int main()
{
    Resume* a = new Resume("大鸟");
    a->setPersonalInfo("male","29");
    a->setWorkExperience("1998-2000","xx公司");

    Resume * b = a->clone();
    b->setWorkExperience("1998-2006", "YY企业");

    Resume * c = a->clone();
    c->setPersonalInfo("男", "24");
    c->setWorkExperience("1998-2003", "ZZ企业");

    a->display();
    b->display();
    c->display();

    return 0;
}