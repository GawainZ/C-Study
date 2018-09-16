#include <stdio.h>
#include <windows.h>
int main()
{
    COORD pos = {15, 0};
    int deposit = 66666;
    while(1)
    {
        int sum=0;
        printf("请输入取款金额：   元");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        scanf("%d", &sum);
        deposit -= sum;
        pos.Y+=2;
        printf("你现在有%d元存款~\n", deposit);
    }
    getchar();
    getchar();
}