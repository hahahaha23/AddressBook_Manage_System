#include <iostream>
using namespace std;
#include "addressbook01.h"


int main()
{
    //创建通讯录结构体变量
    Addressbooks abs;
    //初始化通讯录中当前的人员个数
    abs.m_Size = 0;

    int select = 0; //创建用户选择输入的变量

    while (true)
    {
        //菜单调用
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1: //添加联系人
            addPerson(&abs); //地址传递可以修饰实参
            break;
        case 2: //显示联系人
            showPerson(&abs);
            break;
        case 3: //删除联系人
            deletePerson(&abs);
            break;
        case 4: //查找联系人
            findPerson(&abs);
            break;
        case 5: //修改联系人 
            modifyPerson(&abs);
            break;
        case 6: //清空联系人
            cleanPerson(&abs);
            break;
        case 0: //退出通讯录
            cout << "欢迎下次使用" << endl;
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