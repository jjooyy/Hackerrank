#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    vector<int> height(t);
    long rect = 0;
    stack<int> idx;
    for(int i=0; i<t; i++) {
        cin >> height[i];
    }
    int i=0;
    while(i<t) {
        if(idx.empty()||height[i]>=height[idx.top()]) {
            //cout << height[i] << " " <<endl;
            idx.push(i++);
        }
        else {
            int temp;
            
            temp = idx.top();
            idx.pop();
            int area;
            area = height[temp]*(idx.empty()? i : i-idx.top()-1);
            if(area > rect) {
                rect = area;
            }
        }
    }
    while(!idx.empty()) {
        int temp = idx.top();
        idx.pop();
        int area;
        area = height[temp]*(idx.empty()? i : i-idx.top()-1);
        if(area > rect) {
            rect = area;
        }
    }
    
    cout << rect << endl;
    return 0;
}