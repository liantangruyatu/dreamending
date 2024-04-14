/*
	Name:������.cpp
	Auther:Ҧɭ��
	data:24/03/24 08:00:00
	Description:�������һϵ�в���
*/
#include <stdio.h>
#include <stdlib.h>
#define status int
#define elemtype float


//��������
typedef struct LNode {
	elemtype data;
	struct LNode *next;
} LNode, *LinkList;


//��������
void InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LinkList));
	L->next = NULL;
}


//��������
int Length(LinkList L) {
	LNode *p = L->next;
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}


//����1_β�巨ʵ�ֵ�����Ĵ���
LinkList TailInsert(LinkList &L) {
	InitList(L);
	LNode *s, *r = L;
	elemtype x;
	printf("�����������ֵ������-1ʱ����\n");
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

//����4.2_ʵ�ֵ�����İ�λ����
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
//�ᵽ������ʵ������֮�٣���Ϊ����2�͹���3��Ҫ�õ��������������λ��
//�����ֲ�����ǰ��get�����������������ԾͰѹ���4.2��������

//����2_ʵ�ֵ�����Ĳ���
void Insert(LinkList &L, int i, float x) {
	LNode *p = Get(L, i - 1);
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
}


//����3_ʵ�ֵ������ɾ��
status Delete(LinkList &L, int i) {
	if (i < 1 || Length(L) < i) {
		printf("ɾ������:ɾ��λ�ò�����\n");
		return 0;
	}
	int j = 1;
	LNode *p = Get(L, i - 1);
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	return 0;
}


//����4.1_ʵ�ֵ�����İ�ֵ����
LNode *Locate(LinkList L, status e) {
	LNode *p = L->next;
	int j = 1;
	//�ӵ�1����㿪ʼ����������Ϊe�Ľ��
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	printf("ֵΪ%f�Ľ���λ��Ϊ%d\n", p->data, j);
	return p;    //�ҵ��󷵻ظý��ָ�룬���򷵻�NULL
}


//����5_ʵ�ֵ��������ʾ
status print(LinkList L) {
	LNode *p = L->next;
	while (p) {
		printf("%.3f ", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}

//����6_�������Ա�ϲ��㷨��ʵ��
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
	printf("������������������������в�����š�������������\n");
	printf("1_ʵ�ִ���������\n");
	printf("2_ʵ�ֵ�����Ĳ���\n");
	printf("3_ʵ�ֵ������ɾ��\n");
	printf("4_ʵ�ֵ�����İ�ֵ����\n");
	printf("5_ʵ�ֵ�����İ�λ����\n");
	printf("6_ʵ�ֵ��������ʾ\n");
	printf("7_�������Ա�ϲ��㷨����ʾ\n");
	printf("8_�˳�����\n");
	printf("������������������������������������������������������������������\n");
	scanf("%d", &num);
	while (num != 8) {
		switch (num) {
			case 1 :
				L = TailInsert(L);
				printf("�����ɹ�\n");
				break;
			case 2:
				printf("��������Ҫ�޸ĵ�λ��\n");
				scanf("%d", &i);
				printf("��������Ҫ�޸ĵ�����\n");
				scanf("%f", &x);
				Insert(L, i, x);
				printf("�޸ĺ�ĵ�����Ϊ:");
				print(L);
				printf("\n");
				break;
			case 3:
				printf("��������Ҫɾ����λ��\n");
				scanf("%d", &i);
				Delete(L, i);
				printf("ɾ����ĵ�����Ϊ:");
				print(L);
				printf("\n");
				break;
			case 4:
				printf("��������Ҫ���ҵ�ֵ\n");
				scanf("%f", &x);
				p = Locate(L, x);
				break;
			case 5:
				printf("��������Ҫ���ҵ�λ��\n");
				scanf("%d", &i);
				q = Get(L, i);
				printf("��%dλ��ֵΪ%f\n", i, q->data);
				break;
			case 6:
				print(L);
				break;
			case 7:
				L = TailInsert(L);
				printf("����L�����ɹ�\n");
				M = TailInsert(M);
				printf("����M�����ɹ�\n");
				Merge(L, M, &N);
				printf("L��M�ϲ���Ϊ:\n");
				print(L);
				printf("\n");
				break;
			case 8:
				break;
		}
		printf("����������в������\n");
		scanf("%d", &num);
	}
	return 0;
}