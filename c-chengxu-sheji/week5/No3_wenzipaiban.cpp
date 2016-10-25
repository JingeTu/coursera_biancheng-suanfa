//
// Created by 涂金戈 on 25/10/2016.
//
#include <iostream>

#define MAX_CHARS_PER_LINE 80

int main() {

    int n, w_i, c_count, c_i;
    std::cin >> n;
    std::cin.get();
    char (*words)[40] = new char[n][40];

    for (w_i = 0; w_i < n; ++w_i) {
        std::cin >> words[w_i];
    }

    c_i = 0;
    while (words[0][c_i] != '\0') ++c_i;
    std::cout << words[0];
    c_count = c_i;

    for (w_i = 1; w_i < n; ++w_i) {
        c_i = 0;
        while (words[w_i][c_i] != '\0') {
            ++c_i;
        }
        if (c_count + c_i + 1 > MAX_CHARS_PER_LINE) {
            c_count = c_i;
            std::cout << "\n";
            std::cout << words[w_i];
        }
        else {
            c_count += c_i + 1;
            std::cout << " " << words[w_i];
        }
    }

    delete[] words;

    return 0;
}