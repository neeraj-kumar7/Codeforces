#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int l, r, x;
    cin >> l >> r >> x;

    int a, b;
    cin >> a >> b;

    if((a < l or a > r) or(b < l or b > r)){
        cout << -1 << endl;
        return;
    }

    if(a == b){
        cout << 0 << endl;
        return;
    }

    if(b > a){
        if(b-a >= x)
            cout << 1 << endl;
        else{
            if((a-l >= x) or (r-b >= x))
                cout << 2 << endl;
            else if((r - a >= x) and (b - l >= x))
                cout << 3 << endl;
            else
                cout << -1 << endl;

        }
        return;
    }

    else{
        if(a-b >= x)
            cout << 1 << endl;
        else{
            if((b-l >= x) or (r-a >= x))
                cout << 2 << endl;
            else if((r - b >= x) and (a - l >= x))
                cout << 3 << endl;
            else
                cout << -1 << endl;

        }
        return;
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