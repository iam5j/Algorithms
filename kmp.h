#ifndef KMP_5J_H_
#define KMP_5J_H_

#include <string>
#include <vector>

// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
#if 0
void KmpTable(const std::string &w, std::vector<int> *t) {
	t->resize(w.length(), 0);

	(*t)[0] = -1;
	(*t)[1] = 0;
	int pos = 2;
	int cnd = 0;
	while (pos < w.length()) {
		if (w[pos - 1] == w[cnd]) {
			(*t)[pos] = cnd + 1;
			++pos;
			++cnd;
		} else if ((*t)[cnd] > -1) {
			cnd = (*t)[cnd];
		} else {
			(*t)[pos] = 0;
			++pos;
		}
	}
}

int KmpSearch(const std::string &s, const std::string & w) {
	std::vector<int> t;
	KmpTable(w, &t);

	int m = 0;
	int i = 0;
	while (m + i < s.length()) {
		if (s[m + i] == w[i]) {
			if (i == w.length() - 1) {
				return m;
			} else {
				++i;
			}
		} else if (t[i] > -1) {
			m = m + i - t[i];
			i = t[i];
		} else {
			++m;
			i = 0;
		}
	}

	return -1;
}
#else
void KmpTable(const std::string &w, std::vector<int> *t) {
	t->resize(w.length(), 0);

	(*t)[0] = 0;
	(*t)[1] = 0;
	int pos = 2;
	int cnd = 0;
	while (pos < w.length()) {
		if (w[pos - 1] == w[cnd]) {
			(*t)[pos] = cnd + 1;
			++pos;
			++cnd;
		} else {
			cnd = (*t)[cnd];
			if (cnd == 0) {
				(*t)[pos] = 0;
				++pos;
			}
		}
	}
}

int KmpSearch(const std::string &s, const std::string & w) {
	std::vector<int> t;
	KmpTable(w, &t);

	int m = 0;
	int i = 0;
	while (m + i < s.length()) {
		if (s[m + i] == w[i]) {
			if (i == w.length() - 1) {
				return m;
			} else {
				++i;
			}
		} else if (t[i] > 0) {
			m = m + i - t[i];
			i = t[i];
		} else {
			++m;
			i = 0;
		}
	}

	return -1;
}
#endif //#if 0
#endif //#ifndef KMP_5J_H_
