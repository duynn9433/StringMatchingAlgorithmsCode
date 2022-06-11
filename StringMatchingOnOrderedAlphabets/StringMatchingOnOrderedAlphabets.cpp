//
// Created by nndng on 5/31/2022.
//

#include "StringMatchingOnOrderedAlphabets.h"
#include "../graph/graph.h"
#include <bits/stdc++.h>

using namespace std;
#define XSIZE 128
#define ASIZE 128

/**
 * @brief      Compute the next maximal suffix
 * <br> define x = uv
 * <br> v= w^ew' (e time w)
 *
 * @param      i   |u|
 * @param      j   |uw^e|
 * @param      k   |w'|+1
 * @param      p   |w| = period(v)
 *
 * @return
*/
void nextMaximalSuffix(char *x, int m,
                       int *i, int *j, int *k, int *p) {
    char a, b;

    while (*j + *k < m) {
        a = x[*i + *k];//char at i+k
        b = x[*j + *k];//char at j+k
        if (a == b)
            if (*k == *p) {
                (*j) += *p;//shift k=p to the right
                *k = 1;
            } else
                ++(*k);
        else if (a > b) {//alphabet order
            (*j) += *k;
            *k = 1;
            *p = *j - *i;
        } else {
            *i = *j;
            ++(*j);
            *k = *p = 1;
        }
    }
    /* the maximal suffix of x[1]... x[n] is x[i+1] ...x[n]. */
    /* and p is the smallest period of x[i+1]...x[n] */
}

/* String matching on ordered alphabets algorithm. */
std::vector<int> StringMatchingOnOrderedAlphabets(char *x, int m, char *y, int n) {
    vector<int> res;
    /* i run on x
     * j run on y
     * ip =  |u|
     * jp =  |uw^e|
     * k =  |w'|+1
     * p =  |w| = period(v)*/
    int i, ip, j, jp, k, p;

    /* Searching */
    ip = -1;
    i = j = jp = 0;
    k = p = 1;
    while (j <= n - m) {/* scan from left to right*/
        while (i + j < n && i < m && x[i] == y[i + j])//scan until mismatch
            ++i;
        if (i == 0) {//mismatch at the first position
            ++j;
            ip = -1;
            jp = 0;
            k = p = 1;
        } else {
            /* test for occurrence */
            if (i >= m)
                res.push_back(j);
            /* update the maximal suffix */
            nextMaximalSuffix(y + j, i + 1, &ip, &jp, &k, &p);
            /* x1...xi suffix of the prefix of length p of x[i+1]...x[m-1]t[pos+m]*/
            if (ip < 0 ||
                (ip < p && memcmp(y + j, y + j + p, ip + 1) == 0))
            {
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
