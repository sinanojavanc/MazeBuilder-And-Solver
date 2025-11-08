#include <iostream>
using namespace std;

const int aw = 9, ah = 9;
	 int array[aw][ah] = {
		{1,0,1,0,1,0,1,0,0},
		{1,0,0,0,1,0,1,1,0},
		{0,0,1,0,0,0,0,0,0},
		{1,0,1,1,1,1,0,1,1},
		{1,0,0,1,0,0,0,0,0},
		{1,1,0,1,1,1,1,1,0},
		{0,0,0,0,0,1,1,1,0},
		{1,1,0,1,0,1,0,0,0},
		{1,1,0,1,0,0,0,1,1},

	};
	pair<int,int> ptr = {0,0};

int main(){
	cout << " x x x x x x x x x x x x x x x" << endl
		<< " x ";
	for (int i = 0; i < aw; i++) {
	  	for (int j = 0; j < ah; j++) {
	  		if (array[i][j] == 1)
	  			cout << " x ";
	  		else
	  			cout << " \033[32mo\033[0m ";
			
		}
		cout << " x";
	 	cout << endl;
	}
	cout << " x x x x x x x x x x x x x x x";
	return 0;
}