#include <stdio.h>

int main() {
	char arr[31];
	char n;
	gets(arr);
	scanf("%c", &n);
	int i = 0;
	while (arr[i] != '\0') {
		if (arr[i] == n) {
			arr[i] = '#';
		}
		i++;
	}
	puts(arr);
	return 0;
}