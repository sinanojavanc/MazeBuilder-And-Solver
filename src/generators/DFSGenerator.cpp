#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
#include "DFSGenerator.h"
using namespace std;

pair<int, int> ptr_mover(pair<int, int> pos, char direction)
{
    switch (direction)
    {
    case 'W': return { pos.first,     pos.second - 1 }; // بالا
    case 'S': return { pos.first,     pos.second + 1 }; // پایین
    case 'A': return { pos.first - 1, pos.second     }; // چپ
    case 'D': return { pos.first + 1, pos.second     }; // راست
    default:  return pos;
    }
}

// قرارداد: m[x][y]، v[x][y]
char path_checker(const vector<vector<int>>& m,
                  const vector<vector<bool>>& v,
                  pair<int, int> pos)
{
    vector<char> paths;

    if (pos.first + 2 < mWidth)
        if (m[pos.first + 2][pos.second] == 1 && !v[pos.first + 2][pos.second])
            paths.push_back('D');
    if (pos.first - 2 >= 0)
        if (m[pos.first - 2][pos.second] == 1 && !v[pos.first - 2][pos.second])
            paths.push_back('A');
    if (pos.second + 2 < mHeight)
        if (m[pos.first][pos.second + 2] == 1 && !v[pos.first][pos.second + 2])
            paths.push_back('S');
    if (pos.second - 2 >= 0)
        if (m[pos.first][pos.second - 2] == 1 && !v[pos.first][pos.second - 2])
            paths.push_back('W');

    if (paths.empty()) return 'E';
    shuffle(paths.begin(), paths.end(), gen);
    return paths[0];
}

void deep_first_search(vector<vector<int>>& maze)
{
    cout << "DFS";
    Sleep(300);

    vector<vector<bool>> visited(mWidth, vector<bool>(mHeight, false));
    stack<pair<int, int>> st;

    // شروع از یک خانه‌ی زوج (خانه‌های "اتاق")
    uniform_int_distribution<> distW(0, (mWidth  - 1) / 2);
    uniform_int_distribution<> distH(0, (mHeight - 1) / 2);
    int x = 2 * distW(gen);
    int y = 2 * distH(gen);

    pair<int, int> ptrtop = { x, y };
    char direction;

    visited[ptrtop.first][ptrtop.second] = true;
    maze[ptrtop.first][ptrtop.second]    = 0;

    while (true) {
        cout << "\033[H\033[2J";
        show_maze(maze, ptrtop);
        cout << "stack size: " << st.size() << '\n';

        direction = path_checker(maze, visited, ptrtop);

        if (direction == 'E') {
            if (st.empty()) break;
            ptrtop = st.top();
            st.pop();
        } else {
            pair<int,int> next = ptr_mover(ptrtop, direction);
            next = ptr_mover(next, direction); // دو خانه جلو

            if (next.first  < 0 || next.first  >= mWidth  ||
                next.second < 0 || next.second >= mHeight) continue;

            // باز کردن دیوار میانی
            int midX = (ptrtop.first  + next.first ) / 2;
            int midY = (ptrtop.second + next.second) / 2;
            maze[midX][midY] = 0;

            st.push(ptrtop);
            ptrtop = next;

            visited[ptrtop.first][ptrtop.second] = true;
            maze[ptrtop.first][ptrtop.second]    = 0;
        }

        Sleep(50);
    }

    // نمایش نهایی
    cout << "\033[H\033[2J";
    show_maze(maze, make_pair(-1, -1));
    cout << "\nMaze generated! Press any key...\n";
    system("pause");
}