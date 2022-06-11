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
/**
 * @brief      { KMP skip search }
 *
 * @param      x     pattern
 * @param      y     string
 * @param      m        The x length
 * @param      start  vị trí bắt đầu x trong y
 * @param     wall  vị trí trí duyệt đến phải cùng
 *
 * @return     { k là vị trí đầu tiên mismatch }
 */
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
    /*
     * z vị trí kí tự xuất hiện trong x
     * list: vị trí tiếp theo xuất hiện trong x
     * */
    int kmpNext[XSIZE], list[XSIZE], mpNext[XSIZE],
            z[ASIZE];

    /* Preprocessing */
    //KnuthMorrisPratt preprocessing
    preMp(x, m, mpNext);
    preKmp(x, m, kmpNext);
    //SkipSearch preprocessing
    memset(z, -1, ASIZE*sizeof(int));
    memset(list, -1, m*sizeof(int));
    z[x[0]] = 0;
    for (i = 1; i < m; ++i) {
        list[i] = z[x[i]];
        z[x[i]] = i;
    }

    /* Searching */
    wall = 0;
    per = m - kmpNext[m];//chu kì
    i = j = -1;
    //dịch m kí tự đến khi gặp kí tự có xuất hiện trong x
    do {
        j += m;
    } while (j < n && z[y[j]] < 0);
    // không tồn tại
    if (j >= n)
        return res;
    //i = vị trí lớn nhất y[j] xuất hiện trong x
    i = z[y[j]];
    start = j - i;//vị trí bắt đầu x trong y
    while (start <= n - m) {
        if (start > wall)
            wall = start;
        //vị trí đầu tiên không trùng
        k = attempt(y, x, m, start, wall);
        wall = start + k;
        if (k == m) {
            res.push_back(start);
            i -= per;
        }
        else
            i = list[i];//xét vị trí có y[j] trong x tiếp theo

        if (i < 0) {
            do {
                j += m;
            } while (j < n && z[y[j]] < 0);
            if (j >= n)
                return res;
            i = z[y[j]];
        }

        kmpStart = start + k - kmpNext[k];
        k = kmpNext[k];//ứng với vị trí đầu tiên mismatch
        start = j - i;
        while ((start < kmpStart) || (kmpStart < start && start < wall)) {
            if (start < kmpStart) {
                i = list[i];//vị trí tiếp theo y[j] trong x
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
            else { //(kmpStart < start && start < wall))
                kmpStart += (k - mpNext[k]);
                k = mpNext[k];
            }
        }
    }

    return res;
}
