//
// Created by sunchanghui on 2023/3/23.
//
#include "Raise.h"
int main()
{
    CommonManager * jinli = new CommonManager("����");
    Majordomo * zongjian = new Majordomo("�н�");
    GeneralManager * zongjingli = new GeneralManager("�Ӿ���");

//    �����ϼ�
    jinli->SetSuperior(zongjian);
    zongjian->SetSuperior(zongjingli);

    Request * request = new Request();
    request->setRequestType("���");
    request->setRequestContent("С�����");
    request->setNumber(1);
    jinli->RequestApplications(request);

    Request * request2 = new Request();
    request2->setRequestType("���");
    request2->setRequestContent("С�����");
    request2->setNumber(4);
    jinli->RequestApplications(request2);

    Request * request3 = new Request();
    request3->setRequestType("��н");
    request3->setRequestContent("С�������н");
    request3->setNumber(500);
    jinli->RequestApplications(request3);

    Request * request4 = new Request();
    request4->setRequestType("��н");
    request4->setRequestContent("С�������н");
    request4->setNumber(1000);
    jinli->RequestApplications(request4);

    return 0;
}