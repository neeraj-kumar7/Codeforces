#include <bits/stdc++.h>
using namespace std;

vector<int> permutation(int n){
    vector<int> ans(n, 0);
    for(int i = n; i > 1; i -= 2){
        ans[i-1] = i - 1;
        ans[i-2] = i;
    }
    if(n%2) ans[0] = 1;

    return ans;
}

int main(){
    int t;
    cin >> t;
    vector<vector<int>> ans;
    while(t--){
        int n;
        cin >> n;
        ans.push_back(permutation(n));
    }
    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}