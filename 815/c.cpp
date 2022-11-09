#include <bits/stdc++.h>
using namespace std;

int Corners(vector<vector<int>> matrix, int sum, int n, int m){
    bool two = false, one = false;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            int count = matrix[i][j] + matrix[i+1][j]+
                        matrix[i][j+1] + matrix[i+1][j+1];
            if(count <= 2) two = true;
            else if(count == 3) one = true;
        }
    }

    if(two) return sum;
    if(one) return sum-1;

    return sum-2;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        int sum = 0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < m; j++){
                matrix[i][j] = s[j]-'0';
                sum += matrix[i][j];
            }
        }

        cout << Corners(matrix, sum, n, m) << endl;
    }

    return 0;
}