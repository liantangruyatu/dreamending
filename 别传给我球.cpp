#include <stdio.h>

int main() {
	int arr[100], num;
	int a = 0, b = 0, c = 0, count = 0;
	for (int i = 1; i < 100; ++i) {
		arr[i] = i;
	}
	scanf("%d", &num);
	for (a = 0; a < num; a++) {
		for (b = a + 1; b < num; b++) {
			for (c = b + 1; c < num; c++) {
				if (a + b + c < num) {
					count++;
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}