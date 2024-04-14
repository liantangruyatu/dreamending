#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
string q, w;
int cnt;

int main() {
	cin >> q >> w;
	int l = q.length();
	for (int i = 0; i < q.length(); i++) {
		if (q[i] != w[i]) {
			q[i] = w[i];
			if (q[i + 1] == 'o')
				q[i + 1] = '*';
			else
				q[i + 1] = 'o';
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}