#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <string.h> 
#include <Windows.h>

#define First_Cap 3     //Ĭ�ϴ洢��С
#define Add_Cap 2       //ÿ�����ݴ�С
#define Max_Cap 1000    //���洢��С

typedef struct Information //��ϵ����Ϣ
{
    char name[10];
    char sex[5];
    int age;
    int tel[15];
    char addr[20];
}contacts;

typedef struct Address_book
{
    int num;         //��¼����ϵ������
    int capacity;    //��ǰ����
    contacts *data;  //��ϵ����Ϣ��
}*people;

//��ʼ��ͨѶ¼
void Init_Address_book(people p)
{
    p->num = 0;
    p->data = malloc(First_Cap*sizeof(contacts));
    if (p->data == NULL)
    {
        perror("��ʼ��ʧ�ܣ�\n");
        return;
    }
    memset(p->data, 0, First_Cap*sizeof(contacts));
    p->capacity = First_Cap;
}

//���洢����
int Check_Capacity(people p)
{
    if (p->num >= Max_Cap)
    {
        printf("��ͨѶ¼�������޷���ӣ�\n");
        return 0;
    }
    if (p->capacity >= Max_Cap)
    {
        printf("��ͨѶ¼������С�ѿ��ٵ����ޣ��������ݣ����ɼ��������ϵ�ˣ�\n");
        return 1;
    }
    else if (p->num == p->capacity)
    {
        contacts* ptr = realloc(p->data, (p->capacity + Add_Cap)*sizeof(contacts));
        if (ptr == NULL)
        {
            perror("����ʧ�ܣ��޷���ӣ�\n");
            return 0;
        }
        else
        {
            p->data = ptr;  
            p->capacity += Add_Cap;
            printf("���ݳɹ����ɼ��������ϵ�ˣ�\n");
            return 1;
        }
    }
}

//��ͨѶ¼�������ָ����ϵ�� 
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

//�����ϵ�� 
void Add_Contacts(people p)
{
    if (Check_Capacity(p))
    {
        printf("������������");
        scanf("%s", (p->data[p->num]).name);
        printf("�������Ա�");
        scanf("%s", (p->data[p->num]).sex);
        printf("���������䣺");
        scanf("%d", &(p->data[p->num]).age);
        printf("������绰���룺");
        scanf("%s", (p->data[p->num]).tel);
        printf("�������ַ��");
        scanf("%s", (p->data[p->num]).addr);
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
    scanf("%s", &name);
    int ret = Search(p, name);   //����ָ����Ϣ��  
    if (ret == -1)
    {
        printf("����ϵ�˲����ڣ�ɾ��ʧ�ܣ�\n");
    }
    else
    {
        int i = 0;
        for (i = ret; i<p->num; i++)
        {
            p->data[i] = p->data[i + 1];
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
    int ret = Search(p, name);   //����ָ����Ϣ��
    if (ret == -1)
    {
        printf("����ϵ�˲����ڣ��޸�ʧ�ܣ�\n");
    }
    else
    {
        printf("������������");
        scanf("%s", (p->data[ret]).name);
        printf("�������Ա�");
        scanf("%s", (p->data[ret]).sex);
        printf("���������䣺");
        scanf("%d", &(p->data[ret]).age);
        printf("������绰���룺");
        scanf("%s", (p->data[ret]).tel);
        printf("�������ַ��");
        scanf("%s", (p->data[ret]).addr);
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
    int ret = Search(p, name);   //����ָ����Ϣ��  
    if (ret == -1)
    {
        printf("����ϵ�˲����ڣ�����ʧ�ܣ�\n");
    }
    else
    {
        printf("����\t�Ա�\t����\t�绰����\t��ַ\n");
        printf("%s\t%s\t%d\t%s\t%s\n", (p->data[ret]).name, (p->data[ret]).sex, (p->data[ret]).age, (p->data[ret]).tel, (p->data[ret]).addr);
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
        printf("%s\t%s\t%d\t%s\t%s\n", (p->data[i]).name, (p->data[i]).sex, (p->data[i]).age, (p->data[i]).tel, (p->data[i]).addr);
    }
}

//���������ϵ��  
void Empty_Contacts(people p)
{
    free(p->data);
    p->data = NULL;
    Init_Address_book(p);
    printf("��ճɹ���\n");
}

//������˳������������ϵ�� 
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
    printf("����ɹ���\n");
}

//�˳�
void Exit(people p)
{
    free(p->data);
    p->data = NULL;
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
    Init_Address_book(&p);
    int op = 0;
    do
    {
        menu();
        printf("��ѡ��");
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
            printf("��������������ѡ��\n");
            break;
        }
    } while (op);
    system("pause");
    return 0;
}