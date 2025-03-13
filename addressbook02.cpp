#include "addressbook01.h"

//1.添加联系人
void addPerson(Addressbooks* abs)
{
    //判断通讯录是否已满，如果满了就不再添加
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        //添加具体联系人
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        //性别
        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        while (true)
        {
            //如果输入的是1和2可以退出循环，因为输入的是正确的
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        //年龄
        int age = 0;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;
        //电话
        string phone;
        cout << "请输入电话号码：" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        //住址
        string addr;
        cout << "请输入家庭住址：" << endl;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        //更新通讯录人数
        abs->m_Size++;

        cout << "添加成功。" << endl;
        system("pause"); //请按任意键继续
        system("cls"); //清屏操作
    }
}

//2.显示联系人
void showPerson(Addressbooks* abs)
{
    //判断通讯录中人数是否为0，如果为0，提示记录为空
    //如果不为0，显示记录的联系人信息

    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0;i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause"); //按任意键继续
    system("cls"); //清空屏幕
}


//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;  //找到了，返回该人位置
        }
    }
    return -1;  //如果遍历结束都没有找到，返回-1
}

//3.删除指定联系人

void deletePerson(Addressbooks* abs)
{
    cout << "请输入您要删除的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name); //-1未查到，！=-1，查到了
    if (ret != -1)
    {
        //查找到人，进行删除
        for (int i = ret; i < abs->m_Size; i++)
        {
            //数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--; //更新通讯录中的人员数
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

//4.查找指定联系人
void findPerson(Addressbooks* abs)
{
    cout << "请输入您要查找的联系人：" << endl;
    string name;
    cin >> name;

    //判断指定的联系人是否存在通讯录中
    int ret = isExist(abs, name);

    if (ret != -1)  //找到联系人
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "地址：" << abs->personArray[ret].m_Addr << endl;
    }
    else  //未找到联系人
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}


//5.修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1) //找到联系人
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        //性别
        cout << "请输入性别：" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //住址
        cout << "请输入家庭住址" << endl;
        string addr;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;
    }
    else //未找到联系人
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

//6.清空所有联系人
void cleanPerson(Addressbooks* abs)
{
    cout << "请输入y确认进行清空操作：" << endl;
    string judge;
    cin >> judge;
    if (judge == "y")
    {
        abs->m_Size = 0;  //将当前记录联系人数量置为0，做逻辑清空操作
        cout << "通讯录已清空" << endl;
    }
    else
    {
        cout << "不是y，不进行清空操作" << endl;
    }

    system("pause");
    system("cls");
}

//菜单界面
void showMenu()
{
    cout << "************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}