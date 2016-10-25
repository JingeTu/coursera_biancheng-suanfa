//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int array[100][100];

    int m, n, m_i, n_i, i, j, k;
    std::cin >> m >> n;

    for (m_i = 0; m_i < m; ++m_i) {
        for (n_i = 0; n_i < n; ++n_i) {
            std::cin >> array[m_i][n_i];
        }
    }

    // 相当于把整个矩阵范围扩大到2倍，一个直角三角形，两条直角边的长度为m + n
    // 遍历每一条副对角线
    for (k = 0; k < m + n - 1; ++k) {
        // 对于每一条副对角线，遍历点的数目是k，按顺序从行号0到k，列号从k到0
        for (i = 0; i <= k; ++i) { // 对行的遍历
            j = k - i;
            if (i < m && j < n)
                std::cout << array[i][j] << std::endl;
        }
    }

    return 0;
}