#define _CRT_SECURE_NO_WARNINGS 1


/*所有函数声明和结构体声明都在这个头文件里*/
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
		menu1();			//菜单
		scanf("%d", &chose);
		switch (chose) {
		case 1:
			printf("请输入入队的值：");
			scanf("%d", &num);
			Enqueue(q, num);			//入队操作
			printf("入队成功！\n");
			break;
		case 2:
			if (q->length == 0) {
				printf("当前空队！\n");
				break;
			}
			Dequeue(q);					//出队操作
			printf("出队成功！\n");
			break;
		case 3:
			ClearQueue(q);				//清空队操作
			printf("清空成功！\n");
			break;
		case 4:							//显示队列首元素
			if (q->length == 0) {
				printf("当前空队！\n");
				break;
			}
			printf("该队列的首元素是：%d\n", HeadOfQueue(q));
			break;
		case 5:							//显示队列长度
			printf("该队列的元素个数是：%d\n", LengthOfQueue(q));
			break;
		case 6:
			if (q->length == 0) {
				printf("当前空队！\n");
				break;
			}
			printf("当前队列：");
			PrintQueue(q);				//打印队列
			printf("\n");
			break;
		case  7:
			File(q);
			printf("保存成功！\n");
			break;
		case 0:
			return 0;
		default:
			printf("输入错误！重新输入：\n");
		}
	}
	return 0;
}
//1、入队
/*单个单个元素入队，可以写个循环入队快点*/
/*因为初始队的头指针尾指针都指在0的位置，所以入队rear要++*/
void Enqueue(SQ* q,int num) {
	q->data[q->rear++] = num;		
	q->length++;			//队列的元素个数
}

//2、出队
void Dequeue(SQ* q) {
	q->head++;				//队的head++
	q->length--;			//元素减少
}

//3、清空队列
void ClearQueue(SQ* q) {
	while (q->head != q->rear) {	//将队列清空就是两头指针在一个位置，但head不能++到rear，因为清空栈栈的大小不会变
		q->rear--;
	}
	q->length = 0;			//同时将元素个数变为0
}

//4、队首元素
DataType HeadOfQueue(SQ* q) {
		return (q->data[q->head]);	//只要不是出栈头指针是不会移动的，可以直接打印出来
}

//5、队列元素个数
int LengthOfQueue(SQ* q) {
	return q->length;		//直接打印length
}

//6、打印队列
void PrintQueue(SQ* q) {
	int i = q->head;		//打印队列但不是出队，所以拿两个指针代替原两指针操作
	int j = q->rear;
	for (i; i < j; i++) {
		printf("%d ", q->data[i]);
	}
}
//7、保存文件
void File(SQ* q) {
	FILE* pfWrite1;
	// 打开文件
	pfWrite1 = fopen("SqQueue.txt", "w");
	if (pfWrite1 == NULL) {
		printf("%s\n", strerror(errno));
	}
	//写文件
	for (int i = 0; i < q->length; i++) {
		fprintf(pfWrite1, "%d ", q->data[i]);
	}
	//关闭文件
	fclose(pfWrite1);
	pfWrite1 = NULL;
}


void menu1() {
	printf("###################\n");
	printf("   1、数据入队\n");
	printf("   2、数据出队\n");
	printf("   3、清空队列\n");
	printf("   4、队首元素\n");
	printf("   5、元素个数\n");
	printf("   6、打印队列\n");
	printf("   7、保存为文件\n");
	printf("   0、退出\n");
	printf("###################\n");
	printf("请输入：\n");
}