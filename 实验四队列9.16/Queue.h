#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

#define MAX 100				//�ӵ����Ԫ�ظ���
#define DataType int		//��������

typedef struct SqQueue {	//˳��ӽṹ
	DataType data[MAX];		//����
	int head, rear;			//ͷָ����βָ��
	int length;				//��Ԫ�ظ���
}SQ;

typedef struct LNode {		//������ṹ
	DataType data;			//������
	struct Node* next;		//ָ����
}LNode,*Node;

typedef struct LkQueue {	//���ӽṹ
	Node head;				//ͷָ��
	Node rear;				//βָ��
	int size;				//Ԫ�ظ���
}LQ;

int main1();				//˳��ӵ�������
int main2();				//���ӵ�������
void menu1();				//���˵�

//˳��ӵĺ�������
void Enqueue(SQ* q, int num);
void Dequeue(SQ* q);
void ClearQueue(SQ* q);
DataType HeadOfQueue(SQ* q);
int LengthOfQueue(SQ* q);
void PrintQueue(SQ* q);
void File(SQ* q);

//���ӵĺ�������
void Enqueue2(LQ* p, DataType num);
void PrintQueue2(LQ* p);
int SizeOfQueue2(LQ* p);
DataType HeadOfQueue2(LQ* p);
void ClearQueue2(LQ* p);
void Dequeue2(LQ* p);
void SaveFile2(LQ* q);



