#define _CRT_SECURE_NO_WARNINGS 1


/*���к��������ͽṹ�������������ͷ�ļ���*/
#include"Queue.h"


int main1(){
	SQ queue;
	SQ* q = &queue;
	q->rear = 0;
	q->head = 0;
	q->length = 0;
	int chose;
	int num;
	
	while (1) {
		menu1();			//�˵�
		scanf("%d", &chose);
		switch (chose) {
		case 1:
			printf("��������ӵ�ֵ��");
			scanf("%d", &num);
			Enqueue(q, num);			//��Ӳ���
			printf("��ӳɹ���\n");
			break;
		case 2:
			if (q->length == 0) {
				printf("��ǰ�նӣ�\n");
				break;
			}
			Dequeue(q);					//���Ӳ���
			printf("���ӳɹ���\n");
			break;
		case 3:
			ClearQueue(q);				//��նӲ���
			printf("��ճɹ���\n");
			break;
		case 4:							//��ʾ������Ԫ��
			if (q->length == 0) {
				printf("��ǰ�նӣ�\n");
				break;
			}
			printf("�ö��е���Ԫ���ǣ�%d\n", HeadOfQueue(q));
			break;
		case 5:							//��ʾ���г���
			printf("�ö��е�Ԫ�ظ����ǣ�%d\n", LengthOfQueue(q));
			break;
		case 6:
			if (q->length == 0) {
				printf("��ǰ�նӣ�\n");
				break;
			}
			printf("��ǰ���У�");
			PrintQueue(q);				//��ӡ����
			printf("\n");
			break;
		case  7:
			File(q);
			printf("����ɹ���\n");
			break;
		case 0:
			return 0;
		default:
			printf("��������������룺\n");
		}
	}
	return 0;
}
//1�����
/*��������Ԫ����ӣ�����д��ѭ����ӿ��*/
/*��Ϊ��ʼ�ӵ�ͷָ��βָ�붼ָ��0��λ�ã��������rearҪ++*/
void Enqueue(SQ* q,int num) {
	q->data[q->rear++] = num;		
	q->length++;			//���е�Ԫ�ظ���
}

//2������
void Dequeue(SQ* q) {
	q->head++;				//�ӵ�head++
	q->length--;			//Ԫ�ؼ���
}

//3����ն���
void ClearQueue(SQ* q) {
	while (q->head != q->rear) {	//��������վ�����ͷָ����һ��λ�ã���head����++��rear����Ϊ���ջջ�Ĵ�С�����
		q->rear--;
	}
	q->length = 0;			//ͬʱ��Ԫ�ظ�����Ϊ0
}

//4������Ԫ��
DataType HeadOfQueue(SQ* q) {
		return (q->data[q->head]);	//ֻҪ���ǳ�ջͷָ���ǲ����ƶ��ģ�����ֱ�Ӵ�ӡ����
}

//5������Ԫ�ظ���
int LengthOfQueue(SQ* q) {
	return q->length;		//ֱ�Ӵ�ӡlength
}

//6����ӡ����
void PrintQueue(SQ* q) {
	int i = q->head;		//��ӡ���е����ǳ��ӣ�����������ָ�����ԭ��ָ�����
	int j = q->rear;
	for (i; i < j; i++) {
		printf("%d ", q->data[i]);
	}
}
//7�������ļ�
void File(SQ* q) {
	FILE* pfWrite1;
	// ���ļ�
	pfWrite1 = fopen("SqQueue.txt", "w");
	if (pfWrite1 == NULL) {
		printf("%s\n", strerror(errno));
	}
	//д�ļ�
	for (int i = 0; i < q->length; i++) {
		fprintf(pfWrite1, "%d ", q->data[i]);
	}
	//�ر��ļ�
	fclose(pfWrite1);
	pfWrite1 = NULL;
}


void menu1() {
	printf("###################\n");
	printf("   1���������\n");
	printf("   2�����ݳ���\n");
	printf("   3����ն���\n");
	printf("   4������Ԫ��\n");
	printf("   5��Ԫ�ظ���\n");
	printf("   6����ӡ����\n");
	printf("   7������Ϊ�ļ�\n");
	printf("   0���˳�\n");
	printf("###################\n");
	printf("�����룺\n");
}