#include <bits/stdc++.h>
using namespace std;

void findPairs(int n, int k){
    vector<pair<int,int>> pairs;
    if(k%2){
        for(int i = 1; i < n; i += 2)
            pairs.push_back({i, i+1});
    }
    else{
        if(k%4 == 0){
            cout << "NO" << "\n";
            return;
        }
        else{
            int flag = 0;
            for(int i = 1; i < n; i += 2){
                if(flag)
                    pairs.push_back({i, i+1});
                else
                    pairs.push_back({i+1, i});

                flag = 1 - flag;
            }
        }
    }
    cout << "YES" << "\n";
    for(auto p : pairs)
        cout << p.first << " " << p.second << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        findPairs(n, k);
    }

    return 0;
}