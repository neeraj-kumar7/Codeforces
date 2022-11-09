#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> findArray(vector<vector<pair<int,int>>>& adj, int n){
    
    vector<int> ans(n, (1 << 30) - 1);
    for(int bit = 0; bit < 30; bit++){

        for(int i = 0; i < n; i++){
            for(auto [j, x] : adj[i]){
                if((x & (1 << bit)) == 0)
                    ans[i] &= ~(1 << bit);

            }
        }
        
        for(int i = 0; i < n; i++){
            bool zero = true;
            if(ans[i] & (1 << bit)){
                for(auto [j, x] : adj[i]){

                    if(j == i){
                        zero = false;
                        break;
                    }

                    if(!(ans[j] & (1 << bit))){
                        zero = false;
                        break;
                    }
                }

                if(zero)
                    ans[i] &= ~(1 << bit);
            }
            
        }
        
    }
    return ans;
}

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> adj(n);
    while(q--){
        int i, j, x;
        cin >> i >> j >> x;
        i--, j--;
        adj[i].push_back({j, x});
        adj[j].push_back({i, x});
    }
    vector<int> ans = findArray(adj, n);
    for(int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}