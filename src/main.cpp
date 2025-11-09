#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
#include "DFSGenerator.h"
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