#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

#define MAX 100				//队的最大元素个数
#define DataType int		//数据类型

typedef struct SqQueue {	//顺序队结构
	DataType data[MAX];		//数据
	int head, rear;			//头指针与尾指针
	int length;				//队元素个数
}SQ;

typedef struct LNode {		//链表结点结构
	DataType data;			//数据域
	struct Node* next;		//指针域
}LNode,*Node;

typedef struct LkQueue {	//链队结构
	Node head;				//头指针
	Node rear;				//尾指针
	int size;				//元素个数
}LQ;

int main1();				//顺序队的主函数
int main2();				//链队的主函数
void menu1();				//副菜单

//顺序队的函数声明
void Enqueue(SQ* q, int num);
void Dequeue(SQ* q);
void ClearQueue(SQ* q);
DataType HeadOfQueue(SQ* q);
int LengthOfQueue(SQ* q);
void PrintQueue(SQ* q);
void File(SQ* q);

//链队的函数声明
void Enqueue2(LQ* p, DataType num);
void PrintQueue2(LQ* p);
int SizeOfQueue2(LQ* p);
DataType HeadOfQueue2(LQ* p);
void ClearQueue2(LQ* p);
void Dequeue2(LQ* p);
void SaveFile2(LQ* q);



