#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, vector<vector<int>> v){
    vector<int> minSides;
    for(int i = 0; i < n; i++){
        minSides.push_back(min(v[i][0], v[i][1]));
    }

    vector<int> maxSides;
    for(int i = 0; i < n; i++){
        maxSides.push_back(max(v[i][0], v[i][1]));
    }

    ll perimeter = 0;
    for(int i = 0; i < n; i++){
        perimeter += minSides[i];
    }

    perimeter *= 2LL;
    int maxi = *max_element(maxSides.begin(), maxSides.end());
    perimeter += 2LL*maxi;
    cout << perimeter << "\n";
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
        int n;
        cin >> n;
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        solve(n, v);
    }
    return 0;
}