#include <iostream>
#include <windows.h>
using namespace std;


	
const int aw = 9, ah = 9;
	 int array[aw][ah] = {
		{0,0,1,0,1,0,1,0,0},
		{1,0,0,0,0,0,1,1,0},
		{0,0,1,0,1,0,0,0,0},
		{1,0,1,1,1,1,0,1,1},
		{1,0,0,1,0,0,0,0,0},
		{1,1,0,1,1,1,1,1,0},
		{0,0,0,0,0,1,1,1,0},
		{0,1,1,1,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,0},

	};
	pair<int,int> ptr = {0,0};

int main(){
	
	SetConsoleOutputCP(CP_UTF8);	
	system("chcp 65001 >nul");
	
	cout << " ■  ■  ■  ■  ■  ■  ■  ■  ■  ■  ■" << endl;
	for (int i = 0; i < aw; i++) {
		cout << " ■ ";
	  	for (int j = 0; j < ah; j++) {
	  		if (array[i][j] == 1)
	  			cout << " ■ ";
	  		else
	  			cout << "   ";//\033[36m○\033[0m ";
			
		}
	 	cout << " ■" << endl;
	}
	cout << " ■  ■  ■  ■  ■  ■  ■  ■  ■  ■  ■";
	return 0;
}