#include <stdio.h>

int main() {
	int a, arr[46] = {0, 1};
	for (int i = 0; i < 44; i++) {
		arr[i + 2] = arr[i] + arr[i + 1];
	}
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}