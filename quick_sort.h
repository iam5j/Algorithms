#ifndef QUICK_SORT_H_5J
#define QUICK_SORT_H_5J

#include <algorithm>

void qsort(int* a, int p, int q) {
    if (p >= q) {
        return;
    }

    int j = p;
    int i = p - 1;
    int x = a[q];
    for (; j <= q; ++j) {
        if (a[j] < x) {
            std::swap(a[++i], a[j]);
        }
    }
    std::swap(a[++i], a[q]);

    qsort(a, p, i - 1);
    qsort(a, i + 1, q);
}

#endif
