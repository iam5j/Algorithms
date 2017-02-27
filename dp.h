#ifndef DP_5J_H
#define DP_5J_H

#include <vector>
#include <limits>

namespace J5 {
    // int factory() {
    //     int x[2] = {1, 2};  //TODO
    //     int u[2] = {2, 1};  //TODO
    //     int t[9][2] = {0}; //TODO
    //     int s[10][2] = {0};
    //     s[0][0] = x[0] + t[0][0];
    //     s[0][1] = x[1] + t[0][1];
    //     for (int i = 1; i < 10; ++i) {
    //         s[i][0] = std::min<int>(s[i-1][0], s[i-1][1]+t[i-1][1]);
    //         s[i][1] = std::min<int>(s[i-1][0]+t[i-1][0], s[i-1][1]);
    //     }

    //     s[9][0] += u[0];
    //     s[9][1] += u[1];
    //     return std::min<int>(s[9][0], s[9][1]);
    // }

    int matrix(const std::vector<int> &p) {
        const int n = staitc_cast<int>(p.size()) - 1;
        std::vector<std::vector<int>> m(n);
        for (int i = 0; i < n; ++i) {
            m[i].resize(n, 0);
        }

        for (int l = 1; l < n; ++l) {
            for (int i = 0; i < n - l; ++i) {
                int j = i + l;
                m[i][j] = std::INT_MAX;
                for (int k = i; k <= j; ++k) {
                    int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                    }
                }
            }
        }
        return m[0][n - 1];
    }

    int lcs(const std::string &lhs, const std::string &rhs) {

    }
};

#endif