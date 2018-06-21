#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//设置光标位置
void Pos(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);

    CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOutput, &cci); //获取当前光标信息 
	cci.bVisible = FALSE; //设置光标不可见 
	SetConsoleCursorInfo(hOutput, &cci);
}

//开始界面
void StartInterface()
{
	system("cls");
	Pos((50 - strlen("欢迎来到贪食蛇游戏") / 2), 13);
	printf("欢迎来到贪食蛇游戏\n");
	system("pause");
	system("cls");

	Pos((50 - strlen("用↑、↓、←、→分别控制蛇的移动， F1 为加速，F2 为减速") / 2), 13);
	printf("用↑、↓、←、→分别控制蛇的移动， F1 为加速，F2 为减速");
	Pos((50 - strlen("加速将能得到更高的分数") / 2), 15);
	printf("加速将能得到更高的分数\n");
	system("pause");
	system("cls");
}

//创建墙
void CreatWall()
{
	int i = 0;
	// 上
	for (i = 0; i < wallwidth * 2; i = i + 2)
	{
		Pos(i, 0);
		printf("■");
	}
	// 下
	for (i = 0; i < wallwidth * 2; i = i + 2)
	{
		Pos(i, wallheigth - 1);
		printf("■");
	}
	// 左
	for (i = 1; i < wallheigth - 1; i++)
	{
		Pos(0, i);
		printf("■");
	}
	// 右
	for (i = 1; i < wallheigth - 1; i++)
	{
		Pos((wallwidth - 1) * 2, i);
		printf("■");
	}
}

//初始化蛇
void InitSnake(Snake **pphead)
{
	Snake *tail = (Snake *)malloc(sizeof(Snake));
	tail->x = 2;
	tail->y = 2;
	tail->next = NULL;
	for (int i = 1; i < 3; i++) //头插法
	{
		*pphead = (Snake *)malloc(sizeof(Snake));
		(*pphead)->x = 2 + 2 * i;
		(*pphead)->y = 2;
		(*pphead)->next = tail;
		tail = *pphead;
	}
	while (tail != NULL)
	{
		Pos(tail->x, tail->y);
		printf("■");
		tail = tail->next;
	}
}

//创建食物
void CreateFood(Snake *head, Food **ppfood)
{
	int flag = 0;
	srand((unsigned)time(NULL));
	*ppfood = (Food*)malloc(sizeof(Food));

	while (1)
	{
		(*ppfood)->x = (rand() % gameheigth + 1) * 2;
		(*ppfood)->y = rand() % gameheigth + 1;
		Snake *cur = head;
		while (cur)
		{
			if (cur->x == (*ppfood)->x&&cur->y == (*ppfood)->y) //食物不能和蛇身重合
			{
				flag = 1;
				break;
			}
			cur = cur->next;
		}
		if (flag == 0)
		{
			break;
		}
	}

	Pos((*ppfood)->x, (*ppfood)->y);
	printf("■");
}

//游戏初始化
void InitGame(Snake **pphead, Food **ppfood)
{
	StartInterface();
	CreatWall();
	InitSnake(pphead);
	CreateFood(*pphead, ppfood);
}

//判断是否碰到墙
int TouchWall(Snake *head)
{
	if (head->x == 0 || head->x == (wallwidth - 1) * 2 || head->y == 0 || head->y == wallheigth - 1)
	{
		return 1;
	}
	return 0;
}

//判断是否咬到了自己
int BiteSelf(Snake *head)
{
	Snake *cur = head->next;
	while (cur)
	{
		if (cur->x == head->x&&cur->y == head->y)
		{
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

//暂停
void Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}

//控制蛇前进
void MoveSnake(Snake **pphead, Food **ppfood, int direction, int *score, int perscore)
{
	Snake *nextnode = (Snake *)malloc(sizeof(Snake));
	switch (direction)
	{
	case U:
	{
			  nextnode->x = (*pphead)->x;
			  nextnode->y = (*pphead)->y - 1;
	}
		break;
	case D:
	{
			  nextnode->x = (*pphead)->x;
			  nextnode->y = (*pphead)->y + 1;
	}
		break;
	case L:
	{
			  nextnode->x = (*pphead)->x - 2;
			  nextnode->y = (*pphead)->y;
	}
		break;
	case R:
	{
			  nextnode->x = (*pphead)->x + 2;
			  nextnode->y = (*pphead)->y;
	}
		break;
	}

	if (nextnode->x == (*ppfood)->x&&nextnode->y == (*ppfood)->y) //下一个位置是食物
	{
		nextnode->next = *pphead; //头插法
		*pphead = nextnode;
		Snake *cur = *pphead;
		while (cur)
		{
			Pos(cur->x, cur->y);
			printf("■");
			cur = cur->next;
		}
		*score += perscore;

		free(*ppfood);
		CreateFood(*pphead, ppfood); //创建新的食物
	}
	else //下一个位置不是食物
	{
		nextnode->next = *pphead;
		*pphead = nextnode;
		Snake *cur = *pphead;
		while (cur->next->next) //找到蛇身倒数第二个节点
		{
			Pos(cur->x, cur->y);
			printf("■");
			cur = cur->next;
		}
		Pos(cur->next->x, cur->next->y);
		printf(" ");
		free(cur->next);
		cur->next = NULL;
	}
}

//结束游戏
void EndGame(int endflag, int score)
{
	system("cls");
	if (endflag == 1)
	{
		Pos((50 - strlen("您已结束了游戏") / 2), 13);
		printf("您已结束了游戏\n");
	}
	else if (endflag == 2)
	{
		Pos((50 - strlen("游戏结束，您撞到墙了") / 2), 13);
		printf("游戏结束，您撞到墙了\n");
	}
	else if (endflag == 3)
	{
		Pos((50 - strlen("游戏结束，您撞到自己了") / 2), 13);
		printf("游戏结束，您撞到自己了\n");
	}

	Pos((50 - strlen("您的最终得分是：  ") / 2), 15);
	printf("您的最终得分是：%d\n", score);
}

//控制游戏
void ControlGame(Snake **pphead, Food **ppfood, int score, int perscore, int sleeptime)
{
	Pos(wallwidth * 2 + 10, 12);
	printf("不能撞到墙，不能撞到自己");
	Pos(wallwidth * 2 + 10, 13);
	printf("用↑、↓、←、→分别控制蛇的移动");
	Pos(wallwidth * 2 + 10, 14);
	printf("F1为加速，F2为减速");
	Pos(wallwidth * 2 + 10, 15);
	printf("Esc为退出游戏，Space为暂停");

	int direction = R; //蛇的初始前进方向
	while (1)
	{
		Pos(wallwidth * 2 + 10, 10);
		printf("得分：%d    每个食物得分：%2d", score, perscore);
		if (GetAsyncKeyState(VK_UP) && direction != D)
		{
			direction = U;
		}
		else if (GetAsyncKeyState(VK_DOWN) && direction != U)
		{
			direction = D;
		}
		else if (GetAsyncKeyState(VK_LEFT) && direction != R)
		{
			direction = L;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && direction != L)
		{
			direction = R;
		}
		else if (GetAsyncKeyState(VK_F1))
		{
			if (sleeptime > 100)
			{
				sleeptime -= 200;
				perscore += 5;
			}
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			if (sleeptime < 500)
			{
				sleeptime += 200;
				perscore -= 5;
			}
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			Pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			EndGame(1, score);
			return;
		}

		MoveSnake(pphead, ppfood, direction, &score, perscore);
		Sleep(sleeptime);

		if (TouchWall(*pphead))
		{
			EndGame(2, score);
			return;
		}
		if (BiteSelf(*pphead))
		{
			EndGame(3, score);
			return;
		}
	}
}