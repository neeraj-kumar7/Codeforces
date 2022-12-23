#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int maxi = 0;
    int ans = 0;
    for(int bit = 0; bit < 31; bit++){
        bool flag1 = false;
        bool flag2 = false;
        for(int i = 0; i < n; i++){
            if((a[i])&(1 << bit))
                flag1 = true;
            else
                flag2 = true;
        }

        if(flag1 and flag2) ans |= (1 << bit);
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