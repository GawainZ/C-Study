#include <stdio.h>
int main()
{
    int i, j;
    for(i = 1; i < 10; i++)
    {
        for(j = 1; j < i+1; j++)
        {
            printf("%dX%d=%d", i, j, i * j);
        }
        printf("\n");
    }
    getchar();
}