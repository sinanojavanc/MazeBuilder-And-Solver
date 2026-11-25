#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <random>
#include <utility>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

//---------------------------   main.cpp   ---------------------------
extern int mWidth;
extern int mHeight;
extern random_device rd;
extern mt19937 gen;

void show_maze(const vector<vector<int>>& maze,
               const pair<int, int>& playerPos,
               const vector<pair<int, int>>* solution = nullptr);
int show_menu();

//---------------------------   DFS.cpp   ----------------------------
char path_checker(const vector<vector<int>>& m,
                  const vector<vector<bool>>& v,
                  pair<int, int> pos);
pair<int, int> ptr_mover(pair<int, int> pos, char direction);
void deep_first_search(vector<vector<int>>& maze);

//---------------------------  Solver.cpp  ---------------------------
vector<pair<int, int>> solve_maze(const vector<vector<int>>& maze,
                                  pair<int, int> start,
                                  pair<int, int> goal);
void animate_solution(const vector<vector<int>>& maze,
                      const vector<pair<int, int>>& path);

//---------------------------   Save.cpp   ---------------------------
void save_maze(const vector<vector<int>>& maze, const string& filename);