#include <stdio.h>
#include <stdlib.h>	//system("cls")
#include <conio.h>	//getch()
void PrintHamster(int hamster[]);
int main()
{
	int count;	//�ܹ�����ĵ��� 
	int hamster[]={1,1,1};
	PrintHamster(hamster);
	while(1){
		int a = getch();
		if(a==48||a==49||a==50){	//�жϰ��� 
			a=a-48;
			if(hamster[a]==1){	//�Ƿ��е��� 
				hamster[a]=0; 
				count++;	//�������+1 
				system("cls");	//���� 
				PrintHamster(hamster);	//���´�ӡ��ͼ 
				printf("\n���%d������",count);
			}
		}
	}
}
void PrintHamster(int hamster[]){
	int i;
	for(i=0;i<3;i++){
		if(hamster[i]==1){
			printf("��%d��*   ",i);
		}else{
			printf("��%d��    ",i);
		}
	}
	printf("\n"); 
}
