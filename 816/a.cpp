#include <bits/stdc++.h>
using namespace std;

int findEnergy(int n, int m){
    if(n == 1 and m == 1) return 0;
    return n+m-2 + min(n,m);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m; 
        cout << findEnergy(n, m) << endl;
    }
    return 0;
}