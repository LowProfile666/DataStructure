#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef struct SqList {
	int arr[100];//结构体序列
	int length;//序列长度
}Sq;

//函数声明：
void menu();
int f0(int count);
void f1(Sq* p);
void f2(Sq* p, int count);
void f3(Sq* p, int count);
void f4(Sq* p, int count);
void f5(Sq* p, int count);
void f6(Sq* p, int count);
Sq f7(Sq* p, int count);
void f8(Sq* p, int count);
void f9(Sq* p, int count);

int main() {
	system("TITLE 数据结构顺序表");
	Sq p;//创建一个结构体变量
	int n;//菜单选择数
	int count = 0;
//定义一个count计数，代表第一次进入程序还没有创建序列，传到每个函数用来判断是否是空序列，是就返回菜单，不是就继续操作
	p.length = 0;//初值为0，代表没有序列存在
	
	while (1) {
		//用死循环一直显示菜单直到自己选择退出
		menu();//显示菜单
		scanf("%d", &n);//输入选择值
		switch (n) {
		case 1:f1(&p); count++; break;//创建顺序表，创建序列后count++不再为零
		case 2:f2(&p,count); break;//输出顺序表
		case 3:f3(&p,count); break;//查找某元素
		case 4:f4(&p,count); break;//奇偶数分离
		case 5:f5(&p,count); break;//判断对称否
		case 6:f6(&p,count); break;//插入某序列
		case 7:
			if (count == 0)//count=0时，没有序列所以直接进入f7()后返回
				f7(&p,count);
			else//count不为零，说明有序列，所以进入f7()完成 操作并返回新序列
				p=f7(&p,count); //归并两序列，p接收归并后的新序列，p就是新序列了
			break;
		case 8:f8(&p,count); break;//按顺序排列
		case 9:f9(&p,count); break;//删除某序列
		case 10:system("cls"); break;//清屏
		case 0:printf("成功退出！"); return;
		default:printf("输入错误！请重新输入：\n");
		}
	}
	return 0;
}
//菜单
void menu() {
	printf("**********************\n");
	printf("******顺序表操作******\n");
	printf("********0.退出********\n");
	printf("*****1.创建顺序表*****\n");
	printf("*****2.输出顺序表*****\n");
	printf("*****3.查找某元素*****\n");
	printf("*****4.奇偶数分离*****\n");
	printf("*****5.判断对称否*****\n");
	printf("*****6.插入某序列*****\n");
	printf("*****7.归并两序列*****\n");
	printf("*****8.按顺序排列*****\n");
	printf("*****9.删除某序列*****\n");
	printf("********10.清屏*******\n");
	printf("----请输入你的选择----\n");
}

//0.判断是否空序列
int f0(int count) {
	if (count == 0) {
		printf("当前没有序列！请先创建序列再进行操作！\n");
		return 0;
	}
	return 1;
}

//1.创建顺序表
void f1(Sq* p) {
	int length;//作序列的大小
	int count1 = 0;
	//用来计数，记输入了几个数了，如果输入的数超出了既定的范围，那么就跳出循环，避免下次输入的值是缓存区残留

	//判断是否有序列存在
	if (p->length != 0) {
		printf("已有序列！请勿重复创建！\n");
		return;
	}
	printf("请输入你想创建的序列的大小：");
	scanf("%d", &length);
	if (length <= 0) {
		printf("创建失败！返回菜单！\n");
		return;
	}
	printf("请输入整数序列（输入-1可手动退出）：");
	for (int i = 0; i < 100; i++) {
		scanf("%d", &p->arr[i]);
		count1++;
		if (p->arr[i] == -1) {
			printf("结束输入！\n");
			p->length += count1-1;
			return;
		}
		if (count1 >= length) {//当输入的个数大于了给定的范围
			while (getchar() != '\n') {//用getchar接收后面多余的数，直到接收到换行符
				;//空语句用来支持循环
			}
			break;//跳出外层的输入数的循环
		}
	}
	p->length = length;
	printf("录入成功！\n");
}

//2.输出顺序表
void f2(Sq* p, int count) {
	if (!(f0(count))) //先判断是否是个空列表，是就返回菜单，不是就向下操作
		return;
	int count1 = 0;//用来计数，打印一次加一，当他等于10的时候就换行，达到一排只打印十个数字的效果
	printf("当前的序列是：\n");
	for (int i = 0; i < p->length; i++) {
		printf("%2d ", p->arr[i]);
		count1++;
		if (count1 == 10) {
			printf("\n");
			count1 = 0;//重置count，方便下一排继续计数
		}
	}
	printf("\n");
	printf("----------------------\n");//换行，下一行是菜单
}

//3.查找某元素
void f3(Sq* p, int count) {
	if (!(f0(count)))//先判断是否是个空列表，是就返回菜单，不是就向下操作
		return;
	printf("请输入你想查找的元素：\n");
	int n;
	scanf("%d", &n);//输入查找的元素
	for (int i = 0; i < p->length; i++) {//遍历数组查找元素
		if (n == p->arr[i]) {
			printf("找到了！下标是：%d\n", i);
			return;
		}
	}
	printf("该序列中没有此元素！\n");
}

//4.奇偶数分离
//奇数在前偶数在后，不考虑大小顺序
void  f4(Sq* p, int count) {
	if (!(f0(count)))//先判断是否是个空列表，是就返回菜单，不是就向下操作
		return;
	int* p1 = &p->arr[0];//定义个头指针放在顺序表的第一个元素位置
	int* p2 = &p->arr[p->length - 1];//定义个尾指针放在顺序表的最后一个元素位置
	for (int i = 0; i < p->length; i++) {
		if ((*p1) % 2 == 0) {//第一种情况：如果第一个元素是个偶数，下面又分两种情况
			if ((*p2) % 2 != 0) {//①最后一个元素是个奇数
				//那么就将这俩个数交换，并且，头指针向后移动一格，尾指针向前移动一格
				int tmp = *p1;
				*p1 = *p2;
				*p2 = tmp;
				p1++;
				p2--;
			}
			else {//②最后一个元素是个偶数，那么最后一个偶数不需要动，将头指针向后移动一格直到它是一个奇数
				p2--;
			}
		}
		else {//第二种情况：如果第一个元素是奇数，下面又分两种情况：
			if ((*p2) % 2 == 0) {//①最后一个元素是偶数，这是我们的理想状态，所以不需要交换，只需移动指针
				p1++;//头指针后移一格
				p2--;//尾指针前移一格
			}
			else {//②最后一个元素是奇数，只将尾指针向前移动直到它是个偶数
				p1++;
			}
		}
		if (p1 >= p2)//循环退出条件：此时两个指针起码走在了一起，说明序列已经分离完毕
			break;//跳出循环
	}
	int count1 = 0;//计数，记有多少个奇数，用来分开打印奇数和偶数
	for (int i = 0; i < p->length; i++) {//遍历序列，得出有几个奇数
		if (p->arr[i] % 2 != 0) {
			count1++;
		}
	}
	printf("分离成功！\n");
	printf("奇数为：");
	for (int i = 0; i < count1; i++) {//打印奇数
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	printf("偶数为：");
	for (int i = count1; i < p->length; i++) {//打印偶数
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	printf("分离后的序列为：\n");
	//打印整个序列
	int count2 = 0;//用来计数，打印一次加一，当他等于10的时候就换行，达到一排只打印十个数字的效果
	for (int i = 0; i < p->length; i++) {
		printf("%2d ", p->arr[i]);
		count2++;
		if (count2 == 10) {
			printf("\n");
			count2 = 0;
		}
	}
	printf("\n");
	printf("----------------------\n");//换行，下一行是菜单
}

//5.判断对称否
void f5(Sq* p, int count) {
	if (!(f0(count)))//先判断是否是个空列表，是就返回菜单，不是就向下操作
		return;
	for (int i = 0; i < (p->length) / 2; i++) {//因为这里是头和尾两个一起比较，所以次数减半
		if (p->arr[i] != p->arr[p->length - 1 - i]) {
			printf("不对称！\n");
			return;
		}
	}
	printf("对称！\n");
}
//6.插入序列
void f6(Sq* p, int count) {
	if (!(f0(count)))//先判断是否是个空列表，是就返回菜单，不是就向下操作
		return;
	int num;//插入序列的大小
	printf("请输入要插入序列的大小：");
	scanf("%d", &num);
	if (num <= 0) {//判断要插入的序列大小是否不合理
		printf("插入失败！返回菜单！\n");
		return;
	}
	printf("请输入要插入的序列元素：");
	int count1=p->length;//计数
	for (int i = p->length; i < p->length + num; i++) {
		scanf("%d", &p->arr[i]);//输入要插入的序列
		count1++;
		if (count1 >= p->length+num) {//当输入的个数大于了给定的范围
			while (getchar() != '\n') {//用getchar接收后面多余的数，直到接收到换行符
				;//空语句用来支持循环
			}
			break;//跳出外层的输入数的循环
		}
	}
	p->length += num;//更新序列的长度
	printf("添加成功！\n");
}

//7.归并序列
Sq f7(Sq* p, int count) {
	if (!(f0(count)))//先判断是否是个空列表，是就返回菜单，不是就向下操作
		return *p;//因为在主函数那边有个结构体变量p接收本函数返回的新序列，所以得有个返回值，因为现在没有归并，所以直接返回原序列

	printf("请注意：你确认当前的序列是有序的吗？\n*1.确认继续*\n*0.返回菜单*\n请输入：");
	int intput;
	scanf("%d", &intput);
	if (intput == 0)
		return *p;//因为在主函数那边有个结构体变量p接收本函数返回的新序列，所以得有个返回值，因为现在没有归并，所以直接返回原序列

	printf("抱歉！现在只有一个序列，请再新建一个顺序序列！\n");
	printf("新建序列：");
	Sq q;//新建一个结构体变量用来创建第二个序列
	q.length = 0;//向f1()表示当前这个结构体没有序列
	f1(&q);//创建序列
	printf("请稍后...\n");

	//判断原序列是否是从小到大排列的
	for (int i = 1; i < p->length; i++) {
		if (p->arr[i - 1] <= p->arr[i]) {
			;//空语句，如果满足条件不需要做什么所以这里放个空语句，接下来就是执行i++
		}
		else {
			printf("对不起！原序列不是一个顺序序列不能进行归并！\n");
			return *p;//因为在主函数那边有个结构体变量p接收本函数返回的新序列，所以得有个返回值，因为现在没有归并，所以直接返回原序列
		}
	}
	//判断新建序列是否是从小到大排列的
	for (int i = 1; i < q.length; i++) {
		if (q.arr[i - 1] <= q.arr[i]) {
			;//空语句，如果满足条件不需要做什么所以这里放个空语句，接下来就是执行i++
		}
		else {
			printf("对不起！新序列不是一个顺序序列不能进行归并！\n");
			return *p;//因为在主函数那边有个结构体变量p接收本函数返回的新序列，所以得有个返回值，因为现在没有归并，所以直接返回原序列
		}
	}

	Sq new;//新建一个结构体变量，用来作归并后的新序列
	new.length = p->length + q.length;//归并后的序列长度是两个序列的长度之和
	//将两个序列归并
	for (int i = 0; i < new.length; i++) {
		if (i < p->length)
			new.arr[i] = p->arr[i];
		if (i >= p->length)
			new.arr[i] = q.arr[i - (p->length)];//i - (p->length)这一部分就代表着i是从开始的
	}
	//这里冒泡排序用来排序归并后的新序列
	for (int i = 0; i < new.length - 1; i++) {
		for (int j = 0; j < new.length - 1 - i; j++) {
			if (new.arr[j] > new.arr[j + 1]) {
				int tmp = new.arr[j];
				new.arr[j] = new.arr[j + 1];
				new.arr[j + 1] = tmp;
			}
		}
	}
	printf("归并后的新序列：\n");
	int count1 = 0;//用来计数，打印一次加一，当他等于10的时候就换行，达到一排只打印十个数字的效果
	for (int i = 0; i < new.length; i++) {
		printf("%2d ", new.arr[i]);
		count1++;
		if (count1 == 10) {
			printf("\n");
			count1 = 0;
		}
	}
	printf("\n");
	printf("----------------------\n");//换行，下一行是菜单
	return new;//返回新序列
}
//8.排序
void f8(Sq* p, int count) {
	if (!(f0(count)))//先判断是否是个空列表，是就返回菜单，不是就向下操作
		return;
	//依旧是冒泡排序
	for (int i = 0; i < p->length - 1; i++) {
		for (int j = 0; j < p->length - 1 - i; j++) {
			if (p->arr[j] > p->arr[j + 1]) {
				int tmp = p->arr[j];
				p->arr[j] = p->arr[j + 1];
				p->arr[j + 1] = tmp;
			}
		}
	}
	printf("排序完成！排序后的序列：\n");
	int count1 = 0;//用来计数，打印一次加一，当他等于10的时候就换行，达到一排只打印十个数字的效果
	for (int i = 0; i < p->length; i++) {
		printf("%2d ", p->arr[i]);
		count1++;
		if (count1 == 10) {
			printf("\n");
			count1 = 0;
		}
	}
	printf("\n");
	printf("----------------------\n");//换行，下一行是菜单
}
//9.删除某序列
void f9(Sq* p, int count) {
	if (!(f0(count)))//先判断是否是个空列表，是就返回菜单，不是就向下操作
		return;
	printf("请输入要删除的元素个数：");
	int num;//要删除的元素个数
	int index;//要删除的序列的头元素得下标
	scanf("%d", &num);
	if (num == p->length) {//如果删除个数和元素个数一样多也就是全部删除的话
		for (int i = 0; i < p->length; i++) {
			p->arr[i] = p->arr[i + num];//将后面的空值赋给序列
		}
		p->length -= num;//删除过后要将长度减少
		printf("删除成功！请按2输出查看！\n");
		return *p;
	}
	else if (num < 1) {
		printf("没有要删除的序列，返回菜单！\n");
		return;
	}
	else if (num == 1) {
		printf("请输入要删除的元素下标：");
		scanf("%d", &index);
		if (index > p->length - 1) {//判断要删除的一个元素是否存在
			printf("没有该元素！返回菜单！\n");
				return;
		}
		for (int i = index; i <= p->length - 1; i++) {
			p->arr[i] = p->arr[i + 1];
		}
		p->length--;
		printf("删除成功！请按2输出查看！\n");
	}
	else if(num>p->length){//如果要删除的元素大于序列总元素，那就从给定的位置向后删除直到最后一个元素
		printf("请输入要删除序列的开始元素下标：");
		scanf("%d", &index);
		for (int i = index; i < p->length; i++) {
			p->arr[index] = p->arr[index + num];
		}
		p->length -= index;//不能直接减去num，因为怕从输入的下标开始到最后的元素并没有num这么多
		//比如：输入num=5，序列总共就才5个元素，然后输入开始删除的下标3，这样从下标3的元素到末尾并没有够5个数
		//所以事实上只删除了两个数，所以长度也减少2而不是减少5
		printf("删除成功！请按2输出查看！\n");
	}
	else {//要删除的元素个数大于1小于序列长度时
		printf("请输入要删除的元素下标：");
		scanf("%d", &index);
		if (index + num > p->length) {//如果从给定位置开始删除给定的个数时，元素不够
			//比如共有五个元素，给定删除个数3，给定下标位置3，需要删除位置3和后面的两个元素，但是后面只有一个元素存在
			//所以还是只删除当前位置到末尾
			for (int i = index; i < p->length; i++) {
				p->arr[index] = p->arr[index + num];
			}
			p->length -= index;
			printf("删除成功！请按2输出查看！\n");
			return;
		}
		else {
			for (int i = index; i < index + num; i++) {//这里的循环条件代表着要删除的地方
				p->arr[i] = p->arr[i + num];
			}
			p->length -= num;
			printf("删除成功！请按2输出查看！\n");
			return;
		}
	}
	return;
}