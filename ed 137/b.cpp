#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    vector<int> arr(n);
    int num = 1;
    for(int i = 0; i < (n - (n%2)); i += 2){
        arr[i] = num;
        arr[i+1] = n-num+1;
        num++;
    }
    if(n&1) arr[n-1] = n/2+1;
    for(int i : arr)
        cout << i << " ";
    cout << "\n";
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
        solve(n);
    }
    return 0;
}