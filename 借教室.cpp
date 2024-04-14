#include <stdio.h>
const int N = 1e6 + 10;
int r[N], b[N], r2[N];
int n, m;

void chafen(int s, int t, int d) {
	b[s] += d;
	b[t + 1] -= d;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &r[i]);
	}
	for (int num = 1; num <= m; num ++) {
		int d, s, t;
		scanf("%d%d%d", &d, &s, &t);
		chafen(s, t, d);
		for (int i = 1; i <= n; i ++) {
			r2[i] = r2[i - 1] + b[i];
			if (r[i] < r2[i]) {
				printf("-1\n");
				printf("%d\n", num);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}