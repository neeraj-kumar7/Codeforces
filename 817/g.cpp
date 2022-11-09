#include <bits/stdc++.h>
using namespace std;

vector<int> findArray(int n){
    vector<int> a(n, 0);
    int k = 1;
    for(int i = 0; i < n-1; i += 2){
        a[i] = k;
        a[i+1] = k;
        k++;
    }

    if(n&1){
        int half = (n+1)/2;
        if(half&1){
            for(int i = 0; i < half-1; i++){
                a[2*i] |= (1 << 30);
                a[2*(i+1)] |= (1 << 29);
            }
        }
        else{
            for(int i = 0; i < half; i++){
                a[2*i] |= (1 << 30);
            }
        }
    }

    else{
        int half = n/2;
        if(half&1){
            for(int i = 0; i < half-1; i++){
                a[2*i] |= (1 << 30);
                a[2*(i+1)] |= (1 << 29);
            }
        }
        else{
            for(int i = 0; i < half; i++){
                a[2*i] |= (1 << 30);
            }
        }
    }
    return a;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> nums = findArray(n);

        /*
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++){
            if(i&1) odd ^= nums[i];
            else even ^= nums[i];
        }
        cout << odd << " " << even << endl;*/
        
        for(auto i : nums)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}