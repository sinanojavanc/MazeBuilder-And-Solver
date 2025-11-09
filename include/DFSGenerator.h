#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <utility>
#include <windows.h>
using namespace std;

//---------------------------   Main.cpp       ---------------------------
extern int mWidth;
extern int mHeight;
extern random_device rd;
extern mt19937 gen;

void show_maze(vector<vector<int>>& maze, const pair<int, int>& ptrtop);
int show_menu();

//---------------------------    DFS.cpp     ----------------------------
pair<int, int> path_checker(vector<vector<int>>& m,
							vector<vector<bool>>& v,
							pair<int, int> pos);

void deep_first_search(vector<vector<int>>& maze);