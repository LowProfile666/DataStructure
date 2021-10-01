#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef struct LinkString {
	char data;
	struct LinkString* next;
}String;

//函数声明
String* InitString(String* s);
void menu();
String* ConcattString(String* s,String* str);
void PrintString(String* str);
int my_strlen(String* str);
String* InsertString(String* s, String* str, int index);
String* DeleteString(String* s, String* str);
int my_strstr(String* s, String* str);
int my_strcmp(String* s, String* str);
String* my_strcpy(String* s, String* str);
String* ReplaceString(String* s, String* str,int index);

int main() {
	system("title 链串");
	//创建串
	String LS;
	String* s=&LS;

	printf("请先初始化一个串：");
	s=InitString(s);
	printf("初始化成功！\n");
	//创建一个辅助串，用来插入、比较、替换等需要两个串的操作
	String* str = (String*)malloc(sizeof(String));
	//创建几个变量，用来作选择值、位置值、函数返回值
	int chose = 0;
	int index = 0;
	int num = 0;
	while (1) {
		printf("--当前串为：");
		PrintString(s);				//打印串
		printf("\n");
		printf("--当前串长：%d\n",my_strlen(s));
		menu();						//菜单
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//串插入
		case 1:
			printf("请输入要插入的串：");
			str = InitString(str);			//先初始化辅助串作要插入的串
			printf("请输入要插入的位置：");
			scanf("%d", &index);			//插入的位置，第一个结点的位置是1
			s = InsertString(s, str,index-1);
			printf("插入成功！\n----------------------\n");
			break;
			//串删除
		case 2:printf("请输入要删除的串：");
			str = InitString(str);			//先初始化辅助串作要删除的串
			if (my_strstr(s, str) == -1) {	//先判断是否是子串，不是就不嫩删除
				printf("不是子串无法删除！\n----------------------\n");
				break;
			}
			s = DeleteString(s, str);
			printf("删除成功！\n----------------------\n");
			break;
			//串连接
		case 3:
			printf("请输入要连接的串：");
			str = InitString(str);			//先初始化辅助串作要连接的串
			s = ConcattString(s, str);
			printf("连接成功！\n----------------------\n");
			break;
			//串比较
		case 4:
			printf("请输入要比较的串：");
			str = InitString(str);			//先初始化辅助串作要比较的串
			num = my_strcmp(s, str);		//相等、大于、小于都会返回值
			PrintString(s);					//打印源串
			if (num == 0) {
				printf("等于");
			}
			if (num > 0) {
				printf("大于");
			}
			if (num < 0) {
				printf("小于");
			}
			PrintString(str);				//打印比较的串
			printf("\n----------------------\n");
			break;
			//判子串
		case 5:
			printf("请输入要判断的串：");
			str = InitString(str);			//先初始化辅助串作要判断的串
			num = my_strstr(s, str);		//是不是子串都会返回值
			PrintString(str);				//打印源串
			if (num == 0)
				printf("是");
			else
				printf("不是");
			PrintString(s);					//打印判断的串
			printf("的子串。\n----------------------\n");
			break;
			//串拷贝
		case 6:
			printf("请输入要拷贝的串：");
			str = InitString(str);			//先初始化辅助串作要拷贝的串
			s = my_strcpy(s, str);
			printf("拷贝成功！\n----------------------\n");
			break;
			//串替换
		case 7:
			printf("请输入要替换的串：");
			str = InitString(str);			//先初始化辅助串作要替换的串
			printf("请输入替换的位置：");
			scanf("%d", &index);
			s = ReplaceString(s, str,index);
			printf("替换成功！\n----------------------\n");
			break;
			//退出
		case 0:return;
		default:printf("输入错误！重新输入：\n");
		}
	}
	return 0;
}
void menu() {
	printf("----------------------\n");
	printf("请选择：\n");
	printf("**********************\n");
	printf("****链*串*的*操*作****\n");
	printf("**1、插入    2、删除**\n");
	printf("**3、连接    4、比较**\n");
	printf("**5、子串    6、拷贝**\n");
	printf("**7、替换    0、退出**\n");
	printf("**********************\n");
}
//初始化
String* InitString(String* s) {
	s = (String*)malloc(sizeof(String));
	s->next = NULL;
	//用一个str指针代替操作
	String* str = s;
	//读到换行符时退出
	while (str->data!='\n') {
		String* new = (String*)malloc(sizeof(String));
		new->data = getchar();
		new->next = str->next;
		str->next = new;
		str = new;
	}
	//因为退出循环时，str的值是'\n'，给它换成'\0'
	str->data = '\0';
	str->next = NULL;
	return s;
}
//串插入
String* InsertString(String* s, String* str, int index) {
	//断言，不满足以下条件程序报错退出
	assert(index >= 0 && index <= my_strlen(s));
	//用两个指针代替操作
	String* s1 = s;
	String* s2 = str;
	//先把指针移到要插入的位置处
	while (index--) {
		s1 = s1->next;
	}
	//然后把要插入的串的指针移到最后
	while (s2->next) {
		s2 = s2->next;
	}
	//因为每个串最后都是'\0'，所以给他覆盖掉
	s2->data = s1->next->data;
	s2->next = s1->next->next;
	s1->next = str->next;
	return s;
}
//子串位置
int IndexString(String* s, String* str) {
	//从第一个结点开始比较，值一样便是子串位置
	String* s1 = s->next;
	str = str->next;
	//起始位置为1
	int index = 1;
	while (1) {
		if (s1->data == str->data)
			return index;
		s1 = s1->next;
		index++;
	}
}
//串删除
String* DeleteString(String* s, String* str) {
	//先得到子串的位置
	int index = IndexString(s, str);
	//在得到子串的长度
	int length = my_strlen(str);
	//建两个前后指针
	String* front = s;
	String* s1 = s->next;
	//先把后指针移到删除的位置，前指针移动删除的前一个位置
	while (index!=1) {
		front = front->next;
		s1 = s1->next;
		index--;
	}
	//把后指针往后移动要删除子串的长度那么多个位置
	for (int i = 0; i < length; i++) {
		s1 = s1->next;
	}
	//然后前指针直接指向后指针，中间的就被删掉了
	front->next = s1;
	return s;
} 
//串连接
String* ConcattString(String* s,String* str) {
	String * s1 = s;
	while (1) {
		s1 = s1->next;
		//当指针来到'\0'处，说明是末尾了，那么就直接连接并且把'\0'覆盖掉
		if (s1->data == '\0') {
			s1->data = str->next->data;
			s1->next = str-> next->next;
			return s;
		}
	}
}
//串比较
/*比较的是字符的ASCII码值*/
int my_strcmp(String* s, String* str) {
	//有一个串为空时就退出循环
	while (s && str) {
		if (s->data > str->data)
			return 1;
		if (s->data < str->data)
			return -1;
		if (s->data == str->data) {
			s = s->next;
			str = str->next;
		}
	}
	//推出了循环说明目前两串已比较的值都是相等的
	//需要在比较下那个串已经比较完了，没完的那个串大
	if (s == NULL && str == NULL)
		return 0;
	if (s != NULL)
		return 1;
	else
		return -1;
}
//传打印
void PrintString(String* str) {
	str = str->next;
	while (str->data!='\0') {
		printf("%c", str->data);
		str = str->next;
	}
}
//串长度
int my_strlen(String* str) {
	int count = 0;
	while (str->data!='\0') {
		count++;
		str = str->next;
	}
	//因为串的开头有一个；垃圾值，所以减去他的长度，如果没有就不用建
	return count-1;
}
//判子串
int my_strstr(String* s, String* str) {
	//建两个指针，以前一后，都从第一个值开始
	String* s1 = s->next;
	String* s2 = s->next;
	//str从第一个值开始
	str = str->next;
	//定义两个变量作指针用来计数
	int front = 1;
	int rear = 1;
	//求长度
	int length = my_strlen(str);
	while (s2 && str) {
		//如果两值相等，str和s2往后移动继续比较，并且rear+1
		if (s2->data == str->data) {
			s2 = s2->next;
			str = str->next;
			rear++;
		}
		//如果不等，str不动，把s1移动到s2的位置重新开始，front也移动到rear
		else {
			s2 = s2->next;
			rear++;
			front = rear;
			s1 = s2;
		}
		//如果front和rear的差值等于了str'的长度，说明str是s的子串
		if (rear-front== length)
			return 0;
	}
	//退出了循环说明不是子串
	return -1;
}
//串拷贝
String* my_strcpy(String* s, String* str) {
	String* s1 = s;
	//直接把str里的所有结点包括'\0'赋值给s就行
	while (str) {
		s1->data = str->data;
		s1 = s1->next;
		str = str->next;
	}
	return s;
}
//串替换
String* ReplaceString(String* s, String* str,int index) {
	String* s1 = s;
	//先找到替换的位置
	while (index--) {
		s1 = s1->next;
	}
	str = str->next;
	//然后开始赋值
	while (str->data) {
		s1->data = str->data;
		s1 = s1->next;
		str = str->next;
	}
	return s;
}