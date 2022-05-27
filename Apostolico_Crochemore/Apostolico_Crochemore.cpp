//
// Created by nndng on 5/27/2022.
//

#include "Apostolico_Crochemore.h"
#include "../Knuth-Morris-Pratt/Knuth-Morris-Pratt.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 100

std::vector<int> ApostolicoCrochemore(char *x, int m, char *y, int n){
    vector<int> res;
    int i, j, k, ell, kmpNext[XSIZE];

    /* Preprocessing */
    preKmp(x, m, kmpNext);
    for (ell = 1; x[ell - 1] == x[ell]; ell++);
    if (ell == m)
        ell = 0;

    /* Searching */
    i = ell;
    j = k = 0;
    while (j <= n - m) {
        while (i < m && x[i] == y[i + j])
            ++i;
        if (i >= m) {
            while (k < ell && x[k] == y[j + k])
                ++k;
            if (k >= ell)
                res.push_back(j);
        }
        j += (i - kmpNext[i]);
        if (i == ell)
            k = max(0, k - 1);
        else
        if (kmpNext[i] <= ell) {
            k = max(0, kmpNext[i]);
            i = ell;
        }
        else {
            k = ell;
            i = kmpNext[i];
        }
    }
    return res;
}