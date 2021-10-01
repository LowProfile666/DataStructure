#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef int ElemType;
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode,*L;
Lnode Link;//创建链表
L head=&Link;//头指针

//声明函数
void menu();
void YSF();
void MENOKEYKING();

int main(){
	system("title 循环链表操作");
	int n;
	while (1) {
		menu();	//菜单
		scanf("%d", &n);	//输入选择
		switch (n) {
		case 1:system("cls"); system("title 约瑟夫问题"); YSF(); break;	//约瑟夫问题
		case 2:system("cls"); system("title 求猴子大王"); MENOKEYKING(); break;	//猴子大王
		case 0:free(Link); return;	//退出
		default:printf("输入错误！\n");
		}
	}
	return 0;
}
void menu() {
	printf("+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("+-   循环链表的用法  -+\n");
	printf("+---------------------+\n");
	printf("+-   1、约瑟夫问题   -+\n");
	printf("+-   2、猴子取大王   -+\n");
	printf("+-      0、退出      -+\n");
	printf("+---------------------+\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("请选择：\n");
}
//约瑟夫创建链表函数
void Create() {
	head->next = NULL;	//将头指针指向NULL
	L h = head;	//代替头指针，用来移动
	printf("请先初始化：（-1结束）\n");
	while (1) {
		L new = (L)malloc(sizeof(L));	//新建结点
		scanf("%d", &new->data);	//赋值
		getchar();	//用来接受掉多余的 空格
		if (new->data == -1) {	//-1结束
			return;
		}
		h->next = new;	//将新节点连上
		new->next = head->next;	//直接将新节点的next指向第一个结点
		h = h->next;	//h后移
	}
}
//约瑟夫问题
void YSF() {
	Create();	//初始化链表
	printf("请输入起点结点的数据：\n");
	int begin;	
	scanf("%d", &begin);
	printf("请输入目标大小：\n");
	int num;
	scanf("%d", &num);
	L h = head->next;	//代替头指针用来移动
	L f = head;	//作h的前一个结点，用来找到h
	//先用循环找到起点
	while (1) {
		if (h->data == begin) {
			break;
		}
		f = f->next;
		h = h->next;
	}
	
	int count = 1;	//计数
	while (h->next!=h) {	//只剩下一个结点的条件
		h = h->next;	
		f = f->next;
		count++;	//移动一个结点就加一
		if (count == num) {	//加到目标值了
			f->next = h->next;	//将该节点去除
			h = f->next;	//h后移
			count = 1;	//重置count
		}
	}
	printf("最后一个结点是：%d\n", h->data);
}
//猴子大王
void MENOKEYKING() {
	printf("请输入猴子的个数：\n");
	int num;
	scanf("%d", &num);
	L h = head;	//代替头指针用来移动
	for (int i = 1; i <= num; i++) {	//循环为猴子们编号，和上面差不多
		L new = (L)malloc(sizeof(L));
		new->data = i;
		h->next = new;
		new->next = head->next;
		h = new;
	}
	printf("你想从第几只猴子开始：\n");
	int n;	//起点
	scanf("%d", &n);
	h = head->next;	//将h移回第一个结点的位置，方便下面的f
	L f = head;	//作h的前一节点，如果h不是第一个结点的话，那么f就不好定义
	while (1) {	//循环找到起点
		h = h->next;
		f = f->next;
		if (h->data == n) {
			break;
		}
	}
	printf("请输入目标数：\n");	
	int a;
	scanf("%d", &a);

	int count = 1;	//计数
	while (h != h->next) {	//只剩一个结点的条件，下与上同
		h = h->next;
		f = f->next;
		count++;
		if (count == a) {
			f->next = h->next;
			h = f->next;
			count = 1;
		}
	}
	printf("猴子大王是：%d号猴子！\n", h->data);
}