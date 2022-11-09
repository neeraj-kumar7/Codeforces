#include <bits/stdc++.h>
using namespace std;

void solve(int n, string s){

    int start = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            start = i;
            break;
        }
    }

    if(start == -1){
        cout << "0" << "\n";
        return;
    }

    string sub = s.substr(start);
    int zeroIndex;
    for(int i = start+1; i < n; i++){
        if(s[i] == '0'){
            zeroIndex = i;
            break;
        }
    }

    int diff = zeroIndex-start;
    int len = n-start-diff;

    string ans = s;
    for(int i = start; i+len < n; i++){
        string temp = sub;
        for(int j = 0; j < len; j++){
            temp[diff+j] = max(temp[diff+j], s[i+j]);
        }
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    string s;
    cin >> s;
    solve(n, s);
    return 0;
}