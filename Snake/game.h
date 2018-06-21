#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

//蛇移动区域
#define gamewidth 25
#define gameheigth 25

//墙
#define wallwidth (gamewidth+2)
#define wallheigth (gameheigth+2)

//蛇的方向
#define U 1 //上
#define D 2 //下
#define L 3 //左
#define R 4 //右

typedef struct Snake //蛇身的一个节点
{
	int x;
	int y;
	struct Snake *next;
}Snake;

typedef struct Food //食物节点
{
	int x;
	int y;
}Food;

void Pos(int x, int y); //设置光标位置
void StartInterface(); //开始界面
void CreatWall(); //创建墙
void InitSnake(Snake **pphead); //初始化蛇
void CreateFood(Snake *head, Food **ppfood); //创建食物
void InitGame(Snake **pphead, Food **ppfood); //游戏初始化

int TouchWall(Snake *head); //判断是否碰到墙
int BiteSelf(Snake *head); //判断是否咬到了自己

void Pause(); //暂停
void EndGame(int endflag, int score); //结束游戏
void MoveSnake(Snake **pphead, Food **ppfood, int direction, int *score, int perscore); //控制蛇前进
void ControlGame(Snake **pphead, Food **ppfood, int score, int perscore, int sleeptime); //控制游戏

#endif __GAME_H__