#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"


int main1(){
	system("title 顺序二叉树");
	int chose = 0;
	ElemType elem;
	int index = 0;
	printf("请先输入初始化树值：\n");
	InitTree();
	while (1) {
		Print();
		menu1();
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//1、插入
		case 1:
			printf("请输入要插入的值：");
			scanf("%c", &elem);
			getchar();
			InsertTree(elem);
			break;
			//2、删除
		case 2:
			printf("请输入删除的位置：\n");
			scanf("%d", &index);
			DeleteTree(index);
			break;
			//3、遍历
		case 3:
			VisitTree();
			break;
			//4、关系
		case 4:
			Relation();
			break;
			//5、修改
		case 5:
			printf("请输入要修改的位置：");
			scanf("%d", &index);
			getchar();
			printf("请输入要修改的值：");
			scanf("%c", &elem);
			getchar();
			UpdataTree(index, elem);
			break;
			//0、返回
		case 0:
			system("cls");
			return;
		default:printf("输入错误，请重新输入：\n");
		}
	}
	return 0;
}

void menu1() {
	printf("请输入：\n");
	printf("=======================\n");
	printf("=======顺序二叉树======\n");
	printf("===1、插入   2、删除===\n");
	printf("===3、遍历   4、关系===\n");
	printf("===5、修改   0、返回===\n");
	printf("=======================\n");
}
//初始化
void InitTree() {
	ElemType elem;
	bt[0] = NULL;//从下标为一开始存储
	int i = 1;
	while ((elem = getchar()) != '\n') {
		bt[i] = elem;
		i++;
	}
	btlength = i - 1;
}
//打印
//二叉树性质
void Print() {
	printf("=======================\n");
	int tmp = 2;
	int n = 1;
	//算出n为层数
	while (1) {
		tmp = tmp * 2;
		n++;
		if (tmp > btlength)
			break;
	}
	//m作数组下标
	int m = 2;
	//sum作每一层最大的元素个数
	int sum = 2;
	//打印根节点
	printf("第1层是：%c\n", bt[1]);
	//循环打印其他结点
	for (int i = 2; i <= n; i++) {
		printf("第%d层是：", i);
		for (int j = 0; j < sum; j++) {
			printf("%c ",bt[m++]);
		}
		printf("\n");
		sum *= 2;
	}
	printf("=======================\n");
}
//插入，只能在叶子节点插入
void InsertTree(ElemType elem) {
	bt[++btlength] = elem;
}
//删除，删除后用#代替
void DeleteTree(int index) {
	bt[index] = '#';
}
//结点关系
void Relation() {
	int i = 1;
	printf(" %c 它没有爸爸*_*,左儿子是：%c，右儿子是：%c\n", bt[i], bt[2 * i], bt[2 * i + 1]);
	i++;
	while (i<=btlength) {
		ElemType parent = bt[i / 2];
		ElemType leftchild = bt[2 * i];
		ElemType rightchild = bt[2 * i + 1];
		if (bt[i] == '#') {
			i++;
			continue;
		}
		if (leftchild == 0 && rightchild == 0)
			printf(" %c 的爸爸是：%c，它没有儿子-_-、\n", bt[i],parent);
		else if (rightchild == 0)
			printf(" %c 的爸爸是：%c，左儿子是：%c\n", bt[i], parent, leftchild);
		else
			printf(" %c 的爸爸是：%c，左儿子是：%c，右儿子是：%c\n", bt[i], parent, leftchild, rightchild);
		i++;
	}
}
//修改
void UpdataTree(int index,ElemType elem) {
	bt[index] = elem;
}
//遍历，真难写
void VisitTree() {
	system("cls");
	while (1) {
		printf("===1、前序遍历===\n");
		printf("===2、中序遍历===\n");
		printf("===3、后序遍历===\n");
		printf("===0、退出遍历===\n");
		int chose;
		scanf("%d", &chose);
		switch (chose) {
		case 1:
			printf("前序遍历：没有写太麻烦了……\n");
			break;
		case 2:
			printf("中序遍历：也没有写太麻烦了……\n");
			break;
		case 3:
			printf("后序遍历：还是没有写太麻烦了……\n");
			break;
		case 0:
			system("cls");
			return;
		}
	}
	
}