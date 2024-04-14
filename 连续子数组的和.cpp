
#include <stdio.h>

//求一个整型数组的连续子数组的最大和

int MaxSum(int a[], int size) {
	if (a == NULL || size == 0) {
		//非法输入
		return -1;
	}

	int sum = 0;//初始和为0
	int index = 0;
	int max = a[index];//最大值最初必为数组第一个元素
	for (; index < size; ++index) {
		sum = sum + a[index];//遍历一个元素，累加一次
		//max = sum;//将和赋值给最大值
		if (sum < a[index]) { //如果加上当前元素之后的和比当前元素还小，则舍弃之前的元素，从当前元素开始累加
			sum = a[index];
		}
		//如果加上当前元素之后的和比当前元素大
		//说明可以继续累加
		//如果当前和比最大值大，则更新最大值为当前和
		//否则，不做更新
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}

int main() {
	int a[100000], size, n;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &a[i]);
	}
	n = MaxSum(a, size);
	printf("%d", n);
	return 0;
}