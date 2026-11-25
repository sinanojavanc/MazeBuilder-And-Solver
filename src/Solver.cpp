#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>
#include "DFSGenerator.h"
using namespace std;

// BFS روی خانه‌های باز (maze[x][y] == 0)
vector<pair<int, int>> solve_maze(const vector<vector<int>>& maze,
                                  pair<int, int> start,
                                  pair<int, int> goal)
{
    vector<vector<bool>> vis(mWidth, vector<bool>(mHeight, false));
    vector<vector<pair<int,int>>> parent(mWidth, vector<pair<int,int>>(mHeight, {-1,-1}));

    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    const int dx[4] = { 1, -1, 0,  0 };
    const int dy[4] = { 0,  0, 1, -1 };

    bool found = false;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur == goal) { found = true; break; }

        for (int d = 0; d < 4; ++d) {
            int nx = cur.first  + dx[d];
            int ny = cur.second + dy[d];
            if (nx < 0 || nx >= mWidth || ny < 0 || ny >= mHeight) continue;
            if (vis[nx][ny]) continue;
            if (maze[nx][ny] != 0) continue;

            vis[nx][ny] = true;
            parent[nx][ny] = cur;
            q.push({nx, ny});
        }
    }

    if (!found) return {};

    // بازسازی مسیر
    vector<pair<int,int>> path;
    pair<int,int> cur = goal;
    while (cur != make_pair(-1, -1)) {
        path.push_back(cur);
        if (cur == start) break;
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());
    return path;
}

void animate_solution(const vector<vector<int>>& maze,
                      const vector<pair<int,int>>& path)
{
    for (auto& p : path) {
        cout << "\033[H\033[2J";
        show_maze(maze, p, &path);
        cout << "\nSolving... (" << p.first << ", " << p.second << ")\n";
        Sleep(40);
    }
    cout << "\nSolved! Press any key...\n";
    system("pause");
}