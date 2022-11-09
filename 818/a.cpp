#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        // (a, a/3), (a, a/2), (a, a);
        cout << 2*(n/3) + 2*(n/2) + n << endl;
    }
    return 0;
}