#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		int x = i;
		while (x) {
			if (x % 10 == k)
				ans++;
			x /= 10;
		}
	}
	printf("%d\n", ans);
	return 0;
}
