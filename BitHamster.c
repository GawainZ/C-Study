#include <stdio.h>
#include <stdlib.h>	//system("cls")
#include <conio.h>	//getch()
void PrintHamster(int hamster[]);
int main()
{
	int count;	//总共打掉的地鼠 
	int hamster[]={1,1,1};
	PrintHamster(hamster);
	while(1){
		int a = getch();
		if(a==48||a==49||a==50){	//判断按键 
			a=a-48;
			if(hamster[a]==1){	//是否有地鼠 
				hamster[a]=0; 
				count++;	//打掉地鼠+1 
				system("cls");	//清屏 
				PrintHamster(hamster);	//重新打印地图 
				printf("\n打掉%d个地鼠！",count);
			}
		}
	}
}
void PrintHamster(int hamster[]){
	int i;
	for(i=0;i<3;i++){
		if(hamster[i]==1){
			printf("【%d】*   ",i);
		}else{
			printf("【%d】    ",i);
		}
	}
	printf("\n"); 
}
