//
// Created by nndng on 5/28/2022.
//

#ifndef STRINGMATCHINGALGORITHMS_BOYER_MOORE_H
#define STRINGMATCHINGALGORITHMS_BOYER_MOORE_H
#include <bits/stdc++.h>
std::vector<int> BoyerMoore(char *x, int m, char *y, int n);
void preBmBadCharacter(char *x, int m, int bmBc[]);
void preBmGoodSuffix(char *x, int m, int bmGs[]);
#endif //STRINGMATCHINGALGORITHMS_BOYER_MOORE_H
