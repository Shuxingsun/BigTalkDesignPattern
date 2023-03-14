//
// Created by sunchanghui on 2023/3/14.
//
//���

#include "Resume.h"
#include<iostream>
using namespace std;

//ԭ����--��������ʵ��Icloneable
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
    //����������ʵ�ֿ�¡����
    WorkExperience * clone() const override
    {
        return new WorkExperience(*this);
    }
private:
    string m_workDate;
    string m_company;
};
// ����ԭ���࣬��ConcretePrototype�࣬������Ϊ����Resume�࣬ʵ��һ����¡����Ĳ���
class Resume:public ICloneable
{
public:
    Resume(string name)
    {
        m_name = name;
        m_work = new WorkExperience(); //����ʵ����ͬʱ ʵ������������
    }
    //�ṩclone�������õ�˽�й��캯�����Ա��¡��������������
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
        cout << "����������" << m_work->getWorkdate() << " " << m_work->getCompany() << endl;
    }
    /*
     * ����˽�еĹ��췽�����ù��������¡��ɣ�Ȼ���ٸ�����������շ���һ�� ���  �Ľ�������
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
    Resume* a = new Resume("����");
    a->setPersonalInfo("male","29");
    a->setWorkExperience("1998-2000","xx��˾");

    Resume * b = a->clone();
    b->setWorkExperience("1998-2006", "YY��ҵ");

    Resume * c = a->clone();
    c->setPersonalInfo("��", "24");
    c->setWorkExperience("1998-2003", "ZZ��ҵ");

    a->display();
    b->display();
    c->display();

    return 0;
}