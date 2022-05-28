//
// Created by nndng on 5/27/2022.
//

#include "NotSoNaive.h"
#include <bits/stdc++.h>
using namespace std;

std::vector<int> NotSoNaive(char *x, int m, char *y, int n){
    vector<int> res;
    int j, k, ell;

    /* Preprocessing */
    if (x[0] == x[1]) {
        k = 2;
        ell = 1;
    }
    else {
        k = 1;
        ell = 2;
    }

    /* Searching */
    j = 0;
    while (j <= n - m){
        if (x[1] != y[j + 1])
            j += k;
        else {
            if (memcmp(x + 2, y + j + 2, m - 2) == 0 && x[0] == y[j]){
                res.push_back(j);
            }
            j += ell;
        }
    }
    return res;
}