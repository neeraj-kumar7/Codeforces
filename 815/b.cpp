#include <bits/stdc++.h>
using namespace std;

int interestingSum(int n, vector<int> &nums){
    sort(nums.begin(), nums.end());
    return nums[n-1] + nums[n-2] - nums[0] - nums[1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; i++)
            cin >> nums[i];

        cout << interestingSum(n, nums) << endl;
    }

    return 0;
}