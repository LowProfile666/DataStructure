#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*ͨѶ¼����
�����������������Ա�ʵ��һ��ͨѶ¼����
Ҫ��
1��ʵ��ͨ��¼�Ľ��������ӡ�ɾ�����޸ġ���ѯ�ȹ��� ��
2�� �ܹ�ʵ�ּ򵥵Ĳ˵������������Ը����û���������ѡ��ͬ�Ĳ�����
3�� �ܹ�����ÿ�θ��µ����ݣ�
4�� ��дmain()�������Բ�������ȷ�ԡ�*/

typedef struct people {//������ϵ�˽ṹ��
	char name[20];//����
	char tel[20];//�绰
}P;
P num[100];//����ṹ�����飬���Դ�100����ϵ�˵���Ϣ
int i=0;//��������ϵ�˵���ţ����߿����ж���ϵ�˸����Ƿ񵽴������ֵ

//��������
void menu();
void add();
void del();
void find();
void edit();
void print();

int main() {
	system("title ͨѶ¼����ϵͳ");
	int in;//ѡ��ֵ
	while (1) {
		menu();//�˵�
		scanf("%d", &in);
		switch (in) {
		case 0:return;			//�˳�ϵͳ
		case 1:add(); break;	//�����ϵ��
		case 2:del(); break;	//ɾ����ϵ��
		case 3:find(); break;	//������ϵ��
		case 4:edit(); break;	//�༭��ϵ��
		case 5:print(); break;	//��ӡͨѶ¼
		default:printf("����������������룺\n"); break;
		}
	}
	return 0;
}
//�˵�
void menu() {
	printf("================================\n");
	printf("\tͨѶ¼����ϵͳ\n");
	printf("\t 0.�˳�ͨѶ¼\n");
	printf("\t 1.�����ϵ��\n");
	printf("\t 2.ɾ����ϵ��\n");
	printf("\t 3.������ϵ��\n");
	printf("\t 4.�޸���ϵ��\n");
	printf("\t 5.�鿴ͨѶ¼\n");
	printf("================================\n");
	printf("��ѡ��");
}
//���û���������ʾ����Ļ���
void Printf(double m) {
	if (m == 0) printf("��ͨѶ¼�Ѿ�װ���ˣ�\n");
	if (m == 0.1) printf("��ǰû����ϵ�ˣ�\n");
	if (m == 1.1) printf("��������ϵ�˵�������\n");
	if (m == 1.2) printf("��������ϵ�˵ĵ绰��\n");
	if (m == 1.3) printf("��ӳɹ����Ƿ������� Y/N��\n");
	if (m == 2.1) printf("������Ҫɾ������ϵ��������\n");
	if (m == 2.2) printf("ȷ��ɾ��������Ϣ��\n");
	if (m == 2.3) printf("1.ȷ�� 2.����\n");
	if (m == 2.4) printf("ɾ���ɹ���\n");
	if (m == 2.5) printf("û���ҵ�����ϵ�ˣ�\n");
	if (m == 3.1) printf("������Ҫ���ҵ���ϵ��������\n");
	if (m == 3.2) printf("���ҳɹ���\n");
	if (m == 3.3) printf("�����޴��ˣ�\n");
	if (m == 4.1) printf("������Ҫ�޸ĵ���ϵ��������\n");
	if (m == 4.2) printf("��ǰ��ϵ����ϢΪ��\n");
	if (m == 4.3) printf("�Ƿ�ȷ���޸ģ�Y/N��\n");
	if (m == 4.4) printf("�������µ�������\n");
	if (m == 4.5) printf("�������µĵ绰��\n");
	if (m == 4.6) printf("�޸ĳɹ�����ǰ��ϵ����ϢΪ��\n");
	if (m == 4.7) printf("û�и���ϵ�ˣ�\n");
}
//�ж��ַ����Ƿ���ȣ����ڲ�ѯ��ɾ�����༭�Ȳ���
int my_strcmp(char name[],int j) {	//���������������ýṹ�������±�
	char* p1 = name;				//strcmp������ָ�룬���Խ�������ָ���ʾ
	char* p2 = (char*)&num[j];
	if (strcmp(p1, p2) == 0) {		//strcmp��Ⱦͷ���0
		return 0;
	}
	return 1;
}
//��ӡ�����˵���Ϣ������ɾ���ͱ༭����
void print2(int j) {
	printf("���\t����\t\t�绰\n");
	printf("%2d\t%s\t\t%s\n", (j+1),num[j].name, num[j].tel);
}
//1.������ϵ��
void add() {
	if (i > 100) {							//���ͨѶ¼���˾Ͳ����������
		Printf(0);							//������ʾ
		return;
	}
	char chose;								//�����ж��Ƿ�Ҫ�������
	while (1) {
		Printf(1.1);						//��ʾ��������
		scanf("%s", &num[i].name);
		getchar();							//���������
		Printf(1.2);						//��ʾ����绰
		scanf("%s", &num[i].tel);
		getchar();							//���������
		i++;								//���һ����ϵ�˾ͼ�һ
		Printf(1.3);						//��ʾ�Ƿ�������
		scanf("%c", &chose);
		if (chose == 'y' || chose == 'Y') {	//ѡ��y��Y�ͼ�����ӣ�����ֵ�˳�
			continue;						//��������ѭ�����ص��ж�������
		}
		return;
	}
}
//ɾ������ϸ������������ϵ�˵���Ϣ��ɺ�һ����ϵ�ˣ�����ɾ���ɹ�
void del2(int j) {
		for (j; j < i; j++) {
			num[j] = num[j + 1];
	}
}
//2.ɾ����ϵ��
void del() {
	if (i == 0) {							//�жϵ�ǰ�Ƿ�����ϵ��
		Printf(0.1);
		return;
	}
	char name[20];							//�������������Ҫɾ������ϵ������
	int chose=0;							//�����ж�
	Printf(2.1);							//ɾ��������
	scanf("%s", name);
	for (int j = 0; j < i; j++) {
		if (my_strcmp(name,j) == 0) {		//���������������������ͬ��Ԫ��
			Printf(2.2);					//��ʾ��ǰ��ϵ����Ϣ
			print2(j);						//��ʾ��ǰ����ϵ����Ϣ
			Printf(2.3);					//��ʾ�Ƿ�ȷ��ɾ��
			scanf("%d", &chose);
			if (chose == 1) {
				del2(j);					//����ɾ������
				Printf(2.4);				//��ʾɾ���ɹ�
				i--;						//��ϵ�˵ĸ���Ҫ��һ
				return;						
			}
		}
	}
	Printf(2.5);							//û���ҵ�Ŀ�꣬��ʾû�д���
	return;
}
//3.����
void find() {
	if (i == 0) {							//�жϵ�ǰ�Ƿ�����ϵ��
		Printf(0.1);
		return;
	}
	Printf(3.1);							//��ʾ�����������
	char name[20];							//��������
	scanf("%s", name);
	for (int j = 0; j < i; j++) {
		if (my_strcmp(name,j) == 0) {		//����������������ͬ��Ԫ��
			Printf(3.2);					//��ʾ�ҵ���Ŀ����ϵ��
			print2(j);						//��ʾ����ϵ�˵���Ϣ
			return;
		}
	}
	Printf(3.3);							//��ʾû���ҵ���ϵ��
}
//4.�޸�
void edit() {
	if (i == 0) {							//�жϵ�ǰ�Ƿ�����ϵ��
		Printf(0.1);
		return;
	}
	Printf(4.1);							//����༭����
	char name[20];							//��������
	char chose;								//����ѡ��
	scanf("%s", name);
	getchar();								//���������
	for (int j = 0; j < i; j++) {
		if (my_strcmp(name, j) == 0) {		//����������������ͬ��Ԫ��
			Printf(4.2);					//��ʾ�ҵ�����
			print2(j);						//���������Ϣ
			Printf(4.3);					//��ʾ�Ƿ�ȷ�ϱ༭
			scanf("%c", &chose);			//����ѡ��
			if (chose == 'y' || chose == 'Y') {
				Printf(4.4);				//��ʾ����������
				scanf("%s", &num[j].name);	//����������
				Printf(4.5);				//��ʾ�����µ绰
				scanf("%s", &num[j].tel);	//�����µ绰
				Printf(4.6);				//��ʾ�༭�ɹ�
				print2(j);					//��ʾ����ϵ����Ϣ
				return;
			}
		}
	}
	Printf(4.7);							//��ʾû�д���
}
//5.��ʾͨѶ¼
void print() {
	if (i == 0) {							//�жϵ�ǰ�Ƿ�����ϵ��
		Printf(0.1);
		return;
	}
	int j = 0;								//�������±꣬�ӵ�һ��Ԫ�ؿ�ʼ���
	printf("���\t����\t\t�绰\n");
	printf("----\t----\t\t----\n");
	for (j = 0; j < i; j++) {
		printf("%2d\t%s\t\t%s\n", (j + 1), num[j].name, num[j].tel);
	}
}

