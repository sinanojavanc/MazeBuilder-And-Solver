#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
#include "DFSGenerator.h"
using namespace std;

int mWidth = 17;
int mHeight = 17;
random_device rd;
mt19937 gen(rd());

// قرارداد: maze[x][y]  →  x در [0, mWidth), y در [0, mHeight)
void show_maze(const vector<vector<int>>& maze,
               const pair<int, int>& playerPos,
               const vector<pair<int, int>>* solution)
{
    // مرز بالا
    for (int x = 0; x < mWidth + 2; ++x) cout << " # ";
    cout << '\n';

    for (int y = 0; y < mHeight; y++) {
        cout << " # ";

        for (int x = 0; x < mWidth; x++) {
            bool isPlayer   = (playerPos.first == x && playerPos.second == y);
            bool isSolution = false;
            if (solution) {
                for (auto& p : *solution)
                    if (p.first == x && p.second == y) { isSolution = true; break; }
            }

            if (isPlayer) {
                cout << " \033[36mO\033[0m ";   // آبی = بازیکن
            } else if (isSolution) {
                cout << " \033[32mo\033[0m ";   // سبز = رد پا
            } else if (maze[x][y] == 1) {
                cout << " # ";
            } else {
                cout << "   ";
            }
        }

        cout << " #\n";
    }

    // مرز پایین
    for (int x = 0; x < mWidth + 2; ++x) cout << " # ";
    cout << '\n';
}

int show_menu() {
    cout << "\n============ Maze Creator  ============\n"
         << "1. create maze\n"
         << "2. solve maze\n"
         << "3. save maze\n"
         << "4. Exit\n"
         << "Enter your choose: ";
    int choose;
    if (!(cin >> choose)) { cin.clear(); cin.ignore(1000, '\n'); return 0; }

    switch (choose) {
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    default: return 0;
    }
}

int main() {
    vector<vector<int>> maze(mWidth, vector<int>(mHeight, 1));

    while (true) {
        cout << "\033[H\033[2J";
        show_maze(maze, make_pair(-1, -1));
        int choose = show_menu();

        if (choose == 1) {
            cout << "\nenter the Width  of maze (odd, >=5): ";
            cin >> mWidth;
            cout << "enter the Height of maze (odd, >=5): ";
            cin >> mHeight;

            if (mWidth  < 5) mWidth  = 5;
            if (mHeight < 5) mHeight = 5;
            if (mWidth  % 2 == 0) mWidth++;
            if (mHeight % 2 == 0) mHeight++;

            maze.assign(mWidth, vector<int>(mHeight, 1));
            deep_first_search(maze);
        }
        else if (choose == 2) {
            pair<int, int> start = {0, 0};
            pair<int, int> goal  = {mWidth - 1, mHeight - 1};

            maze[start.first][start.second] = 0;
            maze[goal.first][goal.second]   = 0;

            auto path = solve_maze(maze, start, goal);
            if (path.empty()) {
                cout << "\nNo path found!\n";
                system("pause");
            } else {
                animate_solution(maze, path);
            }
        }
        else if (choose == 3) {
            string fn;
            cout << "\nfilename (e.g. maze.txt): ";
            cin >> fn;
            save_maze(maze, fn);
            cout << "saved to " << fn << "\n";
            system("pause");
        }
        else if (choose == 4) {
            return 0;
        }
    }
}