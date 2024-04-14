#include <stdio.h>

int main() {
	int num, count = 0;
	char arr[110];
	scanf("%d", &num);
	scanf("%s", &arr);
	for (int i = 0; i < num; i++) {
		if (arr[i] == 'x' && arr[i + 1] == 'x' && arr[i + 2] == 'x') {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}