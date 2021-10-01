#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

/*1．随机产生或键盘输入一组元素，建立一个带头结点的单向链表（无序）。
2．遍历单向链表。√
3．把单向链表中元素逆置（不允许申请新的结点空间）。√
4．在单向链表中删除所有的偶数元素结点。√
5．编写在非递减有序链表中插入一个元素使链表元素仍有序的函数，并利用该函数建立一个非递减有序单向链表。
6．利用实验5建立两个递增有序单向链表，然后合并成一个递增链表。
7．利用实验1建立的链表，实现将其分解成两个链表，其中一个全部为奇数，另一个全部为偶数（尽量利用已知的存储空间）√*/

typedef struct Node {
	int data;//数据域
	struct Node* next;//指针域
}Node;

//函数声明
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
	system("title 单链表的操作");//dos窗口命名
	int intput;//输入的选择值
	Node* list;//创建一个链表
	list = (Node*)malloc(sizeof(Node));//为链表分配动态空间
	/*malloc是动态内存分配函数，用于申请一块连续的指定大小的内存块区域以void*类型返回分配的内存区域地址*/
	int count = 0;//计数用，判断是否是第一次进入程序，第一次进入只能进行创建链表操作
	while (1) {//死循环用于在每次操作后都能返回到菜单界面
		menu();//菜单
		scanf("%d", &intput);//输入选择值
		switch (intput) {
		case 0:printf("退出成功!\n"); return;//退出程序
		case 1:list = createList(list,count); count = 1; break;//创建链表，这个操作执行后count变成1，代表已经创建了链表
		case 2:list=insert(list,count); break;//插入结点，返回插入后的链表
		case 3:list=delete(list,count); break;//删除结点，返回删除后的链表
		case 4:find(list,count); break;//查找结点，输出节点位置
		case 5:getLength(list,count); break;//链表长度
		case 6:print(list,count); break;//打印链表
		case 7:count = rebuild(list,count);  break;//删除已有链表，下次可重建链表
		case 8:list = reverse(list, count); break;//逆置链表
		case 9:
			list = deleteO(list, count); 
			if (count != 0) {//表示有链表存在，防止没有链表的情况下进行了操作9从而执行了下面两句
				printf("删除成功！"); 
				print(list, count); 
			} 
			break;//删除偶节点，返会删除后的链表
		case 10:resolve(list,count); break;//奇偶分离，输出两个两个链表，但原链表会变空
		case 11:list = createList2(list, count);  break;//在有节点的情况下
			/*在非递减有序链表中插入一个元素使链表元素仍有序，并利用该函数建立一个非递减有序单向链表。*/
		case 12:list = combine(1); count++;break;//创建并合并两个链表
			/*这里的传参是1，因为这个函数会调用尾插法的函数，尾插法函数会判断count的值是否为零来判断是否有链表*/
		case 13:system("cls"); break;//清屏
		case 14:Max(list); break;
		default:printf("输入错误，重新输入：\n");
		}
	}
	return 0;
}

//菜单界面
void menu() {
	printf("----------------\n");
	printf("*单链表常规操作*\n");
	printf("----------------\n");
	printf("-----0.EXIT-----\n");
	printf("---1.创建链表---\n");
	printf("---2.插入节点---\n");//头插与尾插
	printf("---3.删除节点---\n");
	printf("---4.查找节点---\n");
	printf("---5.链表长度---\n");
	printf("---6.打印链表---\n");
	printf("---7.清除链表---\n");
	printf("---8.逆置链表---\n");
	printf("---9.删除偶节---\n");
	printf("--10.奇偶分离---\n");
	printf("--11.插入有序---\n");
	printf("--12.合并链表---\n");
	printf("--14.找最大值---\n");
	printf("----13.清屏-----\n");
	printf("----------------\n");
	printf("请输入：");
}

//1.创建链表
Node* createList(Node* list,int count) {
	if (count > 0) {//大于0说明已经创建过链表
		printf("已有链表！\n");
		return list;
	}
	//否则就是第一次创建链表：
	list->next = NULL;//创建一个头指针
	printf("创建成功！\n");
	return list;
}

//1.1判断是否有链表，用在每个操作前面
int isList(int count) {
	if (count == 0) {//说明没有进行过操作1
		printf("请先创建链表！\n");
		return 0;
	}
	return 1;
}

//2.插入操作时与用户交互界面
//选择插入方法
int choise() {
	printf("请选择：（1.头插法，2.尾插法）\n");
	int i;		
	scanf("%d", &i);
	return i;
}
//2.1头插法
Node* headInsert(Node* head) {
		int in;//节点值
		printf("请输入添加的节点的值(-1结束)：\n");
		while (1) {
			scanf("%d", &in);//输入节点值
			if (in != -1) {//-1结束输入
				Node* new = (Node*)malloc(sizeof(Node));//创建一个新节点
				if (new == NULL) {//判断动态空间的分配是否成功，取消对NULL指针的引用
					return head;
				}
				new->data = in;//将输入的值放在新节点内
				new->next = head->next;//新节点的指针指向原本头节点指向的地方
				head->next = new;//头节点的指针指向新结点
				getchar();//清楚缓冲区
			}
			else {//-1结束
				break;
			}
		}
		printf("插入完成！\n");
		return head;//返回头节点，就是返回链表
}

//如果进行了一次插入操作，也就是有节点存在，再想尾插进入一个节点，那么就得将已有节点链表的头节点指针移到最后一个节点
//将链表头指针移到最后一位，方便尾插：
Node* f(Node* head1) {//循环将头指针移动到最后一个
	while (head1->next != NULL) {
		head1 = head1->next;
	}
	return head1;
}
//判断链表是否有节点
int F(Node* head1) {
	head1 = head1->next;
	if (head1 != NULL) {
		return 1;
	}
	return 0;
}

//2.2尾插法
Node* endInsert(Node* head) {
	int in;//节点值
	Node* head1 = (Node*)malloc(sizeof(Node));//新建一个节点来代替头节点进行操作
	if (head1 == NULL) {//判断动态空间的分配是否成功，取消对NULL指针的引用
		return head;
	}
	head1 = head;//将新节点与头节点相等，用来代替头节点移动
	printf("请输入添加的节点的值(-1结束)：\n");
	if (F(head1) == 1) {//判断是否有节点存在了
		head1 = f(head1);//有的话就将头节点指针移到最后一位作头指针，再如同初始那样进行尾插
	}
	while (1) {
		Node* new = (Node*)malloc(sizeof(Node));//新建一个结点
		if (new == NULL) {//判断动态空间的分配是否成功，取消对NULL指针的引用
			return head;
		}
		scanf("%d", &in);//输入值
		if (in != -1) {
			new->data = in;//将输入的值放在新节点内
			new->next = NULL;//新节点的指针永远指向NULL
			head1->next = new;//头节点的指针指向新结点
			/*以上操作和头插没区别，因为尾插我就是把它当成另一种头插，以最后一个结点为头节点插入下一个节点*/
			head1 = head1->next;//每次插入一个后，就将头节点往后移一个
			getchar();//清楚缓冲区
		}
		else {//-1结束
			break;
		}
	}
	printf("插入完成！\n");
	return head;//因为需要返回头节点，而头节点在上叙操作会改变再返回就会出错，所以就创个新节点来代替他，
}

//2.插入节点，从这调用头插尾插
Node* insert(Node* head,int count) {
	if (isList(count) == 0) {//判断是否有链表存在
		return head;
	}
	int i = choise();//选择头插尾插
	if (i == 1) {
		return headInsert(head);//2.1头插法
	}
	else if (i == 2) {
		return endInsert(head);//2.2尾插法
	}
	else {//选择时输入了除1 2外的数
		printf("输入错误，没有该选择项！\n");
		return head;
	}
}

//3.删除节点
Node* delete(Node* head, int count) {
	if (isList(count) == 0) {//判断是否有链表存在
		return head;
	}
	int pdata;//定义一个变量作要删除节点的值来进行判断
	printf("请输入你想删除的节点数据：\n");
	scanf("%d", &pdata);
	Node* pFront = head;//新建一指针作目标节点前一节点，从被删除链表的头节点开始
	Node* pNode = head->next;//新建一指针作目标节点，从被删除的链表的第一个节点开始
	while (pNode!=NULL) {//遍历链表判断于输入值相等的节点，那就是要被删除的节点
		if (pNode->data == pdata) {//如果相等说明找到了要删除的节点
			pFront->next = pNode->next;//就将该节点的前一节点于后一节点连接起来
			free(pNode);//free函数是释放空间，这里释放被删除的节点的空间
			printf("删除成功！\n");
			return head;//返回删除后的链表
		}
		pFront = pNode;//向后移动一个节点
		pNode = pNode->next;//向后移动一个节点
	}
	printf("删除失败！链表没有该节点！\n");
	return head;
}

//4.查找节点
void find(Node* head, int count) {
	if (isList(count) == 0) {//判断是否有链表
		return;
	}
	printf("请输入你要查找的节点的数据：\n");
	int pdata;//要删除的数据
	int count1 = 1;//计数，记节点位置
	int ok=0;//定义一个变量，
	/*因为一个链表可能有多个相同的数据相同的节点，我要把他们都输出出来，所以要遍历全部节点，
	而遍历完节点就会输出没有查找到该节点，所以定义个ok用来避免这种情况*/
	scanf("%d", &pdata);//输入要删除的数据
	Node* pMove = (Node*)malloc(sizeof(Node));//新键一个指针，我们用循环来找目标数据，那就用一个指针来进行移动
	if (pMove == NULL) {//判断动态空间是否分配成功
		return head;
	}
	pMove = head->next;//从第一个节点开始
	while (pMove != NULL) {
		if (pMove->data == pdata) {
			printf("找到了！该节点是链表的第%d个节点\n",count1);
			ok = 1;//让ok=1然后继续遍历
		}
		pMove = pMove->next;//向后移一格
		count1++;//记节点位置
	}
	if (ok == 0) {//这是遍历完后，没有找到节点，所以ok依旧等于0
		printf("找不到，链表中没有该节点！\n");
	}
} 
//5.链表长度
void getLength(Node* head, int count) {
	if (isList(count) == 0) {//判断是否有链表
		return 0;
	}
	int count1 = 0;//记长度
	head = head->next;//头节点不算，从第一个有数据的节点开始
	while (head != NULL) {
		head = head->next;
		count1++;
	}
	printf("链表长度为%d\n", count1);
}
//6.打印链表
void print(Node* head, int count) {
	if (isList(count) == 0) {//判断是否有链表
		return;
	}
	printf("链表为:");
	head=head->next;//从第一个有数据的节点开始
	while (head != NULL) {
		printf("%d ", head->data);
		head=head->next;
	}
	printf("\n");//与菜单隔行
}
//7.清除链表
int rebuild(Node* list,int count) {
	if (isList(count) == 0) {//判断是否有链表
		return count;
	}
	Node* pMove;//新建一个指针方便用来操作
	
	while (list != NULL) {
		pMove = list;
		list = list->next;
		free(pMove);//用循环释放每一个节点空间
	}
	printf("原有链表已清除！\n");
	return 0;//返回0作count值
}
//8.逆置链表
//思路：将原链表的节点用头插法一个一个得重新排列查在一起形成一个新链表，就是倒置后得链表
Node* reverse(Node* head,int count) {
	if (isList(count) == 0) {//判断是否有链表
		return head;
	}
	Node* new = (Node*)malloc(sizeof(Node));//新建一个链表用来作倒置后的链表
	Node* pMove = (Node*)malloc(sizeof(Node));//新建一个节点，用来操作
	if (new == NULL && pMove==NULL) {//判断动态空间是否分配成功
		return head;
	}
	new->next = NULL;//头节点
	head = head->next;//原链表从第一个节点开始
	while (head != NULL) {
		pMove = head;//先将pMove指向原链表的第一个节点
		head = head->next;//然后原链表马上向后移动一格
		pMove->next = new->next;//将pMove指向的节点指向新链表头节点的下一个
		new->next = pMove;//新链表头节点指向pMove
	}
	printf("倒置成功！\n倒置后的");
	print(new,count);//打印一遍链表
	return new;//返回倒置后的链表
}
//9.删除偶数元素节点
Node* deleteO(Node* head, int count) {
	if (isList(count) == 0) {//判断是否有链表
		return head;
	}
	Node* pFront; //新建一个指针，用作代表目标节点的前一个节点
	Node* pNode; //新建一个指针，用作代表目标节点，就是偶数节点
	pFront = head;//从头节点指起
	pNode = head->next;//从第一个节点开始
	while (pNode != NULL) {
		if (pNode->data % 2 == 0) {//偶数
			pFront->next = pNode->next;//将这个这个节点的前一个和后一个连接起来
			free(pNode);//释放偶数节点空间
			deleteO(head, count);//将删除一个偶数节点后的链表进行递归
			/*因为释放了pNode后，还要判断下一个节点，但是不好找到他的下一个节点进行判断，就又得新建一个，
			当时具体怎么想的忘记了*/
		}
		//如果不是目标节点就继续往后
		pFront = pFront->next;
		pNode = pFront->next;
	}
	return head;
}
//10.奇偶分离两链表
void resolve(Node* head, int count) {
	if (isList(count) == 0) {//判断是否有链表
		return;
	}
	Node* J = (Node*)malloc(sizeof(Node));//新建奇数链表
	Node* O = (Node*)malloc(sizeof(Node));//新建偶数链表
	Node* pFront = head;//新建一个移动指针，方便进行操作
	J->next = NULL;
	O->next = NULL;
	if (J == NULL && O == NULL) {//判断动态空间分配是否成功，取消NULL对指针的引用
		return head;
	}
	head = head->next;//head后移，从第一个节点开始
	while (head) {//head不为NULL
		if (head->data % 2 == 0) {//偶数
			pFront->next = head->next;//连接该节点前后节点
			head->next = O->next;//将该节点的指针指向偶数链表的头节点的下一个
			O->next = head;//偶数链表的头节点指向该节点
			/*这一步就像头插法*/
			head = pFront->next;//将head指向下一个
			continue;//结束当前循环，重新判断
		}
		else {//奇数，以下同上
			pFront->next = head->next;
			head->next = J->next;
			J -> next = head;
			head = pFront->next;
			continue;
		};
	}
	//打印两链表
	printf("奇数");
	print(J, count);
	printf("偶数");
	print(O, count);
	printf("原链表为空\n");
	/*因为没有从主函数那边创建链表，所以就不返回了，不想再写了
	但是从主函数那边接受的链表进行了分离，所以原函数会被变成空的*/
}

//11.插入元素仍非递减有序
//没写判断是否是非递减有序的链表的程序，所以只能靠用户自觉输入,如果是一个递减有序链表的话，最后的值就会不对
Node* createList2(Node* head, int count) {
	if (isList(count) == 0) {//判断是否有链表
		return head;
	}
	int intput;//要插入的节点的值
	Node* newNode=(Node*)malloc(sizeof(Node));//要插入的节点
	if (newNode == NULL) {//判断动态空间是否分配成功
		return head;
	}
	Node* pFront;//插入结点的前一节点
	Node* pMove;//代替原链表中被查的节点
	if (head == NULL) {
		printf("原链表为空！\n");
		return head;
	}
	pMove = head->next;
	pFront = head;

	printf("请输入你插入的元素：\n");
	scanf("%d", &intput);
	newNode->data = intput;//将值赋给要插入的节点
	while (pMove) {
		if (newNode->data > pMove->data) {//如果新节点的值大于原链表节点的值，那就将原链表的节点向后
			pMove = pMove->next;
			pFront = pFront->next;
		}
		else {//如果小于等于，就将新节点插到原链表的节点的前一个位置
			pFront->next = newNode;
			newNode->next = pMove;
			print(head, count);
			return head;
		}
	}
}

//12.创建两个单链表，合并成一个
Node* combine(int count) {
	//新建两个链表，作两个递增链表，依旧只有靠用户自觉输入
	Node* L1 = (Node*)malloc(sizeof(Node));
	Node* L2 = (Node*)malloc(sizeof(Node));
	//新建一个链表作归并后的链表：
	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL && L1 == NULL && L2 == NULL) {//判断内存是否分配成功
		return 0;
	}
	Node* n1;//作new的头节点
	Node* p1;//作L1的第一个节点，而后便于操作
	Node* p2;//作L2的第一个节点，而后便于操作

	//三个新链表，头节点都指向NULL
	new->next = NULL;
	L1->next = NULL;
	L2->next = NULL;

	printf("创建第一个链表：\n");
	L1 = endInsert(L1);//创建链表
	printf("创建第二个链表：\n");
	L2 = endInsert(L2);//创建链表
	p1 = L1->next;
	p2 = L2->next;
	n1 = new;
	while (p1 != NULL && p2 != NULL) {//当两个链表有一个排序完就退出
		if (p1->data > p2->data) {
			L2->next = p2->next;
			p2->next = n1->next;//将小的节点的指针指向新链表的下一个
			n1->next = p2;//新链表的下一个 指向上面这个节点
			n1 = n1->next;//新链表的头节点后移一个
			p2 = L2->next;//原链表的指针也后裔一个
		}
		else {//操作原理同上
			L1->next = p1->next;
			p1->next = n1->next;
			n1->next = p1;
			n1 = n1->next;
			p1 = L1->next;
		}
	}
	//上面循环退出后，说明至少有一个链表比较完了，但我们不知道是哪一个链表或者还是两个链表
	//所以再分开循环
	//如果没有比较完，那么就直接将后面的值挨个赋给新链表就行，但是还是需要用户输入的链表是有序的才能输出有序的
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
	print(new, 1);//打印
	return new;//返回新链表

	////将两个递增有序链表合并为一个递减有序链表
	////L1、L2为两个递增有序链表
	//p1 = L1;//先用p1代替L1
	//while (p1->next != NULL) {//这个循环将p1移到L1的最后一个节点上
	//	p1 = p1->next;
	//}
	//p1->next = L2->next;//合并：将L2连接在L1的后面
	//p1 = L1->next;//然后p1回到L1的第一个结点
	//p2 = L1->next;//建一个p2也在L1的第一个结点
	//Node* m = NULL;//定义一个m等于NULL，用于循环条件
	////冒泡排序法：第一次的m为NULL，第二次的m为第一次排序到最后面的值，第三次为第二次的值，.....
	//while (p1 != m) {
	//	while (p1->next != m) {
	//		if (p1->data < p1->next->data) {
	//			int tmp = p1->data;
	//			p1->data = p1->next->data;
	//			p1->next->data = tmp;
	//		}
	//		p1 = p1->next;
	//	}
	//	m = p1;//更新m的值，m始终为上一次排序到最后面的结点，m相当于从最后一个往前走，用来限制循环次数次次减少
	//	p1 = p2;//没排序完一个数，就将p1重新移动到当前的第一个数继续排序
	//}
	//
	//print(L1, 1);
	//return L1;

}
void Max(Node* head) {//这里接收链表
	int max = head->next->data;//将第一个结点的值定义为最大值
	head = head->next;//链表从第一个结点开始
	while (head) {
		if (max < head->data) {//如果碰上比max大的值，就将大的值赋给max
			max = head->data;
		}
		head = head->next;//移动到下一个结点
	}
	printf("最大值是：%d\n", max);
}
