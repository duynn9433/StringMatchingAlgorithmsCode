//
// Created by nndng on 3/30/2022.
//

#include "Karp-Rabin.h"
#include <bits/stdc++.h>
using namespace std;

//bo a dau them b cuoi
#define REHASH(a, b, h) ((((h) - (a)*d) << 1) + (b))

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
vector<int> KR(char *x, int m, char *y, int n) {
    vector<int> res;
    int d, hx, hy, i, j;

    /* Preprocessing */
    /* computes d = 2^(m-1) with
       the left-shift operator */
    //use for rehash, d == first index of string in hash
    for (d = i = 1; i < m; ++i)
        d = (d<<1);

    //hash(w[0 .. m-1])=(w[0]*2^(m-1)+ w[1]*2^(m-2)+···+ w[m-1]*2^0) mod q
    // <<1 == *2
    for (hy = hx = i = 0; i < m; ++i) {
        hx = ((hx<<1) + x[i]);
        hy = ((hy<<1) + y[i]);
    }

    /* Searching */
    j = 0;
    while (j <= n-m) {
        if (hx == hy && memcmp(x, y + j, m) == 0)
            res.push_back(j);
        hy = REHASH(y[j], y[j + m], hy);
        ++j;
    }

    if(res.size() == 0) res.push_back(-1);
    return res;
}
