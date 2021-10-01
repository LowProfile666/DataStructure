#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef int DataType;
typedef struct ShareStack {
	DataType data[MAX];
	int top1;
	int top2;
}SS;
SS sharestack;
SS* s = &sharestack;

//声明函数
void menu();
void InitStack(int chose);
void PrintStack(int chose);
void Push(int chose);
void Pop(int chose);
void GetTop(int chose);

int main(){
	int chose;
	while (1) {
		system("title 共享栈");
		menu();				//菜单
		scanf("%d", &chose);
		switch (chose) {
		case 1:				//初始化但不赋值
			printf("请选择初始化哪个栈：\n1、1栈\n2、2栈\n3、都初始化\n");
			int chose1;
			scanf("%d", &chose1);
			InitStack(chose1);
			break;
		case 2:				//打印栈，都打就是打印这个 数组，初始元素都为0
			printf("打印哪个栈？\n1、1栈\n2、2栈\n3、都打\n");
			int chose2;
			scanf("%d", &chose2); 
			PrintStack(chose2);
			break;
		case 3:				//压栈
			printf("请选择栈：\n1、1栈\n2、2栈\n3、都入\n");
			int chose3;
			scanf("%d", &chose3);
			Push(chose3);
			break;
		case 4:				//出栈
			printf("请选择栈：\n1、1栈\n2、2栈\n3、都出\n");
			int chose4;
			scanf("%d", &chose4);
			Pop(chose4);
			break;
		case 5:				//取栈顶元素但不出战
			printf("请选择栈：\n1、1栈\n2、2栈\n3、都取\n");
			int chose5;
			scanf("%d", &chose5);
			GetTop(chose5);
			break;
		case 0:return;
		default:printf("输入错误，重新输入：\n");
		}
	}
	return 0;
}
//菜单
void menu() {
	printf("--------------\n");
	printf("|共享栈的基操\n");
	printf("|1、初始化栈\n");
	printf("|2、打印栈\n");
	printf("|3、入栈\n");
	printf("|4、出栈\n");
	printf("|5、取栈顶元素\n");
	printf("|0、退出\n");
	printf("--------------\n");
	printf("请选择：\n");
}
//1、初始化栈
void InitStack(int chose) {
	/*只给两个栈的top找到位置，不赋值*/
	switch (chose) {
	case 1:
		s->top1 = -1;		//1栈
		printf("是否继续初始化第二个栈?\n1、是\n2、否\n");
		int chose1;
		scanf("%d", &chose1);
		if (chose1 == 1) {
			chose = 2;
		}
		break;
	case 2:
		s->top2 = MAX;		//2栈
		break;
	case 3:
		s->top1 = -1;
		s->top2 = MAX;
		break;
	default:printf("输入错误！\n");
	}
	printf("初始化完成 ！\n");
}
//2、打印栈
void PrintStack(int chose) {
	/*数组初始都为0*/
	int i;				//i代替top，打印但不出栈
	switch (chose) {
	case 1:
		if (s->top1 == -1) {		//判断空战
			printf("当前空栈！\n");
			return;
		}
		printf("1栈：");
		i = s->top1;		
		while (i != -1) {
			printf("%d ", s->data[i--]);	//1栈top要--，因为压栈的时候top是++的
		}
		printf("\n");
		break;
	case 2:
		if (s->top2 == MAX) {		//判断空战
			printf("当前空栈！\n");
			return;
		}
		i = s->top2;
		printf("2栈：");
		while (i != MAX) {					
			printf("%d ", s->data[i++]);	//2栈top要++，因为他是倒着来，压栈的时候是--
		}
		printf("\n");
		break;
	case 3:
		if (s->top1==-1||s->top2 == MAX) {	
			printf("至少有一空栈！\n");
			return;
		}
		i = 0;
		while (i != MAX) {
			printf("%d ", s->data[i++]);	//权当打印数组
		}
		printf("\n");
		break;
	default:printf("输入错误，返回上一级。\n");
	}
}
//3、入栈
void Push(int chose) {
	if (s->top1 == s->top2) {		//判断是否栈满
		printf("栈满！\n");
		return;
	}

	int num1;	//两栈一起入栈时1栈的值
	int num2;	//两栈一起入栈时2栈的值
	int chose1;	//选择
	int n;

	switch (chose) {
	case 1:
		printf("你想入栈几个元素？\n");
		scanf("%d", &n);
		if (n >= MAX || n <= 0) {
			printf("错误！\n");
			return;
		}
		printf("请输入值：\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num1);
			s->top1++;		//因为初始是-1，所以先++
			s->data[s->top1] = num1;	//赋值
		}
		printf("入栈成功！\n是否打印？：1、是，2、否\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {	//打印
			PrintStack(1);
		}
		break;
	case 2:
		printf("你想入栈几个元素？\n");
		scanf("%d", &n);
		if (n >= MAX || n <= 0) {
			printf("错误！\n");
			return;
		}
		printf("请输入值：\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num2);
			s->top2--;		//因为初始是MAX，所以先--
			s->data[s->top2] = num2;	//赋值
		}
		printf("入栈成功！\n是否打印？：1、是，2、否\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {	//打印
			PrintStack(2);
		}
		break;
	case 3:
		printf("你想每个栈入栈几个元素？\n");
		scanf("%d", &n);
		if (n >= MAX || n <= 0) {
			printf("错误！\n");
			return;
		}
		printf("请输入1栈的值：\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num1);
			s->top1++;		//因为初始是-1，所以先++
			s->data[s->top1] = num1;	//赋值
		}
		printf("请输入2栈的值：\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &num2);
			s->top2--;		//因为初始是MAX，所以先--
			s->data[s->top2] = num2;	//赋值
		}
		printf("入栈成功！\n是否打印？：1、是，2、否\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {	//打印
			PrintStack(3);
		}
		break;
	default:printf("输入错误！\n");
	}
}
//4、出栈
void Pop(int chose) {
	int chose1;
	switch (chose) {
	case 1:
		if (s->top1 == -1) {
			printf("当前空栈！\n");
			return;
		}
		s->data[s->top1] = 0;	//将栈顶元素变为0，因为数组元素初始都为0，相当于删除了这个栈顶元素
		s->top1--;		//出栈top1--
		printf("出栈成功！\n是否打印？：1、是，2、否\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {
			PrintStack(1);
		}
		break;
	case 2:
		if (s->top2 == MAX) {
			printf("当前空栈！\n");
			return;
		}
		s->data[s->top2] = 0;
		s->top2++;		//出栈top2++
		printf("出栈成功！\n是否打印？：1、是，2、否\n");
		scanf("%d", &chose1);
		if (chose1 == 1) {
			PrintStack(2);
		}
		break;  
	case 3:
		if (s->top1 == -1 || s->top2 == MAX) {
			printf("至少有一空栈！\n");
			return;
		}
		s->data[s->top1] = 0;
		s->top1--;
		s->data[s->top2] = 0;
		s->top2++;
		break;
	default:printf("输入错误！\n");
	}
	printf("出栈成功!\n");
}
//5、求栈顶元素
void GetTop(int chose) {
	switch (chose) {
	case 1:
		if (s->top1 == -1) {
			printf("当前空栈！\n");
			return;
		}
		printf("1栈的栈顶元素是：%d\n", s->data[s->top1]);
		break;
	case 2:
		if (s->top2 == MAX) {
			printf("当前空栈！\n");
			return;
		}
		printf("2栈的栈顶元素是：%d\n", s->data[s->top2]);
		break;
	case 3:
		if (s->top1==-1||s->top2 == MAX) {
			printf("至少有一空栈！\n");
			return;
		}
		printf("1栈的栈顶元素是：%d\n", s->data[s->top1 ]);
		printf("2栈的栈顶元素是：%d\n", s->data[s->top2 ]);
		break;
	default:printf("输入错误！\n");
	}
}