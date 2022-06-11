//
// Created by nndng on 5/31/2022.
//

#include "Skip-Search.h"
#include "../graph/graph.h"
#include <bits/stdc++.h>
using namespace std;
#define XSIZE 128
#define ASIZE 128

std::vector<int> SkipSearch(char *x, int m, char *y, int n){
    vector<int> res;
    int i, j;
    List ptr, z[ASIZE];//z là bảng chữ cái

    /* Preprocessing */
    memset(z, NULL, ASIZE*sizeof(List));
    for (i = 0; i < m; ++i) {
        ptr = (List)malloc(sizeof(struct _cell));//cấp phát bộ nhớ cho 1 note
        if (ptr == NULL)
            error("SKIP");
        ptr->element = i;//vị trí trong x
        ptr->next = z[x[i]];//thêm vào danh sách vị trí xuất hiện
        z[x[i]] = ptr;//chuyển vị trí hiện thời sang vị trí xuất hiện lớn nhất
    }

    /* Searching */
    // kiểm tra các vị trí thứ m trong y
    for (j = m - 1; j < n; j += m)
        //kiểm tra các vị trí có thể xuất hiện kí tự y[j] trong x
        for (ptr = z[y[j]]; ptr != NULL; ptr = ptr->next)
            if (memcmp(x, y + j - ptr->element, m) == 0)
                res.push_back(j - ptr->element);

    return res;
}
