#include <bits/stdc++.h>
using namespace std;
int loan, pay, month;
double rate, mid, l = 0, r = 10, t;

int main() {
	cin >> loan >> pay >> month;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (r - l < 0.0001)
			break;
		t = loan;
		for (int i = 1; i <= month; i++) {
			t = t * (1 + mid) - pay;
		}
		if (t > 0)
			r = mid;
		else if (t < 0)
			l = mid;
		else {
			printf("%.1f", mid * 100);
		}
	}
	printf("%.1f", mid * 100);
	return 0;
}