#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

#define MAXSIZE 256
typedef struct String {
	char ch[MAXSIZE];
	int length;
}String;
String S;
String* s = &S;

//函数声明
void menu();
void my_strinsert(String* str,int index);
void my_strcpy(String* str);
int my_strempty(String* s);
int my_strlen(String* s);
void my_strcat(String* str);
int my_strstr(String* str);
void my_strdel(String* str, int index);
void my_strreplace(String* str,int index);
int my_strcmp(String* str);


int main() {
	printf("请初始化串：");
	gets(s);
	my_strlen(s);			//算串的长度
	int chose=0;			//菜单选择项
	int index;				//后面作插入和替换的位置
	int num;				//后面作比较和判断子串的变量
	String S2;				//辅助串
	String* str = &S2;
	while (1) {
		printf("当前串值为：%s  \n当前串长为：%d\n", s->ch,s->length);
		menu();
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//串插入
		case 1:
			printf("请输入插入的串：");
			gets(str);
			my_strlen(str);			//新赋值一个串就要算好他的长度，方便调用
			printf("请输入要在几号位置插入：");
			scanf("%d", &index);
			my_strinsert(str,index);
			printf("插入成功！\n------------------------\n");
			break;
			//串删除
		case 2:
			printf("请输入要删除的子串：");
			gets(str);
			if (my_strstr(str)==-1) {		//判断是否是子串，就是判断这个串在源串里面有没有，有才能删除
				printf("%s不是%s的子串！\n", str->ch, s->ch);
				break;
			}			
			printf("当前串值为：%s  当前串长为：%d\n", s->ch, s->length);
			printf("删除串值为：%s  删除串长为：%d\n", str->ch, my_strlen(str));
			my_strdel(str,my_strstr(str));	//my_strstr(str)这个函数返回的是子串的位置
			printf("删除成功！\n------------------------\n");
			break;
			//串拷贝
		case 3:
			printf("请输入要拷贝的串值：");
			gets(str);
			printf("当前串值为：%s  当前串长为：%d\n", s->ch, s->length);
			printf("拷贝串值为：%s  拷贝串长为：%d\n", str->ch, my_strlen(str));
			my_strcpy(str);
			printf("拷贝成功！\n------------------------\n");
			break;
			//串连接
		case 4:
			printf("请输入要连接的串值：");
			gets(str);
			printf("当前串值为：%s  当前串长为：%d\n", s->ch, s->length);
			printf("连接串值为：%s  连接串长为：%d\n", str->ch, my_strlen(str));
			my_strcat(str);
			printf("连接成功！\n------------------------\n");
			break;
			//串比较
		case 5:
			printf("请输入要比较的串值：");
			gets(str);
			printf("当前串值为：%s  当前串长为：%d\n", s->ch, s->length);
			printf("比较串值为：%s  比较串长为：%d\n", str->ch, my_strlen(str));
			num=my_strcmp(str);	
			if (num == 0) {
				printf("串“%s”比串“%s”大小相同。\n",str->ch,s->ch);
				printf("------------------------\n");
				break;
			}
			if (num < 0) {
				printf("串“%s”比串“%s”小。\n", str->ch, s->ch);
				printf("------------------------\n");
				break;
			}
			if (num > 0) {
				printf("串“%s”比串“%s”大。\n", str->ch, s->ch);
				printf("------------------------\n");
				break;
			}
			//串替换
		case 6:
			printf("请输入替换串的值：");
			gets(str);
			printf("请输入替换的位置：");
			scanf("%d", &index);
			printf("当前串值为：%s  当前串长为：%d\n", s->ch, s->length);
			printf("替换串值为：%s  替换串长为：%d\n", str->ch, my_strlen(str));
			my_strreplace(str, index);
			printf("替换成功！\n------------------------\n");
			break;
			//判断是否是子串
		case 7:
			printf("请输入判断串的值：");
			gets(str);
			printf("当前串值为：%s  当前串长为：%d\n", s->ch, s->length);
			printf("判断串值为：%s  判断串长为：%d\n", str->ch, my_strlen(str));
			num=my_strstr(str);
			if (num == -1) {
				printf("串%s不是串%s的子串。\n------------------------\n", str->ch, s ->ch);
				break;
			}
			printf("串%s是串%s的子串。\n------------------------\n", str->ch, s->ch);
			break;
			//退  出
		case 0:return;
		default:printf("输入错误！重新输入：\n");
		}
	}
	return 0;
}
void menu() {
	printf("请选择：\n");
	printf("------------------------\n");
	printf("------串的基本操作------\n");
	printf("--1.串插入    2.串删除--\n");
	printf("--3.串拷贝    4.串连接--\n");
	printf("--5.串比较    6.串替换--\n");
	printf("--7.判子串    0.退  出--\n");
	printf("------------------------\n");
}
//1、串插入
void my_strinsert(String* str,int index) {
	
	//断言，如果以下条件不为真，程序报错并退出
	assert(s->length + str->length <= MAXSIZE && index>=0 && index<=s->length);
	//先将源串里要被插入的位置后的字符向后移动，腾出空间
	for (int i = s->length-1; i >= index; i--) {
		s->ch[i + str->length] = s->ch[i];
	}
	//再从要插入位置开始插入字符
	for (int i = 0; i <str->length; i++) {
		s->ch[index++] = str->ch[i];
	}
	//插入完成，长度改变
	s->length += str->length;
}
//2、串删除
void my_strdel(String* str, int index) {
	//将源串里要删除的部分的后面的字符向前移动，代替原有的部分就是删除了
	for (int i = index; i <s->length; i++) {
		s->ch[i] = s->ch[i + str->length];
	}
	//删除后，长度改变
	s->length -= str->length;
}
//3、串长度
//3.1、计数器
int my_strlen(String* s) {
	int i = 0;
	//因为主函数里都是再新建了串后才调用这个函数，所以先将长度置为0
	s->length = 0;
	while (s->ch[i++] != '\0') {
		s->length++;
	}
	return s->length;
}
//3.2、指针-指针
//int my_strlen(String* s) {
//	int front = 0;
//	int rear = 0;
//	while (s->ch[rear++]) {
//		;
//	}
//	s->length = rear-1 - front;
//	return s->length;
//}
//3.3、递归
//int my_strlen(String* s) {
//	int i = 0;
//	if (s->ch[i] == 0)
//		return 0;
//	s->length=1 +my_strlen(&s->ch[i+1]);
//	return s->length;
//}
//4、串拷贝
void my_strcpy(String* str) {
	//断言
	assert(str->length <= s->length);

	int i = 0;
	//这里需要将串的'\0'也拷贝进去，所以i的上限是str->length
	for (i; i <= str->length; i++) {
		s->ch[i] = str->ch[i];
	}
	//拷贝后，长度要变
	s->length = str->length;
}
//5、串连接
//从源串的最后面连接
void my_strcat(String* str) {
	//断言
	assert(str->length + s->length <= MAXSIZE);

	int i = 0;
	//循环条件的上限是两串长度之和
	for (int index = s->length; index < str->length + s->length; index++) {
		s->ch[index] = str->ch[i++];
	}
	//连接后，长度改变
	s->length += str->length;
}
//6、串比较
/*串比较是按ASCII码值比较串的每一个字符，
如果全部相等则返回0，
如果相同位置的一个字符大于或小于另一串的相同位置字符，则返回大于零的值或返回小于零的值，代表大于和小于*/
int my_strcmp(String* str) {
	int i = 0;
	//先判断是不是有大鱼小鱼的情况
	while (s->ch[i]&&str->ch[i]) {
		//大于：
		if (str->ch[i] > s->ch[i])
			return 1;
		//小于：
		else if (str->ch[i] < s->ch[i])
			return -1;
		i++;
	}
	//退出上面的循环说明，两串至少有一串已经遍历完，而且没有大于小于的情况
	//所以还要判断：
	//如果长度相等，那说明他们字符都相同
	if(s->length==str->length)
		return 0;
	//如果源串当前的值不为0，说明是另一个串被遍历完
	if (s->ch[i] != 0)
		return -1;
	//如果另一个串当前的值为0，说明是源串被遍历完
	if (str->ch[i] != 0)
		return 1;
}
//7、串判空
int my_strempty(String* s) {
	//第一个值是空就是空
	if (s->ch[0])
		return 1;
	return 0;
}
//8、串替换
void my_strreplace(String* str, int index) {
	//断言
	assert(index >= 0 && index <= s ->length);
	
	//直接在相应位置将str的值赋给源串
	for (int i = 0; i < str->length; i++) {
		s->ch[index++] = str->ch[i];
	}
	//替换不改变长度
}
//9、判断是否子串
int my_strstr(String* str) {
	//子串的长度最大只能和主串相等，否则不是子串
	if (my_strlen(str) > s->length)
		return -1;
	//这里用指针的方式
	int left2 = 0;//子串的指针
	int left1 = 0;//主串的左指针，前指针
	int right1 = 0;//主串的右指针，后指针
	//在子串达到最后一个字符前
	while (str->ch[left2]) {
		//如果子串与主串字符相同，两者指针向后移，主串的左指针不动，作起点
		if (s->ch[right1++] == str->ch[left2]) {
			left2++;
		}
		//如果不同，将主串的左指针移到右指针的位置重新开始
		else {
			left1=right1;
		}
		//当主串的两指针之差等于了子串长度，说明这个串确实是子串
		if (right1 - left1  == str->length)
			//返回子串在主串中的位置
			return left1;
	}
	return -1;
}