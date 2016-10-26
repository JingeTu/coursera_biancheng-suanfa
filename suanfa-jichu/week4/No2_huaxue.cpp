//
// Created by 涂金戈 on 26/10/2016.
//
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
 * */
#include <iostream>
#include <algorithm>

struct DEMPoint {
    int row_num;
    int col_num;
    int height;
    DEMPoint(int row, int col, int h):row_num(row), col_num(col), height(h) {}
    DEMPoint(){}
    bool operator < (const DEMPoint & p2) const {
        return height < p2.height;
    }
};

int main() {

    int mesh_heights[100][100];
    int L[100][100];

    int R, C, R_i, C_i, i, row_num, col_num, height, max_L;

    std::cin >> R >> C;
    std::cin.get();

    DEMPoint* dem_points = new DEMPoint[R * C];

    for (R_i = 0; R_i < R; ++R_i) {
        for (C_i = 0; C_i < C; ++C_i) {
            std::cin >> mesh_heights[R_i][C_i];
            L[R_i][C_i] = 1;
            dem_points[R_i * C + C_i].row_num = R_i;
            dem_points[R_i * C + C_i].col_num = C_i;
            dem_points[R_i * C + C_i].height = mesh_heights[R_i][C_i];
        }
    }

    std::sort(dem_points, dem_points + R * C);

    for (i = 0; i < R * C; ++i) {
        max_L = 0;
        row_num = dem_points[i].row_num;
        col_num = dem_points[i].col_num;
        height = dem_points[i].height;
        if (row_num - 1 >= 0)
            if (mesh_heights[row_num - 1][col_num] < height && L[row_num - 1][col_num] > max_L) {
                max_L = L[row_num - 1][col_num];
            }
        if (row_num + 1 < R)
            if (mesh_heights[row_num + 1][col_num] < height && L[row_num + 1][col_num] > max_L) {
                max_L = L[row_num + 1][col_num];
            }
        if (col_num - 1 >= 0)
            if (mesh_heights[row_num][col_num - 1] < height && L[row_num][col_num - 1] > max_L) {
                max_L = L[row_num][col_num - 1];
            }
        if (col_num + 1 < C)
            if (mesh_heights[row_num][col_num + 1] < height && L[row_num][col_num + 1] > max_L) {
                max_L = L[row_num][col_num + 1];
            }
        L[row_num][col_num] = max_L + 1;
    }

    max_L = L[0][0];
    for (R_i = 0; R_i < R; ++R_i) {
        for (C_i = 0; C_i < C; ++C_i) {
            if (max_L < L[R_i][C_i]) {
                max_L = L[R_i][C_i];
            }
        }
    }

    std::cout << max_L;

    delete[] dem_points;

    return 0;
}