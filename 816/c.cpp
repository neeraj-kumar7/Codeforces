#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void awesomeness(ll n, ll i, ll x, ll &ans, vector<ll>& nums){
    
    i--;
    if(i-1 >= 0 and nums[i] != nums[i-1]) ans -= i*(n-i);
    if(i+1 < n and nums[i] != nums[i+1]) ans -= (i+1)*(n-(i+1));

    nums[i] = x;
    if(i-1 >= 0 and nums[i] != nums[i-1]) ans += i*(n-i);
    if(i+1 < n and nums[i] != nums[i+1]) ans += (i+1)*(n-(i+1));

    cout << ans << "\n";
}

int main(){
    
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    long long ans = n*(n+1)/2;
    for(int i = 1; i < n; i++){
        if(nums[i] != nums[i-1])
            ans += 1LL*i*(n-i);
    }

    while(m--){
        ll i, x;
        cin >> i >> x;
        awesomeness(n, i, x, ans, nums);
    }
    
    return 0;
}