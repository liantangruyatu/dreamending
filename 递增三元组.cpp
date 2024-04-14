#include <stdio.h>

void QuickSort(int array[], int low, int high) {
	int i = low;
	int j = high;
	int s;
	if (i >= j) {
		return;
	}

	int temp = array[low];
	while (i != j) {
		while (array[j] >= temp && i < j) {
			j--;
		}
		while (array[i] <= temp && i < j) {
			i++;
		}
		if (i < j) {
			s = array[i];
			array[i] = array[j];
			array[j] = s;
		}
	}

	//将基准temp放于自己的位置，（第i个位置）
	s = array[i];
	array[i] = array[low];
	array[low] = s;
	QuickSort(array, low, i - 1);
	QuickSort(array, i + 1, high);
}

int main() {
	int num;
	long long int count1 = 0, count2 = 0, sum = 0;
	int arr1[10010], arr2[10010], arr3[10010];
	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < num; ++i) {
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < num; ++i) {
		scanf("%d", &arr3[i]);
	}
	QuickSort(arr1, 1, num);
	QuickSort(arr2, 1, num);
	QuickSort(arr3, 1, num);
	for (int i = 0; i < num; ++i) {
		int j = 0;
		while (arr1[j] < arr2[i]) {
			count1++;
			j++;
		}
		int k = 0;
		while (arr2[i] < arr3[k]) {
			count2++;
			k++;
		}
		sum = count1 * count2 + sum;
	}
	printf("%lld", sum);
	return 0;
}