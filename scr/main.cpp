#include "MazeGame.h"
#include <iostream>

using namespace std;

void showMenu() {
    system("cls");
    cout << "=========================================\n";
    cout << "      HE THONG GAME ME CUNG (MAZE)       \n";
    cout << "=========================================\n";
    cout << "1. Tao me cung moi (DFS Backtracker)\n";
    cout << "2. Nguoi choi tu giai (W/A/S/D)\n";
    cout << "3. Tu dong giai bang BFS (Duong ngan nhat)\n";
    cout << "4. Tu dong giai bang DFS (Hien thi backtrack)\n";
    cout << "5. So sanh BFS vs DFS\n";
    cout << "6. Thay doi do kho (Kich thuoc me cung)\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "=========================================\n";
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    MazeGame game(15, 15); 
    game.generateMaze();   

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            game.generateMaze();
            cout << "Da tao me cung moi thanh cong!\n";
            system("pause");
            break;
        case 2:
            game.playManual();
            break;
        case 3:
            game.solveBFS(true);
            break;
        case 4:
            game.solveDFS(true);
            break;
        case 5:
            game.compareAlgorithms();
            break;
        case 6: {
            int r, c;
            cout << "Nhap so hang (Le, VD: 15): "; cin >> r;
            cout << "Nhap so cot (Le, VD: 15): "; cin >> c;
            game.setSize(r, c);
            game.generateMaze();
            cout << "Da doi kich thuoc va tao me cung moi!\n";
            system("pause");
            break;
        }
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
            system("pause");
            break;
        }
    } while (choice != 0);

    return 0;
}
