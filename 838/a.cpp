#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    int sum = 0;
    int zero = 32;
    int one = 32;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum%2 == 0){
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < n; i++){
        if(a[i]&1){    
            for(int bit = 0; bit < 31; bit++){
                if((a[i]&(1 << bit)) == 0)
                    zero = min(zero, bit);
                    
            }
        }
        else{
            for(int bit = 0; bit < 32; bit++){
                if(a[i]&(1 << bit))
                    one = min(one, bit);
            }
        }
    }

    int ans = min(zero, one);
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