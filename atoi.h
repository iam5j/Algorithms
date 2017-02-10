#ifndef ATOI_5J_H
#define ATOI_5J_h

#include <numeric>

static const unsigned NEG_MAX = -INT_MIN;

int atoi_5j(const char* str) {
	if (str == nullptr) {
		return 0;
	}

	int negative = 0;
	switch (*str) {
	case '\0':
		return 0;
	case '+':
		++str;
		break;
	case '-':
		++str;
		negative = true;
		break;
	default:
		break;
	}

	unsigned int val = 0;
	for (; *str != '\0'; ++str) {
		if (val > (NEG_MAX / 10)) {
			return 0;
		}

		if (val == (NEG_MAX / 10) && (*str - '0') > (NEG_MAX % 10)) {
			return 0;
		}

		val *= 10;
		val += (*str - '0');
		if (val > NEG_MAX) {
			return 0;
		}
	}

	if (val == NEG_MAX) {
		if (negative) {
			return INT_MIN;
		} else {
			return 0;
		}
	}

	int result = val;
	return negative ? -result: result;
}

#endif //ATOI_5J_h
