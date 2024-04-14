#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool Judge(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	} else {
		return false;

	}
}

void Gain(int *Year, int *Month, int *Day, long long N) {
	*Year = N / 1e4;
	*Month = (N / 100) % 100;
	*Day = N % 100;
}

int main() {
	long long N;
	scanf("%lld", &N);
	int Year, Month, Day;
	Gain(&Year, &Month, &Day, N);
	int flag = 0;
	int flag2 = 0;
	for (int i = Year; i <= 9999; i++) {

		int i_g, i_s, i_b, i_q;
		i_g = i / 1000;
		i_s = (i / 100) % 10;
		i_b = (i / 10) % 10;
		i_q = i % 10;

		int day = i_s * 10 + i_g;
		int month = i_q * 10 + i_b;

		if (i == Year && (month < Month || month == Month && day <= Day) || month > 12 || day > 31) {
			continue;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day >= 0 && day <= 31) {
				if (flag == 0) {
					printf("回文日期为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag = 1;
				}

				if (i_q != i_s || i_b != i_g) {
					continue;
				} else if (i_q == i_s && i_b == i_g) {
					printf("强回文日期为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag2 = 1;
				};

				if (flag == 1 && flag2 == 1)
					break;
			} else {
				continue;

			}
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day >= 0 && day <= 30) {
				if (flag == 0) {
					printf("回文日期为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag = 1;
				}
				if (i_q != i_s || i_b != i_g) {
					continue;
				} else if (i_q == i_s && i_b == i_g) {
					printf("强回文日期为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag2 = 1;
				};

				if (flag == 1 && flag2 == 1)
					break;
			} else {
				continue;

			}
		} else if (Judge(i) && month == 2) {
			if (day >= 0 && day <= 29) {
				if (flag == 0) {
					printf("回文日期为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag = 1;
				}
				if (i_q != i_s || i_b != i_g) {
					continue;
				} else if (i_q == i_s && i_b == i_g) {
					printf("强回文日期为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag2 = 1;
				};

				if (flag == 1 && flag2 == 1)
					break;
			} else {
				continue;

			}
		} else if (Judge(i) == 0 && month == 2) {
			if (day >= 0 && day <= 28) {
				if (flag == 0) {
					printf("回文日期为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag = 1;
				}
				if (i_q != i_s || i_b != i_g) {
					continue;
				} else if (i_q == i_s && i_b == i_g) {
					printf("为：%d%d%d%d%d\n", i, i_q, i_b, i_s, i_g);
					flag2 = 1;
				};

				if (flag == 1 && flag2 == 1)
					break;
			} else {
				continue;
			}
		}

	}
	return 0;
}