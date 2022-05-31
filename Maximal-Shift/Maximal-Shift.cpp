//
// Created by nndng on 5/30/2022.
//

#include "Maximal-Shift.h"
#include "../Quick-Search/Quick-Search.h"
#include "../Optimal-Mismatch/Optimal-Mismatch.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 128
#define ASIZE 128

int minShift[XSIZE];

/** Computation of the MinShift table values.
 * Minimum left shift needed to match the pattern
string character at location j*/
void computeMinShift(char *x, int m) {
    int i, j;

    for (i = 0; i < m; ++i) {
        for (j = i - 1; j >= 0; --j)
            if (x[i] == x[j])
                break;
        minShift[i] = i - j;
    }
}


/* Maximal Shift pattern comparison function. */
int maxShiftPcmp(pattern *pat1, pattern *pat2) {
    int dsh;

    dsh = minShift[pat2->loc] - minShift[pat1->loc];
    return(dsh ? dsh : (pat2->loc - pat1->loc));
}


/* Maximal Shift string matching algorithm. */
vector<int> MaximalShift(char *x, int m, char *y, int n) {
    vector<int> res;
    int i, j, qsBc[ASIZE], adaptedGs[XSIZE];
    pattern pat[XSIZE];

    /* Preprocessing */
    computeMinShift(x ,m);
    orderPattern(x, m, reinterpret_cast<int (*)(void)>(maxShiftPcmp), pat);
    preQsBc(x, m, qsBc);
    preAdaptedGs(x, m, adaptedGs, pat);

    /* Searching */
    j = 0;
    while (j <= n - m) {
        i = 0;
        while (i < m && pat[i].c == y[j + pat[i].loc])
            ++i;
        if (i >= m)
            res.push_back(j);
        j += max(adaptedGs[i], qsBc[y[j + m]]);
    }
    return res;
}