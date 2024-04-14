#include <stdio.h>

int main() {
	int arr1[110], arr2[110], arr[110];
	int num, count = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &arr1[i], &arr2[i]);
	}
	for (int i = 0; i < num; i++) {
		arr[i] = arr2[i] - arr1[i];
	}
	for (int i = 0; i < num; i++) {
		if (arr[i >= 2]) {
			count++;
		}
	}
	printf("%d", count);
}