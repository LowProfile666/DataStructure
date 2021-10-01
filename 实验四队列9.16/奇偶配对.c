#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"



int main3(){
	//创建头节点
	Node head1 = (Node)malloc(sizeof(Node));
	Node head2 = (Node)malloc(sizeof(Node));
	head1->next = NULL;
	head2->next = NULL;
	int num;
	//创建两个链队
	LQ Q1;	LQ Q2;
	LQ* q1;	LQ* q2;
	q1 = &Q1; q2 = &Q2;
	//初始化
	q1->head = head1; q1->rear = head1;
	q2->head = head2; q2->rear = head2;
	q1->size = 0; q2->size = 0;
	//随机数种子
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++) {
		num = rand() % 100;			//100以内的随机数

		if (num % 2 == 0) {			//偶数
			Enqueue2(q1, num);		//放在q1里面
		}
		else {						//奇数
			Enqueue2(q2, num);		//放在q2里面
		}
	}
	//打印看看
	printf("偶数为：");
	PrintQueue2(q1);
	printf("\n");
	printf("奇数为：");
	PrintQueue2(q2);
	printf("\n");

	printf("开始配对：\n");
	//将q1，q2从头节点的位置移到第一个结点的位置
	q1->head = q1->head->next;
	q2->head = q2->head->next;

	while (q1->head != NULL && q2->head != NULL) {//任何一个为NULL停止
		Sleep(300);			
		printf("%2d ", q1->head->data);
		Sleep(300);
		printf("%2d ", q2->head->data);
		printf("\n");
		q1->head = q1->head->next;
		q2->head = q2->head->next;
	}
	return 0;
}