#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& r, vector<int>& c){
    
    for(int i = 0; i < n; i++){
        if(r[i] == 0){
            cout << "YES" << "\n";
            return;
        }
    }

    for(int i = 0; i < n; i++){
        if(c[i] == 0){
            cout << "YES" << "\n";
            return;
        }

    }

    cout << "NO" << "\n";
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
        int n, m;
        cin >> n >> m;
        vector<int> r(n, 0);
        vector<int> c(n, 0);
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            r[x-1] = 1;
            c[y-1] = 1;
        }
        solve(n, r, c);
    }
    return 0;
}