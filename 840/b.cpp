#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> h(n), p(n);

    for(int i = 0; i < n; i++)
        cin >> h[i];

    for(int i = 0; i < n; i++)
        cin >> p[i];

    vector<pii> v;
    for(int i = 0; i < n; i++)
        v.push_back({p[i], h[i]});

    sort(v.begin(), v.end());
    ll sum = k;
    int i = 0;

    while(i < n){
        while(sum < v[i].second){
            k -= v[i].first;
            if(k <= 0){
                cout << "NO" << endl;
                return;
            }
            sum += k;
        }
        i++;
    }

    cout << "YES" << endl;
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