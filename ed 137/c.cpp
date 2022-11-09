#include <bits/stdc++.h>
using namespace std;

int f(int i, int c, string& isCovered, vector<int>& nums, 
        vector<vector<int>>& dp){

    if(i == 0){
        if(c == 1 or isCovered[0] == '1')
            return nums[0];
        return 0;
    }

    if(dp[i][c] != -1) return dp[i][c];

    if(c == 0){
        int cover = 0;
        int noCover = 0;
        if(isCovered[i] == '1'){
            cover = nums[i] + f(i-1, 0, isCovered, nums, dp);
            noCover = f(i-1, 1, isCovered, nums, dp);
            return dp[i][c] = max(cover, noCover);
        }
        else{
            return dp[i][c] = f(i-1, 0, isCovered, nums, dp);
        }
    }
    else{
    
        if(isCovered[i] == '1'){
            return dp[i][c] = nums[i] + f(i-1, 1, isCovered, nums, dp);
        }
        else{
            return dp[i][c] = nums[i] + f(i-1, 0, isCovered, nums, dp);
        }
    }
    return dp[i][c] = 0;
}

void solve(int n, string& isCovered, vector<int>& nums){
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    cout << f(n, 0, isCovered, nums, dp) << "\n";
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
        int n;
        cin >> n;
        string isCovered;
        cin >> isCovered;

        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        solve(n, isCovered, nums);
    }
    return 0;
}