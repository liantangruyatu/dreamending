#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXnum 100					//最大顶点数
#define MAXint 32767				//表示极大值
int visited[MAXnum];				//定义辅助数组

//定义队列存储结构
typedef struct {
	int *base;
	int front;
	int rear;
} SqQueue;

//初始化队列
int InitQueue(SqQueue *Q) {
	Q->base = (int *)malloc(MAXint);
	if (Q->base == NULL)
		return 0;
	Q->front = Q->rear = 0;
	return 1;
}

//入队
int EnQueue(SqQueue *Q, int e) {
	if (Q->rear + 1 == Q->rear)
		return 0;   //满队
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % 10;
	return 1;
}

//出队
int DeQueue(SqQueue *Q, int *e) {
	if (Q->front == Q->rear)
		return 0;   //队空
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % 10;
	return 1;
}

//判断队列是否为空
int QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return 1;
	return 0;
}

/*-----------------------分割线--------------------------*/

//图的邻接矩阵储存
typedef struct {
	char vexs[MAXnum];
	int arcs[MAXnum][MAXnum];
	int vexnum, arcnum;
} AMGraph;

//定位顶点位置
int LocateVex(AMGraph &G, char v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
}

//邻接矩阵表示法创建无向网
int CreateUDN_1(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//初始化
	printf("请输入顶点数和边数：");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //输入定点数和边数
	printf("请输入%d个顶点值: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //为顶点表赋值
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //初始化边的权值为极大值MaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = MAXint;
	//两点之间的边赋权
	for (k = 0; k < (*G).arcnum; k++) {
		printf("请输入两点及其之间权值：");
		scanf(" %c%c%d", &v1, &v2, &w); //输入两个顶点及其之间权值
		ii = LocateVex(*G, v1);          //定位v1顶点的权值
		jj = LocateVex(*G, v2);         //定位v2顶点的权值
		(*G).arcs[ii][jj] = w;            //该顶点到另一个顶点的权值
		(*G).arcs[jj][ii] = (*G).arcs[ii][jj]; //无向图里另一个顶点到该顶点的权值
	}
	return 1;
}

//邻接矩阵表示法创建无向图
int CreateUDN_2(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//初始化
	printf("请输入顶点数和边数：");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //输入定点数和边数
	printf("请输入%d个顶点值: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //为顶点表赋值
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //初始化边的权值为极大值MaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = 0;
	//两点之间的边赋权
	for (k = 0; k < (*G).arcnum; k++) {
		printf("请输入两点及其之间权值：");
		scanf(" %c%c", &v1, &v2); //输入两个顶点及其之间权值
		ii = LocateVex(*G, v1);          //定位v1顶点的权值
		jj = LocateVex(*G, v2);         //定位v2顶点的权值
		(*G).arcs[ii][jj] = 1;            //该顶点到另一个顶点的权值
		(*G).arcs[jj][ii] = (*G).arcs[ii][jj]; //无向图里另一个顶点到该顶点的权值
	}
	return 1;
}

//邻接矩阵表示法创建有向网
int CreateUDN_3(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//初始化
	printf("请输入顶点数和边数：");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //输入定点数和边数
	printf("请输入%d个顶点值: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //为顶点表赋值
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //初始化边的权值为极大值MaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = MAXint;
	//两点之间的边赋权
	for (k = 0; k < (*G).arcnum; k++) {
		printf("请输入两点及其之间权值：");
		scanf(" %c%c%d", &v1, &v2, &w); //输入两个顶点及其之间权值
		ii = LocateVex(*G, v1);          //定位v1顶点的权值
		jj = LocateVex(*G, v2);         //定位v2顶点的权值
		(*G).arcs[ii][jj] = w;            //该顶点到另一个顶点的权值
//		(*G).arcs[jj][ii]=(*G).arcs[ii][jj];   //无向图里另一个顶点到该顶点的权值
	}
	return 1;
}

//邻接矩阵表示法创建有向图
int CreateUDN_4(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//初始化
	printf("请输入顶点数和边数：");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //输入定点数和边数
	printf("请输入%d个顶点值: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //为顶点表赋值
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //初始化边的权值为极大值MaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = 0;
	//两点之间的边赋权
	for (k = 0; k < (*G).arcnum; k++) {
		printf("请输入两点及其之间权值：");
		scanf(" %c%c", &v1, &v2); //输入两个顶点及其之间权值
		ii = LocateVex(*G, v1);          //定位v1顶点的权值
		jj = LocateVex(*G, v2);         //定位v2顶点的权值
		(*G).arcs[ii][jj] = 1;            //该顶点到另一个顶点的权值
//		(*G).arcs[jj][ii]=(*G).arcs[ii][jj];   //无向图里另一个顶点到该顶点的权值
	}
	return 1;
}



//获得第v个顶点的第一邻接点
int FirstAdjVex(AMGraph G, int v) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.arcs[v][i])
			return i;
	return -1;
}

//获得第v个顶点相对于第w个邻接点的下一个邻接点
int NextAdjVex(AMGraph G, int v, int w) {
	for (int i = w + 1; i < G.vexnum; i++)
		if (G.arcs[v][i])
			return i;
	return -1;
}

void DFS_AM(AMGraph G, int v) {
	printf("%c", G.vexs[v]);   //输出该顶点
	visited[v] = 1;      //在辅助数组里标志该顶点已被访问过
	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) //继续查找邻接点
		if (!visited[w])
			DFS_AM(G, w); //递归调用
}

//邻接矩阵表示图的深度优先遍历
void DFS_AMG(AMGraph G, int v) {
	//初始化辅助数组
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	//开始遍历
	printf("%c", G.vexs[v]);  //输出入口顶点
	visited[v] = 1;     //将入口顶点的位置在辅助数组里标志为1，下一次遍历将不会被访问
	for (int w = 0; w < G.vexnum;
	        w++) //在邻接矩阵图的第v行里搜寻vexs[v]的邻接点——矩阵里值为1且在辅助数组里不为1的那个邻接点
		if ((G.arcs[v][w] != 32767) && (!visited[w]))
			DFS_AM(G, w);
}


int firstVEX(AMGraph G, int u) {
	//在邻接矩阵u行0列开始遍历，如果找到不等于无穷的，
//并且没有访问过的就返回列的下标，否则就返回无穷
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[u][i] != 32767 && visited[i] == 0) {
			return i;
		}
	}
	return 32767;
}

int nextVEX(AMGraph G, int w, int u) {
	//在邻接矩阵u行w+1列开始遍历，如果找到不等于无穷的，
//并且没有访问过的就返回列的下标，否则就返回无穷
	for (int i = w + 1; i < G.vexnum; i++) {
		if (G.arcs[u][i] != 32767 && visited[i] == 0) {
			return i;
		}
	}
	return 32767;
}

void BFS_AMG(AMGraph G, int i) {
	//随机选一个顶点下标，这里为0
	cout << G.vexs[i] << " ";		//输出i下标在顶点表的值
	visited[i] = 1;				//辅助数值对应下标i的值置为1
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, i);				//i为矩阵中顶点的行下标，让它入队(顶点表的下标和矩阵的列下标，行下标一致，本算法中说谁的下标都一样)
	while (Q.rear != Q.front) {	//队不为空
		int u = 0;			//接收矩阵中顶点的行下标，因为是邻接矩阵
		DeQueue(&Q, &u);			//出队并让u接收矩阵中顶点的行下标
		for (int w = firstVEX(G, u); w != 32767; w = nextVEX(G, w, u)) {
			//注意在一次循环中u不变
			if (!visited[w]) {
				cout << G.vexs[w] << " ";
				visited[w] = 1;
				EnQueue(&Q, w);
			}
		}
	}
}

void MinPrim(AMGraph G) {
	int min, i, j, k;
	int adjvex[20]; // 保存相关顶点的下标
	int lowcost[20]; // 保存相关顶点间边的权值
	lowcost[0] = 0;  // 初始化第一个权值为0，即v0加入生成树
	adjvex[0] = 0; // 初始化第一个顶点下标为0

	for (i = 1; i < G.vexnum; i++) {  // 循环除下标为0外的全部顶点
		lowcost[i] = G.arcs[0][i];  // 将v0顶点与之右边的权值存入数组
		adjvex[i] = 0; // 初始化都为v0的下标
	}

	cout << "最小生成树为:\n";
	for (i = 1; i < G.vexnum; i++) {
		min = 65535; //初始化最小权值
		j = 1;
		k = 0;
		while (j < G.vexnum) { // 循环全部顶点
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];  // 让当前权值变为最小值
				k = j;  // 将当前最小值的下标存入k
			}
			j++;
		}
		cout << G.vexs[adjvex[k]] << "与" << G.vexs[k] << "的权值为:" << lowcost[k] <<
		     endl; // 打印当前顶点和连接顶点权值最小的边及权值
		lowcost[k] = 0;             // 将当前顶点的权值设置为0，表示此顶点已经完成任务
		for (j = 1; j < G.vexnum; j++) {  // 循环所有顶点
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j]) { // 如果下标为k顶点各边权值小于当前这些顶点未被加入生成树权值
				lowcost[j] = G.arcs[k][j]; // 将较小的权值存入lowcost相应的位置
				adjvex[j] = k;   // 将下标为k的顶点存入adjvex
			}
		}
	}
}

/*-----------------------分割线--------------------------*/


//图的邻接表储存
typedef struct ArcNode {
	int adjvex;						//该边指向顶点的位置
	struct ArcNode *nextarc;		//指向下一条边的指针
	int info;						//和边有关的信息，如权值
} ArcNode;

typedef struct VNode {
	char data;						//储存顶点名字或一些相关信息
	ArcNode *firstarc;				//指向链表中第一个结点
} VNode, AdjList[MAXnum];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
} ALGraph;

//在顶点表里定位顶点的位置
int LocateVex(ALGraph G, char v) { //顶点名称v
	for (int i = 0; i < G.vexnum; i++)
		if (G.vertices[i].data == v)
			return i;
}

//邻接表创建无向网
int CreateUDG_1(ALGraph *G) {
	printf("请输入顶点数和边数：");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //输入顶点数和边数
	printf("请输入%d顶点名称：", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //两个顶点
		printf("请输入连接那条边的两个顶点：");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //定位两个顶点的位置
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;       //将边的另一个顶点位置设置为j
		scanf("%d", &p1->info);
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表
		//无向网另一顶点
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->nextarc = (*G).vertices[j].firstarc;
		p2->adjvex = i;
		p2->info = p1->info;
		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}

//邻接表创建无向图
int CreateUDG_2(ALGraph *G) {
	printf("请输入顶点数和边数：");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //输入顶点数和边数
	printf("请输入%d顶点名称：", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //两个顶点
		printf("请输入连接那条边的两个顶点：");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //定位两个顶点的位置
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;       //将边的另一个顶点位置设置为j
		p1->info = 1;         //权值
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表
		//无向网另一顶点
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->nextarc = (*G).vertices[j].firstarc;
		p2->adjvex = i;
		p2->info = 1;
		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}

//邻接表创建有向网
int CreateUDG_3(ALGraph *G) {
	printf("请输入顶点数和边数：");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //输入顶点数和边数
	printf("请输入%d顶点名称：", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //两个顶点
		printf("请输入连接那条边的两个顶点：");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //定位两个顶点的位置
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;       //将边的另一个顶点位置设置为j
		scanf("%d", &p1->info);
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表
		//无向网另一顶点
//		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
//		p2->nextarc = (*G).vertices[j].firstarc;
//		p2->adjvex = i;
//		p2->info = p1->info;
//		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}

//邻接表创建有向图
int CreateUDG_4(ALGraph *G) {
	printf("请输入顶点数和边数：");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //输入顶点数和边数
	printf("请输入%d顶点名称：", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //两个顶点
		printf("请输入连接那条边的两个顶点：");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //定位两个顶点的位置
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;       //将边的另一个顶点位置设置为j
		p1->info = 1;         //权值
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表
//		//无向网另一顶点
//		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
//		p2->nextarc = (*G).vertices[j].firstarc;
//		p2->adjvex = i;
//		p2->info = 1;
//		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}


//邻接表深度优先遍历
void DFS_AR(ALGraph G, int i) {
	ArcNode *p;     //指向边链表结点指针
	visited[i] = 1; //辅助数组该位置设置为1
	printf("%c", G.vertices[i].data);
	p = G.vertices[i].firstarc;  //指向边链表结点首结点
	while (p) { //指针不为空继续循环
		if (!visited[p->adjvex])
			DFS_AR(G, p->adjvex);
		p = p->nextarc;  //继续指向下一个结点
	}
}

//深度优先遍历基本操作
void DFS_ARC(ALGraph G) {
	//初始化辅助数组
	for (int i = 0; i < G.vexnum; i++) //初始化辅助数组
		visited[i] = 0;
	for (int i = 0; i < G.vexnum; i++) //从第一个顶点作为入口进行遍历
		if (!visited[i])
			DFS_AR(G, i);
}



//广度优先遍历
void BFS_ARC(ALGraph G, int i) {
	ArcNode *p;
	SqQueue Q;
	int e;   //记录出队顶点位置
	//初始化状态数组
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	//初始化队列
	InitQueue(&Q);
	EnQueue(&Q, i);
	printf("%c", G.vertices[i].data);
	visited[i] = 1;
	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &e);
		p = G.vertices[e].firstarc;
		while (p) {
			if (!visited[p->adjvex]) {
				printf("%c", G.vertices[p->adjvex].data);
				visited[p->adjvex] = 1;
				EnQueue(&Q, p->adjvex);
			}
			p = p->nextarc;
		}
	}
}

int main() {
	ALGraph G;
	AMGraph Q;
	int num1, num2;
	printf("请输入建立图的方式\n");
	printf("1.邻接矩阵创建无向网\n");
	printf("2.邻接矩阵创建无向图\n");
	printf("3.邻接矩阵创建有向网\n");
	printf("4.邻接矩阵创建有向图\n");
	printf("5.邻接表创建无向网\n");
	printf("6.邻接表创建无向图\n");
	printf("7.邻接表创建有向网\n");
	printf("8.邻接表创建有向图\n");
ask:
	scanf("%d", &num1);
	switch (num1) {
		case 1:
			CreateUDN_1(&Q);
			break;
		case 2:
			CreateUDN_2(&Q);
			break;
		case 3:
			CreateUDN_3(&Q);
			break;
		case 4:
			CreateUDN_4(&Q);
			break;
		case 5:
			CreateUDG_1(&G);
			break;
		case 6:
			CreateUDG_2(&G);
			break;
		case 7:
			CreateUDG_3(&G);
			break;
		case 8:
			CreateUDG_4(&G);
			break;
		default:
			printf("您输入的数字有误\n");
			goto ask;
			break;
	}
	printf("\n-----请输入需要进行的操作-----\n");
	printf("1.进行广度优先搜索并输出遍历结果\n");
	printf("2.进行深度优先搜索并输出遍历结果\n");
	printf("3.计算图的最小代价生成树\n");
	printf("4.退出程序\n");
	scanf("%d", &num2);
	while (num2 != 4) {
		switch (num2) {
			case 1:
				switch (num1) {
					case 1:
					case 2:
					case 3:
					case 4:
						printf("\n邻接矩阵广度优先遍历结果：");
						BFS_AMG(Q, 0);
						break;
					case 5:
					case 6:
					case 7:
					case 8:
						printf("\n邻接表广度优先遍历结果：");
						BFS_ARC(G, 0);
						break;
				}
				break;
			case 2:
				switch (num1) {
					case 1:
					case 2:
					case 3:
					case 4:
						printf("\n邻接矩阵深度优先遍历结果：");
						DFS_AMG(Q, 2);
						break;
					case 5:
					case 6:
					case 7:
					case 8:
						printf("\n邻接表深度优先遍历结果：");
						DFS_ARC(G);
						break;
				}
				break;

			case 3:
				switch (num1) {
					case 1:
					case 2:
					case 3:
					case 4:
						MinPrim(Q);
						break;
					case 5:
					case 6:
					case 7:
					case 8:
						printf("此功能只有在以邻接矩阵创建图的情况下才可使用，请重新创建\n");
						goto ask;
						break;
				}
				break;
		}
		printf("\n-----请输入需要进行的操作-----\n");
		scanf("%d", &num2);
	}
	return 0;
}