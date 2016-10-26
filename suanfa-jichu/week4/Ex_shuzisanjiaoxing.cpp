//
// Created by 涂金戈 on 25/10/2016.
//
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
 * */
/* // 记忆型递归 O(n^2)
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];

int MaxSum(int i, int j) {
    if (maxSum[i][j] != -1)
        return maxSum[i][j];
    if (i == n) maxSum[i][j] = D[i][j];
    else {
        int x = MaxSum(i + 1, j);
        int y = MaxSum(i + 1, j + 1);
        maxSum[i][j] = max(x, y) + D[i][j];
    }
    return maxSum[i][j];
}

int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++) {
            cin >> D[i][j];
            maxSum[i][j] = -1;
        }
    cout << MaxSum(1, 1) << endl;
    return 0;
}
*/

/*
// "人人为我"递推型动规程序
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];

int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= i; ++j)
            cin >> D[i][j];
    for (i = 1; i <= n; ++i) // 先直接写出最后一行
        maxSum[n][i] = D[n][i];
    for (i = n - 1; i >= 1; --i)
        for (j = 1; j <= i; ++j)
            maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + D[i][j];
    cout << maxSum[1][1] << endl;

    return 0;
}
*/

// "人人为我"递推型动规程序 空间优化
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int D[MAX][MAX];
int n;
int* maxSum;

int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= i; ++j)
            cin >> D[i][j];
    maxSum = D[n]; // 用最后一行存储maxSum
    for (i = n - 1; i >= 1; --i)
        for (j = 1; j <= i; ++j)
            maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];
    cout << maxSum[1] << endl;

    return 0;
}