#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef int DataType;
typedef struct ShareStack {
	DataType data[MAX];
	int top1;
	int top2;
}SS;
SS sharestack;
SS* s = &sharestack;

//��������
void menu();
void InitStack(int chose);
void PrintStack(int chose);
void Push(int chose);
void Pop(int chose);
void GetTop(int chose);

int main(){
	int chose;
	while (1) {
		system("title ����ջ");
		menu();				//�˵�
		scanf("%d", &chose);
		switch (chose) {
		case 1:				//��ʼ��������ֵ
			printf("��ѡ���ʼ���ĸ�ջ��\n1��1ջ\n2��2ջ\n3������ʼ��\n");
			int chose1;
			scanf("%d", &chose1);
			InitStack(chose1);
			break;
		case 2:				//��ӡջ��������Ǵ�ӡ��� ���飬��ʼԪ�ض�Ϊ0
			printf("��ӡ�ĸ�ջ��\n1��1ջ\n2��2ջ\n3������\n");
			int chose2;
			scanf("%d", &chose2); 
			PrintStack(chose2);
			break;
		case 3:				//ѹջ
			printf("��ѡ��ջ��\n1��1ջ\n2��2ջ\n3������\n");
			int chose3;
			scanf("%d", &chose3);
			Push(chose3);
			break;
		case 4:				//��ջ
			printf("��ѡ��ջ��\n1��1ջ\n2��2ջ\n3������\n");
			int chose4;
			scanf("%d", &chose4);
			Pop(chose4);
			break;
		case 5:				//ȡջ��Ԫ�ص�����ս
			printf("��ѡ��ջ��\n1��1ջ\n2��2ջ\n3����ȡ\n");
			int chose5;
			scanf("%d", &chose5);
			GetTop(chose5);
			break;
		case 0:return;
		default:printf("��������������룺\n");
		}
	}
	return 0;
}
//�˵�
void menu() {
	printf("--------------\n");
	printf("|����ջ�Ļ���\n");
	printf("|1����ʼ��ջ\n");
	printf("|2����ӡջ\n");
	printf("|3����ջ\n");
	printf("|4����ջ\n");
	printf("|5��ȡջ��Ԫ��\n");
	printf("|0���˳�\n");
	printf("--------------\n");
	printf("��ѡ��\n");
}
//1����ʼ��ջ
void InitStack(int chose) {
	/*ֻ������ջ��top�ҵ�λ�ã�����ֵ*/
	switch (chose) {
	case 1:
		s->top1 = -1;		//1ջ
		printf("�Ƿ������ʼ���ڶ���ջ?\n1����\n2����\n");
		int chose1;
		scanf("%d", &chose1);
		if (chose1 == 1) {
			chose = 2;
		}
		break;
	case 2:
		s->top2 = MAX;		//2ջ
		break;
	case 3:
		s->top1 = -1;
		s->top2 = MAX;
		break;
	default:printf("�������\n");
	}
	printf("��ʼ����� ��\n");
}
//2����ӡջ
void PrintStack(int chose) {
	/*�����ʼ��Ϊ0*/
	int i;				//i����top����ӡ������ջ
	switch (chose) {
	case 1:
		if (s->top1 == -1) {		//�жϿ�ս
			printf("��ǰ��ջ��\n");
			return;
		}
		printf("1ջ��");
		i = s->top1;		
		while (i != -1) {
			printf("%d ", s->data[i--]);	//1ջtopҪ--����Ϊѹջ��ʱ��top��++��
		}
		printf("\n");
		break;
	case 2:
		if (s->top2 == MAX) {		//�жϿ�ս
			printf("��ǰ��ջ��\n");
			return;
		}
		i = s->top2;
		printf("2ջ��");
		while (i != MAX) {					
			printf("%d ", s->data[i++]);	//2ջtopҪ++����Ϊ���ǵ�������ѹջ��ʱ����--
		}
		printf("\n");
		break;
	case 3:
		if (s->top1==-1||s->top2 == MAX) {	
			printf("������һ��ջ��\n");
			return;
		}
		i = 0;
		while (i != MAX) {
			printf("%d ", s->data[i++]);	//Ȩ����ӡ����
		}
		printf("\n");
		break;
	default:printf("������󣬷�����һ����\n");
	}
}
//3����ջ
void Push(int chose) {
	if (s->top1 == s->top2) {		//�ж��Ƿ�ջ��
		printf("ջ����\n");
		return;
	}

	int num1;	//��ջһ����ջʱ1ջ��ֵ
	int num2;	//��ջһ����ջʱ2ջ��ֵ
	int chose1;	//ѡ��
	int n;

	switch (chose) {
	case 1:
		printf("������ջ����Ԫ�أ�\n");
		scanf("%d", &n);
		if (n >= MAX || n <= 0) {
			printf("����\n");
			return;
		}
		printf("������ֵ��\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num1);
			s->top1++;		//��Ϊ��ʼ��-1��������++
			s->data[s->top1] = num1;	//��ֵ
		}
		printf("��ջ�ɹ���\n�Ƿ��ӡ����1���ǣ�2����\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {	//��ӡ
			PrintStack(1);
		}
		break;
	case 2:
		printf("������ջ����Ԫ�أ�\n");
		scanf("%d", &n);
		if (n >= MAX || n <= 0) {
			printf("����\n");
			return;
		}
		printf("������ֵ��\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num2);
			s->top2--;		//��Ϊ��ʼ��MAX��������--
			s->data[s->top2] = num2;	//��ֵ
		}
		printf("��ջ�ɹ���\n�Ƿ��ӡ����1���ǣ�2����\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {	//��ӡ
			PrintStack(2);
		}
		break;
	case 3:
		printf("����ÿ��ջ��ջ����Ԫ�أ�\n");
		scanf("%d", &n);
		if (n >= MAX || n <= 0) {
			printf("����\n");
			return;
		}
		printf("������1ջ��ֵ��\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num1);
			s->top1++;		//��Ϊ��ʼ��-1��������++
			s->data[s->top1] = num1;	//��ֵ
		}
		printf("������2ջ��ֵ��\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num2);
			s->top2--;		//��Ϊ��ʼ��MAX��������--
			s->data[s->top2] = num2;	//��ֵ
		}
		printf("��ջ�ɹ���\n�Ƿ��ӡ����1���ǣ�2����\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {	//��ӡ
			PrintStack(3);
		}
		break;
	default:printf("�������\n");
	}
}
//4����ջ
void Pop(int chose) {
	int chose1;
	switch (chose) {
	case 1:
		if (s->top1 == -1) {
			printf("��ǰ��ջ��\n");
			return;
		}
		s->data[s->top1] = 0;	//��ջ��Ԫ�ر�Ϊ0����Ϊ����Ԫ�س�ʼ��Ϊ0���൱��ɾ�������ջ��Ԫ��
		s->top1--;		//��ջtop1--
		printf("��ջ�ɹ���\n�Ƿ��ӡ����1���ǣ�2����\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {
			PrintStack(1);
		}
		break;
	case 2:
		if (s->top2 == MAX) {
			printf("��ǰ��ջ��\n");
			return;
		}
		s->data[s->top2] = 0;
		s->top2++;		//��ջtop2++
		printf("��ջ�ɹ���\n�Ƿ��ӡ����1���ǣ�2����\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {
			PrintStack(2);
		}
		break;  
	case 3:
		if (s->top1 == -1 || s->top2 == MAX) {
			printf("������һ��ջ��\n");
			return;
		}
		s->data[s->top1] = 0;
		s->top1--;
		s->data[s->top2] = 0;
		s->top2++;
		break;
	default:printf("�������\n");
	}
	printf("��ջ�ɹ�!\n");
}
//5����ջ��Ԫ��
void GetTop(int chose) {
	switch (chose) {
	case 1:
		if (s->top1 == -1) {
			printf("��ǰ��ջ��\n");
			return;
		}
		printf("1ջ��ջ��Ԫ���ǣ�%d\n", s->data[s->top1]);
		break;
	case 2:
		if (s->top2 == MAX) {
			printf("��ǰ��ջ��\n");
			return;
		}
		printf("2ջ��ջ��Ԫ���ǣ�%d\n", s->data[s->top2]);
		break;
	case 3:
		if (s->top1==-1||s->top2 == MAX) {
			printf("������һ��ջ��\n");
			return;
		}
		printf("1ջ��ջ��Ԫ���ǣ�%d\n", s->data[s->top1 ]);
		printf("2ջ��ջ��Ԫ���ǣ�%d\n", s->data[s->top2 ]);
		break;
	default:printf("�������\n");
	}
}