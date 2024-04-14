#include <stdio.h>

int main() {
	int arr[10010] = {0};
	int num, count = 0, temp, k;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 0; j <= num - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for ( k = 0; k < num; k++) {
		arr[k + 1] = arr[k] + arr[k + 1];
		count = arr[k + 1] + count;
	}
	count = count - 1;
	printf("%d", count);
	return 0;
}