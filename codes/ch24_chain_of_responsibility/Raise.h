//
// Created by sunchanghui on 2023/3/23.
//

#ifndef BIGTALKDESIGNPATTERN_RAISE_H
#define BIGTALKDESIGNPATTERN_RAISE_H

#include <string>
using namespace std;

class Manager;
//����
class Request
{
private:
    string requestType;
    string requestContent;
    int number;
public:
    string getRequestType();
    void setRequestType(const string &value);

    string getRequestContent();
    void setRequestContent(const string &value);

    int getNumber() const;
    void setNumber(const int &value);
};
//������
class Manager
{
protected:
    string  name;
    //�����ߵ��ϼ�
    Manager * superior{};
public:
    explicit Manager(string name);
    void SetSuperior(Manager  * superior);
    virtual void RequestApplications(Request *request) = 0;
};
//����
class CommonManager:public Manager
{
public:
    explicit CommonManager(const string &name);
    void RequestApplications(Request *request) override;
};
//�ܼ�
class Majordomo:public Manager
{
public:
    explicit Majordomo(const string &name);
    void RequestApplications(Request *request) override;
};
//�ܾ���
class GeneralManager:public Manager
{
    void RequestApplications(Request *request) override;

public:
    explicit GeneralManager(const string &name);
};




#endif //BIGTALKDESIGNPATTERN_RAISE_H
