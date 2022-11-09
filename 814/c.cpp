#include <bits/stdc++.h>
using namespace std;

int findWins(vector<int> &strengths, vector<int> &maxArray, int i, int k){
    if(i > k) return 0;
    int wins = 0;
    if(maxArray[i] == strengths[i]){
        if(i > 0) wins++;
        k -= i;
        while((i + 1) < strengths.size() and k--){
            if(maxArray[i + 1] == maxArray[i]){
                wins++;
                i++;
            }
            else break;
        }
        if(i + 1 == strengths.size())
            return wins + k;
    }
    return wins;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> strengths;
        for(int i = 0 ; i < n; i++){
            int num;
            cin >> num;
            strengths.push_back(num);
        }
        
        vector<int> maxArray(n);
        maxArray[0] = strengths[0];
        for(int j = 1; j < n; j++)
            maxArray[j] = max(maxArray[j-1], strengths[j]);

        while(q--){
            int i, k;
            cin >> i >> k;  
            cout << findWins(strengths, maxArray, i-1, k) << endl;
        }
    }

    return 0;
}