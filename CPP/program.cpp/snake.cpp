#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 40
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

typedef struct{
    int x;
    int y;
}Food,Snakenode;

typedef struct{
    Snakenode snakeNode[1000];
    int length;
    int speed;
}Snake;

void GotoXY(int x,int y);
void Hide();
int Menu();
void Help();
void About();
void InitMap();
void PrintFood();
int MoveSnake();
int IsCorrect();
void SpeedControl();

Snake snake;
Food food;
char now_Dir = RIGHT;
char direction = RIGHT;

int main ()
{
    srand((unsigned int)time(0));
    int end = 1,result;
    while(end)
    {
        result = Menu();
        switch(result)
        {
            case 1:
                InitMap();
                while(MoveSnake());
                break;
            case 2:
                Help();
                break;
            case 3:
                About();
                break;
            case 0:
                end = 0;break;
        }
    }
    return 0;
}
int Menu()
{
    GotoXY(40,12);
    printf("欢迎来到贪吃蛇小游戏");
    GotoXY(43,14);
    printf("1,开始游戏");
    GotoXY(43,16);
    printf("2,帮助");
    GotoXY(43,18);
    printf("3,关于");
    GotoXY(43,20);
    printf("其他任意键退出游戏");
    Hide();
    char ch;
    int result = 0;
    ch = _getch();
    switch(ch)
    {
        case '1':result = 1;break;
        case '2':result = 2;break;
        case '3':result = 3;break;
    }
    system("cls");
    return result;
}
void GotoXY(int x,int y)
{
    HANDLE hout;
    COORD cor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout,cor);
}
void Hide()
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cor_info = {1,0};
    SetConsoleCursorInfo(hout,&cor_info);
}
void About()
{
    GotoXY(30,12);
    printf("HDU--程序设计综合实践案例");
    GotoXY(43,14);
    printf("贪吃蛇小游戏");
    GotoXY(43,16);
    printf("返回上一级菜单");
    Hide();
    char ch = _getch();
    system("cls");
}
void Help()
{
    GotoXY(40,12);
    printf("w上");
    GotoXY(40,14);
    printf("s下");
    GotoXY(40,16);
    printf("a左");
    GotoXY(40,18);
    printf("d右");
    GotoXY(40,20);
    printf("当蛇撞到自身或撞墙时游戏结束");
    GotoXY(45,22);
    printf("按任意键返回上级菜单");
    Hide();
    char ch = _getch();
    system("cls");
}
void InitMap()
{
    Hide();
    snake.snakeNode[0].x = MAP_WIDTH/2-1;
    snake.snakeNode[0].y = MAP_HEIGHT/2-1;
    GotoXY(snake.snakeNode[0].x,snake.snakeNode[0].y);
    printf("@");
    snake.length = 3;
    snake.speed = 250;
    now_Dir = RIGHT;
    for(int i=1;i<snake.length;i++)
    {
        snake.snakeNode[i].y = snake.snakeNode[i-1].x;
        snake.snakeNode[i].x = snake.snakeNode[i-1].x-1;
        GotoXY(snake.snakeNode[i].x,snake.snakeNode[i].y);
        printf("o");
    }
    for(int i=0;i<MAP_WIDTH;i++)
    {
        GotoXY(i,0);
        printf("-");
        GotoXY(i,MAP_HEIGHT-1);
        printf("-");
    }
    for(int i=1;i<MAP_HEIGHT-1;i++)
    {
        GotoXY(0,i);
        printf("|");
        GotoXY(MAP_WIDTH-1,i);
        printf("|");
    }
    PrintFood();
    GotoXY(50,5);
    printf("当前得分:0");
}
void PrintFood()
{
    int flag = 1;
    while(flag)
    {
        flag = 0;
        food.x = rand()%(MAP_WIDTH-2)+1;
        food.y = rand()%(MAP_HEIGHT-2)+1;
        for(int k=0;k<snake.length-1;k++)
        {
            if(snake.snakeNode[k].x==food.x&&snake.snakeNode[k].y==food.y)
            {
                flag = 1;
                break;
            }
        }
    }
    GotoXY(food.x,food.y);
    printf("$");
}
int MoveSnake()
{
    Snakenode temp;
    int flag = 0;
    temp = snake.snakeNode[snake.length-1];
    for(int i=snake.length-1;i>=1;i--)
    {
        snake.snakeNode[i] = snake.snakeNode[i-1];
    }
    GotoXY(snake.snakeNode[1].x,snake.snakeNode[1].y);
    printf("o");
    if(_kbhit())
    {
        direction = _getch();
        switch(direction)
        {
            case UP:
                if(now_Dir!=DOWN)
                    now_Dir = direction;
                break;
            case DOWN:
                if(now_Dir!=UP)
                    now_Dir = direction;
                break;
            case LEFT:
                if(now_Dir!=RIGHT)
                    now_Dir = direction;
                break;
            case RIGHT:
                if(now_Dir!=LEFT)
                    now_Dir = direction;
                break;
        }
    }
    switch(now_Dir)
    {
        case UP:snake.snakeNode[0].y--;break;
        case DOWN:snake.snakeNode[0].y++;break;
        case LEFT:snake.snakeNode[0].x--;break;
        case RIGHT:snake.snakeNode[0].x++;break;
    }
    GotoXY(snake.snakeNode[0].x,snake.snakeNode[0].y);
    printf("@");
    if(snake.snakeNode[0].x==food.x&&snake.snakeNode[0].y==food.y)
    {
        snake.length++;
        flag = 1;
        snake.snakeNode[snake.length-1] = temp;
    }
    if(!flag)
    {
        GotoXY(temp.x,temp.y);
        printf(" ");
    }
    else 
    {
        PrintFood();
        GotoXY(50,5);
        printf("当前得分:%d",snake.length-3);
    }
    if(!IsCorrect())
    {
        system("cls");
        GotoXY(45,14);
        printf("最终得分:%d",snake.length-3);
        GotoXY(45,16);
        printf("你输了!");
        GotoXY(45,18);
        printf("按任意键返回主菜单");
        char c = _getch();
        system("cls");
        return 0;
    }
    SpeedControl();
    Sleep(snake.speed);
    return 1;
}
int IsCorrect()
{
    if(snake.snakeNode[0].x==0||snake.snakeNode[0].y==0||snake.snakeNode[0].x==MAP_WIDTH-1||snake.snakeNode[0].y==MAP_HEIGHT-1)
    return 0;
    for(int i=1;i<snake.length;i++)
    {
        if(snake.snakeNode[0].x==snake.snakeNode[i].x&&snake.snakeNode[0].y==snake.snakeNode[i].y)
        return 0;
    }
    return 1;
}
void SpeedControl()
{
    switch(snake.length)
    {
        case 6:snake.speed = 200;break;
        case 9:snake.speed = 180;break;
        case 12:snake.speed = 160;break;
        case 15:snake.speed = 140;break;
        case 18:snake.speed = 120;break;
        case 21:snake.speed = 100;break;
        case 24:snake.speed = 80;break;
        case 27:snake.speed = 60;break;
        case 30:snake.speed = 40;break;
        default:break;
    }
}

