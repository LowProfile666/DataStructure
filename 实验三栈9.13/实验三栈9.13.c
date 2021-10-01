#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


/*1．采用顺序存储实现栈的初始化、入栈、出栈操作。
2．采用链式存储实现栈的初始化、入栈、出栈操作。
3．写一个程序，将输入的十进制数据M 转换为八进制数据M8，将其调试通过。
在此基础上修改程序，实现十进制数据M 向N 进制（2或8或16）的转换。
（1）采用顺序存储结构实现栈。
（2）采用链表结构实现栈。*/

#define MaxSize 100	//栈的最大存储值
typedef int ElemType;	
typedef struct SqStack {	//顺序栈
	ElemType data[MaxSize];//数据
	int top;	//栈顶指针
}Sq;
Sq s;	

typedef struct LinkNode {	//链表
	ElemType data;
	struct LinkNode* next;
}Lnode;
typedef struct LinkStack {	//链栈
	Lnode* top;
}Ls;
Ls L;
Ls* l = &L;
int count = 0;	//用来计数，判断栈是否创建过或者是否初始化过，避免二次创建或初始化

//函数声明
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
	system("title 栈的操作");
	int chose = 0;
	while (1) {
		menu();	//菜单
		scanf("%d", &chose);	//选择
		switch (chose) {
		case 1:
			system("cls");	//清屏
			menu1();	//进入顺序栈的菜单
			count = 0;	//这里主要是为了在建立完顺序栈后退出重置，以至于链栈能正常建立
			break;	
		case 2:
			system("cls");	//同上
			menu2();	//进入链栈的菜单
			count = 0;	//退出链栈的菜单后，重置
			break;
		case 3:
			TransFrom(1);	//利用栈来转换进制
			break;
		case 0: return;	//退出
		default:printf("输入错误，重新输入：\n");
		}
	}
	return 0;
}
//初始菜单
void menu() {
	printf("··········\n");
	printf("·   栈的操作     ·\n");
	printf("·   1、顺序栈    ·\n");
	printf("·   2、链栈      ·\n");
	printf("·   3、进制转换  ·\n");
	printf("·   0、退出      ·\n");
	printf("··········\n");
	printf("请选择：\n");
}

//顺序栈菜单
void menu1() {
	int n;
	while (1) {
		printf("+++++++++++++++++\n");
		printf("+ 顺序栈的操作  +\n");
		/*因为两个菜单的主要内容都一样，只有菜单头不同，所以单打一份菜单头*/
		menu3();	//显示主菜单
		scanf("%d", &n);	//选择功能
		if (n == 0) {		//选择0退出
			system("cls");	//清屏
			return;
		}
		F(1,n);	//菜单选择项的功能的调用，这里的1代表着 顺序栈
	}
}
//链表栈菜单
void menu2() {
	int n;
	while (1) {
		printf("+++++++++++++++++\n");
		printf("+ 链栈的操作    +\n");
		menu3();	//显示主菜单
		scanf("%d", &n);	//输入选择
		if (n == 0) {		//选择0退出
			system("cls");	//清屏
			return;
		}
		F(2,n);	//菜单选择项的功能的调用，这里的2代表着 链栈
	}
}
//主菜单
void menu3() {
	printf("+ 1、创建栈     +\n");
	printf("+ 2、初始化     +\n");
	printf("+ 3、打印栈     +\n");
	printf("+ 4、进栈       +\n");
	printf("+ 5、出栈       +\n");
	printf("+ 6、取栈顶元素 +\n");
	printf("+ 7、清空栈     +\n");
	printf("+ 0、返回上一级 +\n");
	printf("+++++++++++++++++\n");
	printf("请选择：\n");
}
//菜单选择项的功能的调用
/*因为两个栈方法我都写在一个函数里，所有定义个i变量来区分执行哪一个的操作*/
void F(int i,int n) {	//i是表示1，2的，就是表示链栈还是顺序栈，
	if (i ==  1) {
		switch (n) {	//全程序的1都是代表顺序栈
		case 1:CreateStrack(1); break;	//创建
		case 2:InitStrack(1); break;	//初始化
		case 3:PrintStack(1); break;	//打印
		case 4:	
			if (F1(count) == 0) {
				break;
			}
			printf("请输入要放入栈的元素：\n");
			int n;
			scanf("%d", &n); 
			Push(1,n);break;	//压栈，n是要放进去的元素
			/*因为进制转换需要用到Push函数，但又不需要前面这些话语，
			所以这些语句写在调用函数前*/
		case 5:Pop(1);break;	//出栈
		case 6:GetTop(1); break;	//求栈顶元素
		case 7:Delte(1); break;	//清空栈
		default:  printf("输入错误!\n"); break;
		}
		return;
	}
	if (i == 2) {	//这里是代表着链表，下面均与上同
		/*两个链表不同的地方只在函数内部和该调用函数处*/
		switch (n) {
		case 1:CreateStrack(2); break;
		case 2:InitStrack(2); break;
		case 3:PrintStack(2); break;
		case 4:
			if (F1(count) == 0) {
				break;
			}
			printf("请输入要放入栈的元素：\n");
			int n;
			scanf("%d", &n);
			Push(2,n);
			break;
		case 5:Pop(2); break;
		case 6:GetTop(2); break;
		case 7:Delte(2); break;
		default:  printf("输入错误!\n"); break;
		}
		return;
	}
}
//判断，用在创建的函数里，判断是否二次创建
int Judge(int i) {
	if (i == 1) {
		if (s.top != -1) {	//初始的顺序栈顶为-1，如果不为说明是一个非空顺序栈
			printf("已创建过顺序栈！\n");
			return 0;
		}
	}
	if (i == 2) {
		if (l->top != NULL) {	//初始的链栈顶为NULL，如果不为说明是一个非空链栈
			printf("已创建过链栈！\n");
			return 0;
		}
	}
	return 1;
}
//判断，以count的值来判断是否创建或者初始化，防止没有创建或初始化就能进行其他操作
int F1(int count) {
	if (count == 0) {
		printf("还未创建栈！\n");
		return 0;
	}
	if (count == 1) {
		printf("该栈还未初始化！\n");
		return 0;
	}
	return 1;
}
//3.转换进制
void TransFrom(int i) {
	printf("请输入你要转换的值：\n");
	int n;
	scanf("%d", &n);
	getchar();	//接收缓冲区
	printf("请选择要转换为几进制：\na.八进制\nb.十六进制\nc.二进制\n");
	char m;
	scanf("%c", &m);
	getchar();	//接收缓冲区
	switch (m) {
	case 'a':printf("%d转换为八进制是：%o\n", n, n); return;
	case 'b':printf("%d转换为十六进制是：%x\n", n, n); return;
	case 'c':transfrom(n); return;	//调用二进制转换函数
	}
}
/*因为十进制转二进制不能直接用格式输出，所以另写一格函数*/
//十进制转换为二进制
void transfrom(int n) {	//这个n是传过来要进行转换的值
	int m = n;	//用个m代替n
	while (m > 0) {
		Push(1, m % 2);	//1代表用顺序栈的压栈方法来实现，除二求余再压栈，
		m = m / 2;
	}
	count = 2;	//因为前面设置了，不整个2代表已付初值的话，不让你压栈操作
	printf("%d转换为二进制是：\n", n);
	PrintStack(1);	//输出栈里的内容，也就是转换后的二进制数
	count = 0;	//进行完这个操作，又将count=0，方便后面进行创建站
	s.top = 0;	//因为用的是顺序栈的压栈方法，所以用完都将他回到原来的样子，不要影响后面的操作
}

//1.创建栈
void CreateStrack(int i) {
	if (i == 1) {	//创建顺序栈
		if(Judge(count)==0)	//判断是否已创建栈
			return;
		s.top = -1;	//创建栈
	}
	if (i == 2) {	//创建链栈
		if (Judge(count) == 0)	//判断是否已创建栈
			return;
		l->top = NULL;	//创建站
	}
	count=1;	//创建成功后，count变成1，说明已有栈存在
	printf("创建成功！\n");
}
//2.初始化栈
void InitStrack(int i) {
	if (count == 0) {
		printf("还未创建栈！\n");
		return;
	}
	if (count == 2) {
		printf("该栈已经初始化！\n");
		return;
	}
	printf("请输入值（以-1结束）：\n");
	while (1) {
		if (i == 1) {
			/*顺序栈的栈顶指针是指向栈顶元素的上面的，所以类似下标*/
			s.top++;	//初始s.top为-1，需要先++才能赋值，因为s.top相当于数组下标
			scanf("%d", &s.data[s.top]);	//赋值
 			if (s.data[s.top] == -1) {	//以-1结束
				getchar();	//读取掉-1，避免-1被存入
				count = 2;	//初始化完成，count变为2，代表已初始化
				printf("初始化成功！\n");
				return;
			}
		}
		if (i == 2) {
			Lnode* new = (Lnode*)malloc(sizeof(Lnode));	//新建一节点
			if (new == NULL) {	//取消NULL对new的引用
				return;
			}
			scanf("%d", &new->data);	//赋值
			if (new->data == -1) {	//退出条件
				getchar();		//读取掉-1
				count = 2;	//创建完成
				printf("初始化成功！\n");
				return;
			}
			/*链栈的栈顶指针是指向栈顶那一个元素的*/
			new->next = l->top;	//类似头插法，将新的结点放在l->top的位置
			l->top= new;	//然后，栈顶指针指向这个新的值
		}
	}
}
//3.打印栈
void PrintStack(int i) {
	if (i == 1) {
		if (F1(count) == 0) {	//判断是否创建并初始化了栈
			return;
		}
		int t = s.top - 1;	//用t代替栈顶指针来进行循环，
		/*如果直接用栈顶指针的话，因为指针大小需要每次减少，
		所以等到最后就相当于将所有元素都出栈了*/
		while (t != -1) {	//-1时代表到了栈底，已经遍历了所有元素 
			printf("%d ", s.data[t]);
			t--;	//因为是栈顶指针，所以需要--
		}
	}
	if (i == 2) {
		if (F1(count) == 0) {	//判断是否创建并初始化了栈
			return;
		}
		Lnode* m= l->top;	//新建一个栈顶指针用来进行移动操作
		while (m != NULL) {	//=NULL代表遍历完
			printf("%d ", m->data);
			m = m->next;	//同链表的差不多
		}
	}
	printf("\n");	//换个行
}
//4.压栈
void Push(int i,int n) {	//i是栈的类别，n是要入栈的元素
	if (i == 1) {
		s.data[s.top] = n;	//直接将n赋给栈顶指针的位置
		s.top++;	//然后栈顶指针++依旧指向栈顶元素的上面
	}
	if (i == 2) {
		Lnode* new = (Lnode*)malloc(sizeof(Lnode));	//新建结点 
		if (new == NULL) {	//取消NULL对new的引用
			return;
		}
		new->data = n;	//将n赋给结点
		new->next = l->top;	//然后类似头插法，新节点连上top
		l->top = new;	//top在上移一个
	}
}
//5.出栈
void Pop(int i) {
	if (i == 1) {
		if (F1(count) == 0) {	//判断是否创建并初始化了栈
			return;
		}
		s.top--;	//就将栈顶指针下降一格
	}
	if (i == 2) {
		if (F1(count) == 0) {
			return;
		}
		l->top = l->top->next;	//将栈顶指针移到下一个
	}
	printf("出栈成功！\n");
}
//6.求栈顶元素
void GetTop(int i) {
	if (i == 1) {
		if (F1(count) == 0) {
			return;
		}
		printf("栈顶元素是：%d\n", s.data[s.top - 1]);	//因为顺序栈的top是栈顶元素的上面，所以要减一
	}
	if (i == 2) {
		if (F1(count) == 0) {
			return;
		}
		printf("栈顶元素是：%d\n", l->top->data);	//链栈的栈顶指针就是指向的栈顶元素
	}
}
//7.清空栈
/*就是将栈顶指针移到最下面去*/
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
		Lnode* n = (Lnode*)malloc(sizeof(Lnode));//这里新建一个用来方便释放空间
		n=l->top;	
		while (l->top != NULL) {
			n = n->next;	//先将n指向下一个，起到为l->top指路的作用
			free(l->top);	//然后释放空间
			l->top = n;	//然后将指针移动下一个
		}
	}
	count = 0;	//清空后，就将count=0，代表是没有栈存在的
	printf("清空完成！\n");
}


