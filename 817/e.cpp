#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<vector<long long>> prefix(1001, vector<long long>(1001, 0LL));
        for(int i = 0; i < n; i++){
            int hi, wi;
            cin >> hi >> wi;
            prefix[hi][wi] += 1LL*hi*wi;
        }

        for(int i = 0; i < 1001; i++){
            for(int j = 1; j < 1001; j++){
                prefix[i][j] += prefix[i][j-1];
            }
        }

        for(int j = 0; j < 1001; j++){
            for(int i = 1; i < 1001; i++){
                prefix[i][j] += prefix[i-1][j];
            }
        }

        while(q--){
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;

            cout << prefix[hb-1][wb-1] - prefix[hs][wb-1]
                    - prefix[hb-1][ws] + prefix[hs][ws] << "\n";
        }
    }
    return 0;
}