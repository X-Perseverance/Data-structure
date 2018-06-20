#ifndef __Maze_h__
#define __Maze_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

#define N 6
#define Initsize 5 //��ʼ�洢�ռ�
#define Increment 2 //ÿ������

typedef struct Pos
{
    int row;
    int col;
}Pos;

typedef Pos DataType;

typedef struct Maze
{
    int maze[N][N];
    Pos entry;
}Maze;

typedef struct Stack
{
    DataType* _array;
    size_t _size; //��Ч���ݸ��� 
    size_t _capacity; //���� 
}Stack;

void StackInit(Stack *s);
void CheckCapacity(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
void StackDestroy(Stack* s);

void MazeInit(Maze* m);
void MazePrint(Maze* m);

int MazeCheckIsAccess(Pos pos);

void MazeGetPath(Maze* m, Pos entry, Stack *path);
void MazeGetShortPath(Maze* m, Pos entry, Stack *path, Stack *shortpath, int flag);

#endif __Maze_h__