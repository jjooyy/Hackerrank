#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countPrime(int n) {
    vector<bool> prime(n + 1, true);
    int count = 0;
    for(int i = 2; i * i <= n; i++) {
        if(prime[i]) {
            for(int temp = i * 2; temp <= n; temp += i) {
                prime[temp] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if(prime[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        if(num < 4) {
            cout << "0" << endl;
        }
        else {
            vector<int> way(num + 1);
            for(int i = 0; i < num + 1; i++) {
                if(i < 4) {
                    way[i] = 1;
                }
                else {
                    way[i] = way[i-1] + way[i-4];
                }  
            }   
            cout << countPrime(way[num]) << endl;    
        } 
    }
    return 0;
}
