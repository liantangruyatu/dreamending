#include <stdio.h>
#include <stdlib.h>
#define count 3

int initTriplet(float *&T, float f[]) {
	T = (float *)malloc(sizeof(float) * count);
//这里用指针形式就不会出现编译错误，用引用形式反而会出现编译错误
	T[0] = f[0];
	T[1] = f[1];
	T[2] = f[2];

	return 0;


}//功能1_创建三元组
int getElem(float *&T, int i, float &e) {
	if (i < 1 || i > 3) {
		return 1;
	}
	e = T[i - 1];
	return 0;


}//功能2_取三元组的任意一个分量
int putElem(float *&T, int i, float &e) {
	T[i - 1] = e;
	return 0;


}//功能3_置三元组的任意一个分量
int getMax(float *&T, float &max) {
	if (T[0] > T[1])
		max = T[0];
	else
		max = T[1];
	if (T[2] > max)
		max = T[2];
	return 0;


}//功能4_求三元组的最大分量
int getMin(float *&T, float &min) {
	if (T[0] < T[1])
		min = T[0];
	else
		min = T[1];
	if (T[2] < min)
		min = T[2];
	return 0;


}//功能5_求三元组的最小分量
int printTri(float *&T) {
	printf("三元组的三个值为%f %f %f\n", T[0], T[1], T[2]);
	return 0;


}//功能6_显示三元组
int multiplyTri(float *&T, float i) {
	for (int j = 0; j < 3; j++)
		T[j] = T[j] * i;
	return 0;


}//功能7_对三元组的各分量通乘一个比例因子
int addTri(float *&T, float a, float b) {
	if (a < 1 || a > 3) {
		return 1;
	}
	if (b < 1 || b > 3) {
		return 1;
	}
	printf("%f\n", T[(int) a - 1] + T[(int) b - 1]);
	return 0;
}//功能8_对两个三元组的对应分量相加

int subtractTri(float *&T, float a, float b) {
	if (a < 1 || a > 3) {
		return 1;
	}
	if (b < 1 || b > 3) {
		return 1;
	}
	printf("%f\n", T[(int) a - 1] - T[(int) b - 1]);
	return 0;


}//功能9_对两个三元组的对应分量相减
int destoryTri(float *&T) {
	free(T);
	return 0;


}//功能10_销毁三元组
int main() {
	float a, b, c, i, j, x, y;
	float f[3];
	float *T;
	int flag;
	printf("请输入需进行操作编号\n");
	printf("功能1_创建三元组\n");
	printf("功能2_取三元组的任意一个分量\n");
	printf("功能3_置元组的任意一个分量\n");
	printf("功能4_求三元组的最大分量\n");
	printf("功能5_求三元组的最小分量\n");
	printf("功能6_显示三元组\n");
	printf("功能7_对两个三元组的对应分量相加\n");
	printf("功能8_对两个三元组的对应分量相减\n");
	printf("功能9_对三元组的各分量通乘一个比例因子\n");
	printf("功能10_销毁三元组\n");
	printf("输入0_退出程序");
	scanf("%d", &flag);
	while (flag != 0) {
		switch (flag) {
			case 1:
				printf("请输入三元组的三个值\n");
				scanf("%f %f %f", &f[0], &f[1], &f[2]);
				initTriplet(T, f);
				printf("创建成功\n");
				break;
			case 2:
				printf("请输入要读取三元组分量的位置\n");
				scanf("%f", &i);
				getElem(T, i, x);
				printf("三元组中第%.0f个数是：%f\n", i, x);
				break;
			case 3:
				printf("请输入要修改三元组分量的位置\n");
				scanf("%f", &i);
				printf("请输入要修改三元组分量的值\n");
				scanf("%f", &x);
				putElem(T, i, x);
				printf("三元组中第%.0f个数是：%f\n", i, x);
				break;
			case 4:
				getMax(T, y);
				printf("三元组中最大值是：%f\n", y);
				break;
			case 5:
				getMin(T, y);
				printf("三元组中最小值是：%f\n", y);
				break;
			case 6:
				printTri(T);
				break;
			case 7:
				printf("请输入需要相加的两个三元组分量\n");
				scanf("%f %f", &a, &b);
				addTri(T, a, b);
				break;
			case 8:
				printf("请输入需要相减的两个三元组分量\n");
				scanf("%f %f", &a, &b);
				subtractTri(T, a, b);
				break;
			case 9:
				printf("请输入分量通乘的比例因子\n");
				scanf("%f", &i);
				multiplyTri(T, i);
				printf("修改完毕\n");
				printf("分量通乘比例因子后的值分别为%f %f %f\n", T[0], T[1], T[2]);
				break;
			case 10:
				destoryTri(T);
				printf("已销毁三元组\n");
				break;
			default:
				printf("您输入的数字有误\n");
				break;
		}
		printf("请输入需进行操作编号\n");
		scanf("%d", &flag);
	}
	printf("程序结束\n");
	return 0;
}