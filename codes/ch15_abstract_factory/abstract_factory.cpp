//
// Created by sunchanghui on 2023/3/19.
//
#include <iostream>
using namespace std;
// �����ƷDepartment ,��������Ʒ�Ĺ����ӿ�
class Department
{
public:
    virtual ~Department() = default;
    virtual void Insert() = 0;
    virtual Department* GetDepartment() = 0;

};
// ���������Ʒ��SqlserDepartment�� ���������ľ����Ʒ��
class SqlserveDepartment:public Department
{
    void Insert() override
    {
        cout << "��SQL Server �и� Department ������һ����¼��" << endl;
    }
    Department* GetDepartment() override
    {
        cout << "��SQL Server �и���ID �õ� Department ��һ����¼��" << endl;
        return nullptr;
    }
};
// ���������Ʒ��AccessDepartment�� ���������ľ����Ʒ��
class AccessDepartment:public Department
{
public:
    void Insert() override
    {
        cout << "�� Access �и� Department ������һ����¼��" << endl;
    }
    Department* GetDepartment() override
    {
        cout << "�� Access �и���ID �õ� Department ��һ����¼��" << endl;
        return nullptr;
    }
};
// �����ƷUser ,��������Ʒ�Ĺ����ӿ�
class User
{
public:
    virtual ~User() = default;
    virtual void Insert() = 0;
    virtual User* GetUser() = 0;
};
// ���������Ʒ��SqlserverUser�� ���������ľ����Ʒ��
class SqlserverUser:public User
{
public:
    void Insert()override
    {
        cout << "��SQL Server �и� User������һ����¼��" << endl;
    }
    User* GetUser()override
    {
        cout << "��SQL Server �и���ID �õ� User��һ����¼��" << endl;
        return nullptr;
    }

};
// ���������Ʒ��AccessUser�� ���������ľ����Ʒ��
class AccessUser:public User
{
public:
    void Insert() override
    {
        cout << "�� Access �и� User������һ����¼��" << endl;
    }
    User* GetUser() override
    {
        cout << "�� Access �и���ID �õ� User��һ����¼��" << endl;
        return nullptr;
    }

};
// ���󹤳�,������幤���Ĺ����ӿ�
class AbstractFactory  // ���󹤳�,������幤���Ĺ����ӿ�
{
public:
    virtual ~AbstractFactory() = default;
    virtual User* CreateUser() = 0;
    virtual Department* CreateDepartment() = 0;
};
// �������幤��SqlServerFactory,���崴����Ӧ�����Ʒʵ���ķ�����

class SqlserveFactory:public AbstractFactory
{
public:
    User* CreateUser() override
    {
        return new SqlserverUser(); //�ù��������Ĳ�Ʒ
    }
    Department* CreateDepartment() override
    {
        return new SqlserveDepartment;
    }
};
// �������幤��AccessFactory�����崴����Ӧ�����Ʒʵ���ķ�����
class AccessFactory:public AbstractFactory
{
public:
    User* CreateUser()override
    {
        return new AccessUser(); // �ù��� �����Ĳ�Ʒ
    }
    Department* CreateDepartment()override
    {
        return new AccessDepartment;
    }
};
int main()
{
    AbstractFactory* factory = new SqlserveFactory;
//    AbstractFactory* factory = new AccessFactory;
    User* iu = factory->CreateUser(); // ���õ��� AccessFactory ������׼������  SqlserverUser ��Ʒ
    iu->Insert();
    iu->GetUser();

    Department* id = factory->CreateDepartment(); // ���õ��� AccessFactory ������׼������  AccessDepartment ��Ʒ
    id->Insert();
    id->GetDepartment();

    delete factory;
    delete iu;
    delete id;
    factory = nullptr;
    iu = nullptr;
    id = nullptr;
    system("pause");
    return 0;

}