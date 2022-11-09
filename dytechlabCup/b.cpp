#include <bits/stdc++.h>
using namespace std;

void solve(long long l, long long r){
    long long x = ceill(sqrtl(l));
    long long y = floorl(sqrtl(r));

    long long changes = 2*(y-x) + (y-x+1);

    if(x*x != l){
        if(l <= x*x - 1 - (x-1))
            changes += 2;
        else if (l <= x*x-1)
            changes += 1;
    }

    if(y*y != r){
        if(r >= y*y + 2*y)
            changes += 2;
        else if (r >= y*y + y)
            changes += 1;
    }

    cout << changes << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long l, r;
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}