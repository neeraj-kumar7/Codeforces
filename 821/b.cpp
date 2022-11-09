#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n ,int x, int y){
    int games = n-1;
    vector<int> ans(games);
    if((x != 0 and y != 0) or (x == 0 and y == 0))
        return {-1};

    int k = (x == 0) ? y : x;

    if(games%k != 0)
        return {-1};

    int index = games-1;
    int num = n - k + 1;
    while(index >= 0){
        for(int i = 0; i < k; i++){
            ans[index] = num;
            index--;
        }
        num -= k;
    }

    return ans;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans = solve(n, x, y);
        for(int i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}