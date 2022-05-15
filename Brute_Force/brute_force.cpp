//
// Created by nndng on 3/30/2022.
//

#include "brute_force.h"
#include <bits/stdc++.h>
using namespace std;

#define EOS '\0'

/**
 * @brief
 *
 * @param x mảng chứa các kí tự cần tìm
 * @param m độ dài mảng x
 * @param y mảng chứa các kí tự gốc
 * @param n độ dài mảng y
 * @return * int trả về vị trí đầu tiên x match y,
 * không tìm thấy trả về -1
 */
vector<int> BF(char *x, int m, char *y, int n) {
    vector<int> res;
    int i, j;

    /* Searching */
    for (j = 0; j <= n - m; ++j) {
        for (i = 0; i < m && x[i] == y[i + j]; ++i);
        if (i >= m) {
            res.push_back(j);
        }
    }
    if(res.size() == 0) res.push_back(-1);
    return res;
}

