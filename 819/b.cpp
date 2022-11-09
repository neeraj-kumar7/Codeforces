#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m){
    vector<int> ans;
    if(n == 1){
        cout << "Yes" << "\n";
        cout << m << "\n";
        return;
    }
    if(m/n == 0){
        cout << "No" << "\n";
        return;
    }
    else{
        if(m%n == 0){
            for(int i = 0; i < n; i++)
                ans.push_back(m/n);
        }
        else{
            int remain = m%n;
            if(n&1){
                for(int i = 0; i < n-1; i++)
                    ans.push_back(m/n);
                ans.push_back(m/n + remain);
            }
            else{
                if((remain&1) == 0){
                    for(int i = 0; i < n-2; i++)
                        ans.push_back(m/n);
                    ans.push_back(m/n + remain/2);
                    ans.push_back(m/n + remain/2);
                }
            }
        }
    }
    
    if(ans.size() == 0)
        cout << "No" << "\n";
    else{
        cout << "Yes" << "\n";
        for(int i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}