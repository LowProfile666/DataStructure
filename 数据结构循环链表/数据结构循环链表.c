#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef int ElemType;
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode,*L;
Lnode Link;//��������
L head=&Link;//ͷָ��

//��������
void menu();
void YSF();
void MENOKEYKING();

int main(){
	system("title ѭ���������");
	int n;
	while (1) {
		menu();	//�˵�
		scanf("%d", &n);	//����ѡ��
		switch (n) {
		case 1:system("cls"); system("title Լɪ������"); YSF(); break;	//Լɪ������
		case 2:system("cls"); system("title ����Ӵ���"); MENOKEYKING(); break;	//���Ӵ���
		case 0:free(Link); return;	//�˳�
		default:printf("�������\n");
		}
	}
	return 0;
}
void menu() {
	printf("+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("+-   ѭ��������÷�  -+\n");
	printf("+---------------------+\n");
	printf("+-   1��Լɪ������   -+\n");
	printf("+-   2������ȡ����   -+\n");
	printf("+-      0���˳�      -+\n");
	printf("+---------------------+\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("��ѡ��\n");
}
//Լɪ�򴴽�������
void Create() {
	head->next = NULL;	//��ͷָ��ָ��NULL
	L h = head;	//����ͷָ�룬�����ƶ�
	printf("���ȳ�ʼ������-1������\n");
	while (1) {
		L new = (L)malloc(sizeof(L));	//�½����
		scanf("%d", &new->data);	//��ֵ
		getchar();	//�������ܵ������ �ո�
		if (new->data == -1) {	//-1����
			return;
		}
		h->next = new;	//���½ڵ�����
		new->next = head->next;	//ֱ�ӽ��½ڵ��nextָ���һ�����
		h = h->next;	//h����
	}
}
//Լɪ������
void YSF() {
	Create();	//��ʼ������
	printf("���������������ݣ�\n");
	int begin;	
	scanf("%d", &begin);
	printf("������Ŀ���С��\n");
	int num;
	scanf("%d", &num);
	L h = head->next;	//����ͷָ�������ƶ�
	L f = head;	//��h��ǰһ����㣬�����ҵ�h
	//����ѭ���ҵ����
	while (1) {
		if (h->data == begin) {
			break;
		}
		f = f->next;
		h = h->next;
	}
	
	int count = 1;	//����
	while (h->next!=h) {	//ֻʣ��һ����������
		h = h->next;	
		f = f->next;
		count++;	//�ƶ�һ�����ͼ�һ
		if (count == num) {	//�ӵ�Ŀ��ֵ��
			f->next = h->next;	//���ýڵ�ȥ��
			h = f->next;	//h����
			count = 1;	//����count
		}
	}
	printf("���һ������ǣ�%d\n", h->data);
}
//���Ӵ���
void MENOKEYKING() {
	printf("��������ӵĸ�����\n");
	int num;
	scanf("%d", &num);
	L h = head;	//����ͷָ�������ƶ�
	for (int i = 1; i <= num; i++) {	//ѭ��Ϊ�����Ǳ�ţ���������
		L new = (L)malloc(sizeof(L));
		new->data = i;
		h->next = new;
		new->next = head->next;
		h = new;
	}
	printf("����ӵڼ�ֻ���ӿ�ʼ��\n");
	int n;	//���
	scanf("%d", &n);
	h = head->next;	//��h�ƻص�һ������λ�ã����������f
	L f = head;	//��h��ǰһ�ڵ㣬���h���ǵ�һ�����Ļ�����ôf�Ͳ��ö���
	while (1) {	//ѭ���ҵ����
		h = h->next;
		f = f->next;
		if (h->data == n) {
			break;
		}
	}
	printf("������Ŀ������\n");	
	int a;
	scanf("%d", &a);

	int count = 1;	//����
	while (h != h->next) {	//ֻʣһ������������������ͬ
		h = h->next;
		f = f->next;
		count++;
		if (count == a) {
			f->next = h->next;
			h = f->next;
			count = 1;
		}
	}
	printf("���Ӵ����ǣ�%d�ź��ӣ�\n", h->data);
}