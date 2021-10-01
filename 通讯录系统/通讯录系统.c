#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*通讯录管理
问题描述：利用线性表实现一个通讯录管理。
要求：
1）实现通信录的建立、增加、删除、修改、查询等功能 ；
2） 能够实现简单的菜单交互，即可以根据用户输入的命令，选择不同的操作；
3） 能够保存每次更新的数据；
4） 编写main()函数测试操作的正确性。*/

typedef struct people {//定义联系人结构体
	char name[20];//名字
	char tel[20];//电话
}P;
P num[100];//定义结构体数组，可以存100个联系人的信息
int i=0;//用于作联系人的序号，或者可以判断联系人个数是否到达了最大值

//函数声明
void menu();
void add();
void del();
void find();
void edit();
void print();

int main() {
	system("title 通讯录管理系统");
	int in;//选择值
	while (1) {
		menu();//菜单
		scanf("%d", &in);
		switch (in) {
		case 0:return;			//退出系统
		case 1:add(); break;	//添加联系人
		case 2:del(); break;	//删除联系人
		case 3:find(); break;	//查找联系人
		case 4:edit(); break;	//编辑联系人
		case 5:print(); break;	//打印通讯录
		default:printf("输入错误，请重新输入：\n"); break;
		}
	}
	return 0;
}
//菜单
void menu() {
	printf("================================\n");
	printf("\t通讯录管理系统\n");
	printf("\t 0.退出通讯录\n");
	printf("\t 1.添加联系人\n");
	printf("\t 2.删除联系人\n");
	printf("\t 3.查找联系人\n");
	printf("\t 4.修改联系人\n");
	printf("\t 5.查看通讯录\n");
	printf("================================\n");
	printf("请选择：");
}
//与用户交互、显示输出的话语
void Printf(double m) {
	if (m == 0) printf("该通讯录已经装满了！\n");
	if (m == 0.1) printf("当前没有联系人！\n");
	if (m == 1.1) printf("请输入联系人的姓名：\n");
	if (m == 1.2) printf("请输入联系人的电话：\n");
	if (m == 1.3) printf("添加成功！是否继续添加 Y/N：\n");
	if (m == 2.1) printf("请输入要删除的联系人姓名：\n");
	if (m == 2.2) printf("确认删除以下信息？\n");
	if (m == 2.3) printf("1.确认 2.返回\n");
	if (m == 2.4) printf("删除成功！\n");
	if (m == 2.5) printf("没有找到该联系人！\n");
	if (m == 3.1) printf("请输入要查找的联系人姓名：\n");
	if (m == 3.2) printf("查找成功！\n");
	if (m == 3.3) printf("经查无此人！\n");
	if (m == 4.1) printf("请输入要修改的联系人姓名：\n");
	if (m == 4.2) printf("当前联系人信息为：\n");
	if (m == 4.3) printf("是否确认修改？Y/N：\n");
	if (m == 4.4) printf("请输入新的姓名：\n");
	if (m == 4.5) printf("请输入新的电话：\n");
	if (m == 4.6) printf("修改成功！当前联系人信息为：\n");
	if (m == 4.7) printf("没有该联系人！\n");
}
//判断字符串是否相等，用于查询、删除、编辑等操作
int my_strcmp(char name[],int j) {	//接收输入的名字与该结构体数组下标
	char* p1 = name;				//strcmp参数是指针，所以将他们用指针表示
	char* p2 = (char*)&num[j];
	if (strcmp(p1, p2) == 0) {		//strcmp相等就返回0
		return 0;
	}
	return 1;
}
//打印单个人的信息，用于删除和编辑操作
void print2(int j) {
	printf("序号\t姓名\t\t电话\n");
	printf("%2d\t%s\t\t%s\n", (j+1),num[j].name, num[j].tel);
}
//1.增加联系人
void add() {
	if (i > 100) {							//如果通讯录满了就不能在添加了
		Printf(0);							//警告提示
		return;
	}
	char chose;								//用于判断是否要继续添加
	while (1) {
		Printf(1.1);						//提示输入名字
		scanf("%s", &num[i].name);
		getchar();							//清除缓存区
		Printf(1.2);						//提示输入电话
		scanf("%s", &num[i].tel);
		getchar();							//清除缓冲区
		i++;								//添加一个联系人就加一
		Printf(1.3);						//提示是否继续添加
		scanf("%c", &chose);
		if (chose == 'y' || chose == 'Y') {	//选择y或Y就继续添加，其他值退出
			continue;						//结束本次循环，回到判断条件处
		}
		return;
	}
}
//删除的详细操作，将该联系人的信息变成后一个联系人，就算删除成功
void del2(int j) {
		for (j; j < i; j++) {
			num[j] = num[j + 1];
	}
}
//2.删除联系人
void del() {
	if (i == 0) {							//判断当前是否有联系人
		Printf(0.1);
		return;
	}
	char name[20];							//用来接收输入的要删除的联系人姓名
	int chose=0;							//用作判断
	Printf(2.1);							//删除的姓名
	scanf("%s", name);
	for (int j = 0; j < i; j++) {
		if (my_strcmp(name,j) == 0) {		//在数组里查找与输入名相同的元素
			Printf(2.2);					//提示当前联系人信息
			print2(j);						//显示当前的联系人信息
			Printf(2.3);					//提示是否确认删除
			scanf("%d", &chose);
			if (chose == 1) {
				del2(j);					//进行删除操作
				Printf(2.4);				//提示删除成功
				i--;						//联系人的个数要减一
				return;						
			}
		}
	}
	Printf(2.5);							//没有找到目标，提示没有此人
	return;
}
//3.查找
void find() {
	if (i == 0) {							//判断当前是否有联系人
		Printf(0.1);
		return;
	}
	Printf(3.1);							//提示输入查找姓名
	char name[20];							//接收姓名
	scanf("%s", name);
	for (int j = 0; j < i; j++) {
		if (my_strcmp(name,j) == 0) {		//查找与输入姓名相同的元素
			Printf(3.2);					//提示找到了目标联系人
			print2(j);						//显示该联系人的信息
			return;
		}
	}
	Printf(3.3);							//提示没有找到联系人
}
//4.修改
void edit() {
	if (i == 0) {							//判断当前是否有联系人
		Printf(0.1);
		return;
	}
	Printf(4.1);							//输入编辑姓名
	char name[20];							//接收姓名
	char chose;								//用于选择
	scanf("%s", name);
	getchar();								//清除缓存区
	for (int j = 0; j < i; j++) {
		if (my_strcmp(name, j) == 0) {		//查找与输入姓名相同的元素
			Printf(4.2);					//提示找到此人
			print2(j);						//输入此人信息
			Printf(4.3);					//提示是否确认编辑
			scanf("%c", &chose);			//输入选择
			if (chose == 'y' || chose == 'Y') {
				Printf(4.4);				//提示输入新姓名
				scanf("%s", &num[j].name);	//输入新姓名
				Printf(4.5);				//提示输入新电话
				scanf("%s", &num[j].tel);	//输入新电话
				Printf(4.6);				//提示编辑成功
				print2(j);					//显示新联系人信息
				return;
			}
		}
	}
	Printf(4.7);							//提示没有此人
}
//5.显示通讯录
void print() {
	if (i == 0) {							//判断当前是否有联系人
		Printf(0.1);
		return;
	}
	int j = 0;								//作数组下标，从第一个元素开始输出
	printf("序号\t姓名\t\t电话\n");
	printf("----\t----\t\t----\n");
	for (j = 0; j < i; j++) {
		printf("%2d\t%s\t\t%s\n", (j + 1), num[j].name, num[j].tel);
	}
}

