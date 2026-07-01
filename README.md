# Đồ Án Cấu Trúc Dữ Liệu - Game Mê Cung (Maze Game)

## 1. Giới thiệu ứng dụng
Đây là một game mê cung (Maze) mô phỏng trên console C++, áp dụng các cấu trúc dữ liệu cơ bản đã học:
- **2D Array (Vector of vectors)**: Dùng để lưu trữ bản đồ mê cung.
- **Stack**: Dùng để sinh mê cung ngẫu nhiên (thuật toán Recursive Backtracker) và giải mê cung bằng DFS.
- **Queue**: Dùng để giải mê cung bằng thuật toán BFS (Tìm đường ngắn nhất).

## 2. Cách chạy ứng dụng trên Visual Studio 2022
1. Mở Visual Studio 2022, chọn **Create a new project** -> **Console App (C++)**.
2. Đặt tên project (ví dụ: `MazeGame`).
3. Chuột phải vào thư mục **Header Files** ở Solution Explorer -> Add -> New Item -> Đặt tên là `MazeGame.h` và dán code vào.
4. Chuột phải vào thư mục **Source Files** -> Add -> New Item -> Đặt tên là `MazeGame.cpp` và dán code vào.
5. Sửa file `main.cpp` mặc định trong thư mục **Source Files** bằng code đã cung cấp.
6. Nhấn `Ctrl + F5` để biên dịch (chạy với chuẩn C++17 sẽ hoàn toàn không lỗi) và tận hưởng game.

## 3. Các Test Case Kiểm Thử (Tối thiểu 5)
- **Test Case 1 (Tạo mê cung):** Chọn chức năng 1. Kỳ vọng: Hệ thống tạo ra một mê cung mới ngẫu nhiên (không giống mê cung cũ) có đường đi từ S đến E.
- **Test Case 2 (Chơi bằng tay):** Chọn chức năng 2, bấm W/A/S/D. Kỳ vọng: Ký tự 'P' di chuyển trong mê cung, không đâm xuyên qua tường ('#'). Tới đích ('E') sẽ báo chiến thắng.
- **Test Case 3 (Giải BFS):** Chọn chức năng 3. Kỳ vọng: Hệ thống hiển thị đường đi bằng các dấu `.` nối từ S đến E, in ra số bước.
- **Test Case 4 (So sánh độ dài):** Chọn chức năng 5. Kỳ vọng: In ra số bước của BFS luôn luôn bé hơn hoặc bằng (<=) số bước của DFS.
- **Test Case 5 (Điều chỉnh độ khó):** Chọn chức năng 6, nhập 31 31. Kỳ vọng: Kích thước mê cung thay đổi to hơn, tạo mê cung mới thành công mà không bị crash hay tràn mảng (Stack overflow).
