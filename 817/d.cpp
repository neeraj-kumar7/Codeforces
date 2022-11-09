#include <bits/stdc++.h>
using namespace std;

vector<long long> findValue(string& s, int n){
    long long maxValue = 0LL;
    vector<int> misMatch;
    for(int i = 0; i < n/2; i++){
        maxValue += 2LL*(n-i-1);

        if(s[i] != 'R')
            misMatch.push_back(i);
        if(s[n-i-1] != 'L')
            misMatch.push_back(i);
    }
    if(n&1)
        maxValue += n/2;

    long long initialValue = 0LL;
    for(int i=0; i < n; i++){
        if(s[i] == 'L')
            initialValue += i;
        else
            initialValue += n-i-1;
    }
    

    int m = misMatch.size();
    vector<long long> value(n);
    int j = 0;
    for(int i = 0; i < n; i++){
        if(i >= m-1)
            value[i] = maxValue;
        else{
            int index = misMatch[j];
            initialValue += (n-1-2*index);
            value[i] = initialValue;
            j++;
        }
    }

    return value;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<long long> value = findValue(s, n);

        for(auto i : value)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}