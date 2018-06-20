#define _CRT_SECURE_NO_WARNINGS 1

#include "Maze.h"

//ջ��ʼ��
void StackInit(Stack* s)
{
    assert(s);
    s->_size = 0;
    s->_capacity = Initsize;
    s->_array = (DataType*)malloc(Initsize*sizeof(DataType));
    assert(s->_array);
    memset(s->_array, 0, s->_capacity * sizeof(DataType));
}

//����
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

//��ջ
void StackPush(Stack* s, DataType x)
{
    assert(s);
    CheckCapacity(s);
    s->_array[s->_size] = x;
    s->_size++;
}

//��ջ
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

//��ȡջ��Ԫ��
DataType StackTop(Stack* s)
{
    assert(s&&s->_size > 0);
    return s->_array[(s->_size) - 1];
}

//ջ����
size_t StackSize(Stack* s)
{
    assert(s);
    return s->_size;
}

//����
void StackDestroy(Stack* s)
{
    free(s->_array);
    s->_size = 0;
    s->_capacity = 0;
}

//��ʼ���Թ�
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

//��ӡ�Թ�
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

//�ж��Ƿ�Ϊ���ڣ�������������һ��
int MazeCheckIsAccess(Pos pos)
{
    if (pos.col == N - 1)
    {
        return 1;
    }
    return 0;
}

//��ͨ·���
void MarkPath(Maze** pm, Pos entry)
{
    (*pm)->maze[entry.row][entry.col] = 2;
}

//Ѱ�ҵ�ͨ·����ֻ�ܴ�����·��
void MazeGetPath(Maze* m, Pos entry, Stack *path)
{
    assert(m);
    if (entry.row < 0 || entry.row >= N || entry.col < 0 || entry.col >= N) //���겻�Ϸ�,ֱ�ӷ���
    {
        return;
    }

    if (m->maze[entry.row][entry.col] == 1) //�����·������ջ�������б��
    {
        StackPush(path, entry);
        MarkPath(&m, entry);
    }
    else //����ֱ�ӷ���
    {
        return;
    }

    if (MazeCheckIsAccess(entry)) //�ж��Ƿ񵽴����
    {
        printf("�ҵ����ڣ�\n");
        printf("�������꣺%d %d\n", StackTop(path).row, StackTop(path).col);
        printf("·������Ϊ��%d\n", StackSize(path));
        printf("·��Ϊ��");
        for (int i = 0; i < (int)path->_size; i++)
        {
            printf("(%d,%d) ", path->_array[i].row, path->_array[i].col);
        }
        printf("\n");
        StackPop(path); //ͨ·�������ǳ���λ���Ǿ�4�������ҹ����Pop��������һλ�ã�������λ���ǲ���Ҫ����4������ֱ��Pop��������һλ��
        MazePrint(m);
        return;
    }

    //���û���ҵ����ڣ��ֱ��ڵ�ǰλ�õ�4���������Ѱ��
    //��
    Pos up_pos = entry;
    up_pos.row--;
    MazeGetPath(m, up_pos, path);
    //��
    Pos down_pos = entry;
    down_pos.row++;
    MazeGetPath(m, down_pos, path);
    //��
    Pos left_pos = entry;
    left_pos.col--;
    MazeGetPath(m, left_pos, path);
    //��
    Pos right_pos = entry;
    right_pos.col++;
    MazeGetPath(m, right_pos, path);

    StackPop(path);
    return;
}

//����ջ
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

//���ͨ·
void MarkPath1(Maze** pm, Pos entry, int flag)
{
    (*pm)->maze[entry.row][entry.col] = flag;
}

//Ѱ�����·�������ɴ������·��
void MazeGetShortPath(Maze* m, Pos entry, Stack *path, Stack *shortpath, int flag)
{
    assert(m);
    if (entry.row < 0 || entry.row >= N || entry.col < 0 || entry.col >= N) //���겻�Ϸ�,ֱ�ӷ���
    {
        return;
    }

    if (m->maze[entry.row][entry.col] == 1 || m->maze[entry.row][entry.col]>flag) //�����·�����и��̵�·������ջ�������б��
    {
        StackPush(path, entry);
        MarkPath1(&m, entry, flag++);
    }
    else //����ֱ�ӷ���
    {
        return;
    }

    if (MazeCheckIsAccess(entry)) //�ж��Ƿ񵽴����
    {
        printf("�ҵ����ڣ�\n");
        printf("�������꣺%d %d\n", StackTop(path).row, StackTop(path).col);
        printf("·������Ϊ��%d\n", StackSize(path));
        printf("·��Ϊ��");
        for (int i = 0; i < (int)path->_size; i++)
        {
            printf("(%d,%d) ", path->_array[i].row, path->_array[i].col);
        }
        printf("\n");

        if (StackSize(shortpath) == 0 || StackSize(path) < StackSize(shortpath))
        {
            StackCopy(path, shortpath); //�������·��
        }

        StackPop(path); //ͨ·�������ǳ���λ���Ǿ�4�������ҹ����Pop��������һλ�ã�������λ���ǲ���Ҫ����4������ֱ��Pop��������һλ��
        MazePrint(m);
        return;
    }

    //���û���ҵ����ڣ��ֱ��ڵ�ǰλ�õ�4���������Ѱ��
    //��
    Pos up_pos = entry;
    up_pos.row--;
    MazeGetShortPath(m, up_pos, path, shortpath, flag);
    //��
    Pos down_pos = entry;
    down_pos.row++;
    MazeGetShortPath(m, down_pos, path, shortpath, flag);
    //��
    Pos left_pos = entry;
    left_pos.col--;
    MazeGetShortPath(m, left_pos, path, shortpath, flag);
    //��
    Pos right_pos = entry;
    right_pos.col++;
    MazeGetShortPath(m, right_pos, path, shortpath, flag);

    StackPop(path);
    return;
}