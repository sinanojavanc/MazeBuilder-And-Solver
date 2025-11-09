#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
#include "DFSGenerator.h"
using namespace std;



pair<int, int> path_checker(vector<vector<int>>& m,
							vector<vector<bool>>& v,
							pair<int, int> pos) 
{
	vector<pair<int, int>> paths;

	if (pos.first + 1 < mWidth)
		if (m[pos.first + 1][pos.second] == 1)
			if (v[pos.first + 1][pos.second] == 0)
				paths.push_back({ pos.first + 1, pos.second });
	if (pos.first - 1 > 0)
		if (m[pos.first - 1][pos.second] == 1)
			if (v[pos.first - 1][pos.second] == 0)
				paths.push_back({ pos.first - 1, pos.second });
	if (pos.second + 1 < mHeight)
		if (m[pos.first][pos.second + 1] == 1)
			if (v[pos.first][pos.second + 1] == 0)
				paths.push_back({ pos.first, pos.second + 1 });
	if (pos.second - 1 > 0)
		if (m[pos.first][pos.second - 1] == 1)
			if (v[pos.first][pos.second - 1] == 0)
				paths.push_back({ pos.first , pos.second - 1 });

	if (paths.empty()) return { -1,-1 };
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
	pair<int, int> ptrtop = { distX(gen) ,distY(gen) };
	pair<int, int> temp	  = { 0 , 0 };
	
	while (true) {
		visited[ptrtop.first][ptrtop.second] = true;

		system("cls");
		show_maze(maze, ptrtop);
		cout << stack.size();

		temp = path_checker(maze, visited, ptrtop);
		if (temp.first == -1) // if stuck
		{
			if (!stack.empty())
			{
				ptrtop = stack.top();
				stack.pop();
			}
			else
			{
				return; // path ends
			}
		}
		else  // push stack
		{
			stack.push(temp);
			ptrtop = temp;
		}

		Sleep(500);
	}
}