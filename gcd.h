#ifndef GCD_H_5J
#define GCD_H_5J

#include <algorithm>

int gcd(int x, int y) {
    int a = std::max<int>(x, y);
    int b = std::min<int>(x, y);
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

#endif
