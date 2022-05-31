//
// Created by nndng on 5/30/2022.
//

#include "Zhu-Takaodo.h"
#include "../Boyer-Moore/Boyer-Moore.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 100
#define ASIZE 128

void preZtBc(char *x, int m, int ztBc[ASIZE][ASIZE]) {
    int i, j;
    //th3
    for (i = 0; i < ASIZE; ++i)
        for (j = 0; j < ASIZE; ++j)
            ztBc[i][j] = m;
    //th2
    for (i = 0; i < ASIZE; ++i)
        ztBc[i][x[0]] = m - 1;
    //th1
    for (i = 1; i < m - 1; ++i)
        ztBc[x[i - 1]][x[i]] = m - 1 - i;
}


std::vector<int> ZhuTakaodo(char *x, int m, char *y, int n){
    vector<int> res;
    int i, j, ztBc[ASIZE][ASIZE], bmGs[XSIZE];

    /* Preprocessing */
    preZtBc(x, m, ztBc);
    preBmGoodSuffix(x, m, bmGs);

    /* Searching */
    j = 0;
    while (j <= n - m) {
        i = m - 1;
        while (i < m && x[i] == y[i + j])
            --i;
        if (i < 0) {
            res.push_back(j);
            j += bmGs[0];
        }
        else
            j += max(bmGs[i],
                     ztBc[y[j + m - 2]][y[j + m - 1]]);
    }
    return res;
}

