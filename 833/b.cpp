#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> freq(10, 0);
        int distinct = 0;
        int maxFreq = 0;
        for(int j = i; j < min(i + 100, n); j++){
            freq[s[j] - '0']++;
            if(freq[s[j] - '0'] == 1)
                distinct++;

            maxFreq = max(maxFreq, freq[s[j]-'0']);
            if(maxFreq <= distinct)
                ans++;
        }
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