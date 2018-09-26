#include <stdio.h>
#define MAX 7 //常量MAX表示系统要求最大的妃子数量
int main()
{
    int count = 5;
    int i;//循环变量
    char emperorName[10]; //皇帝的名号，使用字符数组表示字符串
    int choice;//皇帝的选择1-4之间
    char names[MAX][10] = {"貂蝉", "妲己", "公孙离", "杨玉环", "亚丝娜"};//嫔妃姓名数组
    char LeveNames[5][10] = {"贵妃", "嫔妃", "贵妃", "皇贵妃", "皇后"};//嫔妃级别数组
    int levels[MAX] = {1, 2, 0, 0, 3,-1};                                   //用来存放每位妃子的级别
    int loves[MAX] = {100, 100, 100, 100, 100,-1};//对应每个人的好感度初始好感度为100
    /*printf("测试代码，查看当前嫔妃的状态\n");
    printf("%-12s级别\t好感度\n", "姓名");
    for (i = 0; LeveNames[i][0] != '\0'; i++)
    {
            printf("%-12s%s\t%d\n", names[i], LeveNames[levels[i]], loves[i]);
    }
    */
    printf("请输入皇帝的名号：");
    scanf("%s",emperorName);//录入字符串时，不需要&
    printf("皇帝(%s)驾临,有事上奏,无事退朝！\n", emperorName);
    printf("1、皇上下旨选妃:\n"); //增加功能
    printf("2、翻盘幸宠：\n");//修改状态功能
    printf("3、打入冷宫：\n");//删除功能
    printf("4、单独召见爱妃\n");
    printf("陛下请选择：");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
        //增加数组元素,增加前需要判断数组是否已经满了
        printf("%d",count);
        if (count<MAX) 
        {
            printf("请输入娘娘的名讳：");
            scanf("%s", names[count]);//将第count元素的状态
            levels[count] = 0;//级别初始为0
            loves[count] = 0;//好感度为0
            count++;
        }
        else
        {
            printf("陛下，要注意龙体呀，后宫已3经人满为患了！\n添加失败");
        }
        
            break;
        case 2:
            printf("翻盘幸宠：");
            break;
        case 3:
            printf("打入冷宫：");
            break;
        case 4:
            printf("单独召见爱妃：");
            break;
        default:
            printf("君无戏言，请重新输入");
            break;
    }
    printf("测试代码，查看当前嫔妃的状态\n");
    printf("%-12s级别\t好感度\n", "姓名");
    for (i = 0;i<count ; i++)
    {
        printf("%-12s%s\t%d\n", names[i], LeveNames[levels[i]], loves[i]);
    }
    getchar();
    getchar();
}