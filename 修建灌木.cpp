#include <stdio.h>
#include <stdlib.h>

int main() {
	long long int n;
	scanf("%lld", &n);
	printf("%lld\n", 2 * n - 2);
	if (n % 2 == 0) {
		for (int i = 1; i <= (n - 2) / 2; i++) {
			printf("%d\n", 2 * n - 2 - 2 * i);
		}
		for (int i = (n - 2) / 2; i >= 1; i--) {
			printf("%d\n", 2 * n - 2 - 2 * i);
		}
	} else {
		for (int i = 1; i <= (n - 3) / 2; i++) {
			printf("%d\n", 2 * n - 2 - 2 * i);
		}

		printf("%d\n", (2 * n - 2) / 2);

		for (int i = (n - 2) / 2; i >= 1; i--) {
			printf("%d\n", 2 * n - 2 - 2 * i);
		}
	}
	printf("%lld", 2 * n - 2);
	return 0;
}

