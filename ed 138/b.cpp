#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, vector<ll>& a, vector<ll>& b){
    ll time = 0;
    for(ll t : a)
        time += t;

    ll sum = 0;
    for(ll i = 0; i < n; i++)
        sum += b[i];

    ll mini = sum - b[0];
    for(int i = 1; i < n; i++){
        mini = min(mini, sum - b[i]);
    }
    time += mini;
    cout << time << "\n";
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
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<ll> b(n);
        for(int i = 0; i < n; i++)
            cin >> b[i];
        
        
        solve(n, a, b);
    }
    return 0;
}