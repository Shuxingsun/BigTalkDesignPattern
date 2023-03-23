//
// Created by sunchanghui on 2023/3/21.
//
#include<iostream>
#include <string>
using namespace std;

//Memento�࣬����¼���˴�Ϊ��ɫ״̬�洢��
class RoleStateMemento
{
private:
    int m_vit;  // ������
    int m_atk;  // ������
    int m_def;  // ������
public:
    RoleStateMemento(int vit,int atk,int def):m_vit(vit),m_atk(atk),m_def(def){} //

    void setVitality(int vit){m_vit = vit;}
    int getVitality() { return m_vit;}

    void setAttack(int atk) {m_atk = atk;}
    int getAttack() {return m_atk;}

    void setDefense(int def) {m_def = def;}
    int getDefense() {return m_def;}

};
// Originator�������ˣ��˴�Ϊ��Ϸ��ɫ
class GameRole
{
private:
    int m_vit;
    int m_atk;
    int m_def;
public:
    RoleStateMemento* SaveState()
    {
        return (new RoleStateMemento(m_vit,m_atk,m_def));
    }
    void RecoveryState(RoleStateMemento* memento)
    {
        //�ָ���ɫ״̬
        m_vit = memento->getVitality();
        m_atk = memento->getAttack();
        m_def = memento->getDefense();
    }
    //��ó�ʼ״̬
    void GetInitState()
    {
        m_atk = m_def = m_vit = 100;
    }
    void Fight()
    {
        m_atk = m_def = m_vit = 0;
    }
    void StateDisplay()
    {
        cout << "��ɫ��ǰ״̬��" << endl;
        cout << "������" << m_vit << " "
             << "��������" << m_atk << " "
             << "��������" << m_def << endl;
    }
};
//Caretaker�������ߣ��˴�Ϊ��Ϸ��ɫ������
class RoleStateCaretaker
{
private:
    RoleStateMemento* m_memento;
public:
    ~RoleStateCaretaker()
    {
        delete m_memento;
    }
    void setMemento(RoleStateMemento* memento)
    {
        m_memento = memento;
    }
    RoleStateMemento* getMemento()
    {
        return m_memento;
    }
};

int main()
{
    //��սBoss֮ǰ
    GameRole* lixiaoyao = new GameRole;
    lixiaoyao->GetInitState();
    lixiaoyao->StateDisplay();

    //�������
    RoleStateCaretaker* stateAdmin = new RoleStateCaretaker;
    stateAdmin->setMemento(lixiaoyao->SaveState());

    //��սBossʱ���������
    lixiaoyao->Fight();
    lixiaoyao->StateDisplay();

    //�ָ�֮ǰ״̬
    lixiaoyao->RecoveryState(stateAdmin->getMemento());
    lixiaoyao->StateDisplay();

    delete lixiaoyao;
    delete stateAdmin;

    system("pause");
    return 0;
}