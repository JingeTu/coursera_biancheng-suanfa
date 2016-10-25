//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    int n, x, y;
    std::cin >> n >> x >> y;

    int remain = (int)(n - y * (1 / (double)x));
    remain = remain > 0 ? remain : 0;

    std::cout << remain << "\n";

    return 0;
}