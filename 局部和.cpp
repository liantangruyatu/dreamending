#include <stdio.h>

int main() {
	int arr[110] = {0};
	int a, b, num, sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; ++i) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &a, &b);
	for (int i = a - 1; i <= b - 2; ++i) {
		sum = sum + arr[i];
	}
	printf("%d", sum);
	return 0;
}