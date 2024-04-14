#include <stdio.h>

int main() {
	int cap, drink, count = 0, a = 0;
	scanf("%d", &drink);
	cap = drink;
	while (cap > 3) {
		count = count + drink;
		cap = drink + a;
		drink = cap / 3;
		a = cap % 3;
	}
	printf("%d", count);
	return 0;
}