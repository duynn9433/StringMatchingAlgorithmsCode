//
// Created by nndng on 5/28/2022.
//

#include "Quick-Search.h"
#include "../Boyer-Moore/Boyer-Moore.h"
#include <bits/stdc++.h>
using namespace std;
#define ASIZE 128

void preQsBc(char *x, int m, int qsBc[]) {
    int i;

    for (i = 0; i < ASIZE; ++i)
        qsBc[i] = m + 1;
    for (i = 0; i < m; ++i)
        qsBc[x[i]] = m - i;
}


vector<int>  QuickSearch(char *x, int m, char *y, int n) {
    vector<int> res;
    int j, qsBc[ASIZE];

    /* Preprocessing */
    preQsBc(x, m, qsBc);

    /* Searching */
    j = 0;
    while (j <= n - m) {
        if (memcmp(x, y + j, m) == 0)
            res.push_back(j);
        j += qsBc[y[j + m]];               /* shift */
    }
    return res;
}