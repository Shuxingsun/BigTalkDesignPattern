//
// Created by sunchanghui on 2023/3/23.
//
#include "Raise.h"
int main()
{
    CommonManager * jinli = new CommonManager("金利");
    Majordomo * zongjian = new Majordomo("中建");
    GeneralManager * zongjingli = new GeneralManager("钟精励");

//    设置上级
    jinli->SetSuperior(zongjian);
    zongjian->SetSuperior(zongjingli);

    Request * request = new Request();
    request->setRequestType("请假");
    request->setRequestContent("小菜请假");
    request->setNumber(1);
    jinli->RequestApplications(request);

    Request * request2 = new Request();
    request2->setRequestType("请假");
    request2->setRequestContent("小菜请假");
    request2->setNumber(4);
    jinli->RequestApplications(request2);

    Request * request3 = new Request();
    request3->setRequestType("加薪");
    request3->setRequestContent("小菜请求加薪");
    request3->setNumber(500);
    jinli->RequestApplications(request3);

    Request * request4 = new Request();
    request4->setRequestType("加薪");
    request4->setRequestContent("小菜请求加薪");
    request4->setNumber(1000);
    jinli->RequestApplications(request4);

    return 0;
}