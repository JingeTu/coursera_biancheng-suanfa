//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>

int main() {

    const float Pi = 3.14159;

    int h, r;
    std::cin >> h >> r;

    float bucket_volume_liter = (float)Pi * r * r * h / 1000;

    std::cout << (int)(20/bucket_volume_liter + 1) << std::endl;

    return 0;
}