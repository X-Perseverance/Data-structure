#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void Menu()
{
	printf("********������********\n");
	printf("**      0.�˳�      **\n");
	printf("**      1.ͷ��      **\n");
	printf("**      2.β��      **\n");
	printf("**      3.ͷɾ      **\n");
	printf("**      4.βɾ      **\n");
	printf("**      5.����      **\n");
	printf("**      6.ɾ��      **\n");
	printf("**      7.����      **\n");
	printf("**      8.���      **\n");
	printf("**      9.����      **\n");
	printf("**********************\n");
}

int main()
{
	SListNode* pHead = NULL;
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
		{
				  int x = 0;
				  printf("����������ֵ��");
				  scanf("%d", &x);
				  SList_PushFront(&pHead, x);
				  printf("����ɹ�\n");
		}
			break;
		case 2:
		{
				  int x = 0;
				  printf("����������ֵ��");
				  scanf("%d", &x);
				  SList_PushBack(&pHead, x);
				  printf("����ɹ�\n");
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
				  printf("����������ֵ��");
				  scanf("%d", &x);
				  printf("���������ĺϷ�λ�ã�");
				  scanf("%d", &y);
				  while (--y > 0)
				  {
					  pos = pos->_next;
				  }
				  SList_Insert(&pHead, pos, x);
				  printf("����ɹ�\n");
		}
			break;
		case 6:
		{
				  int y = 0;
				  SListNode* pos = pHead;
				  printf("������ɾ���ĺϷ�λ�ã�");
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
				  printf("��������ҵ�ֵ��");
				  scanf("%d", &x);
				  if (SList_Find(pHead, x))
				  {
					  printf("�ҵ���\n");
				  }
				  else
				  {
					  printf("δ�ҵ�\n");
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
			printf("������ѡ��...\n");
			break;
		}
	} while (op);
	system("pause");
	return 0;
}