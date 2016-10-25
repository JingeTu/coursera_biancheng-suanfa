//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int height[22][22], r_i, c_i;

    for (r_i = 0; r_i < 22; ++r_i) {
        for (c_i = 0; c_i < 22; ++c_i) {
            height[r_i][c_i] = 0;
        }
    }

    int m, n;
    std::cin >> m >> n;

    for (r_i = 1; r_i <= m; ++r_i) {
        for (c_i = 1; c_i <= n; ++c_i) {
            std::cin >> height[r_i][c_i];
        }
    }

    for (r_i = 1; r_i <= m; ++r_i) {
        for (c_i = 1; c_i <= n; ++c_i) {
            if (height[r_i][c_i] >= height[r_i - 1][c_i] &&
                    height[r_i][c_i] >= height[r_i + 1][c_i] &&
                    height[r_i][c_i] >= height[r_i][c_i - 1] &&
                    height[r_i][c_i] >= height[r_i][c_i + 1])
                std::cout << r_i - 1 << " " << c_i - 1 << "\n";
        }
    }

    return 0;
}