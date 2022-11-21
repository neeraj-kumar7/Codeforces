#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int m, s;
    cin >> m >> s;

    vector<int> b(m);
    for(int i = 0; i < m; i++)
        cin >> b[i];

    int sb = 0;
    for(int i : b)
        sb += i;

    int maxi = *max_element(b.begin(), b.end());

    int sum = sb + s;
    sum *= 2;

    for(int i = maxi; i < 300; i++){
        if((i * (i + 1)) == sum){
            cout << "Yes" << endl;
            return;
        }
        if(i*(i+1) > sum)
            break;
    }
    cout << "No" << endl;
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