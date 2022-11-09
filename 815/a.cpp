#include <bits/stdc++.h>
using namespace std;

int findClaps(int a, int b, int c, int d){
    
    long long num = 1LL*a*d;
    long long den = 1LL*b*c;

    if(num == den) return 0;
    if(num == 0 or den == 0) return 1;

    if(num > den){
        long long r = num/den;
        if(r*den == num) return 1;

        return 2;
    } 

    if(den > num){
        long long r = den/num;
        if(r*num == den) return 1;

        return 2;
    }

    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d; 
        cout << findClaps(a, b, c, d) << endl;
    }
    return 0;
}