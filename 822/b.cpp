#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++){
        vector<int> floor;
        for(int j = 1; j <= i; j++){
            if(j == 1)
                floor.push_back(1);
            else if(j == i)
                floor.push_back(1);
            else
                floor.push_back(0);
        }
        ans.push_back(floor);
    }

    for(auto i : ans){
        for(int j : i)
            cout << j << " ";
        cout << "\n";
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}