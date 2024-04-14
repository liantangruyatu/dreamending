#include <stdio.h>

int main() {
	char arr[110];
	int num, count1 = 0, count2 = 0;
	scanf("%d", &num);
	for (int i = 0; i <= num; ++i) {
		scanf("%c", &arr[i]);
	}
	for (int i = 0; i <= num; ++i) {
		if (arr[i] == '(') {
			count1++;
		}
		if (arr[i] == ')') {
			count2++;
		}
	}
	if (count1 == count2) {
		printf("Yes\n");
	} 
	
	else if (count1 != count2) {
		printf("No\n");
	}
	return 0;
}