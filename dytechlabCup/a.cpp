#include <bits/stdc++.h>
using namespace std;

void solve(string s, int n, int k ){
    int m = n/k;
    unordered_map<char, int> freq;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
    }

    string ans = "";
    for(int i = 0; i < k; i++){
        int j;
        char c = 'a';
        for(j = 0; j < m; j++){
            
            if(freq.find(c) != freq.end()){
                freq[c]--;
                if(freq[c] == 0)
                    freq.erase(c);
            }
            else break;
            
            c++;
        }
        ans += c;
        if(j < m){
            c++;
            if(freq.find(c) != freq.end()){
                freq[c]--;
                if(freq[c] == 0)
                    freq.erase(c);
                j++;
            }
            
        }
    }
    cout << ans << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        solve(s, n, k);
    }
    return 0;
}