#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
/*1．数据域为字符的一棵二叉树用广义表形式输入，创建一个采用二叉链表存储的二叉树，并按广义表的形式输出这棵二叉树。√
2．在实验1的基础上完成这棵二叉树的中序遍历的递归算法。
3．在实验1的基础上完成这棵二叉树的中序遍历的非递归算法。*/




int main(){
	int chose;
	while (1) {
		system("title 二叉树的操作");
		menu();
		scanf("%d", &chose);
		getchar();
		switch (chose) {
		case 1:
			system("cls");
			main1();
			break;
		case 2:
			system("cls");
			main2();
			break;
		case 0:
			printf("退出成功！\n");
			return;
		default:printf("输入错误，重新输入：\n");
		}
	}
	return 0;
}

void menu() {
	printf("请输入：\n");
	printf("=======================\n");
	printf("=====*二叉树的操作=====\n");
	printf("=====1、顺序二叉树=====\n");
	printf("=====2、链式二叉树=====\n");
	printf("=====0、退      出=====\n");
	printf("=======================\n");
}