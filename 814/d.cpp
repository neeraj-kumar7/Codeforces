#include <bits/stdc++.h>
using namespace std;

long long findMinimumTime(vector<long long> &arr){
    int n = arr.size();
    vector<long long> dp(n, 1e8);

    dp[0] = 0LL;
    for(int i = 1; i < n; i++){
        long long res = 0;
        for(int j = i; j >= 1; j--){
            int count = i-j;
            res ^= arr[j];
            if(res != 0)
                count++;

            dp[i] = min(dp[i], count + dp[j-1]);
        }
    }
    return dp[n-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr(n+1, 0);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        cout << findMinimumTime(arr) << "\n";
    }

    return 0;
}
