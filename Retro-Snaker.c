#include <conio.h> //getch()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   //srand()
#include <unistd.h> //Sleep
#include <windows.h>
//地图大小 可以修改
#define X 18
#define Y 40
typedef struct _snake
{
    int x, y;
    struct _snake *next;
} Snake;

typedef struct _list
{
    Snake *head; //蛇头
    Snake *tail; //蛇尾
    int fx, fy;
} List;


int map[X][Y]; //' '为地图 @代表蛇头 O为蛇身体 *代表食物 #代表边界

int sp = 75; //蛇头的方向 初始为左

int score; //分数

void snake_build(List *list); //初始化蛇(包括食物)

void snake_move(List *list, int up); //up为移动方向

void snake_map(List *list); //初始化地图

void print_map(void); //打印整个地图

void food_build(List *list); //随机生成食物

int game_over(List *list); //自刎返回1 撞墙返回2

int main()
{
    List list;
    list.head = list.tail = NULL; //蛇头蛇尾链表
    snake_build(&list);           //初始化蛇
    snake_map(&list);             //将蛇复制进地图数组 并打印
    //用户操作
    int up;
    while (1)
    {
        if (_kbhit())
        {
            up = getch();
            if (up == 72 || up == 80 || up == 75 || up == 77) //屏蔽除了上下左右以外的ascii码
            {
                //不能走反方向
                if ((sp == 75 && up != 77) || (sp == 72 && up != 80) || (sp == 80 && up != 72) || (sp == 77 && up != 75))
                {
                    snake_move(&list, up);
                    if (game_over(&list))
                    {
                        break;
                    }
                    snake_map(&list);
                }
            }
        }
        else
        {
            snake_move(&list, sp);
            if (game_over(&list))
            {
                break;
            }
            snake_map(&list);
        }
        Sleep(100); //数值越小 难度越高
    }
    system("cls");
    printf(" _____       ___       ___  ___   _____        _____   _     _   _____   _____   \n");
    printf("/  ___|     /   |     /   |/   | | ____|      /  _  \\ | |   / / | ____| |  _  \\  \n");
    printf("| |        / /| |    / /|   /| | | |__        | | | | | |  / /  | |__   | |_| |  \n");
    printf("| |  _    / / | |   / / |__/ | | |  __|       | | | | | | / /   |  __|  |  _  /  \n");
    printf("| |_| |  / /  | |  / /       | | | |___       | |_| | | |/ /    | |___  | | \\ \\  \n");
    printf("\\_____/ /_/   |_| /_/        |_| |_____|      \\_____/ |___/     |_____| |_|  \\_\\ \n");
    printf("\n*********************************你的分数：%-4d*********************************", score);
    getchar();
}

void snake_build(List *list) //初始化蛇
{
    int x = 10, y;
    for (y = 18; y < 22; y++)
    {
        Snake *p = (Snake *)malloc(sizeof(Snake));
        p->x = x;
        p->y = y;
        p->next = NULL;
        if (list->head)
        {
            list->tail->next = p;
            list->tail = p;
        }
        else
        {
            list->head = p;
            list->tail = p;
        }
    }
    food_build(list);
}

void snake_move(List *list, int up)
{
    Snake *p = (Snake *)malloc(sizeof(Snake));
    switch (up)
    {
    case 72: //上移
        //插头
        p->x = list->head->x - 1;
        p->y = list->head->y;
        p->next = list->head;
        list->head = p;
        sp = 72; //改变方向
        break;
    case 80: //下移
        p->x = list->head->x + 1;
        p->y = list->head->y;
        p->next = list->head;
        list->head = p;
        sp = 80;
        break;
    case 75: //左移
        p->x = list->head->x;
        p->y = list->head->y - 1;
        p->next = list->head;
        list->head = p;
        sp = 75;
        break;
    case 77: //右移
        p->x = list->head->x;
        p->y = list->head->y + 1;
        p->next = list->head;
        list->head = p;
        sp = 77;
        break;
    }
    //判断是否吃到食物
    if (list->head->x == list->fx && list->head->y == list->fy)
    {
        score += 100; //吃到食物加分
        food_build(list);
    }
    else
    {
        Snake *p2 = NULL;
        for (p2 = list->head; p2->next != list->tail; p2 = p2->next)
            ; //遍历到尾部前一个
        //去掉尾巴
        free(list->tail);
        list->tail = p2;
        p2->next = NULL;
    }

    //去尾(判断是否吃到食物 吃到不去尾)
}

void snake_map(List *list)
{
    int i, j;
    //生成边界#
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            if (i == 0 || j == 0 || i == X - 1 || j == Y - 1) //边界条件
            {
                map[i][j] = '#';
            }
            else
            {
                map[i][j] = ' ';
            }
        }
    }
    //链表进数组
    Snake *p = list->head;
    map[p->x][p->y] = '@';
    for (p = p->next; p; p = p->next)
    {
        map[p->x][p->y] = 'O';
    }
    //食物：
    map[list->fx][list->fy] = '*';
    print_map(); //初始完毕 打印
}

void print_map(void)
{
    system("cls"); //清除屏幕

    int i, j;
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("------------ 你的分数：%-4d ------------", score);
}

void food_build(List *list)
{
    srand((int)time(NULL));
    list->fx = (rand() % 16) + 1;
    list->fy = (rand() % 38) + 1;
}

int game_over(List *list)
{
    int over = 0;
    //判断是否自刎
    Snake *p;
    for (p = list->head->next; p; p = p->next)
    {
        if (list->head->x == p->x && list->head->y == p->y)
        {
            over = 1; //吃到自己
        }
    }
    //判断是否撞墙
    p = list->head;
    if (p->x == 0 || p->y == 0 || p->x == X - 1 || p->y == Y - 1) //边界条件
    {
        over = 2; //撞到墙壁
    }
    return over;
}
