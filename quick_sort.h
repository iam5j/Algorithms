#ifndef QUICK_SORT_H_5J
#define QUICK_SORT_H_5J

void qsort(int* a, int p, int q) {
    if (p >= q) {
        return;
    }

    int j = p;
    int i = p - 1;
    int x = a[p];
    for (; j < q; ++j) {
        if (a[j] < x) {
            int t = a[j];
            a[j] = a[++i];
            a[i] = t;
        }
    }
    a[++i] = x;
    qsort(a, p, i);
    qsort(a, i + 1, q);
}

#endif
