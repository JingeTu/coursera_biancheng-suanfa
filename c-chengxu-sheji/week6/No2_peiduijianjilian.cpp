//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int n, i, c_i;
    std::cin >> n;
    std::cin.get();
    char (*DNA_sequences)[255] = new char[n][255];

    for (i = 0; i < n; ++i) {
        std::cin >> DNA_sequences[i];
        c_i = 0;
        while (DNA_sequences[i][c_i] != '\0') {
            switch (DNA_sequences[i][c_i]) {
                case 'A':
                std::cout << 'T';
                    break;
                case 'G':
                std::cout << 'C';
                    break;
                case 'T':
                std::cout << 'A';
                    break;
                case 'C':
                std::cout << 'G';
                    break;
            }
            ++c_i;
        }
        std::cout << '\n';
    }

    delete[] DNA_sequences;

    return 0;
}