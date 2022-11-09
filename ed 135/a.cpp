#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& cnt){
    int maxIndex = 0;
    for(int i = 0; i < n; i++)
        if(cnt[i] > cnt[maxIndex])
            maxIndex = i;
    cout << maxIndex+1 << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> cnt(n);
        for(int i = 0; i < n; i++)
            cin >> cnt[i];

        solve(n, cnt);
    }
    return 0;
}