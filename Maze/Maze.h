#ifndef __Maze_h__
#define __Maze_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

#define N 6
#define Initsize 5 //初始存储空间
#define Increment 2 //每次增量

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
    size_t _size; //有效数据个数 
    size_t _capacity; //容量 
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