#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
 
    int ops = (n+1)/2;
    int i = 1;
    int j = 3*n;
    cout << ops << "\n";
    while(ops--){
        cout << i << " " << j << "\n";
        i += 3;
        j -= 3;
    }
    return;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}