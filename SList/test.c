#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void Menu()
{
	printf("********单链表********\n");
	printf("**      0.退出      **\n");
	printf("**      1.头插      **\n");
	printf("**      2.尾插      **\n");
	printf("**      3.头删      **\n");
	printf("**      4.尾删      **\n");
	printf("**      5.插入      **\n");
	printf("**      6.删除      **\n");
	printf("**      7.查找      **\n");
	printf("**      8.输出      **\n");
	printf("**      9.销毁      **\n");
	printf("**********************\n");
}

int main()
{
	SListNode* pHead = NULL;
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
		{
				  int x = 0;
				  printf("请输入插入的值：");
				  scanf("%d", &x);
				  SList_PushFront(&pHead, x);
				  printf("插入成功\n");
		}
			break;
		case 2:
		{
				  int x = 0;
				  printf("请输入插入的值：");
				  scanf("%d", &x);
				  SList_PushBack(&pHead, x);
				  printf("插入成功\n");
		}
			break;
		case 3:
			SList_PopFront(&pHead);
			break;
		case 4:
			SList_PopBack(&pHead);
			break;
		case 5:
		{
				  int x = 0;
				  int y = 0;
				  SListNode* pos = pHead;
				  printf("请输入插入的值：");
				  scanf("%d", &x);
				  printf("请输入插入的合法位置：");
				  scanf("%d", &y);
				  while (--y > 0)
				  {
					  pos = pos->_next;
				  }
				  SList_Insert(&pHead, pos, x);
				  printf("插入成功\n");
		}
			break;
		case 6:
		{
				  int y = 0;
				  SListNode* pos = pHead;
				  printf("请输入删除的合法位置：");
				  scanf("%d", &y);
				  while (--y > 0)
				  {
					  pos = pos->_next;
				  }
				  SList_Erase(&pHead, pos);
		}
			break;
		case 7:
		{
				  int x = 0;
				  printf("请输入查找的值：");
				  scanf("%d", &x);
				  if (SList_Find(pHead, x))
				  {
					  printf("找到了\n");
				  }
				  else
				  {
					  printf("未找到\n");
				  }
		}
			break;
		case 8:
			SList_Print(pHead);
			break;
		case 9:
			SList_Destory(&pHead);
			break;
		default:
			printf("请重新选择...\n");
			break;
		}
	} while (op);
	system("pause");
	return 0;
}