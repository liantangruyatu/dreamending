/*
	Name:单链表.cpp
	Auther:姚森宝
	data:24/03/24 08:00:00
	Description:单链表的一系列操作
*/
#include <stdio.h>
#include <stdlib.h>
#define status int
#define elemtype float


//定义链表
typedef struct LNode {
	elemtype data;
	struct LNode *next;
} LNode, *LinkList;


//创建链表
void InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LinkList));
	L->next = NULL;
}


//求单链表长度
int Length(LinkList L) {
	LNode *p = L->next;
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}


//功能1_尾插法实现单链表的创建
LinkList TailInsert(LinkList &L) {
	InitList(L);
	LNode *s, *r = L;
	elemtype x;
	printf("请输入链表的值，输入-1时结束\n");
	scanf("%f", &x);
	while (x != -1) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%f", &x);
	}
	r->next = NULL;
	return L;
}

//功能4.2_实现单链表的按位查找
LNode *Get(LinkList L, int i) {
	int j = 1;
	LNode *p = L->next;
	if (i == 0) {
		return L;
	}
	if (i < 1) {
		return NULL;
	}
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//提到这里属实是无奈之举，因为功能2和功能3都要用到这个函数来查找位置
//而我又不想提前对get函数进行声明，所以就把功能4.2扔这来了

//功能2_实现单链表的插入
void Insert(LinkList &L, int i, float x) {
	LNode *p = Get(L, i - 1);
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
}


//功能3_实现单链表的删除
status Delete(LinkList &L, int i) {
	if (i < 1 || Length(L) < i) {
		printf("删除错误:删除位置不存在\n");
		return 0;
	}
	int j = 1;
	LNode *p = Get(L, i - 1);
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	return 0;
}


//功能4.1_实现单链表的按值查找
LNode *Locate(LinkList L, status e) {
	LNode *p = L->next;
	int j = 1;
	//从第1个结点开始查找数据域为e的结点
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	printf("值为%f的结点的位置为%d\n", p->data, j);
	return p;    //找到后返回该结点指针，否则返回NULL
}


//功能5_实现单链表的显示
status print(LinkList L) {
	LNode *p = L->next;
	while (p) {
		printf("%.3f ", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}

//功能6_两个线性表合并算法的实现
void Merge(LinkList L, LinkList M, LinkList *N) {
	LNode *pa, *pb, *pc;
	pa = L->next;
	pb = M->next;
	pc = L;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next;
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = pa ? pa : pb;
		free(M);
	}
}

int main() {
	status num, i;
	elemtype x;
	LinkList L, M, N;
	LNode *p, *q;
	printf("·······请输入需进行操作编号·······\n");
	printf("1_实现创建单链表\n");
	printf("2_实现单链表的插入\n");
	printf("3_实现单链表的删除\n");
	printf("4_实现单链表的按值查找\n");
	printf("5_实现单链表的按位查找\n");
	printf("6_实现单链表的显示\n");
	printf("7_两个线性表合并算法的显示\n");
	printf("8_退出程序\n");
	printf("·································\n");
	scanf("%d", &num);
	while (num != 8) {
		switch (num) {
			case 1 :
				L = TailInsert(L);
				printf("创建成功\n");
				break;
			case 2:
				printf("请输入需要修改的位数\n");
				scanf("%d", &i);
				printf("请输入需要修改的数字\n");
				scanf("%f", &x);
				Insert(L, i, x);
				printf("修改后的单链表为:");
				print(L);
				printf("\n");
				break;
			case 3:
				printf("请输入需要删除的位置\n");
				scanf("%d", &i);
				Delete(L, i);
				printf("删除后的单链表为:");
				print(L);
				printf("\n");
				break;
			case 4:
				printf("请输入需要查找的值\n");
				scanf("%f", &x);
				p = Locate(L, x);
				break;
			case 5:
				printf("请输入需要查找的位数\n");
				scanf("%d", &i);
				q = Get(L, i);
				printf("第%d位的值为%f\n", i, q->data);
				break;
			case 6:
				print(L);
				break;
			case 7:
				L = TailInsert(L);
				printf("链表L创建成功\n");
				M = TailInsert(M);
				printf("链表M创建成功\n");
				Merge(L, M, &N);
				printf("L与M合并后为:\n");
				print(L);
				printf("\n");
				break;
			case 8:
				break;
		}
		printf("请输入需进行操作编号\n");
		scanf("%d", &num);
	}
	return 0;
}