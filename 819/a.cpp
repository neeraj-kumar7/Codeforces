#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a){
    int n = a.size();

    int minIndex = 0, maxIndex = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < a[minIndex])
            minIndex = i;
        if(a[i] > a[maxIndex])
            maxIndex = i;
    }

    if((minIndex - maxIndex) == 1 or 
            maxIndex == n-1 or minIndex == 0)
        cout << a[maxIndex] - a[minIndex] << "\n";
    else{
        int ans = max(a[maxIndex] - a[0], a[n-1] - a[minIndex]);
        for(int i = 1;i < n; i++){
            if(a[i] < a[i-1])
                ans = max(ans, a[i-1] - a[i]);
        }
        if(a[0] < a[n-1])
            ans = max(ans, a[n-1] - a[0]);
        cout << ans << "\n";
    }
    return;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        solve(a);
    }
    return 0;
}