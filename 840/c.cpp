#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans;
    if(n == 2){
        ans = max(a[0] + a[1], 2*abs(a[0]-a[1]));
    }
    else if (n == 3){
        ans = max({a[0] + a[1] + a[2], 3*a[0], 3*a[2],
                    3*abs(a[0]-a[1]), 3*abs(a[1]-a[2])});
    }
    else{
        ll maxi = *max_element(a.begin(), a.end());
        ans = n*maxi;
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