#include <stdio.h>
int main()
{
    char word[6] = "Happy";
    for (int i = 0; i < 5; i++)
    {
        printf("%c", word[i] + 5);
    }
    getchar();
    getchar();
}