//
// Created by 涂金戈 on 26/10/2016.
//
/*
2
9
1 2 2 2 2 3 3 3 1
1
1
 */

#include <iostream>
#include <cstring>

using namespace std;

struct Block {
    int color;
    int len;
};

struct Block segment[200]; // 用于存储块的数据，一个块对应 segment 中的一个 element，块的属性包括颜色、长度

int score[200][200][200]; // 存放计算结果，避免重复计算

int click_box(int start, int end, int extra_len) {
    int i, result, temp;
    if (score[start][end][extra_len] > 0) // 前面已经得到了计算结果
        return score[start][end][extra_len];
    result = segment[end].len + extra_len;
    result = result * result;
    if (start == end) { // 终止条件，把 segment[start] 与 extra_len 合并
        score[start][end][extra_len] = result;
        return score[start][end][extra_len];
    }
    result += click_box(start, end - 1, 0); // 将 segment[end] 与 extra_len 合并的结果
    for (i = end - 1; i >= start; --i) { // 遍历，寻找是否可以不直接把 segment[end] 与 extra_len 合并的块消除（等待合并的块再与前面的块合并），而得到更好的结果
        if (segment[i].color != segment[end].color)
            continue;
        // 找到了 start 到 end - 1 这些块中有块的颜色与 end 相同（即 i ），把 i 之后到 end 之间的所有块消除，让 i 与 end&extra_len 合并。
        temp = click_box(start, i, segment[end].len + extra_len) + click_box(i + 1, end - 1, 0);
        if (temp <= result) continue;
        result = temp;
    }
    score[start][end][extra_len] = result;
    return score[start][end][extra_len];
}

int main() {
    int t, n, i, j, end, color;
    cin >> t; // 多少组测试数据
    for (i = 0; i < t; ++i) {
        cin >> n; // 多少个方盒
        end = 0;
        cin >> segment[end].color;
        segment[end].len = 1;
        for (j = 1; j < n; ++j) { // 读入方盒
            cin >> color;
            if (color == segment[end].color) // 与当前 segment 颜色相同
                ++segment[end].len;
            else { // 与当前 segment 颜色不相同，新启用后面的一个 segment
                ++end;
                segment[end].color = color;
                segment[end].len = 1;
            }
        }
        memset(score, 0, sizeof(score));
        cout << "Case " << i + 1 << ": " << click_box(0, end, 0) << endl;
    }
    return 0;
}