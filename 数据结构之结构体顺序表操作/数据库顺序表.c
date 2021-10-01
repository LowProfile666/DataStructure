#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef struct SqList {
	int arr[100];//�ṹ������
	int length;//���г���
}Sq;

//����������
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
	system("TITLE ���ݽṹ˳���");
	Sq p;//����һ���ṹ�����
	int n;//�˵�ѡ����
	int count = 0;
//����һ��count�����������һ�ν������û�д������У�����ÿ�����������ж��Ƿ��ǿ����У��Ǿͷ��ز˵������Ǿͼ�������
	p.length = 0;//��ֵΪ0������û�����д���
	
	while (1) {
		//����ѭ��һֱ��ʾ�˵�ֱ���Լ�ѡ���˳�
		menu();//��ʾ�˵�
		scanf("%d", &n);//����ѡ��ֵ
		switch (n) {
		case 1:f1(&p); count++; break;//����˳����������к�count++����Ϊ��
		case 2:f2(&p,count); break;//���˳���
		case 3:f3(&p,count); break;//����ĳԪ��
		case 4:f4(&p,count); break;//��ż������
		case 5:f5(&p,count); break;//�ж϶ԳƷ�
		case 6:f6(&p,count); break;//����ĳ����
		case 7:
			if (count == 0)//count=0ʱ��û����������ֱ�ӽ���f7()�󷵻�
				f7(&p,count);
			else//count��Ϊ�㣬˵�������У����Խ���f7()��� ����������������
				p=f7(&p,count); //�鲢�����У�p���չ鲢��������У�p������������
			break;
		case 8:f8(&p,count); break;//��˳������
		case 9:f9(&p,count); break;//ɾ��ĳ����
		case 10:system("cls"); break;//����
		case 0:printf("�ɹ��˳���"); return;
		default:printf("����������������룺\n");
		}
	}
	return 0;
}
//�˵�
void menu() {
	printf("**********************\n");
	printf("******˳������******\n");
	printf("********0.�˳�********\n");
	printf("*****1.����˳���*****\n");
	printf("*****2.���˳���*****\n");
	printf("*****3.����ĳԪ��*****\n");
	printf("*****4.��ż������*****\n");
	printf("*****5.�ж϶ԳƷ�*****\n");
	printf("*****6.����ĳ����*****\n");
	printf("*****7.�鲢������*****\n");
	printf("*****8.��˳������*****\n");
	printf("*****9.ɾ��ĳ����*****\n");
	printf("********10.����*******\n");
	printf("----���������ѡ��----\n");
}

//0.�ж��Ƿ������
int f0(int count) {
	if (count == 0) {
		printf("��ǰû�����У����ȴ��������ٽ��в�����\n");
		return 0;
	}
	return 1;
}

//1.����˳���
void f1(Sq* p) {
	int length;//�����еĴ�С
	int count1 = 0;
	//�����������������˼������ˣ����������������˼ȶ��ķ�Χ����ô������ѭ���������´������ֵ�ǻ���������

	//�ж��Ƿ������д���
	if (p->length != 0) {
		printf("�������У������ظ�������\n");
		return;
	}
	printf("���������봴�������еĴ�С��");
	scanf("%d", &length);
	if (length <= 0) {
		printf("����ʧ�ܣ����ز˵���\n");
		return;
	}
	printf("�������������У�����-1���ֶ��˳�����");
	for (int i = 0; i < 100; i++) {
		scanf("%d", &p->arr[i]);
		count1++;
		if (p->arr[i] == -1) {
			printf("�������룡\n");
			p->length += count1-1;
			return;
		}
		if (count1 >= length) {//������ĸ��������˸����ķ�Χ
			while (getchar() != '\n') {//��getchar���պ�����������ֱ�����յ����з�
				;//���������֧��ѭ��
			}
			break;//����������������ѭ��
		}
	}
	p->length = length;
	printf("¼��ɹ���\n");
}

//2.���˳���
void f2(Sq* p, int count) {
	if (!(f0(count))) //���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return;
	int count1 = 0;//������������ӡһ�μ�һ����������10��ʱ��ͻ��У��ﵽһ��ֻ��ӡʮ�����ֵ�Ч��
	printf("��ǰ�������ǣ�\n");
	for (int i = 0; i < p->length; i++) {
		printf("%2d ", p->arr[i]);
		count1++;
		if (count1 == 10) {
			printf("\n");
			count1 = 0;//����count��������һ�ż�������
		}
	}
	printf("\n");
	printf("----------------------\n");//���У���һ���ǲ˵�
}

//3.����ĳԪ��
void f3(Sq* p, int count) {
	if (!(f0(count)))//���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return;
	printf("������������ҵ�Ԫ�أ�\n");
	int n;
	scanf("%d", &n);//������ҵ�Ԫ��
	for (int i = 0; i < p->length; i++) {//�����������Ԫ��
		if (n == p->arr[i]) {
			printf("�ҵ��ˣ��±��ǣ�%d\n", i);
			return;
		}
	}
	printf("��������û�д�Ԫ�أ�\n");
}

//4.��ż������
//������ǰż���ں󣬲����Ǵ�С˳��
void  f4(Sq* p, int count) {
	if (!(f0(count)))//���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return;
	int* p1 = &p->arr[0];//�����ͷָ�����˳���ĵ�һ��Ԫ��λ��
	int* p2 = &p->arr[p->length - 1];//�����βָ�����˳�������һ��Ԫ��λ��
	for (int i = 0; i < p->length; i++) {
		if ((*p1) % 2 == 0) {//��һ������������һ��Ԫ���Ǹ�ż���������ַ��������
			if ((*p2) % 2 != 0) {//�����һ��Ԫ���Ǹ�����
				//��ô�ͽ������������������ң�ͷָ������ƶ�һ��βָ����ǰ�ƶ�һ��
				int tmp = *p1;
				*p1 = *p2;
				*p2 = tmp;
				p1++;
				p2--;
			}
			else {//�����һ��Ԫ���Ǹ�ż������ô���һ��ż������Ҫ������ͷָ������ƶ�һ��ֱ������һ������
				p2--;
			}
		}
		else {//�ڶ�������������һ��Ԫ���������������ַ����������
			if ((*p2) % 2 == 0) {//�����һ��Ԫ����ż�����������ǵ�����״̬�����Բ���Ҫ������ֻ���ƶ�ָ��
				p1++;//ͷָ�����һ��
				p2--;//βָ��ǰ��һ��
			}
			else {//�����һ��Ԫ����������ֻ��βָ����ǰ�ƶ�ֱ�����Ǹ�ż��
				p1++;
			}
		}
		if (p1 >= p2)//ѭ���˳���������ʱ����ָ������������һ��˵�������Ѿ��������
			break;//����ѭ��
	}
	int count1 = 0;//���������ж��ٸ������������ֿ���ӡ������ż��
	for (int i = 0; i < p->length; i++) {//�������У��ó��м�������
		if (p->arr[i] % 2 != 0) {
			count1++;
		}
	}
	printf("����ɹ���\n");
	printf("����Ϊ��");
	for (int i = 0; i < count1; i++) {//��ӡ����
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	printf("ż��Ϊ��");
	for (int i = count1; i < p->length; i++) {//��ӡż��
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	printf("����������Ϊ��\n");
	//��ӡ��������
	int count2 = 0;//������������ӡһ�μ�һ����������10��ʱ��ͻ��У��ﵽһ��ֻ��ӡʮ�����ֵ�Ч��
	for (int i = 0; i < p->length; i++) {
		printf("%2d ", p->arr[i]);
		count2++;
		if (count2 == 10) {
			printf("\n");
			count2 = 0;
		}
	}
	printf("\n");
	printf("----------------------\n");//���У���һ���ǲ˵�
}

//5.�ж϶ԳƷ�
void f5(Sq* p, int count) {
	if (!(f0(count)))//���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return;
	for (int i = 0; i < (p->length) / 2; i++) {//��Ϊ������ͷ��β����һ��Ƚϣ����Դ�������
		if (p->arr[i] != p->arr[p->length - 1 - i]) {
			printf("���Գƣ�\n");
			return;
		}
	}
	printf("�Գƣ�\n");
}
//6.��������
void f6(Sq* p, int count) {
	if (!(f0(count)))//���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return;
	int num;//�������еĴ�С
	printf("������Ҫ�������еĴ�С��");
	scanf("%d", &num);
	if (num <= 0) {//�ж�Ҫ��������д�С�Ƿ񲻺���
		printf("����ʧ�ܣ����ز˵���\n");
		return;
	}
	printf("������Ҫ���������Ԫ�أ�");
	int count1=p->length;//����
	for (int i = p->length; i < p->length + num; i++) {
		scanf("%d", &p->arr[i]);//����Ҫ���������
		count1++;
		if (count1 >= p->length+num) {//������ĸ��������˸����ķ�Χ
			while (getchar() != '\n') {//��getchar���պ�����������ֱ�����յ����з�
				;//���������֧��ѭ��
			}
			break;//����������������ѭ��
		}
	}
	p->length += num;//�������еĳ���
	printf("��ӳɹ���\n");
}

//7.�鲢����
Sq f7(Sq* p, int count) {
	if (!(f0(count)))//���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return *p;//��Ϊ���������Ǳ��и��ṹ�����p���ձ��������ص������У����Ե��и�����ֵ����Ϊ����û�й鲢������ֱ�ӷ���ԭ����

	printf("��ע�⣺��ȷ�ϵ�ǰ���������������\n*1.ȷ�ϼ���*\n*0.���ز˵�*\n�����룺");
	int intput;
	scanf("%d", &intput);
	if (intput == 0)
		return *p;//��Ϊ���������Ǳ��и��ṹ�����p���ձ��������ص������У����Ե��и�����ֵ����Ϊ����û�й鲢������ֱ�ӷ���ԭ����

	printf("��Ǹ������ֻ��һ�����У������½�һ��˳�����У�\n");
	printf("�½����У�");
	Sq q;//�½�һ���ṹ��������������ڶ�������
	q.length = 0;//��f1()��ʾ��ǰ����ṹ��û������
	f1(&q);//��������
	printf("���Ժ�...\n");

	//�ж�ԭ�����Ƿ��Ǵ�С�������е�
	for (int i = 1; i < p->length; i++) {
		if (p->arr[i - 1] <= p->arr[i]) {
			;//����䣬���������������Ҫ��ʲô��������Ÿ�����䣬����������ִ��i++
		}
		else {
			printf("�Բ���ԭ���в���һ��˳�����в��ܽ��й鲢��\n");
			return *p;//��Ϊ���������Ǳ��и��ṹ�����p���ձ��������ص������У����Ե��и�����ֵ����Ϊ����û�й鲢������ֱ�ӷ���ԭ����
		}
	}
	//�ж��½������Ƿ��Ǵ�С�������е�
	for (int i = 1; i < q.length; i++) {
		if (q.arr[i - 1] <= q.arr[i]) {
			;//����䣬���������������Ҫ��ʲô��������Ÿ�����䣬����������ִ��i++
		}
		else {
			printf("�Բ��������в���һ��˳�����в��ܽ��й鲢��\n");
			return *p;//��Ϊ���������Ǳ��и��ṹ�����p���ձ��������ص������У����Ե��и�����ֵ����Ϊ����û�й鲢������ֱ�ӷ���ԭ����
		}
	}

	Sq new;//�½�һ���ṹ��������������鲢���������
	new.length = p->length + q.length;//�鲢������г������������еĳ���֮��
	//���������й鲢
	for (int i = 0; i < new.length; i++) {
		if (i < p->length)
			new.arr[i] = p->arr[i];
		if (i >= p->length)
			new.arr[i] = q.arr[i - (p->length)];//i - (p->length)��һ���־ʹ�����i�Ǵӿ�ʼ��
	}
	//����ð��������������鲢���������
	for (int i = 0; i < new.length - 1; i++) {
		for (int j = 0; j < new.length - 1 - i; j++) {
			if (new.arr[j] > new.arr[j + 1]) {
				int tmp = new.arr[j];
				new.arr[j] = new.arr[j + 1];
				new.arr[j + 1] = tmp;
			}
		}
	}
	printf("�鲢��������У�\n");
	int count1 = 0;//������������ӡһ�μ�һ����������10��ʱ��ͻ��У��ﵽһ��ֻ��ӡʮ�����ֵ�Ч��
	for (int i = 0; i < new.length; i++) {
		printf("%2d ", new.arr[i]);
		count1++;
		if (count1 == 10) {
			printf("\n");
			count1 = 0;
		}
	}
	printf("\n");
	printf("----------------------\n");//���У���һ���ǲ˵�
	return new;//����������
}
//8.����
void f8(Sq* p, int count) {
	if (!(f0(count)))//���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return;
	//������ð������
	for (int i = 0; i < p->length - 1; i++) {
		for (int j = 0; j < p->length - 1 - i; j++) {
			if (p->arr[j] > p->arr[j + 1]) {
				int tmp = p->arr[j];
				p->arr[j] = p->arr[j + 1];
				p->arr[j + 1] = tmp;
			}
		}
	}
	printf("������ɣ����������У�\n");
	int count1 = 0;//������������ӡһ�μ�һ����������10��ʱ��ͻ��У��ﵽһ��ֻ��ӡʮ�����ֵ�Ч��
	for (int i = 0; i < p->length; i++) {
		printf("%2d ", p->arr[i]);
		count1++;
		if (count1 == 10) {
			printf("\n");
			count1 = 0;
		}
	}
	printf("\n");
	printf("----------------------\n");//���У���һ���ǲ˵�
}
//9.ɾ��ĳ����
void f9(Sq* p, int count) {
	if (!(f0(count)))//���ж��Ƿ��Ǹ����б��Ǿͷ��ز˵������Ǿ����²���
		return;
	printf("������Ҫɾ����Ԫ�ظ�����");
	int num;//Ҫɾ����Ԫ�ظ���
	int index;//Ҫɾ�������е�ͷԪ�ص��±�
	scanf("%d", &num);
	if (num == p->length) {//���ɾ��������Ԫ�ظ���һ����Ҳ����ȫ��ɾ���Ļ�
		for (int i = 0; i < p->length; i++) {
			p->arr[i] = p->arr[i + num];//������Ŀ�ֵ��������
		}
		p->length -= num;//ɾ������Ҫ�����ȼ���
		printf("ɾ���ɹ����밴2����鿴��\n");
		return *p;
	}
	else if (num < 1) {
		printf("û��Ҫɾ�������У����ز˵���\n");
		return;
	}
	else if (num == 1) {
		printf("������Ҫɾ����Ԫ���±꣺");
		scanf("%d", &index);
		if (index > p->length - 1) {//�ж�Ҫɾ����һ��Ԫ���Ƿ����
			printf("û�и�Ԫ�أ����ز˵���\n");
				return;
		}
		for (int i = index; i <= p->length - 1; i++) {
			p->arr[i] = p->arr[i + 1];
		}
		p->length--;
		printf("ɾ���ɹ����밴2����鿴��\n");
	}
	else if(num>p->length){//���Ҫɾ����Ԫ�ش���������Ԫ�أ��ǾʹӸ�����λ�����ɾ��ֱ�����һ��Ԫ��
		printf("������Ҫɾ�����еĿ�ʼԪ���±꣺");
		scanf("%d", &index);
		for (int i = index; i < p->length; i++) {
			p->arr[index] = p->arr[index + num];
		}
		p->length -= index;//����ֱ�Ӽ�ȥnum����Ϊ�´�������±꿪ʼ������Ԫ�ز�û��num��ô��
		//���磺����num=5�������ܹ��Ͳ�5��Ԫ�أ�Ȼ�����뿪ʼɾ�����±�3���������±�3��Ԫ�ص�ĩβ��û�й�5����
		//������ʵ��ֻɾ���������������Գ���Ҳ����2�����Ǽ���5
		printf("ɾ���ɹ����밴2����鿴��\n");
	}
	else {//Ҫɾ����Ԫ�ظ�������1С�����г���ʱ
		printf("������Ҫɾ����Ԫ���±꣺");
		scanf("%d", &index);
		if (index + num > p->length) {//����Ӹ���λ�ÿ�ʼɾ�������ĸ���ʱ��Ԫ�ز���
			//���繲�����Ԫ�أ�����ɾ������3�������±�λ��3����Ҫɾ��λ��3�ͺ��������Ԫ�أ����Ǻ���ֻ��һ��Ԫ�ش���
			//���Ի���ֻɾ����ǰλ�õ�ĩβ
			for (int i = index; i < p->length; i++) {
				p->arr[index] = p->arr[index + num];
			}
			p->length -= index;
			printf("ɾ���ɹ����밴2����鿴��\n");
			return;
		}
		else {
			for (int i = index; i < index + num; i++) {//�����ѭ������������Ҫɾ���ĵط�
				p->arr[i] = p->arr[i + num];
			}
			p->length -= num;
			printf("ɾ���ɹ����밴2����鿴��\n");
			return;
		}
	}
	return;
}