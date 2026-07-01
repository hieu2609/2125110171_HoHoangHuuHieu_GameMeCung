#include "MazeGame.h"
#include <ctime>
#include <cstdlib>
#include <conio.h> 

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

MazeGame::MazeGame(int r, int c) {
    setSize(r, c);
}

void MazeGame::setSize(int r, int c) {
    if (r % 2 == 0) r++;
    if (c % 2 == 0) c++;
    rows = r;
    cols = c;
    maze.assign(rows, vector<char>(cols, '#'));
    srand((unsigned)time(0));
}

bool MazeGame::isValid(int r, int c) {
    return (r > 0 && r < rows - 1 && c > 0 && c < cols - 1);
}

void MazeGame::generateMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = '#';
        }
    }

    stack<Point> s;
    startPos = { 1, 1 };
    endPos = { rows - 2, cols - 2 };

    maze[startPos.r][startPos.c] = ' ';
    s.push(startPos);

    while (!s.empty()) {
        Point curr = s.top();
        vector<Point> neighbors;

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i] * 2;
            int nc = curr.c + dc[i] * 2;
            if (isValid(nr, nc) && maze[nr][nc] == '#') {
                neighbors.push_back({ nr, nc });
            }
        }

        if (!neighbors.empty()) {
            int randIdx = rand() % neighbors.size();
            Point next = neighbors[randIdx];

            maze[curr.r + (next.r - curr.r) / 2][curr.c + (next.c - curr.c) / 2] = ' ';
            maze[next.r][next.c] = ' ';

            s.push(next);
        }
        else {
            s.pop();
        }
    }

    maze[startPos.r][startPos.c] = 'S'; 
    maze[endPos.r][endPos.c] = 'E';     
    playerPos = startPos;
}

void MazeGame::printMaze() {
    system("cls"); 
    cout << "=== GAME ME CUNG ===\n";
    cout << "S: Bat dau | E: Ket thuc | P: Nguoi choi | .: Duong di\n\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == playerPos.r && j == playerPos.c)
                cout << 'P' << " ";
            else
                cout << maze[i][j] << " ";
        }
        cout << "\n";
    }
}

void MazeGame::resetMazePath() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == '.') maze[i][j] = ' ';
        }
    }
    maze[startPos.r][startPos.c] = 'S';
    maze[endPos.r][endPos.c] = 'E';
}

void MazeGame::playManual() {
    playerPos = startPos;
    while (true) {
        printMaze();
        if (playerPos.r == endPos.r && playerPos.c == endPos.c) {
            cout << "\nChuc mung! Ban da thoat khoi me cung!\n";
            system("pause");
            break;
        }

        cout << "\nDung W/A/S/D de di chuyen (Bam 'Q' de thoat): ";
        char move = _getch(); 

        if (move == 'q' || move == 'Q') break;

        int nextR = playerPos.r, nextC = playerPos.c;
        if (move == 'w' || move == 'W') nextR--;
        else if (move == 's' || move == 'S') nextR++;
        else if (move == 'a' || move == 'A') nextC--;
        else if (move == 'd' || move == 'D') nextC++;

        if (maze[nextR][nextC] != '#') {
            playerPos.r = nextR;
            playerPos.c = nextC;
        }
    }
    playerPos = startPos; 
}

int MazeGame::solveBFS(bool showPath) {
    resetMazePath();
    queue<Point> q;
    vector<vector<Point>> parent(rows, vector<Point>(cols, { -1, -1 }));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    q.push(startPos);
    visited[startPos.r][startPos.c] = true;
    bool found = false;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.r == endPos.r && curr.c == endPos.c) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] != '#' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                parent[nr][nc] = curr;
                q.push({ nr, nc });
            }
        }
    }

    int pathLength = 0;
    if (found) {
        Point curr = endPos;
        while (!(curr.r == startPos.r && curr.c == startPos.c)) {
            if (maze[curr.r][curr.c] != 'E') maze[curr.r][curr.c] = '.';
            curr = parent[curr.r][curr.c];
            pathLength++;
        }
        if (showPath) {
            playerPos = { -1, -1 }; 
            printMaze();
            cout << "\nBFS tim duoc duong di ngan nhat: " << pathLength << " buoc.\n";
            system("pause");
        }
    }
    else if (showPath) {
        cout << "\nKhong tim thay duong di!\n";
        system("pause");
    }
    return pathLength;
}

int MazeGame::solveDFS(bool showPath) {
    resetMazePath();
    stack<Point> s;
    vector<vector<Point>> parent(rows, vector<Point>(cols, { -1, -1 }));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    s.push(startPos);
    visited[startPos.r][startPos.c] = true;
    bool found = false;

    while (!s.empty()) {
        Point curr = s.top();
        s.pop();

        if (curr.r == endPos.r && curr.c == endPos.c) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] != '#' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                parent[nr][nc] = curr;
                s.push({ nr, nc });
            }
        }
    }

    int pathLength = 0;
    if (found) {
        Point curr = endPos;
        while (!(curr.r == startPos.r && curr.c == startPos.c)) {
            if (maze[curr.r][curr.c] != 'E') maze[curr.r][curr.c] = '.';
            curr = parent[curr.r][curr.c];
            pathLength++;
        }
        if (showPath) {
            playerPos = { -1, -1 }; 
            printMaze();
            cout << "\nDFS tim duoc duong di voi do dai: " << pathLength << " buoc.\n";
            system("pause");
        }
    }
    else if (showPath) {
        cout << "\nKhong tim thay duong di!\n";
        system("pause");
    }
    return pathLength;
}

void MazeGame::compareAlgorithms() {
    int bfsLen = solveBFS(false);
    int dfsLen = solveDFS(false);

    system("cls");
    cout << "=== SO SANH BFS VA DFS ===\n\n";
    cout << "Do dai duong di BFS: " << bfsLen << " buoc.\n";
    cout << "Do dai duong di DFS: " << dfsLen << " buoc.\n\n";

    if (bfsLen < dfsLen) {
        cout << "=> BFS tim duoc duong di NGAN HON DFS.\n";
        cout << "=> Giai thich: BFS lan toa deu ra cac huong nen luon dam bao tim duoc duong di ngan nhat dau tien.\n";
    }
    else if (bfsLen == dfsLen) {
        cout << "=> BFS va DFS tim duoc duong di dai bang nhau (Me cung it duong re).\n";
    }
    else {
        cout << "=> Co loi xay ra, BFS phai luon <= DFS.\n";
    }
    system("pause");
}
