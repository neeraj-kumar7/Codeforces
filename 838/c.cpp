#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> dp(n, 1);
    vector<ll> dpm(n, 1);

    ll ans = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1])
            dp[i] = (2*dp[i-1])%MOD;
        else
            dp[i] = dpm[i-1];

        ans = (ans + dp[i])%MOD;
    }

    cout << ans << endl;
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