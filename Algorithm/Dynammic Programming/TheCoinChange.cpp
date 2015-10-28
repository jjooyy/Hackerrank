#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long findMethods(vector<int> arr, int n) {
    int s = arr.size();
    if(s<=0)
        return 0;
    else {
        vector<long int> methods(n+1, 0);
        methods[0] = 1;
        for (int i=0; i<s&&arr[i]<=n; i++) {
            for(int j=arr[i]; j<n+1; j++) {
                methods[j] += methods[j-arr[i]];
            }
        }
        return methods[n];
    } 

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0; i<m; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long out = findMethods(v, n);
    cout << out << endl;
    return 0;
}
