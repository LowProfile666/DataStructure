#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"


int main2(){
	system("title ��ʽ������");
	printf("�����ù�������ʽ��ʼ������\n�磺A(B(D,E),C(F,G)):\n");
	InitLtree();													//��ʼ��
	LTree Lt1 = Lt;													//������㣬������ӡ
	int chose = 0;													//ѡ��ֵ
	int i = 1;														//��������ѡ���ѭ������
	ElemType elem1,elem2;											//������������
	while (1) {
		printf("=======================\n��ǰ���Ĺ����ģʽ��\n");
		PrintLtree(Lt1);											//��������ʽ���
		printf("\n=======================\n");
		menu2();
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//����
		case 1:
			printf("�������������Ǹ�λ�õ�ǰһ�����ֵ��");
			scanf("%c", &elem1);
			getchar();												//���'\n'
			printf("������Ҫ�����ֵ��");
			scanf("%c", &elem2);
			InsertNode(elem1, elem2);								//����
			break;
			//ɾ��
		case 2:
			printf("������Ҫɾ����ֵ��");
			scanf("%c", &elem1);
			DeleteNode(elem1);										//ɾ��
			break;
			//����
		case 3:
			system("cls");
			printf("=======================\n��ǰ���Ĺ����ģʽ��\n");
			PrintLtree(Lt1);
			printf("\n=======================\n");
			while (i) {
				printf("===1��ǰ�����===\n");
				printf("===2���������===\n");
				printf("===3���������===\n");
				printf("===0���˳�����===\n");
				scanf("%d", &chose);
				switch (chose) {
				case 1:PreOrder(Lt1); printf("\n"); break;			//ǰ�����
				case 2:InOrder(Lt1); printf("\n"); break;			//�������
				case 3:PostOrder(Lt1); printf("\n"); break;			//��������
				default:i = 0; system("cls");
				}
			}
			break;
			//���ӹ�ϵ
		case 4:
			printf("������Ҫ�鿴��ֵ��");
			scanf("%c", &elem1);
			LTreeRelation(elem1);									//���ӹ�ϵ
			break;
			//�޸�
		case 5:
			printf("�����뱻�޸ĵ�ֵ��");
			scanf("%c", &elem1);
			getchar();
			printf("�������޸ĵ�ֵ��");
			scanf("%c", &elem2);
			LTreeUpdata(elem1,elem2);								//�޸�
			break;
			//����
		case 0:
			system("cls");
			return;
		default:printf("����������������룺\n");
		}
	}
	return 0;
}
void menu2() {
	printf("�����룺\n");
	printf("=======================\n");
	printf("=======��ʽ������======\n");
	printf("===1������   2��ɾ��===\n");
	printf("===3������   4����ϵ===\n");
	printf("===5���޸�   0������===\n");
	printf("=======================\n");
}
//�ù������ʽ��ʼ����
void InitLtree() {
	int k = 0;					//��־��Ϊ1��������ӣ�Ϊ2�����Ҷ���
	int top = -1;				//ջ���±����˵�����±�
	LTree stack[MAXSIZE];		//��һ����������ջ����˵������ʱ��Ÿ��ڵ㣬������������ӽ��
	LTree tmp = NULL;			//tmp�������
	Lt = NULL;					//���ĳ�ʼ��
	char ch;					//�������ܹ�����ÿһ���ַ�
	while ((ch = getchar()) != '\n') {	//����˵��������ϣ�ѭ��Ҳ�˳�
		switch (ch) {
			//������˵������������Ӵ��ڣ�����Ҫ�Ƚ���ǰ�ĸ��׽������������棬�������Ķ�������
		case '(':
			stack[++top] = tmp;
			k = 1;
			break;
			//����˵�������Ҷ��Ӵ��ڣ����Խ�k��Ϊ2
		case ',':
			k = 2;
			break;
			//������˵����ǰ�ĸ��׽ڵ�Ķ�����������ˣ���Ϊ������׽����ܻ��и��׽�㣬�����±�������1�����ص���һ�����׽��
		case ')':
			top--;
			break;
			//�����ַ�ʱ���͸�tmp����ռ䡢��ֵ��Ȼ����k�������Ұְ�
		default:
			tmp = (LTree)malloc(sizeof(LTree));
			tmp->data = ch;
			tmp->left = tmp->right = NULL;
			//�����������ĸ��ڵ�
			if (Lt == NULL)
				Lt = tmp;
			else {
				switch (k) {
					//��ǰ���׽��������
				case 1:stack[top]->left = tmp;
					break;
					//��ǰ���׽����Ҷ���
				case 2:stack[top]->right = tmp;
					break;
				}
			}
		}
	}
}
//�ù������ʽ�����
void PrintLtree(LTree Lt1) {
	int k = 0;						//k��һ����־
	if (Lt1)
		printf("%c", Lt1->data);
	if (Lt1->left) {
		k = 1;						//k=1��ʾ������ӽ����ڣ���ֹ���������ŵ������һ��
		printf("(");
		PrintLtree(Lt1->left);
	}
	if (Lt1->right) {
		printf(",");
		PrintLtree(Lt1->right);
		printf(")");
	}
	//�ݹ�������
	else if(k==1){
		printf(")");
	}
	/*���û��k�Ļ���A(B,C(D,E))�������ܻ�ֻ���һ��������*/
}
//����ָ��Ԫ�صĽ��
LTree FindNode(ElemType elem) {
	LTree Lt1 = Lt;						//�������ĸ��ڵ����
	LTree arr[MAXSIZE];					//��һ���������ڵ�
	int top = -1;						
	int k = 0;							//������־��
	while (1) {
		if (Lt1->left || Lt1->right) {	//����ڵ�
			arr[++top] = Lt1;
		}
		if (Lt1->data == elem)
			return Lt1;
		//���ҵ�ǰ���ڵ�������
		else if (Lt1->left) {
			Lt1 = Lt1->left;
			if (Lt1->data == elem)
				return Lt1;
		}
		Lt1 = arr[top];					//��������ӣ�ָ�뻹��ԭ���ĸ��ڵ�
		//���ҵ�ǰ���ڵ���Ҷ���
		 if (Lt1->right) {
			Lt1 = Lt1->right;
			if (Lt1->data == elem)
				return Lt1;
		}
		Lt1 = arr[top];					//�����Ҷ��ӣ�ָ�뻹��ԭ���ĸ��ڵ�
		//k��1�����������������2���������������
		if (k != 1) {
			//�����ǰ���ڵ������ӵ�����ӻ�������ӵ��Ҷ��Ӳ�Ϊ�գ���ô���ڵ�ָ���Ϊ��������ӣ��ص�ѭ����������
			if (Lt1->left->left || Lt1->left->right) {	
				Lt1 = arr[top]->left;
				k = 1;
				continue;				//������������
			}
		}
		//k��1�����������������2���������������
		else if (k != 2) {
			//����Ҷ����ǿգ���ô���ڵ�ָ��ͱ������Ӽ���
			if (Lt1->right == NULL) {
				Lt1 = arr[top]->left;
				k = 2;
				continue;
			}
			//�����ǰ���ڵ���Ҷ��ӵ�����ӻ����Ҷ��ӵ��Ҷ��Ӳ�Ϊ�գ���ô���ڵ�ָ���Ϊ�����Ҷ��ӣ��ص�ѭ����������
			if (Lt1->right->left || Lt1->right->right) {
				Lt1 = arr[top]->right;
				k = 2;
				continue;
			}
			//������ڵ���Ҷ��Ӳ��յ����Ҷ��ӵĶ����ǿգ�˵������ge���������꣬��k��Ϊ2
			k = 2;
		}
	}
}
//����
/*����Ľ�����������*/
void InsertNode(ElemType elem1, ElemType elem2) {
	//���ҵ������λ��
	LTree Lt1 = FindNode(elem1);
	//�������
	LTree new = (LTree)malloc(sizeof(LTree));
	new->data = elem2;
	new->left = Lt1->left;
	new->right = Lt1->right;
	Lt1->left = new;
	Lt1->right = NULL;
}
//ɾ��
void DeleteNode(ElemType elem) {
	//�ҵ�ɾ���ĵ�
	LTree LT1 = FindNode(elem);
	LT1->data = NULL;
	LT1->left = LT1->right = NULL;
}
//�ݹ�ı���
//ǰ�����
void PreOrder(LTree Lt1) {
	if (Lt1 == NULL)
		return;
	printf("%c ", Lt1->data);
	PreOrder(Lt1->left);
	PreOrder(Lt1->right);
}
//�������
void InOrder(LTree Lt1) {
	if (Lt1 == NULL)
		return;
	InOrder(Lt1->left);
	printf("%c ", Lt1->data);
	InOrder(Lt1->right);
}
//�ǵݹ��������
/*��������������û���Ҷ��Ӿͻ����*/
//void InOrder(LTree Lt1) {
//	LTree stack[MAXSIZE];				//���������ڵ�
//	int top = -1;						//�����ʼ�±�
//	while (Lt1) {
//		while (Lt1->left) {				//�ȱ�������������Ҷ�ӽڵ�
//			stack[++top] = Lt1;
//			Lt1 = Lt1->left;
//		}
//		printf("%c ", Lt1->data);		//��ӡ������
//		if (top == -1) {				//��top=-1��˵�����һ�����ڵ�Ķ��Ӷ���ӡ���ˣ��˳�ѭ��
//			break;
//		}
//		printf("%c ", stack[top]->data);//��ӡ��ǰ���ڵ�
//		if (stack[top]->right)			//�����ǰ��������Ҷ��ӵĻ�
//			Lt1 = stack[top--]->right;	//ָ�����ǰ�����Ҷ��ӣ�top--��ʾ �ص���һ�����ڵ�
//		else
//			Lt1 = stack[--top]->right;	//���û�У��ͱ�Ϊ��һ�����ڵ���Ҷ���
//	}
//}
//��������
void PostOrder(LTree Lt1) {
	if (Lt1 == NULL)
		return;
	PostOrder(Lt1->left);
	PostOrder(Lt1->right);
	printf("%c ", Lt1->data);
}
//���ӹ�ϵ�����ְֵ�̫��д��
/*���ɾ����һ����㣬Ӧ�ðѸýڵ����һ�����Ķ�����Ϊ�գ����ǲ��ò���ûд������ɾ��һ���������鿴�丸�ڵ�Ĺ�ϵʱ�����*/
void LTreeRelation(ElemType elem) {
	LTree Lt1 = FindNode(elem);
	if (!Lt1->left && !Lt1->right) {
		printf(" %c ��û�ж���\n", Lt1->data);
		return;
	}	
	if(Lt1->left->data&&Lt1->right->data)
		printf(" %c ��������ǣ�%c���Ҷ�����%c\n",Lt1->data,Lt1->left->data,Lt1->right->data);
	if(Lt1->left->data&&!Lt1->right->data)
		printf(" %c ��������ǣ�%c����û���Ҷ���\n", Lt1->data, Lt1->left->data);
	if(!Lt1->left->data&&Lt1->right->data)
		printf(" %c ���Ҷ����ǣ�%c����û�������\n", Lt1->data, Lt1->right->data);
}
//�޸�
void LTreeUpdata(ElemType elem1,ElemType elem2) {
	//�ҵ�Ҫ�޸ĵĵ�
	LTree Lt1 = FindNode(elem1);
	Lt1->data = elem2;
}
