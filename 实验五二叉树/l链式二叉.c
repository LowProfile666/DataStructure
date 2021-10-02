#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"


int main2(){
	system("title 链式二叉树");
	printf("请先用广义表的形式初始化树：\n如：A(B(D,E),C(F,G)):\n");
	InitLtree();													//初始化
	LTree Lt1 = Lt;													//辅助结点，用来打印
	int chose = 0;													//选择值
	int i = 1;														//遍历操作选择的循环条件
	ElemType elem1,elem2;											//两个辅助变量
	while (1) {
		printf("=======================\n当前树的广义表模式：\n");
		PrintLtree(Lt1);											//广义表的形式输出
		printf("\n=======================\n");
		menu2();
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//插入
		case 1:
			printf("请输入想插入的那个位置的前一个结点值：");
			scanf("%c", &elem1);
			getchar();												//清除'\n'
			printf("请输入要插入的值：");
			scanf("%c", &elem2);
			InsertNode(elem1, elem2);								//插入
			break;
			//删除
		case 2:
			printf("请输入要删除的值：");
			scanf("%c", &elem1);
			DeleteNode(elem1);										//删除
			break;
			//遍历
		case 3:
			system("cls");
			printf("=======================\n当前树的广义表模式：\n");
			PrintLtree(Lt1);
			printf("\n=======================\n");
			while (i) {
				printf("===1、前序遍历===\n");
				printf("===2、中序遍历===\n");
				printf("===3、后序遍历===\n");
				printf("===0、退出遍历===\n");
				scanf("%d", &chose);
				switch (chose) {
				case 1:PreOrder(Lt1); printf("\n"); break;			//前序遍历
				case 2:InOrder(Lt1); printf("\n"); break;			//中序遍历
				case 3:PostOrder(Lt1); printf("\n"); break;			//后续遍历
				default:i = 0; system("cls");
				}
			}
			break;
			//儿子关系
		case 4:
			printf("请输入要查看的值：");
			scanf("%c", &elem1);
			LTreeRelation(elem1);									//儿子关系
			break;
			//修改
		case 5:
			printf("请输入被修改的值：");
			scanf("%c", &elem1);
			getchar();
			printf("请输入修改的值：");
			scanf("%c", &elem2);
			LTreeUpdata(elem1,elem2);								//修改
			break;
			//返回
		case 0:
			system("cls");
			return;
		default:printf("输入错误请重新输入：\n");
		}
	}
	return 0;
}
void menu2() {
	printf("请输入：\n");
	printf("=======================\n");
	printf("=======链式二叉树======\n");
	printf("===1、插入   2、删除===\n");
	printf("===3、遍历   4、关系===\n");
	printf("===5、修改   0、返回===\n");
	printf("=======================\n");
}
//用广义表形式初始化树
void InitLtree() {
	int k = 0;					//标志，为1代表左儿子，为2代表右儿子
	int top = -1;				//栈顶下标或者说数组下标
	LTree stack[MAXSIZE];		//用一个数组来作栈或者说用来暂时存放根节点，方便连接其儿子结点
	LTree tmp = NULL;			//tmp是树结点
	Lt = NULL;					//树的初始化
	char ch;					//用来接受广义表的每一个字符
	while ((ch = getchar()) != '\n') {	//换行说明输入完毕，循环也退出
		switch (ch) {
			//左括号说明可能有左儿子存在，所以要先将当前的父亲结点存在数组里面，方便他的儿子找他
		case '(':
			stack[++top] = tmp;
			k = 1;
			break;
			//逗号说明必有右儿子存在，所以将k变为2
		case ',':
			k = 2;
			break;
			//右括号说明当前的父亲节点的儿子输入完毕了，因为这个父亲结点可能还有父亲结点，所以下标往后退1，返回到上一个父亲结点
		case ')':
			top--;
			break;
			//当是字符时，就给tmp分配空间、赋值，然后按照k给他们找爸爸
		default:
			tmp = (LTree)malloc(sizeof(LTree));
			tmp->data = ch;
			tmp->left = tmp->right = NULL;
			//这是整颗树的根节点
			if (Lt == NULL)
				Lt = tmp;
			else {
				switch (k) {
					//当前父亲结点的左儿子
				case 1:stack[top]->left = tmp;
					break;
					//当前父亲结点的右儿子
				case 2:stack[top]->right = tmp;
					break;
				}
			}
		}
	}
}
//用广义表形式输出树
void PrintLtree(LTree Lt1) {
	int k = 0;						//k作一个标志
	if (Lt1)
		printf("%c", Lt1->data);
	if (Lt1->left) {
		k = 1;						//k=1表示有左儿子结点存在，防止后面右括号的输出少一个
		printf("(");
		PrintLtree(Lt1->left);
	}
	if (Lt1->right) {
		printf(",");
		PrintLtree(Lt1->right);
		printf(")");
	}
	//递归真神奇
	else if(k==1){
		printf(")");
	}
	/*如果没有k的话，A(B,C(D,E))的最后可能会只输出一个右括号*/
}
//查找指定元素的结点
LTree FindNode(ElemType elem) {
	LTree Lt1 = Lt;						//代替树的根节点操作
	LTree arr[MAXSIZE];					//用一个数组存根节点
	int top = -1;						
	int k = 0;							//用作标志，
	while (1) {
		if (Lt1->left || Lt1->right) {	//存根节点
			arr[++top] = Lt1;
		}
		if (Lt1->data == elem)
			return Lt1;
		//查找当前根节点的左儿子
		else if (Lt1->left) {
			Lt1 = Lt1->left;
			if (Lt1->data == elem)
				return Lt1;
		}
		Lt1 = arr[top];					//查完左儿子，指针还到原来的根节点
		//查找当前根节点的右儿子
		 if (Lt1->right) {
			Lt1 = Lt1->right;
			if (Lt1->data == elem)
				return Lt1;
		}
		Lt1 = arr[top];					//查完右儿子，指针还到原来的根节点
		//k：1代表遍历了左子树，2代表遍历了右子树
		if (k != 1) {
			//如果当前根节点的左儿子的左儿子或者左儿子的右儿子不为空，那么根节点指针变为他的左儿子，回到循环继续查找
			if (Lt1->left->left || Lt1->left->right) {	
				Lt1 = arr[top]->left;
				k = 1;
				continue;				//跳过后续步骤
			}
		}
		//k：1代表遍历了左子树，2代表遍历了右子树
		else if (k != 2) {
			//如果右儿子是空，那么根节点指针就变成左儿子继续
			if (Lt1->right == NULL) {
				Lt1 = arr[top]->left;
				k = 2;
				continue;
			}
			//如果当前根节点的右儿子的左儿子或者右儿子的右儿子不为空，那么根节点指针变为他的右儿子，回到循环继续查找
			if (Lt1->right->left || Lt1->right->right) {
				Lt1 = arr[top]->right;
				k = 2;
				continue;
			}
			//如果根节点的右儿子不空但是右儿子的儿子是空，说明，这ge子树遍历完，把k变为2
			k = 2;
		}
	}
}
//插入
/*插入的结点是作左儿子*/
void InsertNode(ElemType elem1, ElemType elem2) {
	//查找到插入的位置
	LTree Lt1 = FindNode(elem1);
	//插入操作
	LTree new = (LTree)malloc(sizeof(LTree));
	new->data = elem2;
	new->left = Lt1->left;
	new->right = Lt1->right;
	Lt1->left = new;
	Lt1->right = NULL;
}
//删除
void DeleteNode(ElemType elem) {
	//找到删除的点
	LTree LT1 = FindNode(elem);
	LT1->data = NULL;
	LT1->left = LT1->right = NULL;
}
//递归的遍历
//前序遍历
void PreOrder(LTree Lt1) {
	if (Lt1 == NULL)
		return;
	printf("%c ", Lt1->data);
	PreOrder(Lt1->left);
	PreOrder(Lt1->right);
}
//中序遍历
void InOrder(LTree Lt1) {
	if (Lt1 == NULL)
		return;
	InOrder(Lt1->left);
	printf("%c ", Lt1->data);
	InOrder(Lt1->right);
}
//非递归中序遍历
/*如果连续两个结点没有右儿子就会出错*/
//void InOrder(LTree Lt1) {
//	LTree stack[MAXSIZE];				//用数组存根节点
//	int top = -1;						//数组初始下标
//	while (Lt1) {
//		while (Lt1->left) {				//先遍历到左子树的叶子节点
//			stack[++top] = Lt1;
//			Lt1 = Lt1->left;
//		}
//		printf("%c ", Lt1->data);		//打印这个结点
//		if (top == -1) {				//当top=-1就说明最后一个根节点的儿子都打印完了，退出循环
//			break;
//		}
//		printf("%c ", stack[top]->data);//打印当前根节点
//		if (stack[top]->right)			//如果当前根结点有右儿子的话
//			Lt1 = stack[top--]->right;	//指针变向当前结点的右儿子，top--表示 回到上一个根节点
//		else
//			Lt1 = stack[--top]->right;	//如果没有，就变为上一个根节点的右儿子
//	}
//}
//后续遍历
void PostOrder(LTree Lt1) {
	if (Lt1 == NULL)
		return;
	PostOrder(Lt1->left);
	PostOrder(Lt1->right);
	printf("%c ", Lt1->data);
}
//儿子关系，他爸爸的太难写了
/*如果删除了一个结点，应该把该节点的上一个结点的儿子置为空，但是不好操作没写，所以删除一个结点后来查看其父节点的关系时会出错*/
void LTreeRelation(ElemType elem) {
	LTree Lt1 = FindNode(elem);
	if (!Lt1->left && !Lt1->right) {
		printf(" %c 他没有儿子\n", Lt1->data);
		return;
	}	
	if(Lt1->left->data&&Lt1->right->data)
		printf(" %c 的左儿子是：%c，右儿子是%c\n",Lt1->data,Lt1->left->data,Lt1->right->data);
	if(Lt1->left->data&&!Lt1->right->data)
		printf(" %c 的左儿子是：%c，它没有右儿子\n", Lt1->data, Lt1->left->data);
	if(!Lt1->left->data&&Lt1->right->data)
		printf(" %c 的右儿子是：%c，它没有左儿子\n", Lt1->data, Lt1->right->data);
}
//修改
void LTreeUpdata(ElemType elem1,ElemType elem2) {
	//找到要修改的点
	LTree Lt1 = FindNode(elem1);
	Lt1->data = elem2;
}
