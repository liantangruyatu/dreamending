#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;

//��������Ĵ洢��ʾ
typedef struct BiTNode {      /*�ڵ�ṹ����*/
	char data ;               /*�ڵ�����*/
	struct BiTNode *lchild;
	struct BiTNode *rchild ;  /*ָ��*/
} *BiTree, BiTNode;

typedef BiTree SElemType;

//˳��ջ�Ĵ洢�ṹ
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;

//ջ�ĳ�ʼ��
Status InitStack(SqStack &S) {
	S.base = new SElemType[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//��ջ
Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top = e;
	S.top++;
	return OK;
}

//��ջ
Status Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base)
		return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S) {
	if (S.base == S.top)
		return ERROR;
	return OK;
}

//���򴴽�һ����
void CreateBiTree(BiTree &T) {
	char ch;
	scanf("%c", &ch);
	if (ch == ' ')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//����ݹ����
void XianTraverse(BiTree T) {
	if (T != NULL) {
		printf("%c", T->data);
		XianTraverse(T->lchild);
		XianTraverse(T->rchild);
	}
}

//����ݹ����
void InOrderTraverse(BiTree T) {
	if (T != NULL) {
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
	}
}

//����ݹ����
void HouTraverse(BiTree T) {
	if (T != NULL) {
		HouTraverse(T->lchild);
		HouTraverse(T->rchild);
		printf("%c", T->data);
	}
}

//�ǵݹ����
void InOrderTraversenot(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTree p, q;
	p = T;
	q = new BiTNode;
	while (p != NULL || StackEmpty(S) != 0) {
		if (p != NULL) {
			Push(S, p);
			p = p->lchild;
		} else {
			Pop(S, q);
			printf("%c", q->data);
			p = q->rchild;
		}
	}
}

//��������������
int Depth(BiTree T) {
	if (T == NULL)
		return 0;
	else {
		int m = Depth(T->lchild);
		int n = Depth(T->lchild);
		if (m > n)
			return (m + 1);
		else
			return (n + 1);
	}
}

//��������
Status NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int main() {
	printf("��������ʽ������������ս����' '����\n");
	BiTree T;
	CreateBiTree(T);//������ݹ鴴�������һ�ö�����T1
	printf("�����ɹ�!\n");
//��Ҫ����ΪʲôҪ�ѽ��������������⣬��Ϊ����ѭ��������������ܣ��ˣ��У�
	int de, nc, num;
	printf("-------����������-------\n");
	printf("1.����ݹ����������\n");
	printf("2.����ݹ����������\n");
	printf("3.����ݹ����������\n");
	printf("4.����ǵݹ����������\n");
	printf("5.չʾ�������߶�\n");
	printf("6.չʾ�ö������������\n");
	printf("7.�˳�����\n");
	printf("-----------------------\n");
	scanf("%d", &num);
	while (num != 7) {
		switch (num) {
			case 1:
				printf("���������");
				XianTraverse(T);//����ݹ�����������е�ÿһ���ڵ㣻
				break;
			case 2:
				printf("\n���������");
				InOrderTraverse(T);//����ݹ�����������е�ÿһ���ڵ�
				break;
			case 3:
				printf("\n���������");
				HouTraverse(T);//����ݹ�����������е�ÿһ���ڵ�
				break;
			case 4:
				printf("\n����ǵݹ������");
				InOrderTraversenot(T);//�÷ǵݹ�ķ�������������е�ÿһ���ڵ㣨����
				printf("\n");
				break;
			case 5:
				de = Depth(T);
				printf("�ö������ĸ߶�Ϊ��%d\n", de);
				break;
			case 6:
				nc = NodeCount(T);
				printf("�ö������Ľ������Ϊ��%d\n", nc);
				break;
		}
		printf("\n-------����������-------\n");
		scanf("%d", &num);
	}
	printf("\n-------�������˳�-------\n");
	return 0;
}