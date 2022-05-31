//
// Created by nndng on 5/31/2022.
//

#include "KMP-Skip-Search.h"
#include "../graph/graph.h"
#include "../Morris-Pratt/Morris-Pratt.h"
#include "../Knuth-Morris-Pratt/Knuth-Morris-Pratt.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 128
#define ASIZE 128
int attempt(char *y, char *x, int m, int start, int wall) {
    int k;

    k = wall - start;
    while (k < m && x[k] == y[k + start])
        ++k;
    return(k);
}

std::vector<int> KMPSkipSearch(char *x, int m, char *y, int n){
    vector<int> res;
    int i, j, k, kmpStart, per, start, wall;
    int kmpNext[XSIZE], list[XSIZE], mpNext[XSIZE],
            z[ASIZE];

    /* Preprocessing */
    preMp(x, m, mpNext);
    preKmp(x, m, kmpNext);
    memset(z, -1, ASIZE*sizeof(int));
    memset(list, -1, m*sizeof(int));
    z[x[0]] = 0;
    for (i = 1; i < m; ++i) {
        list[i] = z[x[i]];
        z[x[i]] = i;
    }

    /* Searching */
    wall = 0;
    per = m - kmpNext[m];
    i = j = -1;
    do {
        j += m;
    } while (j < n && z[y[j]] < 0);
    if (j >= n)
        return res;
    i = z[y[j]];
    start = j - i;
    while (start <= n - m) {
        if (start > wall)
            wall = start;
        k = attempt(y, x, m, start, wall);
        wall = start + k;
        if (k == m) {
            res.push_back(start);
            i -= per;
        }
        else
            i = list[i];
        if (i < 0) {
            do {
                j += m;
            } while (j < n && z[y[j]] < 0);
            if (j >= n)
                return res;
            i = z[y[j]];
        }
        kmpStart = start + k - kmpNext[k];
        k = kmpNext[k];
        start = j - i;
        while (start < kmpStart ||
               (kmpStart < start && start < wall)) {
            if (start < kmpStart) {
                i = list[i];
                if (i < 0) {
                    do {
                        j += m;
                    } while (j < n && z[y[j]] < 0);
                    if (j >= n)
                        return res;
                    i = z[y[j]];
                }
                start = j - i;
            }
            else {
                kmpStart += (k - mpNext[k]);
                k = mpNext[k];
            }
        }
    }

    return res;
}
