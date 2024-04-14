#include <stdio.h>

int main() {
	long long int n, i, j, b, max = 0, min = 100, a[10000][2];
	scanf("%lld", &n);
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < 2; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	for ( i = 0; i < n; i++) {
		if (max < (a[i][0] / a[i][1]))
			max = (a[i][0] / a[i][1]);
		if (min > (a[i][0] / a[i][1]))
			min = (a[i][0] / a[i][1]);
	}
	printf("%lld %lld", min, max);
	return 0;
}