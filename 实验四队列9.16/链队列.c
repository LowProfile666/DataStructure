#define _CRT_SECURE_NO_WARNINGS 1

/*所有函数声明和结构体声明都在这个头文件里*/
#include"Queue.h"


int main2(){
	//创建头节点
	Node head = (Node)malloc(sizeof(Node));
	head->next = NULL;
	//创建链队
	LQ L;
	LQ* p = &L;
	p->size = 0;		//链队的元素个数初始为0
	p->head = head;		//联队的头指针初始指向头节点
	p->rear = head;		//同上
	int chose;
	DataType num;		//入队的值
	while (1) {
		menu1();		//菜单
		scanf("%d", &chose);
		switch (chose) {
		case 1:								//入队操作
			printf("请输入要入队的值：\n");
			scanf("%d", &num);
			Enqueue2(p,num);
			printf("入队成功！\n");
			break;
		case 2:								//出队操作
			if (p->head == p->rear) {		//判断是否空队
				printf("当前是空队列！\n");
				break;
			}
			Dequeue2(p);
			printf("出队成功！\n");
			break;
		case 3:								//清空队列
			ClearQueue2(p);
			printf("清空成功！\n");
			break;
		case 4:								//队列首元素
			if (p->head == p->rear) {
				printf("当前是空队列！\n");
				break;
			}
			printf("该队列首元素是:%d \n",HeadOfQueue2(p)); 
			break;
		case 5:								//队列元素个数
			printf("该队列元素个数是:%d\n",SizeOfQueue2(p));
			break;
		case 6:								//打印队列
			if (p->head == p->rear) {
				printf("当前是空队列！\n");
				break;
			}
			printf("当前队列：");
			PrintQueue2(p);
			printf("\n");
			break;
		case 7:
			SaveFile2(p);
			printf("保存成功！\n");
			break;
		case 0:
			return 0;
		default:printf("输入错误！重新输入：\n");
		}
	}
	return 0;
}
//1、入队操作
void Enqueue2(LQ* p,DataType num) {
	Node new = (Node*)malloc(sizeof(Node));	//新建一个结点
	new->data = num;						//赋值
	new->next = NULL;						//将他指向NULL
	p->rear->next = new;					//第一次用尾指针代头节点将头节点与新结点连起来，以后就是将最后一个结点和新节点连起来
	p->rear = new;							//尾指针移动到新结点上
	p->size++;								//元素个数加一
}
//2、出队操作
void Dequeue2(LQ* p) {
	p->head = p->head->next;				//头指针移动到下一个即出队
	p->size--;								//元素个数要减一
}
//3、清空队列
void ClearQueue2(LQ* p) {
	while (p->head != p->rear) {			//一直出队直到两指针指在了一起
		Dequeue2(p);						//调用出队函数
	}
	p->size = 0;							//将元素个数为0
}
//4、队首元素
DataType HeadOfQueue2(LQ* p) {
	Node new = p->head->next;				//用个new代替头指针，不然头指针会发生变化
	return new->data;
}
//5、元素个数
int SizeOfQueue2(LQ* p) {
	return p->size;							//直接返回
}
//6、打印队列
void PrintQueue2(LQ* p) {
	Node new = p->head->next;				//打印不出队，所以用个new代替头指针，循环打印一直到new==NULL
	while (new != NULL) {
		printf("%2d ", new->data);
		new=new->next;
	}
}

//7、保存文件
void SaveFile2(LQ* q) {
	// 打开文件
	FILE* pfWrite2= fopen("LkQueue.txt", "w");
	if (pfWrite2 == NULL) {
		printf("%s\n", strerror(errno));
	}
	//写文件
	for (Node i = q->head->next; i !=NULL; i=i->next) {
		fprintf(pfWrite2, "%d ", i->data);
	}
	//关闭文件
	fclose(pfWrite2);
	pfWrite2 = NULL;
}
