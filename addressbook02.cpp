#include "addressbook01.h"

//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
    //�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷���ӣ�" << endl;
        return;
    }
    else
    {
        //��Ӿ�����ϵ��
        //����
        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        //�Ա�
        int sex = 0;
        cout << "�������Ա�" << endl;
        cout << "1--��" << endl;
        cout << "2--Ů" << endl;
        while (true)
        {
            //����������1��2�����˳�ѭ������Ϊ���������ȷ��
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }
        //����
        int age = 0;
        cout << "���������䣺" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;
        //�绰
        string phone;
        cout << "������绰���룺" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        //סַ
        string addr;
        cout << "�������ͥסַ��" << endl;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        //����ͨѶ¼����
        abs->m_Size++;

        cout << "��ӳɹ���" << endl;
        system("pause"); //�밴���������
        system("cls"); //��������
    }
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
    //�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
    //�����Ϊ0����ʾ��¼����ϵ����Ϣ

    if (abs->m_Size == 0)
    {
        cout << "��ǰ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0;i < abs->m_Size; i++)
        {
            cout << "������" << abs->personArray[i].m_Name << "\t";
            cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
            cout << "���䣺" << abs->personArray[i].m_Age << "\t";
            cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
            cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause"); //�����������
    system("cls"); //�����Ļ
}


//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;  //�ҵ��ˣ����ظ���λ��
        }
    }
    return -1;  //�������������û���ҵ�������-1
}

//3.ɾ��ָ����ϵ��

void deletePerson(Addressbooks* abs)
{
    cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name); //-1δ�鵽����=-1���鵽��
    if (ret != -1)
    {
        //���ҵ��ˣ�����ɾ��
        for (int i = ret; i < abs->m_Size; i++)
        {
            //����ǰ��
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--; //����ͨѶ¼�е���Ա��
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

//4.����ָ����ϵ��
void findPerson(Addressbooks* abs)
{
    cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
    string name;
    cin >> name;

    //�ж�ָ������ϵ���Ƿ����ͨѶ¼��
    int ret = isExist(abs, name);

    if (ret != -1)  //�ҵ���ϵ��
    {
        cout << "������" << abs->personArray[ret].m_Name << "\t";
        cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
        cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
        cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
    }
    else  //δ�ҵ���ϵ��
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}


//5.�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
    cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1) //�ҵ���ϵ��
    {
        //����
        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        //�Ա�
        cout << "�������Ա�" << endl;
        cout << "1--��" << endl;
        cout << "2--Ů" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }
        //����
        cout << "���������䣺" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //�绰
        cout << "��������ϵ�绰��" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //סַ
        cout << "�������ͥסַ" << endl;
        string addr;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;
    }
    else //δ�ҵ���ϵ��
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

//6.���������ϵ��
void cleanPerson(Addressbooks* abs)
{
    cout << "������yȷ�Ͻ�����ղ�����" << endl;
    string judge;
    cin >> judge;
    if (judge == "y")
    {
        abs->m_Size = 0;  //����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
        cout << "ͨѶ¼�����" << endl;
    }
    else
    {
        cout << "����y����������ղ���" << endl;
    }

    system("pause");
    system("cls");
}

//�˵�����
void showMenu()
{
    cout << "************************" << endl;
    cout << "***** 1.�����ϵ�� *****" << endl;
    cout << "***** 2.��ʾ��ϵ�� *****" << endl;
    cout << "***** 3.ɾ����ϵ�� *****" << endl;
    cout << "***** 4.������ϵ�� *****" << endl;
    cout << "***** 5.�޸���ϵ�� *****" << endl;
    cout << "***** 6.�����ϵ�� *****" << endl;
    cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
    cout << "************************" << endl;
}