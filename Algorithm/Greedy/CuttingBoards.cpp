#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long t, row, col;
    cin >> t ;
    while(t--) {
        cin >> row >> col;
        vector<long> costy(row - 1);
        vector<long> costx(col - 1);
        for(long i = 0; i < row - 1; i++) {
            cin >> costy[i];
        }
        for(long i = 0; i < col - 1; i++) {
            cin >> costx[i];
        }
        sort(costy.begin(), costy.end());
        sort(costx.begin(), costx.end());
        long county = row - 2;
        long countx = col - 2;
        long total = row + col - 2;
        long sum = 0;
        for(long i = 0; i < total; i++) {
            if(county >= 0 && countx >= 0) {
                if(costy[county]  >= costx[countx] ) {
                    sum += (costy[county] * (col - countx - 1)) % MOD;
                    county--;
                }
                else {
                    sum += costx[countx] * (row - county - 1) % MOD;
                    countx--;
                }
            }
            else if(county >= 0) {
               sum += costy[county] * (col - countx - 1) % MOD;
               county--; 
            }
            else if(countx >= 0){
                sum += costx[countx] * (row - county - 1) % MOD;
                countx--;
            }
        }
        cout << sum % MOD << endl;
    }
    return 0;
}
