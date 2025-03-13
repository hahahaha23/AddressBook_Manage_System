#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//设计联系人结构体
struct Person
{
    //姓名
    string m_Name;
    //性别 1男 2女
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
    //通讯录中保存联系人数组
    struct Person personArray[MAX];
    //通讯录中当前记录联系人个数
    int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks* abs);

//2.显示联系人
void showPerson(Addressbooks* abs);

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name);

//3.删除指定联系人
void deletePerson(Addressbooks* abs);

//4.查找指定联系人
void findPerson(Addressbooks* abs);

//5.修改指定联系人信息
void modifyPerson(Addressbooks* abs);

//6.清空所有联系人
void cleanPerson(Addressbooks* abs);

//菜单界面
void showMenu();
