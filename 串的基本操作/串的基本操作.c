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

//��������
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
	printf("���ʼ������");
	gets(s);
	my_strlen(s);			//�㴮�ĳ���
	int chose=0;			//�˵�ѡ����
	int index;				//������������滻��λ��
	int num;				//�������ȽϺ��ж��Ӵ��ı���
	String S2;				//������
	String* str = &S2;
	while (1) {
		printf("��ǰ��ֵΪ��%s  \n��ǰ����Ϊ��%d\n", s->ch,s->length);
		menu();
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//������
		case 1:
			printf("���������Ĵ���");
			gets(str);
			my_strlen(str);			//�¸�ֵһ������Ҫ������ĳ��ȣ��������
			printf("������Ҫ�ڼ���λ�ò��룺");
			scanf("%d", &index);
			my_strinsert(str,index);
			printf("����ɹ���\n------------------------\n");
			break;
			//��ɾ��
		case 2:
			printf("������Ҫɾ�����Ӵ���");
			gets(str);
			if (my_strstr(str)==-1) {		//�ж��Ƿ����Ӵ��������ж��������Դ��������û�У��в���ɾ��
				printf("%s����%s���Ӵ���\n", str->ch, s->ch);
				break;
			}			
			printf("��ǰ��ֵΪ��%s  ��ǰ����Ϊ��%d\n", s->ch, s->length);
			printf("ɾ����ֵΪ��%s  ɾ������Ϊ��%d\n", str->ch, my_strlen(str));
			my_strdel(str,my_strstr(str));	//my_strstr(str)����������ص����Ӵ���λ��
			printf("ɾ���ɹ���\n------------------------\n");
			break;
			//������
		case 3:
			printf("������Ҫ�����Ĵ�ֵ��");
			gets(str);
			printf("��ǰ��ֵΪ��%s  ��ǰ����Ϊ��%d\n", s->ch, s->length);
			printf("������ֵΪ��%s  ��������Ϊ��%d\n", str->ch, my_strlen(str));
			my_strcpy(str);
			printf("�����ɹ���\n------------------------\n");
			break;
			//������
		case 4:
			printf("������Ҫ���ӵĴ�ֵ��");
			gets(str);
			printf("��ǰ��ֵΪ��%s  ��ǰ����Ϊ��%d\n", s->ch, s->length);
			printf("���Ӵ�ֵΪ��%s  ���Ӵ���Ϊ��%d\n", str->ch, my_strlen(str));
			my_strcat(str);
			printf("���ӳɹ���\n------------------------\n");
			break;
			//���Ƚ�
		case 5:
			printf("������Ҫ�ȽϵĴ�ֵ��");
			gets(str);
			printf("��ǰ��ֵΪ��%s  ��ǰ����Ϊ��%d\n", s->ch, s->length);
			printf("�Ƚϴ�ֵΪ��%s  �Ƚϴ���Ϊ��%d\n", str->ch, my_strlen(str));
			num=my_strcmp(str);	
			if (num == 0) {
				printf("����%s���ȴ���%s����С��ͬ��\n",str->ch,s->ch);
				printf("------------------------\n");
				break;
			}
			if (num < 0) {
				printf("����%s���ȴ���%s��С��\n", str->ch, s->ch);
				printf("------------------------\n");
				break;
			}
			if (num > 0) {
				printf("����%s���ȴ���%s����\n", str->ch, s->ch);
				printf("------------------------\n");
				break;
			}
			//���滻
		case 6:
			printf("�������滻����ֵ��");
			gets(str);
			printf("�������滻��λ�ã�");
			scanf("%d", &index);
			printf("��ǰ��ֵΪ��%s  ��ǰ����Ϊ��%d\n", s->ch, s->length);
			printf("�滻��ֵΪ��%s  �滻����Ϊ��%d\n", str->ch, my_strlen(str));
			my_strreplace(str, index);
			printf("�滻�ɹ���\n------------------------\n");
			break;
			//�ж��Ƿ����Ӵ�
		case 7:
			printf("�������жϴ���ֵ��");
			gets(str);
			printf("��ǰ��ֵΪ��%s  ��ǰ����Ϊ��%d\n", s->ch, s->length);
			printf("�жϴ�ֵΪ��%s  �жϴ���Ϊ��%d\n", str->ch, my_strlen(str));
			num=my_strstr(str);
			if (num == -1) {
				printf("��%s���Ǵ�%s���Ӵ���\n------------------------\n", str->ch, s ->ch);
				break;
			}
			printf("��%s�Ǵ�%s���Ӵ���\n------------------------\n", str->ch, s->ch);
			break;
			//��  ��
		case 0:return;
		default:printf("��������������룺\n");
		}
	}
	return 0;
}
void menu() {
	printf("��ѡ��\n");
	printf("------------------------\n");
	printf("------���Ļ�������------\n");
	printf("--1.������    2.��ɾ��--\n");
	printf("--3.������    4.������--\n");
	printf("--5.���Ƚ�    6.���滻--\n");
	printf("--7.���Ӵ�    0.��  ��--\n");
	printf("------------------------\n");
}
//1��������
void my_strinsert(String* str,int index) {
	
	//���ԣ��������������Ϊ�棬���򱨴��˳�
	assert(s->length + str->length <= MAXSIZE && index>=0 && index<=s->length);
	//�Ƚ�Դ����Ҫ�������λ�ú���ַ�����ƶ����ڳ��ռ�
	for (int i = s->length-1; i >= index; i--) {
		s->ch[i + str->length] = s->ch[i];
	}
	//�ٴ�Ҫ����λ�ÿ�ʼ�����ַ�
	for (int i = 0; i <str->length; i++) {
		s->ch[index++] = str->ch[i];
	}
	//������ɣ����ȸı�
	s->length += str->length;
}
//2����ɾ��
void my_strdel(String* str, int index) {
	//��Դ����Ҫɾ���Ĳ��ֵĺ�����ַ���ǰ�ƶ�������ԭ�еĲ��־���ɾ����
	for (int i = index; i <s->length; i++) {
		s->ch[i] = s->ch[i + str->length];
	}
	//ɾ���󣬳��ȸı�
	s->length -= str->length;
}
//3��������
//3.1��������
int my_strlen(String* s) {
	int i = 0;
	//��Ϊ�������ﶼ�����½��˴���ŵ�����������������Ƚ�������Ϊ0
	s->length = 0;
	while (s->ch[i++] != '\0') {
		s->length++;
	}
	return s->length;
}
//3.2��ָ��-ָ��
//int my_strlen(String* s) {
//	int front = 0;
//	int rear = 0;
//	while (s->ch[rear++]) {
//		;
//	}
//	s->length = rear-1 - front;
//	return s->length;
//}
//3.3���ݹ�
//int my_strlen(String* s) {
//	int i = 0;
//	if (s->ch[i] == 0)
//		return 0;
//	s->length=1 +my_strlen(&s->ch[i+1]);
//	return s->length;
//}
//4��������
void my_strcpy(String* str) {
	//����
	assert(str->length <= s->length);

	int i = 0;
	//������Ҫ������'\0'Ҳ������ȥ������i��������str->length
	for (i; i <= str->length; i++) {
		s->ch[i] = str->ch[i];
	}
	//�����󣬳���Ҫ��
	s->length = str->length;
}
//5��������
//��Դ�������������
void my_strcat(String* str) {
	//����
	assert(str->length + s->length <= MAXSIZE);

	int i = 0;
	//ѭ����������������������֮��
	for (int index = s->length; index < str->length + s->length; index++) {
		s->ch[index] = str->ch[i++];
	}
	//���Ӻ󣬳��ȸı�
	s->length += str->length;
}
//6�����Ƚ�
/*���Ƚ��ǰ�ASCII��ֵ�Ƚϴ���ÿһ���ַ���
���ȫ������򷵻�0��
�����ͬλ�õ�һ���ַ����ڻ�С����һ������ͬλ���ַ����򷵻ش������ֵ�򷵻�С�����ֵ��������ں�С��*/
int my_strcmp(String* str) {
	int i = 0;
	//���ж��ǲ����д���С������
	while (s->ch[i]&&str->ch[i]) {
		//���ڣ�
		if (str->ch[i] > s->ch[i])
			return 1;
		//С�ڣ�
		else if (str->ch[i] < s->ch[i])
			return -1;
		i++;
	}
	//�˳������ѭ��˵��������������һ���Ѿ������꣬����û�д���С�ڵ����
	//���Ի�Ҫ�жϣ�
	//���������ȣ���˵�������ַ�����ͬ
	if(s->length==str->length)
		return 0;
	//���Դ����ǰ��ֵ��Ϊ0��˵������һ������������
	if (s->ch[i] != 0)
		return -1;
	//�����һ������ǰ��ֵΪ0��˵����Դ����������
	if (str->ch[i] != 0)
		return 1;
}
//7�����п�
int my_strempty(String* s) {
	//��һ��ֵ�ǿվ��ǿ�
	if (s->ch[0])
		return 1;
	return 0;
}
//8�����滻
void my_strreplace(String* str, int index) {
	//����
	assert(index >= 0 && index <= s ->length);
	
	//ֱ������Ӧλ�ý�str��ֵ����Դ��
	for (int i = 0; i < str->length; i++) {
		s->ch[index++] = str->ch[i];
	}
	//�滻���ı䳤��
}
//9���ж��Ƿ��Ӵ�
int my_strstr(String* str) {
	//�Ӵ��ĳ������ֻ�ܺ�������ȣ��������Ӵ�
	if (my_strlen(str) > s->length)
		return -1;
	//������ָ��ķ�ʽ
	int left2 = 0;//�Ӵ���ָ��
	int left1 = 0;//��������ָ�룬ǰָ��
	int right1 = 0;//��������ָ�룬��ָ��
	//���Ӵ��ﵽ���һ���ַ�ǰ
	while (str->ch[left2]) {
		//����Ӵ��������ַ���ͬ������ָ������ƣ���������ָ�벻���������
		if (s->ch[right1++] == str->ch[left2]) {
			left2++;
		}
		//�����ͬ������������ָ���Ƶ���ָ���λ�����¿�ʼ
		else {
			left1=right1;
		}
		//����������ָ��֮��������Ӵ����ȣ�˵�������ȷʵ���Ӵ�
		if (right1 - left1  == str->length)
			//�����Ӵ��������е�λ��
			return left1;
	}
	return -1;
}