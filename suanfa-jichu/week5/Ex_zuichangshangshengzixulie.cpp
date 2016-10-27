//
// Created by 涂金戈 on 26/10/2016.
//
/*
7
1 7 3 5 9 4 8
 */
/*
// "我为人人" 递推型动规程序
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int a[MAXN];
int maxLen[MAXN];

int main() {

    int N;
    cin >> N;
    cin.get();

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        maxLen[i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        // 每次求以第 i 个数为终点的最长上升子序列的长度
        for (int j = 1; j < i; ++j) {
            // 查看以第 j 个数为终点的最长上升子序列
            if (a[i] > a[j])
                maxLen[i] = max(maxLen[i], maxLen[j] + 1);
        }
    }

    cout << *max_element(maxLen + 1, maxLen + N + 1);

    return 0;
}
*/

// "我为人人"递推型动规程序

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int a[MAXN];
int maxLen[MAXN];

int main() {

    int N;
    cin >> N;
    cin.get();

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        maxLen[i] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (a[j] > a[i])
                maxLen[j] = max(maxLen[j], maxLen[i] + 1);
        }
    }

    cout << *max_element(maxLen + 1, maxLen + N + 1);

    return 0;
}