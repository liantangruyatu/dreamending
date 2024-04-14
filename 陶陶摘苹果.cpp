#include <stdio.h>

int main() {
	int arr[10], length, count = 0;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}
	printf("ÊäÈëÍê±Ï\n");
	scanf("%d", &length);
	for (int i = 0; i < 10; i++) {
		if (arr[i] <= length + 30) {
			count++;
		}
	}
	printf("%d", count);
}