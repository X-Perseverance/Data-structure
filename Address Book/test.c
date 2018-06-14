#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <string.h> 
#include <Windows.h>

#define People_Max 1000 // 通讯录人数上限

typedef struct Information // 联系人信息
{
    char name[10];
    char sex[5];
    int age;
    int tel[15];
    char addr[20];
}contacts;

typedef struct Address_book // 通讯录
{
    int num; // 联系人人数
    contacts count[People_Max]; // 数组里的每个元素都是一位联系人的信息
}*people;

//在通讯录里遍历到指定联系人
static int search(people p, const char *name) 
{
    for (int i = 0; i < p->num; i++)
    {
        if (strcmp(name, (p->count[i]).name) == 0)
        {
            return i;
        }
    }
    return -1;
}

//添加联系人 
void Add_Contacts(people p)
{
    if (p->num == 1000)
    {
        printf("添加失败，通讯录已满，无法录入信息！\n");
    }
    else
    {
        printf("请输入姓名：");
        scanf("%s", (p->count[p->num]).name);
        printf("请输入性别：");
        scanf("%s", (p->count[p->num]).sex);
        printf("请输入年龄：");
        scanf("%d", &(p->count[p->num]).age);
        printf("请输入电话号码：");
        scanf("%s", (p->count[p->num]).tel);
        printf("请输入地址：");
        scanf("%s", (p->count[p->num]).addr);
        printf("添加成功！\n");
        p->num++;
    }
}

//删除联系人
void Delete_Contacts(people p)
{
    if (p->num == 0)
    {
        printf("该通讯录当前为空！\n");
        return;
    }
    char name[10];
    printf("请输入要删除联系人的名字：");
    scanf("%s", name);
    int ret = search(p, name);   //查找指定信息人  
    if (ret == -1)
    {
        printf("此联系人不存在，删除失败！\n");
    }
    else
    {
        int i = 0;
        for (i = ret; i<p->num; i++)
        {
            p->count[i] = p->count[i + 1];
        }
        p->num--;
        printf("删除成功！\n");
    }
}

//修改指定联系人的信息 
void Revise_Contacts(people p)
{
    if (p->num == 0)
    {
        printf("该通讯录当前为空！\n");
        return;
    }
    char name[10];
    printf("请输入要修改联系人的名字：");
    scanf("%s", name);
    int ret = search(p, name);   //查找指定信息人
    if (ret == -1)
    {
        printf("此联系人不存在，修改失败！\n");
    }
    else
    {
        printf("请输入姓名：");
        scanf("%s", (p->count[ret]).name);
        printf("请输入性别：");
        scanf("%s", (p->count[ret]).sex);
        printf("请输入年龄：");
        scanf("%d", &(p->count[ret]).age);
        printf("请输入电话号码：");
        scanf("%s", (p->count[ret]).tel);
        printf("请输入地址：");
        scanf("%s", (p->count[ret]).addr);
        printf("修改成功！\n");
    }
}

//查找联系人 
void Find_Contacts(people p)
{
    if (p->num == 0)
    {
        printf("该通讯录当前为空！\n");
        return;
    }
    char name[10];
    printf("请输入要查找联系人的名字：");
    scanf("%s", name);
    int ret = search(p, name);   //查找指定信息人  
    if (ret == -1)
    {
        printf("此联系人不存在，查找失败！\n");
    }
    else
    {
        printf("姓名\t性别\t年龄\t电话号码\t地址\n");
        printf("%s\t%s\t%d\t%s\t%s\n", (p->count[ret]).name, (p->count[ret]).sex, (p->count[ret]).age, (p->count[ret]).tel, (p->count[ret]).addr);
    }
}

//显示所有联系人信息
void Display_Contacts(people p) 
{
    if (p->num == 0)
    {
        printf("该通讯录当前为空！\n");
        return;
    }
    int i = 0;
    printf("姓名\t性别\t年龄\t电话号码\t地址\n");
    for (i = 0; i<p->num; i++)
    {
        printf("%s\t%s\t%d\t%s\t%s\n", (p->count[i]).name, (p->count[i]).sex, (p->count[i]).age, (p->count[i]).tel, (p->count[i]).addr);
    }
}

//清空所有联系人 
void Empty_Contacts(people p) 
{
    p->num = 0;
    printf("清空成功！\n");
}

//按名字顺序排序所有人 
void Sort_Contacts(people p) 
{
    if (p->num == 0)
    {
        printf("该通讯录当前为空！\n");
        return;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i<p->num - 1; i++)   //冒泡实现联系人的排序  
    {
        for (j = 0; j<p->num - i - 1; j++)
        {
            if (strcmp(p->count[j].name, (p->count[j + 1]).name)>0)
            {
                contacts tmp = p->count[j];
                p->count[j] = p->count[j + 1];
                p->count[j + 1] = tmp;
            }
        }
    }
    printf("排序成功！\n");
}

//菜单
void menu()
{
    printf("***************通讯录***************\n");
    printf("**        1.添加联系人信息        **\n");
    printf("**        2.删除联系人信息        **\n");
    printf("**        3.查找联系人信息        **\n");
    printf("**        4.修改联系人信息        **\n");
    printf("**        5.显示所有联系人信息    **\n");
    printf("**        6.清空所有联系人信息    **\n");
    printf("**        7.以名字排序所有联系人  **\n");
    printf("**        0.退出                  **\n");
    printf("************************************\n");
}

int main()
{
    struct Address_book p;
    p.num = 0;
    int op = 0;
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            break;
        case 1:
            Add_Contacts(&p);
            break;
        case 2:
            Delete_Contacts(&p);
            break;
        case 3:
            Find_Contacts(&p);
            break;
        case 4:
            Revise_Contacts(&p);
            break;
        case 5:
            Display_Contacts(&p);
            break;
        case 6:
            Empty_Contacts(&p);
            break;
        case 7:
            Sort_Contacts(&p);
            break;
        default:
            printf("输入有误，请重新选择：\n");
            break;
        }
    } while (op);
    system("pause");
    return 0;
}