#include <bits/stdc++.h>
using namespace std;

string findWinner(int n, int m){
    if((n+m)%2)
        return "Burenka";
    return "Tonya";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << findWinner(n, m) << "\n";
    }

    return 0;
}