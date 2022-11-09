#include <bits/stdc++.h>
using namespace std;

vector<long long> beautifulArray(int n, int k, int b, long long s){
    long long product = 1LL*k*b;
    if((s < product) or (s > product + 1LL*(k-1)*n)) 
        return {-1};

    vector<long long> ans(n, 0);
    if(n==1 or s <= product + (k-1)) {
        ans[0] = s;
        return ans;
    }
    ans[n-1] = product + (k-1);

    s -= (product + k-1);
    for(int i = n-2; i >= 0; i--){
        if(s >= k-1){
            ans[i] = k-1;
            s -= (k-1);
        }
        else{
            ans[i] = s;
            break;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, b;
        long long s;
        cin >> n >> k >> b >> s; 
        vector<long long> ans = beautifulArray(n, k, b, s);
        for(long long i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}