//
// Created by 涂金戈 on 26/10/2016.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int UP = 0;
const int DOWN = 1;
const int MAXN = 25;
long long C[MAXN][MAXN][2];

void Init(int n) {
    memset(C, 0, sizeof(C));
    C[1][1][UP] = C[1][1][DOWN] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) {
            for (int M = k; M < i; ++M)
                C[i][k][UP] += C[i - 1][M][DOWN];
            for (int N = 1; N <= k - 1; ++N)
                C[i][k][DOWN] += C[i - 1][N][UP];
        }
    }
}

void Print(int n, long long cc) {
    long long skipped = 0;
    int seq[MAXN];
    int used[MAXN];
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; ++i) {
        int No = 0;
        for (int k = 1; k <= n; ++k) {
            skipped = 0;
            if (!usedp[k]) {
                ++No;
                if (i == 1)
                    skipped = C[n][No][UP] + C[n][No][DOWN];
                else {
                    if (k > seq[i - 1] && (i <= 2 || seq[i - 2] > seq[i - 1]))
                        skipped = C[n - i + 1][No][DOWN];
                    else if (k < seq[i - 1] && (i <= 2 || seq[i - 2] < seq[i - 1]))
                        skipped = C[n - i + 1][No][UP];
                }
                if (skipped >= cc)
                    break;
                else
                    cc -= skipped;
            }
            used[k] = true;
            seq[i] = k;
        }
        for (int i = 1; i <= n; ++i)
            if (i < n)
                printf("%d ", seq[i]);
            else
                printf("%d", seq[i]);
        printf("\n");
    }
}

int main() {
    int T, n;
    long long c;
    Init(20);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &c);
        Print(n, c);
    }
    return 0;
}