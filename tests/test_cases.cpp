#include <iostream>
#include <cassert>     // Thu vien de dung ham assert()
#include "../src/MazeGame.h" // Include file h tu thu muc src/

using namespace std;

// Test 1: Đảm bảo BFS luôn tìm được đường ngắn hơn hoặc bằng DFS
void test_BFS_vs_DFS() {
    cout << "Test 1: Kiem tra do dai duong di BFS va DFS...\n";
    MazeGame game(15, 15);
    game.generateMaze();

    // Chạy giải thuật nhưng ẩn đường đi (truyền false)
    int bfsLength = game.solveBFS(false); 
    int dfsLength = game.solveDFS(false);

    // Mê cung luôn phải có đường đi tới đích
    assert(bfsLength > 0 && "Loi: BFS khong tim thay duong di!");
    assert(dfsLength > 0 && "Loi: DFS khong tim thay duong di!");
    
    // Đặc tả của BFS là tìm đường ngắn nhất, nên BFS <= DFS
    assert(bfsLength <= dfsLength && "Loi: BFS lai dai hon DFS!");
    
    cout << "=> Test 1 PASSED!\n\n";
}

// Test 2: Đảm bảo hệ thống hoạt động ổn định với kích thước lớn
void test_Large_Maze() {
    cout << "Test 2: Kiem tra me cung kich thuoc lon (31x31)...\n";
    MazeGame game;
    game.setSize(31, 31);
    game.generateMaze();

    int bfsLength = game.solveBFS(false);
    
    assert(bfsLength > 0 && "Loi: Khong tim duoc duong cho me cung lon!");
    cout << "=> Test 2 PASSED!\n\n";
}

// Test 3: Đảm bảo hệ thống xử lý đúng với kích thước nhỏ nhất
void test_Small_Maze() {
    cout << "Test 3: Kiem tra me cung kich thuoc nho (5x5)...\n";
    MazeGame game;
    game.setSize(5, 5); 
    game.generateMaze();

    int bfsLength = game.solveBFS(false);
    
    assert(bfsLength > 0 && "Loi: Khong tim duoc duong cho me cung nho!");
    cout << "=> Test 3 PASSED!\n\n";
}

// Test 4: Đảm bảo hàm setSize tự động điều chỉnh số chẵn thành số lẻ
void test_Even_Size_Correction() {
    cout << "Test 4: Kiem tra tu dong sua kich thuoc chan thanh le...\n";
    MazeGame game;
    // Cố tình nhập số chẵn
    game.setSize(10, 10); 
    game.generateMaze();

    // Mê cung hợp lệ phải được giải quyết (nghĩa là nó đã tự ép lên 11x11)
    int bfsLength = game.solveBFS(false);
    assert(bfsLength > 0 && "Loi: Xu ly kich thuoc chan bi loi!");
    cout << "=> Test 4 PASSED!\n\n";
}

int main() {
    cout << "========================================\n";
    cout << "       KHOI CHAY Kiem Thu (TESTS)       \n";
    cout << "========================================\n\n";
    
    test_BFS_vs_DFS();
    test_Large_Maze();
    test_Small_Maze();
    test_Even_Size_Correction();
    
    cout << "========================================\n";
    cout << "    TAT CA TEST CASES DEU PASSED !!!    \n";
    cout << "========================================\n";
    
    system("pause");
    return 0;
}
