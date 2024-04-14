#include <stdio.h>

int main() {
	int arr[10000] = {0}, num;
	scanf("%d", &num);
	int a, b, j;
	for (int i = 0; i <= num; i++) {
		arr[i] = 1;
	}
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &a, &b);
		for (j = a; j <= b; j++)
			arr[j] = 0;
	}
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		if (arr[i] == 1) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}