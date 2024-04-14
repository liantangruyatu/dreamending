#include <stdio.h>
#include <stdlib.h>
#define count 3

int initTriplet(float *&T, float f[]) {
	T = (float *)malloc(sizeof(float) * count);
//������ָ����ʽ�Ͳ�����ֱ��������������ʽ��������ֱ������
	T[0] = f[0];
	T[1] = f[1];
	T[2] = f[2];

	return 0;


}//����1_������Ԫ��
int getElem(float *&T, int i, float &e) {
	if (i < 1 || i > 3) {
		return 1;
	}
	e = T[i - 1];
	return 0;


}//����2_ȡ��Ԫ�������һ������
int putElem(float *&T, int i, float &e) {
	T[i - 1] = e;
	return 0;


}//����3_����Ԫ�������һ������
int getMax(float *&T, float &max) {
	if (T[0] > T[1])
		max = T[0];
	else
		max = T[1];
	if (T[2] > max)
		max = T[2];
	return 0;


}//����4_����Ԫ���������
int getMin(float *&T, float &min) {
	if (T[0] < T[1])
		min = T[0];
	else
		min = T[1];
	if (T[2] < min)
		min = T[2];
	return 0;


}//����5_����Ԫ�����С����
int printTri(float *&T) {
	printf("��Ԫ�������ֵΪ%f %f %f\n", T[0], T[1], T[2]);
	return 0;


}//����6_��ʾ��Ԫ��
int multiplyTri(float *&T, float i) {
	for (int j = 0; j < 3; j++)
		T[j] = T[j] * i;
	return 0;


}//����7_����Ԫ��ĸ�����ͨ��һ����������
int addTri(float *&T, float a, float b) {
	if (a < 1 || a > 3) {
		return 1;
	}
	if (b < 1 || b > 3) {
		return 1;
	}
	printf("%f\n", T[(int) a - 1] + T[(int) b - 1]);
	return 0;
}//����8_��������Ԫ��Ķ�Ӧ�������

int subtractTri(float *&T, float a, float b) {
	if (a < 1 || a > 3) {
		return 1;
	}
	if (b < 1 || b > 3) {
		return 1;
	}
	printf("%f\n", T[(int) a - 1] - T[(int) b - 1]);
	return 0;


}//����9_��������Ԫ��Ķ�Ӧ�������
int destoryTri(float *&T) {
	free(T);
	return 0;


}//����10_������Ԫ��
int main() {
	float a, b, c, i, j, x, y;
	float f[3];
	float *T;
	int flag;
	printf("����������в������\n");
	printf("����1_������Ԫ��\n");
	printf("����2_ȡ��Ԫ�������һ������\n");
	printf("����3_��Ԫ�������һ������\n");
	printf("����4_����Ԫ���������\n");
	printf("����5_����Ԫ�����С����\n");
	printf("����6_��ʾ��Ԫ��\n");
	printf("����7_��������Ԫ��Ķ�Ӧ�������\n");
	printf("����8_��������Ԫ��Ķ�Ӧ�������\n");
	printf("����9_����Ԫ��ĸ�����ͨ��һ����������\n");
	printf("����10_������Ԫ��\n");
	printf("����0_�˳�����");
	scanf("%d", &flag);
	while (flag != 0) {
		switch (flag) {
			case 1:
				printf("��������Ԫ�������ֵ\n");
				scanf("%f %f %f", &f[0], &f[1], &f[2]);
				initTriplet(T, f);
				printf("�����ɹ�\n");
				break;
			case 2:
				printf("������Ҫ��ȡ��Ԫ�������λ��\n");
				scanf("%f", &i);
				getElem(T, i, x);
				printf("��Ԫ���е�%.0f�����ǣ�%f\n", i, x);
				break;
			case 3:
				printf("������Ҫ�޸���Ԫ�������λ��\n");
				scanf("%f", &i);
				printf("������Ҫ�޸���Ԫ�������ֵ\n");
				scanf("%f", &x);
				putElem(T, i, x);
				printf("��Ԫ���е�%.0f�����ǣ�%f\n", i, x);
				break;
			case 4:
				getMax(T, y);
				printf("��Ԫ�������ֵ�ǣ�%f\n", y);
				break;
			case 5:
				getMin(T, y);
				printf("��Ԫ������Сֵ�ǣ�%f\n", y);
				break;
			case 6:
				printTri(T);
				break;
			case 7:
				printf("��������Ҫ��ӵ�������Ԫ�����\n");
				scanf("%f %f", &a, &b);
				addTri(T, a, b);
				break;
			case 8:
				printf("��������Ҫ�����������Ԫ�����\n");
				scanf("%f %f", &a, &b);
				subtractTri(T, a, b);
				break;
			case 9:
				printf("���������ͨ�˵ı�������\n");
				scanf("%f", &i);
				multiplyTri(T, i);
				printf("�޸����\n");
				printf("����ͨ�˱������Ӻ��ֵ�ֱ�Ϊ%f %f %f\n", T[0], T[1], T[2]);
				break;
			case 10:
				destoryTri(T);
				printf("��������Ԫ��\n");
				break;
			default:
				printf("���������������\n");
				break;
		}
		printf("����������в������\n");
		scanf("%d", &flag);
	}
	printf("�������\n");
	return 0;
}