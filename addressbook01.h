#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
    //����
    string m_Name;
    //�Ա� 1�� 2Ů
    int m_Sex;
    //����
    int m_Age;
    //�绰
    string m_Phone;
    //סַ
    string m_Addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
    //ͨѶ¼�б�����ϵ������
    struct Person personArray[MAX];
    //ͨѶ¼�е�ǰ��¼��ϵ�˸���
    int m_Size;
};

//1.�����ϵ��
void addPerson(Addressbooks* abs);

//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs);

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name);

//3.ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs);

//4.����ָ����ϵ��
void findPerson(Addressbooks* abs);

//5.�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs);

//6.���������ϵ��
void cleanPerson(Addressbooks* abs);

//�˵�����
void showMenu();
