#pragma once
#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

// Cấu trúc lưu tọa độ
struct Point {
    int r, c;
};

class MazeGame {
private:
    int rows, cols;
    vector<vector<char>> maze; // 2D Array lưu mê cung
    Point startPos, endPos, playerPos;

    // Hàm phụ trợ kiểm tra tọa độ hợp lệ
    bool isValid(int r, int c);

public:
    // Constructor khởi tạo kích thước mặc định
    MazeGame(int r = 11, int c = 11);

    // 1. Tạo mê cung ngẫu nhiên bằng DFS (Stack)
    void generateMaze();

    // 2. Hiển thị mê cung
    void printMaze();

    // 3. Người chơi tự giải bằng W/A/S/D
    void playManual();

    // 4. Giải bằng BFS (Queue) - Trả về độ dài đường đi
    int solveBFS(bool showPath = true);

    // 5. Giải bằng DFS (Stack) - Trả về độ dài đường đi
    int solveDFS(bool showPath = true);

    // 6. So sánh BFS và DFS
    void compareAlgorithms();

    // 7. Điều chỉnh độ khó (kích thước)
    void setSize(int r, int c);

    // Khôi phục lại mê cung gốc (xóa các dấu '.' đường đi)
    void resetMazePath();
};

#endif
