
#include <iostream>
using namespace std;
//��Ա
class Player
{
protected:
    string name;
public:
    Player(string name):name(name){}
    virtual void Attack() = 0;
    virtual void Defense() = 0;
    virtual~Player() {}
};
//ǰ��
class Forwards : public Player
{
public:
    Forwards(string name):Player(name){}
    virtual void Attack() {
        cout << "ǰ��" << name << "����" << endl;
    }
    virtual void Defense() {
        cout << "ǰ��" << name << "����" << endl;
    }
};

//�з�
class Center : public Player
{
public:
    Center(string name) :Player(name) {}
    virtual void Attack() {
        cout << "�з�" << name << "����" << endl;
    }
    virtual void Defense() {
        cout << "�з�" << name << "����" << endl;
    }
};

//����
class Guards : public Player
{
public:
    Guards(string name) :Player(name) {}
    virtual void Attack() {
        cout << "����" << name << "����" << endl;
    }
    virtual void Defense() {
        cout << "����" << name << "����" << endl;
    }
};

class ForeignCenter {
public:
    void SetName(string name) {
        this->name = name;
    }
    string GstName() {
        return name;
    }
    void ForeignAttack() {
        cout << "�⼮�з� " << name << " ����" << endl;
    }
    void ForeignDefense() {
        cout << "�⼮�з� " << name << " ����" << endl;
    }

private:
    string name;
};

//�������� ������
class Translator :public Player {
public:
    Translator(string name) :Player(name) {
        //�½����� ������
        ym = new ForeignCenter;
        ym->SetName(name);
    }
    ~Translator()
    {
        if (ym != NULL) delete ym;
    }
    void Attack() { //�����߽�Attack ����� ForeignAttack
        ym->ForeignAttack();
    }
    void Defense() {
        ym->ForeignDefense(); //�����߽�Defense ����� ForeignDefense
    }

private:
    ForeignCenter* ym; //�⼮�з�
};
int main()
{
    Player* b = new Forwards("�͵ٶ�");
    b->Attack();
    Player* c = new Guards("��˸��׵�");
    c->Attack();
    Player* ym  = new Translator("Ҧ��"); //Ҧ����: "Attack��Defense��ʲô��˼��"
    ym->Attack();
    ym->Defense();
    system("pause");
    return 0;
}