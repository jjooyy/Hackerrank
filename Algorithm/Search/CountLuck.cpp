#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int row, col, tcount;

bool findDir(int x, int y, vector<vector<char>> forest, vector<vector<bool>> &visited) {
    int cd = 0;
    int newx, newy;
    bool r = false;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        newx = x + dirx[i];
        newy = y + diry[i];
        if(newx >= 0 && newx < row && newy >= 0 && newy < col && 
           forest[newx][newy] != 'X' && visited[newx][newy] == false) {
            cd++;
            if(forest[newx][newy] == '*') {
                r = true;
            }
            else {
                if(findDir(newx, newy, forest, visited)) {
                    r = true;
                }
            }
        }
    }
    if(cd > 1 && r) {
        tcount++;
    }
    return r;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--) {    
        cin >> row >> col;
        vector<vector<char>> forest(row, vector<char>(col));
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int x, y, wand;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cin >> forest[i][j];
                if(forest[i][j] == 'M') {
                    x = i;
                    y = j;                   
                }
            }
        }
        cin >> wand;
        tcount = 0;
        if(findDir(x, y, forest, visited)) {
            if(wand == tcount) {
                cout << "Impressed" << endl;
            }
            else {
                cout << "Oops!" << endl;
            }
        }
        else {
            cout << "Oops!" << endl;
        }
    }
    return 0;
}
