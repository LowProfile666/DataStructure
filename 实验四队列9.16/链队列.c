#define _CRT_SECURE_NO_WARNINGS 1

/*���к��������ͽṹ�������������ͷ�ļ���*/
#include"Queue.h"


int main2(){
	//����ͷ�ڵ�
	Node head = (Node)malloc(sizeof(Node));
	head->next = NULL;
	//��������
	LQ L;
	LQ* p = &L;
	p->size = 0;		//���ӵ�Ԫ�ظ�����ʼΪ0
	p->head = head;		//���ӵ�ͷָ���ʼָ��ͷ�ڵ�
	p->rear = head;		//ͬ��
	int chose;
	DataType num;		//��ӵ�ֵ
	while (1) {
		menu1();		//�˵�
		scanf("%d", &chose);
		switch (chose) {
		case 1:								//��Ӳ���
			printf("������Ҫ��ӵ�ֵ��\n");
			scanf("%d", &num);
			Enqueue2(p,num);
			printf("��ӳɹ���\n");
			break;
		case 2:								//���Ӳ���
			if (p->head == p->rear) {		//�ж��Ƿ�ն�
				printf("��ǰ�ǿն��У�\n");
				break;
			}
			Dequeue2(p);
			printf("���ӳɹ���\n");
			break;
		case 3:								//��ն���
			ClearQueue2(p);
			printf("��ճɹ���\n");
			break;
		case 4:								//������Ԫ��
			if (p->head == p->rear) {
				printf("��ǰ�ǿն��У�\n");
				break;
			}
			printf("�ö�����Ԫ����:%d \n",HeadOfQueue2(p)); 
			break;
		case 5:								//����Ԫ�ظ���
			printf("�ö���Ԫ�ظ�����:%d\n",SizeOfQueue2(p));
			break;
		case 6:								//��ӡ����
			if (p->head == p->rear) {
				printf("��ǰ�ǿն��У�\n");
				break;
			}
			printf("��ǰ���У�");
			PrintQueue2(p);
			printf("\n");
			break;
		case 7:
			SaveFile2(p);
			printf("����ɹ���\n");
			break;
		case 0:
			return 0;
		default:printf("��������������룺\n");
		}
	}
	return 0;
}
//1����Ӳ���
void Enqueue2(LQ* p,DataType num) {
	Node new = (Node*)malloc(sizeof(Node));	//�½�һ�����
	new->data = num;						//��ֵ
	new->next = NULL;						//����ָ��NULL
	p->rear->next = new;					//��һ����βָ���ͷ�ڵ㽫ͷ�ڵ����½�����������Ժ���ǽ����һ�������½ڵ�������
	p->rear = new;							//βָ���ƶ����½����
	p->size++;								//Ԫ�ظ�����һ
}
//2�����Ӳ���
void Dequeue2(LQ* p) {
	p->head = p->head->next;				//ͷָ���ƶ�����һ��������
	p->size--;								//Ԫ�ظ���Ҫ��һ
}
//3����ն���
void ClearQueue2(LQ* p) {
	while (p->head != p->rear) {			//һֱ����ֱ����ָ��ָ����һ��
		Dequeue2(p);						//���ó��Ӻ���
	}
	p->size = 0;							//��Ԫ�ظ���Ϊ0
}
//4������Ԫ��
DataType HeadOfQueue2(LQ* p) {
	Node new = p->head->next;				//�ø�new����ͷָ�룬��Ȼͷָ��ᷢ���仯
	return new->data;
}
//5��Ԫ�ظ���
int SizeOfQueue2(LQ* p) {
	return p->size;							//ֱ�ӷ���
}
//6����ӡ����
void PrintQueue2(LQ* p) {
	Node new = p->head->next;				//��ӡ�����ӣ������ø�new����ͷָ�룬ѭ����ӡһֱ��new==NULL
	while (new != NULL) {
		printf("%2d ", new->data);
		new=new->next;
	}
}

//7�������ļ�
void SaveFile2(LQ* q) {
	// ���ļ�
	FILE* pfWrite2= fopen("LkQueue.txt", "w");
	if (pfWrite2 == NULL) {
		printf("%s\n", strerror(errno));
	}
	//д�ļ�
	for (Node i = q->head->next; i !=NULL; i=i->next) {
		fprintf(pfWrite2, "%d ", i->data);
	}
	//�ر��ļ�
	fclose(pfWrite2);
	pfWrite2 = NULL;
}
