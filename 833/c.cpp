#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> zeroIndex;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0)
            zeroIndex.push_back(i);
    }

    vector<ll> prefixSum(n, a[0]);
    for(int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i-1] + a[i];

    int m = zeroIndex.size();
    ll score = 0;
    if(m == 0){
        for(auto i : prefixSum)
            if(i == 0) score++;
        cout << score << endl;
        return;
    }

    int end = zeroIndex[0];
    for(int i = 0; i < end; i++)
        if(prefixSum[i] == 0) score++;

    for(int i = 0; i < m; i++){
        int left = zeroIndex[i];
        int right = (i < m-1) ? zeroIndex[i+1] : n;

        unordered_map<ll, int> m;
        for(int k = left; k < right; k++)
            m[prefixSum[k]]++;

        int maxFreq = 0;
        for(auto p : m)
            maxFreq = max(maxFreq, p.second);

        score += maxFreq;
    }



    cout << score << endl;
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