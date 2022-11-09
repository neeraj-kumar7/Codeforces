#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& a, vector<int>& b){
    map<int, int> freqa, freqb;
    for(int i = 0; i < n; i++){
        freqa[a[i]]++;
        freqb[b[i]]++;
    }

    int ans = 0;
    // step 1
    for(auto x : freqa){
        int i = x.first;
        int minFreq = min(freqa[i], freqb[i]);
        freqa[i] -= minFreq;
        freqb[i] -= minFreq;
        
    }

    // step 2
    for(auto x : freqa){
        int num = x.first;
        int freq = x.second;
        if(num > 9){
            int newNum = log10(num)+1;
            ans += freq;
            freqa[newNum] += freq;
            freqa[num] = 0;
        }
    }

    for(auto x : freqb){
        int num = x.first;
        int freq = x.second;
        if(num > 9){
            int newNum = log10(num)+1;
            ans += freq;
            freqb[newNum] += freq;
            freqb[num] = 0;
        }
    }
    
    // step 3
    for(auto x : freqa){
        int i = x.first;
        int minFreq = min(freqa[i], freqb[i]);
        freqa[i] -= minFreq;
        freqb[i] -= minFreq;
        
    }

    for(auto x : freqa){
        if(x.first != 1)
            ans += x.second;
    }

    for(auto x : freqb){
        if(x.first != 1)
            ans += x.second;
    }
    
    cout << ans << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for(int i = 0; i < n; i++)
            cin >> b[i];

        solve(n, a, b);
    }
    return 0;
}