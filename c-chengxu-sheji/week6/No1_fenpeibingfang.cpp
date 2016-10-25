//
// Created by 涂金戈 on 25/10/2016.
//

#include <iostream>
#include<iomanip>

int main() {

    char No[50][4];
    float severity[50];

    int m, i, j, k;
    char temp_No_char;
    float temp_severity;
    bool someone_move_in;
    float severity_threshold;
    std::cin >> m >> severity_threshold;

    for (i = 0; i < m; ++i) {
        std::cin >> No[i] >> severity[i];
    }

    for (i = 0; i < m - 1; ++i) {
        for (j = i; j < m; ++j) {
            if (severity[i] < severity[j]) {
                for (k = 0; k < 3; ++k) {
                    temp_No_char = No[i][k];
                    No[i][k] = No[j][k];
                    No[j][k] = temp_No_char;
                }
                temp_severity = severity[i];
                severity[i] = severity[j];
                severity[j] = temp_severity;
            }
        }
    }

    someone_move_in = false;
    for (i = 0; i < m; ++i) {
        if(severity[i] > severity_threshold) {
            someone_move_in = true;
            std::cout << No[i] << " " << std::fixed << std::setprecision(1) << severity[i] << "\n";
        }
    }

    if (!someone_move_in) {
        std::cout << "None.\n";
    }

    return 0;
}