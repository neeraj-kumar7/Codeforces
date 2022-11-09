#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string& s, vector<vector<int>>& dp){
    if(i > j)
        return 1;
    
    if(dp[i][j] != -1) return dp[i][j];

    int pickFromStart = -1;

    // case 1 : Alice picks s[i] and Bob picks s[i+1]
    int winner = solve(i+2, j, s, dp);
    if(s[i] < s[i+1]){
        if(winner == 2) pickFromStart = 2;
        else pickFromStart = 0;
    }
    else if (s[i] == s[i+1])
        pickFromStart = winner;
    else{
        if(winner == 0) pickFromStart = 0;
        else pickFromStart = 2;
    }

    //case 2: Alice picks s[i] and Bob picks s[j]
    winner = solve(i+1, j-1, s, dp);
    if(s[i] < s[j]){
        if(winner == 2)
            pickFromStart = max(pickFromStart, 2);
        else
            pickFromStart = max(pickFromStart, 0);
    }
    else if (s[i] == s[j])
        pickFromStart = max(pickFromStart, winner);
    else{
        if(winner == 0)
            pickFromStart = max(pickFromStart, 0);
        else
            pickFromStart = max(pickFromStart, 2);
    }

    int pickFromEnd = -1;
    //case 3: Alice picks s[j] and Bob picks s[j-1]
    winner = solve(i, j-2, s, dp);
    if(s[j] < s[j-1]){
        if(winner == 2) pickFromEnd = 2;
        else pickFromEnd = 0;
    }
    else if (s[j] == s[j-1])
        pickFromEnd = winner;
    else{
        if(winner == 0) pickFromEnd = 0;
        else pickFromEnd = 2;
    }

    //case 4: Alice picks s[j] and Bob picks s[i]
    winner = solve(i+1, j-1, s, dp);
    if(s[j] < s[i]){
        if(winner == 2)
            pickFromEnd = max(pickFromEnd, 2);
        else
            pickFromEnd= max(pickFromEnd, 0);
    }
    else if (s[j] == s[i])
        pickFromEnd = max(pickFromEnd, winner);
    else{
        if(winner == 0)
            pickFromEnd= max(pickFromEnd, 0);
        else
            pickFromEnd = max(pickFromEnd, 2);
    }

    return dp[i][j] = min(pickFromStart, pickFromEnd);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<string> ans = {"Alice", "Draw", "Bob"};
        cout << ans[solve(0, n-1, s, dp)] << "\n"; 
    }
    return 0;
}