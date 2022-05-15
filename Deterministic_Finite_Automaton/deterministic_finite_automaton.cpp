//
// Created by nndng on 3/30/2022.
//

#include "deterministic_finite_automaton.h"
#include "../graph/graph.h"
#include <bits/stdc++.h>
using namespace std;

void preAut(char *x, int m, Graph aut) {
    int i, state, target, oldTarget;

    for (state = getInitial(aut), i = 0; i < m; ++i) {
        oldTarget = getTarget(aut, state, x[i]);
        target = newVertex(aut);
        setTarget(aut, state, x[i], target);
        copyVertex(aut, target, oldTarget);
        state = target;
    }
    setTerminal(aut, state);
}


vector<int> AUT(char *x, int m, char *y, int n) {
    vector<int> res;
    int j, state;
    Graph aut;

    /* Preprocessing */
//    aut = newAutomaton(m + 1, (m + 1)*ASIZE); *******error
    preAut(x, m, aut);

    /* Searching */
    for (state = getInitial(aut), j = 0; j < n; ++j) {
        state = getTarget(aut, state, y[j]);
        if (isTerminal(aut, state))
            res.push_back(j - m + 1);
    }

    if(res.size() == 0) res.push_back(-1);
    return res;
}