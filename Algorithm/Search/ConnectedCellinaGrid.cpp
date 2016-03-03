#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int row, col;

int dfs(vector<vector<int>> matrix, vector<vector<bool>> visited, int x, int y) {
    //check adjacent cells
    queue<pair<int, int>> cellq;
    cellq.push(make_pair(x, y));
    visited[x][y] = true;
    int tempx, tempy;
    int r = 1;
    while(!cellq.empty()) {
        tempx = cellq.front().first;
        tempy = cellq.front().second;
        cellq.pop();
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(!(i == 0 && j == 0)) {
                    if(tempx + i >= 0 && tempx + i < row && tempy + j >= 0 && tempy + j < col && 
                       matrix[tempx+i][tempy+j] == 1 && visited[tempx+i][tempy+j] == false) {
                        cellq.push(make_pair(tempx+i, tempy+j));
                        visited[tempx+i][tempy+j] = true;
                        r++;
                    }
                }
            }
        }
    }
    return r;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> row >> col;
    int max = 0;
    int temp;
    vector<vector<int>> matrix(row, vector<int>(col));
    vector<vector<bool>> visited(row, vector<bool>(col));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> matrix[i][j];
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(matrix[i][j] == 1 && visited[i][j] == false) {
                temp = dfs(matrix, visited, i, j);
                if(max < temp) {
                    max = temp;
                }
            }
        }
    }
     cout << max << endl;
    return 0;
}
