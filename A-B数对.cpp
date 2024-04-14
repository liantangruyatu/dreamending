#include <stdio.h>

int main() {
	long long int arr[200010];
	long long int num1, num2, count = 0;
	scanf("%lld %lld", &num1, &num2);
	for (long long int i = 0; i < num1; ++i) {
		scanf("%lld", &arr[i]);
	}
	for (long long int i = 0; i < num1; ++i) {
		for (long long int j = 0; j < num1; ++j) {
			if (arr[i] - arr[j] == num2) {
				count++;
			}
		}
	}
	printf("%lld", count);
	return 0;
}