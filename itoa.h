#ifndef ITOA_5J_H
#define ITOA_5J_H

#include <numeric>

int digits10(unsigned int x) {
	int num = 1;
	while (true) {
		if (x < 10) return num;
		if (x < 100) return num + 1;
		if (x < 1000) return num + 2;
		if (x < 10000) return num + 3;
		x /= 10000U;
		num += 4;
	}
}

int itoa_5j(char* buffer, int length, int x) {
	int ne = 0;
	unsigned int ux = 0;
	if (x < 0) {
		ne = 1;
		if (x == INT_MIN) {
			ux = (unsigned int)INT_MAX + 1;
		} else {
			ux = -x;
		}
	} else {
		ux = x;
	}

	int count = digits10(ux) + ne;
	if (length <= count) {
		return -1;
	}

	static const char digits[201] =
		"0001020304050607080910111213141516171819"
		"2021222324252627282930313233343536373839"
		"4041424344454647484950515253545556575859"
		"6061626364656667686970717273747576777879"
		"8081828384858687888990919293949596979899";

	buffer[count] = '\0';
	while (ux >= 100) {
		unsigned const mod = (ux % 100) * 2;
		buffer[--count] = digits[mod + 1];
		buffer[--count] = digits[mod];
		ux /= 100;
	}
	if (ux < 10) {
		buffer[--count] = '0' + ux;
	} else {
		buffer[--count] = digits[ux * 2 + 1];
		buffer[--count] = digits[ux * 2];
	}
	if (ne == 1) {
		buffer[--count] = '-';
	}
	return 0;
}

#endif //ITOA_5J_H
