#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        bool flag = true;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] < a[i]) flag = false;
        }

        for(int i = 0; i < n-1; i++){
            if(a[i] < b[i]){
                if(b[i] > (b[i+1] + 1)){
                    flag = false;
                    break;
                }
            }
            
        }

        if(a[n-1] < b[n-1]){
            if(b[n-1] > (b[0] + 1))
                flag = false;
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}