//
// Created by nndng on 5/28/2022.
//

#include "Tuned-Boyer-Moore.h"
#include "../Boyer-Moore/Boyer-Moore.h"
#include <bits/stdc++.h>
using namespace std;
#define ASIZE 128

std::vector<int> TunedBoyerMoore(char *x, int m, char *y, int n){
    vector<int> res;
    int j, k, shift, bmBc[ASIZE];

    /* Preprocessing */
    preBmBadCharacter(x, m, bmBc);
    shift = bmBc[x[m - 1]];
    bmBc[x[m - 1]] = 0;
    memset(y + n, x[m - 1], m);

    /* Searching */
    j = 0;
    while (j < n) {
        k = bmBc[y[j + m -1]];
        while (k !=  0) {
            j += k; k = bmBc[y[j + m -1]];
            j += k; k = bmBc[y[j + m -1]];
            j += k; k = bmBc[y[j + m -1]];
        }
        if (memcmp(x, y + j, m - 1) == 0 && j < n)
            res.push_back(j);
        j += shift;                          /* shift */
    }

    return res;
}