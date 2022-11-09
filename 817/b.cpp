#include <bits/stdc++.h>
using namespace std;

string sameColor(vector<vector<char>>& colors, int n){

    for(int i = 0; i < n; i++){
        if(colors[0][i] != colors[1][i])
            return "NO";
    }
    return "YES";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> colors(2, vector<char> (n));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                char c;
                cin >> c;

                if(c == 'B' or c == 'G')
                    colors[i][j] = 'B';
            }
        }
        cout << sameColor(colors, n) << "\n";
    }
    return 0;
}