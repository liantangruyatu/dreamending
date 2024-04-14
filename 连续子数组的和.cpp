
#include <stdio.h>

//��һ��������������������������

int MaxSum(int a[], int size) {
	if (a == NULL || size == 0) {
		//�Ƿ�����
		return -1;
	}

	int sum = 0;//��ʼ��Ϊ0
	int index = 0;
	int max = a[index];//���ֵ�����Ϊ�����һ��Ԫ��
	for (; index < size; ++index) {
		sum = sum + a[index];//����һ��Ԫ�أ��ۼ�һ��
		//max = sum;//���͸�ֵ�����ֵ
		if (sum < a[index]) { //������ϵ�ǰԪ��֮��ĺͱȵ�ǰԪ�ػ�С��������֮ǰ��Ԫ�أ��ӵ�ǰԪ�ؿ�ʼ�ۼ�
			sum = a[index];
		}
		//������ϵ�ǰԪ��֮��ĺͱȵ�ǰԪ�ش�
		//˵�����Լ����ۼ�
		//�����ǰ�ͱ����ֵ����������ֵΪ��ǰ��
		//���򣬲�������
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