#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"


int main1(){
	system("title ˳�������");
	int chose = 0;
	ElemType elem;
	int index = 0;
	printf("���������ʼ����ֵ��\n");
	InitTree();
	while (1) {
		Print();
		menu1();
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//1������
		case 1:
			printf("������Ҫ�����ֵ��");
			scanf("%c", &elem);
			getchar();
			InsertTree(elem);
			break;
			//2��ɾ��
		case 2:
			printf("������ɾ����λ�ã�\n");
			scanf("%d", &index);
			DeleteTree(index);
			break;
			//3������
		case 3:
			VisitTree();
			break;
			//4����ϵ
		case 4:
			Relation();
			break;
			//5���޸�
		case 5:
			printf("������Ҫ�޸ĵ�λ�ã�");
			scanf("%d", &index);
			getchar();
			printf("������Ҫ�޸ĵ�ֵ��");
			scanf("%c", &elem);
			getchar();
			UpdataTree(index, elem);
			break;
			//0������
		case 0:
			system("cls");
			return;
		default:printf("����������������룺\n");
		}
	}
	return 0;
}

void menu1() {
	printf("�����룺\n");
	printf("=======================\n");
	printf("=======˳�������======\n");
	printf("===1������   2��ɾ��===\n");
	printf("===3������   4����ϵ===\n");
	printf("===5���޸�   0������===\n");
	printf("=======================\n");
}
//��ʼ��
void InitTree() {
	ElemType elem;
	bt[0] = NULL;//���±�Ϊһ��ʼ�洢
	int i = 1;
	while ((elem = getchar()) != '\n') {
		bt[i] = elem;
		i++;
	}
	btlength = i - 1;
}
//��ӡ
//����������
void Print() {
	printf("=======================\n");
	int tmp = 2;
	int n = 1;
	//���nΪ����
	while (1) {
		tmp = tmp * 2;
		n++;
		if (tmp > btlength)
			break;
	}
	//m�������±�
	int m = 2;
	//sum��ÿһ������Ԫ�ظ���
	int sum = 2;
	//��ӡ���ڵ�
	printf("��1���ǣ�%c\n", bt[1]);
	//ѭ����ӡ�������
	for (int i = 2; i <= n; i++) {
		printf("��%d���ǣ�", i);
		for (int j = 0; j < sum; j++) {
			printf("%c ",bt[m++]);
		}
		printf("\n");
		sum *= 2;
	}
	printf("=======================\n");
}
//���룬ֻ����Ҷ�ӽڵ����
void InsertTree(ElemType elem) {
	bt[++btlength] = elem;
}
//ɾ����ɾ������#����
void DeleteTree(int index) {
	bt[index] = '#';
}
//����ϵ
void Relation() {
	int i = 1;
	printf(" %c ��û�аְ�*_*,������ǣ�%c���Ҷ����ǣ�%c\n", bt[i], bt[2 * i], bt[2 * i + 1]);
	i++;
	while (i<=btlength) {
		ElemType parent = bt[i / 2];
		ElemType leftchild = bt[2 * i];
		ElemType rightchild = bt[2 * i + 1];
		if (bt[i] == '#') {
			i++;
			continue;
		}
		if (leftchild == 0 && rightchild == 0)
			printf(" %c �İְ��ǣ�%c����û�ж���-_-��\n", bt[i],parent);
		else if (rightchild == 0)
			printf(" %c �İְ��ǣ�%c��������ǣ�%c\n", bt[i], parent, leftchild);
		else
			printf(" %c �İְ��ǣ�%c��������ǣ�%c���Ҷ����ǣ�%c\n", bt[i], parent, leftchild, rightchild);
		i++;
	}
}
//�޸�
void UpdataTree(int index,ElemType elem) {
	bt[index] = elem;
}
//����������д
void VisitTree() {
	system("cls");
	while (1) {
		printf("===1��ǰ�����===\n");
		printf("===2���������===\n");
		printf("===3���������===\n");
		printf("===0���˳�����===\n");
		int chose;
		scanf("%d", &chose);
		switch (chose) {
		case 1:
			printf("ǰ�������û��д̫�鷳�ˡ���\n");
			break;
		case 2:
			printf("���������Ҳû��д̫�鷳�ˡ���\n");
			break;
		case 3:
			printf("�������������û��д̫�鷳�ˡ���\n");
			break;
		case 0:
			system("cls");
			return;
		}
	}
	
}