#include <bits/stdc++.h>
using namespace std;

void solve(int n, string s){

    int depth = 0, runningDepth = 0;
    int ans = n;
    for(int i = 0; i < 2*n; i++){
        if(s[i] == '('){
            depth++;
            if(depth <= runningDepth)
                ans--;
            
            runningDepth = depth;
        }
        else{
            depth--;
        }
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

        string s;
        cin >> s;

        solve(n, s);
    }
    return 0;
}