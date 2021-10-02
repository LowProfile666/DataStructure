#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define ElemType char
#define MAXSIZE 100

//˳��洢�ṹ������
typedef ElemType BTree[MAXSIZE];//����һ���������͵ı������������������:ElemType [MAXSIZE]
BTree bt;//�������һ�����飬�൱�ڣ� ElemType bt[MAXSIZE];
int btlength;//���鳤��

//��ʽ�洢�ṹ������
typedef struct LinkTree {
	ElemType data;
	struct LinkTree* left;
	struct LinkTree* right;
}LTreeNode, * LTree;
LTree Lt;


//˳��洢��������
//��������ȫ������
void menu();								//���˵�
void menu1();								//˳��˵�
void InitTree();							//��ʼ����
void InsertTree(ElemType num);				//����
void Print();								//��ӡ
void DeleteTree(int index);					//ɾ��
void Relation();							//��ϵ
void UpdataTree(int index, ElemType elem);	//�޸�
void VisitTree();							//����

//��ʽ
void menu2();								//��ʽ�˵�
void InitLtree();							//��ʼ��
void PrintLtree(LTree Lt1);					//��ӡ
void InsertNode(ElemType elem1, ElemType elem2);//����
void PreOrder(LTree Lt1);					//ǰ�����
void InOrder(LTree Lt1);					//�������
void PostOrder(LTree Lt1);					//��������
void DeleteNode(ElemType elem1);			//ɾ��
void LTreeRelation(ElemType elem);			//��ϵ
void LTreeUpdata(ElemType elem1, ElemType elem2);//�޸�
