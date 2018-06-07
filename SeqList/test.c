#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void Menu()
{
	printf("********��̬˳���********\n");
	printf("**       0.�˳�         **\n");
	printf("**       1.��ʼ��       **\n");
	printf("**       2.����         **\n");
	printf("**       3.ɾ��         **\n");
	printf("**       4.����         **\n");
	printf("**       5.�޸�         **\n");
	printf("**       6.ð������     **\n");
	printf("**       7.ѡ������     **\n");
	printf("**       8.���ֲ���     **\n");
	printf("**       9.���         **\n");
	printf("**************************\n");
}

int main()
{
	SeqList pSeq;
	int op = 0;
	do{
		Menu();
		printf("��ѡ��");
		scanf("%d", &op);
		switch (op)
		{
		case 0:
			break;
		case 1:
			SeqList_Init(&pSeq);
			break;
		case 2:
		{
				  DataType x = 0;
				  size_t pos = 0;
				  printf("������Ҫ�����λ�ã�");
				  scanf("%d", &pos);
				  printf("������Ҫ�����ֵ��");
				  scanf("%d", &x);
				  SeqList_Insert(&pSeq, pos, x);
		}
			break;
		case 3:
		{
				  size_t pos = 0;
				  printf("������Ҫɾ����λ�ã�");
				  scanf("%d", &pos);
				  SeqList_Delete(&pSeq, pos);
		}
			break;
		case 4:
		{
				  DataType x = 0;
				  printf("������Ҫ���ҵ�ֵ��");
				  scanf("%d", &x);
				  SeqList_Search(&pSeq, x);
		}
			break;
		case 5:
		{
				  DataType x = 0;
				  size_t pos = 0;
				  printf("������Ҫ�޸ĵ�λ�ã�");
				  scanf("%d", &pos);
				  printf("�������޸ĺ��ֵ��");
				  scanf("%d", &x);
				  SeqList_Modify(&pSeq, pos, x);
		}
			break;
		case 6:
			Bubble_Sort(&pSeq);
			break;
		case 7:
			Select_Sort(&pSeq);
			break;
		case 8:
		{
				   DataType x = 0;
				   printf("������Ҫ���ҵ�ֵ��");
				   scanf("%d", &x);
				   Binary_Search(&pSeq, x);
		}
			break;
		case 9:
			SeqList_Print(&pSeq);
			break;
		default:
			printf("������ѡ��...\n");
			break;
		}
	} while (op);
	system("pause");
	return 0;
}