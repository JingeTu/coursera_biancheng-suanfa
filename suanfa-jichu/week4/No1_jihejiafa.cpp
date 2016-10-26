//
// Created by 涂金戈 on 26/10/2016.
//

/*
2
99
3
49 49 49
2
50 50
11
9
1 2 3 4 5 6 7 8 9
10
10 9 8 7 6 5 4 3 2 1
 * */

#include <iostream>
#include <algorithm>

#define MAX_ELE_PER_SET 10000

int main() {

    int n, s, a, b, i, r_i, c_i, temp_count;
    bool r_turn;
    std::cin >> n;
    std::cin.get();

    int A[MAX_ELE_PER_SET + 1], B[MAX_ELE_PER_SET + 1];

    while (n--) {
        std::cin >> s;
//        std::cin.get();
        std::cin >> a;
//        std::cin.get();
        for (i = 1; i <= a; ++i) {
            std::cin >> A[i];
        }
//        std::cin.get();
        std::cin >> b;
//        std::cin.get();
        for (i = 1; i <= b; ++i) {
            std::cin >> B[i];
        }

        // pairCount[i][j] 表示 A 中前 i 个元素组成的子集和 B 中前 j 个元素组成的子集，对应的最大组数
        // pairCount[i][j] => pairCount[i * (b + 1) + j]  1<=i<=a+1, 1<=j<=b+1
        // pairCount 可以再进行优化，现在浪费了很多空间
        int* pairCount = new int[(a + 1) * (b + 1)];

        // 优化：现将 A 和 B 中的元素从小到大排序
        std::sort(A + 1, A + a + 1);
        std::sort(B + 1, B + b + 1);

/* Time Limit Exceeded
        // 初始化 pairCount[i][0] 与 pairCount[0][j] 也就是第一行与第一列，因为其中有一个集合元素没有用到，所以所有的值都设为 0
//        for (r_i = 0; r_i <= a; ++r_i) {
//            pairCount[r_i * (b + 1) + 0] = 0;
//        }
//        for (c_i = 0; c_i <= b; ++c_i) {
//            pairCount[0 * (b + 1) + c_i] = 0;
//        }
d
        for (r_i = 1; r_i <= a; ++r_i) {
            for (c_i = 1; c_i <= b; ++c_i) {
                //pairCount[r_i * (b + 1) + c_i] = pairCount[r_i * (b + 1) + (c_i - 1)] + B 集合中第 c_i 个元素与 A 集合中前 r_i 个元素和为 s 的配对数
                temp_count = 0;
                for (i = 1; i <= r_i; ++i) {
                    if (A[i] + B[c_i] == s) {
                        ++temp_count;
                    }
                    else if (A[i] + B[c_i] > s) {
                        break;
                    }
                }
                pairCount[r_i * (b + 1) + c_i] = pairCount[r_i * (b + 1) + (c_i - 1)] + temp_count;
            }
        }
*/

        // A 和 B 的子集合交替 +1，也就是阶梯式地往下走
        // 但是如果 a != b，阶梯式走到最右侧或者最左侧之后需要再进行一些计算
        pairCount[0 * (b + 1) + 0] = 0;
        pairCount[0 * (b + 1) + 1] = 0;
        r_i = 1;
        c_i = 1;
        r_turn = false;

        while (r_i <= a && c_i <= b) {
            if (r_turn) {
                // 这一次结束后加的是r_i，那么 pairCount[r_i * (b + 1) + c_i] 使用其左侧的 pairCount[r_i * (b + 1) + (c_i - 1)] 更新
                // pairCount[r_i * (b + 1) + c_i] = pairCount[r_i * (b + 1) + (c_i - 1)] + B 集合中第 c_i 个元素与 A 集合中前 r_i 个元素和为 s 的配对数
                temp_count = 0;
                for (i = 1; i <= r_i; ++i) {
                    if (A[i] + B[c_i] == s) {
                        ++temp_count;
                    }
                    else if (A[i] + B[c_i] > s) {
                        break;
                    }
                }
                pairCount[r_i * (b + 1) + c_i] = pairCount[r_i * (b + 1) + (c_i - 1)] + temp_count;
                ++r_i;
                r_turn = false;
            }
            else {
                // 这一次结束后加的是c_i, 那么 pairCount[r_i * (b + 1) + c_i] 使用其上方的 pairCount[(r_i - 1) * (b + 1) + c_i] 更新
                // pairCount[r_i * (b + 1) + c_i] = pairCount[(r_i - 1) * (b + 1) + c_i] + A 集合中第 r_i 个元素与 B 集合中前 c_i 个元素和为 s 的配对数
                temp_count = 0;
                for (i = 1; i <= c_i; ++i) {
                    if (B[i] + A[r_i] == s) {
                        ++temp_count;
                    }
                    else if (B[i] + A[r_i] > s) {
                        break;
                    }
                }
                pairCount[r_i * (b + 1) + c_i] = pairCount[(r_i - 1) * (b + 1) + c_i] + temp_count;
                ++c_i;
                r_turn = true;
            }
        }

        // 如果 pairCount 不是方阵（a != b），跳出上面的循环需要再继续计算
        if (r_i == a + 1 && c_i < b) {
            r_i = a;
            ++c_i;
            while (c_i <= b) {
                temp_count = 0;
                for (i = 1; i <= r_i; ++i) {
                    if (A[i] + B[c_i] == s) {
                        ++temp_count;
                    }
                    else if (A[i] + B[c_i] > s) {
                        break;
                    }
                }
                pairCount[r_i * (b + 1) + c_i] = pairCount[r_i * (b + 1) + (c_i - 1)] + temp_count;
                ++c_i;
            }
        }
        else if (c_i == b + 1 && r_i < a) {
            c_i = b;
            ++r_i;
            while (r_i <= a) {
                temp_count = 0;
                for (i = 1; i <= c_i; ++i) {
                    if (B[i] + A[r_i] == s) {
                        ++temp_count;
                    }
                    else if (B[i] + A[r_i] > s) {
                        break;
                    }
                }
                pairCount[r_i * (b + 1) + c_i] = pairCount[(r_i - 1) * (b + 1) + c_i] + temp_count;
                ++r_i;
            }
        }

        std::cout << pairCount[a * (b + 1) + b] << std::endl;

        delete[] pairCount;
    }

    return 0;
}

// 这个是网上找到的别人代码，如果不用动态规划会简单得多。
//#include <stdio.h>
//#include <stdlib.h>
//int compare(const void *e1,const void *e2)
//{
//    return *(int*)e1-*(int*)e2;
//}
//
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    while(n--)
//    {
//        int s,sum=0;
//        scanf("%d",&s);
//        int pa,pb,i,j;
//        scanf("%d",&pa);
//        int *a=(int*)malloc(sizeof(int)*pa);
//        for(i=0;i<pa;i++) scanf("%d",&a[i]);
//        qsort(a,pa,sizeof(int),compare);
//        scanf("%d",&pb);
//        int *b=(int*)malloc(sizeof(int)*pb);
//        for(i=0;i<pb;i++) scanf("%d",&b[i]);
//        qsort(b,pb,sizeof(int),compare);
//        for(i=0;i<pa;i++)
//            for(j=pb-1;j>=0;j--)
//            {
//                if(a[i]+b[j]==s) sum++;
//            }
//        printf("%d\n",sum);
//    }
//    return 0;
//}