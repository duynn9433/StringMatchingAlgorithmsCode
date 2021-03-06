//
// Created by nndng on 5/28/2022.
//

#include "Boyer-Moore.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 128
#define ASIZE 128

/**
 * @brief      { calculate the first index of character in pattern (from rigt to left, example:
 *             <br> gcagagag
 *             <br> 7654321x
 *             <br> -->
 *             <br> acgt
 *             <br> 1628 (first index)}
 *
 * @param      x     The pattern
 * @param      m     { size of x }
 * @param      bmBc[]     { pre table }
 *
 * @return     { void }
 */
void preBmBadCharacter(char *x, int m, int bmBc[]) {
    int i;

    for (i = 0; i < ASIZE; ++i)
        bmBc[i] = m;
    for (i = 0; i < m - 1; ++i)
        bmBc[x[i]] = m - i - 1;
}

/**
 * @brief      { 1 <= i < m, suff[i]=max{k : x[i-k+1 ... i]=x[m-k ... m-1]
 *              <br> i: index miss-match
 *              <br> find the length of longest v of u}
 *
 * @param      x     The pattern
 * @param      m     { size of x }
 * @param      suff[]     { }
 *
 * @return     { void }
 */
void suffixes(char *x, int m, int *suff) {
    //g - f <=> dau - cuoi doan can tim
    int f, g, i;

    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i) {
        //dung lai
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g)
                g = i;
            f = i;
            //tim doan dai nhat x[i+1-k ... i] (= x[m-k ... m-1])
            while (g >= 0 && x[g] == x[g + m - 1 - f])
                --g;
            // tinh k
            suff[i] = f - g;
        }
    }
}
/**
 * @brief      {
 *              <br> bmGs[0] as the length of the period of x
 *              <br> Let us define two conditions:
 *              <br>&#9    Cs(i, s): for each k such that i < k < m, s geq k or x[k-s]=x[k]
 *              <br>&#9    Co(i, s): if s <i then x[i-s] neq x[i]
 *              <br>Then, for 0 <= i < m: bmGs[i+1]=min{s>0 : Cs(i, s) and Co(i, s) hold}}
 *
 * @param      x     The pattern
 * @param      m     { size of x }
 * @param      bmGs[]     { }
 *
 * @return     { }
 */
void preBmGoodSuffix(char *x, int m, int bmGs[]) {
    int i, j, suff[XSIZE];

    suffixes(x, m, suff);

    for (i = 0; i < m; ++i)
        bmGs[i] = m;
    j = 0;
    //th2: khong co u = x[i+1 ... m-1] = x[j+i+1 ... j+m-1]
    for (i = m - 1; i >= 0; --i)
        //doan v dai tu 0 den i
        //dieu kien t????ng ??????ng v l?? vi???n c???a x (b???t ?????u t??? 0)
        //suff l?? ??o???n d??i nh???t c?? th??? k b???t ?????u t??? 0
        if (suff[i] == i + 1)
            //kiem tra tu 0 den m-1-i (?????i x???ng v???i t??? i --> m-1)
            //vd: 0 |1 2 3 4 5 |6 7 (i=6)
            for (; j < m - 1 - i; ++j)
                //=m l?? coi nh?? kh??ng c?? v
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
    //th1: co u = x[i+1 ... m-1] = x[j+i+1 ... j+m-1]
    for (i = 0; i <= m - 2; ++i)
        //suff l?? ????? d??i d??i nh???t v c???a u (c?? th??? k b???t ?????u t??? 0)
        //m-1-suff v??? tr?? c?? ??i???m a !=c khi th???c hi???n suffixes
        //m-1-i d???ch t??? v??? tr?? a ra c
        //suff =0: t??? c??ng ph???i d???ch ra ????? g???p n?? (c??ng ph???i fail th?? ?????n l?????t n?? so v???i k?? t??? ????)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}


std::vector<int> BoyerMoore(char *x, int m, char *y, int n){
    vector<int> res;
    int i, j, bmGs[XSIZE], bmBc[ASIZE];

    /* Preprocessing */
    preBmGoodSuffix(x, m, bmGs);
    preBmBadCharacter(x, m, bmBc);

    /* Searching */
    j = 0;
    while (j <= n - m) {
        //ch???y ?????n khi g???p a !=b
        for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
        //tr??ng t???t c???
        if (i < 0) {
            res.push_back(j);
            j += bmGs[0];
        }
        //kh??ng tr??ng
        else
            j += max(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
    }
    return res;
}
