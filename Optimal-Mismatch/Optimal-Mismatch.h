//
// Created by nndng on 5/30/2022.
//

#ifndef STRINGMATCHINGALGORITHMS_OPTIMAL_MISMATCH_H
#define STRINGMATCHINGALGORITHMS_OPTIMAL_MISMATCH_H
#include <bits/stdc++.h>
typedef struct patternScanOrder {
    int loc;
    char c;
} pattern;
std::vector<int> OptimalMismatch(char *x, int m, char *y, int n);
/* Construct an ordered pattern from a string. */
void orderPattern(char *x, int m, int (*pcmp)(), pattern *pat);
/* Optimal Mismatch pattern comparison function. */
int optimalPcmp(pattern *pat1, pattern *pat2);
/* Find the next leftward matching shift for
   the first ploc pattern elements after a
   current shift or lshift. */
int matchShift(char *x, int m, int ploc,int lshift, pattern *pat);
/* Constructs the good-suffix shift table
   from an ordered string. */
void preAdaptedGs(char *x, int m, int adaptedGs[],pattern *pat);
#endif //STRINGMATCHINGALGORITHMS_OPTIMAL_MISMATCH_H
