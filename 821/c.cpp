#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums){
    int n = nums.size();
    vector<int> even, odd;
    for(int i = 0; i < n; i++){
        if(nums[i]&1)
            odd.push_back(i+1);
        else
            even.push_back(i+1);
    }

    cout << n-1 << "\n";
    if(nums[0]&1){
        for(int i = odd.size()-2; i >= 0; i--)
            cout << odd[i] << " " << odd[i+1] << "\n";
        
        for(int i = 0; i < even.size(); i++)
            cout << 1 << " " << even[i] << "\n"; 
    }
    else{
        for(int i = even.size()-2; i >= 0; i--)
            cout << even[i] << " " << even[i+1] << "\n";
        
        for(int i = 0; i < odd.size(); i++)
            cout << 1 << " " << odd[i] << "\n"; 
    }

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