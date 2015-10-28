#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--!=0) {
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int max = arr[n-1];
        long int profit = 0; 
        vector<int> act(n);
        // sell is 0, buy is 1.
        act[n-1]=0;
        for(int i=n-2; i>=0; i--) {
            if(arr[i]>=max) {
                act[i] = 0;
                max = arr[i];
            }
            else {
                act[i] = 1;
                profit += max - arr[i];
            }
        }
        cout << profit << endl;
    }
    return 0;
}
