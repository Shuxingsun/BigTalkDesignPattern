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
//    经理所能有的权限
    if(request->getRequestType() == "请教" && request->getNumber() <= 2)
    {
        cout << name << ":" <<request->getRequestContent();
        cout << "数量" << request->getNumber() << "被批准" << endl;
    }
    else
    {
//        其余的申请都需要转到上级
        if(this->superior != nullptr)
        {
            this->superior->RequestApplications(request);
        }
    }
}
Majordomo::Majordomo(const string &name) : Manager(name){}

void Majordomo::RequestApplications(Request *request)
{
    if(request->getRequestType() == "请教" && request->getNumber() <= 5)
    {
        cout << name << ":" << request->getRequestContent();
        cout << "数量" << request->getNumber() << "被批准" << endl;
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
    if(request->getRequestType() == "请假")
    {
        cout << name << ":" <<request->getRequestContent();
        cout << "数量" << request->getNumber() << "被批准" << endl;
     }
    else if (request->getRequestType() == "加薪" && request->getNumber() <= 500)
    {
        std::cout << name << "：" << request->getRequestContent();
        std::cout << " 数量" << request->getNumber() << " 被批准" << std::endl;
    }
    else if(request->getRequestType() == "加薪" && request->getNumber() > 500)
    {
        std::cout << name << "：" << request->getRequestContent();
        std::cout << " 数量" << request->getNumber() << " 再说吧" << std::endl;
    }
}