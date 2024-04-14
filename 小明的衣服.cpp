#include <stdio.h>

int main() {
	long long int arr[100010] = {0}, count = 0;
	int num, temp;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		scanf("%lld", &arr[i]);
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
	for (int i = 0; i < num; ++i) {
		for (int j = 1; j <= num - i; j++) {
			count = count + arr[j];
		}
	}
	count = count - arr[1];
	printf("%lld", count);
	return 0;
}