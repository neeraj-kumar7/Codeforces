#include <bits/stdc++.h>
#define endl "\n"
#define mod 1e9+7

using namespace std;
typedef long long ll;

void solve(){
    ll n, m;
    cin >> n >> m;

    ll temp = n;

    int tens = 0, twos = 0, fives = 0;
    while(temp%10 == 0){
        temp /= 10;
        tens++;
    }

    while(temp%2 == 0){
        temp /= 2;
        twos++;
    }

    while(temp%5 == 0){
        temp /= 5;
        fives++;
    }

    ll x = 1;
    bool flag = false;

    for(int i = 1; i <= fives; i++){
        if(x*2 > m) break;
        x *= 2;
        flag = true;
    }    

    for(int i = 1; i <= twos; i++){
        if(x*5 > m) break;
        x *= 5;
        flag = true;
    }

    while(x*10 <= m){
        x *= 10;
        flag = true;
    }

    if(!flag)cout << n*m << endl;
    else cout << n*x*(m/x) << endl;

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
        solve();
    }
    return 0;
}