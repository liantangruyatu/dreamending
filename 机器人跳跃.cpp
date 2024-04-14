#include <iostream>
#include <cstdio>


using namespace std;

int n;
const int N = 1e5 + 10;

int g[N];

bool check(int x) { //�ж��Ƿ����
	for (int i = 0; i < n; i++) {
		x = 2 * x - g[i];
		if (x >= 1e5)
			return true;
		if (x < 0)
			return false;
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> g[i];
	int l = 0, r = 1e5;
	while (l < r) { //�����������ڵ����д�
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r ;
	return 0;
}