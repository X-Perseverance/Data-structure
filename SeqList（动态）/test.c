#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void Menu()
{
	printf("********��̬˳���********\n");
	printf("**       0.�˳�         **\n");
	printf("**       1.��ʼ��       **\n");
	printf("**       2.ͷ��         **\n");
	printf("**       3.β��         **\n");
	printf("**       4.ͷɾ         **\n");
	printf("**       5.βɾ         **\n");
	printf("**       6.����         **\n");
	printf("**       7.ɾ��         **\n");
	printf("**       8.����         **\n");
	printf("**       9.�޸�         **\n");
	printf("**       10.ð������    **\n");
	printf("**       11.ѡ������    **\n");
	printf("**       12.���ֲ���    **\n");
	printf("**       13.���        **\n");
	printf("**       14.����        **\n");
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
			SeqInit(&pSeq);
			break;
		case 2:
		{
				  DataType x = 0;
				  printf("������Ҫ�����ֵ��");
				  scanf("%d", &x);
				  SeqPushFront(&pSeq, x);
				  printf("����ɹ�\n");
		}
			break;
		case 3:
		{
				  DataType x = 0;
				  printf("������Ҫ�����ֵ��");
				  scanf("%d", &x);
				  SeqPushBack(&pSeq, x);
				  printf("����ɹ�\n");
		}
			break;
		case 4:
			SeqPopFront(&pSeq);
			break;
		case 5:
			SeqPopBack(&pSeq);
			break;
		case 6:
		{
				  DataType x = 0;
				  size_t pos = 0;
				  printf("������Ҫ�����λ�ã�");
				  scanf("%d", &pos);
				  printf("������Ҫ�����ֵ��");
				  scanf("%d", &x);
				  SeqInsert(&pSeq, pos, x);
				  printf("����ɹ�\n");
		}
			break;
		case 7:
		{
				  size_t pos = 0;
				  printf("������Ҫɾ����λ�ã�");
				  scanf("%d", &pos);
				  SeqErase(&pSeq, pos);
		}
			break;
		case 8:
		{       
				  DataType x = 0;	
				  printf("������Ҫ���ҵ�ֵ��");
				  scanf("%d", &x);
				  printf("%d\n", SeqFind(&pSeq, x));
		}
			break;
		case 9:
		{
				  DataType x = 0;
				  size_t pos = 0;
				  printf("������Ҫ�޸ĵ�λ�ã�");
				  scanf("%d", &pos);
				  printf("�������޸ĺ��ֵ��");
				  scanf("%d", &x);
				  SeqModify(&pSeq, pos, x);
		}
			break;
		case 10:
			BubbleSort(&pSeq);
			break;
		case 11:
			SelectSort(&pSeq);
			break;
		case 12:
		{
				   DataType x = 0;
				   printf("������Ҫ���ҵ�ֵ��");
				   scanf("%d", &x);
				   printf("%d\n", BinarySearch(&pSeq, x));
		}
			break;
		case 13:
			SeqPrint(&pSeq);
			break;
		case 14:
			SeqDestroy(&pSeq);
			break;
		default:
			printf("������ѡ��...\n");
			break;
		}
	} while (op);
	system("pause");
	return 0;
} 