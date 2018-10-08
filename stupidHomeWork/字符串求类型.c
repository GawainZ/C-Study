#include<stdio.h>
int retType(char a);
int main()
{
    char str[100];
    printf("***AI智能计算字符串类型牛逼PLUS***\n");
    gets(str);
    int letter=0, number=0, spac=0,none=0;
    for (int i = 0; str[i] != 0; i++)
    {
        int f = retType(str[i]);
        if (f == 1)
        {
            letter++;
        }else if(f == 2)
        {
            number++;
        }else if(f==3)
        {
            spac++;
        }else{
            none++;
        }
    }
    printf("字符串内包含以下类型\n");
    printf("字母=%d,数字=%d,空格=%d,还有不知道的=%d", letter, number, spac, none);
    getchar();
    getchar();
}
int retType(char a)
{
    if(a>=97&&a<=122)
    {
        return 1;
    }else if(a>=48&&a<=57)
    {
        return 2;
    }else if(a==' ')
    {
        return 3;
    }
    return 0;
}