//
// Created by 涂金戈 on 27/10/2016.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_CHARM 3402
#define MAX_WEIGHT_LIMIT 12880

int F[MAX_CHARM + 1][MAX_WEIGHT_LIMIT + 1]; // F[i][v] ，前 i 个 charm 的子集，其 weight 恰好为 v
int W[MAX_CHARM + 1]; // weights
int D[MAX_CHARM + 1]; // desirabilities

int GetFiv(int i, int v);

int MaxDesireablity(int N, int M) {
    int M_i, max_D, D;
    max_D = 0;
    for (M_i = 0; M_i <= M; ++M_i) { // 对重量进行遍历
        D = GetFiv(N, M_i);
        if (max_D < D) {
            max_D = D;
        }
    }
    return max_D;
}

int GetFiv(int i, int v) {
    if (F[i][v] != -1) { // 如果已经求得，就不用再计算了，直接返回
        return F[i][v];
    }
    if (i == 0) { // 如果是前 0 个 charm，直接返回 0
        F[i][v] = 0;
        return F[i][v];
    }
    if (v == 0) { // 如果 weight 限制为 0，任何 charm 都放不了，返回 0
        F[i][v] = 0;
        return F[i][v];
    }
    int D1 = GetFiv(i - 1, v); // 第 i 个 charm 不放入，前 i - 1 个 charm 的子集，weight 刚好是 v 的 Desirability
    int D2;
    if (v - W[i] < 0) // 第 i 个 charm 放入，那么前 i - 1 个 charm 的子集，weight 应该刚好是 v - W[i]
        D2 = 0;
    else
        D2 = GetFiv(i - 1, v - W[i]) + D[i];
    F[i][v] = max(D1, D2);
    return F[i][v];
}

int main () {

    int M, N, i;

    memset(F, -1, sizeof(F));

    cin >> N >> M; // N 是待选 charm 的总数，M 是 weight limit

    for (i = 1; i <= N; ++i) {
        cin >> W[i] >> D[i];
    }

    cout << MaxDesireablity(N, M) << endl;

    return 0;
}