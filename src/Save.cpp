#include <fstream>
#include <iostream>
#include "DFSGenerator.h"
using namespace std;

void save_maze(const vector<vector<int>>& maze, const string& filename)
{
    ofstream out(filename);
    if (!out) { cerr << "Cannot open " << filename << "\n"; return; }

    out << mWidth << " " << mHeight << "\n";
    for (int y = 0; y < mHeight; ++y) {
        for (int x = 0; x < mWidth; ++x)
            out << maze[x][y] << (x + 1 == mWidth ? '\n' : ' ');
    }
}