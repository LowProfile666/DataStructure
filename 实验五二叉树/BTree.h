#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define ElemType char
#define MAXSIZE 100

//顺序存储结构二叉树
typedef ElemType BTree[MAXSIZE];//定义一个数组类型的别名，这个数组类型是:ElemType [MAXSIZE]
BTree bt;//定义的是一个数组，相当于： ElemType bt[MAXSIZE];
int btlength;//数组长度

//链式存储结构二叉树
typedef struct LinkTree {
	ElemType data;
	struct LinkTree* left;
	struct LinkTree* right;
}LTreeNode, * LTree;
LTree Lt;


//顺序存储函数声明
//适用于完全二叉树
void menu();								//主菜单
void menu1();								//顺序菜单
void InitTree();							//初始化树
void InsertTree(ElemType num);				//插入
void Print();								//打印
void DeleteTree(int index);					//删除
void Relation();							//关系
void UpdataTree(int index, ElemType elem);	//修改
void VisitTree();							//遍历

//链式
void menu2();								//链式菜单
void InitLtree();							//初始化
void PrintLtree(LTree Lt1);					//打印
void InsertNode(ElemType elem1, ElemType elem2);//插入
void PreOrder(LTree Lt1);					//前序遍历
void InOrder(LTree Lt1);					//中序遍历
void PostOrder(LTree Lt1);					//后续遍历
void DeleteNode(ElemType elem1);			//删除
void LTreeRelation(ElemType elem);			//关系
void LTreeUpdata(ElemType elem1, ElemType elem2);//修改
