#include <stdio.h>

int main() {
	int ticket[3][1000], number, money, gap;
	scanf("%d %d %d", &number, &money, &gap);
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &ticket[j][i]);
		}
	}
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", ticket[j][i]);
		}
		printf("\n");
	}
	return 0;
}