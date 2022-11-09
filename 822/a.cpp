#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums ){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int minimum = INT_MAX;
    for(int i = 1; i < n-1; i++){
        int diff1 = nums[i] - nums[i-1];
        int diff2 = nums[i+1] - nums[i];
        minimum = min(minimum, diff1 + diff2);
    }
    cout << minimum << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];

        solve(nums);
    }
    return 0;
}