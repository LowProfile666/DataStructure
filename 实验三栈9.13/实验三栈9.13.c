#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


/*1������˳��洢ʵ��ջ�ĳ�ʼ������ջ����ջ������
2��������ʽ�洢ʵ��ջ�ĳ�ʼ������ջ����ջ������
3��дһ�����򣬽������ʮ��������M ת��Ϊ�˽�������M8���������ͨ����
�ڴ˻������޸ĳ���ʵ��ʮ��������M ��N ���ƣ�2��8��16����ת����
��1������˳��洢�ṹʵ��ջ��
��2����������ṹʵ��ջ��*/

#define MaxSize 100	//ջ�����洢ֵ
typedef int ElemType;	
typedef struct SqStack {	//˳��ջ
	ElemType data[MaxSize];//����
	int top;	//ջ��ָ��
}Sq;
Sq s;	

typedef struct LinkNode {	//����
	ElemType data;
	struct LinkNode* next;
}Lnode;
typedef struct LinkStack {	//��ջ
	Lnode* top;
}Ls;
Ls L;
Ls* l = &L;
int count = 0;	//�����������ж�ջ�Ƿ񴴽��������Ƿ��ʼ������������δ������ʼ��

//��������
void InitStrack(int i);
void CreateStrack(int i);
void PrintStack(int i);
void F(int i,int n);
int F1(int count);
void Push(int i,int m);
void Pop(int i);
void GetTop(int i);
void TransFrom(int i);
void menu();
void menu1();
void menu2();
void menu3();
void Delte(int i);
void transfrom(int n);

int main() {
	system("title ջ�Ĳ���");
	int chose = 0;
	while (1) {
		menu();	//�˵�
		scanf("%d", &chose);	//ѡ��
		switch (chose) {
		case 1:
			system("cls");	//����
			menu1();	//����˳��ջ�Ĳ˵�
			count = 0;	//������Ҫ��Ϊ���ڽ�����˳��ջ���˳����ã���������ջ����������
			break;	
		case 2:
			system("cls");	//ͬ��
			menu2();	//������ջ�Ĳ˵�
			count = 0;	//�˳���ջ�Ĳ˵�������
			break;
		case 3:
			TransFrom(1);	//����ջ��ת������
			break;
		case 0: return;	//�˳�
		default:printf("��������������룺\n");
		}
	}
	return 0;
}
//��ʼ�˵�
void menu() {
	printf("��������������������\n");
	printf("��   ջ�Ĳ���     ��\n");
	printf("��   1��˳��ջ    ��\n");
	printf("��   2����ջ      ��\n");
	printf("��   3������ת��  ��\n");
	printf("��   0���˳�      ��\n");
	printf("��������������������\n");
	printf("��ѡ��\n");
}

//˳��ջ�˵�
void menu1() {
	int n;
	while (1) {
		printf("+++++++++++++++++\n");
		printf("+ ˳��ջ�Ĳ���  +\n");
		/*��Ϊ�����˵�����Ҫ���ݶ�һ����ֻ�в˵�ͷ��ͬ�����Ե���һ�ݲ˵�ͷ*/
		menu3();	//��ʾ���˵�
		scanf("%d", &n);	//ѡ����
		if (n == 0) {		//ѡ��0�˳�
			system("cls");	//����
			return;
		}
		F(1,n);	//�˵�ѡ����Ĺ��ܵĵ��ã������1������ ˳��ջ
	}
}
//����ջ�˵�
void menu2() {
	int n;
	while (1) {
		printf("+++++++++++++++++\n");
		printf("+ ��ջ�Ĳ���    +\n");
		menu3();	//��ʾ���˵�
		scanf("%d", &n);	//����ѡ��
		if (n == 0) {		//ѡ��0�˳�
			system("cls");	//����
			return;
		}
		F(2,n);	//�˵�ѡ����Ĺ��ܵĵ��ã������2������ ��ջ
	}
}
//���˵�
void menu3() {
	printf("+ 1������ջ     +\n");
	printf("+ 2����ʼ��     +\n");
	printf("+ 3����ӡջ     +\n");
	printf("+ 4����ջ       +\n");
	printf("+ 5����ջ       +\n");
	printf("+ 6��ȡջ��Ԫ�� +\n");
	printf("+ 7�����ջ     +\n");
	printf("+ 0��������һ�� +\n");
	printf("+++++++++++++++++\n");
	printf("��ѡ��\n");
}
//�˵�ѡ����Ĺ��ܵĵ���
/*��Ϊ����ջ�����Ҷ�д��һ����������ж����i����������ִ����һ���Ĳ���*/
void F(int i,int n) {	//i�Ǳ�ʾ1��2�ģ����Ǳ�ʾ��ջ����˳��ջ��
	if (i ==  1) {
		switch (n) {	//ȫ�����1���Ǵ���˳��ջ
		case 1:CreateStrack(1); break;	//����
		case 2:InitStrack(1); break;	//��ʼ��
		case 3:PrintStack(1); break;	//��ӡ
		case 4:	
			if (F1(count) == 0) {
				break;
			}
			printf("������Ҫ����ջ��Ԫ�أ�\n");
			int n;
			scanf("%d", &n); 
			Push(1,n);break;	//ѹջ��n��Ҫ�Ž�ȥ��Ԫ��
			/*��Ϊ����ת����Ҫ�õ�Push���������ֲ���Ҫǰ����Щ���
			������Щ���д�ڵ��ú���ǰ*/
		case 5:Pop(1);break;	//��ջ
		case 6:GetTop(1); break;	//��ջ��Ԫ��
		case 7:Delte(1); break;	//���ջ
		default:  printf("�������!\n"); break;
		}
		return;
	}
	if (i == 2) {	//�����Ǵ������������������ͬ
		/*��������ͬ�ĵط�ֻ�ں����ڲ��͸õ��ú�����*/
		switch (n) {
		case 1:CreateStrack(2); break;
		case 2:InitStrack(2); break;
		case 3:PrintStack(2); break;
		case 4:
			if (F1(count) == 0) {
				break;
			}
			printf("������Ҫ����ջ��Ԫ�أ�\n");
			int n;
			scanf("%d", &n);
			Push(2,n);
			break;
		case 5:Pop(2); break;
		case 6:GetTop(2); break;
		case 7:Delte(2); break;
		default:  printf("�������!\n"); break;
		}
		return;
	}
}
//�жϣ����ڴ����ĺ�����ж��Ƿ���δ���
int Judge(int i) {
	if (i == 1) {
		if (s.top != -1) {	//��ʼ��˳��ջ��Ϊ-1�������Ϊ˵����һ���ǿ�˳��ջ
			printf("�Ѵ�����˳��ջ��\n");
			return 0;
		}
	}
	if (i == 2) {
		if (l->top != NULL) {	//��ʼ����ջ��ΪNULL�������Ϊ˵����һ���ǿ���ջ
			printf("�Ѵ�������ջ��\n");
			return 0;
		}
	}
	return 1;
}
//�жϣ���count��ֵ���ж��Ƿ񴴽����߳�ʼ������ֹû�д������ʼ�����ܽ�����������
int F1(int count) {
	if (count == 0) {
		printf("��δ����ջ��\n");
		return 0;
	}
	if (count == 1) {
		printf("��ջ��δ��ʼ����\n");
		return 0;
	}
	return 1;
}
//3.ת������
void TransFrom(int i) {
	printf("��������Ҫת����ֵ��\n");
	int n;
	scanf("%d", &n);
	getchar();	//���ջ�����
	printf("��ѡ��Ҫת��Ϊ�����ƣ�\na.�˽���\nb.ʮ������\nc.������\n");
	char m;
	scanf("%c", &m);
	getchar();	//���ջ�����
	switch (m) {
	case 'a':printf("%dת��Ϊ�˽����ǣ�%o\n", n, n); return;
	case 'b':printf("%dת��Ϊʮ�������ǣ�%x\n", n, n); return;
	case 'c':transfrom(n); return;	//���ö�����ת������
	}
}
/*��Ϊʮ����ת�����Ʋ���ֱ���ø�ʽ�����������дһ����*/
//ʮ����ת��Ϊ������
void transfrom(int n) {	//���n�Ǵ�����Ҫ����ת����ֵ
	int m = n;	//�ø�m����n
	while (m > 0) {
		Push(1, m % 2);	//1������˳��ջ��ѹջ������ʵ�֣�����������ѹջ��
		m = m / 2;
	}
	count = 2;	//��Ϊǰ�������ˣ�������2�����Ѹ���ֵ�Ļ���������ѹջ����
	printf("%dת��Ϊ�������ǣ�\n", n);
	PrintStack(1);	//���ջ������ݣ�Ҳ����ת����Ķ�������
	count = 0;	//����������������ֽ�count=0�����������д���վ
	s.top = 0;	//��Ϊ�õ���˳��ջ��ѹջ�������������궼�����ص�ԭ�������ӣ���ҪӰ�����Ĳ���
}

//1.����ջ
void CreateStrack(int i) {
	if (i == 1) {	//����˳��ջ
		if(Judge(count)==0)	//�ж��Ƿ��Ѵ���ջ
			return;
		s.top = -1;	//����ջ
	}
	if (i == 2) {	//������ջ
		if (Judge(count) == 0)	//�ж��Ƿ��Ѵ���ջ
			return;
		l->top = NULL;	//����վ
	}
	count=1;	//�����ɹ���count���1��˵������ջ����
	printf("�����ɹ���\n");
}
//2.��ʼ��ջ
void InitStrack(int i) {
	if (count == 0) {
		printf("��δ����ջ��\n");
		return;
	}
	if (count == 2) {
		printf("��ջ�Ѿ���ʼ����\n");
		return;
	}
	printf("������ֵ����-1��������\n");
	while (1) {
		if (i == 1) {
			/*˳��ջ��ջ��ָ����ָ��ջ��Ԫ�ص�����ģ����������±�*/
			s.top++;	//��ʼs.topΪ-1����Ҫ��++���ܸ�ֵ����Ϊs.top�൱�������±�
			scanf("%d", &s.data[s.top]);	//��ֵ
 			if (s.data[s.top] == -1) {	//��-1����
				getchar();	//��ȡ��-1������-1������
				count = 2;	//��ʼ����ɣ�count��Ϊ2�������ѳ�ʼ��
				printf("��ʼ���ɹ���\n");
				return;
			}
		}
		if (i == 2) {
			Lnode* new = (Lnode*)malloc(sizeof(Lnode));	//�½�һ�ڵ�
			if (new == NULL) {	//ȡ��NULL��new������
				return;
			}
			scanf("%d", &new->data);	//��ֵ
			if (new->data == -1) {	//�˳�����
				getchar();		//��ȡ��-1
				count = 2;	//�������
				printf("��ʼ���ɹ���\n");
				return;
			}
			/*��ջ��ջ��ָ����ָ��ջ����һ��Ԫ�ص�*/
			new->next = l->top;	//����ͷ�巨�����µĽ�����l->top��λ��
			l->top= new;	//Ȼ��ջ��ָ��ָ������µ�ֵ
		}
	}
}
//3.��ӡջ
void PrintStack(int i) {
	if (i == 1) {
		if (F1(count) == 0) {	//�ж��Ƿ񴴽�����ʼ����ջ
			return;
		}
		int t = s.top - 1;	//��t����ջ��ָ��������ѭ����
		/*���ֱ����ջ��ָ��Ļ�����Ϊָ���С��Ҫÿ�μ��٣�
		���Եȵ������൱�ڽ�����Ԫ�ض���ջ��*/
		while (t != -1) {	//-1ʱ������ջ�ף��Ѿ�����������Ԫ�� 
			printf("%d ", s.data[t]);
			t--;	//��Ϊ��ջ��ָ�룬������Ҫ--
		}
	}
	if (i == 2) {
		if (F1(count) == 0) {	//�ж��Ƿ񴴽�����ʼ����ջ
			return;
		}
		Lnode* m= l->top;	//�½�һ��ջ��ָ�����������ƶ�����
		while (m != NULL) {	//=NULL���������
			printf("%d ", m->data);
			m = m->next;	//ͬ����Ĳ��
		}
	}
	printf("\n");	//������
}
//4.ѹջ
void Push(int i,int n) {	//i��ջ�����n��Ҫ��ջ��Ԫ��
	if (i == 1) {
		s.data[s.top] = n;	//ֱ�ӽ�n����ջ��ָ���λ��
		s.top++;	//Ȼ��ջ��ָ��++����ָ��ջ��Ԫ�ص�����
	}
	if (i == 2) {
		Lnode* new = (Lnode*)malloc(sizeof(Lnode));	//�½���� 
		if (new == NULL) {	//ȡ��NULL��new������
			return;
		}
		new->data = n;	//��n�������
		new->next = l->top;	//Ȼ������ͷ�巨���½ڵ�����top
		l->top = new;	//top������һ��
	}
}
//5.��ջ
void Pop(int i) {
	if (i == 1) {
		if (F1(count) == 0) {	//�ж��Ƿ񴴽�����ʼ����ջ
			return;
		}
		s.top--;	//�ͽ�ջ��ָ���½�һ��
	}
	if (i == 2) {
		if (F1(count) == 0) {
			return;
		}
		l->top = l->top->next;	//��ջ��ָ���Ƶ���һ��
	}
	printf("��ջ�ɹ���\n");
}
//6.��ջ��Ԫ��
void GetTop(int i) {
	if (i == 1) {
		if (F1(count) == 0) {
			return;
		}
		printf("ջ��Ԫ���ǣ�%d\n", s.data[s.top - 1]);	//��Ϊ˳��ջ��top��ջ��Ԫ�ص����棬����Ҫ��һ
	}
	if (i == 2) {
		if (F1(count) == 0) {
			return;
		}
		printf("ջ��Ԫ���ǣ�%d\n", l->top->data);	//��ջ��ջ��ָ�����ָ���ջ��Ԫ��
	}
}
//7.���ջ
/*���ǽ�ջ��ָ���Ƶ�������ȥ*/
void Delte(int i) {
	if (i == 1) {
		if (F1(count) == 0) {
			return;
		}
		s.top = -1;
	}
	if (i == 2) {
		if (F1(count) == 0) {
			return;
		}
		Lnode* n = (Lnode*)malloc(sizeof(Lnode));//�����½�һ�����������ͷſռ�
		n=l->top;	
		while (l->top != NULL) {
			n = n->next;	//�Ƚ�nָ����һ������Ϊl->topָ·������
			free(l->top);	//Ȼ���ͷſռ�
			l->top = n;	//Ȼ��ָ���ƶ���һ��
		}
	}
	count = 0;	//��պ󣬾ͽ�count=0��������û��ջ���ڵ�
	printf("�����ɣ�\n");
}


