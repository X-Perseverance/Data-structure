#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Menu()
{
	printf("**********贪吃蛇游戏**********\n");
	printf("**                          **\n");
	printf("**        1.开始游戏        **\n");
	printf("**        0.退出游戏        **\n");
	printf("**                          **\n");
	printf("******************************\n");
}

int main()
{
	system("mode con cols=100 lines=32");
	int op = 0;
	do{
		Menu();
		printf("请选择：");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
				  Snake *head = NULL;
				  Food *food = NULL;
				  int perscore = 10;
				  int score = 0;
				  int sleeptime = 300;

				  InitGame(&head, &food);
				  ControlGame(&head, &food, score, perscore, sleeptime);

				  Snake* tail = NULL;
				  while (head)
				  {
					  tail = head->next;
					  free(head);
					  head = tail;
				  }

				  free(food);
				  food = NULL;

				  system("pause");
				  system("cls");
		}
			break;
		case 0:
		{
				  system("pause");
				  return 0;
		}
			break;
		}
	} while (op);
}