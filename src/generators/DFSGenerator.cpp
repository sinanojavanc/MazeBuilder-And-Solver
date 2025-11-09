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
    case 'W':
        return { pos.first , pos.second - 1 };
    case 'S': 
        return { pos.first , pos.second + 1 };
    case 'A':
        return { pos.first - 1 , pos.second };
    case 'D':
        return { pos.first + 1 , pos.second };
    default:
        return pos;
    }
}

char path_checker(vector<vector<int>>& m,
				  vector<vector<bool>>& v,
				  pair<int, int> pos) 
{
	vector<char> paths;

	if (pos.first + 2 < mWidth)
		if (m[pos.first + 2][pos.second] == 1)
			if (v[pos.first + 2][pos.second] == 0)
				paths.push_back('D');
	if (pos.first - 2 >= 0)
		if (m[pos.first - 2][pos.second] == 1)
			if (v[pos.first - 2][pos.second] == 0)
				paths.push_back('A');
	if (pos.second + 2 < mHeight)
		if (m[pos.first][pos.second + 2] == 1)
			if (v[pos.first][pos.second + 2] == 0)
				paths.push_back('S');
	if (pos.second - 2 >= 0)
		if (m[pos.first][pos.second - 2] == 1)
			if (v[pos.first][pos.second - 2] == 0)
				paths.push_back('W');

	if (paths.empty()) return 'E';
	shuffle(paths.begin(), paths.end(), gen);
	return paths[0];
}

void deep_first_search(vector<vector<int>>& maze) {
	cout << "DFS";
	Sleep(500);
	vector<vector<bool>> visited(mWidth, vector<bool>(mHeight, 0));
	stack<pair<int, int>> stack;

	uniform_int_distribution<> distY(0, mWidth  - 1);
	uniform_int_distribution<> distX(0, mHeight - 1);
    int x = 2 * (distX(gen) / 2);
    int y = 2 * (distY(gen) / 2);
	pair<int, int> ptrtop = { x , y };
	char direction;
	
    visited[ptrtop.first][ptrtop.second] = true;
    maze[ptrtop.first][ptrtop.second] = 0;

	while (true) {
		system("cls");
		show_maze(maze, ptrtop);
		cout << stack.size();

		direction = path_checker(maze, visited, ptrtop);

		if (direction == 'E') // if stuck
		{
			if (stack.empty()) return; // path ends

			ptrtop = stack.top();
			stack.pop();
		}
		else  // push stack
		{
            pair<int,int> next = ptr_mover(ptrtop, direction);
            next = ptr_mover(next, direction);

            if (next.first < 0 || next.first >= mWidth || next.second < 0 || next.second >= mHeight) {
                continue;
            }

            // open mid wall
            int midX = (ptrtop.first + next.first)/2;
            int midY = (ptrtop.second + next.second)/2;
            maze[midX][midY] = 0;

            stack.push(ptrtop);     
            ptrtop = next;

            visited[ptrtop.first][ptrtop.second] = true;
            maze[ptrtop.first][ptrtop.second] = 0;
		}

		Sleep(20);
	}
}