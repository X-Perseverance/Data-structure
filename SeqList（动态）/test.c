#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void Menu()
{
	printf("********动态顺序表********\n");
	printf("**       0.退出         **\n");
	printf("**       1.初始化       **\n");
	printf("**       2.头插         **\n");
	printf("**       3.尾插         **\n");
	printf("**       4.头删         **\n");
	printf("**       5.尾删         **\n");
	printf("**       6.插入         **\n");
	printf("**       7.删除         **\n");
	printf("**       8.查找         **\n");
	printf("**       9.修改         **\n");
	printf("**       10.冒泡排序    **\n");
	printf("**       11.选择排序    **\n");
	printf("**       12.二分查找    **\n");
	printf("**       13.输出        **\n");
	printf("**       14.销毁        **\n");
	printf("**************************\n");
}

int main()
{
	SeqList pSeq;
	int op = 0;
	do{
		Menu();
		printf("请选择：");
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
				  printf("请输入要插入的值：");
				  scanf("%d", &x);
				  SeqPushFront(&pSeq, x);
				  printf("插入成功\n");
		}
			break;
		case 3:
		{
				  DataType x = 0;
				  printf("请输入要插入的值：");
				  scanf("%d", &x);
				  SeqPushBack(&pSeq, x);
				  printf("插入成功\n");
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
				  printf("请输入要插入的位置：");
				  scanf("%d", &pos);
				  printf("请输入要插入的值：");
				  scanf("%d", &x);
				  SeqInsert(&pSeq, pos, x);
				  printf("插入成功\n");
		}
			break;
		case 7:
		{
				  size_t pos = 0;
				  printf("请输入要删除的位置：");
				  scanf("%d", &pos);
				  SeqErase(&pSeq, pos);
		}
			break;
		case 8:
		{       
				  DataType x = 0;	
				  printf("请输入要查找的值：");
				  scanf("%d", &x);
				  printf("%d\n", SeqFind(&pSeq, x));
		}
			break;
		case 9:
		{
				  DataType x = 0;
				  size_t pos = 0;
				  printf("请输入要修改的位置：");
				  scanf("%d", &pos);
				  printf("请输入修改后的值：");
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
				   printf("请输入要查找的值：");
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
			printf("请重新选择...\n");
			break;
		}
	} while (op);
	system("pause");
	return 0;
} 