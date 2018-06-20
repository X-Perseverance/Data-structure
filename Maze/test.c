#define _CRT_SECURE_NO_WARNINGS 1

#include "Maze.h"

int main()
{
    Maze m;
    MazeInit(&m);
    MazePrint(&m);

    Stack path;
    Stack shortpath;
    StackInit(&path);
    StackInit(&shortpath);

    MazeGetShortPath(&m, m.entry, &path, &shortpath, 1);

    printf("最短路径长度为：%d\n", StackSize(&shortpath));
    printf("路径为：");
    for (int i = 0; i < (int)shortpath._size; i++)
    {
        printf("(%d,%d) ", shortpath._array[i].row, shortpath._array[i].col);
    }
    printf("\n");

    StackDestroy(&path);
    StackDestroy(&shortpath);

    system("pause");
    return 0;
}