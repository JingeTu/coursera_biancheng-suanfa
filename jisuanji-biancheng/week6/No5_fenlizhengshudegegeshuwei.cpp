//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int num, i;
    std::cin >> num;
    int digits[3];

    i = 0;
    while(num > 0) {
        digits[i++] = num % 10;
        num /= 10;
    }

    for (i = 2; i >= 0; --i) {
        std::cout << digits[i] << std::endl;
    }

    return 0;
}