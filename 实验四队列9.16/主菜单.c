#define _CRT_SECURE_NO_WARNINGS 1

/*���к��������ͽṹ�������������ͷ�ļ���*/
#include"Queue.h"


void menu() {
	printf("###################\n");
	printf("      ��ѡ��\n");
	printf("    1��˳���\n");
	printf("    2������\n");
	printf("    3����ż����\n");
	printf("    0���˳�\n");
	printf("###################\n");
}

int main(){
	int chose;
	system("title ���еĲ���");
	while (1) {
		system("cls");				//����
		menu();						//���˵�
		scanf("%d", &chose);		
		switch (chose) {
		case 1:						//����˳��ӵĲ���
			system("cls");
			system("title ˳���");
			main1();				//˳��Ե�������
			break;
		case 2:						//�������ӵĲ���
			system("cls");
			system("title ����");
			main2();				//���ӵ�������
			break;
		case 3:
			system("cls");
			system("title ��ż����");
			main3();
			system("pause");
			break;
		case 0:return;
		default:printf("���������������:\n"); system("pause");
		}
	}
	return 0;
}
