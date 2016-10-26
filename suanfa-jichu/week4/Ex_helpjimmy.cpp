//
// Created by 涂金戈 on 25/10/2016.
//

/*
1
3 8 17 20
0 10 8
0 10 13
4 14 3
 */
/*
// 记忆递归
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 1000
#define INFINITE 1000000

int t, n, x, y, maxHeight;

struct Platform {
    int Lx, Rx, h;
    bool operator < (const Platform & p2) const {
        return h > p2.h;
    }
};

Platform platForms[MAX_N + 10];
int leftMinTime[MAX_N + 10];
int rightMinTime[MAX_N + 10];
int L[MAX_N + 10];

int MinTime(int l, bool bLeft) {
    int y = platForms[l].h;
    int x;
    if (bLeft)
        x = platForms[l].Lx;
    else
        x = platForms[l].Rx;
    int i;
    for (i = l + 1; i <= n; ++i) {
        if (platForms[i].Lx <= x && platForms[i].Rx >= x)
            break;
    }
    if (i <= n) {
        if (y - platForms[i].h > maxHeight)
            return INFINITE;
    }
    else {
        if (y > maxHeight)
            return INFINITE;
        else
            return y;
    }

    int nLeftTime = y - platForms[i].h + x - platForms[i].Lx;
    int nRightTime = y - platForms[i].h + platForms[i].Rx - x;
    if(leftMinTime[i] == -1)
        leftMinTime[i] = MinTime(i, true);
    if(L[i] == -1)
        L[i] = MinTime(i, false);
    nLeftTime += leftMinTime[i];
    nRightTime += L[i];
    if(nLeftTime < nRightTime)
        return nLeftTime;
    return nRightTime;
}

int main() {
    scanf("%d",&t);
    for(int i = 0;i < t; ++i) {
        memset(leftMinTime, -1, sizeof(leftMinTime));
        memset(L, -1, sizeof(rightMinTime));
        scanf("%d%d%d%d", &n, &x, &y, &maxHeight);
        platForms[0].Lx = x;
        platForms[0].Rx = x;
        platForms[0].h = y;
        for(int j = 1; j <= n; ++j)
            scanf("%d%d%d", &platForms[j].Lx, &platForms[j].Rx, &platForms[j].h);
        sort(platForms, platForms+n+1);
        printf("%d\n", MinTime(0, true));
    }
    return 0;
}
*/

// 递推
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 1000
#define INFINITE 1000000

int t, n, x, y, maxHeight;

struct Platform{
    int Lx, Rx, h;
    bool operator < (const Platform & p2) const {
        return h > p2.h;
    }
};

Platform platforms[MAX_N + 10];
int leftMinTime[MAX_N + 10];
int rightMinTime[MAX_N + 10];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &x, &y, &maxHeight);
        platforms[0].Lx = x;
        platforms[0].Rx = x;
        platforms[0].h = y;
        for (int j = 1; j <= n; ++j) {
            scanf("%d%d%d", &platforms[j].Lx, &platforms[j].Rx, &platforms[j].h);
        }
        sort(platforms, platforms + n + 1);
        for (int i = n; i >= 0; --i) {
            int j;
            for (j = i + 1; j <= n; ++j) {
                if (platforms[i].Lx <= platforms[j].Rx && platforms[i].Lx >= platforms[j].Lx)
                    break;
            }
            if (j > n) {
                if (platforms[i].h > maxHeight)
                    leftMinTime[i] = INFINITE;
                else
                    leftMinTime[i] = platforms[i].h;
            }
            else {
                int y = platforms[i].h - platforms[j].h;
                if (y > maxHeight)
                    leftMinTime[i] = INFINITE;
                else
                    leftMinTime[i] = y + min(leftMinTime[j] + platforms[i].Lx - platforms[j].Lx, rightMinTime[j] + platforms[j].Rx - platforms[i].Lx);
            }
            for (j = i + 1; j <= n; ++j) {
                if (platforms[i].Rx <= platforms[j].Rx && platforms[i].Rx >= platforms[j].Lx)
                    break;
            }
            if(j > n) {
                if (platforms[i].h > maxHeight)
                    rightMinTime[i] = INFINITE;
                else
                    rightMinTime[i] = platforms[i].h;
            }
            else {
                int y = platforms[i].h - platforms[j].h;
                if (y > maxHeight)
                    rightMinTime[i] = INFINITE;
                else
                    rightMinTime[i] = y + min(leftMinTime[j] + platforms[i].Rx - platforms[j].Lx, rightMinTime[j] + platforms[j].Rx - platforms[i].Rx);
            }
        }
        printf("%d\n", min(leftMinTime[0],rightMinTime[0]));
    }
    return 0;
}