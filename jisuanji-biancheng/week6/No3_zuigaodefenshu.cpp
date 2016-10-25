//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int score, n, s_i, max_score;
    std::cin >> n;
    std::cin.get();

    max_score = -1;
    for (s_i = 0; s_i < n; ++s_i) {
        std::cin >> score;
        if (score > max_score) {
            max_score = score;
        }
    }

    std::cout << max_score << "\n";

    return 0;
}