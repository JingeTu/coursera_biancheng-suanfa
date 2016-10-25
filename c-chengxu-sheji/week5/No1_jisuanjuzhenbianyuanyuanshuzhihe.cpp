//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int array[100][100];

    int k, m, n, k_i, m_i, n_i, sum;
    std::cin >> k;
    k_i = k;
    while (k_i--) {
        std::cin >> m >> n;
        sum = 0;
        for (m_i = 0; m_i < m; ++m_i) {
            for (n_i = 0; n_i < n; ++n_i) {
                std::cin >> array[m_i][n_i];
                if (m_i == 0 || n_i == 0 || m_i == m - 1 || n_i == n - 1)
                    sum += array[m_i][n_i];
            }
        }
        std::cout << sum << std::endl;
    }

    return 0;
}