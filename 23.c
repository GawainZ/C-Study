#include <stdio.h>
#include <stdlib.h>
int main()
{
    char LeveNames[9][10] = {"贵妃", "嫔妃", "贵妃", "皇贵妃", "皇后","djai"}; //嫔妃级别数组
    int count = 0;
    for(int i = 0; LeveNames[i][0] != '\0'; i++)
    {
        count++;
        printf("%s", LeveNames[i]);
    }
    printf("%d", count);
    getchar();
    getchar();
    
}
