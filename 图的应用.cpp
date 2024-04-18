#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXnum 100					//��󶥵���
#define MAXint 32767				//��ʾ����ֵ
int visited[MAXnum];				//���帨������

//������д洢�ṹ
typedef struct {
	int *base;
	int front;
	int rear;
} SqQueue;

//��ʼ������
int InitQueue(SqQueue *Q) {
	Q->base = (int *)malloc(MAXint);
	if (Q->base == NULL)
		return 0;
	Q->front = Q->rear = 0;
	return 1;
}

//���
int EnQueue(SqQueue *Q, int e) {
	if (Q->rear + 1 == Q->rear)
		return 0;   //����
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % 10;
	return 1;
}

//����
int DeQueue(SqQueue *Q, int *e) {
	if (Q->front == Q->rear)
		return 0;   //�ӿ�
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % 10;
	return 1;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return 1;
	return 0;
}

/*-----------------------�ָ���--------------------------*/

//ͼ���ڽӾ��󴢴�
typedef struct {
	char vexs[MAXnum];
	int arcs[MAXnum][MAXnum];
	int vexnum, arcnum;
} AMGraph;

//��λ����λ��
int LocateVex(AMGraph &G, char v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
}

//�ڽӾ����ʾ������������
int CreateUDN_1(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//��ʼ��
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //���붨�����ͱ���
	printf("������%d������ֵ: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //Ϊ�����ֵ
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //��ʼ���ߵ�ȨֵΪ����ֵMaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = MAXint;
	//����֮��ı߸�Ȩ
	for (k = 0; k < (*G).arcnum; k++) {
		printf("���������㼰��֮��Ȩֵ��");
		scanf(" %c%c%d", &v1, &v2, &w); //�����������㼰��֮��Ȩֵ
		ii = LocateVex(*G, v1);          //��λv1�����Ȩֵ
		jj = LocateVex(*G, v2);         //��λv2�����Ȩֵ
		(*G).arcs[ii][jj] = w;            //�ö��㵽��һ�������Ȩֵ
		(*G).arcs[jj][ii] = (*G).arcs[ii][jj]; //����ͼ����һ�����㵽�ö����Ȩֵ
	}
	return 1;
}

//�ڽӾ����ʾ����������ͼ
int CreateUDN_2(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//��ʼ��
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //���붨�����ͱ���
	printf("������%d������ֵ: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //Ϊ�����ֵ
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //��ʼ���ߵ�ȨֵΪ����ֵMaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = 0;
	//����֮��ı߸�Ȩ
	for (k = 0; k < (*G).arcnum; k++) {
		printf("���������㼰��֮��Ȩֵ��");
		scanf(" %c%c", &v1, &v2); //�����������㼰��֮��Ȩֵ
		ii = LocateVex(*G, v1);          //��λv1�����Ȩֵ
		jj = LocateVex(*G, v2);         //��λv2�����Ȩֵ
		(*G).arcs[ii][jj] = 1;            //�ö��㵽��һ�������Ȩֵ
		(*G).arcs[jj][ii] = (*G).arcs[ii][jj]; //����ͼ����һ�����㵽�ö����Ȩֵ
	}
	return 1;
}

//�ڽӾ����ʾ������������
int CreateUDN_3(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//��ʼ��
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //���붨�����ͱ���
	printf("������%d������ֵ: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //Ϊ�����ֵ
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //��ʼ���ߵ�ȨֵΪ����ֵMaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = MAXint;
	//����֮��ı߸�Ȩ
	for (k = 0; k < (*G).arcnum; k++) {
		printf("���������㼰��֮��Ȩֵ��");
		scanf(" %c%c%d", &v1, &v2, &w); //�����������㼰��֮��Ȩֵ
		ii = LocateVex(*G, v1);          //��λv1�����Ȩֵ
		jj = LocateVex(*G, v2);         //��λv2�����Ȩֵ
		(*G).arcs[ii][jj] = w;            //�ö��㵽��һ�������Ȩֵ
//		(*G).arcs[jj][ii]=(*G).arcs[ii][jj];   //����ͼ����һ�����㵽�ö����Ȩֵ
	}
	return 1;
}

//�ڽӾ����ʾ����������ͼ
int CreateUDN_4(AMGraph *G) {
	int i, j, ii, jj, k, w;
	char v1, v2;
	//��ʼ��
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); //���붨�����ͱ���
	printf("������%d������ֵ: ", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; i++)      //Ϊ�����ֵ
		scanf(" %c", &((*G).vexs[i]));
	for (i = 0; i < (*G).vexnum; i++)     //��ʼ���ߵ�ȨֵΪ����ֵMaxInt=32767
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = 0;
	//����֮��ı߸�Ȩ
	for (k = 0; k < (*G).arcnum; k++) {
		printf("���������㼰��֮��Ȩֵ��");
		scanf(" %c%c", &v1, &v2); //�����������㼰��֮��Ȩֵ
		ii = LocateVex(*G, v1);          //��λv1�����Ȩֵ
		jj = LocateVex(*G, v2);         //��λv2�����Ȩֵ
		(*G).arcs[ii][jj] = 1;            //�ö��㵽��һ�������Ȩֵ
//		(*G).arcs[jj][ii]=(*G).arcs[ii][jj];   //����ͼ����һ�����㵽�ö����Ȩֵ
	}
	return 1;
}



//��õ�v������ĵ�һ�ڽӵ�
int FirstAdjVex(AMGraph G, int v) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.arcs[v][i])
			return i;
	return -1;
}

//��õ�v����������ڵ�w���ڽӵ����һ���ڽӵ�
int NextAdjVex(AMGraph G, int v, int w) {
	for (int i = w + 1; i < G.vexnum; i++)
		if (G.arcs[v][i])
			return i;
	return -1;
}

void DFS_AM(AMGraph G, int v) {
	printf("%c", G.vexs[v]);   //����ö���
	visited[v] = 1;      //�ڸ����������־�ö����ѱ����ʹ�
	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) //���������ڽӵ�
		if (!visited[w])
			DFS_AM(G, w); //�ݹ����
}

//�ڽӾ����ʾͼ��������ȱ���
void DFS_AMG(AMGraph G, int v) {
	//��ʼ����������
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	//��ʼ����
	printf("%c", G.vexs[v]);  //�����ڶ���
	visited[v] = 1;     //����ڶ����λ���ڸ����������־Ϊ1����һ�α��������ᱻ����
	for (int w = 0; w < G.vexnum;
	        w++) //���ڽӾ���ͼ�ĵ�v������Ѱvexs[v]���ڽӵ㡪��������ֵΪ1���ڸ��������ﲻΪ1���Ǹ��ڽӵ�
		if ((G.arcs[v][w] != 32767) && (!visited[w]))
			DFS_AM(G, w);
}


int firstVEX(AMGraph G, int u) {
	//���ڽӾ���u��0�п�ʼ����������ҵ�����������ģ�
//����û�з��ʹ��ľͷ����е��±꣬����ͷ�������
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[u][i] != 32767 && visited[i] == 0) {
			return i;
		}
	}
	return 32767;
}

int nextVEX(AMGraph G, int w, int u) {
	//���ڽӾ���u��w+1�п�ʼ����������ҵ�����������ģ�
//����û�з��ʹ��ľͷ����е��±꣬����ͷ�������
	for (int i = w + 1; i < G.vexnum; i++) {
		if (G.arcs[u][i] != 32767 && visited[i] == 0) {
			return i;
		}
	}
	return 32767;
}

void BFS_AMG(AMGraph G, int i) {
	//���ѡһ�������±꣬����Ϊ0
	cout << G.vexs[i] << " ";		//���i�±��ڶ�����ֵ
	visited[i] = 1;				//������ֵ��Ӧ�±�i��ֵ��Ϊ1
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, i);				//iΪ�����ж�������±꣬�������(�������±�;�������±꣬���±�һ�£����㷨��˵˭���±궼һ��)
	while (Q.rear != Q.front) {	//�Ӳ�Ϊ��
		int u = 0;			//���վ����ж�������±꣬��Ϊ���ڽӾ���
		DeQueue(&Q, &u);			//���Ӳ���u���վ����ж�������±�
		for (int w = firstVEX(G, u); w != 32767; w = nextVEX(G, w, u)) {
			//ע����һ��ѭ����u����
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
	int adjvex[20]; // ������ض�����±�
	int lowcost[20]; // ������ض����ߵ�Ȩֵ
	lowcost[0] = 0;  // ��ʼ����һ��ȨֵΪ0����v0����������
	adjvex[0] = 0; // ��ʼ����һ�������±�Ϊ0

	for (i = 1; i < G.vexnum; i++) {  // ѭ�����±�Ϊ0���ȫ������
		lowcost[i] = G.arcs[0][i];  // ��v0������֮�ұߵ�Ȩֵ��������
		adjvex[i] = 0; // ��ʼ����Ϊv0���±�
	}

	cout << "��С������Ϊ:\n";
	for (i = 1; i < G.vexnum; i++) {
		min = 65535; //��ʼ����СȨֵ
		j = 1;
		k = 0;
		while (j < G.vexnum) { // ѭ��ȫ������
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];  // �õ�ǰȨֵ��Ϊ��Сֵ
				k = j;  // ����ǰ��Сֵ���±����k
			}
			j++;
		}
		cout << G.vexs[adjvex[k]] << "��" << G.vexs[k] << "��ȨֵΪ:" << lowcost[k] <<
		     endl; // ��ӡ��ǰ��������Ӷ���Ȩֵ��С�ı߼�Ȩֵ
		lowcost[k] = 0;             // ����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������
		for (j = 1; j < G.vexnum; j++) {  // ѭ�����ж���
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j]) { // ����±�Ϊk�������ȨֵС�ڵ�ǰ��Щ����δ������������Ȩֵ
				lowcost[j] = G.arcs[k][j]; // ����С��Ȩֵ����lowcost��Ӧ��λ��
				adjvex[j] = k;   // ���±�Ϊk�Ķ������adjvex
			}
		}
	}
}

/*-----------------------�ָ���--------------------------*/


//ͼ���ڽӱ���
typedef struct ArcNode {
	int adjvex;						//�ñ�ָ�򶥵��λ��
	struct ArcNode *nextarc;		//ָ����һ���ߵ�ָ��
	int info;						//�ͱ��йص���Ϣ����Ȩֵ
} ArcNode;

typedef struct VNode {
	char data;						//���涥�����ֻ�һЩ�����Ϣ
	ArcNode *firstarc;				//ָ�������е�һ�����
} VNode, AdjList[MAXnum];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
} ALGraph;

//�ڶ�����ﶨλ�����λ��
int LocateVex(ALGraph G, char v) { //��������v
	for (int i = 0; i < G.vexnum; i++)
		if (G.vertices[i].data == v)
			return i;
}

//�ڽӱ���������
int CreateUDG_1(ALGraph *G) {
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //���붥�����ͱ���
	printf("������%d�������ƣ�", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //����ͼ�Ķ�������
		(*G).vertices[i].firstarc = NULL;        //�����ָ�������ָ���ʼ��ΪNULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //��������
		printf("���������������ߵ��������㣺");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //��λ���������λ��
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //����һ�����ӵ� ��������
		p1->nextarc = (*G).vertices[i].firstarc;    //�������¼�����嵽ͷ
		p1->adjvex = j;       //���ߵ���һ������λ������Ϊj
		scanf("%d", &p1->info);
		(*G).vertices[i].firstarc = p1;   //�������ӱ�����
		//��������һ����
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->nextarc = (*G).vertices[j].firstarc;
		p2->adjvex = i;
		p2->info = p1->info;
		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}

//�ڽӱ�������ͼ
int CreateUDG_2(ALGraph *G) {
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //���붥�����ͱ���
	printf("������%d�������ƣ�", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //����ͼ�Ķ�������
		(*G).vertices[i].firstarc = NULL;        //�����ָ�������ָ���ʼ��ΪNULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //��������
		printf("���������������ߵ��������㣺");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //��λ���������λ��
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //����һ�����ӵ� ��������
		p1->nextarc = (*G).vertices[i].firstarc;    //�������¼�����嵽ͷ
		p1->adjvex = j;       //���ߵ���һ������λ������Ϊj
		p1->info = 1;         //Ȩֵ
		(*G).vertices[i].firstarc = p1;   //�������ӱ�����
		//��������һ����
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->nextarc = (*G).vertices[j].firstarc;
		p2->adjvex = i;
		p2->info = 1;
		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}

//�ڽӱ���������
int CreateUDG_3(ALGraph *G) {
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //���붥�����ͱ���
	printf("������%d�������ƣ�", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //����ͼ�Ķ�������
		(*G).vertices[i].firstarc = NULL;        //�����ָ�������ָ���ʼ��ΪNULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //��������
		printf("���������������ߵ��������㣺");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //��λ���������λ��
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //����һ�����ӵ� ��������
		p1->nextarc = (*G).vertices[i].firstarc;    //�������¼�����嵽ͷ
		p1->adjvex = j;       //���ߵ���һ������λ������Ϊj
		scanf("%d", &p1->info);
		(*G).vertices[i].firstarc = p1;   //�������ӱ�����
		//��������һ����
//		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
//		p2->nextarc = (*G).vertices[j].firstarc;
//		p2->adjvex = i;
//		p2->info = p1->info;
//		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}

//�ڽӱ�������ͼ
int CreateUDG_4(ALGraph *G) {
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &(*G).vexnum, &(*G).arcnum);  //���붥�����ͱ���
	printf("������%d�������ƣ�", (*G).vexnum);
	for (int i = 0; i < (*G).vexnum; i++) {
		scanf(" %c", &((*G).vertices[i].data));  //����ͼ�Ķ�������
		(*G).vertices[i].firstarc = NULL;        //�����ָ�������ָ���ʼ��ΪNULL
	}
	for (int k = 0; k < (*G).arcnum; k++) {
		int i, j;
		char v1, v2;    //��������
		printf("���������������ߵ��������㣺");
		scanf(" %c%c", &v1, &v2);
		i = LocateVex(*G, v1);   //��λ���������λ��
		j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //����һ�����ӵ� ��������
		p1->nextarc = (*G).vertices[i].firstarc;    //�������¼�����嵽ͷ
		p1->adjvex = j;       //���ߵ���һ������λ������Ϊj
		p1->info = 1;         //Ȩֵ
		(*G).vertices[i].firstarc = p1;   //�������ӱ�����
//		//��������һ����
//		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
//		p2->nextarc = (*G).vertices[j].firstarc;
//		p2->adjvex = i;
//		p2->info = 1;
//		(*G).vertices[j].firstarc = p2;
	}
	return 1;
}


//�ڽӱ�������ȱ���
void DFS_AR(ALGraph G, int i) {
	ArcNode *p;     //ָ���������ָ��
	visited[i] = 1; //���������λ������Ϊ1
	printf("%c", G.vertices[i].data);
	p = G.vertices[i].firstarc;  //ָ����������׽��
	while (p) { //ָ�벻Ϊ�ռ���ѭ��
		if (!visited[p->adjvex])
			DFS_AR(G, p->adjvex);
		p = p->nextarc;  //����ָ����һ�����
	}
}

//������ȱ�����������
void DFS_ARC(ALGraph G) {
	//��ʼ����������
	for (int i = 0; i < G.vexnum; i++) //��ʼ����������
		visited[i] = 0;
	for (int i = 0; i < G.vexnum; i++) //�ӵ�һ��������Ϊ��ڽ��б���
		if (!visited[i])
			DFS_AR(G, i);
}



//������ȱ���
void BFS_ARC(ALGraph G, int i) {
	ArcNode *p;
	SqQueue Q;
	int e;   //��¼���Ӷ���λ��
	//��ʼ��״̬����
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	//��ʼ������
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
	printf("�����뽨��ͼ�ķ�ʽ\n");
	printf("1.�ڽӾ��󴴽�������\n");
	printf("2.�ڽӾ��󴴽�����ͼ\n");
	printf("3.�ڽӾ��󴴽�������\n");
	printf("4.�ڽӾ��󴴽�����ͼ\n");
	printf("5.�ڽӱ���������\n");
	printf("6.�ڽӱ�������ͼ\n");
	printf("7.�ڽӱ���������\n");
	printf("8.�ڽӱ�������ͼ\n");
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
			printf("���������������\n");
			goto ask;
			break;
	}
	printf("\n-----��������Ҫ���еĲ���-----\n");
	printf("1.���й����������������������\n");
	printf("2.���������������������������\n");
	printf("3.����ͼ����С����������\n");
	printf("4.�˳�����\n");
	scanf("%d", &num2);
	while (num2 != 4) {
		switch (num2) {
			case 1:
				switch (num1) {
					case 1:
					case 2:
					case 3:
					case 4:
						printf("\n�ڽӾ��������ȱ��������");
						BFS_AMG(Q, 0);
						break;
					case 5:
					case 6:
					case 7:
					case 8:
						printf("\n�ڽӱ������ȱ��������");
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
						printf("\n�ڽӾ���������ȱ��������");
						DFS_AMG(Q, 2);
						break;
					case 5:
					case 6:
					case 7:
					case 8:
						printf("\n�ڽӱ�������ȱ��������");
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
						printf("�˹���ֻ�������ڽӾ��󴴽�ͼ������²ſ�ʹ�ã������´���\n");
						goto ask;
						break;
				}
				break;
		}
		printf("\n-----��������Ҫ���еĲ���-----\n");
		scanf("%d", &num2);
	}
	return 0;
}