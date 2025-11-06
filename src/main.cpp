#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <windows.h>
using namespace std;

const int aWidth = 10;
const int aHeight = 10;

void show_maze() {

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
			break;
	}
	return 0;
}