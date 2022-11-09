#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> maxi(k, 0);
    for(int i = 0; i < n; i++){
        maxi[i%k] = max(maxi[i%k], nums[i]);
    }

    long long score = 0LL;
    for(int i : maxi)
        score += i;

    cout << score << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];

        solve(nums, k);
    }
    return 0;
}