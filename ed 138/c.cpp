#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& nums){
    
    sort(nums.begin(), nums.end());
    for(int k = n; k >= 0; k--){
        int alice = n-1, bob = 0;
        int rounds = 0;

        while(rounds < k and alice >= bob){
            bool found = false;
            bob = rounds;

            while(!found and alice >= bob){
                if(nums[alice] <= k+1 - (rounds+1)){
                    rounds++;
                    found = true;
                }
                alice--;
            }
        }
        
        if(rounds == k){
            cout << k << "\n";
            return;
        }
    }
    
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
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        solve(n, nums);
    }
    return 0;
}