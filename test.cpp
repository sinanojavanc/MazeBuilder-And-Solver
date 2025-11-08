#include <iostream>
using namespace std;

const int aw = 3, ah = 3;
	 int array[aw][ah] = {
		{0,0,1},
		{0,1,0},
		{0,0,0},

	};
	pair<int,int> ptr = {0,0};

int main(){
	cout << " xxxxxxxxxxxxx" << endl;
	for (int i = 0; i < aw; i++) {
	  	for (int j = 0; j < ah; j++) {
	  		cout << " x ";
	  		if (array[i][j] == 1)
	  			cout << "x";
	  		else
	  			cout << " ";
			
		}
		cout << " x";
	 	cout << endl;
	}
	cout << " xxxxxxxxxxxxx";
	return 0;
}