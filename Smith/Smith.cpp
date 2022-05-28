//
// Created by nndng on 5/28/2022.
//

#include "Smith.h"
#include "../Boyer-Moore/Boyer-Moore.h"
#include "../Quick-Search/Quick-Search.h"
#include <bits/stdc++.h>
using namespace std;
#define ASIZE 128


std::vector<int> Smith(char *x, int m, char *y, int n){
    vector<int> res;
    int j, bmBc[ASIZE], qsBc[ASIZE];

    /* Preprocessing */
    preBmBadCharacter(x, m, bmBc);
    preQsBc(x, m, qsBc);

    /* Searching */
    j = 0;
    while (j<= n - m) {
        if (memcmp(x, y + j, m) == 0)
            res.push_back(j);
        j += max(bmBc[y[j + m - 1]], qsBc[y[j + m]]);
    }
    return res;
}