#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <string.h> 
#include <Windows.h>

#define People_Max 1000 // ͨѶ¼��������

typedef struct Information // ��ϵ����Ϣ
{
    char name[10];
    char sex[5];
    int age;
    int tel[15];
    char addr[20];
}contacts;

typedef struct Address_book // ͨѶ¼
{
    int num; // ��ϵ������
    contacts count[People_Max]; // �������ÿ��Ԫ�ض���һλ��ϵ�˵���Ϣ
}*people;

//��ͨѶ¼�������ָ����ϵ��
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

//�����ϵ�� 
void Add_Contacts(people p)
{
    if (p->num == 1000)
    {
        printf("���ʧ�ܣ�ͨѶ¼�������޷�¼����Ϣ��\n");
    }
    else
    {
        printf("������������");
        scanf("%s", (p->count[p->num]).name);
        printf("�������Ա�");
        scanf("%s", (p->count[p->num]).sex);
        printf("���������䣺");
        scanf("%d", &(p->count[p->num]).age);
        printf("������绰���룺");
        scanf("%s", (p->count[p->num]).tel);
        printf("�������ַ��");
        scanf("%s", (p->count[p->num]).addr);
        printf("��ӳɹ���\n");
        p->num++;
    }
}

//ɾ����ϵ��
void Delete_Contacts(people p)
{
    if (p->num == 0)
    {
        printf("��ͨѶ¼��ǰΪ�գ�\n");
        return;
    }
    char name[10];
    printf("������Ҫɾ����ϵ�˵����֣�");
    scanf("%s", name);
    int ret = search(p, name);   //����ָ����Ϣ��  
    if (ret == -1)
    {
        printf("����ϵ�˲����ڣ�ɾ��ʧ�ܣ�\n");
    }
    else
    {
        int i = 0;
        for (i = ret; i<p->num; i++)
        {
            p->count[i] = p->count[i + 1];
        }
        p->num--;
        printf("ɾ���ɹ���\n");
    }
}

//�޸�ָ����ϵ�˵���Ϣ 
void Revise_Contacts(people p)
{
    if (p->num == 0)
    {
        printf("��ͨѶ¼��ǰΪ�գ�\n");
        return;
    }
    char name[10];
    printf("������Ҫ�޸���ϵ�˵����֣�");
    scanf("%s", name);
    int ret = search(p, name);   //����ָ����Ϣ��
    if (ret == -1)
    {
        printf("����ϵ�˲����ڣ��޸�ʧ�ܣ�\n");
    }
    else
    {
        printf("������������");
        scanf("%s", (p->count[ret]).name);
        printf("�������Ա�");
        scanf("%s", (p->count[ret]).sex);
        printf("���������䣺");
        scanf("%d", &(p->count[ret]).age);
        printf("������绰���룺");
        scanf("%s", (p->count[ret]).tel);
        printf("�������ַ��");
        scanf("%s", (p->count[ret]).addr);
        printf("�޸ĳɹ���\n");
    }
}

//������ϵ�� 
void Find_Contacts(people p)
{
    if (p->num == 0)
    {
        printf("��ͨѶ¼��ǰΪ�գ�\n");
        return;
    }
    char name[10];
    printf("������Ҫ������ϵ�˵����֣�");
    scanf("%s", name);
    int ret = search(p, name);   //����ָ����Ϣ��  
    if (ret == -1)
    {
        printf("����ϵ�˲����ڣ�����ʧ�ܣ�\n");
    }
    else
    {
        printf("����\t�Ա�\t����\t�绰����\t��ַ\n");
        printf("%s\t%s\t%d\t%s\t%s\n", (p->count[ret]).name, (p->count[ret]).sex, (p->count[ret]).age, (p->count[ret]).tel, (p->count[ret]).addr);
    }
}

//��ʾ������ϵ����Ϣ
void Display_Contacts(people p) 
{
    if (p->num == 0)
    {
        printf("��ͨѶ¼��ǰΪ�գ�\n");
        return;
    }
    int i = 0;
    printf("����\t�Ա�\t����\t�绰����\t��ַ\n");
    for (i = 0; i<p->num; i++)
    {
        printf("%s\t%s\t%d\t%s\t%s\n", (p->count[i]).name, (p->count[i]).sex, (p->count[i]).age, (p->count[i]).tel, (p->count[i]).addr);
    }
}

//���������ϵ�� 
void Empty_Contacts(people p) 
{
    p->num = 0;
    printf("��ճɹ���\n");
}

//������˳������������ 
void Sort_Contacts(people p) 
{
    if (p->num == 0)
    {
        printf("��ͨѶ¼��ǰΪ�գ�\n");
        return;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i<p->num - 1; i++)   //ð��ʵ����ϵ�˵�����  
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
    printf("����ɹ���\n");
}

//�˵�
void menu()
{
    printf("***************ͨѶ¼***************\n");
    printf("**        1.�����ϵ����Ϣ        **\n");
    printf("**        2.ɾ����ϵ����Ϣ        **\n");
    printf("**        3.������ϵ����Ϣ        **\n");
    printf("**        4.�޸���ϵ����Ϣ        **\n");
    printf("**        5.��ʾ������ϵ����Ϣ    **\n");
    printf("**        6.���������ϵ����Ϣ    **\n");
    printf("**        7.����������������ϵ��  **\n");
    printf("**        0.�˳�                  **\n");
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
        printf("��ѡ��");
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
            printf("��������������ѡ��\n");
            break;
        }
    } while (op);
    system("pause");
    return 0;
}