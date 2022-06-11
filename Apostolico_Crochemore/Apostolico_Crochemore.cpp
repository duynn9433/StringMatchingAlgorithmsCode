//
// Created by nndng on 5/27/2022.
//

#include "Apostolico_Crochemore.h"
#include "../Knuth-Morris-Pratt/Knuth-Morris-Pratt.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 100

std::vector<int> ApostolicoCrochemore(char *x, int m, char *y, int n){
    vector<int> res;
    int i, j, k, ell, kmpNext[XSIZE]; //ell = L kí tự đầu tiên khác x0

    /* Preprocessing */
    preKmp(x, m, kmpNext);
    //tìm ki tự đầu tiên khác x0
    for (ell = 1; x[ell - 1] == x[ell]; ell++);
    if (ell == m)
        ell = 0;

    /* Searching */
    i = ell;
    j = k = 0;
    while (j <= n - m) {
        while (i < m && x[i] == y[i + j])
            ++i;
        //trường hợp 3 i=m
        if (i >= m) {
            //tìm k
            while (k < ell && x[k] == y[j + k])
                ++k;
            //k=L => tìm thấy
            if (k >= ell)
                res.push_back(j);
        }

        //khi i luon < m
        j += (i - kmpNext[i]); //dịch cửa sổ
        //trường hợp 1: i=L
        if (i == ell)
            k = max(0, k - 1);
        //th2: L<i<m
        //  2.1
        else if (kmpNext[i] <= ell) {
            k = max(0, kmpNext[i]);
            i = ell;
        }
        //  2.2
        else {
            k = ell;
            i = kmpNext[i];
        }
    }
    return res;
}