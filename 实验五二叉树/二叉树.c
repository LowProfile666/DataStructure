#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
/*1��������Ϊ�ַ���һ�ö������ù������ʽ���룬����һ�����ö�������洢�Ķ�������������������ʽ�����ö���������
2����ʵ��1�Ļ����������ö���������������ĵݹ��㷨��
3����ʵ��1�Ļ����������ö���������������ķǵݹ��㷨��*/




int main(){
	int chose;
	while (1) {
		system("title �������Ĳ���");
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
			printf("�˳��ɹ���\n");
			return;
		default:printf("��������������룺\n");
		}
	}
	return 0;
}

void menu() {
	printf("�����룺\n");
	printf("=======================\n");
	printf("=====*�������Ĳ���=====\n");
	printf("=====1��˳�������=====\n");
	printf("=====2����ʽ������=====\n");
	printf("=====0����      ��=====\n");
	printf("=======================\n");
}