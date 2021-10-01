#define _CRT_SECURE_NO_WARNINGS 1

/*所有函数声明和结构体声明都在这个头文件里*/
#include"Queue.h"


void menu() {
	printf("###################\n");
	printf("      请选择：\n");
	printf("    1、顺序队\n");
	printf("    2、链队\n");
	printf("    3、奇偶分配\n");
	printf("    0、退出\n");
	printf("###################\n");
}

int main(){
	int chose;
	system("title 队列的操作");
	while (1) {
		system("cls");				//清屏
		menu();						//主菜单
		scanf("%d", &chose);		
		switch (chose) {
		case 1:						//进入顺序队的操作
			system("cls");
			system("title 顺序队");
			main1();				//顺序对的主函数
			break;
		case 2:						//进入链队的操作
			system("cls");
			system("title 链队");
			main2();				//联队的主函数
			break;
		case 3:
			system("cls");
			system("title 奇偶分配");
			main3();
			system("pause");
			break;
		case 0:return;
		default:printf("输入错误！重新输入:\n"); system("pause");
		}
	}
	return 0;
}
