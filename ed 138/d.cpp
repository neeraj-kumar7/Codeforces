#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll power(ll x, ll n){
    ll result = 1;
    x %= mod;
    if(x == 0) return 0;

    while(n){
        if(n&1){
            result *= x;
            result %= mod;
        }

        n = n >> 1;
        x *= x;
        x %= mod;
    }
    return result;
}

vector<bool> sieveOfEratosthenes(ll n){
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for(int p = 2; p*p <= n; p++){
        if(prime[p]){
            for(int i = p*p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}

void solve(ll n , ll m){
    

    ll totalArrays = 0;
    if(m == 1)
        totalArrays = n%mod;
    else{
        totalArrays = m%mod;
        totalArrays *= power(m, n)-1+mod;
        totalArrays %= mod;
        totalArrays *= power(m-1, mod-2);
        totalArrays %= mod;
    }

    ll unambiguous = 0;
    ll prodOfPrimes = 1, ans = 1;
    vector<bool> isPrime = sieveOfEratosthenes(n);
  
    for(ll i = 1; i <= n; i++){
        
        //cout << isPrime[i] << "\n";
        if(isPrime[i])
            prodOfPrimes *= i;
        if(prodOfPrimes > m)
            break;
        
        ll validValues = m/prodOfPrimes;
        validValues %= mod;
        ans *= validValues;
        ans %= mod;

        unambiguous += ans;
        unambiguous %= mod;
    }

    cout << (totalArrays - unambiguous + 5*mod)%mod << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}
