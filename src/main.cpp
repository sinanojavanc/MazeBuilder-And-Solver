#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
using namespace std;

int mWidth = 5;
int mHeight = 5;
random_device rd;
mt19937 gen(rd());

void show_maze(vector<vector<int>>& maze, const pair<int, int>& ptrtop) {
	for (int i = 0; i < (mWidth * 2) + 1; i++)
		cout << "-";
	cout << endl;
	for (int j = 0; j < mWidth; j++) {
		cout << "|";
		for (int i = 0; i < mWidth; i++) {
			cout << " +";
		} cout << endl;
	} for (int i = 0; i < (mWidth * 2) + 1; i++)
		cout << "-";
	cout << endl;
}

int show_menu() {
	cout << "\n============ Maze Creator ============\n" << endl
		<< "1. create maze" << endl << "2. solve maze" << endl
		<< "3. save maze" << endl << "4. Exit" << endl
		<< "Enter your choose: ";
	int choose;
	cin >> choose;

	switch (choose) {
	case 1:
		return 1;
		break;
	case 4:
		return 4;
		break;
	default:
		return 0;
		break;
	}
}

pair<int, int> path_checker(vector<vector<int>>& m,
							vector<vector<bool>>& v,
							pair<int, int> pos) 
{
	vector<pair<int, int>> paths;

	if (pos.first + 1 < mWidth)
		if (m[pos.first + 1][pos.second] == 0)
			if (v[pos.first + 1][pos.second] == 0)
				paths.push_back({ pos.first + 1, pos.second });
	if (pos.first - 1 > 0)
		if (m[pos.first - 1][pos.second] == 0)
			if (v[pos.first - 1][pos.second] == 0)
				paths.push_back({ pos.first - 1, pos.second });
	if (pos.second + 1 < mHeight)
		if (m[pos.first][pos.second + 1] == 0)
			if (v[pos.first][pos.second + 1] == 0)
				paths.push_back({ pos.first, pos.second + 1 });
	if (pos.second - 1 > 0)
		if (m[pos.first][pos.second - 1] == 0)
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

int main() {
	vector<vector<int>> maze(mWidth, vector<int>(mHeight, 0));

	while (true) {
		system("cls");
		show_maze(maze,make_pair(-1,-1));
		int choose = show_menu();
		if (choose == 1)
			deep_first_search(maze);
		if (choose == 4)
			return 0;
	}
}