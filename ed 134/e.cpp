#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string s, string t){

    string combined = s + t;
    int n = combined.length();

    vector<int> lps(n, 0);
    int prevLPS = 0, i = 1;

    while(i < n){
        if(combined[i] == combined[prevLPS]){
            prevLPS++;
            lps[i] = prevLPS;
            i++;
        }
        else if(prevLPS == 0){
            lps[i] = 0;
            i++;
        }
        else
            prevLPS = lps[prevLPS-1];
    }

    return lps;
}

int main(){
    string s;
    cin >> s;

    int q;
    cin >> q;

    while(q--){
        string t;
        cin >> t;
        vector<int> lps = computeLPS(s, t);
        for(int i = s.length(); i < lps.size(); i++)
            cout << lps[i] << " ";
        cout << "\n";
    }
    return 0;
}