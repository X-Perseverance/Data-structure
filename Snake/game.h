#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

//���ƶ�����
#define gamewidth 25
#define gameheigth 25

//ǽ
#define wallwidth (gamewidth+2)
#define wallheigth (gameheigth+2)

//�ߵķ���
#define U 1 //��
#define D 2 //��
#define L 3 //��
#define R 4 //��

typedef struct Snake //�����һ���ڵ�
{
	int x;
	int y;
	struct Snake *next;
}Snake;

typedef struct Food //ʳ��ڵ�
{
	int x;
	int y;
}Food;

void Pos(int x, int y); //���ù��λ��
void StartInterface(); //��ʼ����
void CreatWall(); //����ǽ
void InitSnake(Snake **pphead); //��ʼ����
void CreateFood(Snake *head, Food **ppfood); //����ʳ��
void InitGame(Snake **pphead, Food **ppfood); //��Ϸ��ʼ��

int TouchWall(Snake *head); //�ж��Ƿ�����ǽ
int BiteSelf(Snake *head); //�ж��Ƿ�ҧ�����Լ�

void Pause(); //��ͣ
void EndGame(int endflag, int score); //������Ϸ
void MoveSnake(Snake **pphead, Food **ppfood, int direction, int *score, int perscore); //������ǰ��
void ControlGame(Snake **pphead, Food **ppfood, int score, int perscore, int sleeptime); //������Ϸ

#endif __GAME_H__