#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> nums(n+1);
    int Xor = 0;

    vector<int> prefixZeros(n+1, 0);
    vector<int> prefixXor(n+1, 0);
    map<int, set<int>> odd, even;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];

        if(nums[i] == 0)
            prefixZeros[i]++;
        prefixZeros[i] += prefixZeros[i-1];

        Xor ^= nums[i];
        prefixXor[i] = Xor;

        if(i%2) odd[Xor].insert(i);
        else even[Xor].insert(i);
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        int len = r-l+1;
        if(prefixZeros[r] - prefixZeros[l-1] == len){
            cout << 0 << endl;
            continue;
        }

        if(prefixXor[l-1] != prefixXor[r]){
            cout << -1 << endl;
            continue;
        }

        if(len%2){
            cout << 1 << endl;
            continue;
        }

        if(nums[l] == 0 or nums[r] == 0){
            cout << 1 << endl;
            continue;
        }

        int val = prefixXor[l-1];
        if(l%2){
            if(odd[val].upper_bound(l-1) != odd[val].end()){
                int next = *odd[val].upper_bound(l-1);
                if(next < r) cout << 2 << endl;
                else cout << -1 << endl;
            }
            else
                cout << -1 << endl;
        }
        else{
            if(even[val].upper_bound(l-1) != even[val].end()){
                int next = *even[val].upper_bound(l-1);
                if(next < r) cout << 2 << endl;
                else cout << -1 << endl;
            }
            else
                cout << -1 << endl;
        }
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

    solve();
    return 0;
}