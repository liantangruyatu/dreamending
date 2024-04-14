#include <stdio.h>

int main() {
	long long int arr[100], num, sum = 0;
	scanf("%lld", &num);
	for (int i = 0; i < num; i++) {
		scanf("%lld", &arr[i]);
	}
	for (int i = 0; i < num - 1; i++) {
		sum = arr[i] * arr[i + 1] + sum;
		arr[i + 1] = arr[i] + arr[i + 1];
	}
	printf("%lld", sum);
	return 0;
}