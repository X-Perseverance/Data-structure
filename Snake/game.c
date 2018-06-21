#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//���ù��λ��
void Pos(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);

    CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOutput, &cci); //��ȡ��ǰ�����Ϣ 
	cci.bVisible = FALSE; //���ù�겻�ɼ� 
	SetConsoleCursorInfo(hOutput, &cci);
}

//��ʼ����
void StartInterface()
{
	system("cls");
	Pos((50 - strlen("��ӭ����̰ʳ����Ϸ") / 2), 13);
	printf("��ӭ����̰ʳ����Ϸ\n");
	system("pause");
	system("cls");

	Pos((50 - strlen("�á��������������ֱ�����ߵ��ƶ��� F1 Ϊ���٣�F2 Ϊ����") / 2), 13);
	printf("�á��������������ֱ�����ߵ��ƶ��� F1 Ϊ���٣�F2 Ϊ����");
	Pos((50 - strlen("���ٽ��ܵõ����ߵķ���") / 2), 15);
	printf("���ٽ��ܵõ����ߵķ���\n");
	system("pause");
	system("cls");
}

//����ǽ
void CreatWall()
{
	int i = 0;
	// ��
	for (i = 0; i < wallwidth * 2; i = i + 2)
	{
		Pos(i, 0);
		printf("��");
	}
	// ��
	for (i = 0; i < wallwidth * 2; i = i + 2)
	{
		Pos(i, wallheigth - 1);
		printf("��");
	}
	// ��
	for (i = 1; i < wallheigth - 1; i++)
	{
		Pos(0, i);
		printf("��");
	}
	// ��
	for (i = 1; i < wallheigth - 1; i++)
	{
		Pos((wallwidth - 1) * 2, i);
		printf("��");
	}
}

//��ʼ����
void InitSnake(Snake **pphead)
{
	Snake *tail = (Snake *)malloc(sizeof(Snake));
	tail->x = 2;
	tail->y = 2;
	tail->next = NULL;
	for (int i = 1; i < 3; i++) //ͷ�巨
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
		printf("��");
		tail = tail->next;
	}
}

//����ʳ��
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
			if (cur->x == (*ppfood)->x&&cur->y == (*ppfood)->y) //ʳ�ﲻ�ܺ������غ�
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
	printf("��");
}

//��Ϸ��ʼ��
void InitGame(Snake **pphead, Food **ppfood)
{
	StartInterface();
	CreatWall();
	InitSnake(pphead);
	CreateFood(*pphead, ppfood);
}

//�ж��Ƿ�����ǽ
int TouchWall(Snake *head)
{
	if (head->x == 0 || head->x == (wallwidth - 1) * 2 || head->y == 0 || head->y == wallheigth - 1)
	{
		return 1;
	}
	return 0;
}

//�ж��Ƿ�ҧ�����Լ�
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

//��ͣ
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

//������ǰ��
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

	if (nextnode->x == (*ppfood)->x&&nextnode->y == (*ppfood)->y) //��һ��λ����ʳ��
	{
		nextnode->next = *pphead; //ͷ�巨
		*pphead = nextnode;
		Snake *cur = *pphead;
		while (cur)
		{
			Pos(cur->x, cur->y);
			printf("��");
			cur = cur->next;
		}
		*score += perscore;

		free(*ppfood);
		CreateFood(*pphead, ppfood); //�����µ�ʳ��
	}
	else //��һ��λ�ò���ʳ��
	{
		nextnode->next = *pphead;
		*pphead = nextnode;
		Snake *cur = *pphead;
		while (cur->next->next) //�ҵ��������ڶ����ڵ�
		{
			Pos(cur->x, cur->y);
			printf("��");
			cur = cur->next;
		}
		Pos(cur->next->x, cur->next->y);
		printf(" ");
		free(cur->next);
		cur->next = NULL;
	}
}

//������Ϸ
void EndGame(int endflag, int score)
{
	system("cls");
	if (endflag == 1)
	{
		Pos((50 - strlen("���ѽ�������Ϸ") / 2), 13);
		printf("���ѽ�������Ϸ\n");
	}
	else if (endflag == 2)
	{
		Pos((50 - strlen("��Ϸ��������ײ��ǽ��") / 2), 13);
		printf("��Ϸ��������ײ��ǽ��\n");
	}
	else if (endflag == 3)
	{
		Pos((50 - strlen("��Ϸ��������ײ���Լ���") / 2), 13);
		printf("��Ϸ��������ײ���Լ���\n");
	}

	Pos((50 - strlen("�������յ÷��ǣ�  ") / 2), 15);
	printf("�������յ÷��ǣ�%d\n", score);
}

//������Ϸ
void ControlGame(Snake **pphead, Food **ppfood, int score, int perscore, int sleeptime)
{
	Pos(wallwidth * 2 + 10, 12);
	printf("����ײ��ǽ������ײ���Լ�");
	Pos(wallwidth * 2 + 10, 13);
	printf("�á��������������ֱ�����ߵ��ƶ�");
	Pos(wallwidth * 2 + 10, 14);
	printf("F1Ϊ���٣�F2Ϊ����");
	Pos(wallwidth * 2 + 10, 15);
	printf("EscΪ�˳���Ϸ��SpaceΪ��ͣ");

	int direction = R; //�ߵĳ�ʼǰ������
	while (1)
	{
		Pos(wallwidth * 2 + 10, 10);
		printf("�÷֣�%d    ÿ��ʳ��÷֣�%2d", score, perscore);
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