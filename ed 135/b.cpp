#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    vector<int> ans(n);
    
    ans[n-2] = n-1;
    ans[n-1] = n;

    if((n&1) == 0){
        int count = n-2;
        for(int i = 0; i < n-2; i++){
            ans[i] = count;
            count--;
        }
    }
    else{
        ans[0] = 1;
        int count = 2;
        for(int i = n-3; i > 0; i--){
            ans[i] = count;
            count++;
        }
    }
   
    for(int num : ans)
        cout << num << " ";
    cout << "\n";
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