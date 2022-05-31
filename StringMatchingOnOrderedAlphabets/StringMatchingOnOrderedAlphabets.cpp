//
// Created by nndng on 5/31/2022.
//

#include "StringMatchingOnOrderedAlphabets.h"
#include "../graph/graph.h"
#include <bits/stdc++.h>

using namespace std;
#define XSIZE 128
#define ASIZE 128

/* Compute the next maximal suffix. */
void nextMaximalSuffix(char *x, int m,
                       int *i, int *j, int *k, int *p) {
    char a, b;

    while (*j + *k < m) {
        a = x[*i + *k];
        b = x[*j + *k];
        if (a == b)
            if (*k == *p) {
                (*j) += *p;
                *k = 1;
            } else
                ++(*k);
        else if (a > b) {
            (*j) += *k;
            *k = 1;
            *p = *j - *i;
        } else {
            *i = *j;
            ++(*j);
            *k = *p = 1;
        }
    }
}

/* String matching on ordered alphabets algorithm. */
std::vector<int> StringMatchingOnOrderedAlphabets(char *x, int m, char *y, int n) {
    vector<int> res;
    int i, ip, j, jp, k, p;

    /* Searching */
    ip = -1;
    i = j = jp = 0;
    k = p = 1;
    while (j <= n - m) {
        while (i + j < n && i < m && x[i] == y[i + j])
            ++i;
        if (i == 0) {
            ++j;
            ip = -1;
            jp = 0;
            k = p = 1;
        } else {
            if (i >= m)
                res.push_back(j);
            nextMaximalSuffix(y + j, i + 1, &ip, &jp, &k, &p);
            if (ip < 0 ||
                (ip < p &&
                 memcmp(y + j, y + j + p, ip + 1) == 0)) {
                j += p;
                i -= p;
                if (i < 0)
                    i = 0;
                if (jp - ip > p)
                    jp -= p;
                else {
                    ip = -1;
                    jp = 0;
                    k = p = 1;
                }
            } else {
                j += (max(ip + 1,
                          min(i - ip - 1, jp + 1)) + 1);
                i = jp = 0;
                ip = -1;
                k = p = 1;
            }
        }
    }
    return res;
}
