//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int i, max_odd, min_even, number;
    max_odd = 1;
    min_even = 100;

    for (i = 0; i < 6; ++i) {
        std::cin >> number;
        if (number % 2 == 1 && number > max_odd) { // odd
            max_odd = number;
        } else if (number % 2 == 0 && number < min_even) { // even
            min_even = number;
        }
    }

    int diff = max_odd - min_even;
    int diff_abs = diff > 0 ? diff : -1*diff;
    std::cout << diff_abs << std::endl;

    return 0;
}