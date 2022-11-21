#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

int strStr(string haystack, string needle) {
        
    int n = haystack.length();
    int m = needle.length();
    
    vector<int> lps(m, 0);
    int prevLPS = 0, i = 1;
    while(i < m){
        if(needle[i] == needle[prevLPS]){
            prevLPS++;
            lps[i] = prevLPS;
            i++;
        }
        else{
            if(prevLPS == 0){
                lps[i] = 0;
                i++;
            }
            else{
                prevLPS = lps[prevLPS-1];
            }
        }   
    }
    
    int j = 0;
    i = 0;
    
    while(i < n){
        if(haystack[i] == needle[j])
            i++, j++;
        else{
            if(j == 0)
                i++;
            else
                j = lps[j-1];
        }
        if(j == m)
            return i-m;
    }
    return -1;
}

void solve(){
    string s;
    cin >> s;

    string text = "";
    for(int i = 0; i < 30; i++)
        text += "Yes";

    int x = strStr(text, s);
    if(x == -1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
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