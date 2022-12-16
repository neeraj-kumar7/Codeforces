#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        a[i] = {num, i};
    }

    sort(a.begin(), a.end());

    int prev = a[0].first;
    cout << n-1 << endl;
    for(int i = 1; i < n; i++){
        int index = a[i].second;
        int x = prev - (a[i].first)%prev;
        cout << index+1 << " " << x << endl;

        prev = a[i].first + x;
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