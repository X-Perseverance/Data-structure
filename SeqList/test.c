#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void Menu()
{
	printf("********静态顺序表********\n");
	printf("**       0.退出         **\n");
	printf("**       1.初始化       **\n");
	printf("**       2.插入         **\n");
	printf("**       3.删除         **\n");
	printf("**       4.查找         **\n");
	printf("**       5.修改         **\n");
	printf("**       6.冒泡排序     **\n");
	printf("**       7.选择排序     **\n");
	printf("**       8.二分查找     **\n");
	printf("**       9.输出         **\n");
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
			SeqList_Init(&pSeq);
			break;
		case 2:
		{
				  DataType x = 0;
				  size_t pos = 0;
				  printf("请输入要插入的位置：");
				  scanf("%d", &pos);
				  printf("请输入要插入的值：");
				  scanf("%d", &x);
				  SeqList_Insert(&pSeq, pos, x);
		}
			break;
		case 3:
		{
				  size_t pos = 0;
				  printf("请输入要删除的位置：");
				  scanf("%d", &pos);
				  SeqList_Delete(&pSeq, pos);
		}
			break;
		case 4:
		{
				  DataType x = 0;
				  printf("请输入要查找的值：");
				  scanf("%d", &x);
				  SeqList_Search(&pSeq, x);
		}
			break;
		case 5:
		{
				  DataType x = 0;
				  size_t pos = 0;
				  printf("请输入要修改的位置：");
				  scanf("%d", &pos);
				  printf("请输入修改后的值：");
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
				   printf("请输入要查找的值：");
				   scanf("%d", &x);
				   Binary_Search(&pSeq, x);
		}
			break;
		case 9:
			SeqList_Print(&pSeq);
			break;
		default:
			printf("请重新选择...\n");
			break;
		}
	} while (op);
	system("pause");
	return 0;
}