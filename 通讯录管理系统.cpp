#include <iostream>
using namespace std;
#include "addressbook01.h"


int main()
{
    //����ͨѶ¼�ṹ�����
    Addressbooks abs;
    //��ʼ��ͨѶ¼�е�ǰ����Ա����
    abs.m_Size = 0;

    int select = 0; //�����û�ѡ������ı���

    while (true)
    {
        //�˵�����
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1: //�����ϵ��
            addPerson(&abs); //��ַ���ݿ�������ʵ��
            break;
        case 2: //��ʾ��ϵ��
            showPerson(&abs);
            break;
        case 3: //ɾ����ϵ��
            deletePerson(&abs);
            break;
        case 4: //������ϵ��
            findPerson(&abs);
            break;
        case 5: //�޸���ϵ�� 
            modifyPerson(&abs);
            break;
        case 6: //�����ϵ��
            cleanPerson(&abs);
            break;
        case 0: //�˳�ͨѶ¼
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }


    system("pause");
    return 0;
}