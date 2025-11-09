#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
#include "DFSGenerator.h"
using namespace std;

int mWidth = 18;
int mHeight = 18;
random_device rd;
mt19937 gen(rd());

void show_maze(vector<vector<int>>& maze, const pair<int, int>& playerPos) 
{
for (int i = 0; i < mWidth + 2; ++i) cout << " o "; 
cout << endl;

    for (int y = 0; y < mWidth; y++) {
        cout << " o ";

        for (int x = 0; x < mHeight; x++) {
            bool isPlayerHere = (playerPos.first == x && playerPos.second == y);

            if (isPlayerHere) {
                cout << " \033[36mo\033[0m ";
            } else if (maze[x][y] == 1) {
                cout << " o ";
            } else {
                cout << "   ";
            }
        }

        cout << " o" << endl; 
    }

for (int i = 0; i < mWidth + 2; ++i) cout << " o "; 
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

	vector<vector<int>> maze(mWidth, vector<int>(mHeight, 1));

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