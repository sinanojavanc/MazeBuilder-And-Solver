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
	
	for (int i = 0; i < aw; i++) {
	  	for (int j = 0; j < ah; j++) {
			cout << array[i][j] << " ";
		}
	 	cout << endl;
	}
	
	return 0;
}