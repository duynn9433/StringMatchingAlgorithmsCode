//
// Created by nndng on 5/16/2022.
//

#ifndef STRINGMATCHINGALGORITHMS_KNUTH_MORRIS_PRATT_H
#define STRINGMATCHINGALGORITHMS_KNUTH_MORRIS_PRATT_H
#include <bits/stdc++.h>
std::vector<int> KnuthMorrisPratt(char *x, int m, char *y, int n);
void preKmp(char *x, int m, int kmpNext[]);
#endif //STRINGMATCHINGALGORITHMS_KNUTH_MORRIS_PRATT_H
