//
// Created by 涂金戈 on 26/10/2016.
//

#include <iostream>
#include <cstring>

using namespace std;

long long F[250][250]; // F[N][k] 表示数字 N 的单峰回文中开头数字 >=k 的数目
long long G[250][250]; // G[N][k] 表示数字 N 的单峰回文中开头数字为 k 的数目

long long GetFNk(int N, int k);

long long GetGNk(int N, int k) {
    if (G[N][k] != -1) { // 如果 G[N][k] 已经有值，那么可以直接返回
        return G[N][k];
    }
    if (N < k) { // 如果 N < k，不可能形成回文
        G[N][k] = 0;
        return G[N][k];
    }
    if (N == k) { // 如果 N == k，单峰回文是 N 自身
        G[N][k] = 1;
        return G[N][k];
    }
    if (N == 2 && k == 1) { // 初始条件
        G[N][k] = 1;
        return G[N][k];
    }
    if (N == 1 && k == 1) { // 初始条件
        G[N][k] = 1;
        return G[N][k];
    }

    if (N == 2 * k) { // 如果 N == 2 * k，形成的回文就是 (k k)，而 F[N - 2 * k][k] = F[0][k] = 0，所以需要在这里止步
        G[N][k] = 1;
        return G[N][k];
    }

    G[N][k] = GetFNk(N - 2 * k, k);

    return G[N][k];
}

long long GetFNk(int N, int k) {
    if (F[N][k] != -1) { // F[N][k] 已经有值，直接返回
        return F[N][k];
    }
    if (N < k) { // 如果 N < k，不可能形成回文
        F[N][k] = 0;
        return F[N][k];
    }
    int half_N = N / 2;
    long long FNk = 0;
    int i;
    for (i = k; i <= half_N; ++i) {
        FNk += GetGNk(N, i);
    }
    FNk += GetGNk(N, N);
    F[N][k] = FNk;
    return F[N][k];
}

int main() {

    memset(F, -1, sizeof(F));
    memset(G, -1, sizeof(G));

    int N;

    while (true) {
        cin >> N;
        if (N == 0)
            break;
        cout << N << " " << GetFNk(N, 1) << "\n";
    }

    return 0;
}