#include <bits/stdc++.h>
using namespace std;

int numOfOperations(vector<int> &nums, int n){
    unordered_map<int,int> hashMap;
    for(int i = 0; i < n; i++)
        hashMap[nums[i]]++;

    for(int i = n-1; i >= 0; i--){
        while( i > 0 and nums[i-1] == nums[i]){
            hashMap[nums[i]]--;
            i--;
        }
        hashMap[nums[i]]--;

        if(hashMap[nums[i]] == 0) hashMap.erase(nums[i]);
        if(hashMap.count(nums[i]))
            return hashMap.size();
        if(i > 0 and nums[i-1] > nums[i])
            return hashMap.size();
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    vector<int> ans;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n,0);
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            p[i] = num;
        }

        ans.push_back(numOfOperations(p, n));
    }
    for(int i : ans)
        cout << i << endl;

    return 0;
}