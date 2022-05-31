//
// Created by nndng on 5/30/2022.
//

#include "Optimal-Mismatch.h"
#include "../Quick-Search/Quick-Search.h"
#include <bits/stdc++.h>
#include <stdlib.h>     /* qsort */
using namespace std;
#define XSIZE 128
#define ASIZE 128
//https://dl.acm.org/doi/pdf/10.1145/79173.79184

int freq[ASIZE];
/* pattern: c=character, loc=location */
/* Construct an ordered pattern from a string. */
void orderPattern(char *x, int m, int (*pcmp)(), pattern *pat) {
    int i;

    for (i = 0; i <= m; ++i) {
        pat[i].loc = i;
        pat[i].c = x[i];
    }
    qsort(pat, m, sizeof(pattern), reinterpret_cast<int (*)(const void *, const void *)>(pcmp));
}


/* Optimal Mismatch pattern comparison function. */
int optimalPcmp(pattern *pat1, pattern *pat2) {
    float fx;
    //độ chênh lệch  tần số xuất hiện
    fx = freq[pat1->c] - freq[pat2->c];
    //nếu độ chênh lệch tần số xuất hiện bằng nhau thì so sánh vị trí
    return(fx ? (fx > 0 ? 1 : -1) : (pat2->loc - pat1->loc));
}


/**
 * @brief      { find the next leftward matching shift for
 *              <br> the first ploc pattern elements after a
 *              <br> current shift or lshift}
 *
 * @param      x     The pattern string
 * @param      m     { size of x }
 * @param      ploc  { the number of pattern elements to match}
 * @param      lshift  { smallest left shift to consider }
 * @param      pat     { the ordered pattern }
 *
 * @return     { the next left shift value }
 */
int matchShift(char *x, int m, int ploc,
               int lshift, pattern *pat) {
    int i, j;

    for (; lshift < m; ++lshift) {//scan left fo matching shift
        // ploc kí tự đầu tiên của pattern (vd 2 kí tự đầu)
        i = ploc;
        while (--i >= 0) {
            /*j là vị trí sau khi shift,
             * <0 nghĩa là k tồn tại --> tìm kí tiếp theo
             * all preceding chars must match */
            if ((j = (pat[i].loc - lshift)) < 0)
                continue;
            if (pat[i].c != x[j])
                break;
        }
        //all matched
        if (i < 0)
            break;
    }
    return(lshift);
}


/* Constructs the good-suffix shift table
   from an ordered string. */
void preAdaptedGs(char *x, int m, int adaptedGs[],
                  pattern *pat) {
    int lshift; //current left shift
    int i, ploc;//pattern location counter

    //first initialize for the minimum lshift
    adaptedGs[0] = lshift = 1;  //no preceding chars, so =1
    for (ploc = 1; ploc <= m; ++ploc) { // for each pattern location
        //tìm lshift thoả mãn: ploc kí tự đầu tiên của pattern trùng sau khi lshift
        //scan leftward for first matching shift
        lshift = matchShift(x, m, ploc, lshift, pat);
        adaptedGs[ploc] = lshift;
    }
    for (ploc = 0; ploc <= m; ++ploc) {
        lshift = adaptedGs[ploc];//get init matching shift
        while (lshift < m) {//when current shift is less than pattern length
            /*already have a matching shift here
             * also require current char must not match*/
            i = pat[ploc].loc - lshift;
            //mismatch
            if (i < 0 || pat[ploc].c != x[i])
                break;
            //if not: scan further for next matching shift
            ++lshift;
            lshift = matchShift(x, m, ploc, lshift, pat);
        }
        adaptedGs[ploc] = lshift;//set final shift
    }
}


/* Optimal Mismatch string matching algorithm. */
vector<int> OptimalMismatch(char *x, int m, char *y, int n) {
    vector<int> res;
    int i, j, adaptedGs[XSIZE], qsBc[ASIZE];
    pattern pat[XSIZE];

    /* Preprocessing */
    orderPattern(x, m, reinterpret_cast<int (*)(void)>(optimalPcmp), pat);
    preQsBc(x, m, qsBc);
    preAdaptedGs(x, m, adaptedGs, pat);

    /* Searching */
    j = 0;
    while (j <= n - m) {
        i = 0;
        //do theo thứ tự của pattern, vị trí trên cửa sổ nhảy theo vị trí pattern
        while (i < m && pat[i].c == y[j + pat[i].loc])
            ++i;
        if (i >= m)
            res.push_back(j);
        j += max(adaptedGs[i],qsBc[y[j + m]]);
    }
    return res;
}