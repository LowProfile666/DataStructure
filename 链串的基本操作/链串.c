#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef struct LinkString {
	char data;
	struct LinkString* next;
}String;

//��������
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
	system("title ����");
	//������
	String LS;
	String* s=&LS;

	printf("���ȳ�ʼ��һ������");
	s=InitString(s);
	printf("��ʼ���ɹ���\n");
	//����һ�����������������롢�Ƚϡ��滻����Ҫ�������Ĳ���
	String* str = (String*)malloc(sizeof(String));
	//��������������������ѡ��ֵ��λ��ֵ����������ֵ
	int chose = 0;
	int index = 0;
	int num = 0;
	while (1) {
		printf("--��ǰ��Ϊ��");
		PrintString(s);				//��ӡ��
		printf("\n");
		printf("--��ǰ������%d\n",my_strlen(s));
		menu();						//�˵�
		scanf("%d", &chose);
		getchar();
		switch (chose) {
			//������
		case 1:
			printf("������Ҫ����Ĵ���");
			str = InitString(str);			//�ȳ�ʼ����������Ҫ����Ĵ�
			printf("������Ҫ�����λ�ã�");
			scanf("%d", &index);			//�����λ�ã���һ������λ����1
			s = InsertString(s, str,index-1);
			printf("����ɹ���\n----------------------\n");
			break;
			//��ɾ��
		case 2:printf("������Ҫɾ���Ĵ���");
			str = InitString(str);			//�ȳ�ʼ����������Ҫɾ���Ĵ�
			if (my_strstr(s, str) == -1) {	//���ж��Ƿ����Ӵ������ǾͲ���ɾ��
				printf("�����Ӵ��޷�ɾ����\n----------------------\n");
				break;
			}
			s = DeleteString(s, str);
			printf("ɾ���ɹ���\n----------------------\n");
			break;
			//������
		case 3:
			printf("������Ҫ���ӵĴ���");
			str = InitString(str);			//�ȳ�ʼ����������Ҫ���ӵĴ�
			s = ConcattString(s, str);
			printf("���ӳɹ���\n----------------------\n");
			break;
			//���Ƚ�
		case 4:
			printf("������Ҫ�ȽϵĴ���");
			str = InitString(str);			//�ȳ�ʼ����������Ҫ�ȽϵĴ�
			num = my_strcmp(s, str);		//��ȡ����ڡ�С�ڶ��᷵��ֵ
			PrintString(s);					//��ӡԴ��
			if (num == 0) {
				printf("����");
			}
			if (num > 0) {
				printf("����");
			}
			if (num < 0) {
				printf("С��");
			}
			PrintString(str);				//��ӡ�ȽϵĴ�
			printf("\n----------------------\n");
			break;
			//���Ӵ�
		case 5:
			printf("������Ҫ�жϵĴ���");
			str = InitString(str);			//�ȳ�ʼ����������Ҫ�жϵĴ�
			num = my_strstr(s, str);		//�ǲ����Ӵ����᷵��ֵ
			PrintString(str);				//��ӡԴ��
			if (num == 0)
				printf("��");
			else
				printf("����");
			PrintString(s);					//��ӡ�жϵĴ�
			printf("���Ӵ���\n----------------------\n");
			break;
			//������
		case 6:
			printf("������Ҫ�����Ĵ���");
			str = InitString(str);			//�ȳ�ʼ����������Ҫ�����Ĵ�
			s = my_strcpy(s, str);
			printf("�����ɹ���\n----------------------\n");
			break;
			//���滻
		case 7:
			printf("������Ҫ�滻�Ĵ���");
			str = InitString(str);			//�ȳ�ʼ����������Ҫ�滻�Ĵ�
			printf("�������滻��λ�ã�");
			scanf("%d", &index);
			s = ReplaceString(s, str,index);
			printf("�滻�ɹ���\n----------------------\n");
			break;
			//�˳�
		case 0:return;
		default:printf("��������������룺\n");
		}
	}
	return 0;
}
void menu() {
	printf("----------------------\n");
	printf("��ѡ��\n");
	printf("**********************\n");
	printf("****��*��*��*��*��****\n");
	printf("**1������    2��ɾ��**\n");
	printf("**3������    4���Ƚ�**\n");
	printf("**5���Ӵ�    6������**\n");
	printf("**7���滻    0���˳�**\n");
	printf("**********************\n");
}
//��ʼ��
String* InitString(String* s) {
	s = (String*)malloc(sizeof(String));
	s->next = NULL;
	//��һ��strָ��������
	String* str = s;
	//�������з�ʱ�˳�
	while (str->data!='\n') {
		String* new = (String*)malloc(sizeof(String));
		new->data = getchar();
		new->next = str->next;
		str->next = new;
		str = new;
	}
	//��Ϊ�˳�ѭ��ʱ��str��ֵ��'\n'����������'\0'
	str->data = '\0';
	str->next = NULL;
	return s;
}
//������
String* InsertString(String* s, String* str, int index) {
	//���ԣ������������������򱨴��˳�
	assert(index >= 0 && index <= my_strlen(s));
	//������ָ��������
	String* s1 = s;
	String* s2 = str;
	//�Ȱ�ָ���Ƶ�Ҫ�����λ�ô�
	while (index--) {
		s1 = s1->next;
	}
	//Ȼ���Ҫ����Ĵ���ָ���Ƶ����
	while (s2->next) {
		s2 = s2->next;
	}
	//��Ϊÿ���������'\0'�����Ը������ǵ�
	s2->data = s1->next->data;
	s2->next = s1->next->next;
	s1->next = str->next;
	return s;
}
//�Ӵ�λ��
int IndexString(String* s, String* str) {
	//�ӵ�һ����㿪ʼ�Ƚϣ�ֵһ�������Ӵ�λ��
	String* s1 = s->next;
	str = str->next;
	//��ʼλ��Ϊ1
	int index = 1;
	while (1) {
		if (s1->data == str->data)
			return index;
		s1 = s1->next;
		index++;
	}
}
//��ɾ��
String* DeleteString(String* s, String* str) {
	//�ȵõ��Ӵ���λ��
	int index = IndexString(s, str);
	//�ڵõ��Ӵ��ĳ���
	int length = my_strlen(str);
	//������ǰ��ָ��
	String* front = s;
	String* s1 = s->next;
	//�ȰѺ�ָ���Ƶ�ɾ����λ�ã�ǰָ���ƶ�ɾ����ǰһ��λ��
	while (index!=1) {
		front = front->next;
		s1 = s1->next;
		index--;
	}
	//�Ѻ�ָ�������ƶ�Ҫɾ���Ӵ��ĳ�����ô���λ��
	for (int i = 0; i < length; i++) {
		s1 = s1->next;
	}
	//Ȼ��ǰָ��ֱ��ָ���ָ�룬�м�ľͱ�ɾ����
	front->next = s1;
	return s;
} 
//������
String* ConcattString(String* s,String* str) {
	String * s1 = s;
	while (1) {
		s1 = s1->next;
		//��ָ������'\0'����˵����ĩβ�ˣ���ô��ֱ�����Ӳ��Ұ�'\0'���ǵ�
		if (s1->data == '\0') {
			s1->data = str->next->data;
			s1->next = str-> next->next;
			return s;
		}
	}
}
//���Ƚ�
/*�Ƚϵ����ַ���ASCII��ֵ*/
int my_strcmp(String* s, String* str) {
	//��һ����Ϊ��ʱ���˳�ѭ��
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
	//�Ƴ���ѭ��˵��Ŀǰ�����ѱȽϵ�ֵ������ȵ�
	//��Ҫ�ڱȽ����Ǹ����Ѿ��Ƚ����ˣ�û����Ǹ�����
	if (s == NULL && str == NULL)
		return 0;
	if (s != NULL)
		return 1;
	else
		return -1;
}
//����ӡ
void PrintString(String* str) {
	str = str->next;
	while (str->data!='\0') {
		printf("%c", str->data);
		str = str->next;
	}
}
//������
int my_strlen(String* str) {
	int count = 0;
	while (str->data!='\0') {
		count++;
		str = str->next;
	}
	//��Ϊ���Ŀ�ͷ��һ��������ֵ�����Լ�ȥ���ĳ��ȣ����û�оͲ��ý�
	return count-1;
}
//���Ӵ�
int my_strstr(String* s, String* str) {
	//������ָ�룬��ǰһ�󣬶��ӵ�һ��ֵ��ʼ
	String* s1 = s->next;
	String* s2 = s->next;
	//str�ӵ�һ��ֵ��ʼ
	str = str->next;
	//��������������ָ����������
	int front = 1;
	int rear = 1;
	//�󳤶�
	int length = my_strlen(str);
	while (s2 && str) {
		//�����ֵ��ȣ�str��s2�����ƶ������Ƚϣ�����rear+1
		if (s2->data == str->data) {
			s2 = s2->next;
			str = str->next;
			rear++;
		}
		//������ȣ�str��������s1�ƶ���s2��λ�����¿�ʼ��frontҲ�ƶ���rear
		else {
			s2 = s2->next;
			rear++;
			front = rear;
			s1 = s2;
		}
		//���front��rear�Ĳ�ֵ������str'�ĳ��ȣ�˵��str��s���Ӵ�
		if (rear-front== length)
			return 0;
	}
	//�˳���ѭ��˵�������Ӵ�
	return -1;
}
//������
String* my_strcpy(String* s, String* str) {
	String* s1 = s;
	//ֱ�Ӱ�str������н�����'\0'��ֵ��s����
	while (str) {
		s1->data = str->data;
		s1 = s1->next;
		str = str->next;
	}
	return s;
}
//���滻
String* ReplaceString(String* s, String* str,int index) {
	String* s1 = s;
	//���ҵ��滻��λ��
	while (index--) {
		s1 = s1->next;
	}
	str = str->next;
	//Ȼ��ʼ��ֵ
	while (str->data) {
		s1->data = str->data;
		s1 = s1->next;
		str = str->next;
	}
	return s;
}