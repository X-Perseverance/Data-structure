#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <string.h> 
#include <Windows.h>

#define First_Cap 3     //默认存储大小
#define Add_Cap 2       //每次增容大小
#define Max_Cap 1000    //最大存储大小

typedef struct Information //联系人信息
{
    char name[10];
    char sex[5];
    int age;
    int tel[15];
    char addr[20];
}contacts;

typedef struct Address_book
{
    int num;         //已录入联系人人数
    int capacity;    //当前容量
    contacts *data;  //联系人信息库
}*people;

//初始化通讯录
void Init_Address_book(people p)
{
    p->num = 0;
    p->data = malloc(First_Cap*sizeof(contacts));
    if (p->data == NULL)
    {
        perror("初始化失败！\n");
        return;
    }
    memset(p->data, 0, First_Cap*sizeof(contacts));
    p->capacity = First_Cap;
}

//检查存储容量
int Check_Capacity(people p)
{
    if (p->num >= Max_Cap)
    {
        printf("该通讯录已满，无法添加！\n");
        return 0;
    }
    if (p->capacity >= Max_Cap)
    {
        printf("该通讯录容量大小已开辟到上限，不再增容，但可继续添加联系人！\n");
        return 1;
    }
    else if (p->num == p->capacity)
    {
        contacts* ptr = realloc(p->data, (p->capacity + Add_Cap)*sizeof(contacts));
        if (ptr == NULL)
        {
            perror("增容失败，无法添加！\n");
            return 0;
        }
        else
        {
            p->data = ptr;  
            p->capacity += Add_Cap;
            printf("增容成功，可继续添加联系人！\n");
            return 1;
        }
    }
}

//在通讯录里遍历到指定联系人 
static int Search(people p, const char *name)
{
    for (int i = 0; i < p->num; i++)
    {
        if (strcmp(name, (p->data[i]).name) == 0)
        {
            return i;
        }
    }
    return -1;
}

//添加联系人 
void Add_Contacts(people p)
{
    if (Check_Capacity(p))
    {
        printf("请输入姓名：");
        scanf("%s", (p->data[p->num]).name);
        printf("请输入性别：");
        scanf("%s", (p->data[p->num]).sex);
        printf("请输入年龄：");
        scanf("%d", &(p->data[p->num]).age);
        printf("请输入电话号码：");
        scanf("%s", (p->data[p->num]).tel);
        printf("请输入地址：");
        scanf("%s", (p->data[p->num]).addr);
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
    scanf("%s", &name);
    int ret = Search(p, name);   //查找指定信息人  
    if (ret == -1)
    {
        printf("此联系人不存在，删除失败！\n");
    }
    else
    {
        int i = 0;
        for (i = ret; i<p->num; i++)
        {
            p->data[i] = p->data[i + 1];
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
    int ret = Search(p, name);   //查找指定信息人
    if (ret == -1)
    {
        printf("此联系人不存在，修改失败！\n");
    }
    else
    {
        printf("请输入姓名：");
        scanf("%s", (p->data[ret]).name);
        printf("请输入性别：");
        scanf("%s", (p->data[ret]).sex);
        printf("请输入年龄：");
        scanf("%d", &(p->data[ret]).age);
        printf("请输入电话号码：");
        scanf("%s", (p->data[ret]).tel);
        printf("请输入地址：");
        scanf("%s", (p->data[ret]).addr);
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
    int ret = Search(p, name);   //查找指定信息人  
    if (ret == -1)
    {
        printf("此联系人不存在，查找失败！\n");
    }
    else
    {
        printf("姓名\t性别\t年龄\t电话号码\t地址\n");
        printf("%s\t%s\t%d\t%s\t%s\n", (p->data[ret]).name, (p->data[ret]).sex, (p->data[ret]).age, (p->data[ret]).tel, (p->data[ret]).addr);
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
        printf("%s\t%s\t%d\t%s\t%s\n", (p->data[i]).name, (p->data[i]).sex, (p->data[i]).age, (p->data[i]).tel, (p->data[i]).addr);
    }
}

//清空所有联系人  
void Empty_Contacts(people p)
{
    free(p->data);
    p->data = NULL;
    Init_Address_book(p);
    printf("清空成功！\n");
}

//按名字顺序排序所有联系人 
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
        int flag = 0;
        for (j = 0; j<p->num - i - 1; j++)
        {
            if (strcmp(p->data[j].name, (p->data[j + 1]).name)>0)
            {
                flag = 1;
                contacts tmp = p->data[j];
                p->data[j] = p->data[j + 1];
                p->data[j + 1] = tmp;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("排序成功！\n");
}

//退出
void Exit(people p)
{
    free(p->data);
    p->data = NULL;
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
    Init_Address_book(&p);
    int op = 0;
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            Exit(&p);
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