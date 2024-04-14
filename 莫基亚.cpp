#include <stdio.h>

int change(int &arr[][], int c, int d, int e) {

}

int print(int &arr[][], int c, int d, int e, int f) {

}

int main() {
	int num, a, b, c, d, e, f;
	int arr[20000][20000] = {0};
	scanf("%d %d", &a, &b);
	scanf("%d", &num);
	while (true) {
		switch (num) {
			case 1:
				scanf("%d %d %d", c, d, e);
				change(&arr, c, d, e);
				break;
			case 2:
				scanf("%d %d %d %d", c, d, e, f);
				print(arr, c, d, e, f);
				break;
			case 3:
				return;
		}
	}
	return 0;
}