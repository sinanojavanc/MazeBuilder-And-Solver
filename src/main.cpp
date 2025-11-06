#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
using namespace std;

int mWidth = 5;
int mHeight = 5;

void show_maze() {
	for (int i = 0; i < (mWidth * 2) + 1; i++)
		cout << "#";
	cout << endl;
	for (int j = 0; j < mWidth; j++) 
	{
		cout << "#";
		for (int i = 0; i < mWidth; i++) 
		{
			cout << " #";
		}
		cout  << endl;
	}
	for (int i = 0; i < (mWidth * 2) + 1; i++)
		cout << "#";
	cout << endl;
}

int show_menu() {
	show_maze();

	cout << "\n============ Maze Creator ============\n" << endl
		 << "1. create maze" << endl << "2. solve maze"  << endl
		 << "3. save maze"   << endl << "4. Exit"		 << endl
		 << "Enter your choose: ";
	int choose;
	cin >> choose;

	switch (choose) {
	case 1:

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
	while (true) {
		system("cls");
		if (show_menu() == 4)
			return 0;
	}
}