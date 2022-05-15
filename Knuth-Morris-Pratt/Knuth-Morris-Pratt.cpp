//
// Created by nndng on 5/16/2022.
//

#include "Knuth-Morris-Pratt.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 100

void preKmp(char *x, int m, int kmpNext[]) {
    int i, j;

    i = 0;
    j = kmpNext[0] = -1;
    while (i < m) {
        while (j > -1 && x[i] != x[j])
            j = kmpNext[j];
        i++;
        j++;
        if (x[i] == x[j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
}
/**
 * @brief
 *
 * @param x mảng chứa các kí tự cần tìm
 * @param m độ dài mảng x
 * @param y mảng chứa các kí tự gốc
 * @param n độ dài mảng y
 * @return * int trả về vị trí đầu tiên x match y,
 * không tìm thấy trả về -1
 */
vector<int> KnuthMorrisPratt(char *x, int m, char *y, int n) {
    vector<int> res;
    int i, j, kmpNext[XSIZE];

    /* Preprocessing */
    preKmp(x, m, kmpNext);

    /* Searching */
    i = j = 0;
    while (j < n) {
        while (i > -1 && x[i] != y[j])
            i = kmpNext[i];
        i++;
        j++;
        if (i >= m) {
            res.push_back(j - i);
            i = kmpNext[i];
        }
    }

    if(res.size() == 0) res.push_back(-1);
    return res;
}
