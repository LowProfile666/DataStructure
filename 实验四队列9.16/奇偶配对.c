#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"



int main3(){
	//����ͷ�ڵ�
	Node head1 = (Node)malloc(sizeof(Node));
	Node head2 = (Node)malloc(sizeof(Node));
	head1->next = NULL;
	head2->next = NULL;
	int num;
	//������������
	LQ Q1;	LQ Q2;
	LQ* q1;	LQ* q2;
	q1 = &Q1; q2 = &Q2;
	//��ʼ��
	q1->head = head1; q1->rear = head1;
	q2->head = head2; q2->rear = head2;
	q1->size = 0; q2->size = 0;
	//���������
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++) {
		num = rand() % 100;			//100���ڵ������

		if (num % 2 == 0) {			//ż��
			Enqueue2(q1, num);		//����q1����
		}
		else {						//����
			Enqueue2(q2, num);		//����q2����
		}
	}
	//��ӡ����
	printf("ż��Ϊ��");
	PrintQueue2(q1);
	printf("\n");
	printf("����Ϊ��");
	PrintQueue2(q2);
	printf("\n");

	printf("��ʼ��ԣ�\n");
	//��q1��q2��ͷ�ڵ��λ���Ƶ���һ������λ��
	q1->head = q1->head->next;
	q2->head = q2->head->next;

	while (q1->head != NULL && q2->head != NULL) {//�κ�һ��ΪNULLֹͣ
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