//
// Created by sunchanghui on 2023/3/23.
//
#include "Raise.h"
#include <iostream>
#include<utility>

string Request::getRequestType()
{
    return requestType;
}
void Request::setRequestType(const string &value)
{
    this->requestType = value;
}
string Request::getRequestContent()
{
    return requestContent;
}
void Request::setRequestContent(const string &value)
{
    this->requestContent = value;
}
int Request::getNumber() const
{
    return this->number;
}

void Request::setNumber(const int &value)
{
    this->number = value;
}

CommonManager::CommonManager(const string &name) : Manager(name){}


void CommonManager::RequestApplications(Request *request)
{
//    ���������е�Ȩ��
    if(request->getRequestType() == "���" && request->getNumber() <= 2)
    {
        cout << name << ":" <<request->getRequestContent();
        cout << "����" << request->getNumber() << "����׼" << endl;
    }
    else
    {
//        ��������붼��Ҫת���ϼ�
        if(this->superior != nullptr)
        {
            this->superior->RequestApplications(request);
        }
    }
}
Majordomo::Majordomo(const string &name) : Manager(name){}

void Majordomo::RequestApplications(Request *request)
{
    if(request->getRequestType() == "���" && request->getNumber() <= 5)
    {
        cout << name << ":" << request->getRequestContent();
        cout << "����" << request->getNumber() << "����׼" << endl;
    }
    else
    {
        if(this->superior != nullptr)
        {
            this->superior->RequestApplications(request);
        }
    }
}

GeneralManager::GeneralManager(const string &name) : Manager(name) {}

void GeneralManager::RequestApplications(Request *request)
{
    if(request->getRequestType() == "���")
    {
        cout << name << ":" <<request->getRequestContent();
        cout << "����" << request->getNumber() << "����׼" << endl;
     }
    else if (request->getRequestType() == "��н" && request->getNumber() <= 500)
    {
        std::cout << name << "��" << request->getRequestContent();
        std::cout << " ����" << request->getNumber() << " ����׼" << std::endl;
    }
    else if(request->getRequestType() == "��н" && request->getNumber() > 500)
    {
        std::cout << name << "��" << request->getRequestContent();
        std::cout << " ����" << request->getNumber() << " ��˵��" << std::endl;
    }
}