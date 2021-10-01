#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

/*1������������������һ��Ԫ�أ�����һ����ͷ���ĵ����������򣩡�
2����������������
3���ѵ���������Ԫ�����ã������������µĽ��ռ䣩����
4���ڵ���������ɾ�����е�ż��Ԫ�ؽ�㡣��
5����д�ڷǵݼ����������в���һ��Ԫ��ʹ����Ԫ��������ĺ����������øú�������һ���ǵݼ�����������
6������ʵ��5����������������������Ȼ��ϲ���һ����������
7������ʵ��1����������ʵ�ֽ���ֽ��������������һ��ȫ��Ϊ��������һ��ȫ��Ϊż��������������֪�Ĵ洢�ռ䣩��*/

typedef struct Node {
	int data;//������
	struct Node* next;//ָ����
}Node;

//��������
void menu();
Node* createList(Node* list,int count);
Node* insert(Node* head, int count);
Node* delete(Node* head, int count);
void find(Node* head, int count);
void getLength(Node* head, int count);
void print(Node* head, int count);
int isList(int count);
int rebuild(Node* list,int count);
Node* reverse(Node* head, int count);
Node* deleteO(Node* head, int count);
void resolve(Node* head, int count);
Node* createList2(Node* head, int count);
Node* combine(int count);
void Max(Node* head);

int main() {
	system("title ������Ĳ���");//dos��������
	int intput;//�����ѡ��ֵ
	Node* list;//����һ������
	list = (Node*)malloc(sizeof(Node));//Ϊ������䶯̬�ռ�
	/*malloc�Ƕ�̬�ڴ���亯������������һ��������ָ����С���ڴ��������void*���ͷ��ط�����ڴ������ַ*/
	int count = 0;//�����ã��ж��Ƿ��ǵ�һ�ν�����򣬵�һ�ν���ֻ�ܽ��д����������
	while (1) {//��ѭ��������ÿ�β������ܷ��ص��˵�����
		menu();//�˵�
		scanf("%d", &intput);//����ѡ��ֵ
		switch (intput) {
		case 0:printf("�˳��ɹ�!\n"); return;//�˳�����
		case 1:list = createList(list,count); count = 1; break;//���������������ִ�к�count���1�������Ѿ�����������
		case 2:list=insert(list,count); break;//�����㣬���ز���������
		case 3:list=delete(list,count); break;//ɾ����㣬����ɾ���������
		case 4:find(list,count); break;//���ҽ�㣬����ڵ�λ��
		case 5:getLength(list,count); break;//������
		case 6:print(list,count); break;//��ӡ����
		case 7:count = rebuild(list,count);  break;//ɾ�����������´ο��ؽ�����
		case 8:list = reverse(list, count); break;//��������
		case 9:
			list = deleteO(list, count); 
			if (count != 0) {//��ʾ��������ڣ���ֹû�����������½����˲���9�Ӷ�ִ������������
				printf("ɾ���ɹ���"); 
				print(list, count); 
			} 
			break;//ɾ��ż�ڵ㣬����ɾ���������
		case 10:resolve(list,count); break;//��ż���룬�����������������ԭ�������
		case 11:list = createList2(list, count);  break;//���нڵ�������
			/*�ڷǵݼ����������в���һ��Ԫ��ʹ����Ԫ�������򣬲����øú�������һ���ǵݼ�����������*/
		case 12:list = combine(1); count++;break;//�������ϲ���������
			/*����Ĵ�����1����Ϊ������������β�巨�ĺ�����β�巨�������ж�count��ֵ�Ƿ�Ϊ�����ж��Ƿ�������*/
		case 13:system("cls"); break;//����
		case 14:Max(list); break;
		default:printf("��������������룺\n");
		}
	}
	return 0;
}

//�˵�����
void menu() {
	printf("----------------\n");
	printf("*�����������*\n");
	printf("----------------\n");
	printf("-----0.EXIT-----\n");
	printf("---1.��������---\n");
	printf("---2.����ڵ�---\n");//ͷ����β��
	printf("---3.ɾ���ڵ�---\n");
	printf("---4.���ҽڵ�---\n");
	printf("---5.������---\n");
	printf("---6.��ӡ����---\n");
	printf("---7.�������---\n");
	printf("---8.��������---\n");
	printf("---9.ɾ��ż��---\n");
	printf("--10.��ż����---\n");
	printf("--11.��������---\n");
	printf("--12.�ϲ�����---\n");
	printf("--14.�����ֵ---\n");
	printf("----13.����-----\n");
	printf("----------------\n");
	printf("�����룺");
}

//1.��������
Node* createList(Node* list,int count) {
	if (count > 0) {//����0˵���Ѿ�����������
		printf("��������\n");
		return list;
	}
	//������ǵ�һ�δ�������
	list->next = NULL;//����һ��ͷָ��
	printf("�����ɹ���\n");
	return list;
}

//1.1�ж��Ƿ�����������ÿ������ǰ��
int isList(int count) {
	if (count == 0) {//˵��û�н��й�����1
		printf("���ȴ�������\n");
		return 0;
	}
	return 1;
}

//2.�������ʱ���û���������
//ѡ����뷽��
int choise() {
	printf("��ѡ�񣺣�1.ͷ�巨��2.β�巨��\n");
	int i;		
	scanf("%d", &i);
	return i;
}
//2.1ͷ�巨
Node* headInsert(Node* head) {
		int in;//�ڵ�ֵ
		printf("��������ӵĽڵ��ֵ(-1����)��\n");
		while (1) {
			scanf("%d", &in);//����ڵ�ֵ
			if (in != -1) {//-1��������
				Node* new = (Node*)malloc(sizeof(Node));//����һ���½ڵ�
				if (new == NULL) {//�ж϶�̬�ռ�ķ����Ƿ�ɹ���ȡ����NULLָ�������
					return head;
				}
				new->data = in;//�������ֵ�����½ڵ���
				new->next = head->next;//�½ڵ��ָ��ָ��ԭ��ͷ�ڵ�ָ��ĵط�
				head->next = new;//ͷ�ڵ��ָ��ָ���½��
				getchar();//���������
			}
			else {//-1����
				break;
			}
		}
		printf("������ɣ�\n");
		return head;//����ͷ�ڵ㣬���Ƿ�������
}

//���������һ�β��������Ҳ�����нڵ���ڣ�����β�����һ���ڵ㣬��ô�͵ý����нڵ������ͷ�ڵ�ָ���Ƶ����һ���ڵ�
//������ͷָ���Ƶ����һλ������β�壺
Node* f(Node* head1) {//ѭ����ͷָ���ƶ������һ��
	while (head1->next != NULL) {
		head1 = head1->next;
	}
	return head1;
}
//�ж������Ƿ��нڵ�
int F(Node* head1) {
	head1 = head1->next;
	if (head1 != NULL) {
		return 1;
	}
	return 0;
}

//2.2β�巨
Node* endInsert(Node* head) {
	int in;//�ڵ�ֵ
	Node* head1 = (Node*)malloc(sizeof(Node));//�½�һ���ڵ�������ͷ�ڵ���в���
	if (head1 == NULL) {//�ж϶�̬�ռ�ķ����Ƿ�ɹ���ȡ����NULLָ�������
		return head;
	}
	head1 = head;//���½ڵ���ͷ�ڵ���ȣ���������ͷ�ڵ��ƶ�
	printf("��������ӵĽڵ��ֵ(-1����)��\n");
	if (F(head1) == 1) {//�ж��Ƿ��нڵ������
		head1 = f(head1);//�еĻ��ͽ�ͷ�ڵ�ָ���Ƶ����һλ��ͷָ�룬����ͬ��ʼ��������β��
	}
	while (1) {
		Node* new = (Node*)malloc(sizeof(Node));//�½�һ�����
		if (new == NULL) {//�ж϶�̬�ռ�ķ����Ƿ�ɹ���ȡ����NULLָ�������
			return head;
		}
		scanf("%d", &in);//����ֵ
		if (in != -1) {
			new->data = in;//�������ֵ�����½ڵ���
			new->next = NULL;//�½ڵ��ָ����Զָ��NULL
			head1->next = new;//ͷ�ڵ��ָ��ָ���½��
			/*���ϲ�����ͷ��û������Ϊβ���Ҿ��ǰ���������һ��ͷ�壬�����һ�����Ϊͷ�ڵ������һ���ڵ�*/
			head1 = head1->next;//ÿ�β���һ���󣬾ͽ�ͷ�ڵ�������һ��
			getchar();//���������
		}
		else {//-1����
			break;
		}
	}
	printf("������ɣ�\n");
	return head;//��Ϊ��Ҫ����ͷ�ڵ㣬��ͷ�ڵ������������ı��ٷ��ؾͻ�������Ծʹ����½ڵ�����������
}

//2.����ڵ㣬�������ͷ��β��
Node* insert(Node* head,int count) {
	if (isList(count) == 0) {//�ж��Ƿ����������
		return head;
	}
	int i = choise();//ѡ��ͷ��β��
	if (i == 1) {
		return headInsert(head);//2.1ͷ�巨
	}
	else if (i == 2) {
		return endInsert(head);//2.2β�巨
	}
	else {//ѡ��ʱ�����˳�1 2�����
		printf("�������û�и�ѡ���\n");
		return head;
	}
}

//3.ɾ���ڵ�
Node* delete(Node* head, int count) {
	if (isList(count) == 0) {//�ж��Ƿ����������
		return head;
	}
	int pdata;//����һ��������Ҫɾ���ڵ��ֵ�������ж�
	printf("����������ɾ���Ľڵ����ݣ�\n");
	scanf("%d", &pdata);
	Node* pFront = head;//�½�һָ����Ŀ��ڵ�ǰһ�ڵ㣬�ӱ�ɾ�������ͷ�ڵ㿪ʼ
	Node* pNode = head->next;//�½�һָ����Ŀ��ڵ㣬�ӱ�ɾ��������ĵ�һ���ڵ㿪ʼ
	while (pNode!=NULL) {//���������ж�������ֵ��ȵĽڵ㣬�Ǿ���Ҫ��ɾ���Ľڵ�
		if (pNode->data == pdata) {//������˵���ҵ���Ҫɾ���Ľڵ�
			pFront->next = pNode->next;//�ͽ��ýڵ��ǰһ�ڵ��ں�һ�ڵ���������
			free(pNode);//free�������ͷſռ䣬�����ͷű�ɾ���Ľڵ�Ŀռ�
			printf("ɾ���ɹ���\n");
			return head;//����ɾ���������
		}
		pFront = pNode;//����ƶ�һ���ڵ�
		pNode = pNode->next;//����ƶ�һ���ڵ�
	}
	printf("ɾ��ʧ�ܣ�����û�иýڵ㣡\n");
	return head;
}

//4.���ҽڵ�
void find(Node* head, int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return;
	}
	printf("��������Ҫ���ҵĽڵ�����ݣ�\n");
	int pdata;//Ҫɾ��������
	int count1 = 1;//�������ǽڵ�λ��
	int ok=0;//����һ��������
	/*��Ϊһ����������ж����ͬ��������ͬ�Ľڵ㣬��Ҫ�����Ƕ��������������Ҫ����ȫ���ڵ㣬
	��������ڵ�ͻ����û�в��ҵ��ýڵ㣬���Զ����ok���������������*/
	scanf("%d", &pdata);//����Ҫɾ��������
	Node* pMove = (Node*)malloc(sizeof(Node));//�¼�һ��ָ�룬������ѭ������Ŀ�����ݣ��Ǿ���һ��ָ���������ƶ�
	if (pMove == NULL) {//�ж϶�̬�ռ��Ƿ����ɹ�
		return head;
	}
	pMove = head->next;//�ӵ�һ���ڵ㿪ʼ
	while (pMove != NULL) {
		if (pMove->data == pdata) {
			printf("�ҵ��ˣ��ýڵ�������ĵ�%d���ڵ�\n",count1);
			ok = 1;//��ok=1Ȼ���������
		}
		pMove = pMove->next;//�����һ��
		count1++;//�ǽڵ�λ��
	}
	if (ok == 0) {//���Ǳ������û���ҵ��ڵ㣬����ok���ɵ���0
		printf("�Ҳ�����������û�иýڵ㣡\n");
	}
} 
//5.������
void getLength(Node* head, int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return 0;
	}
	int count1 = 0;//�ǳ���
	head = head->next;//ͷ�ڵ㲻�㣬�ӵ�һ�������ݵĽڵ㿪ʼ
	while (head != NULL) {
		head = head->next;
		count1++;
	}
	printf("������Ϊ%d\n", count1);
}
//6.��ӡ����
void print(Node* head, int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return;
	}
	printf("����Ϊ:");
	head=head->next;//�ӵ�һ�������ݵĽڵ㿪ʼ
	while (head != NULL) {
		printf("%d ", head->data);
		head=head->next;
	}
	printf("\n");//��˵�����
}
//7.�������
int rebuild(Node* list,int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return count;
	}
	Node* pMove;//�½�һ��ָ�뷽����������
	
	while (list != NULL) {
		pMove = list;
		list = list->next;
		free(pMove);//��ѭ���ͷ�ÿһ���ڵ�ռ�
	}
	printf("ԭ�������������\n");
	return 0;//����0��countֵ
}
//8.��������
//˼·����ԭ����Ľڵ���ͷ�巨һ��һ�����������в���һ���γ�һ�����������ǵ��ú������
Node* reverse(Node* head,int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return head;
	}
	Node* new = (Node*)malloc(sizeof(Node));//�½�һ���������������ú������
	Node* pMove = (Node*)malloc(sizeof(Node));//�½�һ���ڵ㣬��������
	if (new == NULL && pMove==NULL) {//�ж϶�̬�ռ��Ƿ����ɹ�
		return head;
	}
	new->next = NULL;//ͷ�ڵ�
	head = head->next;//ԭ����ӵ�һ���ڵ㿪ʼ
	while (head != NULL) {
		pMove = head;//�Ƚ�pMoveָ��ԭ����ĵ�һ���ڵ�
		head = head->next;//Ȼ��ԭ������������ƶ�һ��
		pMove->next = new->next;//��pMoveָ��Ľڵ�ָ��������ͷ�ڵ����һ��
		new->next = pMove;//������ͷ�ڵ�ָ��pMove
	}
	printf("���óɹ���\n���ú��");
	print(new,count);//��ӡһ������
	return new;//���ص��ú������
}
//9.ɾ��ż��Ԫ�ؽڵ�
Node* deleteO(Node* head, int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return head;
	}
	Node* pFront; //�½�һ��ָ�룬��������Ŀ��ڵ��ǰһ���ڵ�
	Node* pNode; //�½�һ��ָ�룬��������Ŀ��ڵ㣬����ż���ڵ�
	pFront = head;//��ͷ�ڵ�ָ��
	pNode = head->next;//�ӵ�һ���ڵ㿪ʼ
	while (pNode != NULL) {
		if (pNode->data % 2 == 0) {//ż��
			pFront->next = pNode->next;//���������ڵ��ǰһ���ͺ�һ����������
			free(pNode);//�ͷ�ż���ڵ�ռ�
			deleteO(head, count);//��ɾ��һ��ż���ڵ���������еݹ�
			/*��Ϊ�ͷ���pNode�󣬻�Ҫ�ж���һ���ڵ㣬���ǲ����ҵ�������һ���ڵ�����жϣ����ֵ��½�һ����
			��ʱ������ô���������*/
		}
		//�������Ŀ��ڵ�ͼ�������
		pFront = pFront->next;
		pNode = pFront->next;
	}
	return head;
}
//10.��ż����������
void resolve(Node* head, int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return;
	}
	Node* J = (Node*)malloc(sizeof(Node));//�½���������
	Node* O = (Node*)malloc(sizeof(Node));//�½�ż������
	Node* pFront = head;//�½�һ���ƶ�ָ�룬������в���
	J->next = NULL;
	O->next = NULL;
	if (J == NULL && O == NULL) {//�ж϶�̬�ռ�����Ƿ�ɹ���ȡ��NULL��ָ�������
		return head;
	}
	head = head->next;//head���ƣ��ӵ�һ���ڵ㿪ʼ
	while (head) {//head��ΪNULL
		if (head->data % 2 == 0) {//ż��
			pFront->next = head->next;//���Ӹýڵ�ǰ��ڵ�
			head->next = O->next;//���ýڵ��ָ��ָ��ż�������ͷ�ڵ����һ��
			O->next = head;//ż�������ͷ�ڵ�ָ��ýڵ�
			/*��һ������ͷ�巨*/
			head = pFront->next;//��headָ����һ��
			continue;//������ǰѭ���������ж�
		}
		else {//����������ͬ��
			pFront->next = head->next;
			head->next = J->next;
			J -> next = head;
			head = pFront->next;
			continue;
		};
	}
	//��ӡ������
	printf("����");
	print(J, count);
	printf("ż��");
	print(O, count);
	printf("ԭ����Ϊ��\n");
	/*��Ϊû�д��������Ǳߴ����������ԾͲ������ˣ�������д��
	���Ǵ��������Ǳ߽��ܵ���������˷��룬����ԭ�����ᱻ��ɿյ�*/
}

//11.����Ԫ���Էǵݼ�����
//ûд�ж��Ƿ��Ƿǵݼ����������ĳ�������ֻ�ܿ��û��Ծ�����,�����һ���ݼ���������Ļ�������ֵ�ͻ᲻��
Node* createList2(Node* head, int count) {
	if (isList(count) == 0) {//�ж��Ƿ�������
		return head;
	}
	int intput;//Ҫ����Ľڵ��ֵ
	Node* newNode=(Node*)malloc(sizeof(Node));//Ҫ����Ľڵ�
	if (newNode == NULL) {//�ж϶�̬�ռ��Ƿ����ɹ�
		return head;
	}
	Node* pFront;//�������ǰһ�ڵ�
	Node* pMove;//����ԭ�����б���Ľڵ�
	if (head == NULL) {
		printf("ԭ����Ϊ�գ�\n");
		return head;
	}
	pMove = head->next;
	pFront = head;

	printf("������������Ԫ�أ�\n");
	scanf("%d", &intput);
	newNode->data = intput;//��ֵ����Ҫ����Ľڵ�
	while (pMove) {
		if (newNode->data > pMove->data) {//����½ڵ��ֵ����ԭ����ڵ��ֵ���Ǿͽ�ԭ����Ľڵ����
			pMove = pMove->next;
			pFront = pFront->next;
		}
		else {//���С�ڵ��ڣ��ͽ��½ڵ�嵽ԭ����Ľڵ��ǰһ��λ��
			pFront->next = newNode;
			newNode->next = pMove;
			print(head, count);
			return head;
		}
	}
}

//12.���������������ϲ���һ��
Node* combine(int count) {
	//�½���������������������������ֻ�п��û��Ծ�����
	Node* L1 = (Node*)malloc(sizeof(Node));
	Node* L2 = (Node*)malloc(sizeof(Node));
	//�½�һ���������鲢�������
	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL && L1 == NULL && L2 == NULL) {//�ж��ڴ��Ƿ����ɹ�
		return 0;
	}
	Node* n1;//��new��ͷ�ڵ�
	Node* p1;//��L1�ĵ�һ���ڵ㣬������ڲ���
	Node* p2;//��L2�ĵ�һ���ڵ㣬������ڲ���

	//����������ͷ�ڵ㶼ָ��NULL
	new->next = NULL;
	L1->next = NULL;
	L2->next = NULL;

	printf("������һ������\n");
	L1 = endInsert(L1);//��������
	printf("�����ڶ�������\n");
	L2 = endInsert(L2);//��������
	p1 = L1->next;
	p2 = L2->next;
	n1 = new;
	while (p1 != NULL && p2 != NULL) {//������������һ����������˳�
		if (p1->data > p2->data) {
			L2->next = p2->next;
			p2->next = n1->next;//��С�Ľڵ��ָ��ָ�����������һ��
			n1->next = p2;//���������һ�� ָ����������ڵ�
			n1 = n1->next;//�������ͷ�ڵ����һ��
			p2 = L2->next;//ԭ�����ָ��Ҳ����һ��
		}
		else {//����ԭ��ͬ��
			L1->next = p1->next;
			p1->next = n1->next;
			n1->next = p1;
			n1 = n1->next;
			p1 = L1->next;
		}
	}
	//����ѭ���˳���˵��������һ������Ƚ����ˣ������ǲ�֪������һ��������߻�����������
	//�����ٷֿ�ѭ��
	//���û�бȽ��꣬��ô��ֱ�ӽ������ֵ����������������У����ǻ�����Ҫ�û����������������Ĳ�����������
	while (p1 != NULL) {
		L1->next = p1->next;
		p1->next = n1->next;
		n1->next = p1;
		n1 = n1->next;
		p1 = L1->next;
	}
	while (p2 != NULL) {
		L2->next = p2->next;
		p2->next = n1->next;
		n1->next = p2;
		n1 = n1->next;
		p2 = L2->next;
	}
	print(new, 1);//��ӡ
	return new;//����������

	////������������������ϲ�Ϊһ���ݼ���������
	////L1��L2Ϊ����������������
	//p1 = L1;//����p1����L1
	//while (p1->next != NULL) {//���ѭ����p1�Ƶ�L1�����һ���ڵ���
	//	p1 = p1->next;
	//}
	//p1->next = L2->next;//�ϲ�����L2������L1�ĺ���
	//p1 = L1->next;//Ȼ��p1�ص�L1�ĵ�һ�����
	//p2 = L1->next;//��һ��p2Ҳ��L1�ĵ�һ�����
	//Node* m = NULL;//����һ��m����NULL������ѭ������
	////ð�����򷨣���һ�ε�mΪNULL���ڶ��ε�mΪ��һ������������ֵ��������Ϊ�ڶ��ε�ֵ��.....
	//while (p1 != m) {
	//	while (p1->next != m) {
	//		if (p1->data < p1->next->data) {
	//			int tmp = p1->data;
	//			p1->data = p1->next->data;
	//			p1->next->data = tmp;
	//		}
	//		p1 = p1->next;
	//	}
	//	m = p1;//����m��ֵ��mʼ��Ϊ��һ�����������Ľ�㣬m�൱�ڴ����һ����ǰ�ߣ���������ѭ�������δμ���
	//	p1 = p2;//û������һ�������ͽ�p1�����ƶ�����ǰ�ĵ�һ������������
	//}
	//
	//print(L1, 1);
	//return L1;

}
void Max(Node* head) {//�����������
	int max = head->next->data;//����һ������ֵ����Ϊ���ֵ
	head = head->next;//����ӵ�һ����㿪ʼ
	while (head) {
		if (max < head->data) {//������ϱ�max���ֵ���ͽ����ֵ����max
			max = head->data;
		}
		head = head->next;//�ƶ�����һ�����
	}
	printf("���ֵ�ǣ�%d\n", max);
}
