//
// Created by sunchanghui on 2023/3/15.
//

#include "TestPaper.h"
#include "iostream"
using namespace std;

void TestPaper::testQuestion1()
{
    cout << "����õ����������˹������������콣��������������������[ ] a.��ĥ���� b.����� c.���ٺϽ�� d.̼����ά" << endl;
    cout << "�𰸣�" << answer1() << endl;
}
void TestPaper::testQuestion2()
{
    cout << "�������Ӣ��½��˫�������黨�����[ ] a.ʹ����ֲ�ﲻ�ٺ��� b.ʹһ����ϡ������� c.�ƻ����Ǹ�����Ȧ����̬ƽ�� d.��ɸõ���ɳĮ��" << endl;
    cout << "�𰸣�" << answer2() << endl;
}

void TestPaper::testQuestion3()
{
    cout << "����˵���ʹ��ɽʦͽ���ҹ�����Ż�²�ֹ,������Ǵ��,������ǿ�ʲôҩ[ ] a.��˾ƥ�� b.ţ�ƽⶾƬ c.������ d.�����Ǻȴ�������ţ�� e.����ȫ����" << endl;
    cout << "�𰸣�" << answer3() << endl;
}
string TestPaperA::answer1()
{
    return "b";
}

string TestPaperA::answer2()
{
    return "c";
}

string TestPaperA::answer3()
{
    return "a";
}

string TestPaperB::answer1()
{
    return "c";
}

string TestPaperB::answer2()
{
    return "a";
}

string TestPaperB::answer3()
{
    return "a";
}
int main()
{
    cout << "ѧ���׳����Ծ�"<< endl;
    //����������������ĳ��˸��������˶�̬�ԣ�ʵ���˴���ĸ���
    TestPaper * studentA = new TestPaperA();
    studentA->testQuestion1();
    studentA->testQuestion2();
    studentA->testQuestion3();

    cout << "ѧ���ҳ����Ծ�" << endl;
    TestPaper * studentB = new TestPaperB();
    studentB->testQuestion1();
    studentB->testQuestion2();
    studentB->testQuestion3();

    return 0;
}