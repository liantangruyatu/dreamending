#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;

//二叉链表的存储表示
typedef struct BiTNode {      /*节点结构声明*/
	char data ;               /*节点数据*/
	struct BiTNode *lchild;
	struct BiTNode *rchild ;  /*指针*/
} *BiTree, BiTNode;

typedef BiTree SElemType;

//顺序栈的存储结构
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;

//栈的初始化
Status InitStack(SqStack &S) {
	S.base = new SElemType[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//入栈
Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top = e;
	S.top++;
	return OK;
}

//出栈
Status Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base)
		return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack S) {
	if (S.base == S.top)
		return ERROR;
	return OK;
}

//先序创建一棵树
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

//先序递归输出
void XianTraverse(BiTree T) {
	if (T != NULL) {
		printf("%c", T->data);
		XianTraverse(T->lchild);
		XianTraverse(T->rchild);
	}
}

//中序递归输出
void InOrderTraverse(BiTree T) {
	if (T != NULL) {
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
	}
}

//后序递归输出
void HouTraverse(BiTree T) {
	if (T != NULL) {
		HouTraverse(T->lchild);
		HouTraverse(T->rchild);
		printf("%c", T->data);
	}
}

//非递归遍历
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

//计算二叉树的深度
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

//求结点总数
Status NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int main() {
	printf("请以先序方式输入二叉树，空结点用' '代替\n");
	BiTree T;
	CreateBiTree(T);//用先序递归创建下面的一棵二叉树T1
	printf("创建成功!\n");
//不要问我为什么要把建立二叉树放在这，因为放在循环里面根本不！能！运！行！
	int de, nc, num;
	printf("-------请输入需求-------\n");
	printf("1.先序递归遍历二叉树\n");
	printf("2.中序递归遍历二叉树\n");
	printf("3.后序递归遍历二叉树\n");
	printf("4.中序非递归遍历二叉树\n");
	printf("5.展示二叉树高度\n");
	printf("6.展示该二叉树结点总数\n");
	printf("7.退出程序\n");
	printf("-----------------------\n");
	scanf("%d", &num);
	while (num != 7) {
		switch (num) {
			case 1:
				printf("先序输出：");
				XianTraverse(T);//先序递归输出二叉树中的每一个节点；
				break;
			case 2:
				printf("\n中序输出：");
				InOrderTraverse(T);//中序递归输出二叉树中的每一个节点
				break;
			case 3:
				printf("\n后序输出：");
				HouTraverse(T);//后序递归输出二叉树中的每一个节点
				break;
			case 4:
				printf("\n中序非递归输出：");
				InOrderTraversenot(T);//用非递归的方法遍历输出树中的每一个节点（中序）
				printf("\n");
				break;
			case 5:
				de = Depth(T);
				printf("该二叉树的高度为：%d\n", de);
				break;
			case 6:
				nc = NodeCount(T);
				printf("该二叉树的结点总数为：%d\n", nc);
				break;
		}
		printf("\n-------请输入需求-------\n");
		scanf("%d", &num);
	}
	printf("\n-------程序已退出-------\n");
	return 0;
}