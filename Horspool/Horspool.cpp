//
// Created by nndng on 5/28/2022.
//

#include "Horspool.h"
#include "../Boyer-Moore/Boyer-Moore.h"
#include <bits/stdc++.h>
using namespace std;
#define ASIZE 128

std::vector<int> Horspool(char *x, int m, char *y, int n){
    vector<int> res;
    int j, bmBc[ASIZE];
    char c;

    /* Preprocessing */
    preBmBadCharacter(x, m, bmBc);

    /* Searching */
    j = 0;
    while (j <= n - m) {
        //c la vi tri dau tien so sanh cua y, right to left
        c = y[j + m - 1];
        if (x[m - 1] == c && memcmp(x, y + j, m - 1) == 0)
            res.push_back(j);
        //shift theo bad-character
        j += bmBc[c];
    }
    return res;
}