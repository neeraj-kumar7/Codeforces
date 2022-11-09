#include <bits/stdc++.h>
using namespace std;

void solve(string s, int n){
    
    long long cost = 0;
    string marked (n, '1');
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            for(int j = i+1; j <= n; j += (i+1) ){
                if(s[j-1] == '1') break;

                if(marked[j-1] == '0')
                    continue;

                marked[j-1] = '0';
                cost += i+1;
            }
        }
    }
    cout << cost << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }
    return 0;
}