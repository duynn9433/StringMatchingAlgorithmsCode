//
// Created by nndng on 5/31/2022.
//

#include "ShiftOr.h"
#include "../graph/graph.h"
#include <bits/stdc++.h>

using namespace std;
#define XSIZE 128
#define ASIZE 128
#define WORD 32
int preSo(char *x, int m, unsigned int S[]) {
    unsigned int j, lim;
    int i;
    //~ revert bit 1->0, 0->1
    for (i = 0; i < ASIZE; ++i)
        S[i] = ~0; //fill all bit with 1 ---> 1111...1111 --> max value

    //from x[0] to x[m-1]
    for (lim = i = 0, j = 1; i < m; ++i, j <<= 1) {
        S[x[i]] &= ~j; //x[i] = c --> bit i of S[c] is 0
        lim |= j;   //Or all bit
    }
    lim = ~(lim>>1);
    return(lim);
}

std::vector<int> ShiftOr(char *x, int m, char *y, int n) {
    vector<int> res;
    unsigned int lim, state;
    unsigned int S[ASIZE];
    int j;
    if (m > WORD)
        error("SO: Use pattern size <= word size");
    /* Preprocessing */
    lim = preSo(x, m, S);
    /* Searching */
    for (state = ~0, j = 0; j < n; ++j) {
        //Rj=1 = Shift(Rj) OR Sy[j+1]
        state = (state<<1) | S[y[j]];
        //Rj+1[m-1] = 0 --> all match
        if (state < lim)
            res.push_back(j - m + 1);
    }
    return res;
}

