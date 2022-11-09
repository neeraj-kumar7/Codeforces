#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int n, vector<int>& weights){
    sort(weights.begin(), weights.end());
    ll maxScore = 0;

    for(int i = 1; i < n-1; i++){
        ll diff1 = weights[i] - weights[i-1];
        ll diff2 = weights[n-1] - weights[i-1];
        maxScore = max(maxScore, diff1 + diff2);
    }

    for(int i = 2; i < n; i++){
        ll diff1 = weights[i] - weights[i-1];
        ll diff2 = weights[i] - weights[0];
        maxScore = max(maxScore, diff1 + diff2);
    }

    cout << maxScore << "\n";
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
        vector<int> weights(n);
        for(int i = 0; i < n; i++)
            cin >> weights[i];
        
        solve(n, weights);
    }
    return 0;
}