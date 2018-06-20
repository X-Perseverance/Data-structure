#define _CRT_SECURE_NO_WARNINGS 1

#include "Maze.h"

//栈初始化
void StackInit(Stack* s)
{
    assert(s);
    s->_size = 0;
    s->_capacity = Initsize;
    s->_array = (DataType*)malloc(Initsize*sizeof(DataType));
    assert(s->_array);
    memset(s->_array, 0, s->_capacity * sizeof(DataType));
}

//扩容
void CheckCapacity(Stack* s)
{
    assert(s);
    if (s->_size >= s->_capacity)
    {
        DataType* ptr = (DataType*)realloc(s->_array, (s->_capacity + Increment)*sizeof(DataType));
        assert(ptr);
        s->_array = ptr;
        s->_capacity += Increment;
    }
}

//入栈
void StackPush(Stack* s, DataType x)
{
    assert(s);
    CheckCapacity(s);
    s->_array[s->_size] = x;
    s->_size++;
}

//出栈
void StackPop(Stack* s)
{
    assert(s);
    if (s->_size == 0)
    {
        return;
    }
    else
    {
        s->_size--;
    }
}

//获取栈顶元素
DataType StackTop(Stack* s)
{
    assert(s&&s->_size > 0);
    return s->_array[(s->_size) - 1];
}

//栈长度
size_t StackSize(Stack* s)
{
    assert(s);
    return s->_size;
}

//销毁
void StackDestroy(Stack* s)
{
    free(s->_array);
    s->_size = 0;
    s->_capacity = 0;
}

//初始化迷宫
void MazeInit(Maze* m)
{
    assert(m);
    int a[N][N] =
    {
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 0 },
        { 0, 0, 1, 0, 1, 1 },
        { 0, 0, 1, 1, 1, 0 },
        { 0, 0, 1, 0, 0, 0 },
    };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m->maze[i][j] = a[i][j];
        }
    }
    m->entry.row = 5;
    m->entry.col = 2;
}

//打印迷宫
void MazePrint(Maze* m)
{
    assert(m);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", m->maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//判断是否为出口，假设出口在最后一列
int MazeCheckIsAccess(Pos pos)
{
    if (pos.col == N - 1)
    {
        return 1;
    }
    return 0;
}

//单通路标记
void MarkPath(Maze** pm, Pos entry)
{
    (*pm)->maze[entry.row][entry.col] = 2;
}

//寻找单通路——只能处理单条路径
void MazeGetPath(Maze* m, Pos entry, Stack *path)
{
    assert(m);
    if (entry.row < 0 || entry.row >= N || entry.col < 0 || entry.col >= N) //坐标不合法,直接返回
    {
        return;
    }

    if (m->maze[entry.row][entry.col] == 1) //如果是路，就入栈，并进行标记
    {
        StackPush(path, entry);
        MarkPath(&m, entry);
    }
    else //否则，直接返回
    {
        return;
    }

    if (MazeCheckIsAccess(entry)) //判断是否到达出口
    {
        printf("找到出口！\n");
        printf("出口坐标：%d %d\n", StackTop(path).row, StackTop(path).col);
        printf("路径长度为：%d\n", StackSize(path));
        printf("路径为：");
        for (int i = 0; i < (int)path->_size; i++)
        {
            printf("(%d,%d) ", path->_array[i].row, path->_array[i].col);
        }
        printf("\n");
        StackPop(path); //通路上其他非出口位置是经4个方向都找过后才Pop并返回上一位置；而出口位置是不需要查找4个方向，直接Pop并返回上一位置
        MazePrint(m);
        return;
    }

    //如果没有找到出口，分别在当前位置的4个方向继续寻找
    //上
    Pos up_pos = entry;
    up_pos.row--;
    MazeGetPath(m, up_pos, path);
    //下
    Pos down_pos = entry;
    down_pos.row++;
    MazeGetPath(m, down_pos, path);
    //左
    Pos left_pos = entry;
    left_pos.col--;
    MazeGetPath(m, left_pos, path);
    //右
    Pos right_pos = entry;
    right_pos.col++;
    MazeGetPath(m, right_pos, path);

    StackPop(path);
    return;
}

//复制栈
void StackCopy(Stack *src, Stack *dst)
{
    assert(src&&dst);
    if (src->_size == 0)
    {
        dst->_size = 0;
    }
    else
    {
        if (dst->_capacity < src->_size)
        {
            DataType *ptr = (DataType *)realloc(dst->_array, src->_size*sizeof(DataType));
            assert(ptr);
            dst->_array = ptr;
            dst->_capacity = src->_size;
        }
        dst->_size = src->_size;
        memcpy(dst->_array, src->_array, sizeof(DataType)*src->_size);
    }
}

//标记通路
void MarkPath1(Maze** pm, Pos entry, int flag)
{
    (*pm)->maze[entry.row][entry.col] = flag;
}

//寻找最短路径——可处理多条路径
void MazeGetShortPath(Maze* m, Pos entry, Stack *path, Stack *shortpath, int flag)
{
    assert(m);
    if (entry.row < 0 || entry.row >= N || entry.col < 0 || entry.col >= N) //坐标不合法,直接返回
    {
        return;
    }

    if (m->maze[entry.row][entry.col] == 1 || m->maze[entry.row][entry.col]>flag) //如果是路或者有更短的路，就入栈，并进行标记
    {
        StackPush(path, entry);
        MarkPath1(&m, entry, flag++);
    }
    else //否则，直接返回
    {
        return;
    }

    if (MazeCheckIsAccess(entry)) //判断是否到达出口
    {
        printf("找到出口！\n");
        printf("出口坐标：%d %d\n", StackTop(path).row, StackTop(path).col);
        printf("路径长度为：%d\n", StackSize(path));
        printf("路径为：");
        for (int i = 0; i < (int)path->_size; i++)
        {
            printf("(%d,%d) ", path->_array[i].row, path->_array[i].col);
        }
        printf("\n");

        if (StackSize(shortpath) == 0 || StackSize(path) < StackSize(shortpath))
        {
            StackCopy(path, shortpath); //保存最短路径
        }

        StackPop(path); //通路上其他非出口位置是经4个方向都找过后才Pop并返回上一位置；而出口位置是不需要查找4个方向，直接Pop并返回上一位置
        MazePrint(m);
        return;
    }

    //如果没有找到出口，分别在当前位置的4个方向继续寻找
    //上
    Pos up_pos = entry;
    up_pos.row--;
    MazeGetShortPath(m, up_pos, path, shortpath, flag);
    //下
    Pos down_pos = entry;
    down_pos.row++;
    MazeGetShortPath(m, down_pos, path, shortpath, flag);
    //左
    Pos left_pos = entry;
    left_pos.col--;
    MazeGetShortPath(m, left_pos, path, shortpath, flag);
    //右
    Pos right_pos = entry;
    right_pos.col++;
    MazeGetShortPath(m, right_pos, path, shortpath, flag);

    StackPop(path);
    return;
}