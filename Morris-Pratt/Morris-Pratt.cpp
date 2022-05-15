//
// Created by nndng on 5/15/2022.
//

#include "Morris-Pratt.h"
#include <bits/stdc++.h>
using namespace std;

#define XSIZE 100
void preMp(char *x, int m, int mpNext[]) {
    int i, j;

    i = 0;
    j = mpNext[0] = -1;
    while (i < m) {
        //ki tu dau, ki tư hien tai != ki tu tiep theo mpNext
        while (j > -1 && x[i] != x[j]){
            //check tiep ki tu tiep theo mpNext
            j = mpNext[j];
        }
        //ki tu hien tai == ki tu tiep theo mpNext => i++, j++
        mpNext[++i] = ++j;
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
vector<int> MorrisPratt(char *x, int m, char *y, int n) {
    vector<int> res;

    int i, j, mpNext[XSIZE];

    /* Preprocessing */
    preMp(x, m, mpNext);

    /* Searching */
    i = j = 0;
    while (j < n) {
        while (i > -1 && x[i] != y[j])
            i = mpNext[i];
        i++;
        j++;
        if (i >= m) {
            res.push_back(j - i);
            i = mpNext[i];
        }
    }

    if(res.size() == 0) res.push_back(-1);
    return res;
}